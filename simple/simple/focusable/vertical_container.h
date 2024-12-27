#ifndef _VERTICAL_CONTAINER_
#define _VERTICAL_CONTAINER_

#include <vector>
#include <memory>
#include "focusable.h"

namespace simple {
	class vertical_container final : public focusable {
	public:
		vertical_container(std::vector<std::shared_ptr<focusable>> components) :
			components(std::move(components)) {
		}

		auto focused(bool flag) -> void override {
			focusable::focused(flag);
			this->components[this->focused_component]->focused(flag);
		}
		auto on_key(const KEY_EVENT_RECORD& key_event) -> bool override {
			if (this->components[this->focused_component]->on_key(key_event)) {
				return true;
			}

			// move focus to the next component
			if (
				((key_event.dwControlKeyState & SHIFT_PRESSED) && key_event.wVirtualKeyCode == VK_TAB) ||
				key_event.wVirtualKeyCode == VK_UP ||
				key_event.uChar.AsciiChar == 'k' ||
				key_event.uChar.AsciiChar == 'K'
				) {
				if (this->focused_component > 0) {
					this->components[this->focused_component]->focused(false);
					this->components[--this->focused_component]->focused(true);
					return true;
				}
				return false;
			}

			// move focus to the previous component
			if (
				key_event.wVirtualKeyCode == VK_TAB ||
				key_event.wVirtualKeyCode == VK_DOWN ||
				key_event.uChar.AsciiChar == 'j' ||
				key_event.uChar.AsciiChar == 'J'
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
std::shared_ptr<simple::focusable> vcontainer(T&&... elements) {
	return std::make_shared<simple::vertical_container>(
		std::vector<std::shared_ptr<simple::focusable>>{
		std::forward<T>(elements)...
	}
	);
}

#endif // !_VERTICAL_CONTAINER_