/*****************************************************************//**
 * \file   SmartNode.h
 * \brief  Declares an Abstract Class to be used to create SmartNodes 
 * of differrent types.
 * 
 * \author Craig Smith
 * \date   May 2022
 *********************************************************************/
#pragma once
#include "Network.h"
#include <string>

namespace Node {


	class SmartNode
	{
	public:
		SmartNode(std::string deviceType, std::string deviceName, std::string deviceMac, std::string deviceIPv4, std::string deviceSubnetMask,
			std::string deviceGatewayAddress);
		virtual ~SmartNode();
		Net::Network* getNetworkConfigurationPtr();
		void setDeviceType(std::string deviceType);
		std::string getDeviceType();
		SmartNode* getPtrToSmartNode();

	private:
		Net::Network* _netConfig;
		std::string  _deviceType;
		SmartNode* _smartNode;
	};

} // End namespace Node