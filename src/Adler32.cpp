/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#include <cotan/Adler32.hpp>


std::uint64_t cotan::Adler32::algorithm_(const BitArray &bitArray, const size_t iteration)
{
    std::uint64_t s1 = iteration & 0xffff;
    std::uint64_t s2 = (iteration >> 16) & 0xffff;

    for(const auto& it : bitArray){

        s1 = ( s1 + it  ) % 65521;
        s2 = ( s2 + s1 ) % 65521;

    }

    return  ( s2 << 16 ) + s1;
}

cotan::Adler32::Adler32():iteration_(1){}

void cotan::Adler32::addData(const BitArray &bitArray){

    iteration_ =  algorithm_(bitArray,iteration_);

}

uint64_t cotan::Adler32::final(){
    const auto result = iteration_;
    iteration_ = 1;
    return result;
}

std::uint64_t cotan::Adler32::now(const BitArray &bitArray){
    return Adler32::hash(bitArray);
}

uint64_t cotan::Adler32::hash(const BitArray &bitArray){
    Adler32 adler32;
    adler32.addData(bitArray);
    return adler32.final();
}
