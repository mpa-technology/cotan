/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#include <cotan/BitArray.hpp>


cotan::BitArray::BitArray(){}

cotan::BitArray::BitArray(const std::string &string){

    for(const auto& it : string)
        data_.push_back(static_cast<type>(it));

}

cotan::BitArray &cotan::BitArray::operator<<(const std::vector<uint32_t> &vector){
    for(const auto &it : vector)
        data_.push_back(it);

    return *this;
}

cotan::BitArray &cotan::BitArray::operator<<(const std::string &string){

    for(const auto& it : string)
        data_.push_back(static_cast<type>(it));

    return *this;
}

cotan::BitArray::type &cotan::BitArray::operator[](const size_t &index){
    return data_.at(index);
}

cotan::BitArray::type_const &cotan::BitArray::operator[](const size_t &index) const{
    return data_.at(index);
}

bool cotan::BitArray::operator ==(const cotan::BitArray &bitArray) const{
    return data_ == bitArray.data_;
}

bool cotan::BitArray::operator !=(const cotan::BitArray &bitArray)const{
    return data_ != bitArray.data_;
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

std::string cotan::BitArray::toString() const{
    std::string string;

    for(const auto& it : data_)
        string += static_cast<std::string::value_type>(it);


    return string;
}

std::vector<uint8_t> cotan::BitArray::toVector() const{
    return data_;
}
