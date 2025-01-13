#ifndef _SIMPLE_
#define _SIMPLE_

#include <iostream>
#include "simple/canvas.h"
#include "simple/renderable/renderable.h"
#include "simple/focusable/focusable.h"

namespace simple {
	class application {
	public:
		application(int height, int width) :
			canvas(height, width) {
		}
		void stop() {
			this->running = false;
		}
		void run() {
			// set console output to utf-8
			SetConsoleOutputCP(CP_UTF8);

			// hide cursor
			std::cout << "\x1b[?25l" << std::flush;

			this->main();
		}

	protected:
		virtual void main() = 0;
		void render(const std::shared_ptr<simple::renderable> element) {
			canvas.clear();
			element->init();
			element->set({ 0, 0, this->canvas.get_width(), this->canvas.get_height() });
			element->render(this->canvas);
			std::cout << "\x1b[H" << canvas.render() << std::flush;
		}
		void render(const std::shared_ptr<simple::renderable>& element, const std::shared_ptr<simple::focusable>& component) {
			component->focused(true);

			bool update = true;
			while (this->running) {
				ReadConsoleInput(this->input_handle, this->input_record, 128, &this->events);
				for (DWORD i = 0; i < this->events; ++i) {
					if (this->input_record[i].EventType == KEY_EVENT && this->input_record[i].Event.KeyEvent.bKeyDown) {
						component->on_key(this->input_record[i].Event.KeyEvent);
						update = true;
					}
				}

				if (update) {
					canvas.clear();
					element->init();
					element->set({ 0, 0, this->canvas.get_width(), this->canvas.get_height() });
					element->render(this->canvas);
					std::cout << "\x1b[H" << canvas.render() << std::flush;
					update = false;
				}
			}
		}
		void render(const bool& condition, const std::shared_ptr<simple::renderable>& element, const std::shared_ptr<simple::focusable>& component) {
			component->focused(true);

			bool update = true;
			while (condition) {
				ReadConsoleInput(this->input_handle, this->input_record, 128, &this->events);
				for (DWORD i = 0; i < this->events; ++i) {
					if (this->input_record[i].EventType == KEY_EVENT && this->input_record[i].Event.KeyEvent.bKeyDown) {
						component->on_key(this->input_record[i].Event.KeyEvent);
						update = true;
					}
				}

				if (update) {
					canvas.clear();
					element->init();
					element->set({ 0, 0, this->canvas.get_width(), this->canvas.get_height() });
					element->render(this->canvas);
					std::cout << "\x1b[H" << canvas.render() << std::flush;
					update = false;
				}
			}
		}

	protected:
		bool running = true;
		canvas canvas;
		HANDLE input_handle = GetStdHandle(STD_INPUT_HANDLE);
		HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
		INPUT_RECORD input_record[128]{};
		DWORD events = 0;
	};
}

#endif // !_SIMPLE_