#include <ipCalculator.h>

ipV4Calculator::ipV4Calculator(std::string& Ipv4_Mask)
    : m_addressRaw(Ipv4_Mask)
{
    initAddr();
    parse();
}

const std::string ipV4Calculator::getAddress() { return addrToString(m_address); }
const std::string ipV4Calculator::getBinaryAddress() { return binary.addrToBinary(m_address); }
const std::string ipV4Calculator::getHexAddress() { return hex.addrToHex(m_address); }
const std::string ipV4Calculator::getLongNetmask() { return addrToString(m_longNetmask); }
const std::string ipV4Calculator::getBinaryLongNetmask()
{
    return binary.addrToBinary(m_longNetmask);
}
const std::string ipV4Calculator::getHexLongNetmask() { return hex.addrToHex(m_longNetmask); }
const std::string ipV4Calculator::getNetwork() { return addrToString(m_network); }
const std::string ipV4Calculator::getBinaryNetwork() { return binary.addrToBinary(m_network); }
const std::string ipV4Calculator::getHexNetwork() { return hex.addrToHex(m_network); }
const std::string ipV4Calculator::getBroadcast() { return addrToString(m_broadcast); }
const std::string ipV4Calculator::getBinaryBroadcast() { return binary.addrToBinary(m_broadcast); }
const std::string ipV4Calculator::getHexBroadcast() { return hex.addrToHex(m_broadcast); }
const std::string ipV4Calculator::getHostMin()
{
    if (m_netmask == 32 || m_netmask == 31)
        return "N/A";
    return addrToString(m_hostMin);
}
const std::string ipV4Calculator::getBinaryHostMin() { return binary.addrToBinary(m_hostMin); }
const std::string ipV4Calculator::getHexHostMin() { return hex.addrToHex(m_hostMin); }
const std::string ipV4Calculator::getHostMax()
{
    if (m_netmask == 32 || m_netmask == 31)
        return "N/A";
    return addrToString(m_hostMax);
}
const std::string ipV4Calculator::getBinaryHostMax() { return binary.addrToBinary(m_hostMax); }
const std::string ipV4Calculator::getHexHostMax() { return hex.addrToHex(m_hostMin); }
const std::string ipV4Calculator::getWildcard() { return addrToString(m_wildcard); }
const std::string ipV4Calculator::getBinaryWildcard() { return binary.addrToBinary(m_wildcard); }
const std::string ipV4Calculator::getHexWildcard() { return hex.addrToHex(m_wildcard); }
uint32_t ipV4Calculator::getUsableHosts() { return m_hostsNumber; }

uint32_t ipV4Calculator::getIPstep()
{
    int increment = 0;
    for (size_t i = 0; i < m_longNetmask.size(); i++) {
        if (m_longNetmask[i] == 255) {
            increment = 1;
        }
        else if (m_longNetmask[i] == 254) {
            increment = 2;
            break;
        }
        else if (m_longNetmask[i] == 252) {
            increment = 4;
            break;
        }
        else if (m_longNetmask[i] == 248) {
            increment = 8;
            break;
        }
        else if (m_longNetmask[i] == 240) {
            increment = 16;
            break;
        }
        else if (m_longNetmask[i] == 224) {
            increment = 32;
            break;
        }
        else if (m_longNetmask[i] == 192) {
            increment = 64;
            break;
        }
        else if (m_longNetmask[i] == 128) {
            increment = 128;
            break;
        }
    }
    return increment;
}

const std::string ipV4Calculator::getIPclassRess()
{
    std::string mask = m_addressRaw.substr(m_addressRaw.find('/') + 1);
    int classResult = 0;

    if (stoi(mask) >= 1 && stoi(mask) < 15) {
        classResult = 1;
    }
    else if (stoi(mask) >= 16 && stoi(mask) < 23) {
        classResult = 2;
    }
    else if (stoi(mask) >= 24 && stoi(mask) < 32) {
        classResult = 3;
    }
    else {
        classResult = 0;
    }

    switch (classResult) {
    case 1:
        return "A";
        break;
    case 2:
        return "B";
        break;
    case 3:
        return "C";
        break;
    default:
        return "Not in Range";
        break;
    }
    return 0;
}
void ipV4Calculator::setAddress(const std::string& addr)
{
    m_addressRaw = addr;
    initAddr();
    parse();
}

const std::string ipV4Calculator::getNextaddress()
{
    std::string br = &addrToString(nexthope).back() - 2;
    nexthope.at(m_network.size() - 1) += 1;
    if (br != "255")
        return addrToString(nexthope);
    else
        return "Next network address does not exist";
}
void ipV4Calculator::parse()
{
    // Decomposes the string into array of ipv4 address bytes m_address and netmask prefix
    size_t i = 0;
    char* token;
    std::string c_address = m_addressRaw;
    token = strtok(&c_address[0], "./");
    while (token != NULL) {
        if (i == m_address.max_size())
            m_netmask = (uint8_t)atoi(token);
        else
            m_address.at(i) = (uint8_t)atoi(token);
        i++;
        token = strtok(NULL, "./");
    }
    // Builds the long netmask from the prefix m_netmask
    uint8_t bitShifts = 32 - m_netmask, byteIndex = 3;
    while (bitShifts - 8 >= 0) {
        m_longNetmask.at(byteIndex) <<= 8;
        bitShifts -= 8;
        byteIndex--;
    }
    m_longNetmask.at(byteIndex) <<= bitShifts;
    // Network address
    for (size_t i = 0; i < m_address.size(); i++)
        m_network.at(i) = m_address.at(i) & m_longNetmask.at(i);

    // Wildcard and broadcast
    for (size_t i = 0; i < m_address.size(); i++) {
        m_wildcard.at(i) = 255 - m_longNetmask.at(i);
        m_broadcast.at(i) = m_network.at(i) + m_wildcard.at(i);
        nexthope.at(i) = m_network.at(i) + m_wildcard.at(i);
    }
    // Lowest and highest IP address in network range
    if (m_netmask == 32 || m_netmask == 31)
        m_hostsNumber = 0;
    else {
        m_hostMin = m_network;
        m_hostMax = m_broadcast;
        m_hostMin.at(m_network.size() - 1) += 1;
        m_hostMax.at(m_network.size() - 1) -= 1;
        // Number of usable hosts
        m_hostsNumber = (1 << (32 - m_netmask)) - 2;
    }
}

void ipV4Calculator::initAddr()
{
    m_longNetmask.fill(255);
    m_wildcard.fill(0);
    m_network.fill(0);
    m_broadcast.fill(0);
    m_hostMin.fill(0);
    m_hostMax.fill(0);
    m_hostsNumber = 0;
}
