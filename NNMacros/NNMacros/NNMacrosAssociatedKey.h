//
//  NNMacrosAssociatedKey.h
//  NNMacros
//
//  Created by 顾海军 on 2019/10/16.
//  Copyright © 2019 GuHaijun. All rights reserved.
//

#ifndef NNMacrosAssociatedKey_h
#define NNMacrosAssociatedKey_h

#include "metamacros.h"

#define nn_associated_prefix                __nn_associated_
#define nn_associated_setter_prefix         metamacro_concat(__nn_associated_, set_)
#define nn_associated_store_key             nn_associated_prefix


#endif /* NNMacrosAssociatedKey_h */
