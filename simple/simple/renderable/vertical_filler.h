#ifndef _VERTICAL_FILLER_
#define _VERTICAL_FILLER_

#include "renderable.h"

namespace simple {
	class vertical_filler final : public renderable {
	public:
		void init() override {
			renderable::vertical_flex = 1;
		}
	};
}

std::shared_ptr<simple::renderable> vfiller() {
	return std::make_shared<simple::vertical_filler>();
}

#endif // !_VERTICAL_FILLER_