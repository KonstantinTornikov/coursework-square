#pragma once
#include <X11/Xlib.h>

void drop_points();
void draw_points(Display* display, Window window, GC gc);

extern bool points_exist;
extern int xA, yA, xB, yB;
