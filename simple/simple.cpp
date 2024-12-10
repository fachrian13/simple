#include "simple.h"
#include <iostream>

using Simple::Palette16;
using Simple::Palette256;
using Simple::Color;
using Simple::Pixel;

int main() {
	Pixel p = Pixel(Color("#ff79c6"), Color("#282a36"));

	std::cout << p.Foreground.Foreground() << p.Background.Background();
}