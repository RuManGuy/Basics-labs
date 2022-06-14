#include <cstring>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>
#include <limits>

using namespace std;

#include "organization.h"

//#typedef CHECK_FILE(file) if (!file.is_open())\
//return "0";

using namespace std;

// #pragma once
//void resetInputBuffer() {
//	cin.clear();
//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
//}

void Organization::updateTotalSalary() {
    totalSalary = countPerson * salary;
} 

bool Organization::dismissPerson(int count) {
    if (count > countPerson) {
        return false;
    }

    countPerson -= count;
    updateTotalSalary();

    return true;
}

bool Organization::increasePerson(int count) {
    if (count + countPerson > workplaces) {
        return false;
    }

    countPerson += count;
    updateTotalSalary();

    return true;
}

void Organization::changeSalary(int newSalary) {
    salary = newSalary;
    updateTotalSalary();
}

bool Organization::outputToFile(ofstream& fileRef) {
    if (!fileRef.is_open()) {
        return false;
    }

    fileRef << name << salary << countPerson << workplaces << totalSalary;

    return true;
}

bool Organization::readFromFile(ifstream& fileRef) {
    if (!fileRef.is_open()) {
        return false;
    }

    fileRef >> name >> salary >> countPerson >> workplaces;

    updateTotalSalary();

    return true;
}

string Organization::toString() {
    string str;

    str += "name: " + name + "\n";
    str += "salary: " +  to_string(salary) + "\n";
    str += "count person: " +  to_string(countPerson) + "\n";
    str += "workplaces: " +  to_string(workplaces) + "\n";
    str += "total salary: " +  to_string(totalSalary) + "\n";

    return str;
}


void Organization::fromConsole() {
    cout << "enter name organization: ";
    cin >> name;
    //resetInputBuffer();

    cout << "enter salary: ";
    cin >> salary;
    //resetInputBuffer();

    cout << "enter count person: ";
    cin >> countPerson;
    //resetInputBuffer();

    cout << "enter workplaces: ";
    cin >> workplaces;
    //resetInputBuffer();

    updateTotalSalary();
};
