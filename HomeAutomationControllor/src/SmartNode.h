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
		
		enum class Message
		{
			ENABLE_NODE = 0, DISABLE_NODE, HEALTH_STATUS
		};
		
		SmartNode(std::string deviceType, std::string deviceName, std::string deviceMac, std::string deviceIPv4, std::string deviceSubnetMask,
			std::string deviceGatewayAddress);
		virtual ~SmartNode();
		
		Net::Network* getNetworkConfigurationPtr();
		SmartNode* getPtrToSmartNode();
		void setDeviceType(std::string deviceType);
		std::string getDeviceType();
		
		// Health Status Monitor
		virtual void pollHealthStatus();
		void setHealthStatus(std::string currentStatus);

		// Receive messages / commands from teh CentralController
		virtual bool messageHandler(Message message);
		
		// Methods called by the messageHandler
		virtual bool enableNode();
		virtual bool disableNode();
		virtual std::string getHealthStatus();

	private:
		Net::Network* _netConfig;
		std::string  _deviceType;
		SmartNode* _smartNode;
		bool _isNodeEnabled;
		std::string _healthStatus = "Ok";

	};

} // End namespace Node