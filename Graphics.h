#ifndef _GRAPHICS_H   
#define _GRAPHICS_H
#include <windows.h>

int const size_of_button = 80;
int const start_line = 10; // координаты левого угла начального квадрата  по х
int const start_colom = 190; // координаты левого угла начального квадрата  по y
int const count = 4; // количество кнопок в одном ряду 
int const width_input_line = 30; // ширина строки ввода 
int const len = 20; //   координата верхнего левого угла консоли по y
int const consol = 10; // консоль по у

// Идентификаторы кнопок
#define IDB_Button1 1
#define IDB_Button2 2
#define IDB_Button3 3
#define IDB_Button4 4
#define IDB_Button5 5
#define IDB_Button6 6
#define IDB_Button7 7
#define IDB_Button8 8
#define IDB_Button9 9
#define IDB_Button10 10
#define IDB_Button11 11
#define IDB_Button12 12
#define IDB_Button13 13
#define IDB_Button14 14
#define IDB_Button15 15
#define IDB_Button16 16
#define IDB_Button17 17
#define IDB_Button18 18
#define IDB_Button19 19
#define IDB_Button20 20
#define IDB_Button21 21
#define IDB_Button22 22

// идентификатор дочернего окна
#define ID_FIRSTCHILD 100

// объявление функций
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK СhildProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hinst;

ATOM RegMyWindowClass(HINSTANCE, LPCTSTR);
ATOM RegMyWindowClassChild(HINSTANCE, LPCTSTR);

HDC hdc;
HWND hWnd;
////////////////////////////////////////////////////////////////////////// 
// функция вхождений программы WinMain
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE         hPrevInstance,
	LPSTR             lpCmdLine,
	int               nCmdShow)
{

	// имя будущего класса
	LPCTSTR lpzClass = TEXT("My Window Class!");

	// регистрация класса
	if (!RegMyWindowClass(hInstance, lpzClass))
		return 1;

	// вычисление координат центра экрана
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect); // разрешение экрана
	int x = screen_rect.right / 2 - 150;
	int y = screen_rect.bottom / 2 - 75;

	// создание диалогового окна
	HWND hWnd = CreateWindow(lpzClass, TEXT("calculator"),
		WS_OVERLAPPEDWINDOW| WS_VISIBLE| WS_CLIPCHILDREN| WS_TILEDWINDOW, x, y, 4 * size_of_button + 2 * len, 5 * size_of_button + 3 * len + start_colom, NULL, NULL, hInstance, NULL);
	//WS_VSCROLL | WS_HSCROLL | горизонтальная и вертикальная полоса прокрутки 
	// если окно не создано, описатель будет равен 0
	if (!hWnd) return 2;
	



	// Идентификаторы кнопок
	HWND hButton1, hButton2, hButton3, hButton4, hButton5,
		hButton6, hButton7, hButton8, hButton9, hButton10,
		hButton11, hButton12, hButton13, hButton14, hButton15,
		hButton16, hButton17, hButton18, hButton19, hButton20, hButton21, hButton22 ;

	HMENU Button1, Button2, Button3, Button4, Button5,
		Button6, Button7, Button8, Button9, Button10,
		Button11, Button12, Button13, Button14, Button15,
		Button16, Button17, Button18, Button19, Button20, Button21, Button22;


	int line = start_line, column = start_colom; //  координаты левого угла начального квадрата 


												 // Создаем кнопки

												 //0 ряд
	column = column - size_of_button;
	line = start_line;

	hButton17 = CreateWindow("button", "(",
		WS_CHILD | WS_VISIBLE |  BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button17,
		hInstance, NULL);

	line = line + size_of_button;

	hButton18 = CreateWindow("button", ")",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button18,
		hInstance, NULL);

	line = line + size_of_button;

	hButton19 = CreateWindow("button", "div",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button19,
		hInstance, NULL);

	line = line + size_of_button;

	hButton20 = CreateWindow("button", "<",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button20,
		hInstance, NULL);


	// 1 ряд
	line = start_line;
	column = start_colom;
	hButton7 = CreateWindow("button", "7",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button7,
		hInstance, NULL);

	line = line + size_of_button;


	hButton8 = CreateWindow("button", "8",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button8,
		hInstance, NULL);
	line = line + size_of_button;


	hButton9 = CreateWindow("button", "9",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button9,
		hInstance, NULL);
	line = line + size_of_button;


	hButton11 = CreateWindow("button", "/",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button11,
		hInstance, NULL);

	line = line + size_of_button;


	//2 строка 

	column = column + size_of_button;
	line = start_line;

	hButton4 = CreateWindow("button", "4",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button4,
		hInstance, NULL);
	line = line + size_of_button;

	hButton5 = CreateWindow("button", "5",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button5,
		hInstance, NULL);
	line = line + size_of_button;

	hButton6 = CreateWindow("button", "6",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button6,
		hInstance, NULL);
	line = line + size_of_button;

	hButton12 = CreateWindow("button", "X",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button12,
		hInstance, NULL);
	line = line + size_of_button;

	//3 строка 

	column = column + size_of_button;
	line = start_line;

	hButton1 = CreateWindow("button", "1",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button1,
		hInstance, NULL);
	line = line + size_of_button;

	hButton2 = CreateWindow("button", "2",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button2,
		hInstance, NULL);
	line = line + size_of_button;

	hButton3 = CreateWindow("button", "3",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button3,
		hInstance, NULL);
	line = line + size_of_button;

	hButton13 = CreateWindow("button", "-",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button13,
		hInstance, NULL);

	line = line + size_of_button;
	//4 строка 

	column = column + size_of_button;
	line = start_line;
	hButton10 = CreateWindow("button", "0",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button10,
		hInstance, NULL);

	line = line + size_of_button;


	hButton15 = CreateWindow("button", ".",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button15,
		hInstance, NULL);
	line = line + size_of_button;

	hButton16 = CreateWindow("button", "=",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button16,
		hInstance, NULL);
	line = line + size_of_button;

	hButton14 = CreateWindow("button", "+",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button14,
		hInstance, NULL);
	line = line + size_of_button;

	// 5 ряд


	column = column + size_of_button;
	line = start_line;

	hButton21 = CreateWindow("button", "Точность",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button, size_of_button,
		hWnd,
		(HMENU)IDB_Button21,
		hInstance, NULL);
	line = line + size_of_button;

	hButton22 = CreateWindow("button", "Показать подробный результат",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		line, column,
		size_of_button * 3, size_of_button,
		hWnd,
		(HMENU)IDB_Button22,
		hInstance, NULL);

	// цикл сообщений приложения
	MSG msg = { 0 };    // структура сообщения
	int iGetOk = 0;   // переменная состояния
	while ((iGetOk = GetMessage(&msg, NULL, 0, 0)) != 0) // цикл сообщений
	{
		if (iGetOk == -1) return 3;  // если GetMessage вернул ошибку - выход
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;  // возвращаем код завершения программы
}

////////////////////////////////////////////////////////////////////////// 
// функция регистрации класса окон
ATOM RegMyWindowClass(HINSTANCE hInst, LPCTSTR lpzClassName)
{
	WNDCLASS wcWindowClass = { 0 };
	// адрес ф-ции обработки сообщений
	wcWindowClass.lpfnWndProc = (WNDPROC)WndProc;
	// стиль окна
	wcWindowClass.style = CS_HREDRAW | CS_VREDRAW;
	// дискриптор экземпляра приложения
	wcWindowClass.hInstance = hInst;
	// название класса
	wcWindowClass.lpszClassName = lpzClassName;
	// загрузка курсора
	wcWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	// загрузка цвета окон
	wcWindowClass.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;
	return RegisterClass(&wcWindowClass); // регистрация класса
}

HINSTANCE hInst;

////////////////////////////////////////////////////////////////////////// 
// функция обработки сообщений




LRESULT CALLBACK ChildProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   // Обработчик сообщений
	switch (message)
	{
	case WM_DESTROY: PostQuitMessage(0);


		break; // Завершение программы
			   // Обработка сообщения по умолчанию

	case WM_CTLCOLORSTATIC:
	{
		HDC hdcStatic = (HDC)wParam;
		SetTextColor(hdcStatic, RGB(0, 0, 0));
		SetBkColor(hdcStatic, RGB(248, 248, 255));
		HBRUSH hbrBkgnd = NULL;
		if (hbrBkgnd == NULL)
		{
			hbrBkgnd = CreateSolidBrush(RGB(248, 248, 255));
		}
		return (INT_PTR)hbrBkgnd;
	}
	break;
	default: return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


static HWND hStat;
WNDPROC StaticWndProc = NULL;
TCHAR szText[] = "TestString";
HWND hWndStatic;

LRESULT CALLBACK MyStaticWndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	if (Message == WM_PAINT)
	{
		RECT rc;
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rc);
		SetBkMode(hdc, TRANSPARENT);
		DrawText(hdc, szText, 10, &rc, DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	}
}




#define _CRT_SECURE_NO_WARNINGS
#endif   