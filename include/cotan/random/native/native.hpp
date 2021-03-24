/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#pragma once



#if defined(__x86_64__) || defined(__amd64)   || defined(__x86)
#include <cotan/random/native/x86/NativeRandEngine.hpp>
#include <cotan/random/native/x86/NativeStrongRandEngine.hpp>
#endif
