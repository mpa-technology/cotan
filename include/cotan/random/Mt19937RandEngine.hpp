/*
   SPDX-FileCopyrightText: 2021 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#pragma once

#include <array>
#include <cstdint>
#include <limits>

namespace cotan {

class Mt19937RandEngine {

public:
  using generateType = unsigned long long;
  using seedType = generateType;

  Mt19937RandEngine();

  generateType generate();

  void setSeed(const seedType seed) {
    _clear();
    _seed = seed;
    _init();
  }

private:
  const generateType MM = 156;
  const generateType MATRIX_A = 0xB5026F5AA96619E9ULL;
  const generateType UM = 0xFFFFFFFF80000000ULL;
  const generateType LM = 0x7FFFFFFFUL;

  static constexpr generateType NN = 312;
  std::array<generateType, NN> mt;

  generateType mti;

  void _init_genrand64(generateType seed);

  void _init_by_array64(generateType init_key[], generateType key_length);

  void _clear();

  void _init();

  seedType _seed = 5489ULL;
};

} // namespace cotan
