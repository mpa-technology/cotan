/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#pragma once

#include <cotan/type/BitArray.hpp>
#include <cotan/type/HashResult.hpp>


namespace cotan {

class HashInterface{


public:

    virtual ~HashInterface();

    virtual void put(const BitArray& bitArray) = 0;

    virtual HashResult final() const  = 0;

    virtual void clear() = 0;

    virtual HashResult fast(const BitArray& bitArray)const = 0;


};

}
