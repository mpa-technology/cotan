/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#include <gtest/gtest.h>
#include <cotan/cotan.hpp>
#include <iostream>


namespace cotan {



class SR : public RandomInterface<unsigned int> {


public:


};

}

TEST(all,all){





}


TEST(HashAdler32,HelloWorld){
    ASSERT_EQ(cotan::Adler32::now({"hello wolrd"}).getHexString(),"1a05045d");
}


TEST(HashAdler32,Cotan){
    ASSERT_EQ(cotan::Adler32::now({"cotan"}).getHexString(),"63c0216");
}


TEST(HashAdler32,Null){
    ASSERT_EQ(cotan::Adler32::now({}).getHexString(),"1");
}

TEST(Hash,Adler32){
    cotan::Hash<cotan::Adler32> hash;
    ASSERT_EQ(hash.fast({"Hello. cotan"}).getHexString(),"1b780458");
}

TEST(StringRandom,NE){

   cotan::StringRandom<cotan::RdRandom64>sr(12);
   const auto f = sr.step();
   const auto s = sr.step();

    ASSERT_NE(f,s);
}


TEST(Random,StringRandom){
    cotan::Random<cotan::StringRandom<cotan::RdRandom64>>rd{8};

    const auto f = rd.step();
    const auto s = rd.step();
    ASSERT_NE(f,s);
}



#if COTON_BUILD_NATIVE == 1 && (  defined(__i386__) || defined(__x86_64__) )


TEST(RdRandom,RdRandom16){
    cotan::RdRandom16 rd;
    const auto f = rd.step();
    const auto s = rd.step();
    ASSERT_NE(f,s);
}


TEST(RdRandom,RdRandom32){
    cotan::RdRandom32 rd;
    const auto f = rd.step();
    const auto s = rd.step();
    ASSERT_NE(f,s);
}


TEST(RdRandom,RdRandom64){
    cotan::RdRandom64 rd;
    const auto f = rd.step();
    const auto s = rd.step();
    ASSERT_NE(f,s);
}



TEST(Random,RdRandom16){
    cotan::Random<cotan::RdRandom16>rd;
    const auto f = rd.step();
    const auto s = rd.step();
    ASSERT_NE(f,s);
}

TEST(Random,RdRandom32){
    cotan::Random<cotan::RdRandom32>rd;
    const auto f = rd.step();
    const auto s = rd.step();
    ASSERT_NE(f,s);
}

TEST(Random,RdRandom64){
    cotan::Random<cotan::RdRandom64>rd;
    const auto f = rd.step();
    const auto s = rd.step();
    ASSERT_NE(f,s);
}




#endif






int main(int argc, char *argv[]){


    ::testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}
