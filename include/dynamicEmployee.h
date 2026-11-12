
#ifndef DYNAMIC_EMPLOYEE_H
#define DYNAMIC_EMPLOYEE_H

#include <string>
using namespace std;

struct DynamicEmployee {
  int id;
  string name;
};

void resizeArray(DynamicEmployee*& employees, int& capacity,
                 const int empCount);

void newEmpDynamic(DynamicEmployee*& employees, int& empCount, int& capacity);

#endif
