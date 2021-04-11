/*
 * DemoWindow.h
 *
 *  Created on: 11 апр. 2021 г.
 *      Author: admin
 */

#ifndef DEMOWINDOW_H_
#define DEMOWINDOW_H_

#include "Window.h"

class DemoWindow final : public Window
{
public:
	DemoWindow(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~DemoWindow() = default;

	virtual void setup_gl();
	virtual void render();
};

#endif /* DEMOWINDOW_H_ */
