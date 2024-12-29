#ifndef _VERTICAL_CENTER_
#define _VERTICAL_CENTER_

#include "vertical_layout.h"
#include "vertical_fill.h"
#include "../modifier/vertical_flex.h"

std::shared_ptr<simple::renderable> vcenter(std::shared_ptr<simple::renderable> element) {
	return vflex(vlayout(vfill(), std::move(element), vfill()));
}

#endif // !_VERTICAL_CENTER_