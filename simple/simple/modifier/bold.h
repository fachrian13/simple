#ifndef _BOLD_
#define _BOLD_

#include "modifier.h"

namespace simple {
	class bold final : public modifier {
	public:
		bold(std::shared_ptr<renderable> element) :
			modifier(std::move(element)) {
		}

		void render(canvas& canvas) override {
			modifier::render(canvas);

			for (int y = renderable::dimension.top; y < renderable::dimension.bottom; ++y) {
				for (int x = renderable::dimension.left; x < renderable::dimension.right; ++x) {
					canvas.at(y, x).bold = true;
				}
			}
		}
	};
}

std::shared_ptr<simple::renderable> bold(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::bold>(std::move(element));
}

#endif // !_BOLD_