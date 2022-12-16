#include <ToString.h>
std::string ToString::addrToString(const std::array<uint8_t, 4>& addr) const
{
    std::string strAddr = "";
    size_t i;
    for (i = 0; i < addr.size() - 1; i++)
        strAddr += std::to_string(addr.at(i)) + '.';
    strAddr += std::to_string(addr.at(i));
    return strAddr;
}
