/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#pragma once
#include <utility>

namespace cotan {

template <typename RENGINE> class RandomGenerator {
public:
  using generateType = typename RENGINE::generateType;
  using seedType = typename RENGINE::generateType;

  RandomGenerator() {}
  RandomGenerator(seedType seed) { setSeed(seed); }
  RandomGenerator(const RandomGenerator &rg) { rengine_ = rg.rengine_; }
  RandomGenerator(const RENGINE &engine) { rengine_ = engine; }

  generateType generate() { return rengine_.generate(); }

  generateType generate(const std::pair<generateType, generateType> range) {
    const auto [min, max] = range;
    return rengine_.generate() % (max - min + 1) + min;
  }

  template <typename ForwardIterator>
  void generate(ForwardIterator begin, ForwardIterator end) {

    for (auto it = begin; it != end; ++it)
      *(it) = generate();
  }

  template <typename ForwardIterator>
  void generate(ForwardIterator begin, ForwardIterator end,
                const std::pair<generateType, generateType> range) {

    for (auto it = begin; it != end; ++it)
      *(it) = generate(range);
  }

  void setSeed(const seedType seed) { rengine_.setSeed(seed); }

  seedType getSeed() const { return rengine_.getSeed(); }

  generateType min() const { return rengine_.min(); }

  generateType max() const { return rengine_.max(); }

  static RandomGenerator create(seedType seed) {
    RandomGenerator rg(seed);
    return rg;
  }

  static RandomGenerator create() {
    RandomGenerator rg;
    return rg;
  }

  generateType operator()() { return generate(); }

private:
  RENGINE rengine_;
};

} // namespace cotan
