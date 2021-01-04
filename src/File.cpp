/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#include <cotan/File.hpp>

cotan::BitArray cotan::readFileBinary(const std::string &fileName){

    std::ifstream fstream(fileName,std::ios::binary);


    cotan::BitArray bitFile;

    char buffer;
    while (fstream.read(&buffer,1)) bitFile << buffer;


    return bitFile;
}

void cotan::writeFileBinary(const cotan::BitArray &bitArray, const std::string &fileName){

    std::ofstream fstream(fileName,std::ios::binary);
    for(const auto& it : bitArray)
        fstream << it;


}
