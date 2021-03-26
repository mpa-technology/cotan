/*
   SPDX-FileCopyrightText: 2021 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#pragma once
#include <limits>
#include <type_traits>
#include <cstdint>

template<typename T,typename =  std::enable_if<std::is_integral<T>::value>>
class XorshiftRandEngine{
public:
    using generateType = T;
    using seedType = generateType;


    generateType generate() noexcept{
        auto x = state_;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        return state_ = x;
    }

    XorshiftRandEngine(){
        state_ = 2;
    }

    XorshiftRandEngine(const seedType state){
        state_ = state;
    }

    XorshiftRandEngine(const XorshiftRandEngine &xorshiftRandEngine){
        state_ = xorshiftRandEngine.state_;
    }


    generateType generate(const generateType min,
                          const generateType max) noexcept{
        return  generate() % (max - min + 1) + min;
    }

    generateType min() const noexcept{
        return 0;
    }

    generateType max() const noexcept{
        return std::numeric_limits<T>::max()-1;
    }

    XorshiftRandEngine &operator=(const XorshiftRandEngine &xorshiftRandEngine){
        state_ = xorshiftRandEngine.state_;
        return *this;
    }

    void setSeed(const seedType state) noexcept{
        state_ = state;
    }

    seedType getSeed() const noexcept{
        return state_;
    }

private:
    seedType state_;


};

template<>
class XorshiftRandEngine<std::uint32_t>{
public:
    using generateType = std::uint32_t;
    using seedType = generateType;


    generateType generate() noexcept{
        auto x = state_;
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        return state_ = x;
    }

    XorshiftRandEngine(){
        state_ = 2;
    }

    XorshiftRandEngine(const seedType state){
        state_ = state;
    }

    XorshiftRandEngine(const XorshiftRandEngine &xorshiftRandEngine){
        state_ = xorshiftRandEngine.state_;
    }


    generateType generate(const generateType min,
                          const generateType max) noexcept{
        return  generate() % (max - min + 1) + min;
    }

    generateType min() const noexcept{
        return 0;
    }

    generateType max() const noexcept{
        return std::numeric_limits<generateType>::max()-1;
    }

    XorshiftRandEngine &operator=(const XorshiftRandEngine &xorshiftRandEngine){
        state_ = xorshiftRandEngine.state_;
        return *(this);
    }

    void setSeed(const seedType state) noexcept{
        state_ = state;
    }

    seedType getSeed() const noexcept{
        return state_;
    }

private:
    seedType state_;


};


template<>
class XorshiftRandEngine<std::uint64_t>{
public:
    using generateType =std::uint64_t;
    using seedType = generateType;


    generateType generate() noexcept{
        auto x = state_;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        return state_ = x;
    }

    XorshiftRandEngine(){
        state_ = 2;
    }

    XorshiftRandEngine(const seedType state){
        state_ = state;
    }

    XorshiftRandEngine(const XorshiftRandEngine &xorshiftRandEngine){
        state_ = xorshiftRandEngine.state_;
    }


    generateType generate(const generateType min,
                          const generateType max) noexcept{
        return  generate() % (max - min + 1) + min;
    }

    generateType min() const noexcept{
        return 0;
    }

    generateType max() const noexcept{
        return std::numeric_limits<generateType>::max()-1;
    }

    XorshiftRandEngine &operator=(const XorshiftRandEngine &xorshiftRandEngine){
        state_ = xorshiftRandEngine.state_;
        return *this;
    }

    void setSeed(const seedType state) noexcept{
        state_ = state;
    }

    seedType getSeed() const noexcept{
        return state_;
    }

private:
    seedType state_;


};

