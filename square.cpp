#include "square.h"
#include "points.h"
#include <cmath>
#include <X11/Xlib.h>

bool draw_square_enabled = false;

void draw_square(Display* display, Window window, GC gc) {
    if (!points_exist) return;

    // Сохраняем текущий цвет
    XGCValues old_gc_values;
    XGetGCValues(display, gc, GCForeground, &old_gc_values);
    unsigned long old_color = old_gc_values.foreground;

    // Устанавливаем красный цвет
    Colormap colormap = DefaultColormap(display, DefaultScreen(display));
    XColor red, exact;
    XAllocNamedColor(display, colormap, "red", &red, &exact);
    XSetForeground(display, gc, red.pixel);

    // Диагональные точки
    double x1 = xA, y1 = yA;
    double x3 = xB, y3 = yB;

    double cx = (x1 + x3) / 2.0;
    double cy = (y1 + y3) / 2.0;

    double hx = (x3 - x1) / 2.0;
    double hy = (y3 - y1) / 2.0;

    double px = -hy;
    double py = hx;

    double x2 = cx + px;
    double y2 = cy + py;
    double x4 = cx - px;
    double y4 = cy - py;

    // Заливка
    XPoint points[4];
    points[0] = { (short)x1, (short)y1 };
    points[1] = { (short)x2, (short)y2 };
    points[2] = { (short)x3, (short)y3 };
    points[3] = { (short)x4, (short)y4 };

    XFillPolygon(
        display,
        window,
        gc,
        points,
        4,
        Convex,
        CoordModeOrigin
    );

    // Контур
    XDrawLine(display, window, gc, x1, y1, x2, y2);
    XDrawLine(display, window, gc, x2, y2, x3, y3);
    XDrawLine(display, window, gc, x3, y3, x4, y4);
    XDrawLine(display, window, gc, x4, y4, x1, y1);

    // Восстанавливаем старый цвет
    XSetForeground(display, gc, old_color);
}
