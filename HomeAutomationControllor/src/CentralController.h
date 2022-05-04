/*****************************************************************//**
 * \file   CentralController.h
 * \brief  Declaration for the main central controller for interfacing
 *         with the other systems inputs and outputs
 * 
 * \author Craig Smith
 * \date   May 2022
 *********************************************************************/
#pragma once
#include<stdlib.h>
#include"SmartNode.h"
#include<map>
#include<vector>

namespace Controller {

class CentralController
{
public:
	CentralController();
	~CentralController();
	void startController();
	friend void print_tempNewSmartNodeContainer(CentralController centralController);

private:
	// Top-Level Menus
	void launchMainMenu();
	void launchStatusMenu();
	void launchInventoryMenu();
	void launchSchedulerMenu();
	void launchControllerMenu();
	void launchPowerOffMenu(int &mainMenuChoice);

	// Sub-Level Menus
	void launchInventoryAddDeviceMenu();
	void launchGetNetworkConfigDataMenu();
	void launchCreateDeviceNameMenu();
	void launchCreateDeviceMACMenu();
	void launchCreateDeviceIPAddressMenu();
	void launchCreateSubnetMaskMenu();
	void launchCreateGatewayAddressMenu();

	// Containers
	std::vector<Node::SmartNode*> _smartNodeInventory;
	std::map<std::string, std::string> _tempNewSmartNodeContainer;

	// State Flags
	bool _isTempNewSmartNodeContainerDeviceNameSet = false;
	bool _isTempNewSmartNodeContainerDeviceMAC = false;
	bool _isTempNewSmartNodeContainerDeviceIPv4AddressSet = false;
	bool _isTempNewSmartNodeContainerDeviceSubnetMaskSet = false;
	bool _isTempNewSmartNodeContainerDeviceGatewayAddressSet = false;

	// Internal Helper Functions
	void resetTempNewSmartNodeContainerStateFlags();



};

} // End namespace Controller
