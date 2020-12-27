#pragma once

namespace cotan {


template<typename T>
class RandomInterface{

public:


    typedef  T Type;


    virtual ~RandomInterface(){}

    virtual T maxValue() const = 0;

    virtual T minValue() const = 0;

    virtual T step() = 0;

    virtual T last() const = 0;



};



}
