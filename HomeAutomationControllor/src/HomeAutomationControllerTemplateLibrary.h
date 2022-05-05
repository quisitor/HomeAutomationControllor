/*****************************************************************//**
 * \file   HomeAutomationControllerTemplateLibrary.h
 * \brief  Template Library of Helper Functions and/or Classes
 * 
 * \author Craig Smith
 * \date   May 2022
 *********************************************************************/
#pragma once
#include "SmartNode.h"
#include "Thermostat.h"
#include <vector>
#include <iostream>
template<typename SmartNodeType>
void createNewSmartNode(
	std::vector<Node::SmartNode*> & smartNodeInventory,
	std::string deviceType,
	std::string deviceName,
	std::string deviceMAC,
	std::string deviceIP,
	std::string deviceSubnetMask,
	std::string deviceGatewayAddress) 
{
	Node::SmartNode* newSmartDevice = new SmartNodeType(
	deviceType,
	deviceName,
	deviceMAC,
	deviceIP,
	deviceSubnetMask,
	deviceGatewayAddress);
	smartNodeInventory.push_back(newSmartDevice);
}

