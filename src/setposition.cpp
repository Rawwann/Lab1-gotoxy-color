#include <cstdio>
#include <iostream>

using namespace std;

#ifdef _WIN32
#include <io.h>
#include <windows.h>
#else
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE
#endif

#endif

void setPosition(int x, int y) {
  printf("\033[%d;%dH", y, x);  /// 033 ASCII ESC
}

// y -> row, x -> column
