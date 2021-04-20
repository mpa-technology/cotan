#include <cotan/Utils/Memory.hpp>

bool cotan::isZero(void *const begin, void *const end) {


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
