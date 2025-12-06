#pragma once
#include <X11/Xlib.h>
#include "points.h"

void draw_square(Display* display, Window window, GC gc);
extern bool draw_square_enabled;
