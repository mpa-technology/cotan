/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#pragma once
namespace cotan {

class SRandEngine {

public:
  using generateType = unsigned long;
  using seedType = generateType;

  SRandEngine();

  SRandEngine(const seedType seed);

  SRandEngine(const SRandEngine &sRandEngine);

  generateType generate() noexcept;

  generateType generate(const generateType min,
                        const generateType max) noexcept;

  generateType min() const noexcept;

  generateType max() const noexcept;

  SRandEngine &operator=(const SRandEngine &sRandEngine);

  void setSeed(const seedType seed) noexcept;

  seedType getSeed() const noexcept;

private:
  generateType next_ = 1;
  seedType seed_;
  const generateType randMax_ = 32767;
};

} // namespace cotan
