#ifndef IPCALCULATOR_H
#define IPCALCULATOR_H
#include <Binary.h>
#include <Hex.h>
#include <ToString.h>
#include <stdio.h>
#include <string.h>

class ipV4Calculator : public ToString {
public:
    ipV4Calculator(std::string& Ipv4_Mask);
    const std::string getLongNetmask();
    const std::string getNetwork();
    const std::string getBroadcast();
    const std::string getHostMin();
    const std::string getHostMax();
    const std::string getNextaddress();
    const std::string getIPclassRess();
    const std::string getWildcard();
    const std::string getAddress();

    uint32_t getUsableHosts();
    uint32_t getIPstep();
    void setAddress(const std::string&);

    const std::string getBinaryLongNetmask();
    const std::string getBinaryNetwork();
    const std::string getBinaryBroadcast();
    const std::string getBinaryWildcard();
    const std::string getBinaryHostMin();
    const std::string getBinaryHostMax();
    const std::string getBinaryAddress();

    const std::string getHexAddress();
    const std::string getHexLongNetmask();
    const std::string getHexNetwork();
    const std::string getHexBroadcast();
    const std::string getHexWildcard();
    const std::string getHexHostMin();
    const std::string getHexHostMax();

private:
    void parse();
    void initAddr();
    Binary binary;
    Hex hex;
    std::array<uint8_t, 4> m_address, m_longNetmask, m_wildcard, m_network, m_broadcast, m_hostMin,
        m_hostMax, nexthope;
    uint8_t m_netmask;
    std::string m_addressRaw;
    uint32_t m_hostsNumber;
};

#endif  // IPCALCULATOR_H
