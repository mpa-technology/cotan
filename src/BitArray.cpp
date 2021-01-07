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

cotan::BitArray::BitArray(const cotan::BitArraySlice &slice){

    for(const auto &it: slice){
        data_.push_back(it);
    }

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

cotan::BitArray::type &cotan::BitArray::at(const size_t &index){
    return data_.at(index);
}

cotan::BitArray::type_const &cotan::BitArray::at(const size_t &index) const{
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

bool cotan::BitArray::isEmpty() const{
    return data_.empty();
}

cotan::BitArraySlice cotan::BitArray::slice(){
    BitArraySlice slice(this);
    slice.ibegin = data_.begin();
    slice.iend = data_.end();
    slice.size = std::distance(slice.ibegin,slice.iend);
    return slice;
}

cotan::BitArraySlice cotan::BitArray::slice(const size_t &index){
    BitArraySlice slice(this);
    slice.ibegin = data_.begin()+index;
    slice.iend = data_.end();
    slice.size = std::distance(slice.ibegin,slice.iend);
    return slice;
}

cotan::BitArraySlice cotan::BitArray::slice(const size_t &begin, const size_t &end){
    BitArraySlice slice(this);
    slice.ibegin = data_.begin()+begin;
    slice.iend = data_.begin()+end;
    slice.size = std::distance(slice.ibegin,slice.iend);
    return slice;
}






//BitArraySlice


cotan::BitArraySlice::BitArraySlice(cotan::BitArray *bitArray):bitArray_(bitArray){}

cotan::BitArray *cotan::BitArraySlice::bitArray(){
    return bitArray_;
}

const cotan::BitArray *cotan::BitArraySlice::bitArray() const{
    return bitArray_;
}

cotan::BitArraySlice::iterator cotan::BitArraySlice::begin(){
    return ibegin;
}

cotan::BitArraySlice::iterator cotan::BitArraySlice::end(){
    return iend;
}

cotan::BitArraySlice::iterator_const cotan::BitArraySlice::begin() const{
    return ibegin;
}

cotan::BitArraySlice::iterator_const cotan::BitArraySlice::end() const{
    return iend;
}
