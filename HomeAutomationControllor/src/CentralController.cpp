#include "CentralController.h"
#include "ValidationLibrary.h"
#include "HomeAutomationControllerTemplateLibrary.h"
#include "Thermostat.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>


namespace Controller {

	CentralController::CentralController()
	{

	}
	CentralController::~CentralController()
	{
		// enable once in-app inventory display is an option (need keep for print statements for testing)
		// clean up all the smartNode inventory objects dynamically created on heap
		// for (auto smartNode : _smartNodeInventory) delete smartNode;
		std::cout << "\n CentralController Destructor was called" << std::endl;
	}
	void CentralController::startController()
	{
		loadSmartNodeListFromInventoryFile();
		launchMainMenu();
	}

void CentralController::launchMainMenu()
{
	enum choices {STATUS = 1, INVENTORY, SCHEDULER, CONTROLLER, POWEROFF };
	int choice = 0;
	while (choice != POWEROFF) {
		system("cls");  // Clear the Console Screen
		
		std::string scMainMenu;   // Central Controller Main Menu String Builder
		scMainMenu.append("=============================================================\n");
		scMainMenu.append("           Central Smart-Home Controller Main Menu           \n");
		scMainMenu.append("-------------------------------------------------------------\n");
		scMainMenu.append("  1. Status                                                  \n");
		scMainMenu.append("  2. Inventory                                               \n");
		scMainMenu.append("  3. Scheduler                                               \n");
		scMainMenu.append("  4. Controller                                              \n");
		scMainMenu.append("  5. Power Off                                               \n");
		scMainMenu.append("=============================================================\n"); 
		scMainMenu.append(">>> ");              // Input Prompt
		std::cout << scMainMenu;

		if (!(std::cin >> choice)) {           // Clear if CIN is not an Integer
			std::cin.clear();
			std::cin.ignore(255, '\n');
			choice = 0;
		}
		else if (choice < 1 || choice > 5) {   // Clear if CIN is not in range [1,5]
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else                                   // Branch to Submenu
		{
			switch (choice) {
			case STATUS:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchStatusMenu();
				break;
			case INVENTORY:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchInventoryMenu();
				break;
			case SCHEDULER:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchSchedulerMenu();
				break;
			case CONTROLLER:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchControllerMenu();
				break;
			case POWEROFF:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchPowerOffMenu(choice);
				break;
			default:
				std::cout << "Default Option is Not Possible.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			}
		}
		
	}
}

void CentralController::launchStatusMenu()
{
	enum choices { REFRESH_STATUS = 1, BACK_TO_MAIN_MENU };
	int choice = 0;
	while (choice != BACK_TO_MAIN_MENU) {
		system("cls");  // Clear the Console Screen

		std::string statusMenu;   // Central Controller Status Menu String Builder
		statusMenu.append("=============================================================\n");
		statusMenu.append("               Central Smart-Home Status Menu                \n");
		statusMenu.append("-------------------------------------------------------------\n");
		statusMenu.append("  1. Refresh Status                                          \n");
		statusMenu.append("  2. Back to Main Menu                                       \n");
		statusMenu.append("=============================================================\n");
		statusMenu.append(">>> ");              // Input Prompt
		std::cout << statusMenu;

		if (!(std::cin >> choice)) {           // Clear if CIN is not an Integer
			std::cin.clear();
			std::cin.ignore(255, '\n');
			choice = 0;
		}
		else if (choice < 1 || choice > 2) {   // Clear if CIN is not in range [1,2]
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else                                   // Branch to Submenu
		{
			switch (choice) {
			case REFRESH_STATUS:
				std::cout << "Option 1. Refresh Status was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case BACK_TO_MAIN_MENU:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				break;
			default:
				std::cout << "Default Option is Not Possible.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			}
		}

	}
}

void CentralController::launchInventoryMenu()
{
	enum choices { ADD_DEVICE = 1, EDIT_DEVICE, DELETE_DEVICE, BACK_TO_MAIN_MENU };
	int choice = 0;
	while (choice != BACK_TO_MAIN_MENU) {
		system("cls");  // Clear the Console Screen
		
		std::cout << "===========================================================================================================\n";
		std::cout << "                              Central Smart - Home Controller Inventory Menu                               \n";
		std::cout << "-----------------------------------------------------------------------------------------------------------\n";
		printf("%-*s%-*s%-*s%-*s%-*s%-*s\n",16,"Type",18,"Name",20,"MAC Address",18,"IP Address",18,"Subnet Mask",18,"Gateway Address");
		for (auto smartNode : _smartNodeInventory)
		{
			//Issue with getting variable std::string to print solved via https://stackoverflow.com/questions/10865957/printf-with-stdstring
			printf("%-*s%-*s%-*s%-*s%-*s%-*s\n", 
				16, smartNode->getDeviceType().c_str(),
				18, smartNode->getNetworkConfigurationPtr()->getDeviceName().c_str(),
				20, smartNode->getNetworkConfigurationPtr()->getMacAddress().c_str(),
				18, smartNode->getNetworkConfigurationPtr()->getIPAddress().c_str(),
				18, smartNode->getNetworkConfigurationPtr()->getSubnetMask().c_str(),
				18, smartNode->getNetworkConfigurationPtr()->getGatewayAddress().c_str());
		}
		std::cout << "-----------------------------------------------------------------------------------------------------------\n";
		std::cout << "  1. Add Device                                                                                            \n";
		std::cout << "  2. Edit Device                                                                                           \n";
		std::cout << "  3. Delete Device                                                                                         \n";
		std::cout << "  4. Back to Main Menu                                                                                     \n";
		std::cout << "===========================================================================================================\n";
		std::cout << ">>> ";                   // Input Prompt
		
		if (!(std::cin >> choice)) {           // Clear if CIN is not an Integer
			std::cin.clear();
			std::cin.ignore(255, '\n');
			choice = 0;
		}
		else if (choice < 1 || choice > 4) {   // Clear if CIN is not in range [1,4]
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else                                   // Branch to Submenu
		{
			switch (choice) {
			case ADD_DEVICE:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchInventoryAddDeviceMenu();
				break;
			case EDIT_DEVICE:
				std::cout << "Option 2. Edit Device was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case DELETE_DEVICE:
				std::cout << "Option 3. Delete Device was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case BACK_TO_MAIN_MENU:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				break;
			default:
				std::cout << "Default Option is Not Possible.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			}
		}

	}
}

void CentralController::launchSchedulerMenu()
{
	enum choices { CREATE_SCHEDULE = 1, EDIT_SCHEDULE, DELETE_SCHEDULE, ACTIVATE_SCHEDULE, PAUSE_SCHEDULE, BACK_TO_MAIN_MENU };
	int choice = 0;
	while (choice != BACK_TO_MAIN_MENU) {
		system("cls");  // Clear the Console Screen

		std::string schedulerMenu;   // Central Controller Scheduler Menu String Builder
		schedulerMenu.append("=============================================================\n");
		schedulerMenu.append("         Central Smart-Home Controller Scheduler Menu        \n");
		schedulerMenu.append("-------------------------------------------------------------\n");
		schedulerMenu.append("  1. Create Schedule                                         \n");
		schedulerMenu.append("  2. Edit Schedule                                           \n");
		schedulerMenu.append("  3. Delete Schedule                                         \n");
		schedulerMenu.append("  4. Activate Schedule                                       \n");
		schedulerMenu.append("  5. Pause Schedule                                          \n");
		schedulerMenu.append("  6. Back to Main Menu                                       \n");
		schedulerMenu.append("=============================================================\n");
		schedulerMenu.append(">>> ");              // Input Prompt
		std::cout << schedulerMenu;

		if (!(std::cin >> choice)) {           // Clear if CIN is not an Integer
			std::cin.clear();
			std::cin.ignore(255, '\n');
			choice = 0;
		}
		else if (choice < 1 || choice > 6) {   // Clear if CIN is not in range [1,6]
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else                                   // Branch to Submenu
		{
			switch (choice) {
			case CREATE_SCHEDULE:
				std::cout << "Option 1. Create Schedule was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case EDIT_SCHEDULE:
				std::cout << "Option 2. Edit Schedule was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case DELETE_SCHEDULE:
				std::cout << "Option 3. Delete Schedule was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case ACTIVATE_SCHEDULE:
				std::cout << "Option 4. Activate Schedule was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case PAUSE_SCHEDULE:
				std::cout << "Option 5. Pause Schedule was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case BACK_TO_MAIN_MENU:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				break;
			default:
				std::cout << "Default Option is Not Possible.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			}
		}

	}
}

void CentralController::launchControllerMenu()
{
	enum choices { MODIFY_DEVICE_SETTING = 1, ENABLE_DEVICE, DISABLE_DEVICE, BACK_TO_MAIN_MENU };
	int choice = 0;
	while (choice != BACK_TO_MAIN_MENU) {
		system("cls");  // Clear the Console Screen

		std::string controllerMenu;   // Central Controller Controller Menu String Builder
		controllerMenu.append("=============================================================\n");
		controllerMenu.append("        Central Smart-Home Controller Controller Menu        \n");
		controllerMenu.append("-------------------------------------------------------------\n");
		controllerMenu.append("  1. Modify Device Setting                                   \n");
		controllerMenu.append("  2. Enable Device                                           \n");
		controllerMenu.append("  3. Disable Device                                          \n");
		controllerMenu.append("  4. Back to Main Menu                                       \n");
		controllerMenu.append("=============================================================\n");
		controllerMenu.append(">>> ");              // Input Prompt
		std::cout << controllerMenu;

		if (!(std::cin >> choice)) {           // Clear if CIN is not an Integer
			std::cin.clear();
			std::cin.ignore(255, '\n');
			choice = 0;
		}
		else if (choice < 1 || choice > 4) {   // Clear if CIN is not in range [1,4]
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else                                   // Branch to Submenu
		{
			switch (choice) {
			case MODIFY_DEVICE_SETTING:
				std::cout << "Option 1. Modify Device Setting was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case ENABLE_DEVICE:
				std::cout << "Option 2. Enable Device was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case DISABLE_DEVICE:
				std::cout << "Option 3. Disable Device was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case BACK_TO_MAIN_MENU:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				break;
			default:
				std::cout << "Default Option is Not Possible.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			}
		}

	}
}

void CentralController::launchPowerOffMenu(int &mainMenuChoice)
{
	enum choices { CONFIRM_CONTROLLER_SHUTDOWN = 1, BACK_TO_MAIN_MENU };
	int choice = 0;
	while (choice != BACK_TO_MAIN_MENU && choice != CONFIRM_CONTROLLER_SHUTDOWN) {
		system("cls");  // Clear the Console Screen

		std::string powerOffMenu;   // Central Controller Power Off Menu String Builder
		powerOffMenu.append("=============================================================\n");
		powerOffMenu.append("               Central Smart-Home Status Menu                \n");
		powerOffMenu.append("-------------------------------------------------------------\n");
		powerOffMenu.append("  1. Confirm Controller Shutdown                             \n");
		powerOffMenu.append("  2. Back to Main Menu                                       \n");
		powerOffMenu.append("=============================================================\n");
		powerOffMenu.append(">>> ");              // Input Prompt
		std::cout << powerOffMenu;

		if (!(std::cin >> choice)) {           // Clear if CIN is not an Integer
			std::cin.clear();
			std::cin.ignore(255, '\n');
			choice = 0;
		}
		else if (choice < 1 || choice > 2) {   // Clear if CIN is not in range [1,2]
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else                                   // Branch to Submenu
		{
			switch (choice) {
			case CONFIRM_CONTROLLER_SHUTDOWN:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				break;
			case BACK_TO_MAIN_MENU:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				mainMenuChoice = 0;
				break;
			default:
				std::cout << "Default Option is Not Possible.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			}
		}

	}
}

void CentralController::launchGetNetworkConfigDataMenu()
{
	enum choices { DEVICE_NAME = 1, DEVICE_MAC, DEVICE_IPV4_ADDRESS, DEVICE_SUBNET_MASK, DEVICE_GATEWAY_ADDRESS, SAVE, CANCEL };
	int choice = 0;
	while (choice != CANCEL) {
		system("cls");  // Clear the Console Screen

		std::string getNetworkConfigMenu;   // Central Controller Inventory-Add Menu String Builder
		getNetworkConfigMenu.append("=============================================================\n");
		getNetworkConfigMenu.append("                Inventory -  Add Device Menu                 \n");
		getNetworkConfigMenu.append("-------------------------------------------------------------\n");
		getNetworkConfigMenu.append("  1. Device Name (Max 15 Characters & Numbers)               \n");
		getNetworkConfigMenu.append("  2. Device MAC  (AA:BB:CC:DD:EE:FF)                         \n");
		getNetworkConfigMenu.append("  3. Device IPv4 Address (xxx.xxx.xxx.xxx)                   \n");
		getNetworkConfigMenu.append("  4. Device Subnet Mask  (xxx.xxx.xxx.xxx)                   \n");
		getNetworkConfigMenu.append("  5. Device Gateway Address (xxx.xxx.xxx.xxx)                \n");
		getNetworkConfigMenu.append("  6. Save Device                                             \n");
		getNetworkConfigMenu.append("  7. Cancel and Discard Input                                \n");
		getNetworkConfigMenu.append("=============================================================\n");
		getNetworkConfigMenu.append(">>> ");              // Input Prompt
		std::cout << getNetworkConfigMenu;

		if (!(std::cin >> choice)) {           // Clear if CIN is not an Integer
			std::cin.clear();
			std::cin.ignore(255, '\n');
			choice = 0;
		}
		else if (choice < 1 || choice > 7) {   // Clear if CIN is not in range [1,7]
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else                                   // Branch to Submenu
		{
			switch (choice) {
			case DEVICE_NAME:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchCreateDeviceNameMenu();
				break;
			case DEVICE_MAC:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchCreateDeviceMACMenu();
				break;
			case DEVICE_IPV4_ADDRESS:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchCreateDeviceIPAddressMenu();
				break;
			case DEVICE_SUBNET_MASK:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchCreateSubnetMaskMenu();
				break;
			case DEVICE_GATEWAY_ADDRESS:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchCreateGatewayAddressMenu();
				break;
			case SAVE:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchSaveNewDeviceMenu();
				break;
			case CANCEL:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				_tempNewSmartNodeContainer.clear();
				break;
			default:
				std::cout << "Default Option is Not Possible.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			}
		}

	}
}

void CentralController::launchCreateDeviceNameMenu()
{
	std::string choice = "";
	bool isDeviceNameValid = false;


	while (choice != "Q" && choice != "q") {
		system("cls");  // Clear the Console Screen

		std::string createDeviceNameMenu;   // Central Controller Create Device Name Menu String Builder
		createDeviceNameMenu.append("=============================================================\n");
		createDeviceNameMenu.append("         Central Smart-Home Create Device Name Menu          \n");
		createDeviceNameMenu.append("-------------------------------------------------------------\n");
		createDeviceNameMenu.append("  Device Name Constraints:                                   \n");
		createDeviceNameMenu.append("     -- Total Lenght = 15 Characters                         \n");
		createDeviceNameMenu.append("     -- Can contain Upper and Lowercase Letters              \n");
		createDeviceNameMenu.append("     -- Can contain Numbers                                  \n");
		createDeviceNameMenu.append("     -- Cannot be Q or q                                     \n");
		createDeviceNameMenu.append("  Examples                                                   \n");
		createDeviceNameMenu.append("     -- THERMOSMART01                                        \n");
		createDeviceNameMenu.append("     -- ThermoSmart                                          \n");
		createDeviceNameMenu.append("  Enter Value at the prompt >>>                              \n");
		createDeviceNameMenu.append("=============================================================\n");
		createDeviceNameMenu.append("(Q to Quit Input and Not Save) >>> ");              // Input Prompt
		std::cout << createDeviceNameMenu;

		std::getline(std::cin, choice);
		if (choice.length() < 1 || choice.length() > 15) {
			choice = "";
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else if (choice.length() == 1 && (choice.compare("Q") or choice.compare("q"))) {
			// Do nothing and allow to exit the loop back to the previous menu
		}
		else if (ValidationLibrary::Network::isDeviceNameValid(choice)) {
			
			_tempNewSmartNodeContainer["device_name"] = choice;    // Store user input value into map while obtaining rest of input
			_isTempNewSmartNodeContainerDeviceNameSet = true;      // Set device_name flag = true for save device option enablement
			choice = "Q";                                          // Return to previous menu afte setting the device name successfully

		}


	}
}

void CentralController::launchCreateDeviceMACMenu()
{
	std::string choice = "";


	while (choice != "Q" && choice != "q") {
		system("cls");  // Clear the Console Screen

		std::string createDeviceMACMenu;   // Central Controller Create Device MAC Menu String Builder
		createDeviceMACMenu.append("=============================================================\n");
		createDeviceMACMenu.append("         Central Smart-Home Create Device MAC Menu           \n");
		createDeviceMACMenu.append("-------------------------------------------------------------\n");
		createDeviceMACMenu.append("  Device MAC Constraints:                                    \n");
		createDeviceMACMenu.append("     -- Total Lenght = 17 Characters                         \n");
		createDeviceMACMenu.append("     -- Can contain Upper and Lowercase Letters A thru F     \n");
		createDeviceMACMenu.append("     -- Can contain Numbers 0 thru 9                         \n");
		createDeviceMACMenu.append("     -- Must use octet colon delimeters as shown in examples \n");
		createDeviceMACMenu.append("     -- Cannot be Q or q                                     \n");
		createDeviceMACMenu.append("  Examples                                                   \n");
		createDeviceMACMenu.append("     -- AA:BB:CC:DD:EE:FF                                    \n");
		createDeviceMACMenu.append("     -- aa:b1:c2:d3:ff:f1                                    \n");
		createDeviceMACMenu.append("  Enter Value at the prompt >>>                              \n");
		createDeviceMACMenu.append("=============================================================\n");
		createDeviceMACMenu.append("(Q to Quit Input and Not Save) >>> ");              // Input Prompt
		std::cout << createDeviceMACMenu;

		std::getline(std::cin, choice);
		if (choice.length() < 1 || choice.length() > 17) {
			choice = "";
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else if (choice.length() == 1 && (choice.compare("Q") or choice.compare("q"))) {
			// Do nothing and allow to exit the loop back to the previous menu
		}
		else if (ValidationLibrary::Network::isMACValid(choice)) {

			_tempNewSmartNodeContainer["device_mac"] = choice;    // Store user input value into map while obtaining rest of input
			_isTempNewSmartNodeContainerDeviceMACSet = true;      // Set device_name flag = true for save device option enablement
			choice = "Q";                                          // Return to previous menu afte setting the device name successfully

		}


	}
}

void CentralController::launchCreateDeviceIPAddressMenu()
{
	std::string choice = "";


	while (choice != "Q" && choice != "q") {
		system("cls");  // Clear the Console Screen

		std::string createDeviceIPv4AddressMenu;   // Central Controller Create Device IPv4 Menu String Builder
		createDeviceIPv4AddressMenu.append("=============================================================\n");
		createDeviceIPv4AddressMenu.append("     Central Smart-Home Create Device IPv4 Address Menu      \n");
		createDeviceIPv4AddressMenu.append("-------------------------------------------------------------\n");
		createDeviceIPv4AddressMenu.append("  Device IPv4 Address Constraints:                           \n");
		createDeviceIPv4AddressMenu.append("     -- Total Lenght = 15 Characters                         \n");
		createDeviceIPv4AddressMenu.append("     -- Can contain Numbers 0 thru 9                         \n");
		createDeviceIPv4AddressMenu.append("     -- Must use dotted-decimal notation                     \n");
		createDeviceIPv4AddressMenu.append("     -- Cannot be Q or q                                     \n");
		createDeviceIPv4AddressMenu.append("  Examples                                                   \n");
		createDeviceIPv4AddressMenu.append("     -- 192.168.234.123                                      \n");
		createDeviceIPv4AddressMenu.append("     -- 10.10.10.1                                           \n");
		createDeviceIPv4AddressMenu.append("  Enter Value at the prompt >>>                              \n");
		createDeviceIPv4AddressMenu.append("=============================================================\n");
		createDeviceIPv4AddressMenu.append("(Q to Quit Input and Not Save) >>> ");              // Input Prompt
		std::cout << createDeviceIPv4AddressMenu;

		std::getline(std::cin, choice);
		if (choice.length() < 1 || choice.length() > 15) {
			choice = "";
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else if (choice.length() == 1 && (choice.compare("Q") or choice.compare("q"))) {
			// Do nothing and allow to exit the loop back to the previous menu
		}
		else if (ValidationLibrary::Network::isIPv4AddressValid(choice)) {

			_tempNewSmartNodeContainer["ipv4_address"] = choice;    // Store user input value into map while obtaining rest of input
			_isTempNewSmartNodeContainerDeviceIPv4AddressSet = true;      // Set device_name flag = true for save device option enablement
			choice = "Q";                                          // Return to previous menu afte setting the device name successfully

		}


	}
}

void CentralController::launchCreateSubnetMaskMenu()
{
	std::string choice = "";


	while (choice != "Q" && choice != "q") {
		system("cls");  // Clear the Console Screen

		std::string createDeviceSubnetAddressMenu;   // Central Controller Create Device Subnet Mask Menu String Builder
		createDeviceSubnetAddressMenu.append("=============================================================\n");
		createDeviceSubnetAddressMenu.append("    Central Smart-Home Create Device Subnet Address Menu     \n");
		createDeviceSubnetAddressMenu.append("-------------------------------------------------------------\n");
		createDeviceSubnetAddressMenu.append("  Device Subnet Address Constraints:                         \n");
		createDeviceSubnetAddressMenu.append("     -- Total Lenght = 15 Characters                         \n");
		createDeviceSubnetAddressMenu.append("     -- Can contain Numbers 0 thru 9                         \n");
		createDeviceSubnetAddressMenu.append("     -- Must use dotted-decimal notation                     \n");
		createDeviceSubnetAddressMenu.append("     -- Cannot be Q or q                                     \n");
		createDeviceSubnetAddressMenu.append("  Examples                                                   \n");
		createDeviceSubnetAddressMenu.append("     -- 255.255.255.255                                      \n");
		createDeviceSubnetAddressMenu.append("     -- 255.255.255.0                                        \n");
		createDeviceSubnetAddressMenu.append("  Enter Value at the prompt >>>                              \n");
		createDeviceSubnetAddressMenu.append("=============================================================\n");
		createDeviceSubnetAddressMenu.append("(Q to Quit Input and Not Save) >>> ");              // Input Prompt
		std::cout << createDeviceSubnetAddressMenu;

		std::getline(std::cin, choice);
		if (choice.length() < 1 || choice.length() > 15) {
			choice = "";
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else if (choice.length() == 1 && (choice.compare("Q") or choice.compare("q"))) {
			// Do nothing and allow to exit the loop back to the previous menu
		}
		else if (ValidationLibrary::Network::isSubnetMaskValid(choice)) {

			_tempNewSmartNodeContainer["subnet_mask"] = choice;          // Store user input value into map while obtaining rest of input
			_isTempNewSmartNodeContainerDeviceSubnetMaskSet = true;      // Set device_name flag = true for save device option enablement
			choice = "Q";                                                // Return to previous menu afte setting the device name successfully

		}


	}
}

void CentralController::launchCreateGatewayAddressMenu()
{
	std::string choice = "";


	while (choice != "Q" && choice != "q") {
		system("cls");  // Clear the Console Screen

		std::string createDeviceGatewayAddressMenu;   // Central Controller Create Device Gateway Address Menu String Builder
		createDeviceGatewayAddressMenu.append("=============================================================\n");
		createDeviceGatewayAddressMenu.append("    Central Smart-Home Create Device Gateway Address Menu    \n");
		createDeviceGatewayAddressMenu.append("-------------------------------------------------------------\n");
		createDeviceGatewayAddressMenu.append("  Device Gateway Address Constraints:                        \n");
		createDeviceGatewayAddressMenu.append("     -- Total Lenght = 15 Characters                         \n");
		createDeviceGatewayAddressMenu.append("     -- Can contain Numbers 0 thru 9                         \n");
		createDeviceGatewayAddressMenu.append("     -- Must use dotted-decimal notation                     \n");
		createDeviceGatewayAddressMenu.append("     -- Cannot be Q or q                                     \n");
		createDeviceGatewayAddressMenu.append("  Examples                                                   \n");
		createDeviceGatewayAddressMenu.append("     -- 192.168.234.121                                      \n");
		createDeviceGatewayAddressMenu.append("     -- 10.10.101.1                                          \n");
		createDeviceGatewayAddressMenu.append("  Enter Value at the prompt >>>                              \n");
		createDeviceGatewayAddressMenu.append("=============================================================\n");
		createDeviceGatewayAddressMenu.append("(Q to Quit Input and Not Save) >>> ");              // Input Prompt
		std::cout << createDeviceGatewayAddressMenu;

		std::getline(std::cin, choice);
		if (choice.length() < 1 || choice.length() > 15) {
			choice = "";
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else if (choice.length() == 1 && (choice.compare("Q") or choice.compare("q"))) {
			// Do nothing and allow to exit the loop back to the previous menu
		}
		else if (ValidationLibrary::Network::isIPv4AddressValid(choice)) {

			_tempNewSmartNodeContainer["gateway_address"] = choice;          // Store user input value into map while obtaining rest of input
			_isTempNewSmartNodeContainerDeviceGatewayAddressSet = true;      // Set device_name flag = true for save device option enablement
			choice = "Q";                                                    // Return to previous menu afte setting the device name successfully

		}


	}
}

void CentralController::launchSaveNewDeviceMenu()
{
	std::string choice = "";


	while (choice != "Q" && choice != "q") {
		system("cls");  // Clear the Console Screen

		std::cout << "=============================================================" << std::endl;
		std::cout << "       Central Smart-Home Confirm Save New Device Menu       " << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		std::cout << "  Device Type............. " << _tempNewSmartNodeContainer["device_type"] << std::endl;
		std::cout << "  Device Name............. " << _tempNewSmartNodeContainer["device_name"] << std::endl;
		std::cout << "  Device MAC Address...... " << _tempNewSmartNodeContainer["device_mac"] << std::endl;
		std::cout << "  Device IP Address....... " << _tempNewSmartNodeContainer["ipv4_address"] << std::endl;
		std::cout << "  Device Subnet Address... " << _tempNewSmartNodeContainer["subnet_mask"] << std::endl;
		std::cout << "  Device Gateway Address.. " << _tempNewSmartNodeContainer["gateway_address"] << std::endl << std::endl;
		std::cout << "  Verify details and enter confirmation at the prompt >>> \n";
		std::cout << "=============================================================\n";
		std::cout << "(Q to Quit Input and Not Save, S to Save New Device) >>> ";    // Input Prompt

		std::getline(std::cin, choice);
		if (choice.length() < 1 || choice.length() > 1) {
			choice = "";
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else if (choice == "Q" || choice == "q" ) {
			// Do nothign and allow to exist the loop back to the previous menu
		}
		else if (choice == "s" || choice == "S") {
			enum device_type_choice {THERMOSTAT = 1, TELEVISON, VACUUM_BOT, ALARM, LIGHTING_ZONE };
			int whichDeviceType = 0;
			if (_tempNewSmartNodeContainer["device_type"] == "Thermostat") whichDeviceType = THERMOSTAT;
			if (_tempNewSmartNodeContainer["device_type"] == "Televsion") whichDeviceType = TELEVISON;
			if (_tempNewSmartNodeContainer["device_type"] == "Vacuum Bot") whichDeviceType = VACUUM_BOT;
			if (_tempNewSmartNodeContainer["device_type"] == "Alarm") whichDeviceType = ALARM;
			if (_tempNewSmartNodeContainer["device_type"] == "Lighting Zone") whichDeviceType = LIGHTING_ZONE;
			
			switch (whichDeviceType) {
			case THERMOSTAT:
			{
				Node::SmartNode* newThermostatDevice = new Node::Thermostat(
					_tempNewSmartNodeContainer["device_type"],
					_tempNewSmartNodeContainer["device_name"],
					_tempNewSmartNodeContainer["device_mac"],
					_tempNewSmartNodeContainer["ipv4_address"],
					_tempNewSmartNodeContainer["subnet_mask"],
					_tempNewSmartNodeContainer["gateway_address"]);
				_smartNodeInventory.push_back(newThermostatDevice);
				_tempNewSmartNodeContainer.clear();
				appendSmartNodeToInventoryFile(newThermostatDevice);
			}
				choice = "Q";     // Return to previous menu after succesful save
				break;
			case TELEVISON:
				break;
			case VACUUM_BOT:
				break;
			case ALARM:
				break;
			case LIGHTING_ZONE:
				break;
			default:
				break;
			}
			
		}


	}
}

void CentralController::resetTempNewSmartNodeContainerStateFlags()
{
	_isTempNewSmartNodeContainerDeviceNameSet = false;
	_isTempNewSmartNodeContainerDeviceMACSet = false;
	_isTempNewSmartNodeContainerDeviceIPv4AddressSet = false;
	_isTempNewSmartNodeContainerDeviceSubnetMaskSet = false;
	_isTempNewSmartNodeContainerDeviceGatewayAddressSet = false;
}

void CentralController::appendSmartNodeToInventoryFile(Node::SmartNode* newSmartNode)
{
	std::fstream inventoryFile(NODE_INVENTORY_FILE, std::ios::app);
	if (inventoryFile.is_open()) {

		inventoryFile << newSmartNode->getDeviceType() << ","
			<< newSmartNode->getNetworkConfigurationPtr()->getDeviceName() << ","
			<< newSmartNode->getNetworkConfigurationPtr()->getMacAddress() << ","
			<< newSmartNode->getNetworkConfigurationPtr()->getIPAddress() << ","
			<< newSmartNode->getNetworkConfigurationPtr()->getSubnetMask() << ","
			<< newSmartNode->getNetworkConfigurationPtr()->getGatewayAddress() << std::endl;
	}
	inventoryFile.close();

}

void CentralController::loadSmartNodeListFromInventoryFile()
{
	//Loading std::vector<Node::SmartNode*> _smartNodeInventory; from file
	//csv line format: deviceType,deviceName,deviceMAC,deviceIP,deviceSubnetMask,deviceGatewayAddress\n
	
	int whichDeviceType = 0;
	enum device_type_choice { THERMOSTAT = 1, TELEVISON, VACUUM_BOT, ALARM, LIGHTING_ZONE };
	std::string deviceType, deviceName, deviceMAC, deviceIP, deviceSubnetMask, deviceGatewayAddress;
	std::fstream inventoryFile(NODE_INVENTORY_FILE, std::ios::in);
	if (inventoryFile.is_open()) {
		while (!inventoryFile.eof()) {
			std::getline(inventoryFile, deviceType, ',');
			std::getline(inventoryFile, deviceName, ',');
			std::getline(inventoryFile, deviceMAC, ',');
			std::getline(inventoryFile, deviceIP, ',');
			std::getline(inventoryFile, deviceSubnetMask, ',');
			std::getline(inventoryFile, deviceGatewayAddress, '\n');

			if (deviceType == "Thermostat") whichDeviceType = THERMOSTAT;
			else if (deviceType == "Televsion") whichDeviceType = TELEVISON;
			else if (deviceType == "Vacuum Bot") whichDeviceType = VACUUM_BOT;
			else if (deviceType == "Alarm") whichDeviceType = ALARM;
			else if (deviceType == "Lighting Zone") whichDeviceType = LIGHTING_ZONE;

			if (!inventoryFile.good()) break;
			switch (whichDeviceType) {
			case THERMOSTAT:
				createNewSmartNode<Node::Thermostat>(
					_smartNodeInventory, 
					deviceType, 
					deviceName, 
					deviceMAC, 
					deviceIP, 
					deviceSubnetMask, 
					deviceGatewayAddress);
				break;
			case TELEVISON:
				break;
			case VACUUM_BOT:
				break;
			case ALARM:
				break;
			case LIGHTING_ZONE:
				break;
			default:
				break;
			}
		}
		inventoryFile.close();
	}


}

void CentralController::launchInventoryAddDeviceMenu()
{
	enum choices { THERMOSTAT = 1, TELEVISION, VACUUM_BOT, ALARM, LIGHTING_ZONE, BACK_TO_INVENTORY_MENU };
	int choice = 0;
	while (choice != BACK_TO_INVENTORY_MENU) {
		system("cls");  // Clear the Console Screen

		std::string inventoryAddMenu;   // Central Controller Inventory-Add Menu String Builder
		inventoryAddMenu.append("=============================================================\n");
		inventoryAddMenu.append("                Inventory -  Add Device Menu                 \n");
		inventoryAddMenu.append("-------------------------------------------------------------\n");
		inventoryAddMenu.append("  1. Thermostat                                              \n");
		inventoryAddMenu.append("  2. Television                                              \n");
		inventoryAddMenu.append("  3. Vacuum Bot                                              \n");
		inventoryAddMenu.append("  4. Alarm                                                   \n");
		inventoryAddMenu.append("  5. Lighting Zone                                           \n");
		inventoryAddMenu.append("  6. Back to Inventory Menu                                  \n");
		inventoryAddMenu.append("=============================================================\n");
		inventoryAddMenu.append(">>> ");              // Input Prompt
		std::cout << inventoryAddMenu;

		if (!(std::cin >> choice)) {           // Clear if CIN is not an Integer
			std::cin.clear();
			std::cin.ignore(255, '\n');
			choice = 0;
		}
		else if (choice < 1 || choice > 6) {   // Clear if CIN is not in range [1,6]
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
		else                                   // Branch to Submenu
		{
			switch (choice) {
			case THERMOSTAT:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				_tempNewSmartNodeContainer["device_type"] = "Thermostat";
				_isTempNewSmartNodeContainerDeviceTypeSet = true;
				launchGetNetworkConfigDataMenu();
				break;
			case TELEVISION:
				std::cout << "Option 2. Television was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case VACUUM_BOT:
				std::cout << "Option 3. Vacuum Bot was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case ALARM:
				std::cout << "Option 4. Alarm was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case LIGHTING_ZONE:
				std::cout << "Option 5. Lighting Zone was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case BACK_TO_INVENTORY_MENU:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				break;
			default:
				std::cout << "Default Option is Not Possible.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			}
		}

	}
}

/**
 * Friend function to help test user data collection.
 * 
 * \param centralController
 */
void print_tempNewSmartNodeContainer(CentralController centralController)
{
	std::string smartNode;
	std::cout << std::endl << std::endl;
	smartNode.append("=====================================\n");
	smartNode.append("            smartNodeData            \n");
	smartNode.append("-------------------------------------\n");
	std::cout << smartNode;
	for (auto kvPair : centralController._tempNewSmartNodeContainer) {
		std::cout << kvPair.first << " : " << kvPair.second << std::endl;
	}
	std::cout << "=====================================" << std::endl;
}

/**
 * Friend function to help test user data collection storage post device creation.
 * 
 * \param centralController
 */
void print_smartNodeInventory(CentralController centralController)
{
	/*
	Inventory Container: std::vector<Node::SmartNode*> _smartNodeInventory;
	*/

	std::string inventory;
	std::cout << std::endl << std::endl;
	inventory.append("=====================================\n");
	inventory.append("            smartNodeInventory       \n");
	inventory.append("-------------------------------------\n");
	std::cout << inventory;
	for (auto smartNode : centralController._smartNodeInventory) {
		std::cout << "Device Type: " << smartNode->getDeviceType() << std::endl;
		std::cout << "Device Name: " << smartNode->getNetworkConfigurationPtr()->getDeviceName() << std::endl;
		std::cout << "Device MAC Address: " << smartNode->getNetworkConfigurationPtr()->getMacAddress() << std::endl;
		std::cout << "Device IPv4 Address: " << smartNode->getNetworkConfigurationPtr()->getIPAddress() << std::endl;
		std::cout << "Device Subnet Mask:  " << smartNode->getNetworkConfigurationPtr()->getSubnetMask() << std::endl;
		std::cout << "Device Gateway Address: " << smartNode->getNetworkConfigurationPtr()->getGatewayAddress() << std::endl;
		std::cout << std::endl;
	}
	std::cout << "=====================================" << std::endl;
}

} // End namespace Controller