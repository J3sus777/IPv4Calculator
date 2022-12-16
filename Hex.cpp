#include <Hex.h>
std::string Hex::addrToHex(const std::array<uint8_t, 4>& addr) const
{
    std::string strAddr = addrToString(addr);
    std::array<int, 4> ip;
    std::stringstream stream;

    for (size_t i = 0; i < strAddr.size(); i++) {
        ip.at(i) = stoi(strAddr.substr(0, strAddr.find('.')));
        stream << std::hex << ip.at(i);
        std::string str = std::to_string(ip.at(i));
        strAddr.erase(0, str.size() + 1);
    }

    std::string ipHex(stream.str());
    return ipHex;
}
