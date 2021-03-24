/*
   SPDX-FileCopyrightText: 2020 Maxim Palshin
   <palshin.maxim.alekseevich@gmail.com> SPDX-License-Identifier: BSD 3-Clause
   "New" or "Revised" License
*/

#include <cotan/random/MSWSRandEngine.hpp>

cotan::MSWSRandEngine::MSWSRandEngine():seed_(0xb5ad4eceda1ce2a9),x_(0),w_(0){

}

cotan::MSWSRandEngine::MSWSRandEngine(const cotan::MSWSRandEngine::seedType seed){
    seed_ = seed;
}

cotan::MSWSRandEngine::MSWSRandEngine(const cotan::MSWSRandEngine &mSWSRandEngine){
    x_ = mSWSRandEngine.x_;
    w_ = mSWSRandEngine.w_;
    seed_ = mSWSRandEngine.seed_;
}

cotan::MSWSRandEngine::generateType cotan::MSWSRandEngine::generate() noexcept{
    x_ *= x_;
    x_ += (w_ += seed_);
    return x_ = (x_>>32) | (x_<<32);
}

cotan::MSWSRandEngine::generateType cotan::MSWSRandEngine::generate(const cotan::MSWSRandEngine::generateType min, const cotan::MSWSRandEngine::generateType max) noexcept{
    return  generate() % (max - min + 1) + min;
}

cotan::MSWSRandEngine::generateType cotan::MSWSRandEngine::min() const noexcept{
    return x_;
}

cotan::MSWSRandEngine::generateType cotan::MSWSRandEngine::max() const noexcept{
    return std::numeric_limits<generateType>::max();
}

cotan::MSWSRandEngine &cotan::MSWSRandEngine::operator=(const cotan::MSWSRandEngine &mSWSRandEngine){
    x_ = mSWSRandEngine.x_;
    w_ = mSWSRandEngine.w_;
    seed_ = mSWSRandEngine.seed_;
    return *(this);
}

void cotan::MSWSRandEngine::setSeed(const cotan::MSWSRandEngine::seedType seed) noexcept{
    seed_ = seed;
}

cotan::MSWSRandEngine::seedType cotan::MSWSRandEngine::getSeed() const noexcept{
    return seed_;
}
