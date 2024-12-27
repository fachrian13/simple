#ifndef _CANVAS_
#define _CANVAS_

#include <vector>
#include "pixel.h"

namespace simple {
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
		void render(std::string& str) {
			pixel prev;
			for (int y = 0; y < this->height; ++y) {
				if (y > 0) {
					str += "\n";
				}

				for (int x = 0; x < this->width; ++x) {
					pixel& next = this->pixels[y * this->width + x];

					if (prev.bold != next.bold) {
						str += (next.bold ? "\x1b[1m" : "\x1b[22m");
					}
					if (prev.dim != next.dim) {
						str += (next.dim ? "\x1b[2m" : "\x1b[22m");
					}
					if (prev.italic != next.italic) {
						str += (next.italic ? "\x1b[3m" : "\x1b[23m");
					}
					if (prev.underline != next.underline) {
						str += (next.underline ? "\x1b[4m" : "\x1b[24m");
					}
					if (prev.blink != next.blink) {
						str += (next.blink ? "\x1b[5m" : "\x1b[25m");
					}
					if (prev.invert != next.invert) {
						str += (next.invert ? "\x1b[7m" : "\x1b[27m");
					}
					if (prev.invisible != next.invisible) {
						str += (next.invisible ? "\x1b[8m" : "\x1b[28m");
					}
					if (prev.strikethrough != next.strikethrough) {
						str += (next.strikethrough ? "\x1b[9m" : "\x1b[29m");
					}

					if (prev.background != next.background) {
						next.background_color(str);
					}
					if (prev.foreground != next.foreground) {
						next.foreground_color(str);
					}

					str += next.character;

					prev = next;
				}
			}
			str += "\x1b[m";
		}
		void render(std::ostringstream& ost) {
			pixel prev;
			for (int y = 0; y < this->height; ++y) {
				if (y > 0) {
					ost << "\n";
				}

				for (int x = 0; x < this->width; ++x) {
					pixel& next = this->pixels[y * this->width + x];

					if (prev.bold != next.bold) {
						ost << (next.bold ? "\x1b[1m" : "\x1b[22m");
					}
					if (prev.dim != next.dim) {
						ost << (next.dim ? "\x1b[2m" : "\x1b[22m");
					}
					if (prev.italic != next.italic) {
						ost << (next.italic ? "\x1b[3m" : "\x1b[23m");
					}
					if (prev.underline != next.underline) {
						ost << (next.underline ? "\x1b[4m" : "\x1b[24m");
					}
					if (prev.blink != next.blink) {
						ost << (next.blink ? "\x1b[5m" : "\x1b[25m");
					}
					if (prev.invert != next.invert) {
						ost << (next.invert ? "\x1b[7m" : "\x1b[27m");
					}
					if (prev.invisible != next.invisible) {
						ost << (next.invisible ? "\x1b[8m" : "\x1b[28m");
					}
					if (prev.strikethrough != next.strikethrough) {
						ost << (next.strikethrough ? "\x1b[9m" : "\x1b[29m");
					}

					if (prev.background != next.background) {
						next.background_color(ost);
					}
					if (prev.foreground != next.foreground) {
						next.foreground_color(ost);
					}

					ost << next.character;

					prev = next;
				}
			}
			ost << "\x1b[m";
		}
		std::string render() {
			std::string str;
			pixel prev;
			for (int y = 0; y < this->height; ++y) {
				if (y > 0) {
					str += "\n";
				}

				for (int x = 0; x < this->width; ++x) {
					pixel& next = this->pixels[y * this->width + x];

					if (prev.bold != next.bold) {
						str += (next.bold ? "\x1b[1m" : "\x1b[22m");
					}
					if (prev.dim != next.dim) {
						str += (next.dim ? "\x1b[2m" : "\x1b[22m");
					}
					if (prev.italic != next.italic) {
						str += (next.italic ? "\x1b[3m" : "\x1b[23m");
					}
					if (prev.underline != next.underline) {
						str += (next.underline ? "\x1b[4m" : "\x1b[24m");
					}
					if (prev.blink != next.blink) {
						str += (next.blink ? "\x1b[5m" : "\x1b[25m");
					}
					if (prev.invert != next.invert) {
						str += (next.invert ? "\x1b[7m" : "\x1b[27m");
					}
					if (prev.invisible != next.invisible) {
						str += (next.invisible ? "\x1b[8m" : "\x1b[28m");
					}
					if (prev.strikethrough != next.strikethrough) {
						str += (next.strikethrough ? "\x1b[9m" : "\x1b[29m");
					}

					if (prev.background != next.background) {
						next.background_color(str);
					}
					if (prev.foreground != next.foreground) {
						next.foreground_color(str);
					}

					str += next.character;

					prev = next;
				}
			}
			str += "\x1b[m";
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