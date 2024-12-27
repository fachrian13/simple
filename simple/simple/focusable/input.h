#ifndef _INPUT_
#define _INPUT_

#include <functional>
#include <string>
#include "../renderable/renderable.h"
#include "focusable.h"

namespace simple {
	class input final : public renderable, public focusable {
	public:
		input() = default;
		input(std::string placeholder) :
			placeholder(std::move(placeholder)) {
		}

		void init() override {
			if (renderable::height == 0) {
				renderable::height = 1;
			}
			if (renderable::width == 0) {
				renderable::width = 30;
			}
		}
		void render(canvas& canvas) override {
			// render input area
			for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(y, x).invert = true;
				}
			}

			// render cursor position if focused
			if (focusable::focused()) {
				canvas.at(renderable::dimension.top + this->y_cursor, renderable::dimension.left + this->x_cursor).invert = false;
			}

			// render placeholder if value is empty
			if (this->value.empty() && !this->placeholder.empty()) {
				for (int y = renderable::dimension.top, i = 0; y < renderable::dimension.bottom; ++y) {
					for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x, ++i) {
						if (i < this->placeholder.size()) {
							canvas.at(y, x).italic = true;
							canvas.at(y, x).character = this->placeholder[i];
						}
						else {
							break;
						}
					}
				}
				return;
			}

			// if hide is true, render value as bullet
			if (this->hide) {
				for (int y = renderable::dimension.top, i = this->text_begin; y < renderable::dimension.bottom; ++y) {
					for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x, ++i) {
						if (i < this->value.size()) {
							canvas.at(y, x).character = u8"•";
						}
						else {
							break;
						}
					}
				}
				return;
			}

			// render value
			for (int y = renderable::dimension.top, i = this->text_begin; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x, ++i) {
					if (i < this->value.size()) {
						canvas.at(y, x).character = this->value[i];
					}
					else {
						break;
					}
				}
			}
		}

		bool on_key(const KEY_EVENT_RECORD& key_event) override {
			switch (key_event.wVirtualKeyCode) {
			case VK_LEFT:
				if (this->index > 0) {
					--this->index;
					this->move_cursor(0, -1);
					return true;
				}
				break;
			case VK_UP:
				if (this->index - renderable::width >= 0) {
					this->index -= renderable::width;
					this->move_cursor(-1, 0);
					return true;
				}
				break;
			case VK_RIGHT:
				if (this->index < this->value.size()) {
					++this->index;
					this->move_cursor(0, 1);
					return true;
				}
				break;
			case VK_DOWN:
				if (this->index + renderable::width <= this->value.size()) {
					this->index += renderable::width;
					this->move_cursor(1, 0);
					return true;
				}
				break;
			case VK_BACK:
				if (this->index > 0) {
					this->value.erase(this->value.begin() + --this->index);
					this->move_cursor(0, -1);
					return true;
				}
				break;
			default:
				if (this->pattern(key_event.uChar.AsciiChar) && this->value.size() < this->limit) {
					this->value.insert(this->value.begin() + this->index++, key_event.uChar.AsciiChar);
					this->move_cursor(0, 1);
					return true;
				}
			}

			return false;
		}

	private:
		auto move_cursor(int y, int x) -> void {
			if (y > 0) {
				if (this->y_cursor < renderable::height - 1) {
					++this->y_cursor;
				}
				else { this->text_begin += renderable::width; }
			}
			else if (y < 0) {
				if (this->y_cursor > 0) {
					--this->y_cursor;
				}
				else { this->text_begin -= renderable::width; }
			}
			if (x > 0) {
				if (this->x_cursor < renderable::width - 1) {
					++this->x_cursor;
				}
				else if (this->y_cursor < renderable::height - 1) {
					this->x_cursor = 0;
					++this->y_cursor;
				}
				else {
					this->x_cursor = 0;
					this->text_begin += renderable::width;
				}
			}
			else if (x < 0) {
				if (this->x_cursor > 0) {
					--this->x_cursor;
				}
				else if (this->y_cursor > 0) {
					this->x_cursor = renderable::width - 1;
					--this->y_cursor;
				}
				else {
					this->x_cursor = renderable::width - 1;
					this->text_begin -= renderable::width;
				}
			}
		}

	public:
		bool hide = false;
		size_t limit = std::numeric_limits<size_t>::max();
		std::function<bool(int)> pattern = [](int ch) { return ch > 0x1F && ch < 0x7F; };

	private:
		int index = 0;
		int y_cursor = 0;
		int x_cursor = 0;
		int text_begin = 0;
		std::string value;
		std::string placeholder;
	};
}

std::shared_ptr<simple::input> input() {
	return std::make_shared<simple::input>();
}

std::shared_ptr<simple::input> input(std::string placeholder) {
	return std::make_shared<simple::input>(std::move(placeholder));
}

#endif // !_INPUT_