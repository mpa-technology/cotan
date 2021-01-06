/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/




#pragma once
#include <gtest/gtest.h>
#include <cotan/Xor.hpp>
#include <cotan/RandomSTD.hpp>

TEST(Xor,KeyGenerate){




    cotan::BitArray barray{"hello wolrd"};
    const auto& key = cotan::xorKeyGenerate(barray);

    ASSERT_NE(key,barray);
    ASSERT_EQ(barray.size(),key.size());



}

TEST(Xor,StringTest){


    cotan::BitArray barray{"hello wolrd"};
    const auto& key = cotan::xorKeyGenerate(barray);
    auto xorData = cotan::xorEncryption(barray,key);

    ASSERT_NE(barray,xorData);

    xorData = cotan::xorEncryption(xorData,key);


    ASSERT_EQ(xorData,barray);







}
