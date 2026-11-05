
#include "setcolor.h"

#include <cstdio>

void setColor(Color c) { printf("\033[%dm", c); }

// m -> Text Formatting