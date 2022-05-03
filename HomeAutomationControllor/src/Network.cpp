/*****************************************************************//**
 * \file   Network.cpp
 * \brief  Implementation for the Network Configurator of the SmartNodes
 * 
 * \author Craig Smith
 * \date   May 2022
 *********************************************************************/
#include "Network.h"

namespace Net {
	/**
	 * Default constructor, initialize values with placeholders.
	 *
	 */
	Network::Network()
	{
		setDeviceName("AddDeviceName");
		setMacAddress("00:00:00:00:00:00");
		setIPAddress("000.000.000.000");
		setSubnetMask("000.000.000.000");
		setGatewayAddress("000.000.000.000");
	}

	/**
	 * Full constructor to set all the parameters for the Network Adapter of the SmartNode.
	 *
	 * \param ipAddress
	 * \param subnetMask
	 * \param gatewayAddress
	 * \param deviceName
	 * \param macAddress
	 */
	Network::Network(std::string deviceName, std::string macAddress, std::string ipAddress, std::string subnetMask, std::string gatewayAddress)
	{
		setDeviceName(deviceName);
		setMacAddress(macAddress);
		setIPAddress(ipAddress);
		setSubnetMask(subnetMask);
		setGatewayAddress(gatewayAddress);
	}

	/**
	 * Set a name for the device to be used in menu displays.
	 *
	 * \param deviceName
	 */
	void Network::setDeviceName(std::string deviceName)
	{
		_deviceName = deviceName;
	}

	/**
	 * Set an IP for the device to be used in communications and displays.
	 *
	 * \param ipAddress
	 */
	void Network::setIPAddress(std::string ipAddress)
	{
		_ipAddress = ipAddress;
	}

	/**
	 * Set a Subnet Mask for the device to be used in communications and displays.
	 *
	 * \param subnetMask
	 */
	void Network::setSubnetMask(std::string subnetMask)
	{
		_subnetMask = subnetMask;
	}

	/**
	 * Set a Gateway Address for the device to be used in communications and displays.
	 *
	 * \param gatewayAddress
	 */
	void Network::setGatewayAddress(std::string gatewayAddress)
	{
		_gatewayAddress = gatewayAddress;
	}

	/**
	 * Set a MAC Address for the device to be used in communications and displays.
	 *
	 * \param macAddress
	 */
	void Network::setMacAddress(std::string macAddress)
	{
		_macAddress = macAddress;
	}

	/**
	 * Get the Device Name to be used in communications and displays.
	 *
	 * \return Device Host/Device Name
	 */
	std::string Network::getDeviceName()
	{
		return _deviceName;
	}

	/**
	 * Get the IP Address to be used in communications and displays.
	 *
	 * \return Device IP Address
	 */
	std::string Network::getIPAddress()
	{
		return _ipAddress;
	}

	/**
	 * Get the Subnet Mask to be used in communications and displays.
	 *
	 * \return Device Subnet Mask
	 */
	std::string Network::getSubnetMask()
	{
		return _subnetMask;
	}

	/**
	 * Get the Gateway Address to be used in communications and displays.
	 *
	 * \return Device Gateway Address
	 */
	std::string Network::getGatewayAddress()
	{
		return _gatewayAddress;
	}

	/**
	 * Get the MAC to be used in communicationds and displays..
	 *
	 * \return Device MAC
	 */
	std::string Network::getMacAddress()
	{
		return _macAddress;
	}
} // End namespace Net




















