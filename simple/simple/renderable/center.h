#ifndef _CENTER_
#define _CENTER_

#include "horizontal_center.h"
#include "vertical_center.h"

std::shared_ptr<simple::renderable> center(std::shared_ptr<simple::renderable> element) {
	return vcenter(hcenter(std::move(element)));
}

#endif // !_CENTER_