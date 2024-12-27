#ifndef _FOCUSABLE_
#define _FOCUSABLE_
#define NOMINMAX

#include <windows.h>

namespace simple {
	/*
	* @brief: a class that can be focused.
	* @note: this class is used to create a focusable component.
	*/
	class focusable {
	public:
		const bool& focused() const {
			return this->focus;
		}
		virtual void focused(bool flag) {
			this->focus = flag;
		}
		virtual bool on_key(const KEY_EVENT_RECORD&) {
			return false;
		}

	private:
		bool focus = false;
	};
}

#endif // !_FOCUSABLE_