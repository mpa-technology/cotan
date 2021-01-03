/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/
#pragma once

namespace cotan {


class BitArray;

template<typename RTYPE>
class Hash{

public:

    virtual ~Hash(){}


    virtual void addData(const BitArray &bitArray) = 0;

    virtual RTYPE final() = 0;

    virtual RTYPE now(const BitArray& bitArray) = 0;


};

}
