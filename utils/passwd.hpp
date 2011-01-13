// Copyright 2010 Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
// * Neither the name of Google Inc. nor the names of its contributors
//   may be used to endorse or promote products derived from this software
//   without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/// \file utils/passwd.hpp
/// Querying and manipulation of users and groups.

#if !defined(UTILS_PASSWD_HPP)
#define UTILS_PASSWD_HPP

#include <string>

namespace utils {
namespace passwd {


/// Represents a system user.
struct user {
    /// The name of the user.
    const std::string name;

    /// The system-wide identifier of the user.
    unsigned int uid;

    /// The login group identifier for the user.
    unsigned int gid;

    user(const std::string&, const unsigned int, const unsigned int);

    bool is_root(void) const;
};


user current_user(void);
void drop_privileges(const user&);
user find_user_by_name(const std::string&);
user find_user_by_uid(const unsigned int);
void set_current_user_for_testing(const user&);


}  // namespace passwd
}  // namespace utils

#endif  // !defined(UTILS_PASSWD_HPP)