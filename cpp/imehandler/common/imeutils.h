/*
Copyright 2011 WebDriver committers
Copyright 2011 Google Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

Author: timothe@google.com
*/

#ifndef IMEUTILS_H_
#define IMEUTILS_H_

#include <string>
#include <map>

// A macro to disallow the copy constructor and operator= functions.
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&);                 \
void operator=(const TypeName&)


class ImeUtils {
 public:
  virtual ~ImeUtils() {}
  std::string GetNextCandidateKeyForEngine(std::string engine) const {
    std::string key = "";
    std::map<std::string, std::string>::const_iterator it;
    if ((it = kNextCandidateKeysMap.find(engine)) !=
         kNextCandidateKeysMap.end()) {
      key = it->second;
    }
    return key;
  }

 protected:
  ImeUtils() {}
  std::map<std::string, std::string> kNextCandidateKeysMap;
};

#endif  // IMEUTILS_H_
