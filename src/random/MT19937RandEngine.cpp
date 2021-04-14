/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#include <cotan/random/Mt19937RandEngine.hpp>

cotan::Mt19937RandEngine::Mt19937RandEngine() { _init(); }

cotan::Mt19937RandEngine::generateType cotan::Mt19937RandEngine::generate() {
  int i;
  unsigned long long x;
  static unsigned long long mag01[2] = {0ULL, MATRIX_A};

  if (mti >= NN) {

    //            if (mti == NN+1)
    //                _init_genrand64(5489ULL);

    for (i = 0; i < NN - MM; i++) {
      x = (mt[i] & UM) | (mt[i + 1] & LM);
      mt[i] = mt[i + MM] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];
    }
    for (; i < NN - 1; i++) {
      x = (mt[i] & UM) | (mt[i + 1] & LM);
      mt[i] = mt[i + (MM - NN)] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];
    }
    x = (mt[NN - 1] & UM) | (mt[0] & LM);
    mt[NN - 1] = mt[MM - 1] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];

    mti = 0;
  }

  x = mt[mti++];

  x ^= (x >> 29) & 0x5555555555555555ULL;
  x ^= (x << 17) & 0x71D67FFFEDA60000ULL;
  x ^= (x << 37) & 0xFFF7EEE000000000ULL;
  x ^= (x >> 43);

  return x;
}

void cotan::Mt19937RandEngine::_init_genrand64(
    cotan::Mt19937RandEngine::generateType seed) {
  mt[0] = seed;
  for (mti = 1; mti < NN; mti++)
    mt[mti] =
        (6364136223846793005ULL * (mt[mti - 1] ^ (mt[mti - 1] >> 62)) + mti);
}

void cotan::Mt19937RandEngine::_init_by_array64(
    Mt19937RandEngine::generateType init_key[],
    Mt19937RandEngine::generateType key_length) {
  generateType i, j, k;
  _init_genrand64(_seed);
  i = 1;
  j = 0;
  k = (NN > key_length ? NN : key_length);
  for (; k; k--) {
    mt[i] =
        (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >> 62)) * 3935559000370003845ULL)) +
        init_key[j] + j; /* non linear */
    i++;
    j++;
    if (i >= NN) {
      mt[0] = mt[NN - 1];
      i = 1;
    }
    if (j >= key_length)
      j = 0;
  }
  for (k = NN - 1; k; k--) {
    mt[i] =
        (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >> 62)) * 2862933555777941757ULL)) -
        i; /* non linear */
    i++;
    if (i >= NN) {
      mt[0] = mt[NN - 1];
      i = 1;
    }
  }

  mt[0] = 1ULL << 63; /* MSB is 1; assuring non-zero initial array */
}

void cotan::Mt19937RandEngine::_clear() {

  mti = NN + 1;

  mt.fill(0);
}

void cotan::Mt19937RandEngine::_init() {
  _clear();
  unsigned long long init[4] = {0x12345ULL, 0x23456ULL, 0x34567ULL, 0x45678ULL},
                     length = 4;
  _init_by_array64(init, length);
}
