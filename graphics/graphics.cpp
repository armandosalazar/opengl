#include <iostream>

#include "graphics.h";

Graphics::Graphics(/* args */)
{
    std::cout << "graphics constructor" << std::endl;
}

Graphics::~Graphics()
{
    std::cout << "graphics destructor" << std::endl;
}

void Graphics::putPixel(int x, int y, int color)
{
}
