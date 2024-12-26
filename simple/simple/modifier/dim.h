#ifndef _DIM_
#define _DIM_

#include "modifier.h"

namespace simple {
	class dim final : public modifier {
	public:
		dim(std::shared_ptr<renderable> element) :
			modifier(std::move(element)) {
		}

		void render(canvas& canvas) override {
			modifier::render(canvas);

			for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(y, x).dim = true;
				}
			}
		}
	};
}

std::shared_ptr<simple::renderable> dim(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::dim>(std::move(element));
}

#endif // !_DIM_