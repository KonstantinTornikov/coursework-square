#include "points.h"
#include <X11/Xlib.h>
#include <cstdlib>

bool points_exist = false;
int xA, yA, xB, yB;

int win_width = 600;
int win_height = 400;

void drop_points() {
    xA = rand() % (win_width - 40) + 20;
    yA = rand() % (win_height - 80) + 80;

    xB = rand() % (win_width - 40) + 20;
    yB = rand() % (win_height - 80) + 80;

    points_exist = true;
}

void draw_points(Display* display, Window window, GC gc) {
    if (!points_exist) return;

    XFillArc(display, window, gc, xA - 3, yA - 3, 6, 6, 0, 360 * 64);
    XFillArc(display, window, gc, xB - 3, yB - 3, 6, 6, 0, 360 * 64);
}

