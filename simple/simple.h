#ifndef _SIMPLE_
#define _SIMPLE_

#include <string>
#include <sstream>
#include <vector>

namespace Simple {
	enum class Palette16 : unsigned {
		Black = 30,
		Red = 31,
		Green = 32,
		Yellow = 33,
		Blue = 34,
		Magenta = 35,
		Cyan = 36,
		White = 37,
		Default = 39,
		Reset = 0,
		BrightBlack = 90,
		BrightRed = 91,
		BrightGreen = 92,
		BrightYellow = 93,
		BrightBlue = 94,
		BrightMagenta = 95,
		BrightCyan = 96,
		BrightWhite = 97
	};
	enum class Palette256 : unsigned {
		Black = 0,
		Maroon = 1,
		Green = 2,
		Olive = 3,
		Navy = 4,
		Purple = 5,
		Teal = 6,
		Silver = 7,
		Gray = 8,
		Red = 9,
		Lime = 10,
		Yellow = 11,
		Blue = 12,
		Fuchsia = 13,
		Cyan = 14,
		White = 15,
		Black2 = 16,
		MidnightBlue = 17,
		Navy2 = 18,
		MediumBlue = 19,
		MediumBlue2 = 20,
		Blue2 = 21,
		DarkGreen = 22,
		Teal2 = 23,
		SteelBlue = 24,
		DarkSlateBlue = 25,
		RoyalBlue = 26,
		MediumSlateBlue = 27,
		Green2 = 28,
		SeaGreen = 29,
		Teal3 = 30,
		SteelBlue2 = 31,
		CornFlowerBlue = 32,
		DodgerBlue = 33,
		LimeGreen = 34,
		MediumSeaGreen = 35,
		MediumSeaGreen2 = 36,
		LightSeaGreen = 37,
		DeepSkyBlue = 38,
		DeepSkyBlue2 = 39,
		LimeGreen2 = 40,
		SpringGreen = 41,
		MediumSpringGreen = 42,
		MediumAquamarine = 43,
		DarkTurquoise = 44,
		SkyBlue = 45,
		Lime2 = 46,
		SpringGreen2 = 47,
		SpringGreen3 = 48,
		MediumSpringGreen2 = 49,
		Aquamarine = 50,
		Cyan2 = 51,
		Maroon2 = 52,
		Purple2 = 53,
		Indigo = 54,
		DarkOrchid = 55,
		MediumBLue3 = 56,
		Blue3 = 57,
		Olive2 = 58,
		DimGray = 59,
		SlateGrey = 60,
		DarkSlateBlue2 = 61,
		SlateBlue = 62,
		MediumSlateBlue2 = 63,
		OliveDrab = 64,
		DarkOliveGreen = 65,
		CadetBlue = 66,
		SteelBlue3 = 67,
		CornflowerBlue2 = 68,
		RoyalBlue2 = 69,
		YellowGreen = 70,
		MediumSeaGreen3 = 71,
		MediumAquamarine2 = 72,
		CadetBlue2 = 73,
		LightSkyBlue = 74,
		CornflowerBlue3 = 75,
		LimeGreen3 = 76,
		LimeGreen4 = 77,
		LightGreen = 78,
		MediumAquamarine3 = 79,
		MediumTurquoise = 80,
		SkyBlue2 = 81,
		Chartreuse = 82,
		SpringGreen4 = 83,
		SpringGreen5 = 84,
		MediumSpringGreen3 = 85,
		Aquamarine2 = 86,
		Cyan3 = 87,
		Maroon3 = 88,
		Purple3 = 89,
		Purple4 = 90,
		DarkOrchid2 = 91,
		DarkViolet = 92,
		Blue4 = 93,
		SaddleBrown = 94,
		DimGray2 = 95,
		SlateGrey2 = 96,
		MediumPurple = 97,
		SlateBlue2 = 98,
		MediumSlateBlue3 = 99,
		Olive3 = 100,
		DarkOliveGreen2 = 101,
		Gray2 = 102,
		LightSlateGray = 103,
		CornflowerBlue4 = 104,
		MediumPurple2 = 105,
		YellowGreen2 = 106,
		OliveDrab2 = 107,
		DarkSeaGreen = 108,
		CadetBlue3 = 109,
		LightSteelBlue = 110,
		CornflowerBlue5 = 111,
		GreenYellow = 112,
		LightGreen2 = 113,
		LightGreen3 = 114,
		MediumAquamarine4 = 115,
		PaleTurquoise = 116,
		LightSkyBlue2 = 117,
		Chartreuse2 = 118,
		LimeGreen5 = 119,
		PaleGreen = 120,
		PaleGreen2 = 121,
		Aquamarine3 = 122,
		Cyan4 = 123,
		Firebrick = 124,
		MediumVioletRed = 125,
		MediumVioletRed2 = 126,
		DarkMagenta = 127,
		DarkViolet2 = 128,
		DarkViolet3 = 129,
		Chocolate = 130,
		IndianRed = 131,
		PaleVioletRed = 132,
		Orchid = 133,
		MediumOrchid = 134,
		DarkOrchid3 = 135,
		DarkGoldenrod = 136,
		Tan = 137,
		RosyBrown = 138,
		Plum = 139,
		Plum2 = 140,
		Plum3 = 141,
		MediumPurple3 = 141,
		Olive4 = 142,
		DarkKhkaki = 143,
		Tan2 = 144,
		DarkGrey = 145,
		LightSteelBlue2 = 146,
		CornflowerBlue6 = 147,
		YellowGreen3 = 148,
		YellowGreen4 = 149,
		DarkSeaGreen2 = 150,
		DarkSeaGreen3 = 151,
		PowderBlue = 152,
		LightSkyBlue3 = 153,
		GreenYellow2 = 154,
		GreenYellow3 = 155,
		PaleGreen3 = 156,
		LightGreen4 = 157,
		Aquamarine4 = 158,
		PaleTurquoise2 = 159,
		Red2 = 160,
		DeepPink = 161,
		MediumVioletRed3 = 162,
		MediumVioletRed4 = 163,
		Fuchsia2 = 164,
		Fuchsia3 = 165,
		Chocolate2 = 166,
		IndianRed2 = 167,
		PaleVioletRed2 = 168,
		HotPink = 169,
		Orchid2 = 170,
		MediumOrchid2 = 171,
		DarkGoldernrod = 172,
		DarkSalmon = 173,
		LightCoral = 174,
		PaleVioletRed3 = 175,
		Plum4 = 176,
		Violed = 177,
		Goldenrod = 178,
		DarkKhaki = 179,
		Tan3 = 180,
		RosyBrown2 = 181,
		Thistle = 182,
		Plum5 = 183,
		Gold = 184,
		Khaki = 185,
		Khaki2 = 186,
		Wheat = 187,
		LightGrey = 188,
		Lavender = 189,
		Yellow2 = 190,
		YellowGreen5 = 191,
		PaleGreen4 = 192,
		PaleGoldenrod = 193,
		LightGoldenrodYellow = 194,
		LightCyan = 195,
		Red3 = 196,
		Crimson = 197,
		DeepPink2 = 198,
		DeepPink3 = 199,
		Fuchsia4 = 200,
		Fuchsia5 = 201,
		OrangeRed = 202,
		Tomato = 203,
		PaleVioletRed4 = 204,
		HotPink2 = 205,
		Orchid3 = 206,
		MediumOrchid3 = 207,
		DarkOrange = 208,
		Coral = 209,
		LightCoral2 = 210,
		PaleVioledRed = 211,
		HotPink3 = 212,
		Violet = 213,
		Orange = 214,
		SandyBrown = 215,
		LightSalmon = 216,
		LightPink = 217,
		Plum6 = 218,
		Plum7 = 219,
		Gold2 = 220,
		Goldenrod2 = 221,
		Khaki3 = 222,
		PeachPuff = 223,
		MistyRose = 224,
		Thistle2 = 225,
		Yellow3 = 226,
		Yellow4 = 227,
		Khaki4 = 228,
		Khaki5 = 229,
		LightGoldenrodYellow2 = 230,
		White2 = 231,
		Black3 = 232,
		Black4 = 233,
		Black5 = 234,
		Black6 = 235,
		DarkSlateGrey = 236,
		DarkSlateGrey2 = 237,
		DarkSlateGrey3 = 238,
		DimGray3 = 239,
		DimGray4 = 240,
		DimGray5 = 241,
		DimGray6 = 242,
		Gray3 = 243,
		Gray4 = 244,
		Gray5 = 245,
		Gray6 = 246,
		DarkGrey2 = 247,
		DarkGrey3 = 248,
		DarkGrey4 = 249,
		Silver2 = 250,
		Silver3 = 251,
		LightGrey2 = 252,
		Gainsboro = 253,
		Gainsboro2 = 254,
		WhiteSmoke = 255
	};

	class Color final {
	public:
		Color(Palette16 value) :
			colorType(Type::Palette16),
			Red(static_cast<unsigned>(value)),
			Green(static_cast<unsigned>(value)),
			Blue(static_cast<unsigned>(value)) {
		}
		Color(Palette256 value) :
			colorType(Type::Palette256),
			Red(static_cast<unsigned>(value)),
			Green(static_cast<unsigned>(value)),
			Blue(static_cast<unsigned>(value)) {
		}
		Color(unsigned red, unsigned green, unsigned blue) :
			colorType(Type::RGB),
			Red(red < 256 ? red : 0),
			Green(green < 256 ? green : 0),
			Blue(blue < 256 ? blue : 0) {
		}
		Color(const std::string& hex) :
			colorType(Type::RGB) {
			if (hex.size() != 7 && hex[0] != '#') {
				return;
			}

			this->Red = std::stoi(hex.substr(1, 2), nullptr, 16);
			this->Green = std::stoi(hex.substr(3, 2), nullptr, 16);
			this->Blue = std::stoi(hex.substr(5, 2), nullptr, 16);
		}
		auto Foreground() -> const std::string {
			switch (this->colorType) {
			case Type::Palette16:
				return std::string(
					"\x1b[" +
					std::to_string(this->Red) +
					"m"
				);
			case Type::Palette256:
				return std::string(
					"\x1b[38;5;" +
					std::to_string(this->Red) +
					"m"
				);
			case Type::RGB:
				return std::string(
					"\x1b[38;2;" +
					std::to_string(this->Red) + ";" +
					std::to_string(this->Green) + ";" +
					std::to_string(this->Blue) + "m"
				);
			}

			return "";
		}
		auto Background() -> const std::string {
			switch (this->colorType) {
			case Type::Palette16:
				return std::string(
					"\x1b[" +
					std::to_string(this->Red + 10) +
					"m"
				);
			case Type::Palette256:
				return std::string(
					"\x1b[48;5;" +
					std::to_string(this->Red) +
					"m"
				);
			case Type::RGB:
				return std::string(
					"\x1b[48;2;" +
					std::to_string(this->Red) + ";" +
					std::to_string(this->Green) + ";" +
					std::to_string(this->Blue) + "m"
				);
			}

			return "";
		}
		auto Foreground(std::ostringstream& ostr) -> void {
			switch (this->colorType) {
			case Type::Palette16:
				ostr << "\x1b[" << this->Red << "m";
				break;
			case Type::Palette256:
				ostr << "\x1b[38;5;" << this->Red << "m";
				break;
			case Type::RGB:
				ostr << "\x1b[38;2;"
					<< this->Red << ";"
					<< this->Green << ";"
					<< this->Blue << "m";
				break;
			}
		}
		auto Background(std::ostringstream& ostr) -> void {
			switch (this->colorType) {
			case Type::Palette16:
				ostr << "\x1b[" << this->Red + 10 << "m";
				break;
			case Type::Palette256:
				ostr << "\x1b[48;5;" << this->Red << "m";
				break;
			case Type::RGB:
				ostr << "\x1b[48;2;"
					<< this->Red << ";"
					<< this->Green << ";"
					<< this->Blue << "m";
				break;
			}
		}
		auto operator ==(const Color& other) -> bool {
			return
				this->Red == other.Red &&
				this->Green == other.Green &&
				this->Blue == other.Blue;
		}
		auto operator !=(const Color& other) -> bool {
			return !(*this == other);
		}

	public:
		unsigned Red = 0;
		unsigned Green = 0;
		unsigned Blue = 0;

	private:
		enum class Type : unsigned {
			Palette16,
			Palette256,
			RGB
		};
		Type colorType = Type::Palette16;
	};
	class Pixel final {
	public:
		Pixel() = default;
		Pixel(Color foreground, Color background) :
			Foreground(foreground),
			Background(background) {
		}
		Pixel(Color foreground, Color background, std::string value) :
			Foreground(foreground),
			Background(background),
			Value(std::move(value)) {
		}
		auto operator ==(const Pixel& other) -> bool {
			return
				this->Bold == other.Bold &&
				this->Dim == other.Dim &&
				this->Italic == other.Italic &&
				this->Underline == other.Underline &&
				this->Blink == other.Blink &&
				this->Invert == other.Invert &&
				this->Invisible == other.Invisible &&
				this->Strikethrough == other.Strikethrough &&
				this->Foreground == other.Foreground &&
				this->Background == other.Background;
		}
		auto operator !=(const Pixel& other) -> bool {
			return !(*this == other);
		}

	public:
		bool Bold = false;
		bool Dim = false;
		bool Italic = false;
		bool Underline = false;
		bool Blink = false;
		bool Invert = false;
		bool Invisible = false;
		bool Strikethrough = false;
		Color Foreground = Palette16::Default;
		Color Background = Palette16::Default;
		std::string Value = " ";
	};
	class Buffer final {
	public:
		Buffer(unsigned height, unsigned width) :
			height(height),
			width(width),
			pixels(height* width) {
		}
		Buffer(unsigned height, unsigned width, Pixel style) :
			height(height),
			width(width),
			style(style),
			pixels(height* width, style) {
		}
		auto At(unsigned y, unsigned x) -> Pixel& {
			static Pixel decoy;
			if (y > this->height || x > this->width) {
				return decoy;
			}

			return this->pixels[y * this->width + x];
		}
		auto ToString() -> const std::string {
			std::ostringstream ostr;
			Pixel prevPixel;

			for (unsigned y = 0; y < this->height; ++y) {
				if (y > 0) {
					ostr << "\n";
				}

				for (unsigned x = 0; x < this->width; ++x) {
					Pixel& nextPixel = this->pixels[y * this->width + x];

					// Mengatur atribut pixel
					if (prevPixel.Bold != nextPixel.Bold) {
						ostr << (nextPixel.Bold ? "\x1b[1m" : "\x1b[22m");
					}
					if (prevPixel.Dim != nextPixel.Dim) {
						ostr << (nextPixel.Dim ? "\x1b[2m" : "\x1b[22m");
					}
					if (prevPixel.Italic != nextPixel.Italic) {
						ostr << (nextPixel.Italic ? "\x1b[3m" : "\x1b[23m");
					}
					if (prevPixel.Underline != nextPixel.Underline) {
						ostr << (nextPixel.Underline ? "\x1b[4m" : "\x1b[24m");
					}
					if (prevPixel.Blink != nextPixel.Blink) {
						ostr << (nextPixel.Blink ? "\x1b[5m" : "\x1b[25m");
					}
					if (prevPixel.Invert != nextPixel.Invert) {
						ostr << (nextPixel.Invert ? "\x1b[7m" : "\x1b[27m");
					}
					if (prevPixel.Invisible != nextPixel.Invisible) {
						ostr << (nextPixel.Invisible ? "\x1b[8m" : "\x1b[28m");
					}
					if (prevPixel.Strikethrough != nextPixel.Strikethrough) {
						ostr << (nextPixel.Strikethrough ? "\x1b[9m" : "\x1b[29m");
					}

					// Mengatur warna pixel
					if (prevPixel.Foreground != nextPixel.Foreground) {
						nextPixel.Foreground.Foreground(ostr);
					}
					if (prevPixel.Background != nextPixel.Background) {
						nextPixel.Background.Background(ostr);
					}

					ostr << nextPixel.Value;
				}
			}
			ostr << "\x1b[m";

			return ostr.str();
		}
		auto Render(std::ostringstream& ostr) {
			Pixel prevPixel;

			for (unsigned y = 0; y < this->height; ++y) {
				if (y > 0) {
					ostr << "\n";
				}

				for (unsigned x = 0; x < this->width; ++x) {
					Pixel& nextPixel = this->pixels[y * this->width + x];

					// Mengatur atribut pixel
					if (prevPixel.Bold != nextPixel.Bold) {
						ostr << (nextPixel.Bold ? "\x1b[1m" : "\x1b[22m");
					}
					if (prevPixel.Dim != nextPixel.Dim) {
						ostr << (nextPixel.Dim ? "\x1b[2m" : "\x1b[22m");
					}
					if (prevPixel.Italic != nextPixel.Italic) {
						ostr << (nextPixel.Italic ? "\x1b[3m" : "\x1b[23m");
					}
					if (prevPixel.Underline != nextPixel.Underline) {
						ostr << (nextPixel.Underline ? "\x1b[4m" : "\x1b[24m");
					}
					if (prevPixel.Blink != nextPixel.Blink) {
						ostr << (nextPixel.Blink ? "\x1b[5m" : "\x1b[25m");
					}
					if (prevPixel.Invert != nextPixel.Invert) {
						ostr << (nextPixel.Invert ? "\x1b[7m" : "\x1b[27m");
					}
					if (prevPixel.Invisible != nextPixel.Invisible) {
						ostr << (nextPixel.Invisible ? "\x1b[8m" : "\x1b[28m");
					}
					if (prevPixel.Strikethrough != nextPixel.Strikethrough) {
						ostr << (nextPixel.Strikethrough ? "\x1b[9m" : "\x1b[29m");
					}

					// Mengatur warna pixel
					if (prevPixel.Foreground != nextPixel.Foreground) {
						nextPixel.Foreground.Foreground(ostr);
					}
					if (prevPixel.Background != nextPixel.Background) {
						nextPixel.Background.Background(ostr);
					}

					ostr << nextPixel.Value;
				}
			}
		}
		auto Height() -> const unsigned& {
			return this->height;
		}
		auto Width() -> const unsigned& {
			return this->width;
		}
		auto Style() -> const Pixel& {
			return this->style;
		}
		auto Clear() -> void {
			std::fill(this->pixels.begin(), this->pixels.end(), this->style);
		}

	private:
		unsigned height = 0;
		unsigned width = 0;
		Pixel style;
		std::vector<Pixel> pixels;
	};
}

#endif