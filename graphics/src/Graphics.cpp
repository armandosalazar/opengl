#include <iostream>

#include <GL/glew.h>

#include "Graphics.h"

void PutPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void DrawLineDDA(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;

	std::cout << "dx: " << dx << std::endl;
	std::cout << "dy: " << dy << std::endl;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float xInc = dx / (float)steps;
	float yInc = dy / (float)steps;

	float x = x1;
	float y = y1;

	for (int i = 0; i <= steps; i++)
	{
		PutPixel(round(x), round(y));
		x += xInc;
		y += yInc;
	}
}
