#ifndef _BORDER_
#define _BORDER_

#include "modifier.h"

namespace simple {
	class border_style final {
	public:
		class alignment final {
		public:
			std::string left;
			std::string middle;
			std::string right;
		};

		std::string horizontal;
		std::string vertical;
		alignment top;
		alignment middle;
		alignment bottom;
	};

	class border final : public modifier {
	public:
		border(std::shared_ptr<renderable> element) :
			modifier(std::move(element)) {
		}
		border(std::shared_ptr<renderable> element, border_style style) :
			modifier(std::move(element)),
			style(style) {
		}

		void init() override {
			modifier::init();

			renderable::height += 2;
			renderable::width += 2;
		}
		void set(rectangle dimension) override {
			modifier::element->set(
				{
					dimension.left + 1,
					dimension.top + 1,
					dimension.right - 1,
					dimension.bottom - 1
				}
			);

			renderable::set(dimension);
		}
		void render(canvas& canvas) override {
			modifier::render(canvas);

			// render every corner
			canvas.at(renderable::dimension.top, renderable::dimension.left).character = this->style.top.left;
			canvas.at(renderable::dimension.top, renderable::dimension.right - 1).character = this->style.top.right;
			canvas.at(renderable::dimension.bottom - 1, renderable::dimension.left).character = this->style.bottom.left;
			canvas.at(renderable::dimension.bottom - 1, renderable::dimension.right - 1).character = this->style.bottom.right;

			// render vertical line
			for (int y = renderable::dimension.top + 1; y < renderable::dimension.bottom - 1; ++y) {
				canvas.at(y, renderable::dimension.left).character = this->style.vertical;
				canvas.at(y, renderable::dimension.right - 1).character = this->style.vertical;
			}

			// render horizontal line
			for (int x = renderable::dimension.left + 1; x < renderable::dimension.right - 1; ++x) {
				canvas.at(renderable::dimension.top, x).character = this->style.horizontal;
				canvas.at(renderable::dimension.bottom - 1, x).character = this->style.horizontal;
			}
		}

	private:
		border_style style = {
			"-", "|",
			{"+", "+", "+"},
			{"+", "+", "+"},
			{"+", "+", "+"}
		};
	};
}

static const simple::border_style ascii = {
	"-", "|",
	{"+", "+", "+"},
	{"+", "+", "+"},
	{"+", "+", "+"}
};
static const simple::border_style line = {
	u8"━", u8"┃",
	{u8"┏", u8"┳", u8"┓"},
	{u8"┣", u8"╋", u8"┫"},
	{u8"┗", u8"┻", u8"┛"}
};
static const simple::border_style double_line = {
	u8"═", u8"║",
	{u8"╔", u8"╦", u8"╗"},
	{u8"╠", u8"╬", u8"╣"},
	{u8"╚", u8"╩", u8"╝"}
};
static const simple::border_style none = {
	" ", " ",
	{" ", " ", " "},
	{" ", " ", " "},
	{" ", " ", " "}
};
static const simple::border_style rounded = {
	u8"─", u8"│",
	{u8"╭", u8"─", u8"╮"},
	{u8"│", u8"┼", u8"│"},
	{u8"╰", u8"─", u8"╯"}
};
static const simple::border_style dashed = {
	u8"╌", u8"╎",
	{u8"┌", u8"╌", u8"┐"},
	{u8"╎", u8"┼", u8"╎"},
	{u8"└", u8"╌", u8"┘"}
};

std::shared_ptr<simple::renderable> border(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::border>(std::move(element));
}

std::shared_ptr<simple::renderable> border_ascii(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::border>(std::move(element), ascii);
}

std::shared_ptr<simple::renderable> border_line(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::border>(std::move(element), line);
}

std::shared_ptr<simple::renderable> border_double_line(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::border>(std::move(element), double_line);
}

std::shared_ptr<simple::renderable> border_none(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::border>(std::move(element), none);
}

std::shared_ptr<simple::renderable> border_rounded(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::border>(std::move(element), rounded);
}

std::shared_ptr<simple::renderable> border_dashed(std::shared_ptr<simple::renderable> element) {
	return std::make_shared<simple::border>(std::move(element), dashed);
}

std::shared_ptr<simple::renderable> border_style(std::shared_ptr<simple::renderable> element, simple::border_style style) {
	return std::make_shared<simple::border>(std::move(element), style);
}

std::function<std::shared_ptr<simple::renderable>(std::shared_ptr<simple::renderable>)> border_style(simple::border_style style) {
	return [style](std::shared_ptr<simple::renderable> element) {
		return border_style(std::move(element), style);
		};
}

#endif // !_BORDER_