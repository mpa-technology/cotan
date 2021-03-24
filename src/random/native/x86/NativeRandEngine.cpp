/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/


#include <immintrin.h>
#include <cotan/random/native/x86/NativeRandEngine.hpp>

cotan::NativeRandEngine::NativeRandEngine(){}

cotan::NativeRandEngine::generateType cotan::NativeRandEngine::generate(){
    generateType rn;
    const auto res = _rdrand64_step(&rn);

    if(!res)
        throw std::runtime_error("error generate random value");

    return rn;
}

cotan::NativeRandEngine::generateType cotan::NativeRandEngine::generate(const cotan::NativeRandEngine::generateType min, const cotan::NativeRandEngine::generateType max){
    return generate() % (max - min + 1) + min;
}

cotan::NativeRandEngine::generateType cotan::NativeRandEngine::min() const noexcept{
    return std::numeric_limits<generateType>::min();
}

cotan::NativeRandEngine::generateType cotan::NativeRandEngine::max() const noexcept{
    return std::numeric_limits<generateType>::max();
}
