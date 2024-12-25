#ifndef _RENDERABLE_
#define _RENDERABLE_

#include "../canvas.h"

namespace simple {
	class rectangle final {
	public:
		int left = 0;
		int top = 0;
		int right = 0;
		int bottom = 0;
	};

	class renderable {
	public:
		virtual void init() {
			this->height = 0;
			this->width = 0;
			this->vertical_flex = 0;
			this->horizontal_flex = 0;
		}
		virtual void set(rectangle dimension) {
			this->dimension = dimension;
		}
		virtual void render(canvas&) {
			/* implemented later in children or element */
		}

	public:
		int height = 0;
		int width = 0;
		int vertical_flex = 0;
		int horizontal_flex = 0;
		rectangle dimension;
	};
}

#endif // !_RENDERABLE_