#pragma once
#include <X11/Xlib.h> 
#include "points.h"

//функция что рисует квадрат
void draw_square(Display* display, Window window, GC gc);
extern bool draw_square_enabled;
