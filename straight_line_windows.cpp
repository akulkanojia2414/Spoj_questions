#include<windows.h>
static HWND sHwnd;
static COLORREF redColor=RGB(255,0,0);
static COLORREF blueColor=RGB(0,0,255);
static COLORREF greenColor=RGB(0,255,0);

void SetWindowHandle(HWND hwnd)
{
    sHwnd=hwnd;
}
void setPixel(int x,int y,COLORREF& color=redColor)
{
    if(sHwnd==NULL)
    {
        MessageBox(NULL,"sHwnd was not initialized !","Error",MB_OK|MB_ICONERROR);
        exit(0);
    }
    HDC hdc=GetDC(sHwnd);
    SetPixel(hdc,x,y,color);
    ReleaseDC(sHwnd,hdc);
    return;
}
void drawRect(int x,int y)
{
    for(int i = x; i < x+200; i++)
		for(int j=y;j<y+100;j++)
        setPixel(i, j, blueColor);
}
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{HDC hdc;
    switch(message)
    {
    case WM_PAINT:
        SetWindowHandle(hwnd);
        drawRect(100,50);
        drawRect(350,50);
        drawRect(600,50);
        drawRect(850,50);
		drawRect(100,180);
        drawRect(350,180);
        drawRect(600,180);
        drawRect(850,180);
        drawRect(100,310);
        drawRect(350,310);
        drawRect(600,310);
        drawRect(850,310);
        drawRect(100,440);
        drawRect(350,440);
        drawRect(600,440);
        drawRect(850,440);
         hdc=GetDC(sHwnd);
	TextOut(hdc,100,100,"2",1);
        break;
    case WM_CLOSE: // FAIL THROUGH to call DefWindowProc
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        break; // FAIL to call DefWindowProc //
    }
    return DefWindowProc(hwnd,message,wParam,lParam);
}
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("Test");
    WNDCLASS wndclass;
    wndclass.style         = CS_HREDRAW|CS_VREDRAW ;
    wndclass.lpfnWndProc   = WndProc ;
    wndclass.cbClsExtra    = 0 ;
    wndclass.cbWndExtra    = 0 ;
    wndclass.hInstance     = hInstance ;
    wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
    wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
    wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
    wndclass.lpszMenuName  = NULL ;
    wndclass.lpszClassName = szAppName ;
// Register the window //
    if(!RegisterClass(& wndclass))
    {
        MessageBox(NULL,"Registering the class failled","Error",MB_OK|MB_ICONERROR);
        exit(0);
    }
// CreateWindow //
    HWND hwnd=CreateWindow(szAppName,"2048- //Author:AKul",
                           WS_OVERLAPPEDWINDOW,
                           0,0,1400,900,
                           NULL,
                           NULL,
                           hInstance,
                           NULL);
    if(!hwnd)
    {
        MessageBox(NULL,"Window Creation Failed!","Error",MB_OK);
        exit(0);
    }
// ShowWindow and UpdateWindow //
    ShowWindow(hwnd,iCmdShow);
    UpdateWindow(hwnd);
// Message Loop //
    MSG msg;
    while(GetMessage(& msg,NULL,0,0))
    {
        TranslateMessage(& msg);
        DispatchMessage(& msg);
    }
    return 0;
}
