#ifndef _MODIFIER_
#define _MODIFIER_

#include <functional>
#include "../renderable/renderable.h"

namespace simple {
	class modifier : public renderable {
	public:
		modifier(std::shared_ptr<renderable> element) :
			element(std::move(element)) {
		}

		void init() override {
			this->element->init();

			/* copy all element information to this class */
			renderable::height = element->height;
			renderable::width = element->width;
			renderable::vertical_flex = element->vertical_flex;
			renderable::horizontal_flex = element->horizontal_flex;
		}
		void set(rectangle dimension) override {
			this->element->set(dimension);
			renderable::set(dimension);
		}
		void render(canvas& canvas) override {
			this->element->render(canvas);
		}

	protected:
		std::shared_ptr<renderable> element;
	};
}

std::shared_ptr<simple::renderable> operator |(
	std::shared_ptr<simple::renderable> target_element,
	std::function<std::shared_ptr<simple::renderable>(std::shared_ptr<simple::renderable>)> modifier
	) {
	return modifier(std::move(target_element));
}

#endif // !_MODIFIER_