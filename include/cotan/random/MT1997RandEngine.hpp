/*
   SPDX-FileCopyrightText: 2021 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#pragma once

#include <cstdint>
#include <limits>
#include <array>
class MT1997RandEngine {


public:
    using generateType = unsigned long long;
    using seedType = generateType;




    MT1997RandEngine();

    generateType  generate();

private:


#ifndef MT1997RandEngine_NN
#define MT1997RandEngine_NN 312
#endif

    const generateType MM = 156;
    const generateType MATRIX_A = 0xB5026F5AA96619E9ULL;
    const generateType UM = 0xFFFFFFFF80000000ULL;
    const generateType LM =0x7FFFFFFFUL;


    std::array<generateType,MT1997RandEngine_NN>mt;


    generateType mti;

    void _init_genrand64( generateType seed);

    void _init_by_array64( generateType init_key[],
                           generateType key_length);

    void _clear();

    void _init();


    seedType _seed = 5489ULL;
};


