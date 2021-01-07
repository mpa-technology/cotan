/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#include <cotan/Crc.hpp>

//crc8
uint8_t cotan::Crc8::algorithm_(const cotan::BitArray &bitArray, const unsigned &iteration){
    unsigned crc = iteration;
    int i;
    for (const auto &it : bitArray) {
        crc ^= (it << 8);
        for(i = 8; i; i--) {
            if (crc & 0x8000)
                crc ^= (0x1070 << 3);
            crc <<= 1;
        }
    }
    return (uint8_t)(crc >> 8);
}

cotan::Crc8::Crc8() : iteration_(0){

}

void cotan::Crc8::addData(const cotan::BitArray &bitArray){
    iteration_ = algorithm_(bitArray,iteration_);
}

uint8_t cotan::Crc8::final(){
    return iteration_;
}

uint8_t cotan::Crc8::now(const cotan::BitArray &bitArray){

    return Crc8::hash(bitArray);
}

uint8_t cotan::Crc8::hash(const cotan::BitArray &bitArray){
    Crc8 crc8;
    crc8.addData(bitArray);
    return crc8.final();
}


//crc32


uint32_t cotan::Crc32::algorithm_(const cotan::BitArray &bitArray, const unsigned &iteration){
    auto crc = iteration;
    for(const auto &it : bitArray)
    {
        crc = (crc << 8) ^ table_[((crc >> 24) ^ it) & 255];

    }
    return crc;
}

cotan::Crc32::Crc32():iteration_(0xffffffff){

}

void cotan::Crc32::addData(const cotan::BitArray &bitArray){
    iteration_ = algorithm_(bitArray,iteration_);
}

uint32_t cotan::Crc32::final(){
    return iteration_;
}

uint32_t cotan::Crc32::now(const cotan::BitArray &bitArray){
    return Crc32::hash(bitArray);
}

uint32_t cotan::Crc32::hash(const cotan::BitArray &bitArray){
    Crc32 crc32;
    crc32.addData(bitArray);
    return crc32.final();
}
