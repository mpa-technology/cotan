/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/
#pragma once

#include <limits>
#include <stdlib.h>
#include <cotan/RandomInterface.hpp>


namespace cotan {



class RandomSTD : public RandomInterface<size_t,size_t>{

    size_t seed_;


public:

    RandomSTD();

    RandomSTD(const size_t &seed);


    size_t seed()const override;

    void setSeed(const size_t& seed)override;


    size_t step()override;

    size_t operator()()override;



    size_t min()const override;

    size_t max()const override;

};



}
