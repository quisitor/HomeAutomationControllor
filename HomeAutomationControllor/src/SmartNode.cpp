/*****************************************************************//**
 * \file   SmartNode.cpp
 * \brief  Implementation of the Abstrac SmartNode Class 
 * 
 * \author Craig Smith
 * \date   May 2022
 *********************************************************************/
#include "SmartNode.h"

namespace Node {

	SmartNode::SmartNode()
	{

	}

	SmartNode::SmartNode(std::string deviceName, std::string deviceMac, std::string deviceIPv4, std::string deviceSubnetMask, std::string deviceGatewayAddress)
	{
		_netConfig = new Net::Network(deviceName, deviceMac, deviceIPv4, deviceSubnetMask, deviceGatewayAddress);
	}

	SmartNode::~SmartNode()
	{
		delete _netConfig;
	}

	Net::Network* SmartNode::getNetworkConfiguration()
	{
		return _netConfig;
	}


}
