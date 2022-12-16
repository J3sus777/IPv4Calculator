#include <iostream>
#include <ipCalculator.h>

int main()
{
    std::string Ipv4_Mask = "";

    std::cout << "Enter to IPv4/Mask: ";
    std::getline(std::cin, Ipv4_Mask);

    ipV4Calculator ip4(Ipv4_Mask);
    std::cout << "INFO           "
              << "\t ADDRESS "
              << "\t\t\t BINARY ADDRESS"
              << "\t       HEX ADDRESS" << std::endl;
    std::cout << "---------------------------------------------------------------------------------"
                 "---------"
              << std::endl;
    std::cout << "Address:       " << ip4.getAddress() << "\t " << ip4.getBinaryAddress() << "\t  "
              << ip4.getHexAddress() << std::endl;
    std::cout << "---------------------------------------------------------------------------------"
                 "---------"
              << std::endl;
    std::cout << "Long netmask:  " << ip4.getLongNetmask() << "\t " << ip4.getBinaryLongNetmask()
              << "\t  " << ip4.getHexLongNetmask() << std::endl;
    std::cout << "---------------------------------------------------------------------------------"
                 "---------"
              << std::endl;
    std::cout << "Network:       " << ip4.getNetwork() << "\t " << ip4.getBinaryNetwork() << "\t  "
              << ip4.getHexNetwork() << std::endl;
    std::cout << "---------------------------------------------------------------------------------"
                 "---------"
              << std::endl;
    std::cout << "Broadcast:     " << ip4.getBroadcast() << "\t " << ip4.getBinaryBroadcast()
              << "\t  " << ip4.getHexBroadcast() << std::endl;
    std::cout << "---------------------------------------------------------------------------------"
                 "---------"
              << std::endl;
    std::cout << "Address Range: " << ip4.getHostMin() << "\t " << ip4.getBinaryHostMin() << "\t  "
              << ip4.getHexHostMin() << "\n\t      - " << ip4.getHostMax() << "\t - "
              << ip4.getBinaryHostMax() << "\t  " << ip4.getHexHostMax() << std::endl;
    std::cout << "---------------------------------------------------------------------------------"
                 "---------"
              << std::endl;
    std::cout << "Wildcard:      " << ip4.getWildcard() << "\t\t " << ip4.getBinaryWildcard()
              << "\t  " << ip4.getHexWildcard() << std::endl;

    std::cout << "---------------------------------------------------------------------------------"
                 "---------"
              << std::endl;
    std::cout << "#Usable hosts: " << ip4.getUsableHosts() << "\t"
              << "IP Class:      " << ip4.getIPclassRess() << std::endl;
    std::cout << "---------------------------------------------------------------------------------"
                 "---------"
              << std::endl;
    std::cout << "#Step:         " << ip4.getIPstep() << "\t"
              << "Next network address: " << ip4.getNextaddress() << std::endl;
    std::cout << "---------------------------------------------------------------------------------"
                 "---------"
              << std::endl;

    return 0;
}
