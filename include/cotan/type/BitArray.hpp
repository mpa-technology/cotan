/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#pragma once

#include <string>
#include <vector>
#include <cstring>

namespace  cotan {


class BitArray{

    std::vector<std::uint8_t>bits_;


public:


    BitArray();

    BitArray(const std::string& string);

    BitArray(const char* cstring);


    BitArray(const char& ch);


    BitArray(const char* cstring , const size_t size);

    template<typename T>
    BitArray(const std::vector<T>&vector){

        for(const auto&it : vector)
            bits_.push_back(static_cast<unsigned char>(it));

    }


    template<typename T>
    void push(const T& value){
        bits_.push_back(static_cast<unsigned char>(value));
    }

    template<>
    void push(const std::string& string){

        for(const auto&it : string)
            bits_.push_back(static_cast<unsigned char>(it));

    }


    size_t length()const;

    size_t size()const;

    std::vector<unsigned char>::iterator begin();


    std::vector<unsigned char>::iterator end();


    const std::vector<unsigned char>::const_iterator begin()const;


    const std::vector<unsigned char>::const_iterator end()const;



};

}
