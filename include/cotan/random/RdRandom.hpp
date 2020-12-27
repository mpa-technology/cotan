#pragma once
#include <limits>
#include <cotan/cotan/buildFlag.hpp>
#include <cotan/type/RandomInterface.hpp>




#if COTON_BUILD_NATIVE == 1 && (  defined(__i386__) || defined(__x86_64__) )

namespace  cotan {






class  RdRandom64 : public RandomInterface<unsigned  long long>{

    Type last_;

public:

    virtual ~RdRandom64();


    Type step() override;

    Type  last() const override;

    Type maxValue()const override;

    Type  minValue()const override;

};


class  RdRandom32 : public RandomInterface<unsigned>{

    Type  last_;

public:


    virtual ~RdRandom32();


    Type step() override;
    Type last() const override;


    Type  maxValue()const override;

    Type minValue()const override;


};


class  RdRandom16 : public RandomInterface<unsigned short> {


    Type last_;

public:

    virtual ~RdRandom16();


    Type step() override;
   Type last() const override;

    Type maxValue()const override;

    Type minValue()const override;

};

}


#else


#endif
