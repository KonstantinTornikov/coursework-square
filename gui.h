#pragma once
#include <X11/Xlib.h>    
#include <X11/Xutil.h>   
#include <X11/Xlocale.h> 

//кнопка и что ей передаем
struct Button {
    int x, y;           //координаты верхнего левого угла кнопки
    int w, h;           //ширина и высота кнопки
    const char* label;  //текст
};

//Функция рисует кнопку на окне
void draw_button(Display* display, Window window, GC gc, XFontSet fontset, Button b);

//функция проверки находится курсор в кнопке или нет
bool inside_button(Button b, int mx, int my);
