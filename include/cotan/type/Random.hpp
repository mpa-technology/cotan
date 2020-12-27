#pragma once
#include <cotan/type/RandomInterface.hpp>

namespace cotan {



template<typename T>
class Random{

T* ri_;


public:


    Random(){
        ri_ = new T();
    }

    template<typename ...ARGC>
    Random(ARGC... v){
    ri_ = new T(v...);

    }

    virtual ~Random(){
        delete ri_;
    }




   auto maxValue() const{
        return  ri_->maxValue();
    }
    auto minValue() const {
        return  ri_->minValue();
    }

    auto step() {
        return  ri_->step();
    }

    auto last() const {
        ri_->last();
    }


};

}
