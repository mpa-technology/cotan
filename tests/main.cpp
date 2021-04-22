/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#include <gtest/gtest.h>

#include <cotan/random/random.hpp>

#include <cotan/utils/Memory.hpp>

using namespace cotan;

TEST(Memory, isZero) {
    std::array<int, 10> array;
    array.fill(25);


    ASSERT_FALSE(isZeroMemory(array.data(), array.data() + array.size()));
    array.fill(0);
    ASSERT_TRUE(isZeroMemory(array.data(), array.data() + array.size()));

    ASSERT_THROW(isZeroMemory(array.data(), nullptr), std::invalid_argument);
    ASSERT_THROW(isZeroMemory(nullptr, array.data()), std::invalid_argument);
    ASSERT_THROW(isZeroMemory(nullptr, nullptr), std::invalid_argument);

}

TEST(SRandEngine, testRandomNumber) {

    SRandEngine re;
    const auto val1 = re.generate();
    const auto val2 = re.generate();

    ASSERT_NE(val1, val2);
}

TEST(SRandEngine, testRandomNumberSeed) {

    SRandEngine re;
    SRandEngine res(static_cast<SRandEngine::seedType>(time(nullptr)));

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
    std::vector<SRandEngine::generateType> v(10);

    rg.generate(v.begin(), v.end());

    auto it = std::unique(v.begin(), v.end());
    bool wasUnique = (it == v.end());

    ASSERT_TRUE(wasUnique);
}

TEST(RandomGenerator, testRange) {

    RandomGenerator<SRandEngine> re;

    const SRandEngine::generateType min = 25;
    const SRandEngine::generateType max = 128;

    for (size_t i = 0; i != 128; ++i) {
        const auto val = re.generate({min, max});
        ASSERT_TRUE(val <= max && val >= min);
    }
}

TEST(RandomGenerator, testRandomNumberSeed) {

    RandomGenerator<SRandEngine> re;
    RandomGenerator<SRandEngine> res(
            static_cast<SRandEngine::generateType>(time(nullptr)));

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

TEST(MSWSRandEngine, testRandomNumberSeed) {

    MSWSRandEngine re;
    MSWSRandEngine res(static_cast<MSWSRandEngine::seedType>(time(nullptr)));

    const auto v1 = re.generate();
    const auto v2 = re.generate();

    const auto vs1 = res.generate();
    const auto vs2 = res.generate();

    ASSERT_NE(v1, vs1);
    ASSERT_NE(v2, vs2);
}


TEST(Mt19937RandEngine, testRandomNumber) {

    Mt19937RandEngine re;
    const auto val1 = re.generate();
    const auto val2 = re.generate();

    ASSERT_NE(val1, val2);
}

TEST(Mt19937RandEngine, testRandomNumberSeed) {
    MSWSRandEngine re;
    MSWSRandEngine res(static_cast<MSWSRandEngine::seedType>(time(nullptr)));

    const auto v1 = re.generate();
    const auto v2 = re.generate();

    const auto vs1 = res.generate();
    const auto vs2 = res.generate();

    ASSERT_NE(v1, vs1);
    ASSERT_NE(v2, vs2);
}

TEST(XorshiftRandEngin, testRandomNumber) {


    XorshiftRandEngine<uint64_t> re;
    const auto val1 = re.generate();
    const auto val2 = re.generate();

    ASSERT_NE(val1, val2);
}

TEST(XorshiftRandEngin, testRandomNumberSeed) {
    XorshiftRandEngine<uint64_t> re;
    XorshiftRandEngine<uint64_t> res(static_cast<XorshiftRandEngine<uint64_t>::seedType>(time(nullptr)));

    const auto v1 = re.generate();
    const auto v2 = re.generate();

    const auto vs1 = res.generate();
    const auto vs2 = res.generate();

    ASSERT_NE(v1, vs1);
    ASSERT_NE(v2, vs2);
}

TEST(RandomTimeDevice, testTime) {
    RandomTimeDevice re;


    const auto v1 = re.generate<long>();

    sleep(1);

    const auto v2 = re.generate<long>();


    ASSERT_NE(v1, v2);

}

TEST(StringGenerator, testRandomString) {

    StringGenerator<XorshiftRandEngine<std::uint64_t>> sg;
    sg.setSeed({12, "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZ"});
    const auto v1 = sg.generate();
    const auto v2 = sg.generate();
    ASSERT_NE(v1, v2);
}

#if defined(USE_SPECIFICALLY_PLATFORM) || defined(COTAN_SP)

TEST(NativeRandEngine, testRandomNumber) {

    NativeRandEngine re;
    const auto val1 = re.generate();
    const auto val2 = re.generate();

    ASSERT_NE(val1, val2);
}

TEST(NativeStrongRandEngine, testRandomNumber) {

    NativeStrongRandEngine re;
    const auto val1 = re.generateNotThrow();
    const auto val2 = re.generateNotThrow();

    ASSERT_NE(val1, val2);
}

#endif



TEST(f8SRandEngine, testRandomNumber) {

    SRandEngine re;
    const auto val1 = re.generate();
    const auto val2 = re.generate();

    ASSERT_NE(val1, val2);
}

TEST(f8SRandEngine, testRandomNumberSeed) {

    f8SRandEngine re;
    f8SRandEngine res(static_cast<f8SRandEngine::seedType>(time(nullptr)));

    const auto v1 = re.generate();
    const auto v2 = re.generate();

    const auto vs1 = res.generate();
    const auto vs2 = res.generate();

    ASSERT_NE(v1, vs1);
    ASSERT_NE(v2, vs2);
}


#ifdef SPEED_TEST
TEST(f8SRandEngine, testSpeed) {

    f8SRandEngine re;
    for (size_t i = 0; i != std::numeric_limits<size_t>::max(); ++i) {
        const f8SRandEngine::generateType t = re.generate();
        static_cast<void>(t);
    }
}

TEST(MSWSRandEngine, testSpeed) {

    MSWSRandEngine re;
    for (unsigned int i = 0; i != std::numeric_limits<unsigned int>::max(); ++i) {
        const MSWSRandEngine::generateType t = re.generate();
        static_cast<void>(t);
    }
}

TEST(Mt19937RandEngine, testSpeed) {

    Mt19937RandEngine re;
    for (unsigned int i = 0; i != std::numeric_limits<unsigned int>::max(); ++i) {
        const Mt19937RandEngine::generateType t = re.generate();
        static_cast<void>(t);
    }
}

TEST(SRandEngine, testSpeed) {

    SRandEngine re;
    for (unsigned int i = 0; i != std::numeric_limits<unsigned int>::max(); ++i) {
        const SRandEngine::generateType t = re.generate();
        static_cast<void>(t);
    }
}


#endif


int main(int argc, char *argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
