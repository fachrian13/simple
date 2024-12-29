#ifndef _HORIZONTAL_FILL_
#define _HORIZONTAL_FILL_

#include "renderable.h"

namespace simple {
	class horizontal_fill final : public renderable {
	public:
		void init() override {
			renderable::horizontal_flex = 1;
		}
	};
}

std::shared_ptr<simple::renderable> hfill() {
	return std::make_shared<simple::horizontal_fill>();
}

#endif // !_HORIZONTAL_FILL_