#pragma once

void PutPixel(int x, int y);
void DrawLineDDA(int x1, int y1, int x2, int y2);
void DrawLineBresenham(int x1, int y1, int x2, int y2);
void DrawLineMidPoint(int x1, int y1, int x2, int y2);
void DrawCircleMidPoint(int xc, int yc, int radius);
void DrawCircleBresenham(int xc, int yc, int radius);
void DrawCirclePolar(int xc, int yc, int radius);
void DrawCircleIterativePolar(int xc, int yc, int radius);
void DrawCircleDirectEquation(int xc, int yc, int radius);
void DrawCircleCartesianEquation(int xc, int yc, int radius);
void DrawEllipseMidPoint(int xc, int yc, int rx, int ry);
void DrawEllipseDirectEquation(int xc, int yc, int rx, int ry);
void DrawEllipseCartesianEquation(int xc, int yc, int rx, int ry);
void DrawEllipseTrigonometricEquation(int xc, int yc, int rx, int ry);

