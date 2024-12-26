#ifndef _ITALIC_
#define _ITALIC_

#include "modifier.h"

namespace simple {
	class italic final : public modifier {
	public:
		italic(std::shared_ptr<renderable> element) :
			modifier(std::move(element)) {
		}

		void render(canvas& canvas) override {
			modifier::render(canvas);

			for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(y, x).italic = true;
				}
			}
		}
	};
}

std::shared_ptr<simple::renderable> italic(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::italic>(std::move(element));
}

#endif // !_ITALIC_