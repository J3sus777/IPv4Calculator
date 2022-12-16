#ifndef BINARY_H
#define BINARY_H
#include <ToString.h>
#include <bitset>
#include <sstream>

class Binary : public ToString {
public:
    std::string addrToBinary(const std::array<uint8_t, 4>& addr) const;
};

#endif  // BINARY_H
