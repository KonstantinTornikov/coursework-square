#pragma once
#include <X11/Xlib.h>    
#include <X11/Xutil.h>   
#include <X11/Xlocale.h> 

struct Button {
    int x, y;           //координаты верхнего левого угла кнопки
    int w, h;           //ширина и высота кнопки
    const char* label;  //текст
};

void draw_button(Display* display, Window window, GC gc, XFontSet fontset, Button b);
bool inside_button(Button b, int mx, int my);
