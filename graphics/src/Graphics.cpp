#include <iostream>
#include <cmath>

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

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float increment_x = dx / (float)steps;
	float increment_y = dy / (float)steps;

	float x = x1;
	float y = y1;

	for (int k = 0; k <= steps; k++)
	{
		PutPixel(round(x), round(y));
		x += increment_x;
		y += increment_y;
	}
}

void DrawLineBresenham(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;

	int x = x1;
	int y = y1;

	int inc_x = 1;
	int inc_y = 1;

	if (dx < 0)
	{
		inc_x = -1;
		dx = -dx;
	}

	if (dy < 0)
	{
		inc_y = -1;
		dy = -dy;
	}

	int incE = 2 * dy;
	int incNE = 2 * dy - 2 * dx;
	int d = 2 * dy - dx;

	PutPixel(x, y);

	while (x != x2)
	{
		if (d <= 0)
		{
			d += incE;
			x += inc_x;
		}
		else
		{
			d += incNE;
			x += inc_x;
			y += inc_y;
		}

		PutPixel(x, y);
	}
}

void DrawLineMidPoint(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;

	int x = x1;
	int y = y1;

	int inc_x = 1;
	int inc_y = 1;

	if (dx < 0)
	{
		inc_x = -1;
		dx = -dx;
	}

	if (dy < 0)
	{
		inc_y = -1;
		dy = -dy;
	}

	int incE = 2 * dy;
	int incNE = 2 * dy - 2 * dx;
	int d = 2 * dy - dx;

	PutPixel(x, y);

	while (x != x2)
	{
		if (d <= 0)
		{
			d += incE;
			x += inc_x;
		}
		else
		{
			d += incNE;
			x += inc_x;
			y += inc_y;
		}

		PutPixel(x, y);
	}
}

void DrawCircleMidPoint(int xc, int yc, int radius)
{
	int x = 0;
	int y = radius;
	int d = 1 - radius;

	PutPixel(xc + x, yc + y);
	PutPixel(xc + x, yc - y);
	PutPixel(xc - x, yc + y);
	PutPixel(xc - x, yc - y);
	PutPixel(xc + y, yc + x);
	PutPixel(xc + y, yc - x);
	PutPixel(xc - y, yc + x);
	PutPixel(xc - y, yc - x);

	while (y > x)
	{
		if (d < 0)
		{
			d += 2 * x + 3;
			x++;
		}
		else
		{
			d += 2 * (x - y) + 5;
			x++;
			y--;
		}

		PutPixel(xc + x, yc + y);
		PutPixel(xc + x, yc - y);
		PutPixel(xc - x, yc + y);
		PutPixel(xc - x, yc - y);
		PutPixel(xc + y, yc + x);
		PutPixel(xc + y, yc - x);
		PutPixel(xc - y, yc + x);
		PutPixel(xc - y, yc - x);
	}
}

void DrawCircleBresenham(int xc, int yc, int radius)
{
	
}
