/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#include <gtest/gtest.h>



#include <cotan/SRandEngine.hpp>
#include <cotan/RandomGenerator.hpp>
using namespace cotan;


TEST(SRandEngine,testRandomNumber){

    SRandEngine re;
    const auto val1 = re.generate();
    const auto val2 = re.generate();

    ASSERT_NE(val1,val2);


}

TEST(SRandEngine,testRange){


    SRandEngine re;

    const SRandEngine::generateType min = 25;
    const SRandEngine::generateType max = 128;

    for(size_t i = 0; i != std::numeric_limits<unsigned short>::max() ; ++i){
        const auto val = re.generate(min,max);
        ASSERT_TRUE( val <= max && val >= min );
    }


}

TEST(SRandEngine,testRandomNumberSeed){


    SRandEngine re;
    SRandEngine res(static_cast<unsigned long>(time(nullptr)));

    const auto v1 = re.generate();
    const auto v2 = re.generate();

    const auto vs1 = res.generate();
    const auto vs2 = res.generate();

    ASSERT_NE(v1,vs1);
    ASSERT_NE(v2,vs2);


}

TEST(RandomGenerator,testRandomNumber){


   RandomGenerator<SRandEngine>rg;
   const auto v1 = rg.generate();
   const auto v2 = rg.generate();

   ASSERT_NE(v1,v2);


}

TEST(RandomGenerator,tsetIterator){


   RandomGenerator<SRandEngine>rg;
   std::vector<unsigned long>v(10);

   rg.generate(v.begin(),v.end());

   auto it = std::unique( v.begin(),v.end() );
   bool wasUnique = (it == v.end() );


   ASSERT_TRUE(wasUnique);



}

TEST(RandomGenerator,testRange){


    RandomGenerator<SRandEngine> re;

    const SRandEngine::generateType min = 25;
    const SRandEngine::generateType max = 128;

    for(size_t i = 0; i != std::numeric_limits<unsigned short>::max() ; ++i){
        const auto val = re.generate({min,max});
        ASSERT_TRUE( val <= max && val >= min );
    }




}

TEST(RandomGenerator,testRandomNumberSeed){


    RandomGenerator<SRandEngine> re;
    RandomGenerator<SRandEngine> res(static_cast<unsigned long>(time(nullptr)));

    const auto v1 = re.generate();
    const auto v2 = re.generate();

    const auto vs1 = res.generate();
    const auto vs2 = res.generate();

    ASSERT_NE(v1,vs1);
    ASSERT_NE(v2,vs2);


}

int main(int argc, char *argv[]){


::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
