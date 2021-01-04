/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#pragma once


namespace cotan {


template<typename RT,typename  ST>
class RandomInterface{

public:

    typedef  RT result_type;

    virtual ~RandomInterface(){}

    virtual result_type step() = 0;

    virtual void setSeed(const ST& seed) = 0;

    virtual result_type seed()const = 0;

    virtual result_type operator ()() = 0;

    virtual result_type max()const = 0;

    virtual result_type min()const = 0;

};


}
