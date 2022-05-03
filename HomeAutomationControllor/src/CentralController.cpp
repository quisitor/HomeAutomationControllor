#include "CentralController.h"
#include <string>
#include <iostream>

namespace Controller {

	CentralController::CentralController()
	{

	}
	CentralController::~CentralController()
	{
	}
	void CentralController::startController()
{
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
	enum choices { ADD_DEVICE = 1, EDIT_DEVICE, DELETE_DEVICE, REFRESH_INVENTORY_LISTING, BACK_TO_MAIN_MENU };
	int choice = 0;
	while (choice != BACK_TO_MAIN_MENU) {
		system("cls");  // Clear the Console Screen

		std::string inventoryMenu;   // Central Controller Inventory Menu String Builder
		inventoryMenu.append("=============================================================\n");
		inventoryMenu.append("         Central Smart-Home Controller Inventory Menu        \n");
		inventoryMenu.append("-------------------------------------------------------------\n");
		inventoryMenu.append("  1. Add Device                                              \n");
		inventoryMenu.append("  2. Edit Device                                             \n");
		inventoryMenu.append("  3. Delete Device                                           \n");
		inventoryMenu.append("  4. Refresh Inventory Listing                               \n");
		inventoryMenu.append("  5. Back to Main Menu                                       \n");
		inventoryMenu.append("=============================================================\n");
		inventoryMenu.append(">>> ");              // Input Prompt
		std::cout << inventoryMenu;

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
			case REFRESH_INVENTORY_LISTING:
				std::cout << "Option 4. Refresh Inventory Listing was selected.";
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
				std::cout << "Option 1. Thermostat was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
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
				std::cout << "Option 5. Ligting Zone was selected.";
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

} // End namespace Controller