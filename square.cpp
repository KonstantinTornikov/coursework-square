#include "square.h"
#include "points.h"
#include <cmath>

bool draw_square_enabled = false;

void draw_square(Display* display, Window window, GC gc) {
    if (!points_exist) return;

    // Диагональные точки квадрата
    double x1 = xA, y1 = yA;
    double x3 = xB, y3 = yB;

    // Центр диагонали
    double cx = (x1 + x3) / 2.0;
    double cy = (y1 + y3) / 2.0;

    // Вектор половины диагонали
    double hx = (x3 - x1) / 2.0;
    double hy = (y3 - y1) / 2.0;

    // Поворот вектора половины диагонали на 90°
    double px = -hy;
    double py = hx;

    // Вершины квадрата
    double x2 = cx + px;
    double y2 = cy + py;

    double x4 = cx - px;
    double y4 = cy - py;

    // Рисуем квадрат
    XDrawLine(display, window, gc, x1, y1, x2, y2);
    XDrawLine(display, window, gc, x2, y2, x3, y3);
    XDrawLine(display, window, gc, x3, y3, x4, y4);
    XDrawLine(display, window, gc, x4, y4, x1, y1);
}

