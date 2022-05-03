#pragma once
/*****************************************************************//**
 * \file   ValidationLibrary.h
 * \brief  Library of static functions to facilitate user input validation
 * 
 * \author Craig Smith
 * \date   May 2022
 *********************************************************************/
#include<string>

namespace ValidationLibrary {

	class Network 
	{
	public:
		/**
		 * Method that validates a standard 48Bit MAC in HexHex: Format
		 * 
		 * \param mac ex. AA:BB:CC:DD:EE:FF
		 * \return true upon valid MAC format
		 */
		static bool isMACValid(std::string mac);

		/**
		 * Method that validates for standard IPv4 dotted decimal notation.
		 * The method only gaurantees the dotted decimal format.
		 * The method can be used to validate host and gateway addresses.
		 * 
		 * \param ipV4Address ex. 10.0.0.0
		 * \return 
		 */
		static bool isIPv4AddressValid(std::string ipV4Address);
		
		/**
		 * Method that validates for standard IPv4 subnet mask dotted decimal notation.
		 * The method only gaurantees the dotted decimal format
		 * 
		 * \param subnetMask
		 * \return 
		 */
		static bool isSubnetMaskValid(std::string subnetMask);

		/**
		 * Method that that validates the lenght and format of the device name.
		 * The device name can be 15 characters long and include letters and numbers only.
		 * \param deviceName ex. "alarm01"
		 * \return 
		 */
		static bool isDeviceNameValid(std::string deviceName);


	};

}
