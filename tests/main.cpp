/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#include <fstream>
#include <iterator>


#include "Adler32Test.hpp"
#include "UtilityTest.hpp"
#include "XorTest.hpp"
#include "CrcTest.hpp"
#include <cotan/XorShift.hpp>
using namespace cotan;





int main(int argc, char *argv[]){

    XorShift  xs(7);

    for(int i = 0;i!=5;++i)
        std::cout << xs() << std::endl;


    ::testing::InitGoogleTest(&argc,argv);

    //return RUN_ALL_TESTS();
}
