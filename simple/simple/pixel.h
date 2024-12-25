#ifndef _PIXEL_
#define _PIXEL_

#include "color.h"

namespace simple {
	class pixel final {
	public:
		pixel() = default;
		pixel(color foreground, color background) :
			foreground(foreground),
			background(background) {
		}
		pixel(color foreground, color background, std::string character) :
			foreground(foreground),
			background(background),
			character(std::move(character)) {
		}
		void foreground_color(std::string& str) {
			this->foreground.foreground(str);
		}
		void foreground_color(std::ostringstream& ost) {
			this->foreground.foreground(ost);
		}
		std::string foreground_color() {
			return this->foreground.foreground();
		}
		void background_color(std::string& str) {
			this->background.background(str);
		}
		void background_color(std::ostringstream& ost) {
			this->background.background(ost);
		}
		std::string background_color() {
			return this->background.background();
		}
		bool operator==(const pixel& other) {
			return
				this->bold == other.bold &&
				this->dim == other.dim &&
				this->italic == other.italic &&
				this->underline == other.underline &&
				this->blink == other.blink &&
				this->invert == other.invert &&
				this->invisible == other.invisible &&
				this->strikethrough == other.strikethrough &&
				this->foreground == other.foreground &&
				this->background == other.background &&
				this->character == other.character;
		}
		bool operator !=(const pixel& other) {
			return !(*this == other);
		}

	public:
		bool bold = false;
		bool dim = false;
		bool italic = false;
		bool underline = false;
		bool blink = false;
		bool invert = false;
		bool invisible = false;
		bool strikethrough = false;

		color background = palette16::default_color;
		color foreground = palette16::default_color;

		std::string character = " ";
	};
}

#endif // !_PIXEL_