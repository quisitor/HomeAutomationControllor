/*****************************************************************//**
 * \file   ValidationLibrary.cpp
 * \brief  Implementation for the static validation library
 * 
 * \author Craig Smith
 * \date   May 2022
 *********************************************************************/
#include "ValidationLibrary.h"
#include <regex>

namespace ValidationLibrary {
	
	bool ValidationLibrary::Network::isMACValid(std::string mac)
	{
		/*
		6xHexOctects  HH:HH:HH:HH:HH:HH
		*/
		
		std::string regString = "^([0-9A-Fa-f]{2}:){5}([0-9A-Fa-f]{2})$";
		std::regex reg(regString);
		return std::regex_match(mac, reg);
	}

	bool Network::isIPv4AddressValid(std::string ipV4Address)
	{
		/*
		dotted decimal ipv4: 0.0.0.0 to 255.255.255.255
		1st octect { 0-9 | 10 to 99 | 100 to 199 | 200 to 254 } .
		2nd to 3rd octect { 0-9 | 10-99 | 100 to 199 | 200 to 255 } .
		4th octect { 0-9 | 10-99 | 100 to 199 | 200 to 255 }
		*/
		
		std::string firstOctet = "(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-4])\\.){1}";
		std::string secondAndThirdOctets = "(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){2}";
		std::string fourthOctet = "([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$";
		std::string regString = firstOctet + secondAndThirdOctets + fourthOctet;
		std::regex reg(regString);
		return std::regex_match(ipV4Address, reg);
	}

	bool Network::isSubnetMaskValid(std::string subnetMask)
	{
		/*
		Similar to the IPv4 but allows for the first octect to also be 255
		dotted decimal ipv4: 0.0.0.0 to 255.255.255.255
		1st to 3rd octect { 0-9 | 10 to 99 | 100 to 199 | 200 to 255 } .
		4th octect { 0-9 | 10-99 | 100 to 199 | 200 to 255 }
		*/
		std::string firstToThirdOctets = "(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}";
		std::string fourthOctet = "([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$";
		std::string regString = firstToThirdOctets + fourthOctet;
		std::regex reg(regString);
		return std::regex_match(subnetMask, reg);
	}

	bool Network::isDeviceNameValid(std::string deviceName)
	{
		/*
		The Device Name can be 1 to 15 Characters long and includes uppercase letters, lowercase letters, and numbers
		*/
		std::regex reg("[A-Za-z0-9]{1,15}");
		return std::regex_match(deviceName, reg);
	}


}

