/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/



#pragma once
#include <numeric>
#include <gtest/gtest.h>
#include <cotan/Utility.hpp>


TEST(Utility,HexNum){
    ASSERT_EQ(cotan::toHex(1024),"400");
    ASSERT_EQ(cotan::toHex(16384),"4000");

    //FIXME:
    ASSERT_EQ(cotan::toHex(std::numeric_limits<int>::max()),"7fffffff");
    ASSERT_EQ(cotan::toHex(std::numeric_limits<int>::min()),"80000000");

}


TEST(Utility,HexNumW){
    ASSERT_EQ(cotan::toHexW(1024),"00000400");
    ASSERT_EQ(cotan::toHexW(16384),"00004000");



    //FIXME:
    ASSERT_EQ(cotan::toHexW(std::numeric_limits<int>::max()),"7fffffff");
    ASSERT_EQ(cotan::toHexW(std::numeric_limits<int>::min()),"80000000");
}


void f(){
    throw cotan::NotImplemented;
}

class Tc{

public:


    void f(){
    throw cotan::NotImplemented;
    }

};


TEST(NotImplementedException,Test){

    EXPECT_THROW(f(),cotan::NotImplemented_);
    Tc c;
    EXPECT_THROW(c.f(),cotan::NotImplemented_);
}


#include <cotan/Adler32.hpp>




TEST(UtilityAndAdler32,StringTest){

    auto hash = cotan::Adler32::hash({"hello wolrd"});
    auto hex = cotan::toHex(hash);

    ASSERT_EQ(hex,"1a05045d");


    hash = cotan::Adler32::hash({"hello cotan"});
    hex = cotan::toHex(hash);

    ASSERT_EQ(hex,"19a1044a");

}
