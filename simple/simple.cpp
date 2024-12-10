#include "simple.h"
#include <iostream>

using Simple::Palette16;
using Simple::Palette256;
using Simple::Color;
using Simple::Pixel;
using Simple::Buffer;
using Simple::Text;

int main() {
	Pixel p = Pixel(Color("#ff79c6"), Color("#282a36"), ".");
	Buffer b = Buffer(20, 100, p);

	auto v = VLayout(
		Text("VERTICAL 1"),
		Text("VERTICAL 22"),
		HLayout(
			Text("HORIZONTAL 1"),
			Text("HORIZONTAL 22"),
			VLayout(
				Text("VERTICAL 1"),
				Text("VERTICAL 22"),
				HLayout(
					Text("HORIZONTAL 1"),
					Text("HORIZONTAL 22"),
					Text("HORIZONTAL 333"),
					Text("HORIZONTAL 4444")
				),
				Text("VERTICAL 333"),
				Text("VERTICAL 4444")
			),
			Text("HORIZONTAL 333"),
			Text("HORIZONTAL 4444")
		),
		Text("VERTICAL 333"),
		Text("VERTICAL 4444")
	);

	v->Init();
	v->Set({ 0, 0, v->Width, v->Height });
	v->Render(b);
	
	std::cout << b.ToString();
}