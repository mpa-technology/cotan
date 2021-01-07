/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#pragma once

#include <vector>
#include <string>
#include <cstring>


namespace cotan {

class BitArray;

class BitArraySlice{




    BitArray* bitArray_;

public:


    typedef std::uint8_t type;
    typedef const std::uint8_t type_const;
    typedef std::vector<type>::iterator iterator;
    typedef const std::vector<type>::const_iterator iterator_const;



    BitArraySlice(BitArray* bitArray);

    BitArray* bitArray();

    const BitArray* bitArray()const;

    iterator ibegin;
    iterator iend;

    iterator begin();


    iterator end();


    iterator_const begin()const;


    iterator_const end()const;


    size_t size;



};

class BitArray{

    std::vector<std::uint8_t>data_;

public:
    typedef std::uint8_t type;
    typedef const std::uint8_t type_const;
    typedef std::vector<type>::iterator iterator;
    typedef const std::vector<type>::const_iterator iterator_const;


    BitArray();

    BitArray(const std::string &string);
    BitArray(const BitArraySlice &slice);


    BitArray& operator<<(const std::vector<std::uint32_t> &vector);

    BitArray& operator<<(const std::string &string);

    BitArray& operator<<(const size_t &value);

    BitArray& operator<<(const char *string);



    template<typename T>
    BitArray& operator<<(const std::vector<T> &value){
        data_.push_back(static_cast<type>(value));
        return *this;
    }


    template<typename T>
    BitArray& operator<<(const T &value){
        data_.push_back(static_cast<type>(value));
        return *this;
    }

    template<typename T>
    BitArray& add(const T &value){
        *this << value;

        return *this;
    }

    type& operator[](const size_t &index);

    type& at(const size_t &index);

    type_const& at(const size_t &index)const;

    type_const& operator[](const size_t &index)const;


    bool operator == (const BitArray& bitArray)const;

    bool operator != (const BitArray& bitArray)const;

    iterator begin();
    iterator_const begin()const;

    iterator end();

    iterator_const end()const;

    size_t size()const;


    std::string toString()const;

    std::vector<std::uint8_t>toVector()const;

    bool isEmpty()const;


    BitArraySlice slice();


    BitArraySlice slice(const size_t &index);

    BitArraySlice slice(const size_t &begin , const size_t &end);



};

}
