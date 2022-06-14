#pragma once
#include <string>
#include <fstream>

#include "organization.h"

using CurrentClass = Organization;

class Manager
{
public:
	Manager();
	~Manager();

	CurrentClass** arr;
	int putIndex;

	bool isEmpty();

	void doAction();

	void add(CurrentClass* obj);
	bool remove(int index);

	bool outputListToFile(std::ofstream& filePtr);
	bool readListFromFile(std::ifstream& filePtr);

	void printShortList();
	void printList();
};

