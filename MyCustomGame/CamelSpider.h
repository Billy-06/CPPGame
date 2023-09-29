#pragma once
#include "Character.h"

/**
 * @file CamelSpider.h
 * @author Billy Ndegwah Micah
 *
 * Description: This is the definition of the CamelSpider class. The CamelSpider class is a derived class of the Character class.
 *
 * Properties:
 * -----------
 * > venomReserve {int}: This is the venom reserve of the CamelSpider.
 * > webStrength {int}: This is the web strength of the CamelSpider.
 * > webReserve {int}: This is the web reserve of the CamelSpider.
 *
 * Methods:
 * --------
 * > Default Constructor
 * > Constructor (overload)
 * > Destructor
 * > Copy Constructor
 * > Getters and setters for the properties
 * > InflictHarm() {void} - This method makes the CamelSpider inflict harm using its venom.
 * > SpinWeb() {void} - This method makes the CamelSpider spin a web.
 * > Crawl(direction {string}) {void} - This method makes the CamelSpider crawl in a given direction.
 */
class CamelSpider : public Character
{
private:
	int venomReserve_;
	int webStrength_;
	int webReserve_;

public:
	/**
	 * @brief This is the default constructor for the CamelSpider class.
	*/
	CamelSpider();

	/**
	 * @brief This is the overloaded constructor for the CamelSpider class.
	 * @param name - the name of the CamelSpider
	 * @param health - the maximum health of the CamelSpider
	 * @param friendly - the friendly status of the CamelSpider
	 * @param venomReserve - the venom reserve of the CamelSpider
	 * @param webStrength - the web strength of the CamelSpider
	 * @param webReserve - the web reserve of the CamelSpider
	*/
	CamelSpider(std::string& name, float health, bool friendly, int venomReserve, int webStrength, int webReserve);

	/**
	 * @brief This is the copy constructor for the CamelSpider class.
	 * @param camelSpider - reference to the CamelSpider object to be copied
	*/
	CamelSpider(const CamelSpider& camelSpider);

	/**
	 * @brief This is the destructor for the CamelSpider class.
	*/
	~CamelSpider() override;

	/**
	 * @brief Getter for the venomReserve property.
	 * @return an integer value representing the venom reserve of the CamelSpider.
	*/
	int GetVenomReserve() const;

	/**
	 * @brief Setter for the venomReserve property.
	 * @param venomReserve - an integer value representing the venom reserve of the CamelSpider.
	*/
	void SetVenomReserve(int venomReserve);

	/**
	 * @brief Getter for the webStrength property.
	 * @return an integer value representing the web strength of the CamelSpider.
	*/
	int GetWebStrength() const;

	/**
	 * @brief Setter for the webStrength property.
	 * @param webStrength - an integer value representing the web strength of the CamelSpider.
	*/
	void SetWebStrength(int webStrength);

	/**
	 * @brief Getter for the webReserve property.
	 * @return an integer value representing the web reserve of the CamelSpider.
	*/
	int GetWebReserve() const;

	/**
	 * @brief Setter for the webReserve property.
	 * @param webReserve - an integer value representing the web reserve of the CamelSpider.
	*/
	void SetWebReserve(int webReserve);

	/**
	 * @brief This method allows the CamelSpider to inflict harm using its venom.
	*/
	void InflictHarm();

	/**
	 * @brief This method allows the CamelSpider to spin a web.
	*/
	void SpinWeb();

	/**
	 * @brief This method allows the CamelSpider to crawl in a given direction.
	 * @param direction - the desired direction of crawling.
	*/
	void Crawl(std::string& direction) const;

};