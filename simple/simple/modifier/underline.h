#ifndef _UNDERLINE_
#define _UNDERLINE_

#include "modifier.h"

namespace simple {
	class underline final : public modifier {
	public:
		underline(std::shared_ptr<renderable> element) :
			modifier(std::move(element)) {
		}

		void render(canvas& canvas) override {
			modifier::render(canvas);

			for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(y, x).underline = true;
				}
			}
		}
	};
}

std::shared_ptr<simple::renderable> underline(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::underline>(std::move(element));
}

#endif // !_UNDERLINE_