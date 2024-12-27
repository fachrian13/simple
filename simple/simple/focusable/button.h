#ifndef _BUTTON_
#define _BUTTON_

#include <string>
#include <functional>
#include "../renderable/renderable.h"
#include "focusable.h"

namespace simple {
	class button final : public renderable, public focusable {
	public:
		button(std::string name) :
			name(std::move(name)) {
		}
		button(std::string name, std::function<void()> logic) :
			name(std::move(name)),
			logic(std::move(logic)) {
		}

		void init() override {
			renderable::height = 1;
			renderable::width = static_cast<int>(this->name.size()) + 4;
		}
		void render(canvas& canvas) override {
			// render the []
			canvas.at(renderable::dimension.top, renderable::dimension.left).character = '[';
			canvas.at(renderable::dimension.top, renderable::dimension.right - 1).character = ']';

			// render the name to the center of the button
			int x = renderable::dimension.left + (renderable::dimension.right - renderable::dimension.left - static_cast<int>(this->name.size())) / 2;
			for (const auto& i : this->name) {
				canvas.at(renderable::dimension.top, x++).character = i;
			}

			// invert the button if focused
			if (focusable::focused()) {
				for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
					for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
						canvas.at(y, x).invert = true;
					}
				}
			}
		}

		bool on_key(const KEY_EVENT_RECORD& key) override {
			switch (key.wVirtualKeyCode) {
			case VK_RETURN:
				if (this->logic) {
					this->logic();
					return true;
				}
			}

			return false;
		}

	private:
		std::string name;
		std::function<void()> logic;
	};
}

std::shared_ptr<simple::button> button(std::string name) {
	return std::make_shared<simple::button>(std::move(name));
}

std::shared_ptr<simple::button> button(std::string name, std::function<void()> logic) {
	return std::make_shared<simple::button>(std::move(name), std::move(logic));
}

#endif // !_BUTTON_