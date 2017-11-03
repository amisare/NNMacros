//
//  HJMacrosNetworkUrl.h
//  HJMacros
//
//  Created by GuHaijun on 2017/11/3.
//  Copyright © 2017年 顾海军. All rights reserved.
//

#ifndef HJMacrosNetworkUrl_h
#define HJMacrosNetworkUrl_h

typedef NS_ENUM(NSUInteger, HJNetworkUrlApiType) {
    HJNetworkUrlApiTypeTest,
    HJNetworkUrlApiTypeRelease,
};

static inline HJNetworkUrlApiType HJNetworkUrlApiTypeGet(void);
static inline BOOL HJNetworkUrlApiTypeSet(HJNetworkUrlApiType type);
static inline BOOL HJNetworkUrlApiTypeSwitch(void);


static inline BOOL HJNetworkUrlApiTypeSet(HJNetworkUrlApiType type) {

    NSString *pathString = [HJM_PathDocuments stringByAppendingPathComponent:@"BETA_HJNetworkUrlApiType.plist"];
    NSMutableDictionary *apiTypeDic = [NSMutableDictionary dictionaryWithContentsOfFile:pathString];

    if (apiTypeDic == nil) {
        apiTypeDic = [NSMutableDictionary new];
    }

    [apiTypeDic setValue:@(type) forKey:@"apiType"];

    return [apiTypeDic writeToFile:pathString atomically:false];
}

static inline HJNetworkUrlApiType HJNetworkUrlApiTypeGet() {

    NSString *pathString = [HJM_PathDocuments stringByAppendingPathComponent:@"BETA_HJNetworkUrlApiType.plist"];
    NSMutableDictionary *apiTypeDic = [NSMutableDictionary dictionaryWithContentsOfFile:pathString];

    NSNumber *type = [apiTypeDic valueForKey:@"apiType"];

    if (type == nil) {
        return HJNetworkUrlApiTypeTest;
    }

    return (HJNetworkUrlApiType)type.unsignedIntegerValue;
}

static inline BOOL HJNetworkUrlApiTypeSwitch() {

    if (HJNetworkUrlApiTypeGet() == HJNetworkUrlApiTypeTest) {
        return HJNetworkUrlApiTypeSet(HJNetworkUrlApiTypeRelease);
    }
    else if (HJNetworkUrlApiTypeGet() == HJNetworkUrlApiTypeRelease){
        return HJNetworkUrlApiTypeSet(HJNetworkUrlApiTypeTest);
    }
    return false;
}


#define HJM_NetworkUrlApiType_ENV_Name                                     "HaiJunGu_HJMacros_EVN_HJM_NetworkUrlApiType"
#define HJM_NetworkUrlApiType_ENV_Value_Test                               "HaiJunGu_HJMacros_EVN_HJM_NetworkUrlApiType_Test"
#define HJM_NetworkUrlApiType_ENV_Value_Release                            "HaiJunGu_HJMacros_EVN_HJM_NetworkUrlApiType_Release"

static inline HJNetworkUrlApiType HJNetworkUrlApiTypeEnvGet(void);
static inline BOOL HJNetworkUrlApiTypeEnvSet(HJNetworkUrlApiType type);
static inline BOOL HJNetworkUrlApiTypeEnvSync(void);
static inline BOOL HJNetworkUrlApiTypeEnvSwitch(void);


static inline BOOL HJNetworkUrlApiTypeEnvSet(HJNetworkUrlApiType type) {

    if (HJNetworkUrlApiTypeSet(type)) {

        if (type == HJNetworkUrlApiTypeRelease) {
            setenv(HJM_NetworkUrlApiType_ENV_Name, HJM_NetworkUrlApiType_ENV_Value_Release, 1);
        }

        if (type == HJNetworkUrlApiTypeTest) {
            setenv(HJM_NetworkUrlApiType_ENV_Name, HJM_NetworkUrlApiType_ENV_Value_Test, 1);
        }

        char *env = getenv(HJM_NetworkUrlApiType_ENV_Name);
        printf("evn set %s = %s\n", HJM_NetworkUrlApiType_ENV_Name, env);

        HJNetworkUrlApiType envType = HJNetworkUrlApiTypeEnvGet();

        return (type == envType);
    }
    return false;
}

static inline HJNetworkUrlApiType HJNetworkUrlApiTypeEnvGet() {

    char *env = getenv(HJM_NetworkUrlApiType_ENV_Name);
    printf("evn get %s = %s\n", HJM_NetworkUrlApiType_ENV_Name, env);

    if (strlen(env) == 0 || env == NULL) {
        return HJNetworkUrlApiTypeTest;
    }

    if ((0 == strcmp(env, HJM_NetworkUrlApiType_ENV_Value_Test))) {
        return HJNetworkUrlApiTypeTest;
    }

    if ((0 == strcmp(env, HJM_NetworkUrlApiType_ENV_Value_Release))) {
        return HJNetworkUrlApiTypeRelease;
    }

    return HJNetworkUrlApiTypeTest;
}

static inline BOOL HJNetworkUrlApiTypeEnvSync() {

    HJNetworkUrlApiType type = HJNetworkUrlApiTypeGet();
    return HJNetworkUrlApiTypeEnvSet(type);
}

static inline BOOL HJNetworkUrlApiTypeEnvSwitch() {

    if (HJNetworkUrlApiTypeSwitch()) {
        return HJNetworkUrlApiTypeEnvSync();
    }
    return false;
}

#ifdef BETA

    #define ZCNetworkUrlBlock(host, url) \
    \
    ({\
        NSString *retUrl = (NSString *)^{\
            if (HJNetworkUrlApiTypeEnvGet() == HJNetworkUrlApiTypeRelease) {\
                return HJM_StringConnect(host, url);\
            }\
            else {\
                return HJM_StringConnect(host##Test, url);\
            }\
        }();\
        NSLog(@"Mode:BETA %@", retUrl);\
        retUrl;\
    })\

#else

    #ifdef DEBUG

        #define ZCNetworkUrlBlock(host, url) \
        \
        ({\
            NSString *retUrl = (NSString *)^{\
                return HJM_StringConnect(host##Test, url);\
            }();\
            NSLog(@"Mode:DEBUG %@", retUrl);\
            retUrl;\
        })\

    #else

        #define ZCNetworkUrlBlock(host, url) \
        \
        ({\
            NSString *retUrl = (NSString *)^{\
                return HJM_StringConnect(host, url);\
            }();\
            NSLog(@"Mode:RELEASE %@", retUrl);\
            retUrl;\
        })\

    #endif

#endif


#endif /* HJMacrosNetworkUrl_h */
