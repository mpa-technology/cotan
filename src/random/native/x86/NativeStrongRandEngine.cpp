/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/


#include <immintrin.h>
#include <cotan/random/native/x86/NativeStrongRandEngine.hpp>

cotan::NativeStrongRandEngine::NativeStrongRandEngine(){}

cotan::NativeStrongRandEngine::generateType cotan::NativeStrongRandEngine::generate(){
    generateType rn;
    const auto res = _rdseed64_step(&rn);

    if(!res)
        throw std::runtime_error("error generate random value");

    return rn;
}

cotan::NativeStrongRandEngine::generateType cotan::NativeStrongRandEngine::generate(const cotan::NativeStrongRandEngine::generateType min, const cotan::NativeStrongRandEngine::generateType max){
    return generate() % (max - min + 1) + min;
}

cotan::NativeStrongRandEngine::generateType cotan::NativeStrongRandEngine::min() const noexcept{
    return std::numeric_limits<generateType>::min();
}

cotan::NativeStrongRandEngine::generateType cotan::NativeStrongRandEngine::max() const noexcept{
    return std::numeric_limits<generateType>::max();
}
