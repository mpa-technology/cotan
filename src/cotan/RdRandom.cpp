
#include <cotan/random/RdRandom.hpp>






#if COTON_BUILD_NATIVE == 1 && (  defined(__i386__) || defined(__x86_64__) )


#include <immintrin.h>

unsigned long long cotan::RdRandom64::last() const
{
    return last_;
}

cotan::RdRandom64::~RdRandom64(){}

cotan::RdRandom64::Type cotan::RdRandom64::step(){
    unsigned long long result = 0ULL;
    int rc = _rdrand64_step (&result);
    last_ = result;

    return result;
}

cotan::RdRandom64::Type cotan::RdRandom64::maxValue() const{
    return   std::numeric_limits<unsigned long long>::max();
}

cotan::RdRandom64::Type cotan::RdRandom64::minValue() const{
    return  std::numeric_limits<unsigned long long>::min();
}


cotan::RdRandom32::Type  cotan::RdRandom32::last() const
{
    return last_;
}

cotan::RdRandom32::Type cotan::RdRandom32::maxValue() const{
    return   std::numeric_limits<unsigned>::max();
}

cotan::RdRandom32::Type cotan::RdRandom32::minValue() const{
    return  std::numeric_limits<unsigned>::min();
}


cotan::RdRandom32::~RdRandom32(){}

cotan::RdRandom32::Type  cotan::RdRandom32::step(){
    unsigned  result = 0ULL;
    int rc = _rdrand32_step (&result);
    last_ = result;

    return result;
}

cotan::RdRandom16::Type cotan::RdRandom16::last() const
{
    return last_;
}

cotan::RdRandom16::Type cotan::RdRandom16::maxValue() const{
    return   std::numeric_limits<unsigned short>::max();
}

cotan::RdRandom16::Type cotan::RdRandom16::minValue() const{
    return  std::numeric_limits<unsigned short>::min();
}



cotan::RdRandom16::~RdRandom16(){}

cotan::RdRandom16::Type cotan::RdRandom16::step(){
    unsigned short  result = 0ULL;
    int rc = _rdrand16_step(&result);

    last_ = result;

    return result;
}



#endif

