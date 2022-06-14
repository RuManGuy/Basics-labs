#include <iostream>
#include<limits>

using namespace std;

void resetInputBuffer() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}