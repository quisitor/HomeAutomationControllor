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
		_isNodeEnabled = false;
		//std::cout << "\n smartnode constructor was called" << std::endl;
	}

	SmartNode::~SmartNode()
	{
		//std::cout << "\n SmartNode Destructor was called" << std::endl;
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

	void SmartNode::pollHealthStatus()
	{
		// Do some real world stuff, check device registers on a set chrono timer then update Health status
		// with messages specific to this SmartNode type
		setHealthStatus("All Good");
	}

	void SmartNode::setHealthStatus(std::string currentStatus)
	{
		_healthStatus = currentStatus;
	}

	bool SmartNode::messageHandler(Message message)
	{
		switch (message) {
		case Message::ENABLE_NODE:
			enableNode();
			break;
		case Message::DISABLE_NODE:
			disableNode();
			break;
		case Message::HEALTH_STATUS:
			getHealthStatus();
			break;
		default:
			return false;
		}
		return true;  // Messaged processed successfully
	}

	bool SmartNode::enableNode()
	{
		// Do some real world stuff to enable the node then set flag to true
		_isNodeEnabled = true;
		return true;
	}

	bool SmartNode::disableNode()
	{
		// Do some real world stuff to disable the node then set flag to false
		_isNodeEnabled = false;
		return false;
	}

	std::string SmartNode::getHealthStatus()
	{
		return _healthStatus;
	}

	SmartNode* SmartNode::getPtrToSmartNode()
	{
		return _smartNode;
	}

}
