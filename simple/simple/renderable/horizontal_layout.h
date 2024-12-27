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
			this->total_horizontal_flex = 0;
			for (const auto& element : this->elements) {
				element->init();
				renderable::width += element->width;
				renderable::height = std::max(renderable::height, element->height);
				this->total_horizontal_flex += element->horizontal_flex;
			}
		}
		void set(rectangle dimension) override {
			renderable::set(dimension);
			
			// calculate horizontal space and remaining space for each element
			int hspace =
				(renderable::dimension.right - renderable::dimension.left - renderable::width) /
				(this->total_horizontal_flex == 0 ? 1 : this->total_horizontal_flex);
			int remaining_space =
				(renderable::dimension.right - renderable::dimension.left - renderable::width) %
				(this->total_horizontal_flex == 0 ? 1 : this->total_horizontal_flex);

			for (const auto& element : this->elements) {
				if (element->horizontal_flex == 1) {
					dimension.right = dimension.left + element->width + hspace;
					if (remaining_space > 0) {
						++dimension.right;
						--remaining_space;
					}
				}
				else {
					dimension.right = dimension.left + element->width;
				}

				if (element->vertical_flex == 1) {
					dimension.bottom = renderable::dimension.bottom;
				}
				else {
					dimension.bottom = dimension.top + element->height;
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
		int total_horizontal_flex = 0;
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