#ifndef _TOGGLE_
#define _TOGGLE_

#include "selectable.h"
#include "../renderable/renderable.h"
#include "../focusable/focusable.h"

namespace simple {
	class toggle final : public selectable, public renderable, public focusable {
	public:
		toggle() = default;
		toggle(std::string name) :
			selectable(std::move(name)) {
		}
		
		void init() override {
			renderable::height = 1;
			renderable::width = (selectable::selected() ? 4 : 5) + static_cast<int>(selectable::name.size());
		}
		void render(canvas& canvas) override {
			if (selectable::selected()) {
				canvas.at(renderable::dimension.top, renderable::dimension.left).character = "[";
				canvas.at(renderable::dimension.top, renderable::dimension.left + 1).character = "O";
				canvas.at(renderable::dimension.top, renderable::dimension.left + 2).character = "N";
				canvas.at(renderable::dimension.top, renderable::dimension.left + 3).character = "]";
			}
			else {
				canvas.at(renderable::dimension.top, renderable::dimension.left).character = "[";
				canvas.at(renderable::dimension.top, renderable::dimension.left + 1).character = "O";
				canvas.at(renderable::dimension.top, renderable::dimension.left + 2).character = "F";
				canvas.at(renderable::dimension.top, renderable::dimension.left + 3).character = "F";
				canvas.at(renderable::dimension.top, renderable::dimension.left + 4).character = "]";
			}

			int x = renderable::dimension.left + (selectable::selected() ? 4 : 5);
			for (const auto& i : selectable::name) {
				canvas.at(renderable::dimension.top, x++).character = i;
			}

			if (focusable::focused()) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(renderable::dimension.top, x).invert = true;
				}
			}
		}

		bool on_key(const KEY_EVENT_RECORD& keyEvent) override {
			if (keyEvent.wVirtualKeyCode == VK_RETURN || keyEvent.uChar.AsciiChar == ' ') {
				if (selectable::group) {
					selectable::group->clear();
				}
				selectable::selected(!selectable::selected());
				return true;
			}
			return false;
		}
	};
}

std::shared_ptr<simple::toggle> toggle() {
	return std::make_shared<simple::toggle>();
}

std::shared_ptr<simple::toggle> toggle(std::string name) {
	return std::make_shared<simple::toggle>(std::move(name));
}

#endif // !_TOGGLE_