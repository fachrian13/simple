#ifndef _VERTICAL_FILL_
#define _VERTICAL_FILL_

#include "renderable.h"

namespace simple {
	class vertical_fill final : public renderable {
	public:
		void init() override {
			renderable::vertical_flex = 1;
		}
	};
}

std::shared_ptr<simple::renderable> vfill() {
	return std::make_shared<simple::vertical_fill>();
}

#endif // !_VERTICAL_FILL_