/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#include <cotan/XorShift.hpp>


uint32_t cotan::XorShift::xorshift128_()
{
    uint32_t t = x_;
    t ^= t << 11U;
    t ^= t >> 8U;
    x_ = y_; y_ = z_; z_ = seed_;
    seed_ ^= seed_ >> 19U;
    seed_ ^= t;
    return seed_;
}

cotan::XorShift::XorShift():
    seed_(0xf),x_(0xff),y_(0xfff),z_(0xffff){}

cotan::XorShift::XorShift(const std::size_t &seed):
    seed_(seed),x_(0xff),y_(0xfff),z_(0xffff)
{

}

std::size_t cotan::XorShift::seed() const{
    return seed_;
}

void cotan::XorShift::setSeed(const std::size_t &seed){
    seed_ = seed;
}

std::size_t cotan::XorShift::step(){
    return xorshift128_();
}

std::size_t cotan::XorShift::operator()(){
    return step();
}

std::size_t cotan::XorShift::min() const{
    return std::numeric_limits<std::size_t>::min();
}

std::size_t cotan::XorShift::max() const{
    return std::numeric_limits<std::size_t>::max();
}
