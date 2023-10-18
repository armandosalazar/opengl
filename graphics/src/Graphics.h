#pragma once

void PutPixel(int x, int y);

void DrawLineDDA(int x1, int y1, int x2, int y2);
void DrawLineBresenham(int x1, int y1, int x2, int y2);
void DrawLineMidPoint(int x1, int y1, int x2, int y2);

void DrawCircleBasic(int x1, int y1, int xc, int yc);
void DrawCircleMidPoint(int xc, int yc, int radius);
void DrawCirclePolarCoordinates(int xc, int yc, int radius);

void DrawEllipseMidPoint(int xc, int yc, int radiusX, int radiusY);
void DrawRectangle(int x1, int y1, int x2, int y2);

void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);

void DrawRhombus(int x1, int y1, int sideLength);

void FillTriangleInundation(int x1, int y1, int x2, int y2, int x3, int y3);

void FillRhombusScanline(int x1, int y1, int sideLength);

void FillCircleInundation(int xc, int yc, int radius);

void FillRectangleScanline(int x1, int y1, int x2, int y2);

void FillEllipseScanline(int xc, int yc, int radiusX, int radiusY);

void TranslatePoint(int &x, int &y, int tx, int ty);

void ScalePoint(int &x, int &y, float sx, float sy);

void RotatePoint(int &x, int &y, int xc, int yc, float angle);
