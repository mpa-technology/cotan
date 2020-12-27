 #pragma once
#include <string>
#include <cotan/type/RandomInterface.hpp>


namespace cotan {



template<typename T>
class StringRandom : public RandomInterface<std::string>{


    Type last_;

    std::string alf_;

    const size_t size_;

    T rdGen_;


    std::string get_(){

        std::string string;


        for(size_t i = 0 ; i != size_ ; ++i )
        string += alf_.at(rdGen_.step()%alf_.size());

        return string;
    }
public:


    StringRandom(const std::string& alf , const size_t& size ): alf_(alf) , size_(size) {}

    StringRandom(const size_t& size ): alf_(alphnum()) , size_(size) {}

    StringRandom(const std::string& alf , const size_t& size , const T& rdGen): alf_(alf) , size_(size) , rdGen_(rdGen) {}

    StringRandom(const size_t& size , const T& rdGen): alf_(alphnum()) , size_(size) , rdGen_(rdGen) {}

    virtual ~StringRandom(){}


    Type maxValue()const override{
        return {};
    }
    Type minValue()const override{
        return {};
    }

    Type step() override{

        last_ = get_();
        return last_;
    }

    Type last()const override{
        return last_;
    }


    static std::string alphnum(){
        return {"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyz"};
    }



};


}
