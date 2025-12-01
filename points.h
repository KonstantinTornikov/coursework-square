#pragma once
#include <X11/Xlib.h>

//генерирует случайные координаты двух точек
void drop_points();

void draw_points(Display* display, Window window, GC gc);

//глобальные переменные для точек
extern bool points_exist; //true, если точки сгенерированы
extern int xA, yA, xB, yB; //координаты двух точек
