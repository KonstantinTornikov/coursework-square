#include "points.h"
#include <X11/Xlib.h>
#include <cstdlib>

bool points_exist = false;
int xA, yA, xB, yB;

int win_width = 600;
int win_height = 400;

//генерация двух случайных точек
void drop_points() {
    xA = rand() % (win_width - 40) + 20;  //первая x
    yA = rand() % (win_height - 80) + 80; //первая y

    int horiz_shift = 50 + rand() % 200;  //смещаем вторую точку
    xB = xA + horiz_shift;
    yB = yA;

    points_exist = true;
}

//рисуем точки в окне
void draw_points(Display* display, Window window, GC gc) {
    if (!points_exist) return;

    //рисуем окружности по 3 пикселя (наши точки)
    XFillArc(display, window, gc, xA - 3, yA - 3, 6, 6, 0, 360 * 64);
    XFillArc(display, window, gc, xB - 3, yB - 3, 6, 6, 0, 360 * 64);
}
