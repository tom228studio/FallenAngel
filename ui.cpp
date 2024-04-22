#include <iostream>
#include <Windows.h>
#include <gdiplus.h>

using namespace Gdiplus;
using namespace std;

int main() {
    ULONG_PTR gdiplusToken;
    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    HWND targetWindow = FindWindowA(NULL, "AssaultCube");
    if (!targetWindow) {
        cerr << "Error: cannot find Notepad window." << std::endl;
        return 1;
    }

    HDC dc = GetDC(targetWindow);
    if (!dc) {
        cerr << "Error: cannot get device context of Notepad window." << std::endl;
        return 1;
    }
    Graphics graphics(dc);
    Pen pen(Color::Red, 2);
    Font font(L"Arial", 14);
    Rect rect(10, 20, 500, 300);
    LinearGradientBrush brush(rect, Color(255, 0, 0, 0), Color(255, 0, 0, 255), LinearGradientModeHorizontal);
    graphics.SetTextRenderingHint(TextRenderingHintAntiAlias);
    wstring text = L"Ванек ебаш соль\nCheat Menu \nHP increas:PgUP";
    PointF point(10.0f, 185.0f);
    while (true)
    {
        graphics.DrawString(text.c_str(), -1, &font, point, &brush);   
        graphics.FillEllipse(&brush, 10, 10, 170, 170);

        
        
    }
    ReleaseDC(targetWindow, dc);
    GdiplusShutdown(gdiplusToken);

    return 0;
}