#ifndef _VERTICAL_FLEX_
#define _VERTICAL_FLEX_

#include "modifier.h"

namespace simple {
	class vertical_flex : public modifier {
	public:
		vertical_flex(std::shared_ptr<renderable> renderable) :
			modifier(renderable) {
		}

		void init() override {
			modifier::init();
			modifier::element->vertical_flex = 1;
			renderable::vertical_flex = 1;
		}
	};
}

std::shared_ptr<simple::renderable> vflex(std::shared_ptr<simple::renderable> renderable) {
	return std::make_shared<simple::vertical_flex>(std::move(renderable));
}

#endif // !_VERTICAL_FLEX_