#include "simple.h"
#include <iostream>

using Simple::Palette16;
using Simple::Palette256;
using Simple::Color;
using Simple::Pixel;
using Simple::Buffer;

int main() {
	Pixel p = Pixel(Color("#ff79c6"), Color("#282a36"), "*");
	Buffer b = Buffer(20, 100, p);
	
	std::cout << b.ToString();
}