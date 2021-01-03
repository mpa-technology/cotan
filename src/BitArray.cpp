/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#include <cotan/BitArray.hpp>
#include <cstring>


cotan::BitArray::BitArray(){}

cotan::BitArray::BitArray(const std::string &string){

    for(const auto& it : string)
        data_.push_back(static_cast<type>(it));

}

cotan::BitArray &cotan::BitArray::operator<<(const std::string &string){

    for(const auto& it : string)
        data_.push_back(static_cast<type>(it));

    return *this;
}

cotan::BitArray &cotan::BitArray::operator<<(const size_t &value){
    data_.push_back(static_cast<type>(value));
    return *this;
}

cotan::BitArray &cotan::BitArray::operator<<(const char *string){

    const auto strSize = strlen(string);
    for(size_t i = 0; i!= strSize; ++i)
        data_.push_back(string[i]);


    return *this;
}

cotan::BitArray::iterator cotan::BitArray::begin(){
    return data_.begin();
}

cotan::BitArray::iterator_const cotan::BitArray::begin() const{
    return data_.begin();
}

cotan::BitArray::iterator cotan::BitArray::end(){
    return data_.end();
}

cotan::BitArray::iterator_const cotan::BitArray::end() const{
    return data_.end();
}

size_t cotan::BitArray::size() const{
    return data_.size();
}
