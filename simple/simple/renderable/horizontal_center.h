#ifndef _HORIZONTAL_CENTER_
#define _HORIZONTAL_CENTER_

#include "horizontal_layout.h"
#include "horizontal_fill.h"
#include "../modifier/horizontal_flex.h"

std::shared_ptr<simple::renderable> hcenter(std::shared_ptr<simple::renderable> element) {
	return hflex(hlayout(hfill(), std::move(element), hfill()));
}

#endif // !_HORIZONTAL_CENTER_