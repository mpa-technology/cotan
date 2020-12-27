/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#include <cotan/type/BitArray.hpp>

namespace cotan {

BitArray::BitArray(){

}

BitArray::BitArray(const std::string &string){
    for(const auto&it : string)
        bits_.push_back(static_cast<uint8_t>(it));
}

BitArray::BitArray(const char *cstring){

    const size_t size = strlen(cstring);

    for(size_t i = 0 ; i != size ; ++i )
        bits_.push_back(cstring[i]);


}

BitArray::BitArray(const char &ch){

    bits_.push_back(ch);


}

BitArray::BitArray(const char *cstring, const size_t size){

    for(size_t i = 0 ; i != size ; ++i )
        bits_.push_back(cstring[i]);


}

size_t BitArray::length() const{
    return bits_.size();
}

size_t BitArray::size() const{
    return bits_.size();
}

std::vector<uint8_t>::iterator BitArray::begin(){
    return bits_.begin();
}

std::vector<uint8_t>::iterator BitArray::end(){
    return bits_.end();
}

const std::vector<uint8_t>::const_iterator BitArray::begin() const{
    return bits_.begin();
}

const std::vector<uint8_t>::const_iterator BitArray::end() const{
    return bits_.end();
}

}
