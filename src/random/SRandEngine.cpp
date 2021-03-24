/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#include <cotan/random/SRandEngine.hpp>

cotan::SRandEngine::SRandEngine() { seed_ = next_ = 1; }

cotan::SRandEngine::SRandEngine(const cotan::SRandEngine::seedType seed) {
  next_ = seed_ = seed;
}

cotan::SRandEngine::SRandEngine(const SRandEngine &sRandEngine) {
  next_ = sRandEngine.next_;
  seed_ = sRandEngine.seed_;
}

cotan::SRandEngine::generateType cotan::SRandEngine::generate() noexcept {
  next_ = next_ * 1103515245 + 12345;
  return (next_ / 65536) % (randMax_ + 1);
}

cotan::SRandEngine::generateType
cotan::SRandEngine::generate(const SRandEngine::generateType min,
                             const SRandEngine::generateType max) noexcept {
  return generate() % (max - min + 1) + min;
}

cotan::SRandEngine::generateType cotan::SRandEngine::min() const noexcept {
  return 0;
}

cotan::SRandEngine::generateType cotan::SRandEngine::max() const noexcept {
  return randMax_;
}

cotan::SRandEngine &
cotan::SRandEngine::operator=(const SRandEngine &sRandEngine) {
  next_ = sRandEngine.next_;
  seed_ = sRandEngine.seed_;
  return *this;
}

void cotan::SRandEngine::setSeed(const SRandEngine::seedType seed) noexcept {
  seed_ = next_ = seed;
}

cotan::SRandEngine::seedType cotan::SRandEngine::getSeed() const noexcept {
  return seed_;
}
