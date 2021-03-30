/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#pragma once
#include <string>
namespace cotan {

template <typename RandEngine, typename CST = char> class StringGenerator {

public:
  using generateType = std::basic_string<CST>;
  using seedType = std::pair<size_t, generateType>;

  StringGenerator() {}
  StringGenerator(const RandEngine &randEngine) : rengine_(randEngine) {}
  StringGenerator(const seedType &seed) : seed_(seed) {}
  StringGenerator(const seedType &seed, const RandEngine &randEngine)
      : seed_(seed), rengine_(randEngine) {}

  generateType generate() {

    generateType result;

    const auto [length, string] = seed_;

    for (size_t i = 0; i != length; ++i) {
      const size_t index = rengine_.generate(0, string.length() - 1);
      result += seed_.second.at(index);
    }

    return result;
  }

  void setSeed(const seedType &seed) { seed_ = seed; }

  RandEngine &getRandEngine() { return rengine_; }

  const RandEngine &getRandEngine() const { return rengine_; }

private:
  seedType seed_{0, ""};
  RandEngine rengine_;
};

} // namespace cotan
