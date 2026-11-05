#include "terminal.h"

#ifdef _WIN32
#include <windows.h>
#endif

void initializeTerminal() {
#ifdef _WIN32
  HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

  if (output == INVALID_HANDLE_VALUE || output == nullptr) {
    return false;
  }

  DWORD mode = 0;

  if (!GetConsoleMode(output, &mode)) {
    return false;
  }

  if (!SetConsoleMode(output, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {
    return false;
  }
#endif

  return;
}