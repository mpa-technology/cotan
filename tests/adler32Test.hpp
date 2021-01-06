/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/



#pragma once

#include <gtest/gtest.h>
#include <cotan/Adler32.hpp>



TEST(Adler32,StringTest){

    ASSERT_EQ(cotan::Adler32::hash({"hello wolrd"}),0x1a05045d);
    ASSERT_EQ(cotan::Adler32::hash({"hello cotan"}),0x19a1044a);

}




TEST(Hash,Adler32StringTest){

    std::unique_ptr<cotan::Hash<std::uint64_t>>hash = std::make_unique<cotan::Adler32>();
    ASSERT_EQ(hash->now({"hello wolrd"}),0x1a05045d);

    ASSERT_EQ(hash->now({"hello cotan"}),0x19a1044a);


}


