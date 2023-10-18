#include <iostream>
#include <cmath>

#include <GL/glew.h>

#include "graphics.h"

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

void DrawCircleBasic(int x1, int y1, int xc, int yc)
{
	int radius = sqrt(pow(x1 - xc, 2) + pow(y1 - yc, 2));

	for (int x = xc - radius; x <= xc + radius; x++)
	{
		int yTop = (int)(yc + sqrt(pow(radius, 2) - pow((x - xc), 2)));
		int yBottom = (int)(yc - sqrt(pow(radius, 2) - pow((x - xc), 2)));
		PutPixel(x, yTop);
		PutPixel(x, yBottom);
	}
}

void DrawCirclePolarCoordinates(int xc, int yc, int radius)
{
	for (float theta = 0; theta <= 360; theta += 0.01)
	{
		float x = radius * cos(theta);
		float y = radius * sin(theta);
		PutPixel(xc + x, yc + y);
	}
}

void DrawEllipseMidPoint(int xc, int yc, int radiusX, int radiusY)
{
	float x = 0;
	float y = radiusY;
	float d = pow(radiusY, 2) - pow(radiusX, 2) * radiusY + 0.25 * pow(radiusX, 2);

	PutPixel(xc + x, yc + y);
	PutPixel(xc + x, yc - y);
	PutPixel(xc - x, yc + y);
	PutPixel(xc - x, yc - y);

	while (pow(radiusX, 2) * (y - 0.5) > pow(radiusY, 2) * (x + 1))
	{
		if (d < 0)
		{
			d += pow(radiusY, 2) * (2 * x + 3);
			x++;
		}
		else
		{
			d += pow(radiusY, 2) * (2 * x + 3) + pow(radiusX, 2) * (-2 * y + 2);
			x++;
			y--;
		}

		PutPixel(xc + x, yc + y);
		PutPixel(xc + x, yc - y);
		PutPixel(xc - x, yc + y);
		PutPixel(xc - x, yc - y);
	}

	d = pow(radiusY, 2) * pow((x + 0.5), 2) + pow(radiusX, 2) * pow((y - 1), 2) - pow(radiusX, 2) * pow(radiusY, 2);

	while (y > 0)
	{
		if (d < 0)
		{
			d += pow(radiusY, 2) * (2 * x + 2) + pow(radiusX, 2) * (-2 * y + 3);
			x++;
			y--;
		}
		else
		{
			d += pow(radiusX, 2) * (-2 * y + 3);
			y--;
		}

		PutPixel(xc + x, yc + y);
		PutPixel(xc + x, yc - y);
		PutPixel(xc - x, yc + y);
		PutPixel(xc - x, yc - y);
	}
}

void DrawRectangle(int x1, int y1, int x2, int y2)
{
	DrawLineDDA(x1, y1, x2, y1);
	DrawLineDDA(x2, y1, x2, y2);
	DrawLineDDA(x2, y2, x1, y2);
	DrawLineDDA(x1, y2, x1, y1);
}

void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	DrawLineDDA(x1, y1, x2, y2);
	DrawLineDDA(x2, y2, x3, y3);
	DrawLineDDA(x3, y3, x1, y1);
}

void DrawRhombus(int x1, int y1, int sideLength)
{
	int x2 = x1 + sideLength;
	int y2 = y1 + sideLength;
	int x3 = x1;
	int y3 = y1 + 2 * sideLength;
	int x4 = x1 - sideLength;
	int y4 = y1 + sideLength;

	DrawLineDDA(x1, y1, x2, y2);
	DrawLineDDA(x2, y2, x3, y3);
	DrawLineDDA(x3, y3, x4, y4);
	DrawLineDDA(x4, y4, x1, y1);
}

bool IsPointInTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
	// Calcula las áreas de los tres subtriángulos formados por el punto (x, y)
	double totalArea = 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
	double area1 = 0.5 * fabs(x * (y2 - y3) + x2 * (y3 - y) + x3 * (y - y2));
	double area2 = 0.5 * fabs(x1 * (y - y3) + x * (y3 - y1) + x3 * (y1 - y));
	double area3 = 0.5 * fabs(x1 * (y2 - y) + x2 * (y - y1) + x * (y1 - y2));

	// Si la suma de las áreas de los subtriángulos es igual al área total, el punto está dentro del triángulo
	return (totalArea == area1 + area2 + area3);
}

void FillTriangleInundation(int x1, int y1, int x2, int y2, int x3, int y3)
{
	// Encontrar los límites del triángulo
	int minX = std::min({x1, x2, x3});
	int minY = std::min({y1, y2, y3});
	int maxX = std::max({x1, x2, x3});
	int maxY = std::max({y1, y2, y3});

	for (int x = minX; x <= maxX; x++)
	{
		for (int y = minY; y <= maxY; y++)
		{
			// Comprobar si el punto (x, y) está dentro del triángulo
			if (IsPointInTriangle(x1, y1, x2, y2, x3, y3, x, y))
			{
				// Rellena el punto (x, y) aquí, por ejemplo, con DrawPixel(x, y)
				PutPixel(x, y);
			}
		}
	}
}

void FillRhombusScanline(int x1, int y1, int sideLength)
{
	int x2 = x1 + sideLength;
	int y2 = y1 + sideLength;
	int x3 = x1;
	int y3 = y1 + 2 * sideLength;
	int x4 = x1 - sideLength;
	int y4 = y1 + sideLength;

	FillTriangleInundation(x1, y1, x2, y2, x3, y3);
	FillTriangleInundation(x1, y1, x3, y3, x4, y4);
}

void FillCircleInundation(int xc, int yc, int radius)
{
	int x = 0;
	int y = radius;
	int d = 1 - radius;

	while (y >= x)
	{
		for (int i = xc - x; i <= xc + x; i++)
		{
			PutPixel(i, yc + y);
			PutPixel(i, yc - y);
		}

		for (int i = xc - y; i <= xc + y; i++)
		{
			PutPixel(i, yc + x);
			PutPixel(i, yc - x);
		}

		if (d < 0)
		{
			d += 2 * x + 3;
		}
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}

		x++;
	}
}

void FillRectangleScanline(int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= x2; i++)
	{
		DrawLineDDA(i, y1, i, y2);
	}
}

void FillEllipseScanline(int xc, int yc, int radiusX, int radiusY)
{
	for (int y = yc - radiusY; y <= yc + radiusY; y++)
	{
		int x1 = xc - radiusX;
		int x2 = xc + radiusX;
		bool inside = false;

		for (int x = x1; x <= x2; x++)
		{
			double dx = x - xc;
			double dy = y - yc;
			if ((dx * dx) / (radiusX * radiusX) + (dy * dy) / (radiusY * radiusY) <= 1.0)
			{
				inside = !inside;
				PutPixel(x, y);
			}
			else if (inside)
			{
				break; // Terminate the scanline if we were inside the ellipse and then went outside.
			}
		}
	}
}

void TranslatePoint(int &x, int &y, int tx, int ty)
{
	int matrix[3][3] = {
		{1, 0, tx},
		{0, 1, ty},
		{0, 0, 1}};

	int result[3] = {0, 0, 0};

	for (int i = 0; i < 3; i++)
	{
		result[i] = matrix[i][0] * x + matrix[i][1] * y + matrix[i][2];
	}

	x = result[0];
	y = result[1];
}

void ScalePoint(int &x, int &y, float sx, float sy)
{
	int matrix[3][3] = {
		{(int)round(sx), 0, 0},
		{0, (int)round(sy), 0},
		{0, 0, 1}};

	int result[3] = {0, 0, 0};

	for (int i = 0; i < 3; i++)
	{
		result[i] = matrix[i][0] * x + matrix[i][1] * y + matrix[i][2];
	}

	x = result[0];
	y = result[1];
}

void RotatePoint(int &x, int &y, int xc, int yc, float angle)
{
	int matrix[3][3] = {
		{(int)round(cos(angle)), (int)round(sin(angle)), 0},
		{(int)round(-sin(angle)), (int)round(cos(angle)), 0},
		{0, 0, 1}};

	int result[3] = {0, 0, 0};

	for (int i = 0; i < 3; i++)
	{
		result[i] = matrix[i][0] * (x - xc) + matrix[i][1] * (y - yc) + matrix[i][2];
	}

	x = result[0] + xc;
	y = result[1] + yc;
}
