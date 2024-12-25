#ifndef _TEXT_
#define _TEXT_

#include "renderable.h"

namespace simple {
	class text final : public renderable {
	public:
		text(std::string value) :
			value(std::move(value)) {
		}

		void init() override {
			renderable::height = 1;
			renderable::width = static_cast<int>(this->value.size());
		}
		void render(canvas& canvas) override {
			int x = renderable::dimension.left;

			for (const auto& i : this->value) {
				if (i == '\n') {
					continue;
				}
				canvas.at(renderable::dimension.top, x).character = i;
				++x;
			}
		}

	private:
		std::string value;
	};
}

std::shared_ptr<simple::renderable> text(std::string value) {
	return std::make_shared<simple::text>(std::move(value));
}

#endif