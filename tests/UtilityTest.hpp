#pragma once
#include <gtest/gtest.h>
#include <cotan/Utility.hpp>


TEST(Utility,HexNum){
    ASSERT_EQ(cotan::toHex(1024),"400");
    ASSERT_EQ(cotan::toHex(16384),"4000");
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
