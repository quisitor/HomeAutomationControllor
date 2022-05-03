#include "CentralController.h"
#include <string>
#include <iostream>

namespace Controller {

	CentralController::CentralController()
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
		scMainMenu.append("           Central Smart-Home Controller Main Menu          \n");
		scMainMenu.append("------------------------------------------------------------\n");
		scMainMenu.append("  1. Status                                                 \n");
		scMainMenu.append("  2. Inventory                                              \n");
		scMainMenu.append("  3. Scheduler                                              \n");
		scMainMenu.append("  4. Controller                                             \n");
		scMainMenu.append("  5. Power Off                                              \n");
		scMainMenu.append("=============================================================\n");
		scMainMenu.append(">>>");              // Input Prompt
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
				std::cout << "Option 1. Status was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case INVENTORY:
				std::cin.clear();
				std::cin.ignore(255, '\n');
				launchInventoryMenu();
				break;
			case SCHEDULER:
				std::cout << "Option 3. Scheduler was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case CONTROLLER:
				std::cout << "Option 4. Controller was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
				break;
			case POWEROFF:
				std::cout << "Option 5. Power Off was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
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
		inventoryMenu.append("------------------------------------------------------------\n");
		inventoryMenu.append("  1. Add Device                                             \n");
		inventoryMenu.append("  2. Edit Device                                            \n");
		inventoryMenu.append("  3. Delete Device                                          \n");
		inventoryMenu.append("  4. Refresh Inventory Listing                              \n");
		inventoryMenu.append("  5. Back to Main Menu                                      \n");
		inventoryMenu.append("=============================================================\n");
		inventoryMenu.append(">>>");              // Input Prompt
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
				std::cout << "Option 1. Add Device was selected.";
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin.get();
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

} // End namespace Controller