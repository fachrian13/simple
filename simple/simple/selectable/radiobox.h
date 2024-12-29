#ifndef _RADIOBOX_
#define _RADIOBOX_

#include "selectable.h"
#include "../renderable/renderable.h"
#include "../focusable/focusable.h"

namespace simple {
	class radiobox final : public selectable, public focusable, public renderable {
	public:
		radiobox() = default;
		radiobox(std::string name) :
			selectable(std::move(name)) {
		}

		void init() override {
			this->height = 1;
			this->width = static_cast<int>(selectable::name.size()) + 3;
		}
		void render(canvas& canvas) override {
			// render ()
			canvas.at(renderable::dimension.top, renderable::dimension.left).character = '(';
			canvas.at(renderable::dimension.top, renderable::dimension.left + 2).character = ')';

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
				canvas.at(renderable::dimension.top, renderable::dimension.left + 1).character = u8"●";
			}
		}

		bool on_key(const KEY_EVENT_RECORD& keyEvent) override {
			if (keyEvent.wVirtualKeyCode == VK_RETURN || keyEvent.uChar.AsciiChar == ' ') {
				if (selectable::group) {
					selectable::group->clear();
				}
				selectable::selected(true);
				return true;
			}
			return false;
		}
	};
}

std::shared_ptr<simple::radiobox> radiobox() {
	return std::make_shared<simple::radiobox>();
}

std::shared_ptr<simple::radiobox> radiobox(std::string name) {
	return std::make_shared<simple::radiobox>(std::move(name));
}

#endif // !_RADIOBOX_