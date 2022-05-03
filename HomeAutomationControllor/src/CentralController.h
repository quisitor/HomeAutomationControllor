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
	void startController();
private:
	void launchMainMenu();
	void launchInventoryMenu();

};

} // End namespace Controller
