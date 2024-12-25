#ifndef _HORIZONTAL_LAYOUT_
#define _HORIZONTAL_LAYOUT_

#include "renderable.h"

namespace simple {
	class horizontal_layout final : public renderable {
	public:
		horizontal_layout(std::vector<std::shared_ptr<renderable>> elements) :
			elements(std::move(elements)) {
		}

		void init() override {
			renderable::init();
			for (const auto& element : this->elements) {
				element->init();
				renderable::width += element->width;
				renderable::height = std::max(renderable::height, element->height);
				renderable::horizontal_flex += element->horizontal_flex;
			}
		}
		void set(rectangle dimension) override {
			renderable::set(dimension);

			/*
			* calculate extra space for horizontal flex
			*/
			int hspace =
				(renderable::dimension.right - renderable::dimension.left - renderable::width) /
				(renderable::horizontal_flex == 0 ? 1 : renderable::horizontal_flex);

			for (const auto& element : this->elements) {
				if (element->horizontal_flex == 1) {
					dimension.right = dimension.left + element->width + hspace;
				}
				else {
					dimension.right = dimension.left + element->width;
				}

				element->set(dimension);

				dimension.left = dimension.right;
			}
		}
		void render(canvas& canvas) override {
			for (const auto& element : this->elements) {
				element->render(canvas);
			}
		}

	private:
		std::vector<std::shared_ptr<renderable>> elements;
	};
}

template<typename... T>
std::shared_ptr<simple::renderable> hlayout(T&&... elements) {
	return std::make_shared<simple::horizontal_layout>(
		std::vector<std::shared_ptr<simple::renderable>>{
			std::forward<T>(elements)...
		}
	);
}

#endif // !_HORIZONTAL_LAYOUT_