#include "simple/canvas.h"
#include "simple/renderable/text.h"
#include "simple/renderable/vertical_layout.h"
#include "simple/renderable/horizontal_layout.h"
#include "simple/renderable/vertical_filler.h"
#include "simple/renderable/horizontal_filler.h"
#include "simple/modifier/foreground.h"
#include "simple/modifier/background.h"
#include "simple/modifier/border.h"
#include "simple/renderable/horizontal_center.h"
#include "simple/renderable/vertical_center.h"
#include "simple/modifier/blink.h"
#include "simple/modifier/italic.h"
#include "simple/modifier/strikethrough.h"
#include <windows.h>
#include <iostream>

int main() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	SetConsoleOutputCP(CP_UTF8);

	simple::canvas canvas(csbi.dwSize.Y, csbi.dwSize.X);

	auto vLayout = vlayout(
		hlayout(text("top-left"), hfiller(), text("top-center"), hfiller(), text("top-right")),
		vfiller(),
		hlayout(text("middle-left"), hfiller(), text("middle-center"), hfiller(), text("middle-right")),
		vfiller(),
		hlayout(text("bottom-left"), hfiller(), text("bottom-center"), hfiller(), text("bottom-right"))
	) | border_rounded;
	vLayout->init();
	vLayout->set({ 0, 0, canvas.get_width(), canvas.get_height() });
	vLayout->render(canvas);

	std::cout << canvas.render();
}