#ifndef _FOREGROUND_
#define _FOREGROUND_

#include "modifier.h"

namespace simple {
	class foreground final : public modifier {
	public:
		foreground(std::shared_ptr<renderable> element, color color) :
			modifier(std::move(element)),
			color(color) {
		}

		void render(canvas& canvas) override {
			modifier::render(canvas);

			for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					if (canvas.at(y, x).foreground == canvas.get_style().foreground) {
						canvas.at(y, x).foreground = this->color;
					}
				}
			}
		}

	private:
		color color;
	};
}

std::shared_ptr<simple::renderable> foreground(std::shared_ptr<simple::renderable> element, simple::color color) {
	return std::make_shared<simple::foreground>(std::move(element), color);
}

std::function<std::shared_ptr<simple::renderable>(std::shared_ptr<simple::renderable>)> foreground(simple::color color) {
	return [color](std::shared_ptr<simple::renderable> element) {
		return foreground(std::move(element), color);
		};
}

#endif // !_FOREGROUND_