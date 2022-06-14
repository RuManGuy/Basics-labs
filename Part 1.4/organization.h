#include <iostream>
#include <fstream>
#include <string>

void animation();

class Organization {
public:
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

	std::string toString();

	void fromConsole();
};