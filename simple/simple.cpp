#include <iostream>
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
#include <windows.h>

int main() {
	SetConsoleOutputCP(CP_UTF8);

	simple::canvas c = simple::canvas(20, 100);

	auto vl = vlayout(
		text("VERTICAL1 "),
		text("VERTICAL12 "),
		hlayout(
			text("HORIZONTAL1 ") | vcenter | background(simple::palette256::medium_aquamarine3),
			vlayout(vfiller(), text("HORIZONTAL12 ")) | background(simple::color(89, 123, 187)),
			vlayout(
				text("VERTICAL1 ") | hcenter | background(simple::palette256::plum4),
				hlayout(hfiller(), text("VERTICAL12 ")) | background(simple::palette256::dark_olive_green),
				hlayout(
					text("HORIZONTAL1 "),
					text("HORIZONTAL12 "),
					text("HORIZONTAL123 "),
					text("HORIZONTAL1234 ")
				) | border_dashed,
				text("VERTICAL123 "),
				text("VERTICAL1234 ")
			) | border_rounded,
			text("HORIZONTAL123 "),
			text("HORIZONTAL1234 ")
		) | border_line,
		text("VERTICAL123 "),
		text("VERTICAL1234 ")
	) | foreground(simple::palette16::black) | background(simple::palette256::cornflower_blue4) | border_double_line;
	vl->init();
	vl->set({ 0, 0, 100, 20 });
	vl->render(c);

	std::cout << c.render();
}