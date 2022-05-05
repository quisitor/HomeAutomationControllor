/*****************************************************************//**
 * \file   SmartNode.cpp
 * \brief  Implementation of the Abstrac SmartNode Class 
 * 
 * \author Craig Smith
 * \date   May 2022
 *********************************************************************/
#include "SmartNode.h"
#include <iostream>
namespace Node {

	SmartNode::SmartNode(std::string deviceType, std::string deviceName, std::string deviceMac, 
		std::string deviceIPv4, std::string deviceSubnetMask, std::string deviceGatewayAddress)
	{
		_netConfig = new Net::Network(deviceName, deviceMac, deviceIPv4, deviceSubnetMask, deviceGatewayAddress);
		_deviceType = deviceType;
		_smartNode = this;
		std::cout << "\n smartnode constructor was called" << std::endl;
	}

	SmartNode::~SmartNode()
	{
		std::cout << "\n SmartNode Destructor was called" << std::endl;
		delete _netConfig;
	}

	Net::Network* SmartNode::getNetworkConfigurationPtr()
	{
		return _netConfig;
	}

	void SmartNode::setDeviceType(std::string deviceType)
	{
		_deviceType = deviceType;
	}

	std::string SmartNode::getDeviceType()
	{
		return _deviceType;
	}

	SmartNode* SmartNode::getPtrToSmartNode()
	{
		return _smartNode;
	}


}
