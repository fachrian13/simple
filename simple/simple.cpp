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
#include "simple/modifier/vertical_flex.h"
#include "simple/modifier/horizontal_flex.h"
#include "simple/renderable/center.h"
#include <windows.h>
#include <iostream>

int main() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	SetConsoleOutputCP(CP_UTF8);

	simple::canvas canvas(csbi.srWindow.Bottom - csbi.srWindow.Top + 1, csbi.srWindow.Right - csbi.srWindow.Left + 1);

	auto vLayout = vlayout(
		hlayout(
			text("top-left") | border_rounded,
			hlayout(
				hfiller(),
				text("-- horizontal space --"),
				hfiller()
			) | border_rounded | hflex,
			text("top-center") | border_rounded,
			hlayout(
				hfiller(),
				text("-- horizontal space --"),
				hfiller()
			) | border_rounded | hflex,
			text("top-right") | border_rounded
		),
		vlayout(
			vfiller() | border_rounded,
			hlayout(
				hfiller(),
				text("-- space using vertical layout --"),
				hfiller()
			) | border_rounded,
			vfiller() | border_rounded
		) | border_rounded | vflex,
		hlayout(
			text("middle-left") | border_rounded,
			hlayout(
				hfiller(),
				text("-- horizontal space --"),
				hfiller()
			) | border_rounded | hflex,
			text("middle-center") | border_rounded,
			hlayout(
				hfiller(),
				text("-- horizontal space --"),
				hfiller()
			) | border_rounded | hflex,
			text("middle-right") | border_rounded
		),
		hlayout(
			hfiller() | border_rounded,
			vlayout(
				vfiller(),
				text("-- space using horizontal layout --"),
				vfiller()
			) | border_rounded,
			hfiller() | border_rounded
		) | border_rounded | vflex,
		hlayout(
			text("bottom-left") | border_rounded,
			hlayout(
				hfiller(),
				text("-- horizontal space --"),
				hfiller()
			) | border_rounded | hflex,
			text("bottom-center") | border_rounded,
			hlayout(
				hfiller(),
				text("-- horizontal space --"),
				hfiller()
			) | border_rounded | hflex,
			text("bottom-right") | border_rounded
		)
	) | border_rounded;
	vLayout->init();
	vLayout->set({ 0, 0, canvas.get_width(), canvas.get_height() });
	vLayout->render(canvas);

	std::cout << canvas.render();
}