#include "gui.h"
#include <cstring>
#include <X11/Xutil.h>

//рисует кнопки из прямоугольника и текста
void draw_button(Display* display, Window window, GC gc, XFontSet fontset, Button b) {
    XDrawRectangle(display, window, gc, b.x, b.y, b.w, b.h); //прямоугольник(рамка)
    XmbDrawString(display, window, fontset, gc,
                  b.x + 5, b.y + 22,  //текст по середине прямоугольнка
                  b.label, strlen(b.label));
}

//проверяет, нажата ли кнопка мыши внутри прямоугольника кнопки
bool inside_button(Button b, int mx, int my) {
    return (mx >= b.x && mx <= b.x + b.w &&
            my >= b.y && my <= b.y + b.h);
}
