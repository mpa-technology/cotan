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






int main(int argc, char *argv[]){

    ::testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}
