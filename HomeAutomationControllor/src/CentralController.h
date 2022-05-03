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

namespace Controller {

class CentralController
{
public:
	CentralController();
	~CentralController();
	void startController();
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

};

} // End namespace Controller
