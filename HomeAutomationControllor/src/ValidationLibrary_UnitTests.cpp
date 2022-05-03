/*****************************************************************//**
 * \file   ValidationLibrary_UnitTests.cpp
 * \brief  Implementation file to test the input validators
 * 
 * \author Craig Smith
 * \date   May 2022
 *********************************************************************/
#include "ValidationLibrary.h"
#include "CentralController.h"
#include <string>
#include <iostream>

using namespace std;
using namespace ValidationLibrary;
using namespace Controller;

void testMACAddressValidation();
void testIPV4AddressValidation();
void testIPV4SubnetMaskValidation();
void testDeviceNameValidation();
void testMainMenuDisplay();


int main() {
	
	// Run Tests
	testMACAddressValidation();
	std::cin.get();
	testIPV4AddressValidation();
	std::cin.get();
	testIPV4SubnetMaskValidation();
	std::cin.get();
	testDeviceNameValidation();
	std::cin.get();
	testMainMenuDisplay();

	return 0;

}
	void testMACAddressValidation()
	{
		/* Test the MAC Address Input Validator*/
		string goodMACS[]
		{
			"AA:BB:CC:DD:EE:FF",
			"00:11:22:33:44:55",
			"66:77:88:99:01:12",
			"A1:B2:C3:D4:E5:F6",
			"A7:B8:C9:0A:1B:2C",
			"3D:4E:5F:FF:FF:FF",
			"aa:bb:cc:dd:ee:ff"
		};
		string badMACS[]
		{
			"GG:aa:bb:cc:dd:ee",
			"gg:aa:bb:cc:dd:ee",
			"aa:bb:cc:dd:ee:gg",
			"aa:bb:cc:dd:ee:GG",
			"a1:b1:c1:d1:G2:ab",
			"11:aa:bb:cc:dd:ee:ff",
			"aa:123:bb:cc:dd:ee",
			"a:bb:cc:dd:ee:ff",
			"aa:bb:cc:dd:ee:ff:",
			"abcd.efff.abcc",
			"ab.cd.ef.ff.ff.ff",
			"aa:bb:cc:dd:ee:f",
			"aa:bb:dd:dd:ee:ffaa",
			"aa:bb:cc:dd:ee:123",
			"123:bb:cc:dd:ee:ff",
			"00:11:22:33:44",
			"00:11:22:33",
			"00:11:22",
			"00:11",
			"00",
			"0",
			""
		};

		std::cout << "MAC Address Validation Unit Tests\n===================================================\n\n";
		std::cout << "These are the True cases\n-----------------------" << endl;
		for (string mac : goodMACS) {
			std::cout << boolalpha << " Is the MAC " << mac << " valid: " << Network::isMACValid(mac) << endl;
		}

		std::cout << "These are the False cases\n-----------------------" << endl;
		for (string mac : badMACS) {
			std::cout << boolalpha << " Is the MAC " << mac << " valid: " << Network::isMACValid(mac) << endl;
		}
	}

	void testIPV4AddressValidation()
	{
		/* Test the IPv4 Address Validator */
		string goodIPv4Addresses[]
		{
			"0.0.0.0",
			"126.255.255.255",
			"0.0.0.255",
			"0.0.255.0",
			"0.255.0.0",
			"254.0.0.0",
			"128.0.0.0",
			"191.255.255.255",
			"192.0.0.0",
			"223.255.255.255",
			"224.0.0.0",
			"239.255.255.255",
			"240.0.0.0",
			"254.255.255.255"
		};

		string badIPv4Addresses[]
		{
			"a.0.0.0",
			"0.a.0.0",
			"0.0.a.0",
			"0.0.0.a",
			"300.255.255.255",
			"192.168.1.2.3",
			"23:23.23.233",
			"255.10.10.10",
			"256.13.32.3",
			"10.256.0.0",
			"10.10.256.0",
			"10.10.10.256",
			"10.10.10.2333",
			"123.23.3.",
			"22.22.2",
			"120.23.",
			"199.1",
			"10.",
			"10",
			"1",
			"0",
			""
		};

		std::cout << std::endl << std::endl << std::endl << std::endl;
		std::cout << "IPv4 Address Validation Unit Tests\n===================================================\n\n";
		std::cout << "These are the True cases\n-----------------------" << endl;
		for (string ip : goodIPv4Addresses) {
			std::cout << boolalpha << " Is the IPv4 Address " << ip << " valid: " << Network::isIPv4AddressValid(ip) << endl;
		}

		std::cout << "These are the False cases\n-----------------------" << endl;
		for (string ip : badIPv4Addresses) {
			std::cout << boolalpha << " Is the IPv4 Address " << ip << " valid: " << Network::isIPv4AddressValid(ip) << endl;
		}
	}

	void testIPV4SubnetMaskValidation()
	{
		/* Test the IPv4 Subnet Mask Address Validator */
		string goodIPv4SubnetMaskAddresses[]
		{
			"0.0.0.0",
			"126.255.255.255",
			"0.0.0.255",
			"0.0.255.0",
			"0.255.0.0",
			"254.0.0.0",
			"128.0.0.0",
			"191.255.255.255",
			"192.0.0.0",
			"223.255.255.255",
			"224.0.0.0",
			"239.255.255.255",
			"240.0.0.0",
			"255.255.255.255"
		};

		string badIPv4SubnetMaskAddresses[]
		{
			"a.0.0.0",
			"0.a.0.0",
			"0.0.a.0",
			"0.0.0.a",
			"300.255.255.255"
			"192.168.1.2.3",
			"23:23.23.233",
			"256.13.32.3",
			"10.256.0.0",
			"10.10.256.0",
			"10.10.10.256",
			"10.10.10.2333"
		};

		std::cout << std::endl << std::endl << std::endl << std::endl;
		std::cout << "IPv4 Subnet Mask Address Validation Unit Tests\n===================================================\n\n";
		std::cout << "These are the True cases\n-----------------------" << endl;
		for (string sm : goodIPv4SubnetMaskAddresses) {
			std::cout << boolalpha << " Is the IPv4 Subnet Mask " << sm << " valid: " << Network::isSubnetMaskValid(sm) << endl;
		}

		std::cout << "These are the False cases\n-----------------------" << endl;
		for (string sm : badIPv4SubnetMaskAddresses) {
			std::cout << boolalpha << " Is the IPv4 Subnet Mask " << sm << " valid: " << Network::isSubnetMaskValid(sm) << endl;
		}
	}


	void testDeviceNameValidation()
	{
		/* Test the Device Name Validator */
		string goodDeviceNames[]
		{
			"ABCDEFGHIJKLMNO",
			"PQRSTUVWXYZabcd",
			"efghijklmnopqrs",
			"tuvwxyz01234567",
			"89AAVVBBUuOk23m",
			"0",
			"01",
			"abc",
			"abcd"
		};

		string badDeviceNames[]
		{
			"ABCDEFGHIJKLMNOP",
			"",
			"_",
			"abcd_",
			"abc&",
			"#fd",
			"avdl-sjk1",
			"))",
			"%",
			"&",
			"@",
			"$",
			"^",
			"~",
			"(",
			"+",
			"=",
			".",
			",",
			"?",
			"/",
			"\\"
		};

		std::cout << std::endl << std::endl << std::endl << std::endl;
		std::cout << "Device Name Validation Unit Tests\n===================================================\n\n";
		std::cout << "These are the True cases\n-----------------------" << endl;
		for (string dn : goodDeviceNames) {
			std::cout << boolalpha << " Is the Device name " << dn << " valid: " << Network::isDeviceNameValid(dn) << endl;
		}

		std::cout << "These are the False cases\n-----------------------" << endl;
		for (string dn : badDeviceNames) {
			std::cout << boolalpha << " Is the Device name " << dn << " valid: " << Network::isDeviceNameValid(dn) << endl;
		}
	}

	void testMainMenuDisplay() {
		CentralController testController;
		testController.startController();
	}

