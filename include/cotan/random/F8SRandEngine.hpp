/*
   SPDX-FileCopyrightText: 2021 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#pragma once

#include <limits>


namespace cotan {

    class f8SRandEngine {

    public:
        using generateType = unsigned char;
        using seedType = generateType;

        f8SRandEngine();

        f8SRandEngine(const seedType seed);


        generateType generate() noexcept;

        generateType min() const noexcept;

        generateType max() const noexcept;


        void setSeed(const seedType seed) noexcept;

        seedType getSeed() const noexcept;

    private:
        generateType _x, _y, _z, _seed;
    };


}