#ifndef _FLEX_
#define _FLEX_

#include "modifier.h"

namespace simple {
	class flex : public modifier {
	public:
		flex(std::shared_ptr<renderable> renderable) :
			modifier(renderable) {
		}

		void init() override {
			modifier::init();
			modifier::element->vertical_flex = 1;
			modifier::element->horizontal_flex = 1;
			renderable::vertical_flex = 1;
			renderable::horizontal_flex = 1;
		}
	};
}

std::shared_ptr<simple::renderable> flex(std::shared_ptr<simple::renderable> renderable) {
	return std::make_shared<simple::flex>(std::move(renderable));
}

#endif // !_FLEX_