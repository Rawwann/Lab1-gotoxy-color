#include <iostream>
#include <string>

#include "ArrowInput2.h"
#include "dynamicEmployee.h"
#include "setcolor.h"
#include "setposition.h"

#define MAX_EMP 20
#define TOTAL_OPT 3
#define NEW 0
#define DISPLAY 1
#define EXIT 2
#define X 5
#define Y_TITLE 3
#define Y_ID 5
#define Y_SORRY 5
#define Y_NAME 6
#define Y_MSG 7
#define Y_ESC 11
#define ESC '\033'
#define CLR "\033[2J\033[H"

using namespace std;

class Employee {
 public:
  int id;
  string name;
};

void handleArrow(char direction, int& selected, const int totalOpt);
void displayMenu(int selected, int totalOpt);
void newEmp(Employee employees[], int& empCount);
template <typename T>
void displayEmp(const T employees[], const int empCount);

int main() {
  int selected = NEW;
  const int totalOpt = TOTAL_OPT;
  Employee employees[MAX_EMP];
  int empCount = 0;
  int dynamicCapacity = MAX_EMP;
  int dynamicEmpCount = 0;
  DynamicEmployee* dynamicEmployees = new DynamicEmployee[dynamicCapacity];

  while (true) {
    displayMenu(selected, totalOpt);

    //====================Arrows========================
    char byte1 = getch_linux();

    if (byte1 == ESC) {
      char byte2 = getch_linux();
      char byte3 = getch_linux();

      handleArrow(byte3, selected, totalOpt);
      // ====================Keys=============================
    } else if (byte1 == 'a' || byte1 == 'A' || byte1 == 'h' || byte1 == 'H') {
      selected = NEW;
    } else if (byte1 == 'b' || byte1 == 'B') {
      selected = DISPLAY;
    } else if (byte1 == 'c' || byte1 == 'C' || byte1 == 'f' || byte1 == 'F') {
      selected = EXIT;
      // ======================Enter===========================
    } else if (byte1 == '\n' || byte1 == '\r') {
      if (selected == NEW) {
        cout << CLR;

        cout << "Do you want to use Static or Dynamic Array? (S/D):  " << endl;

        char choice = getch_linux();

        if (choice == 's' || choice == 'S') {
          newEmp(employees, empCount);
        } else if (choice == 'd' || choice == 'D') {
          newEmpDynamic(dynamicEmployees, dynamicEmpCount, dynamicCapacity);
        }
      } else if (selected == DISPLAY) {
        cout << CLR;

        cout << "Do you want to use Static or Dynamic Array? (S/D):  " << endl;

        char choice = getch_linux();

        if (choice == 's' || choice == 'S') {
          displayEmp(employees, empCount);
        } else if (choice == 'd' || choice == 'D') {
          displayEmp(dynamicEmployees, dynamicEmpCount);
        }
      } else if (selected == EXIT) {
        break;
      }
    }
  }
  delete[] dynamicEmployees;
  return 0;
}

void handleArrow(char direction, int& selected, const int totalOpt) {
  if (direction == 'A') {
    selected = (selected - 1 + totalOpt) % totalOpt;  // up
  } else if (direction == 'B') {
    selected = (selected + 1) % totalOpt;  // down
  } else if (direction == 'H') {           // go to first item
    selected = NEW;
  } else if (direction == 'F') {  // go to last item
    selected = EXIT;
  }
}

void displayMenu(int selected, int totalOpt) {
  const char* options[] = {"1. New Employee", "2. Display Employees",
                           "3. Exit"};

  for (int i = 0; i < totalOpt; i++) {
    setPosition(X, 8 + i);

    if (i == selected) {
      setColor(COLOR_GREEN);
      cout << "-> ";

    } else {
      setColor(COLOR_WHITE);
      cout << "   ";
    }

    cout << options[i];
  }

  setColor(COLOR_RESET);
  cout << endl;
}

void newEmp(Employee employees[], int& empCount) {
  if (empCount >= MAX_EMP) {
    cout << CLR;
    setPosition(X, Y_SORRY);
    setColor(COLOR_RED);
    cout << "Sorry! Employee array is full :(" << endl;
    char key;
    do {
      setColor(COLOR_YELLOW);
      setPosition(X, Y_ESC);
      cout << "Press ESC to return..." << endl;
    } while ((key = getch_linux()) != ESC);

    cout << CLR;
    return;
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

// Function Templates: Instead of writing a function specifically for Employee,
// we write a function that accepts different employee types.

template <typename T>
void displayEmp(const T employees[], const int empCount) {
  cout << CLR;

  setColor(COLOR_GREEN);
  setPosition(X, Y_TITLE);
  cout << "EMPLOYEE LIST";

  if (empCount == 0) {
    setColor(COLOR_RED);
    setPosition(X, Y_SORRY);
    cout << "No employees found! :(";
  } else {
    setColor(COLOR_WHITE);
    for (int i = 0; i < empCount; i++) {
      setPosition(X, 5 + i);
      cout << "#" << employees[i].id << " - Name: " << employees[i].name;
    }
    int totalRow = 5 + empCount + 2;

    setPosition(X, totalRow);
    setColor(COLOR_MAGENTA);
    cout << "Total Employees: " << empCount;
  }

  char key;

  do {
    setColor(COLOR_YELLOW);
    int totalRow = 5 + empCount + 3;
    setPosition(X, totalRow);
    cout << "Press ESC to return..." << endl;
  } while ((key = getch_linux()) != ESC);

  cout << CLR;
}
