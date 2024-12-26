#ifndef _INVERT_
#define _INVERT_

#include "modifier.h"

namespace simple {
	class invert final : public modifier {
	public:
		invert(std::shared_ptr<renderable> element) :
			modifier(std::move(element)) {
		}

		void render(canvas& canvas) override {
			modifier::render(canvas);

			for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(y, x).invert = true;
				}
			}
		}
	};
}

std::shared_ptr<simple::renderable> invert(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::invert>(std::move(element));
}

#endif // !_INVERT_