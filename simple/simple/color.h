#ifndef _COLOR_
#define _COLOR_

#include <string>
#include <sstream>

namespace simple {
	enum class palette16 : int {
		black = 30,
		red = 31,
		green = 32,
		yellow = 33,
		blue = 34,
		magenta = 35,
		cyan = 36,
		white = 37,
		default_color = 39,
		reset = 0,
		bright_black = 90,
		bright_red = 91,
		bright_green = 92,
		bright_yellow = 93,
		bright_blue = 94,
		bright_magenta = 95,
		bright_cyan = 96,
		bright_white = 97
	};
	enum class palette256 : int {
		black = 0,
		maroon = 1,
		green = 2,
		olive = 3,
		navy = 4,
		purple = 5,
		teal = 6,
		silver = 7,
		gray = 8,
		red = 9,
		lime = 10,
		yellow = 11,
		blue = 12,
		fuchsia = 13,
		cyan = 14,
		white = 15,
		black2 = 16,
		midnight_blue = 17,
		navy2 = 18,
		medium_blue = 19,
		medium_blue2 = 20,
		blue2 = 21,
		dark_green = 22,
		teal2 = 23,
		steel_blue = 24,
		dark_slate_blue = 25,
		royal_blue = 26,
		medium_slate_blue = 27,
		green2 = 28,
		sea_green = 29,
		teal3 = 30,
		steel_blue2 = 31,
		cornflower_blue = 32,
		dodger_blue = 33,
		lime_green = 34,
		medium_sea_green = 35,
		medium_sea_green2 = 36,
		light_sea_green = 37,
		deep_sky_blue = 38,
		deep_sky_blue2 = 39,
		lime_green2 = 40,
		spring_green = 41,
		medium_spring_green = 42,
		medium_aquamarine = 43,
		dark_turquoise = 44,
		sky_blue = 45,
		lime2 = 46,
		spring_green2 = 47,
		spring_green3 = 48,
		medium_spring_green2 = 49,
		aquamarine = 50,
		cyan2 = 51,
		maroon2 = 52,
		purple2 = 53,
		indigo = 54,
		dark_orchid = 55,
		medium_blue3 = 56,
		blue3 = 57,
		olive2 = 58,
		dim_gray = 59,
		slate_grey = 60,
		dark_slate_blue2 = 61,
		slate_blue = 62,
		medium_slate_blue2 = 63,
		olive_drab = 64,
		dark_olive_green = 65,
		cadet_blue = 66,
		steel_blue3 = 67,
		cornflower_blue2 = 68,
		royal_blue2 = 69,
		yellow_green = 70,
		medium_sea_green3 = 71,
		medium_aquamarine2 = 72,
		cadet_blue2 = 73,
		light_sky_blue = 74,
		cornflower_blue3 = 75,
		lime_green3 = 76,
		lime_green4 = 77,
		light_green = 78,
		medium_aquamarine3 = 79,
		medium_turquoise = 80,
		sky_blue2 = 81,
		chartreuse = 82,
		spring_green4 = 83,
		spring_green5 = 84,
		medium_spring_green3 = 85,
		aquamarine2 = 86,
		cyan3 = 87,
		maroon3 = 88,
		purple3 = 89,
		purple4 = 90,
		dark_orchid2 = 91,
		dark_violet = 92,
		blue4 = 93,
		saddle_brown = 94,
		dim_gray2 = 95,
		slate_grey2 = 96,
		medium_purple = 97,
		slate_blue2 = 98,
		medium_slate_blue3 = 99,
		olive3 = 100,
		dark_olive_green2 = 101,
		gray2 = 102,
		light_slate_gray = 103,
		cornflower_blue4 = 104,
		medium_purple2 = 105,
		yellow_green2 = 106,
		olive_drab2 = 107,
		dark_sea_green = 108,
		cadet_blue3 = 109,
		light_steel_blue = 110,
		cornflower_blue5 = 111,
		green_yellow = 112,
		light_green2 = 113,
		light_green3 = 114,
		medium_aquamarine4 = 115,
		pale_turquoise = 116,
		light_sky_blue2 = 117,
		chartreuse2 = 118,
		lime_green5 = 119,
		pale_green = 120,
		pale_green2 = 121,
		aquamarine3 = 122,
		cyan4 = 123,
		firebrick = 124,
		medium_violet_red = 125,
		medium_violet_red2 = 126,
		dark_magenta = 127,
		dark_violet2 = 128,
		dark_violet3 = 129,
		chocolate = 130,
		indian_red = 131,
		pale_violet_red = 132,
		orchid = 133,
		medium_orchid = 134,
		dark_orchid3 = 135,
		dark_goldenrod = 136,
		tan = 137,
		rosy_brown = 138,
		plum = 139,
		plum2 = 140,
		plum3 = 141,
		medium_purple3 = 141,
		olive4 = 142,
		dark_khaki = 143,
		tan2 = 144,
		dark_grey = 145,
		light_steel_blue2 = 146,
		cornflower_blue6 = 147,
		yellow_green3 = 148,
		yellow_green4 = 149,
		dark_sea_green2 = 150,
		dark_sea_green3 = 151,
		powder_blue = 152,
		light_sky_blue3 = 153,
		green_yellow2 = 154,
		green_yellow3 = 155,
		pale_green3 = 156,
		light_green4 = 157,
		aquamarine4 = 158,
		pale_turquoise2 = 159,
		red2 = 160,
		deep_pink = 161,
		medium_violet_red3 = 162,
		medium_violet_red4 = 163,
		fuchsia2 = 164,
		fuchsia3 = 165,
		chocolate2 = 166,
		indian_red2 = 167,
		pale_violet_red2 = 168,
		hot_pink = 169,
		orchid2 = 170,
		medium_orchid2 = 171,
		dark_goldenrod2 = 172,
		dark_salmon = 173,
		light_coral = 174,
		pale_violet_red3 = 175,
		plum4 = 176,
		violed = 177,
		goldenrod = 178,
		dark_khaki2 = 179,
		tan3 = 180,
		rosy_brown2 = 181,
		thistle = 182,
		plum5 = 183,
		gold = 184,
		khaki = 185,
		khaki2 = 186,
		wheat = 187,
		light_grey = 188,
		lavender = 189,
		yellow2 = 190,
		yellow_green5 = 191,
		pale_green4 = 192,
		pale_goldenrod = 193,
		light_goldenrod_yellow = 194,
		light_cyan = 195,
		red3 = 196,
		crimson = 197,
		deep_pink2 = 198,
		deep_pink3 = 199,
		fuchsia4 = 200,
		fuchsia5 = 201,
		orange_red = 202,
		tomato = 203,
		pale_violet_red4 = 204,
		hot_pink2 = 205,
		orchid3 = 206,
		medium_orchid3 = 207,
		dark_orange = 208,
		coral = 209,
		light_coral2 = 210,
		pale_violed_red = 211,
		hot_pink3 = 212,
		violet = 213,
		orange = 214,
		sandy_brown = 215,
		light_salmon = 216,
		light_pink = 217,
		plum6 = 218,
		plum7 = 219,
		gold2 = 220,
		goldenrod2 = 221,
		khaki3 = 222,
		peach_puff = 223,
		misty_rose = 224,
		thistle2 = 225,
		yellow3 = 226,
		yellow4 = 227,
		khaki4 = 228,
		khaki5 = 229,
		light_goldenrod_yellow2 = 230,
		white2 = 231,
		black3 = 232,
		black4 = 233,
		black5 = 234,
		black6 = 235,
		dark_slate_grey = 236,
		dark_slate_grey2 = 237,
		dark_slate_grey3 = 238,
		dim_gray3 = 239,
		dim_gray4 = 240,
		dim_gray5 = 241,
		dim_gray6 = 242,
		gray3 = 243,
		gray4 = 244,
		gray5 = 245,
		gray6 = 246,
		dark_grey2 = 247,
		dark_grey3 = 248,
		dark_grey4 = 249,
		silver2 = 250,
		silver3 = 251,
		light_grey2 = 252,
		gainsboro = 253,
		gainsboro2 = 254,
		white_smoke = 255
	};

	class color final {
	public:
		color(palette16 color) :
			color_type(type::PALETTE16),
			red(static_cast<int>(color)),
			green(static_cast<int>(color)),
			blue(static_cast<int>(color)) {
		}
		color(palette256 color) :
			color_type(type::PALETTE256),
			red(static_cast<int>(color)),
			green(static_cast<int>(color)),
			blue(static_cast<int>(color)) {
		}
		color(int red, int green, int blue) :
			color_type(type::RGB),
			red(red > -1 && red < 256 ? red : 0),
			green(green > -1 && green < 256 ? green : 0),
			blue(blue > -1 && blue < 256 ? blue : 0) {
		}
		color(const std::string& hex) :
			color_type(type::RGB) {
			if (hex.size() != 7 && hex[0] != '#') {
				return;
			}
			this->red = std::stoi(hex.substr(1, 2), nullptr, 16);
			this->green = std::stoi(hex.substr(3, 2), nullptr, 16);
			this->blue = std::stoi(hex.substr(5, 2), nullptr, 16);
		}
		color(const char* hex) :
			color_type(type::RGB) {
			if (strlen(hex) != 7 && hex[0] != '#') {
				return;
			}

			this->red = std::stoi(std::string(hex + 1, 2), nullptr, 16);
			this->green = std::stoi(std::string(hex + 3, 2), nullptr, 16);
			this->blue = std::stoi(std::string(hex + 5, 2), nullptr, 16);
		}
		void foreground(std::string& str) {
			str += "\x1b[";
			switch (this->color_type) {
			case type::PALETTE16:
				str += std::to_string(this->red);
				break;
			case type::PALETTE256:
				str += "38;5;"
					+ std::to_string(this->red);
				break;
			case type::RGB:
				str += "38;2;"
					+ std::to_string(this->red) + ";"
					+ std::to_string(this->green) + ";"
					+ std::to_string(this->blue);
				break;
			}
			str += "m";
		}
		void foreground(std::ostringstream& ost) {
			ost << "\x1b[";
			switch (this->color_type) {
			case type::PALETTE16:
				ost << this->red;
				break;
			case type::PALETTE256:
				ost << "38;5;"
					<< this->red;
				break;
			case type::RGB:
				ost << "38;2;"
					<< this->red << ";"
					<< this->green << ";"
					<< this->blue;
				break;
			}
			ost << "m";
		}
		std::string foreground() {
			std::string str = "\x1b[";
			switch (this->color_type) {
			case type::PALETTE16:
				str += std::to_string(this->red);
				break;
			case type::PALETTE256:
				str += "38;5;"
					+ std::to_string(this->red);
				break;
			case type::RGB:
				str += "38;2;"
					+ std::to_string(this->red) + ";"
					+ std::to_string(this->green) + ";"
					+ std::to_string(this->blue);
				break;
			}
			str += "m";
			return std::move(str);

			/* versi simple tapi saya lebih memilih yang rumit */
			/*std::string str;
			this->foreground(str);
			return std::move(str);*/
		}
		void background(std::string& str) {
			str += "\x1b[";
			switch (this->color_type) {
			case type::PALETTE16:
				str += std::to_string(this->red + 10);
				break;
			case type::PALETTE256:
				str += "48;5;"
					+ std::to_string(this->red);
				break;
			case type::RGB:
				str += "48;2;"
					+ std::to_string(this->red) + ";"
					+ std::to_string(this->green) + ";"
					+ std::to_string(this->blue);
				break;
			}
			str += "m";
		}
		void background(std::ostringstream& ost) {
			ost << "\x1b[";
			switch (this->color_type) {
			case type::PALETTE16:
				ost << this->red + 10;
				break;
			case type::PALETTE256:
				ost << "48;5;"
					<< this->red;
				break;
			case type::RGB:
				ost << "48;2;"
					<< this->red << ";"
					<< this->green << ";"
					<< this->blue;
				break;
			}
			ost << "m";
		}
		std::string background() {
			std::string str = "\x1b[";
			switch (this->color_type) {
			case type::PALETTE16:
				str += std::to_string(this->red + 10);
				break;
			case type::PALETTE256:
				str += "48;5;"
					+ std::to_string(this->red);
				break;
			case type::RGB:
				str += "48;2;"
					+ std::to_string(this->red) + ";"
					+ std::to_string(this->green) + ";"
					+ std::to_string(this->blue);
				break;
			}
			str += "m";
			return std::move(str);

			/* versi simple tapi saya lebih memilih yang rumit */
			/*std::string str;
			this->background(str);
			return std::move(str);*/
		}
		bool operator ==(const color& other) {
			return
				this->red == other.red &&
				this->green == other.green &&
				this->blue == other.blue;
		}
		bool operator !=(const color& other) {
			return !(*this == other);
		}

	public:
		int red = 0;
		int green = 0;
		int blue = 0;

	private:
		/* used in class only */
		enum class type : int {
			PALETTE16,
			PALETTE256,
			RGB
		};
		type color_type = type::PALETTE16;
	};
}

#endif // !_COLOR_