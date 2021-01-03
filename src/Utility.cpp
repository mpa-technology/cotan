/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#pragma once

#include <cotan/Utility.hpp>

//NotImplemented_ BEGIN

cotan::NotImplemented_::NotImplemented_(const std::string &fnName, const std::string &className, const std::string &msg){
    msg_ =  "function(" +fnName+") in class(" + className +")";

    if(!msg.empty())
        msg_.append(" : ").append(msg);

}


cotan::NotImplemented_::~NotImplemented_(){}

const char *cotan::NotImplemented_::what() const noexcept
{
    return msg_.c_str();
}

//NotImplemented_ END
