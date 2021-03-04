/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/
#pragma once

#include <limits>
#include <cstdint>
#include <cotan/RandomInterface.hpp>


//FIXME: NOT TEST

namespace cotan {

class XorShift : public RandomInterface<std::size_t,std::size_t>{


    uint32_t seed_, x_, y_, z_;


    uint32_t xorshift128_(void);


public:

    XorShift();

    XorShift(const std::size_t &seed);


    std::size_t seed()const override;

    void setSeed(const std::size_t& seed)override;


    std::size_t step()override;

    std::size_t operator()()override;



    std::size_t min()const override;

    std::size_t max()const override;

};


}
