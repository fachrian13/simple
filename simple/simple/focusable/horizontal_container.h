#ifndef _HORIZONTAL_CONTAINER_
#define _HORIZONTAL_CONTAINER_

#include <vector>
#include <memory>
#include "focusable.h"

namespace simple {
	class horizontal_container final : public focusable {
	public:
		horizontal_container(std::vector<std::shared_ptr<focusable>> components) :
			components(std::move(components)) {
		}

		void focused(bool flag) override {
			focusable::focused(flag);
			this->components[this->focused_component]->focused(flag);
		}
		bool on_key(const KEY_EVENT_RECORD& key_event) override {
			if (this->components[this->focused_component]->on_key(key_event)) {
				return true;
			}
			if (
				((key_event.dwControlKeyState & SHIFT_PRESSED) && key_event.wVirtualKeyCode == VK_TAB) ||
				key_event.wVirtualKeyCode == VK_LEFT ||
				key_event.uChar.AsciiChar == 'h' ||
				key_event.uChar.AsciiChar == 'H'
				) {
				if (this->focused_component > 0) {
					this->components[this->focused_component]->focused(false);
					this->components[--this->focused_component]->focused(true);
					return true;
				}
				return false;
			}
			if (
				key_event.wVirtualKeyCode == VK_TAB ||
				key_event.wVirtualKeyCode == VK_RIGHT ||
				key_event.uChar.AsciiChar == 'l' ||
				key_event.uChar.AsciiChar == 'L'
				) {
				if (this->focused_component < this->components.size() - 1) {
					this->components[this->focused_component]->focused(false);
					this->components[++this->focused_component]->focused(true);
					return true;
				}
				return false;
			}
			return false;
		}

	private:
		int focused_component = 0;
		std::vector<std::shared_ptr<focusable>> components;
	};
}

template<typename... T>
std::shared_ptr<simple::focusable> hcontainer(T&&... elements) {
	return std::make_shared<simple::horizontal_container>(
		std::vector<std::shared_ptr<simple::focusable>>{
		std::forward<T>(elements)...
	});
}

#endif // !_HORIZONTAL_CONTAINER_