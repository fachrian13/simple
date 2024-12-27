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
			this->total_vertical_flex = 0;
			for (const auto& element : this->elements) {
				element->init();
				renderable::height += element->height;
				renderable::width = std::max(renderable::width, element->width);
				this->total_vertical_flex += element->vertical_flex;
			}
		}
		void set(rectangle dimension) override {
			renderable::set(dimension);

			// calculate vertical space and remaining space for each element
			int vspace =
				(renderable::dimension.bottom - renderable::dimension.top - renderable::height) /
				(this->total_vertical_flex == 0 ? 1 : this->total_vertical_flex);
			int remaining_space =
				(renderable::dimension.bottom - renderable::dimension.top - renderable::height) %
				(this->total_vertical_flex == 0 ? 1 : this->total_vertical_flex);

			for (const auto& element : this->elements) {
				if (element->vertical_flex == 1) {
					dimension.bottom = dimension.top + element->height + vspace;
					if (remaining_space > 0) {
						++dimension.bottom;
						--remaining_space;
					}
				}
				else {
					dimension.bottom = dimension.top + element->height;
				}

				if (element->horizontal_flex == 1) {
					dimension.right = renderable::dimension.right;
				}
				else {
					dimension.right = dimension.left + element->width;
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
		int total_vertical_flex = 0;
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