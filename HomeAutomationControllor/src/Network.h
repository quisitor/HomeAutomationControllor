#pragma once
/*****************************************************************//**
 * \file   Network.h
 * \brief Class declaration to configure the network parameters for a SmartNode  
 * 
 * 
 * \author Craig Smith
 * \date   May 2022
 *********************************************************************/

#include<string>
namespace Net {
	class Network
	{
	public:
		Network();
		Network(std::string deviceName, std::string macAddress, std::string ipAddress, std::string subnetMask, std::string gatewayAddress);
		void setDeviceName(std::string deviceName);
		void setIPAddress(std::string ipAddress);
		void setSubnetMask(std::string subnetMask);
		void setGatewayAddress(std::string gatewayAddress);
		void setMacAddress(std::string macAddress);
		std::string getDeviceName();
		std::string getIPAddress();
		std::string getSubnetMask();
		std::string getGatewayAddress();
		std::string getMacAddress();

	private:
		std::string _deviceName;
		std::string _ipAddress;
		std::string _subnetMask;
		std::string _gatewayAddress;
		std::string _macAddress;
	};
} // End namespace Net

