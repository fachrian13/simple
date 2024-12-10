#include "simple.h"
#include <iostream>

using Simple::Palette16;
using Simple::Palette256;
using Simple::Color;
using Simple::Pixel;
using Simple::Buffer;
using Simple::Text;

int main() {
	Pixel p = Pixel(Color("#ff79c6"), Color("#282a36"), "*");
	Buffer b = Buffer(20, 100, p);

	Text t = Text("Hello World");
	t.Init();
	t.Set({ 0, 0, t.Width, t.Height });
	t.Render(b);
	
	std::cout << b.ToString();
}