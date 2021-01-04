/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/
#pragma once


#include <stdexcept>
#include <random>
#include <limits>

#include <cotan/BitArray.hpp>

namespace cotan {




cotan::BitArray xorEncryption(const cotan::BitArray &data , const cotan::BitArray &key);





template<typename RANDOMENGINE = std::default_random_engine>
cotan::BitArray xorKeyGenerate(const cotan::BitArray& data , RANDOMENGINE randomEngine = RANDOMENGINE()){

    cotan::BitArray key;
    std::uniform_int_distribution<size_t> uid(std::numeric_limits<cotan::BitArray::type>::min(),std::numeric_limits<cotan::BitArray::type>::max());

    for(size_t i = 0 ;i != data.size(); ++i){
        key << uid(randomEngine);
    }




    return key;
}







}
