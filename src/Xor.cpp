/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#include <cotan/Xor.hpp>

cotan::BitArray cotan::xorEncryption(const cotan::BitArray &data, const cotan::BitArray &key){

    cotan::BitArray final;

    if(data.size() != key.size())
        throw std::out_of_range("data.size() != key.size()");

    const auto& size = data.size();

    for(size_t i = 0; i != size; ++i){
        const auto res = data[i] xor key[i];

        final << res;


    }


    return final;
}
