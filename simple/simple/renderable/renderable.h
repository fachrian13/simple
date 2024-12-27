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

	/*
	* @brief: renderable class is the base
	* @note: this class is used to create a renderable object
	*/
	class renderable {
	public:
		/*
		* @brief: init function is used to initialize the renderable object
		* @note: this function is called before rendering the object
		*/
		virtual void init() {
			this->height = 0;
			this->width = 0;
			this->vertical_flex = 0;
			this->horizontal_flex = 0;
		}
		/*
		* @brief: set function is used to set the dimension of the renderable object
		* @param: dimension is the dimension of the renderable object
		* @note: this function is called before rendering the object
		*/
		virtual void set(rectangle dimension) {
			this->dimension = dimension;
		}
		/*
		* @brief: render function is used to render the renderable object
		* @param: canvas is the canvas object
		* @note: this function is called after the object is initialized and the dimension is set
		*/
		virtual void render(canvas&) {
			// implement this function in the derived class
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