// Win32Project1.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Win32Project1.h"
#include "Typer.h"
class Typer;

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
COLORREF WINDOW_BACKGROUND_COLOR;
COLORREF TEXT_COLOR = RGB(0, 0, 0);
Typer typer;


LPCWSTR windowTitle = L"Typer";

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                RegisterWindowClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    WINDOW_BACKGROUND_COLOR = RGB(255, 255, 255);
    
    typer.reset();
    typer.start();

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
    RegisterWindowClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow)) {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
//
ATOM RegisterWindowClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize         = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;

    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);

    wcex.hbrBackground  = NULL;
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной
   
   HWND hWnd = CreateWindowW(szWindowClass,       // lpClassName
                             windowTitle,         // lpWindowName 
                             WS_OVERLAPPEDWINDOW, // dwStyle
                             CW_USEDEFAULT,       // x
                             0,                   // y
                             CW_USEDEFAULT,       // mWidth 
                             0,                   // mHeight
                             nullptr,             // hWndParent
                             nullptr,             // hMenu
                             hInstance,           // hInstance
                             nullptr);            // lpParam
   if (!hWnd) {
      return FALSE;
   }
   
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


void handleMenuSelection(HWND hWnd, int wmId) {
    switch (wmId) {
     case IDM_EXIT:
        DestroyWindow(hWnd);
        break;
    default:
        return;
    }
}


void goRed() {
    WINDOW_BACKGROUND_COLOR = RGB(255, 0, 0);
}


void goWhite() {
    WINDOW_BACKGROUND_COLOR = RGB(255, 255, 255);
}


int GetTextSize(LPCWSTR a0)
{
    for (int iLoopCounter = 0; ; iLoopCounter++) {
        if (a0[iLoopCounter] == '\0') {
            return iLoopCounter;
        }
    }
}


wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
    int strSize = strlen(charArray);
    wchar_t* wString = new wchar_t[strSize];
    MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, strSize);
    return wString;
}


void doPaint(HWND hWnd, HDC hdc, PAINTSTRUCT * ps) {
    HFONT hFont, hTmp;
    RECT rect;
    GetClientRect(hWnd, &rect);

    HGDIOBJ original = NULL;
    original = SelectObject(hdc, GetStockObject(DC_PEN));
    LPCWSTR fontName = (LPCWSTR)"SYSTEM_FIXED_FONT";
    hFont = CreateFontW(60, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 2, FF_DECORATIVE, fontName);
    hTmp = (HFONT)SelectObject(hdc, hFont);
    

    SelectObject(hdc, GetStockObject(DC_BRUSH));
    SetDCBrushColor(hdc, WINDOW_BACKGROUND_COLOR);
    
    SelectObject(hdc, GetStockObject(DC_PEN));
    SetDCPenColor(hdc, WINDOW_BACKGROUND_COLOR);

    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

   
    const char * textToPrint = typer.getSequence();
    
    int textSize = strlen(textToPrint);
    int textX = (rect.right - rect.left) / 2 - textSize;
    int textY = (rect.bottom - rect.top) / 2;

    // http://www.cplusplus.com/forum/windows/17963/
    DrawTextW(hdc,
        convertCharArrayToLPCWSTR(textToPrint), 
        Typer::SEQUENCE_SIZE, 
        &rect, 
        DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    DeleteObject(SelectObject(hdc, hTmp));
    
    delete textToPrint;

    SelectObject(hdc, original);
}


void redraw(HWND hWnd) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    SetBkMode(hdc, TRANSPARENT);
    doPaint(hWnd, hdc, &ps);
    EndPaint(hWnd, &ps);
}


//int CALLBACK EnumFontFamExProc(
//    const LOGFONT    *lpelfe,
//    const TEXTMETRIC *lpntme,
//    DWORD      FontType,
//    LPARAM     lParam
//) {
//
//}

void setFonts(HDC hdc) {
    LPLOGFONT logFont;
    logFont->lfCharSet = DEFAULT_CHARSET;
    logFont->lfFaceName[0] = '\0';
    logFont->lfPitchAndFamily = 0;
        
    //EnumFontFamiliesEx( hdc, //
    //                    logFont,
    //                    EnumFontFamExProc, //lpEnumFontFamExProc
    //                    lparam,
    //                    dwFlags
    //);
}



void handleKeyPress(HWND hWnd, wchar_t key) {
    if (key == VK_ESCAPE) {
        DestroyWindow(hWnd);
    }

    Typer::Character character = Typer::symToCharacter(key);
    typer.onInput(character, goWhite, goRed);
    redraw(hWnd);
    
    RECT rect;
    GetClientRect(hWnd, &rect);
    RedrawWindow(hWnd, &rect, NULL, RDW_NOERASE | RDW_INVALIDATE | RDW_UPDATENOW);
}



//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает события / сообщения в главном окне.
//
//  WM_COMMAND — обработать меню приложения
//  WM_PAINT — отрисовать главное окно
//  WM_DESTROY — отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CHAR:
        handleKeyPress(hWnd, (wchar_t)wParam);
        break;
    case WM_PAINT:
        redraw(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

