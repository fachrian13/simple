#ifndef _CHECKBOX_
#define _CHECKBOX_

#include "selectable.h"
#include "../renderable/renderable.h"
#include "../focusable/focusable.h"

namespace simple {
	class checkbox final : public selectable, public focusable, public renderable {
	public:
		checkbox() = default;
		checkbox(std::string name) :
			selectable(std::move(name)) {
		}

		void init() override {
			this->height = 1;
			this->width = static_cast<int>(selectable::name.size()) + 3;
		}
		void render(canvas& canvas) override {
			// render []
			canvas.at(renderable::dimension.top, renderable::dimension.left).character = '[';
			canvas.at(renderable::dimension.top, renderable::dimension.left + 2).character = ']';

			// render name
			if (!selectable::name.empty()) {
				int x = renderable::dimension.left + 3;
				for (const auto& i : selectable::name) {
					canvas.at(renderable::dimension.top, x++).character = i;
				}
			}

			// if focused
			if (focusable::focused()) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(renderable::dimension.top, x).invert = true;
				}
			}

			// if selected
			if (selectable::selected()) {
				canvas.at(renderable::dimension.top, renderable::dimension.left + 1).character = u8"■";
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

std::shared_ptr<simple::checkbox> checkbox() {
	return std::make_shared<simple::checkbox>();
}

std::shared_ptr<simple::checkbox> checkbox(std::string name) {
	return std::make_shared<simple::checkbox>(std::move(name));
}

#endif // !_CHECKBOX_