#include "gui.h"
#include <cstring>
#include <X11/Xutil.h>

void draw_button(Display* display, Window window, GC gc, XFontSet fontset, Button b) {
    XDrawRectangle(display, window, gc, b.x, b.y, b.w, b.h);
    XmbDrawString(display, window, fontset, gc,
                  b.x + 5, b.y + 22,
                  b.label, strlen(b.label));
}

bool inside_button(Button b, int mx, int my) {
    return (mx >= b.x && mx <= b.x + b.w &&
            my >= b.y && my <= b.y + b.h);
}
