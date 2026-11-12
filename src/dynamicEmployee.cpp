#include "dynamicEmployee.h"

#include <iostream>
#include <string>

#include "ArrowInput2.h"
#include "setcolor.h"
#include "setposition.h"

using namespace std;

// double arr
void resizeArray(DynamicEmployee*& employees, int& capacity,
                 const int empCount) {
  int newCapacity = capacity * 2;

  DynamicEmployee* newEmployees = new DynamicEmployee[newCapacity];

  // copy then delete and update
  for (int i = 0; i < empCount; i++) {
    newEmployees[i] = employees[i];
  }

  delete[] employees;

  employees = newEmployees;
  capacity = newCapacity;
}

void newEmpDynamic(DynamicEmployee*& employees, int& empCount, int& capacity) {
  if (empCount == capacity) {
    resizeArray(employees, capacity, empCount);
  }

  cout << "\033[2J\033[H";

  setColor(COLOR_GREEN);
  setPosition(5, 3);
  cout << "NEW EMPLOYEE";

  setColor(COLOR_WHITE);
  setPosition(5, 5);
  cout << "Enter employee id: ";
  cin >> employees[empCount].id;

  setColor(COLOR_WHITE);
  setPosition(5, 6);
  cout << "Enter employee name: ";
  cin >> employees[empCount].name;

  setColor(COLOR_GREEN);
  setPosition(5, 7);
  cout << "Employee Added! :)" << endl;

  empCount++;

  char key;

  do {
    setColor(COLOR_YELLOW);
    setPosition(5, 11);
    cout << "Press ESC to return..." << endl;
  } while ((key = getch_linux()) != '\033');

  cout << "\033[2J\033[H";
}
