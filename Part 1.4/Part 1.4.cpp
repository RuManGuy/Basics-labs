#include <iostream>
#include <string>
#include <conio.h>

#include "organization.h"

using namespace std;

int main(int argc, char** argv) {
	Organization s;

	string fileName = "data1.txt";

	while (true) {
		cout << endl << "1 - fill from console" << endl;
		cout << "2 - output to console" << endl;
		cout << "3 - write to file" << endl;
		cout << "4 - read from file" << endl;
		cout << "5 - for dismiss person" << endl;
		cout << "6 - for increase persons" << endl;
		cout << "7 - for change salary" << endl;
		cout << "e - for exit" << endl << endl;

		char action = _getch();
		
		switch (action) {
			case '1': 
				s.fromConsole();
				break;
			case '2': {
				cout << s.toString() << endl;
				
				break;
			}
			case '3': {
				ofstream file;

				file.open(fileName);

				bool result = s.outputToFile(file);

				if (result) {
					cout << "Success" << endl;

					file.close();
				} else {
					cout << "File is not opened or doesn't exists" << endl;
				}

				break;
			}
			case '4':{
				ifstream file;

				file.open(fileName);

				bool result = s.readFromFile(file);

				if (result) {
					cout << "Success" << endl;

					file.close();
				} else {
					cout << "File is not opened or doesn't exists" << endl;
				}

				break;
			}
			case '5': {
				int count;

				cout << "Enter count to dismiss: ";
				cin >> count;

				bool result = s.dismissPerson(count);

				if (result) {
					cout << "New count persons :" << s.countPerson << endl;
				} else {
					cout << "Not enough persons!" << endl;
				} 

				break;
			} 
			case '6': {
				int count;

				cout << "Enter count to increase: ";
				cin >> count;

				bool result = s.increasePerson(count);

				if (result) {
					cout << "New count persons :" << s.countPerson << endl;
				} else {
					cout << "Not enough workplaces!" << endl;
				}

				break;
			}
				
			case '7': {
				int newSalary;

				cout << "enter new salary: " << endl;
				cin >> newSalary;
				// resetInputBuffer

				s.changeSalary(newSalary);
				break;
			}
			case 'e': return 0;
				break;
		};
	}
	return 0;
}