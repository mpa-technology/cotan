#include <cotan/utils/Memory.hpp>

bool cotan::isZeroMemory(void *const begin, void *const end) {


    if(!begin || !end)
        throw std::invalid_argument("begin or end == nullptr");

    const auto itb = reinterpret_cast<char*>(begin);
    const auto ite = reinterpret_cast<char*>(end);

    for(auto i = itb ; i != ite ; ++i) {
        if (*i != 0) {
            return false;
        }
    }

    return true;
}

void cotan::zeroMemory(void *const begin, void *const end) {
    using  ptrType = volatile unsigned char *volatile;

    if(!begin || !end)
        throw std::invalid_argument("begin or end == nullptr");

    auto  itb = reinterpret_cast<ptrType>(begin);
    auto  ite = reinterpret_cast<ptrType>(end);

    for(auto it = itb ; it != end ; ++it)
        *it = 0U;

}

void cotan::copyMemory(const void *const begin, const void *const end, void *const dis) {
    using  ptrType = volatile unsigned char *volatile;
    using  constPtrType = volatile const unsigned char *volatile;

    if(!begin || !end || !dis)
        throw std::invalid_argument("begin or end or dis == nullptr");

    auto  itb = reinterpret_cast<constPtrType>(begin);
    auto  ite = reinterpret_cast<constPtrType>(end);
    auto  itd = reinterpret_cast<ptrType>(dis);

    for(auto i = itb; i != ite ; ++i,++itd){
        *itd = *i;
    }


}

void cotan::swapMemory(void *const begin, void *const end, void *const dis) {
    using  ptrType = volatile unsigned char *volatile;


    if(!begin || !end || !dis)
        throw std::invalid_argument("begin or end or dis == nullptr");

    auto  itb = reinterpret_cast<ptrType>(begin);
    auto  ite = reinterpret_cast<ptrType>(end);
    auto  itd = reinterpret_cast<ptrType>(dis);

    for(auto i = itb; i != ite ; ++i,++itd){
        const auto tmp = *i;
        *i = *itd;
        *itd = tmp;
    }


}
