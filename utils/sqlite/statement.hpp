// Copyright 2011 Google Inc.
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

/// \file utils/sqlite/statement.hpp
/// Wrapper classes and utilities for SQLite statement processing.
///
/// This module contains thin RAII wrappers around the SQLite 3 structures
/// representing statements.

#if !defined(UTILS_SQLITE_STATEMENT_HPP)
#define UTILS_SQLITE_STATEMENT_HPP

extern "C" {
#include <stdint.h>
}

#include <string>
#include <tr1/memory>

namespace utils {
namespace sqlite {


class database;


/// Representation of the SQLite data types.
enum type {
    type_blob,
    type_float,
    type_integer,
    type_null,
    type_text,
};


/// A RAII model for an SQLite 3 statement.
class statement {
    struct impl;
    std::tr1::shared_ptr< impl > _pimpl;

    statement(database&, void*);
    friend class database;

public:
    ~statement(void);

    bool step(void);

    int column_count(void);
    std::string column_name(const int);
    type column_type(const int);

    const void* column_blob(const int);
    double column_double(const int);
    int column_int(const int);
    int64_t column_int64(const int);
    const char* column_text(const int);
    int column_bytes(const int);

    void reset(void);

    void bind_blob(const int, const void*, const int);
    void bind_double(const int, const double);
    void bind_int(const int, const int);
    void bind_int64(const int, const int64_t);
    void bind_null(const int);
    void bind_text(const int, const std::string&);

    int bind_parameter_count(void);
    int bind_parameter_index(const std::string&);
    std::string bind_parameter_name(const int);

    void clear_bindings(void);
};


}  // namespace sqlite
}  // namespace utils

#endif  // !defined(UTILS_SQLITE_STATEMENT_HPP)
