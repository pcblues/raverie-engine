// MIT Licensed (see LICENSE.md).

#pragma once
#include "String.hpp"
#include "HashMap.hpp"
#include "Array.hpp"

namespace Zero
{

typedef HashMap<String, String> StringMap;

template <typename type>
void GetStringValue(const StringMap& map,
                    StringParam key,
                    type* outValue,
                    const type& valueIfNotFound)
{
  StringMap::range r = map.Find(key);
  if (!r.Empty())
    ToValue(r.Front().second, *outValue);
  else
    *outValue = valueIfNotFound;
}

template <typename type>
type GetStringValue(const StringMap& map,
                    StringParam key,
                    const type& valueIfNotFound)
{
  type value;
  GetStringValue(map, key, &value, valueIfNotFound);
  return value;
}

} // namespace Zero
