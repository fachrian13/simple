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
	bool loop = true;

	auto bLogin = Button("Login");
	auto bExit = Button("Exit", [&loop]() { loop = false; });
	auto dAgama = Dropdown("Silakan Pilih",
		{
			"Islam",
			"Kristen",
			"Hindu",
			"Buddha"
		}
	);

	auto v = VLayout(
		HLayout(Text("Username: "), Text("[]")),
		HLayout(Text("Password: "), Text("[]")),
		HLayout(bLogin, bExit),
		dAgama
	);

	auto vContainer = VContainer(
		HContainer(bLogin, bExit),
		dAgama
	);
	vContainer->Focused(true);

	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD iRecord[128];
	DWORD iSize;
	bool needUpdate = true;
	while (loop) {
		ReadConsoleInput(hIn, iRecord, 128, &iSize);
		for (DWORD i = 0; i < iSize; ++i) {
			if (iRecord[i].EventType == KEY_EVENT && iRecord[i].Event.KeyEvent.bKeyDown) {
				vContainer->OnKey(iRecord[i].Event.KeyEvent);
				needUpdate = true;
			}
		}

		if (needUpdate) {
			b.Clear();
			v->Init();
			v->Set({ 0, 0, v->Width, v->Height });
			v->Render(b);
			std::cout << "\x1b[H" << b.ToString() << std::flush;
			needUpdate = false;
		}
	}
}