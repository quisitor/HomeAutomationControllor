/*****************************************************************//**
 * \file   Main.cpp
 * \brief  File to start the Home Automation Controller
 * 
 * \author Craig Smith
 * \date   May 2022
 *********************************************************************/
#include "CentralController.h"

int main()
{
	Controller::CentralController homeAutomationController;
	homeAutomationController.startController();
}
