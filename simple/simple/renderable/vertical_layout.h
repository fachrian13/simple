#ifndef _VERTICAL_LAYOUT_
#define _VERTICAL_LAYOUT_

#include "renderable.h"

namespace simple {
	class vertical_layout final : public renderable {
	public:
		vertical_layout(std::vector<std::shared_ptr<renderable>> elements) :
			elements(std::move(elements)) {
		}

		void init() override {
			renderable::init();
			for (const auto& element : this->elements) {
				element->init();
				renderable::height += element->height;
				renderable::width = std::max(renderable::width, element->width);
				renderable::vertical_flex += element->vertical_flex;
			}
		}
		void set(rectangle dimension) override {
			renderable::set(dimension);

			/*
			* calculate extra space for vertical flex
			*/
			int vspace =
				(renderable::dimension.bottom - renderable::dimension.top - renderable::height) /
				(renderable::vertical_flex == 0 ? 1 : renderable::vertical_flex);

			for (const auto& element : this->elements) {
				if (element->vertical_flex == 1) {
					dimension.bottom = dimension.top + element->height + vspace;
				}
				else {
					dimension.bottom = dimension.top + element->height;
				}

				element->set(dimension);

				dimension.top = dimension.bottom;
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
std::shared_ptr<simple::renderable> vlayout(T&&... elements) {
	return std::make_shared<simple::vertical_layout>(
		std::vector<std::shared_ptr<simple::renderable>>{
			std::forward<T>(elements)...
		}
	);
}

#endif // !_VERTICAL_LAYOUT_