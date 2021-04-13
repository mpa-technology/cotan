/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#include <cotan/native/random/x86/NativeStrongRandEngine.hpp>
#include <immintrin.h>
cotan::NativeStrongRandEngine::NativeStrongRandEngine() {}

cotan::NativeStrongRandEngine::generateType
cotan::NativeStrongRandEngine::generate() {
  generateType rn;
  const auto res = _rdseed64_step(&rn);

  if (!res)
    throw std::runtime_error("error generate random value");

  return rn;
}

cotan::NativeStrongRandEngine::generateType cotan::NativeStrongRandEngine::generateNotThrow()
{
    generateType rn;
    const auto res = _rdseed64_step(&rn);

    return !res ? generateNotThrow() : rn;
}



cotan::NativeStrongRandEngine::generateType
cotan::NativeStrongRandEngine::min() const noexcept {
  return std::numeric_limits<generateType>::min();
}

cotan::NativeStrongRandEngine::generateType
cotan::NativeStrongRandEngine::max() const noexcept {
  return std::numeric_limits<generateType>::max();
}
