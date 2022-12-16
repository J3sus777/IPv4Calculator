#include <Binary.h>
std::string Binary::addrToBinary(const std::array<uint8_t, 4>& addr) const
{
    std::string strAddr = addrToString(addr);

    unsigned a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    std::istringstream iss{strAddr};
    char dotDummy;
    iss >> a1 >> dotDummy >> a2 >> dotDummy >> a3 >> dotDummy >> a4;

    std::bitset<8> b1{a1};
    std::bitset<8> b2{a2};
    std::bitset<8> b3{a3};
    std::bitset<8> b4{a4};

    std::string Binaryip =
        b1.to_string() + ' ' + b2.to_string() + ' ' + b3.to_string() + ' ' + b4.to_string();

    return Binaryip;
}
