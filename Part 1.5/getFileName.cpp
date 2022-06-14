#pragma once

#include <string>
#include <iostream>

#include "getFileName.h"
#include "resetInputBuffer.h"

using namespace std;

string getFileName() {
	string fileName;

	cout << "Enter file name (with extension): ";
	cin >> fileName;
	resetInputBuffer();

	return fileName;
}
