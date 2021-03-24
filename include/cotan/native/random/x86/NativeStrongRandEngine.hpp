/*
  SPDX-FileCopyrightText: 2020 Maxim Palshin
  <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
  "New" or "Revised" License
*/

#pragma once
#include <limits>
#include <stdexcept>

namespace cotan {

class NativeStrongRandEngine {

public:
  using generateType = unsigned long long;
  using seedType = void;

  NativeStrongRandEngine();

  generateType generate();

  generateType generate(const generateType min, const generateType max);

  generateType min() const noexcept;

  generateType max() const noexcept;

private:
};

} // namespace cotan
