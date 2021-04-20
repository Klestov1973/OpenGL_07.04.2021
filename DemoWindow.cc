 /*
 * DemoWindow.cc
 *
 *  Created on: 11 ���. 2021 �.
 *      Author: admin
 */

#include "DemoWindow.h"

DemoWindow::DemoWindow(int width, int height)
: Window(width, height)
{
	set_title("OpenGL Demo Window");
}

void DemoWindow::setup_gl()
{
	glEnable(GL_DEPTH_TEST); // испавляет не правильное изображение
	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(
			45.0,								// Угол обзора по вертикали
			double(width()) / double(height()),	// Соотношение сторон
			0.1,								// Расстояние до ближней ПО
			20.0);								// Расстояние до дальней ПО
	glMatrixMode(GL_MODELVIEW);
}

void Cube(){
	glBegin(GL_QUADS);

	glEnable(GL_CULL_FACE);

	glColor3d(1.0, 0.0, 0.0);		// Нижняя грань, красная
		glVertex3d(-0.5,  0.5, -0.5);
		glVertex3d(0.5,  0.5, -0.5);
		glVertex3d( 0.5, -0.5, -0.5);
		glVertex3d(-0.5, -0.5, -0.5);


		glColor3d(0.0, 1.0, 1.0);		// Верхняя грань, бирюзовая
		glVertex3d(-0.5, -0.5,  0.5);
		glVertex3d( 0.5, -0.5,  0.5);
		glVertex3d( 0.5,  0.5,  0.5);
		glVertex3d(-0.5,  0.5,  0.5);


		glColor3d(0.0, 0.0, 1.0);		// Боковая грань 1, синяя
			glVertex3d(-0.5, 0.5,  0.5);
			glVertex3d(-0.5, -0.5, 0.5);
			glVertex3d(-0.5, -0.5, -0.5);
			glVertex3d(-0.5,  0.5, -0.5);

		glColor3d(1.0, 0.5, .0);		// Боковая грань 2, оранжевый
			glVertex3d(-0.5, -0.5,  0.5);
			glVertex3d(0.5, -0.5, 0.5);
			glVertex3d(0.5, -0.5, -0.5);
			glVertex3d(-0.5, -0.5, -0.5);

		glColor3d(0.0, 1.0, 0.0);		// Боковая грань 3, зеленая
			glVertex3d(0.5, -0.5,  0.5);
			glVertex3d(0.5, -0.5, -0.5);
			glVertex3d(0.5, 0.5, -0.5);
			glVertex3d(0.5, 0.5, 0.5);

		glColor3d(1.0, 1.0, 0.5);		// Боковая грань 4, желтый
			glVertex3d(0.5, 0.5,  0.5);
			glVertex3d(-0.5, 0.5, 0.5);
			glVertex3d(-0.5, 0.5, -0.5);
			glVertex3d(0.5, 0.5, -0.5);


	glEnd();
	}

void DemoWindow::render()
{

	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); // Очистка



	glLoadIdentity(); // MV = единичная матрица

	gluLookAt(	3.0, 4.0, 2.0,		// Координаты камеры
				0.0, 0.0, 0.0,		// Координаты центра
				0.0, 0.0, 1.0);		// Направление вверх,	MV = C


	glRotated(_cube_angle, 0.0, 0.0, 1.0);


	glPushMatrix();// сохраняем текущие координаты

	glTranslated(0.0, 0.0, -0.5); // сдвигаемся по оси Y на -0.5
		Cube();

	glTranslated(-1.2, 0.0, 0.0); // сдвигаемся по оси Х на -1.2
	Cube();

	glTranslated(2.4, 0.0, 0.0); // еще сдвигаемся по оси Х на 2.4
	Cube();

	glTranslated(-0.6, 0.0, 1.0); // еще сдвигаемся по оси Х на -0.6 по оси Y на 1
	Cube();

	glTranslated(-1.2, 0.0, 0.0); // еще сдвигаемся по оси Х на -0.6 по оси Y на 1
	Cube();

	glTranslated(0.6, 0.0, 1.0); // еще сдвигаемся по оси Х на -0.6 по оси Y на 1
	Cube();

	glPopMatrix(); // возвращаемся к старой системе координат
}


void DemoWindow::update()
{
	_cube_angle += 0.1;
	if (_cube_angle >= 360.0)
		_cube_angle -= 360.0;
}
