/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/
#pragma once


#include <string>
#include <fstream>
#include <cotan/BitArray.hpp>

namespace cotan {



cotan::BitArray readFileBinary(const std::string& fileName);


void writeFileBinary(const cotan::BitArray& bitArray, const std::string& fileName);





}
