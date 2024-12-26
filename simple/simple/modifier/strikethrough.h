#ifndef _STRIKETHROUGH_
#define _STRIKETHROUGH_

#include "modifier.h"

namespace simple {
	class strikethrough final : public modifier {
	public:
		strikethrough(std::shared_ptr<renderable> element) :
			modifier(std::move(element)) {
		}

		void render(canvas& canvas) override {
			modifier::render(canvas);

			for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(y, x).strikethrough = true;
				}
			}
		}
	};
}

std::shared_ptr<simple::renderable> strikethrough(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::strikethrough>(std::move(element));
}

#endif // !_STRIKETHROUGH_