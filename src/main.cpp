#include <iostream>
#include <string>

#include "ArrowInput2.h"
#include "dynamicEmployee.h"
#include "setcolor.h"
#include "setposition.h"

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
  int selected = 0;
  const int totalOpt = 3;
  Employee employees[20];
  int empCount = 0;
  int dynamicCapacity = 20;
  int dynamicEmpCount = 0;
  DynamicEmployee* dynamicEmployees = new DynamicEmployee[dynamicCapacity];

  while (true) {
    displayMenu(selected, totalOpt);

    //====================Arrows========================
    char byte1 = getch_linux();

    if (byte1 == '\033') {
      char byte2 = getch_linux();
      char byte3 = getch_linux();

      handleArrow(byte3, selected, totalOpt);
      // ====================Keys=============================
    } else if (byte1 == 'a' || byte1 == 'A' || byte1 == 'h' || byte1 == 'H') {
      selected = 0;
    } else if (byte1 == 'b' || byte1 == 'B') {
      selected = 1;
    } else if (byte1 == 'c' || byte1 == 'C' || byte1 == 'f' || byte1 == 'F') {
      selected = 2;
      // ======================Enter===========================
    } else if (byte1 == '\n' || byte1 == '\r') {
      if (selected == 0) {
        cout << "\033[2J\033[H";

        cout << "Do you want to use Static or Dynamic Array? (S/D):  " << endl;

        char choice = getch_linux();

        if (choice == 's' || choice == 'S') {
          newEmp(employees, empCount);
        } else if (choice == 'd' || choice == 'D') {
          newEmpDynamic(dynamicEmployees, dynamicEmpCount, dynamicCapacity);
        }
      } else if (selected == 1) {
        cout << "\033[2J\033[H";
        cout << "\033[2J\033[H";

        cout << "Do you want to use Static or Dynamic Array? (S/D):  " << endl;

        char choice = getch_linux();

        if (choice == 's' || choice == 'S') {
          displayEmp(employees, empCount);
        } else if (choice == 'd' || choice == 'D') {
          displayEmp(dynamicEmployees, dynamicEmpCount);
        }
      } else if (selected == 2) {
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
    selected = 0;
  } else if (direction == 'F') {  // go to last item
    selected = totalOpt - 1;
  }
}

void displayMenu(int selected, int totalOpt) {
  const char* options[] = {"1. New Employee", "2. Display Employees",
                           "3. Exit"};

  for (int i = 0; i < totalOpt; i++) {
    setPosition(5, 8 + i);

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
  if (empCount >= 20) {
    cout << "\033[2J\033[H";
    setPosition(5, 5);
    setColor(COLOR_RED);
    cout << "Sorry! Employee array is full :(" << endl;
    char key;
    do {
      setColor(COLOR_YELLOW);
      setPosition(5, 7);
      cout << "Press ESC to return..." << endl;
    } while ((key = getch_linux()) != '\033');

    cout << "\033[2J\033[H";
    return;
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

// Function Templates: Instead of writing a function specifically for Employee,
// we write a function that accepts different employee types.

template <typename T>
void displayEmp(const T employees[], const int empCount) {
  cout << "\033[2J\033[H";

  setColor(COLOR_GREEN);
  setPosition(5, 3);
  cout << "EMPLOYEE LIST";

  if (empCount == 0) {
    setColor(COLOR_RED);
    setPosition(5, 5);
    cout << "No employees found! :(";
  } else {
    setColor(COLOR_WHITE);
    for (int i = 0; i < empCount; i++) {
      setPosition(5, 5 + i);
      cout << "#" << employees[i].id << " - Name: " << employees[i].name;
    }
    int totalRow = 5 + empCount + 2;

    setPosition(5, totalRow);
    setColor(COLOR_MAGENTA);
    cout << "Total Employees: " << empCount;
  }

  char key;

  do {
    setColor(COLOR_YELLOW);
    int totalRow = 5 + empCount + 3;
    setPosition(5, totalRow);
    cout << "Press ESC to return..." << endl;
  } while ((key = getch_linux()) != '\033');

  cout << "\033[2J\033[H";
}
