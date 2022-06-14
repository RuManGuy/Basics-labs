#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Organization {
public:
	Organization();
	Organization(
		std::string name,
		int salary,
		int countPerson,
		int workplaces,
		int totalSalary
	);

	std::map<char, std::string> actions;

	std::string name;
	int salary;
	int countPerson;
	int workplaces;
	int totalSalary;

	void updateTotalSalary();

	bool dismissPerson(int count);
	void changeSalary(int newSalary);
	bool increasePerson(int count);

	bool outputToFile(std::ofstream& filePtr);
	bool readFromFile(std::ifstream& filePtr);

	void fillFromConsole();

	std::string toString();
};

