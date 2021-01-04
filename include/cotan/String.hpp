/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#pragma once

#include <string>

#include <cotan/RandomInterface.hpp>



namespace cotan {


template<typename T = size_t>
std::string stringRandom( const size_t &length , RandomInterface<size_t,T> &rd , const std::string& alp = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"){
    std::string string(length,0);

    for(auto &it : string)
        it = alp.at( rd() % alp.length()  );


    return string;
}

}
