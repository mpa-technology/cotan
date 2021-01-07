/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/



#pragma once

#include <gtest/gtest.h>
#include <cotan/Crc.hpp>



TEST(CRC8,stringTest){

    ASSERT_EQ(cotan::Crc8::hash({"hello wolrd"}),167);
    ASSERT_EQ(cotan::Crc8::hash({"hello cotan"}),183);

}


TEST(CRC32,stringTest){

    ASSERT_EQ(cotan::Crc32::hash({"hello wolrd"}),3546008634);
    ASSERT_EQ(cotan::Crc32::hash({"hello cotan"}),771948523);

}
