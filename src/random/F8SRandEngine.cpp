/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/


#include <cotan/random/F8SRandEngine.hpp>

cotan::f8SRandEngine::generateType cotan::f8SRandEngine::generate() noexcept {
    auto t = _x ^ (_x << 4);
    _x =_y;
    _y =_z;
    _z =_seed;
    _seed = _z ^ t ^ ( _z >> 1) ^ (t << 1);

    return _seed;
}

cotan::f8SRandEngine::f8SRandEngine() :_x(0),_y(0),_z(0),_seed(1){}

cotan::f8SRandEngine::generateType cotan::f8SRandEngine::min() const noexcept {
    return  std::numeric_limits<generateType>::min();
}

cotan::f8SRandEngine::generateType cotan::f8SRandEngine::max() const noexcept {
    return  std::numeric_limits<generateType>::max();
}

void cotan::f8SRandEngine::setSeed(const cotan::f8SRandEngine::seedType seed) noexcept {
    _seed = seed;
}

cotan::f8SRandEngine::seedType cotan::f8SRandEngine::getSeed() const noexcept {
    return _seed;
}

cotan::f8SRandEngine::f8SRandEngine(const cotan::f8SRandEngine::seedType seed) :_x(0),_y(0),_z(0),_seed(seed){}
