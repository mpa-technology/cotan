/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#pragma once

#include <cstdint>

#include <cotan/Hash.hpp>
#include <cotan/BitArray.hpp>

namespace cotan {


class Adler32 : public Hash<std::uint64_t>{


    size_t iteration_;



    std::uint64_t algorithm_(const BitArray &bitArray, const size_t &iteration);


public:


    Adler32();


    void addData(const BitArray &bitArray)override;

    uint64_t final()override;


    std::uint64_t now(const BitArray &bitArray)override;

    static uint64_t hash(const BitArray &bitArray);



};


}


