/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#pragma once


#include <cotan/Hash.hpp>
#include <cotan/BitArray.hpp>


namespace cotan {




class Crc8 : public Hash<uint8_t>{



    uint8_t algorithm_(const BitArray &bitArray, const unsigned &iteration);

    unsigned iteration_;

public:

    Crc8();


    void addData(const BitArray &bitArray)override;

    uint8_t final()override;

    uint8_t now(const BitArray& bitArray)override;

    static uint8_t hash(const BitArray& bitArray);



};




}
