/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#pragma once

#include <vector>
#include <string>



namespace cotan {


class BitArray{

    std::vector<std::uint8_t>data_;


public:
    typedef std::uint8_t type;
    typedef const std::uint8_t type_const;
    typedef std::vector<type>::iterator iterator;
    typedef const std::vector<type>::const_iterator iterator_const;



    BitArray();

    BitArray(const std::string& string);



    BitArray& operator<<(const std::string& string);

    BitArray& operator<<(const size_t& value);


    BitArray& operator<<(const char* string);




    template<typename T>
    BitArray& operator<<(const T& value){
        data_.push_back(static_cast<type>(value));
        return *this;
    }


    type& operator[](const size_t& index){
        return data_.at(index);
    }

    type_const& operator[](const size_t& index)const{
        return data_.at(index);
    }



    iterator begin();
    iterator_const begin()const;


    iterator end();

    iterator_const end()const;

    size_t size()const;


    std::string toString()const{
        std::string string;

        for(const auto& it : data_)
            string += static_cast<std::string::value_type>(it);


        return string;
    }




};

}
