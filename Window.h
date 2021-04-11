/*
 * Window.h
 *
 *  Created on: 11 ���. 2021 �.
 *      Author: admin
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <memory>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Window {
public:
	static constexpr int DEFAULT_WIDTH = 800;
	static constexpr int DEFAULT_HEIGHT = 600;
	static constexpr int DEFAULT_X = SDL_WINDOWPOS_CENTERED;
	static constexpr int DEFAULT_Y = SDL_WINDOWPOS_CENTERED;
protected:
	std::shared_ptr<SDL_Window> _window; // ����
	std::shared_ptr<void> _gl_context; // �������� OpenGL
	int _width, _height; // ������ � ������ ����

public:
	Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~Window() = default;

	int getHeight() const {return _height;}
	int getWidth() const {return _width;}

	void main_loop();

	virtual void setup() {}
		virtual void setup_gl() {}
		virtual void update() {}
		virtual void render() {}
		virtual void handle_event(const SDL_Event& event) {}
		virtual void handle_keys(const Uint8 * keys) {}
};
#endif /* WINDOW_H_ */
