#ifndef _BACKGROUND_
#define _BACKGROUND_

#include "modifier.h"

namespace simple {
	class background final : public modifier {
	public:
		background(std::shared_ptr<renderable> element, color color) :
			modifier(std::move(element)),
			color(color) {
		}

		void render(canvas& canvas) override {
			modifier::render(canvas);

			for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					if (canvas.at(y, x).background == canvas.get_style().background) {
						canvas.at(y, x).background = this->color;
					}
				}
			}
		}

	private:
		color color;
	};
}

std::shared_ptr<simple::renderable> background(std::shared_ptr<simple::renderable> element, simple::color color) {
	return std::make_shared<simple::background>(std::move(element), color);
}

std::function<std::shared_ptr<simple::renderable>(std::shared_ptr<simple::renderable>)> background(simple::color color) {
	return [color](std::shared_ptr<simple::renderable> element) {
		return background(std::move(element), color);
		};
}

#endif // !_BACKGROUND_