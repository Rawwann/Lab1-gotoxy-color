#ifndef SETCOLOR_H
#define SETCOLOR_H

typedef enum {
  COLOR_BLACK = 30,
  COLOR_RED = 31,
  COLOR_GREEN = 32,
  COLOR_YELLOW = 33,
  COLOR_BLUE = 34,
  COLOR_MAGENTA = 35,
  COLOR_CYAN = 36,
  COLOR_WHITE = 37,
  COLOR_RESET = 39  // resets the foreground color.
} Color;

// \033[0m resets all text formatting attributes, including foreground and
// background colors and styles.

void setColor(Color c);

#endif