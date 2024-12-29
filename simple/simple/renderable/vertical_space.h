#ifndef _VERTICAL_SPACE_
#define _VERTICAL_SPACE_

#include "renderable.h"

namespace simple {
	class vertical_space final : public renderable {
	public:
		vertical_space() = default;
		vertical_space(int height) :
			height(height) {
		}

		void init() override {
			renderable::height = this->height;
		}

	private:
		int height = 1;
	};
}

std::shared_ptr<simple::renderable> vspace() {
	return std::make_shared<simple::vertical_space>();
}

std::shared_ptr<simple::renderable> vspace(int height) {
	return std::make_shared<simple::vertical_space>(height);
}

#endif // !_VERTICAL_SPACE_