#pragma once

#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <conio.h>

#include "manager.h"
#include "resetInputBuffer.h"
#include "getFileName.h"

using namespace std;

using ActionsMap = map<char, string>;

ActionsMap actions = {
    { '1', "fill from console" },
    { '2', "output to console" },
    { '3', "write to file" },
    { '4', "read from file" },
    { '5', "for dismiss person" },
    { '6', "for increase persons" },
    { '7', "for change salary" },
    { 'c', "cancel" }
};

string getActionDescription(char action) {
    map<char, string>::iterator it = actions.find(action);

    if (it != actions.end()) {
        return it->second;
    }
    else {
        return "";
    }
}

Manager::Manager() {
	this->arr = new CurrentClass*[200];
	this->putIndex = 0;
}

Manager::~Manager() {
	delete[] this->arr;
}

bool Manager::isEmpty() {
	return putIndex == 0;
}

void Manager::doAction() {
	if (putIndex == 0) {
		cout << "No objects" << endl;
		return;
	}

	cout << "Select object" << endl;
	printShortList();

	cout << "enter index of object: ";
	int selectedIndex;
	cin >> selectedIndex;
	cout << endl;

	if (arr[selectedIndex] == nullptr) {
		cout << "No object with index" << selectedIndex << endl;

		return;
	}

    cout << "Select action" << endl;

    for (ActionsMap::iterator it = actions.begin(); it != actions.end(); it++) {
        cout << it->first << " - " << it->second << endl;
    }

	CurrentClass* objPtr = arr[selectedIndex];

    char action = _getch();

	string actionDescription = getActionDescription(action);

	if (actionDescription == "") {
		cout << "No action `" << action << "`" << endl;

		return;
	}

	cout << "Selected action: " << actionDescription << endl;

    switch (action) {
		case '1':
			objPtr->fillFromConsole();
			break;
		case '2': {
			cout << objPtr->toString() << endl;

			break;
		}
		case '3': {
			string fileName = getFileName();

			if (fileName.length() < 3) {
				cout << "Invalid file name" << endl;

				return;
			}

			ofstream file;

			file.open(fileName);

			bool result = objPtr->outputToFile(file);

			if (result) {
				cout << "Success" << endl;

				file.close();
			}
			else {
				cout << "Failed to save" << endl;
			}

			break;
		}
		case '4': {
			string fileName = getFileName();

			if (fileName.length() < 3) {
				cout << "Invalid file name" << endl;

				return;
			}

			ifstream file;

			file.open(fileName);

			bool result = objPtr->readFromFile(file);

			if (result) {
				cout << "Success" << endl;

				file.close();
			}
			else {
				cout << "Failed to read file " << fileName << endl;
			}

			break;
		}
		case '5': {
			int count;

			cout << "Enter count to dismiss: ";
			cin >> count;
			resetInputBuffer();

			bool result = objPtr->dismissPerson(count);

			if (result) {
				cout << "New count persons :" << objPtr->countPerson << endl;
			}
			else {
				cout << "Not enough persons!" << endl;
			}

			break;
		}
		case '6': {
			int count;

			cout << "Enter count to increase: ";
			cin >> count;
			resetInputBuffer();

			bool result = objPtr->increasePerson(count);

			if (result) {
				cout << "New count persons :" << objPtr->countPerson << endl;
			}
			else {
				cout << "Not enough workplaces!" << endl;
			}

			break;
		}
		case '7': {
			int newSalary;

			cout << "enter new salary: " << endl;
			cin >> newSalary;
			resetInputBuffer();

			objPtr->changeSalary(newSalary);
			break;
		}
    }
}

void Manager::add(CurrentClass* objPtr) {
	arr[putIndex++] = objPtr;
}

bool Manager::remove(int index) {
	if (arr[index] == nullptr) {
		return false;
	}

	delete arr[index];
	arr[index] = nullptr;

    // Создаём новый массив, заполняем его без пропусков
    // Заменяем старый массив на него и меняем putIndex
    CurrentClass** newArr = new CurrentClass*[200];
    int newI = 0;

    for (int i = 0; i < putIndex; i++) {
        if (arr[i] != nullptr) {
            newArr[newI++] = arr[i];
        }
    }

    delete[] arr;
    arr = newArr;
    putIndex = newI;

	return true;
}

bool Manager::outputListToFile(ofstream& fileRef) {
    if (!fileRef.is_open()) {
        return false;
    }

    for (int i = 0; i < putIndex; i++) {
        CurrentClass* objPtr = arr[i];

        objPtr->outputToFile(fileRef);
        
		if (i != putIndex - 1) {
			fileRef << endl;
		}
    }

    return true;
}

bool Manager::readListFromFile(ifstream& fileRef) {
    if (!fileRef.is_open()) {
        return false;
    }

    while (!fileRef.eof()) {
        CurrentClass* objPtr = new CurrentClass();

        objPtr->readFromFile(fileRef);
        fileRef.ignore(numeric_limits<streamsize>::max(), '\n');

        add(objPtr);
    }

    return true;
}

void Manager::printList() {
    for (int i = 0; i < putIndex; i++) {
        cout << "Object #" << i << endl;
        cout << arr[i]->toString() << endl;
    }
}

void Manager::printShortList() {
    for (int i = 0; i < putIndex; i++) {
        cout << "Object #" << i << " - " << arr[i]->name << endl;
    }
}