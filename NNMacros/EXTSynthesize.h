//
//  EXTSynthesize.h
//  extobjc
//
//  Created by Justin Spahr-Summers on 2012-09-04.
//  Copyright (C) 2012 Justin Spahr-Summers.
//  Released under the MIT license.
//

#import <objc/runtime.h>

/**
 * \@synthesizeAssociation synthesizes a property for a class using associated
 * objects. This is primarily useful for adding properties to a class within
 * a category.
 *
 * PROPERTY must have been declared with \@property in the interface of the
 * specified class (or a category upon it), and must be of object type.
 */
#define synthesizeAssociation(CLASS, PROPERTY) \
    \
	dynamic PROPERTY; \
	\
	static void *   metamacro_concat(nn_macros_uniqueKey_, \
                    metamacro_concat(CLASS, \
                    metamacro_concat(_, PROPERTY \
                    ))) \
                    = \
                    &metamacro_concat(nn_macros_uniqueKey_, \
                    metamacro_concat(CLASS, \
                    metamacro_concat(_, PROPERTY \
                    ))) ;\
	\
	__attribute__((constructor)) \
	static void metamacro_concat(nn_macros_, \
                metamacro_concat(CLASS, \
                metamacro_concat(_, \
                metamacro_concat(PROPERTY, _synthesize \
                )))) (void) { \
        \
		Class cls = objc_getClass(metamacro_stringify(CLASS)); \
		objc_property_t property = class_getProperty(cls, metamacro_stringify(PROPERTY)); \
		NSCAssert(property, @"Could not find property %s on class %@", metamacro_stringify(PROPERTY), cls); \
		\
		nn_macros_propertyAttributes *attributes = nn_macros_copyPropertyAttributes(property); \
		if (!attributes) { \
			NSLog(@"*** Could not copy property attributes for %@.%s", cls, metamacro_stringify(PROPERTY)); \
			return; \
		} \
		\
		NSCAssert(!attributes->weak, @"@synthesizeAssociation does not support weak properties (%@.%s)", cls, metamacro_stringify(PROPERTY)); \
		\
		objc_AssociationPolicy policy = OBJC_ASSOCIATION_ASSIGN; \
		switch (attributes->memoryManagementPolicy) { \
			case nn_macros_propertyMemoryManagementPolicyRetain: \
				policy = attributes->nonatomic ? OBJC_ASSOCIATION_RETAIN_NONATOMIC : OBJC_ASSOCIATION_RETAIN; \
				break; \
			\
			case nn_macros_propertyMemoryManagementPolicyCopy: \
				policy = attributes->nonatomic ? OBJC_ASSOCIATION_COPY_NONATOMIC : OBJC_ASSOCIATION_COPY; \
				break; \
			\
			case nn_macros_propertyMemoryManagementPolicyAssign: \
				break; \
			\
			default: \
				NSCAssert(NO, @"Unrecognized property memory management policy %i", (int)attributes->memoryManagementPolicy); \
		} \
		\
		id getter = ^(id self){ \
			return objc_getAssociatedObject(self, \
                                            metamacro_concat(nn_macros_uniqueKey_, \
                                            metamacro_concat(CLASS, \
                                            metamacro_concat(_, PROPERTY \
                                            )))); \
		}; \
		\
		id setter = ^(id self, id value){ \
            objc_setAssociatedObject(self, \
                                     metamacro_concat(nn_macros_uniqueKey_, \
                                     metamacro_concat(CLASS, \
                                     metamacro_concat(_, PROPERTY \
                                     ))), \
                                     value, \
                                     policy); \
		}; \
		\
		if (!class_addMethod(cls, attributes->getter, imp_implementationWithBlock(getter), "@@:")) { \
			NSCAssert(NO, @"Could not add getter %s for property %@.%s", sel_getName(attributes->getter), cls, metamacro_stringify(PROPERTY)); \
		} \
		\
		if (!class_addMethod(cls, attributes->setter, imp_implementationWithBlock(setter), "v@:@")) { \
			NSCAssert(NO, @"Could not add setter %s for property %@.%s", sel_getName(attributes->setter), cls, metamacro_stringify(PROPERTY)); \
		} \
		\
		free(attributes); \
	}


/**
 * Describes the memory management policy of a property.
 */
typedef enum {
    /**
     * The value is assigned.
     */
    nn_macros_propertyMemoryManagementPolicyAssign = 0,

    /**
     * The value is retained.
     */
    nn_macros_propertyMemoryManagementPolicyRetain,

    /**
     * The value is copied.
     */
    nn_macros_propertyMemoryManagementPolicyCopy
} nn_macros_propertyMemoryManagementPolicy;


/**
 * Describes the attributes and type information of a property.
 */
typedef struct {
    /**
     * Whether this property was declared with the \c readonly attribute.
     */
    BOOL readonly;

    /**
     * Whether this property was declared with the \c nonatomic attribute.
     */
    BOOL nonatomic;

    /**
     * Whether the property is a weak reference.
     */
    BOOL weak;

    /**
     * Whether the property is eligible for garbage collection.
     */
    BOOL canBeCollected;

    /**
     * Whether this property is defined with \c \@dynamic.
     */
    BOOL dynamic;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
    
    /**
     * The memory management policy for this property. This will always be
     * #nn_macros_propertyMemoryManagementPolicyAssign if #readonly is \c YES.
     */
    nn_macros_propertyMemoryManagementPolicy memoryManagementPolicy;


    /**
     * The selector for the getter of this property. This will reflect any
     * custom \c getter= attribute provided in the property declaration, or the
     * inferred getter name otherwise.
     */
    SEL getter;

    /**
     * The selector for the setter of this property. This will reflect any
     * custom \c setter= attribute provided in the property declaration, or the
     * inferred setter name otherwise.
     *
     * @note If #readonly is \c YES, this value will represent what the setter
     * \e would be, if the property were writable.
     */
    SEL setter;
    
#pragma clang diagnostic pop

    /**
     * The backing instance variable for this property, or \c NULL if \c
     * \c @synthesize was not used, and therefore no instance variable exists. This
     * would also be the case if the property is implemented dynamically.
     */
    const char *ivar;

    /**
     * If this property is defined as being an instance of a specific class,
     * this will be the class object representing it.
     *
     * This will be \c nil if the property was defined as type \c id, if the
     * property is not of an object type, or if the class could not be found at
     * runtime.
     */
    Class objectClass;

    /**
     * The type encoding for the value of this property. This is the type as it
     * would be returned by the \c \@encode() directive.
     */
    char type[];
} nn_macros_propertyAttributes;


NS_INLINE nn_macros_propertyAttributes *nn_macros_copyPropertyAttributes (objc_property_t property) {
    const char * const attrString = property_getAttributes(property);
    if (!attrString) {
        fprintf(stderr, "ERROR: Could not get attribute string from property %s\n", property_getName(property));
        return NULL;
    }

    if (attrString[0] != 'T') {
        fprintf(stderr, "ERROR: Expected attribute string \"%s\" for property %s to start with 'T'\n", attrString, property_getName(property));
        return NULL;
    }

    const char *typeString = attrString + 1;
    const char *next = NSGetSizeAndAlignment(typeString, NULL, NULL);
    if (!next) {
        fprintf(stderr, "ERROR: Could not read past type in attribute string \"%s\" for property %s\n", attrString, property_getName(property));
        return NULL;
    }

    size_t typeLength = next - typeString;
    if (!typeLength) {
        fprintf(stderr, "ERROR: Invalid type in attribute string \"%s\" for property %s\n", attrString, property_getName(property));
        return NULL;
    }

    // allocate enough space for the structure and the type string (plus a NUL)
    nn_macros_propertyAttributes *attributes = (nn_macros_propertyAttributes *)calloc(1, sizeof(nn_macros_propertyAttributes) + typeLength + 1);
    if (!attributes) {
        fprintf(stderr, "ERROR: Could not allocate nn_macros_propertyAttributes structure for attribute string \"%s\" for property %s\n", attrString, property_getName(property));
        return NULL;
    }

    // copy the type string
    strncpy(attributes->type, typeString, typeLength);
    attributes->type[typeLength] = '\0';

    // if this is an object type, and immediately followed by a quoted string...
    if (typeString[0] == *(@encode(id)) && typeString[1] == '"') {
        // we should be able to extract a class name
        const char *className = typeString + 2;
        next = strchr(className, '"');

        if (!next) {
            fprintf(stderr, "ERROR: Could not read class name in attribute string \"%s\" for property %s\n", attrString, property_getName(property));
            goto errorOut;
        }

        if (className != next) {
            size_t classNameLength = next - className;
            char trimmedName[classNameLength + 1];

            strncpy(trimmedName, className, classNameLength);
            trimmedName[classNameLength] = '\0';

            // attempt to look up the class in the runtime
            attributes->objectClass = objc_getClass(trimmedName);
        }
    }

    if (*next != '\0') {
        // skip past any junk before the first flag
        next = strchr(next, ',');
    }

    while (next && *next == ',') {
        char flag = next[1];
        next += 2;

        switch (flag) {
        case '\0':
            break;

        case 'R':
            attributes->readonly = YES;
            break;

        case 'C':
            attributes->memoryManagementPolicy = nn_macros_propertyMemoryManagementPolicyCopy;
            break;

        case '&':
            attributes->memoryManagementPolicy = nn_macros_propertyMemoryManagementPolicyRetain;
            break;

        case 'N':
            attributes->nonatomic = YES;
            break;

        case 'G':
        case 'S':
            {
                const char *nextFlag = strchr(next, ',');
                SEL name = NULL;

                if (!nextFlag) {
                    // assume that the rest of the string is the selector
                    const char *selectorString = next;
                    next = "";

                    name = sel_registerName(selectorString);
                } else {
                    size_t selectorLength = nextFlag - next;
                    if (!selectorLength) {
                        fprintf(stderr, "ERROR: Found zero length selector name in attribute string \"%s\" for property %s\n", attrString, property_getName(property));
                        goto errorOut;
                    }

                    char selectorString[selectorLength + 1];

                    strncpy(selectorString, next, selectorLength);
                    selectorString[selectorLength] = '\0';

                    name = sel_registerName(selectorString);
                    next = nextFlag;
                }

                if (flag == 'G')
                    attributes->getter = name;
                else
                    attributes->setter = name;
            }

            break;

        case 'D':
            attributes->dynamic = YES;
            attributes->ivar = NULL;
            break;

        case 'V':
            // assume that the rest of the string (if present) is the ivar name
            if (*next == '\0') {
                // if there's nothing there, let's assume this is dynamic
                attributes->ivar = NULL;
            } else {
                attributes->ivar = next;
                next = "";
            }

            break;

        case 'W':
            attributes->weak = YES;
            break;

        case 'P':
            attributes->canBeCollected = YES;
            break;

        case 't':
            fprintf(stderr, "ERROR: Old-style type encoding is unsupported in attribute string \"%s\" for property %s\n", attrString, property_getName(property));

            // skip over this type encoding
            while (*next != ',' && *next != '\0')
                ++next;

            break;

        default:
            fprintf(stderr, "ERROR: Unrecognized attribute string flag '%c' in attribute string \"%s\" for property %s\n", flag, attrString, property_getName(property));
        }
    }

    if (next && *next != '\0') {
        fprintf(stderr, "Warning: Unparsed data \"%s\" in attribute string \"%s\" for property %s\n", next, attrString, property_getName(property));
    }

    if (!attributes->getter) {
        // use the property name as the getter by default
        attributes->getter = sel_registerName(property_getName(property));
    }

    if (!attributes->setter) {
        const char *propertyName = property_getName(property);
        size_t propertyNameLength = strlen(propertyName);

        // we want to transform the name to setProperty: style
        size_t setterLength = propertyNameLength + 4;

        char setterName[setterLength + 1];
        strncpy(setterName, "set", 3);
        strncpy(setterName + 3, propertyName, propertyNameLength);

        // capitalize property name for the setter
        setterName[3] = (char)toupper(setterName[3]);

        setterName[setterLength - 1] = ':';
        setterName[setterLength] = '\0';

        attributes->setter = sel_registerName(setterName);
    }

    return attributes;

errorOut:
    free(attributes);
    return NULL;
}
