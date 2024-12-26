#ifndef _HORIZONTAL_CENTER_
#define _HORIZONTAL_CENTER_

#include "horizontal_layout.h"
#include "horizontal_filler.h"

std::shared_ptr<simple::renderable> hcenter(std::shared_ptr<simple::renderable> element) {
	return hlayout(hfiller(), std::move(element), hfiller());
}

#endif // !_HORIZONTAL_CENTER_