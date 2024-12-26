#ifndef _INVISIBLE_
#define _INVISIBLE_

#include "modifier.h"

namespace simple {
	class invisible final : public modifier {
	public:
		invisible(std::shared_ptr<renderable> element) :
			modifier(std::move(element)) {
		}

		void render(canvas& canvas) override {
			modifier::render(canvas);

			for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(y, x).invisible = true;
				}
			}
		}
	};
}

std::shared_ptr<simple::renderable> invisible(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::invisible>(std::move(element));
}

#endif // !_INVISIBLE_