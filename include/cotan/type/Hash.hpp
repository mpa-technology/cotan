/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#pragma once

#include <cotan/type/HashInterface.hpp>

namespace cotan {


template<typename T>
class Hash{

    T HashInterface_;

public:

    void put(const BitArray& bitArray){

        HashInterface_.put(bitArray);

    }

    HashResult final(){
        return  HashInterface_.final();
    }

    void clear(){
        HashInterface_.clear();
    }

    HashResult fast(const BitArray& bitArray)const{
        return  HashInterface_.fast(bitArray);
    }




};



}
