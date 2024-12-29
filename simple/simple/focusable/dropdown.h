#ifndef _DROPDOWN_
#define _DROPDOWN_

#include "../renderable/renderable.h"
#include "focusable.h"

namespace simple {
	class dropdown final : public renderable, public focusable {
	public:
		dropdown(std::vector<std::string>&& values) :
			values(std::move(values)) {
		}
		dropdown(const std::vector<std::string>& values) :
			values(values) {
		}
		dropdown(std::string placeholder, std::vector<std::string>&& values) :
			placeholder(std::move(placeholder)),
			values(std::move(values)) {
		}
		dropdown(std::string placeholder, const std::vector<std::string>& values) :
			placeholder(std::move(placeholder)),
			values(values) {
		}

		void init() override {
			if (renderable::width == 0) {
				renderable::width = static_cast<int>(
					std::max(
						std::max_element(
							this->values.begin(),
							this->values.end(),
							[](const std::string& a, const std::string& b) {
								return a.size() < b.size();
							}
						)->size(),
						this->placeholder.size()
					)
					);
			}

			renderable::height = focusable::focused() ? std::min(7, static_cast<int>(this->values.size())) : 1;
		}
		void render(canvas& canvas) override {
			// render dropdown area
			for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(y, x).invert = true;
				}
			}

			// if focused, render list values into buffer
			if (focusable::focused()) {
				for (int y = renderable::dimension.top, i = this->text_begin; y < renderable::dimension.bottom; ++y, ++i) {
					for (int x = renderable::dimension.left + 1, ii = 0; x < renderable::dimension.right - 1; ++x, ++ii) {
						if (ii < this->values[i].size()) {
							canvas.at(y, x).character = this->values[i][ii];
						}
						else {
							break;
						}

						if (i == this->selected_index) {
							canvas.at(y, renderable::dimension.left).character = "*";
						}
					}
				}

				// render cursor position
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(renderable::dimension.top + this->y_cursor, x).invert = false;
				}

				// render vertical scrollbar
				if (index != 0) {
					int pos = this->index * 7 / static_cast<int>(this->values.size());
					canvas.at(renderable::dimension.top + pos, renderable::dimension.right - 1).character = u8"┃";
				}
				else {
					canvas.at(renderable::dimension.top, renderable::dimension.right - 1).character = u8"┃";
				}

				return;
			}

			int x = renderable::dimension.left;
			// if items not selected, render placeholder
			if (this->selected_index < 0 && !this->placeholder.empty()) {
				for (const auto& i : this->placeholder) {
					canvas.at(renderable::dimension.top, x++).character = i;
				}
			}
			// if items selected, render selected item
			else {
				for (const auto& i : this->values[this->selected_index]) {
					canvas.at(renderable::dimension.top, x++).character = i;
				}
			}
		}

		bool on_key(const KEY_EVENT_RECORD& key_event) override {
			// move next item
			if (key_event.wVirtualKeyCode == VK_DOWN ||
				key_event.uChar.AsciiChar == 'j' ||
				key_event.uChar.AsciiChar == 'J') {
				if (this->index < this->values.size() - 1) {
					++this->index;
					this->move_cursor(1);
					return true;
				}
				return false;
			}

			// move previous item
			if (key_event.wVirtualKeyCode == VK_UP ||
				key_event.uChar.AsciiChar == 'k' ||
				key_event.uChar.AsciiChar == 'K') {
				if (this->index > 0) {
					--this->index;
					this->move_cursor(-1);
					return true;
				}
				return false;
			}

			// select item
			if (key_event.wVirtualKeyCode == VK_RETURN) {
				this->selected_index = this->index;
				return true;
			}
			return false;
		}

	private:
		void move_cursor(int y) {
			if (y > 0) {
				if (this->y_cursor < height - 1) {
					++this->y_cursor;
				}
				else {
					++text_begin;
				}
			}
			else if (y < 0) {
				if (this->y_cursor > 0) {
					--this->y_cursor;
				}
				else {
					--text_begin;
				}
			}
		}

	private:
		int index = 0;
		int selected_index = -1;
		int y_cursor = 0;
		int text_begin = 0;
		std::string placeholder;
		std::vector<std::string> values;
	};
}

std::shared_ptr<simple::dropdown> dropdown(std::vector<std::string>&& values) {
	return std::make_shared<simple::dropdown>(std::move(values));
}

std::shared_ptr<simple::dropdown> dropdown(const std::vector<std::string>& values) {
	return std::make_shared<simple::dropdown>(values);
}

std::shared_ptr<simple::dropdown> dropdown(std::string placeholder, std::vector<std::string>&& values) {
	return std::make_shared<simple::dropdown>(std::move(placeholder), std::move(values));
}

std::shared_ptr<simple::dropdown> dropdown(std::string placeholder, const std::vector<std::string>& values) {
	return std::make_shared<simple::dropdown>(std::move(placeholder), values);
}

#endif // !_DROPDOWN_