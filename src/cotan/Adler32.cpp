/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#include <cotan/hash/Adler32.hpp>

namespace cotan {


uint32_t Adler32::adler32_(const BitArray &buffer, const size_t &adler)
{
    unsigned long s1 = adler & 0xffff;
    unsigned long s2 = (adler >> 16) & 0xffff;

    for(const auto& it : buffer){

        s1 = ( s1 + it  ) % 65521;
        s2 = ( s2 + s1 ) % 65521;

    }

    return  ( s2 << 16 ) + s1;
}

Adler32::Adler32(){

}

Adler32::~Adler32(){}

void Adler32::put(const BitArray &bitArray){
    lastAdler_ = adler32_(bitArray,lastAdler_);
}

HashResult Adler32::final() const{

    std::stringstream ss;
    ss << lastAdler_;

    return ss.str();
}

void Adler32::clear(){
    lastAdler_ = 1;
}

HashResult Adler32::fast(const BitArray &bitArray) const{
    std::stringstream ss;

    ss  <<  adler32_(bitArray,1);

    return ss.str();
}

HashResult Adler32::now(const BitArray &bitArray){
    std::stringstream ss;

    ss << adler32_(bitArray,1);

    return ss.str();
}

}
