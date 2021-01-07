/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/

#pragma once

#include <exception>
#include <string>
#include <sstream>
#include <iomanip>

namespace cotan {


template<typename T , typename  = typename std::enable_if<std::is_integral<T>::value>::type >
std::string toHexW(const T &value){
    std::stringstream ss;


    ss << std::setfill ('0') << std::setw(sizeof(decltype (value))*2)
       << std::hex << (value);



    return ss.str();
}

template<typename T , typename  = typename std::enable_if<std::is_integral<T>::value>::type >
std::string toHex(const T &value){
    std::stringstream ss;


    ss <<  std::hex << (value);



    return ss.str();
}




class NotImplemented_ : public std::exception{


    std::string msg_;

public:


    NotImplemented_(const std::string &fnName , const std::string &className , const std::string &msg);



    virtual  ~NotImplemented_();


    virtual const char* what() const noexcept;


};

#ifndef NotImplemented
#define NotImplemented NotImplemented_(__func__,__PRETTY_FUNCTION__,std::string())
#define NotImplementedMessage(msg) NotImplemented_(__func__,__PRETTY_FUNCTION__,msg)
#endif


}



