/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#include <cotan/RandomSTD.hpp>

cotan::RandomSTD::RandomSTD():seed_(1){
    srand(seed_);
}

cotan::RandomSTD::RandomSTD(const size_t &seed):
    seed_(seed)
{
    srand(seed_);
}

size_t cotan::RandomSTD::seed() const{
    return seed_;
}

void cotan::RandomSTD::setSeed(const size_t &seed){
    seed_ = seed;
    srand(seed_);
}

size_t cotan::RandomSTD::step(){
    int tmp = rand();
    return tmp < 0 ? -tmp : tmp;
}

size_t cotan::RandomSTD::operator()(){
    return step();
}

size_t cotan::RandomSTD::min() const{
    return std::numeric_limits<size_t>::min();
}

size_t cotan::RandomSTD::max() const{
    return std::numeric_limits<size_t>::max();
}
