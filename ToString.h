#ifndef TOSTRING_H
#define TOSTRING_H
#include <array>
#include <string>
class ToString {
public:
    std::string addrToString(const std::array<uint8_t, 4>& addr) const;
};
#endif  // TOSTRING_H
