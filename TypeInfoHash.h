/****************************************************************************
 * TypeInfoComparator.h
 * Gasboy
 *
 * Created by Stefan Nguyen on 9/12/12.
 *
 * Copyright Vinova Pte. Ltd. All rights reserved.
 ****************************************************************************/

#ifndef Gasboy_TypeInfoComparator_h
#define Gasboy_TypeInfoComparator_h

#include <typeinfo>

struct type_info_hash {
#define type_info_hash_precision 2
  // hash algorithm discussed on http://stackoverflow.com/a/628867
  std::size_t operator ()(const std::type_info* tinfo) const {
    return (*(size_t*)tinfo->name()) >> type_info_hash_precision;
  }
  
};


#endif
