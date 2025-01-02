#ifndef _CANVAS_
#define _CANVAS_

#include <vector>
#include "pixel.h"

namespace simple {
	class rectangle final {
	public:
		int left = 0;
		int top = 0;
		int right = 0;
		int bottom = 0;
	};

	class canvas final {
	public:
		canvas(int height, int width) :
			height(height),
			width(width),
			pixels(height* width) {
		}
		canvas(int height, int width, pixel style) :
			height(height),
			width(width),
			style(style),
			pixels(height* width, style) {
		}
		pixel& at(size_t y, size_t x) {
			static pixel dummy;
			if (y >= this->height || x >= this->width) {
				return dummy;
			}

			return this->pixels[y * this->width + x];
		}
		const int& get_height() {
			return this->height;
		}
		const int& get_width() {
			return this->width;
		}
		const pixel& get_style() {
			return this->style;
		}
		void clear() {
			std::fill(this->pixels.begin(), this->pixels.end(), this->style);
		}
		void clear_area(const rectangle& dimension) {
			for (int y = dimension.top; y < dimension.bottom; ++y) {
				for (int x = dimension.left; x < dimension.right; ++x) {
					this->pixels[y * this->width + x] = this->style;
				}
			}
		}
		void render(std::string& str) {
			pixel prev;
			for (int y = 0; y < this->height; ++y) {
				if (y > 0) {
					str.append("\n");
				}

				for (int x = 0; x < this->width; ++x) {
					pixel& next = this->pixels[y * this->width + x];

					if (prev.bold != next.bold) {
						str.append(next.bold ? "\x1b[1m" : "\x1b[22m");
					}
					if (prev.dim != next.dim) {
						str.append(next.dim ? "\x1b[2m" : "\x1b[22m");
					}
					if (prev.italic != next.italic) {
						str.append(next.italic ? "\x1b[3m" : "\x1b[23m");
					}
					if (prev.underline != next.underline) {
						str.append(next.underline ? "\x1b[4m" : "\x1b[24m");
					}
					if (prev.blink != next.blink) {
						str.append(next.blink ? "\x1b[5m" : "\x1b[25m");
					}
					if (prev.invert != next.invert) {
						str.append(next.invert ? "\x1b[7m" : "\x1b[27m");
					}
					if (prev.invisible != next.invisible) {
						str.append(next.invisible ? "\x1b[8m" : "\x1b[28m");
					}
					if (prev.strikethrough != next.strikethrough) {
						str.append(next.strikethrough ? "\x1b[9m" : "\x1b[29m");
					}

					if (prev.background != next.background) {
						next.background_color(str);
					}
					if (prev.foreground != next.foreground) {
						next.foreground_color(str);
					}

					str.append(next.character);
					prev = next;
				}
			}
			str.append("\x1b[m");
		}
		void render(std::ostringstream& ost) {
			pixel prev;
			for (int y = 0; y < this->height; ++y) {
				if (y > 0) {
					ost.str("\n");
				}

				for (int x = 0; x < this->width; ++x) {
					pixel& next = this->pixels[y * this->width + x];

					if (prev.bold != next.bold) {
						ost.str(next.bold ? "\x1b[1m" : "\x1b[22m");
					}
					if (prev.dim != next.dim) {
						ost.str(next.dim ? "\x1b[2m" : "\x1b[22m");
					}
					if (prev.italic != next.italic) {
						ost.str(next.italic ? "\x1b[3m" : "\x1b[23m");
					}
					if (prev.underline != next.underline) {
						ost.str(next.underline ? "\x1b[4m" : "\x1b[24m");
					}
					if (prev.blink != next.blink) {
						ost.str(next.blink ? "\x1b[5m" : "\x1b[25m");
					}
					if (prev.invert != next.invert) {
						ost.str(next.invert ? "\x1b[7m" : "\x1b[27m");
					}
					if (prev.invisible != next.invisible) {
						ost.str(next.invisible ? "\x1b[8m" : "\x1b[28m");
					}
					if (prev.strikethrough != next.strikethrough) {
						ost.str(next.strikethrough ? "\x1b[9m" : "\x1b[29m");
					}

					if (prev.background != next.background) {
						next.background_color(ost);
					}
					if (prev.foreground != next.foreground) {
						next.foreground_color(ost);
					}

					ost.str(next.character);
					prev = next;
				}
			}
			ost.str("\x1b[m");
		}
		std::string render() {
			std::string str;
			pixel prev;
			for (int y = 0; y < this->height; ++y) {
				if (y > 0) {
					str.append("\n");
				}

				for (int x = 0; x < this->width; ++x) {
					pixel& next = this->pixels[y * this->width + x];

					if (prev.bold != next.bold) {
						str.append(next.bold ? "\x1b[1m" : "\x1b[22m");
					}
					if (prev.dim != next.dim) {
						str.append(next.dim ? "\x1b[2m" : "\x1b[22m");
					}
					if (prev.italic != next.italic) {
						str.append(next.italic ? "\x1b[3m" : "\x1b[23m");
					}
					if (prev.underline != next.underline) {
						str.append(next.underline ? "\x1b[4m" : "\x1b[24m");
					}
					if (prev.blink != next.blink) {
						str.append(next.blink ? "\x1b[5m" : "\x1b[25m");
					}
					if (prev.invert != next.invert) {
						str.append(next.invert ? "\x1b[7m" : "\x1b[27m");
					}
					if (prev.invisible != next.invisible) {
						str.append(next.invisible ? "\x1b[8m" : "\x1b[28m");
					}
					if (prev.strikethrough != next.strikethrough) {
						str.append(next.strikethrough ? "\x1b[9m" : "\x1b[29m");
					}

					if (prev.background != next.background) {
						next.background_color(str);
					}
					if (prev.foreground != next.foreground) {
						next.foreground_color(str);
					}

					str.append(next.character);
					prev = next;
				}
			}
			str.append("\x1b[m");
			return std::move(str);

			// simple version but I prefer the complicated one
			/*
			* std::string str;
			* this->render(str);
			* return std::move(str);
			*/
		}

	private:
		int height = 0;
		int width = 0;
		pixel style;
		std::vector<pixel> pixels;
	};
}

#endif // !_CANVAS_