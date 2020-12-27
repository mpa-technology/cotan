/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#pragma once

#include <string>
#include <sstream>


namespace cotan {

class HashResult{


    std::string value_;
    std::string typeName_;


public:

    HashResult(const std::string& string);
    HashResult(const uint32_t& value);


    template<typename T>
    T get()const{
        return value_;
    }

    template<>
    std::string get()const{
        return value_;
    }

    std::string getHexString()const;


    template<>
    uint32_t get()const{
        return std::stoul(value_);
    }


    std::string typeName()const;


};

}
