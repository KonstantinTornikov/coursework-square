#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xlocale.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

#include "gui.h"
#include "points.h"
#include "square.h"

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "");
    XSetLocaleModifiers("");

    Display* display = XOpenDisplay(NULL);
    if (!display) {
        std::cerr << "Не удалось открыть X11 display\n";
        return 1;
    }

    int screen = DefaultScreen(display);
    int win_width = 600;
    int win_height = 400;

    Window window = XCreateSimpleWindow(
        display, RootWindow(display, screen),
        100, 100, win_width, win_height,
        1, BlackPixel(display, screen), WhitePixel(display, screen)
    );

    XSelectInput(display, window, ExposureMask | ButtonPressMask);
    XMapWindow(display, window);

    GC gc = XCreateGC(display, window, 0, NULL);

    char **missing;
    int missing_count;
    char *defstr;
    XFontSet fontset = XCreateFontSet(display,
                                      "-misc-fixed-*-*-*-*-20-*-*-*-*-*-*-*",
                                      &missing, &missing_count, &defstr);
    if (!fontset) {
        std::cerr << "Ошибка: не удалось создать XFontSet\n";
        return 1;
    }

    Button btn_drop   = {10, 10, 200, 30, "Бросить две точки"};
    Button btn_square = {220, 10, 200, 30, "Дорисовать квадрат"};

    while (true) {
        XEvent e;
        XNextEvent(display, &e);

        if (e.type == Expose) {
            draw_button(display, window, gc, fontset, btn_drop);
            draw_button(display, window, gc, fontset, btn_square);
            draw_points(display, window, gc);
            if (draw_square_enabled)
                draw_square(display, window, gc);
        }

        if (e.type == ButtonPress) {
            int mx = e.xbutton.x;
            int my = e.xbutton.y;

            if (inside_button(btn_drop, mx, my)) {
                drop_points();
                draw_square_enabled = false;
                XClearWindow(display, window);
            }

            if (inside_button(btn_square, mx, my)) {
                draw_square_enabled = true;
                XClearWindow(display, window);
            }

            draw_button(display, window, gc, fontset, btn_drop);
            draw_button(display, window, gc, fontset, btn_square);
            draw_points(display, window, gc);
            if (draw_square_enabled)
                draw_square(display, window, gc);
        }
    }

    return 0;
}
