/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#include <gtest/gtest.h>

#include <cotan/random/random.hpp>

using namespace cotan;

TEST(SRandEngine, testRandomNumber) {

  SRandEngine re;
  const auto val1 = re.generate();
  const auto val2 = re.generate();

  ASSERT_NE(val1, val2);
}

TEST(SRandEngine, testRange) {

  SRandEngine re;

  const SRandEngine::generateType min = 25;
  const SRandEngine::generateType max = 128;

  for (size_t i = 0; i != std::numeric_limits<unsigned short>::max(); ++i) {
    const auto val = re.generate(min, max);
    ASSERT_TRUE(val <= max && val >= min);
  }
}

TEST(SRandEngine, testRandomNumberSeed) {

  SRandEngine re;
  SRandEngine res(static_cast<unsigned long>(time(nullptr)));

  const auto v1 = re.generate();
  const auto v2 = re.generate();

  const auto vs1 = res.generate();
  const auto vs2 = res.generate();

  ASSERT_NE(v1, vs1);
  ASSERT_NE(v2, vs2);
}

TEST(RandomGenerator, testRandomNumber) {

  RandomGenerator<SRandEngine> rg;
  const auto v1 = rg.generate();
  const auto v2 = rg.generate();

  ASSERT_NE(v1, v2);
}

TEST(RandomGenerator, testIterator) {

  RandomGenerator<SRandEngine> rg;
  std::vector<unsigned long> v(10);

  rg.generate(v.begin(), v.end());

  auto it = std::unique(v.begin(), v.end());
  bool wasUnique = (it == v.end());

  ASSERT_TRUE(wasUnique);
}

TEST(RandomGenerator, testRange) {

  RandomGenerator<SRandEngine> re;

  const SRandEngine::generateType min = 25;
  const SRandEngine::generateType max = 128;

  for (size_t i = 0; i != std::numeric_limits<unsigned short>::max(); ++i) {
    const auto val = re.generate({min, max});
    ASSERT_TRUE(val <= max && val >= min);
  }
}

TEST(RandomGenerator, testRandomNumberSeed) {

  RandomGenerator<SRandEngine> re;
  RandomGenerator<SRandEngine> res(static_cast<unsigned long>(time(nullptr)));

  const auto v1 = re.generate();
  const auto v2 = re.generate();

  const auto vs1 = res.generate();
  const auto vs2 = res.generate();

  ASSERT_NE(v1, vs1);
  ASSERT_NE(v2, vs2);
}

TEST(MSWSRandEngine, testRandomNumber) {

  MSWSRandEngine re;
  const auto val1 = re.generate();
  const auto val2 = re.generate();

  ASSERT_NE(val1, val2);
}

TEST(MSWSRandEngine, testRange) {

  MSWSRandEngine re;

  const MSWSRandEngine::generateType min = 25;
  const MSWSRandEngine::generateType max = 128;

  for (size_t i = 0; i != std::numeric_limits<unsigned short>::max(); ++i) {
    const auto val = re.generate(min, max);
    ASSERT_TRUE(val <= max && val >= min);
  }
}

TEST(MSWSRandEngine, testRandomNumberSeed) {

  MSWSRandEngine re;
  MSWSRandEngine res(static_cast<unsigned long>(time(nullptr)));

  const auto v1 = re.generate();
  const auto v2 = re.generate();

  const auto vs1 = res.generate();
  const auto vs2 = res.generate();

  ASSERT_NE(v1, vs1);
  ASSERT_NE(v2, vs2);
}

TEST(StringGenerator, testRandomString) {

  StringGenerator<XorshiftRandEngine<std::uint64_t>> sg;
  sg.setSeed({12, "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZ"});
  const auto v1 = sg.generate();
  const auto v2 = sg.generate();
  ASSERT_NE(v1, v2);
}

#ifdef DISABLE

TEST(NativeRandEngine, testRandomNumber) {

  NativeRandEngine re;
  const auto val1 = re.generate();
  const auto val2 = re.generate();

  ASSERT_NE(val1, val2);
}

TEST(NativeRandEngine, testRange) {

  NativeRandEngine re;

  const SRandEngine::generateType min = 25;
  const SRandEngine::generateType max = 128;

  for (size_t i = 0; i != std::numeric_limits<unsigned short>::max(); ++i) {
    const auto val = re.generate(min, max);
    ASSERT_TRUE(val <= max && val >= min);
  }
}

TEST(NativeStrongRandEngine, testRandomNumber) {

  NativeStrongRandEngine re;
  const auto val1 = re.generate();
  const auto val2 = re.generate();

  ASSERT_NE(val1, val2);
}

TEST(NativeStrongRandEngine, testRange) {

  NativeStrongRandEngine re;

  const SRandEngine::generateType min = 25;
  const SRandEngine::generateType max = 128;

  for (size_t i = 0; i != std::numeric_limits<unsigned short>::max(); ++i) {
    const auto val = re.generate(min, max);
    ASSERT_TRUE(val <= max && val >= min);
  }
}

#endif

int main(int argc, char *argv[]) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
