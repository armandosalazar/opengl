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

/**
 * @brief Fill a Circle using the Inundation Algorithm
*/
void FillCircleInundation(int xc, int yc, int radius);

/**
 * @brief Fill a Circle using the Scanline Algorithm
*/
void FillRectangleScanline(int x1, int y1, int x2, int y2);

/**
 * @brief Fill a Ellipse using the Scanline Algorithm
*/
void FillEllipseScanline(int xc, int yc, int radiusX, int radiusY);

/**
 * @brief Translate a point with matrix multiplication
*/
void TranslatePoint(int &x, int &y, int tx, int ty);

/**
 * @brief Rotate a point with matrix multiplication
*/
void RotatePoint(int &x, int &y, float angle);

/**
 * @brief Scale a point with matrix multiplication
*/
void ScalePoint(int &x, int &y, float sx, float sy);