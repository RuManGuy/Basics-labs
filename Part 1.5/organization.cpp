#pragma once

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "organization.h"
#include "resetInputBuffer.h"

Organization::Organization() : Organization("", 0, 0, 0, 0) {};
Organization::Organization(
    std::string name,
    int salary,
    int countPerson,
    int workplaces,
    int totalSalary
) {
    this->name = name;
    this->salary = salary;
    this->countPerson = countPerson;
    this->workplaces = workplaces;
    this->totalSalary = workplaces;
    this->actions = actions;
}

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

    fileRef << name << " " << salary << " " << countPerson << " " << workplaces;

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

void Organization::fillFromConsole() {
    cout << "enter name organization: ";
    cin >> name;
    resetInputBuffer();

    cout << "enter salary: ";
    cin >> salary;
    resetInputBuffer();

    cout << "enter count person: ";
    cin >> countPerson;
    resetInputBuffer();

    cout << "enter workplaces: ";
    cin >> workplaces;
    resetInputBuffer();

    updateTotalSalary();
};


string Organization::toString() {
    string str;

    str += "name: " + name + "\n";
    str += "salary: " + to_string(salary) + "\n";
    str += "count person: " + to_string(countPerson) + "\n";
    str += "workplaces: " + to_string(workplaces) + "\n";
    str += "total salary: " + to_string(totalSalary) + "\n";

    return str;
}
