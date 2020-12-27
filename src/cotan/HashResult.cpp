/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#include <cotan/type/HashResult.hpp>

namespace cotan {


HashResult::HashResult(const std::string &string):value_(string){
    typeName_ = typeid (string).name();
}

HashResult::HashResult(const uint32_t &value){
    value_ = std::to_string(value);
    typeName_ = typeid (value).name();
}

std::string HashResult::getHexString() const{
    std::stringstream ss;
    ss << std::hex << get<uint32_t>();

    return ss.str();
}

std::string HashResult::typeName() const{
    return typeName_;
}


}
