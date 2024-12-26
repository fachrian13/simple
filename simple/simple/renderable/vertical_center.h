#ifndef _VERTICAL_CENTER_
#define _VERTICAL_CENTER_

#include "vertical_layout.h"
#include "vertical_filler.h"

std::shared_ptr<simple::renderable> vcenter(std::shared_ptr<simple::renderable> element) {
	return vlayout(vfiller(), std::move(element), vfiller());
}

#endif // !_VERTICAL_CENTER_