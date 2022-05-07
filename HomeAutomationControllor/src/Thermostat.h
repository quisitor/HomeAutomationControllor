/*****************************************************************//**
 * \file   Thermostat.h
 * \brief  Object declaration for the Thermostat SmartNode Type
 * 
 * \author Craig Smith
 * \date   May 2022
 *********************************************************************/
#pragma once
#include "SmartNode.h"
#include <string>
#include <iostream>

namespace Node {
	class Thermostat : public Node::SmartNode
	{
	public:
		Thermostat(std::string deviceType, std::string deviceName, std::string deviceMac, std::string deviceIPv4, std::string deviceSubnetMask,
			std::string deviceGatewayAddress) : SmartNode(deviceType, deviceName, deviceMac, deviceIPv4, deviceSubnetMask, deviceGatewayAddress) 
		{
			//std::cout << "\nThermostat constructor was called" << std::endl;
		}

		virtual ~Thermostat() { /*std::cout << "\nThermost Destructor was Called..." << std::endl;*/ }
	};
} // End namespace Thermostat

