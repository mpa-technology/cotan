/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin <palshin.maxim.alekseevich@gmail.com>
   SPDX-License-Identifier: BSD 3-Clause "New" or "Revised" License
*/


#pragma once
#include <cotan/cotan/buildFlag.hpp>
#include <cotan/type/Hash.hpp>
#include <cotan/hash/Adler32.hpp>
#include <cotan/type/Random.hpp>
#include <cotan/random/StringRandom.hpp>

#if COTON_BUILD_NATIVE == 1 && (  defined(__i386__) || defined(__x86_64__) )

#include <cotan/random/RdRandom.hpp>

#endif


namespace cotan {







}

