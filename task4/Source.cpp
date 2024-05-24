#include <iostream>
#include <windows.h>
#include <cmath>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wc = { 0 };
    wc.lpszClassName = L"GraphPlotter";
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClass(&wc);

    HWND hwnd = CreateWindow(L"GraphPlotter", L"Graph Plotter", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (msg)
    {
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);

        // Отрисовка графиков f1(x), f2(x), f3(x)
        double xn = 3.35;
        double xk = 36.26;
        double xh = 0.2;

        for (double x = xn; x <= xk; x += xh)
        {
            double f1 = pow(x, 5) * tan(x + 2);
            double f2 = (5 * x + pow(x, 2)) / pow(x * x + 3, 3);
            double f3 = pow(sin(x + 3), 2) / pow(x, 5) - tan(3.14 * pow(x, 3));

            // Отрисовка точек

        }

        EndPaint(hwnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}