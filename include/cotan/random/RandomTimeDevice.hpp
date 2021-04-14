/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

_Pragma("once")
#include <ctime>

    namespace cotan {

  class RandomTimeDevice {

  public:
    template <typename T> T time() const { return static_cast<T>(_time()); }

    template <> std::time_t time() const { return _time(); }

    template <typename T> T generate() { return time<T>(); }

  private:
    std::time_t _time() const { return std::time(nullptr); }
  };
}
