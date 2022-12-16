#ifndef HEX_H
#define HEX_H
#include <ToString.h>
#include <bitset>
#include <sstream>
class Hex : public ToString {
public:
    std::string addrToHex(const std::array<uint8_t, 4>& addr) const;
};
#endif  // HEX_H
