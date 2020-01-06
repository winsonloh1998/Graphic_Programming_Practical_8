#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#define WINDOW_TITLE "Practical 6"

float dif[] = { 0.0, 0.0, 1.0 };
float dif2[] = { 0.0, 1.0, 0.0 };
float pos[] = { 0.0, 0.0, 0.0 };
float pos2[] = { 0.0, 0.0, 0.0 };

int lightSwitch = 0;
int objShape = 0;
float rotate = 0.0;
float rotateLR = 0.0;

int questionNo = 1;
LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		else if (wParam == 'W')
			pos[1] += 0.1;
		else if (wParam == 'S')
			pos[1] -= 0.1;
		else if (wParam == 'A')
			pos[0] -= 0.1;
		else if (wParam == 'D')
			pos[0] += 0.1;
		else if (wParam == 'Y')
		{
			glRotatef(340, 1, 0, 0);
		}
		else if (wParam == '2')
			questionNo = 2;
		else if (wParam == VK_UP) 
			pos2[1] += 0.1;
		else if (wParam == VK_DOWN)
			pos2[1] -= 0.1;
		else if (wParam == VK_LEFT) 
			pos2[0] -= 0.1;
		else if (wParam == VK_RIGHT)
			pos2[0] += 0.1;
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void lightSource() {
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 0.1, -0.1);
	glVertex3f(0.1, 0.1, -0.1);
	glVertex3f(0.1, -0.1, -0.1);
	glVertex3f(-0.1, -0.1, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.1, -0.1, -0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glVertex3f(-0.1, 0.1, 0.1);
	glVertex3f(-0.1, 0.1, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 0.1, -0.1);
	glVertex3f(-0.1, 0.1, 0.1);
	glVertex3f(0.1, 0.1, 0.1);
	glVertex3f(0.1, 0.1, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.1, 0.1, -0.1);
	glVertex3f(0.1, 0.1, 0.1);
	glVertex3f(0.1, -0.1, 0.1);
	glVertex3f(0.1, -0.1, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.1, -0.1, -0.1);
	glVertex3f(-0.1, -0.1, -0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glVertex3f(0.1, -0.1, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.1, -0.1, 0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glVertex3f(-0.1, 0.1, 0.1);
	glVertex3f(0.1, 0.1, 0.1);
	glEnd();
}

void cube() {
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 0.1, -0.1);
	glVertex3f(0.1, 0.1, -0.1);
	glVertex3f(0.1, -0.1, -0.1);
	glVertex3f(-0.1, -0.1, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.1, -0.1, -0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glVertex3f(-0.1, 0.1, 0.1);
	glVertex3f(-0.1, 0.1, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 0.1, -0.1);
	glVertex3f(-0.1, 0.1, 0.1);
	glVertex3f(0.1, 0.1, 0.1);
	glVertex3f(0.1, 0.1, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.1, 0.1, -0.1);
	glVertex3f(0.1, 0.1, 0.1);
	glVertex3f(0.1, -0.1, 0.1);
	glVertex3f(0.1, -0.1, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.1, -0.1, -0.1);
	glVertex3f(-0.1, -0.1, -0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glVertex3f(0.1, -0.1, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.1, -0.1, 0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glVertex3f(-0.1, 0.1, 0.1);
	glVertex3f(0.1, 0.1, 0.1);
	glEnd();
}

void sphere() {
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, ambM);
	GLUquadricObj *sphere = NULL;
	sphere = gluNewQuadric();
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluSphere(sphere, 0.1, 30, 30);
	gluDeleteQuadric(sphere);
}

void plane() {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 0, -1);
	glVertex3f(-1, 0, 1);
	glVertex3f(1, 0, 1);
	glVertex3f(1, 0, -1);
	glEnd();
}

void shadow() {
	float yValue = 0.0;
	if (pos[1] > 3.0)
		yValue = pos[1];

	//Squish matrix for y-plane
	GLfloat matrix[16] =
	{
		yValue, -pos[0], 0 , 0,
		0, 0, 0, 0,
		0, -pos[2], yValue, 0,
		0, -1, 0, yValue
	};

	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(-0.5, 0.3, 0);
	glMultMatrixf(matrix);
	glColor3f(0, 0, 0);
	glTranslatef(0, 0.3, 0);
	sphere();
	glPopMatrix();

	//Squish matrix for y-plane
	GLfloat matrix1[16] =
	{
		yValue, -pos[0], 0 , 0,
		0, 0, 0, 0,
		0, -pos[2], yValue, 0,
		0, -1, 0, yValue
	};

	//glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(+0.5, 0.3, 0);
	glMultMatrixf(matrix1);
	glColor3f(0, 0, 0);
	glTranslatef(0, 0.3, 0);
	cube();
	glPopMatrix();
	
}

void shadow2(){
	float yValue = 0.0;
	if (pos2[1] > 3.0)
		yValue = pos2[1];

	//Squish matrix for y-plane
	GLfloat matrix[16] =
	{
		yValue, -pos2[0], 0 , 0,
		0, 0, 0, 0,
		0, -pos2[2], yValue, 0,
		0, -1, 0, yValue
	};

	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(-0.5, 0.3, 0);
	glMultMatrixf(matrix);
	glColor3f(0, 0, 0);
	glTranslatef(0.0, 0.3, 0);
	sphere();
	glPopMatrix();

	//Squish matrix for y-plane
	GLfloat matrix1[16] =
	{
		yValue, -pos2[0], 0 , 0,
		0, 0, 0, 0,
		0, -pos2[2], yValue, 0,
		0, -1, 0, yValue
	};

	//glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(+0.5, 0.3, 0);
	glMultMatrixf(matrix1);
	glColor3f(0, 0, 0);
	glTranslatef(0, 0.3, 0);
	cube();
	glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glClearColor(1, 1, 1, 0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_STENCIL_TEST);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glEnable(GL_LIGHT0);

	if (questionNo == 2)
	{
		glLightfv(GL_LIGHT1, GL_DIFFUSE, dif2);
		glLightfv(GL_LIGHT1, GL_POSITION, pos2);
		glEnable(GL_LIGHT1);
	}
	
	glPushMatrix();
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(pos[0], pos[1], pos[2]);
	lightSource();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(pos2[0], pos2[1], pos2[2]);
	lightSource();
	glPopMatrix();

	plane();

	glPushMatrix();
	glTranslatef(-0.5, 0.3, 0);
	sphere();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0.3, 0);
	cube();
	glPopMatrix();

	shadow();

	if(questionNo == 2)
		shadow2();
}
//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));


	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------

