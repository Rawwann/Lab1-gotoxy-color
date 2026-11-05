#include <cstdio>
#include <iostream>

#include "printtext.h"
#include "setcolor.h"
#include "setposition.h"

using namespace std;

int main() {
  setColor(COLOR_RED);
  setPosition(5, 8);
  printText("1. Main Menu\n");

  setColor(COLOR_GREEN);
  setPosition(5, 9);
  printText("2. New Screen\n");

  setColor(COLOR_BLUE);
  setPosition(5, 10);
  printText("3. Display Screen\n");

  setColor(COLOR_WHITE);
  setPosition(5, 11);
  printText("4. Exit");

  setColor(COLOR_RESET);
  return 0;
}