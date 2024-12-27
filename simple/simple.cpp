#include "simple/canvas.h"
#include "simple/renderable/text.h"
#include "simple/renderable/vertical_layout.h"
#include "simple/focusable/button.h"
#include "simple/modifier/border.h"
#include "simple/modifier/horizontal_flex.h"
#include "simple/renderable/horizontal_layout.h"
#include "simple/focusable/input.h"
#include "simple/focusable/vertical_container.h"
#include "simple/focusable/horizontal_container.h"
#include <iostream>

int main() {
	SetConsoleOutputCP(CP_UTF8);

	simple::canvas canvas = simple::canvas(20, 100);

	auto iUsername = input("username");
	auto iPassword = input();
	iPassword->hide = true;
	iPassword->limit = 8;
	iPassword->pattern = isdigit;
	auto bLogin = button("login");
	auto bExit = button("exit", []() { exit(0); });

	auto vLayout = vlayout(
		hlayout(text("username :"), iUsername),
		hlayout(text("password :"), iPassword),
		hlayout(bLogin, bExit)
	) | border_rounded;

	auto vContainer = vcontainer(
		iUsername,
		iPassword,
		hcontainer(bLogin, bExit)
	);
	vContainer->focused(true);

	bool update = true;
	bool running = true;
	INPUT_RECORD input_record[128];
	DWORD events;
	HANDLE input_handle = GetStdHandle(STD_INPUT_HANDLE);
	while (running) {
		ReadConsoleInput(input_handle, input_record, 128, &events);
		for (DWORD i = 0; i < events; ++i) {
			if (input_record[i].EventType == KEY_EVENT && input_record[i].Event.KeyEvent.bKeyDown) {
				if (vContainer->on_key(input_record[i].Event.KeyEvent)) {
					update = true;
				}
			}
		}

		if (update) {
			canvas.clear();
			vLayout->init();
			vLayout->set({ 0, 0, 100, 20 });
			vLayout->render(canvas);
			std::cout << "\x1b[H" << canvas.render() << std::flush;
			update = false;
		}
	}
}