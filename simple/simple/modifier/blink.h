#ifndef _BLINK_
#define _BLINK_

#include "modifier.h"

namespace simple {
	class blink final : public modifier {
	public:
		blink(std::shared_ptr<renderable> element) :
			modifier(std::move(element)) {
		}

		void render(canvas& canvas) override {
			modifier::render(canvas);

			for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(y, x).blink = true;
				}
			}
		}
	};
}

std::shared_ptr<simple::renderable> blink(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::blink>(std::move(element));
}

#endif // !_BLINK_