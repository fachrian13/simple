#ifndef _HORIZONTAL_FLEX_
#define _HORIZONTAL_FLEX_

#include "modifier.h"

namespace simple {
	class horizontal_flex : public modifier {
	public:
		horizontal_flex(std::shared_ptr<renderable> renderable) :
			modifier(renderable) {
		}

		void init() override {
			modifier::init();
			modifier::element->horizontal_flex = 1;
			renderable::horizontal_flex = 1;
		}
	};
}

std::shared_ptr<simple::renderable> hflex(std::shared_ptr<simple::renderable> renderable) {
	return std::make_shared<simple::horizontal_flex>(std::move(renderable));
}

#endif // !_HORIZONTAL_FLEX_