#ifndef _HORIZONTAL_SPACE_
#define _HORIZONTAL_SPACE_

#include "renderable.h"

namespace simple {
	class horizontal_space final : public renderable {
	public:
		horizontal_space() = default;
		horizontal_space(int width) :
			width(width) {
		}

		void init() override {
			renderable::width = this->width;
		}

	private:
		int width = 1;
	};
}

std::shared_ptr<simple::renderable> hspace() {
	return std::make_shared<simple::horizontal_space>();
}

std::shared_ptr<simple::renderable> hspace(int width) {
	return std::make_shared<simple::horizontal_space>(width);
}

#endif // !_HORIZONTAL_SPACE_