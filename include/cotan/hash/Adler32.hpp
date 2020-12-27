/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#pragma once
#include <cotan/type/HashInterface.hpp>

namespace cotan {



class Adler32 : public HashInterface{



    static  uint32_t adler32_( const BitArray& buffer , const size_t& adler = 1 );

    uint32_t lastAdler_ = 1;


public:

    Adler32();

    virtual ~Adler32();

    void put(const BitArray& bitArray)override;

    HashResult final()const override;


    void clear()override;


    HashResult fast(const BitArray& bitArray)const override;

    static HashResult now(const BitArray& bitArray);

};

}
