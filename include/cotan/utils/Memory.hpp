/*
   SPDX-FileCopyrightText: 2021 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#pragma once

#include <stdexcept>

namespace cotan{


    bool isZeroMemory(void *const begin , void *const end);

    void zeroMemory(void *const begin, void *const end);

    void copyMemory(const void *const begin , const void *const end, void *const dis);

    void swapMemory(void *const begin , void *const end, void *const dis);

    size_t distanceMemory(const void *begin , const void *end);


}



