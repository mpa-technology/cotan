/*
   SPDX-FileCopyrightText: 2021 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#pragma once

#include <cstdint>
#include <limits>

namespace cotan {

class MSWSRandEngine {

public:
  using generateType = std::uint64_t;
  using seedType = generateType;

  MSWSRandEngine();

  MSWSRandEngine(const seedType seed);

  MSWSRandEngine(const MSWSRandEngine &mSWSRandEngine);

  generateType generate() noexcept;

  generateType min() const noexcept;

  generateType max() const noexcept;

  MSWSRandEngine &operator=(const MSWSRandEngine &mSWSRandEngine);

  void setSeed(const seedType seed) noexcept;

  seedType getSeed() const noexcept;

private:
  seedType seed_;
  generateType x_;
  generateType w_;
};

} // namespace cotan
