#ifndef _HORIZONTAL_FILLER_
#define _HORIZONTAL_FILLER_

#include "renderable.h"

namespace simple {
	class horizontal_filler final : public renderable {
	public:
		void init() override {
			renderable::horizontal_flex = 1;
		}
	};
}

std::shared_ptr<simple::renderable> hfiller() {
	return std::make_shared<simple::horizontal_filler>();
}

#endif // !_HORIZONTAL_FILLER_