#include "dynamicEmployee.h"

#include <iostream>
#include <string>

#include "ArrowInput2.h"
#include "setcolor.h"
#include "setposition.h"

#define MULT 2
#define X 5
#define Y_TITLE 3
#define Y_ID 5
#define Y_NAME 6
#define Y_MSG 7
#define Y_ESC 11
#define ESC '\033'
#define CLR "\033[2J\033[H"

using namespace std;

// double arr
void resizeArray(DynamicEmployee*& employees, int& capacity,
                 const int empCount) {
  int newCapacity = capacity * MULT;

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

  cout << CLR;

  setColor(COLOR_GREEN);
  setPosition(X, Y_TITLE);
  cout << "NEW EMPLOYEE";

  setColor(COLOR_WHITE);
  setPosition(X, Y_ID);
  cout << "Enter employee id: ";
  cin >> employees[empCount].id;

  setColor(COLOR_WHITE);
  setPosition(X, Y_NAME);
  cout << "Enter employee name: ";
  cin >> employees[empCount].name;

  setColor(COLOR_GREEN);
  setPosition(X, Y_MSG);
  cout << "Employee Added! :)" << endl;

  empCount++;

  char key;

  do {
    setColor(COLOR_YELLOW);
    setPosition(X, Y_ESC);
    cout << "Press ESC to return..." << endl;
  } while ((key = getch_linux()) != ESC);

  cout << CLR;
}
