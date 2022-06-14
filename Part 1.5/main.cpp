#include <iostream>
#include <string>
#include <conio.h>

#include "organization.h"
#include "manager.h"
#include "getFileName.h"
#include "resetInputBuffer.h"

using namespace std;

int main(int argc, char** argv) {
	Manager m;

	while (true) {
		cout << endl << endl;
		cout << "1 - do action with object" << endl;
		cout << "2 - output list to console" << endl;
		cout << "3 - write list to file" << endl;
		cout << "4 - read list from file" << endl;
		cout << "5 - add object" << endl;
		cout << "6 - remove object" << endl;
		cout << "e - for exit" << endl << endl;

		char action = _getch();

		switch (action) {
		case '1': // do action with object
			m.doAction();
			break;
		case '2': { // print list to console
			if (m.isEmpty()) {
				cout << "List empty" << endl;

				break;
			}

			m.printList();

			break;
		}
		case '3': { // write list to file
			if (m.isEmpty()) {
				cout << "No objects to save" << endl;

				break;
			}

			string fileName = getFileName();

			ofstream file;

			file.open(fileName);

			bool result = m.outputListToFile(file);

			if (result) {
				cout << "Success" << endl;

				file.close();
			}
			else {
				cout << "Unable to ouput to file" << endl;
			}

			break;
		}
		case '4': { // read list from file
			string fileName = getFileName();

			ifstream file;

			file.open(fileName);

			bool result = m.readListFromFile(file);

			if (result) {
				cout << "Success" << endl;

				file.close();
			}
			else {
				cout << "Unable to read from file `" << fileName << "`" << endl;
			}

			break;
		}
		case '5': { // add object
			char way;

			cout << "Choose way to add:" << endl;
			cout << "0 - fill from console" << endl;
			cout << "1 - read from file" << endl;

			way = _getch();

			if (way != '0' && way != '1') {
				cout << "invalid way" << endl;
				break;
			}

			CurrentClass* newObj = new CurrentClass();

			if (way == '0') {
				newObj->fillFromConsole();
			}
			else if (way == '1') {
				string fileName = getFileName();

				ifstream file;

				file.open(fileName);

				bool result = newObj->readFromFile(file);

				if (result) {
					cout << "Success" << endl;

					file.close();
				}
				else {
					cout << "Unable to read from file `" << fileName << "`" << endl;
				}
			}

			m.add(newObj);
			
			break;
		}
		case '6': {
			if (m.isEmpty()) {
				cout << "No objects to remove" << endl;

				break;
			}

			cout << "Enter index of object to remove:" << endl;
			m.printShortList();

			int selectedIndex;
			cin >> selectedIndex;
			resetInputBuffer();

			bool result = m.remove(selectedIndex);

			if (result) {
				cout << "Object with index " << selectedIndex << " removed" << endl;
			}
			else {
				cout << "Unable to remove object with index " << selectedIndex << endl;
			}

			break;
		}
		case 'e': // exit
			return 0;
		};
	}
	return 0;
}