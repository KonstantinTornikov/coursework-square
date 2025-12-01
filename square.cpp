#include "square.h"
#include "points.h"
#include <cmath>

bool draw_square_enabled = false;

//рисует квадрат, используя точки A и B
void draw_square(Display* display, Window window, GC gc) {
    if (!points_exist) return;

    int dx = xB - xA;
    int dy = yB - yA;

    double length = sqrt(dx*dx + dy*dy); //вычисляем длину квадрата

    //вектор перпендикулярный AB
    int vx = -dy;
    int vy = dx;

    //нормализация вектора
    double norm = sqrt(vx*vx + vy*vy);
    vx = (int)((vx / norm) * length);
    vy = (int)((vy / norm) * length);

    int xC = xB + vx;
    int yC = yB + vy;
    int xD = xA + vx;
    int yD = yA + vy;

    //рисуем линии квадраат
    XDrawLine(display, window, gc, xA, yA, xB, yB);
    XDrawLine(display, window, gc, xB, yB, xC, yC);
    XDrawLine(display, window, gc, xC, yC, xD, yD);
    XDrawLine(display, window, gc, xD, yD, xA, yA);
}
