#ifndef _SIMPLE_
#define _SIMPLE_
#define NOMINMAX

#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>

namespace Simple {
	enum class Palette16 : int {
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
	enum class Palette256 : int {
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
		MediumBlue3 = 56,
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

	class BorderStyle final {
	public:
		class Alignment final {
		public:
			std::string Left;
			std::string Middle;
			std::string Right;
		};

	public:
		std::string Horizontal;
		std::string Vertical;
		Alignment Top;
		Alignment Middle;
		Alignment Bottom;
	};
	class Rectangle final {
	public:
		int Left = 0;
		int Top = 0;
		int Right = 0;
		int Bottom = 0;
	};
	class Color final {
	public:
		Color(Palette16 value) :
			colorType(Type::Palette16),
			Red(static_cast<int>(value)),
			Green(static_cast<int>(value)),
			Blue(static_cast<int>(value)) {
		}
		Color(Palette256 value) :
			colorType(Type::Palette256),
			Red(static_cast<int>(value)),
			Green(static_cast<int>(value)),
			Blue(static_cast<int>(value)) {
		}
		Color(int red, int green, int blue) :
			colorType(Type::RGB),
			Red(red > -1 && red < 256 ? red : 0),
			Green(green > -1 && green < 256 ? green : 0),
			Blue(blue > -1 && blue < 256 ? blue : 0) {
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
			std::string result;

			result += "\x1b[";
			switch (this->colorType) {
			case Type::Palette16:
				result += std::to_string(this->Red);
				break;
			case Type::Palette256:
				result += "38;5;";
				result += std::to_string(this->Red);
				break;
			case Type::RGB:
				result += "38;2;";
				result += std::to_string(this->Red) + ";";
				result += std::to_string(this->Green) + ";";
				result += std::to_string(this->Blue);
				break;
			}
			result += "m";

			return std::move(result);
		}
		auto Foreground(std::ostringstream& ostr) -> void {
			ostr << "\x1b[";
			switch (this->colorType) {
			case Type::Palette16:
				ostr << this->Red;
				break;
			case Type::Palette256:
				ostr << "38;5;" << this->Red;
				break;
			case Type::RGB:
				ostr << "38;2;"
					<< this->Red << ";"
					<< this->Green << ";"
					<< this->Blue;
				break;
			}
			ostr << "m";
		}
		auto Background() -> const std::string {
			std::string result;

			result += "\x1b[";
			switch (this->colorType) {
			case Type::Palette16:
				result += std::to_string(this->Red + 10);
				break;
			case Type::Palette256:
				result += "48;5;";
				result += std::to_string(this->Red);
				break;
			case Type::RGB:
				result += "48;2;";
				result += std::to_string(this->Red) + ";";
				result += std::to_string(this->Green) + ";";
				result += std::to_string(this->Blue);
				break;
			}
			result += "m";

			return std::move(result);
		}
		auto Background(std::ostringstream& ostr) -> void {
			ostr << "\x1b[";
			switch (this->colorType) {
			case Type::Palette16:
				ostr << this->Red;
				break;
			case Type::Palette256:
				ostr << "48;5;" << this->Red;
				break;
			case Type::RGB:
				ostr << "48;2;"
					<< this->Red << ";"
					<< this->Green << ";"
					<< this->Blue;
				break;
			}
			ostr << "m";
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
		int Red = 0;
		int Green = 0;
		int Blue = 0;

	private:
		enum class Type : int {
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
		Buffer(int height, int width) :
			height(height),
			width(width),
			pixels(height* width) {
		}
		Buffer(int height, int width, Pixel style) :
			height(height),
			width(width),
			style(style),
			pixels(height* width, style) {
		}
		auto At(int y, int x) -> Pixel& {
			static Pixel dummy;
			if (y >= this->height || x >= this->width) {
				return dummy;
			}

			return this->pixels[y * this->width + x];
		}
		auto ToString() -> const std::string {
			std::string result;
			Pixel prevPixel;

			for (int y = 0; y < this->height; ++y) {
				if (y > 0) {
					result += "\n";
				}

				for (int x = 0; x < this->width; ++x) {
					Pixel& nextPixel = this->pixels[y * this->width + x];

					// Mengatur atribut pixel
					if (prevPixel.Bold != nextPixel.Bold) {
						result += nextPixel.Bold ? "\x1b[1m" : "\x1b[22m";
					}
					if (prevPixel.Dim != nextPixel.Dim) {
						result += nextPixel.Dim ? "\x1b[2m" : "\x1b[22m";
					}
					if (prevPixel.Italic != nextPixel.Italic) {
						result += nextPixel.Italic ? "\x1b[3m" : "\x1b[23m";
					}
					if (prevPixel.Underline != nextPixel.Underline) {
						result += nextPixel.Underline ? "\x1b[4m" : "\x1b[24m";
					}
					if (prevPixel.Blink != nextPixel.Blink) {
						result += nextPixel.Blink ? "\x1b[5m" : "\x1b[25m";
					}
					if (prevPixel.Invert != nextPixel.Invert) {
						result += nextPixel.Invert ? "\x1b[7m" : "\x1b[27m";
					}
					if (prevPixel.Invisible != nextPixel.Invisible) {
						result += nextPixel.Invisible ? "\x1b[8m" : "\x1b[28m";
					}
					if (prevPixel.Strikethrough != nextPixel.Strikethrough) {
						result += nextPixel.Strikethrough ? "\x1b[9m" : "\x1b[29m";
					}

					// Mengatur warna pixel
					if (prevPixel.Foreground != nextPixel.Foreground) {
						result += nextPixel.Foreground.Foreground();
					}
					if (prevPixel.Background != nextPixel.Background) {
						result += nextPixel.Background.Background();
					}

					result += nextPixel.Value;

					prevPixel = nextPixel;
				}
			}
			result += "\x1b[m";

			return std::move(result);
		}
		auto Render(std::ostringstream& ostr) {
			Pixel prevPixel;

			for (int y = 0; y < this->height; ++y) {
				if (y > 0) {
					ostr << "\n";
				}

				for (int x = 0; x < this->width; ++x) {
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

					prevPixel = nextPixel;
				}
			}
		}
		auto Height() -> const int& {
			return this->height;
		}
		auto Width() -> const int& {
			return this->width;
		}
		auto Style() -> const Pixel& {
			return this->style;
		}
		auto Clear() -> void {
			std::fill(this->pixels.begin(), this->pixels.end(), this->style);
		}

	private:
		int height = 0;
		int width = 0;
		Pixel style;
		std::vector<Pixel> pixels;
	};

	class SelectableGroup;
	namespace Base {
		class Renderable {
		public:
			virtual auto Init() -> void {}
			virtual auto Set(Rectangle dimension) -> void {
				this->Dimension = dimension;
			}
			virtual auto Render(Buffer&) -> void {}

		public:
			int Height = 0;
			int Width = 0;
			int FlexY = 0;
			int FlexX = 0;
			Rectangle Dimension;
		};
		class Focusable {
		public:
			auto Focused() -> const bool& {
				return this->focused;
			}
			virtual auto Focused(bool flag) -> void {
				this->focused = flag;
			}
			virtual auto OnKey(const KEY_EVENT_RECORD&) -> bool {
				return false;
			}

		private:
			bool focused = false;
		};
		class Selectable {
		public:
			Selectable() = default;
			Selectable(std::string name) :
				name(std::move(name)) {
			}
			auto Selected() -> const bool& {
				return this->selected;
			}
			virtual auto Selected(bool flag) -> void {
				this->selected = flag;
			}
			auto SetGroup(SelectableGroup* group) -> void {
				this->group = group;
			}
			auto Name() -> const std::string& {
				return this->name;
			}

		protected:
			std::string name;
			SelectableGroup* group = nullptr;

		private:
			bool selected = false;
		};
		class Modifier : public Renderable {
		public:
			Modifier(std::shared_ptr<Renderable> element) :
				element(std::move(element)) {
			}

			virtual auto Init() -> void override {
				this->element->Init();
				Renderable::Height = this->element->Height;
				Renderable::Width = this->element->Width;
			}
			virtual auto Set(Rectangle dimension) -> void override {
				this->element->Set(dimension);
				Renderable::Set(dimension);
			}
			virtual auto Render(Buffer& buf) -> void override {
				this->element->Render(buf);
			}

		protected:
			std::shared_ptr<Renderable> element;
		};
	}
	namespace Utility {
		template<class Type, class... Args>
		std::vector<Type> ToVector(Args&&... args) {
			return std::vector<Type>{ std::forward<Args>(args)... };
		}
	}

	class SelectableGroup final {
	public:
		SelectableGroup(std::vector<std::shared_ptr<Base::Selectable>> components) {
			for (auto& component : components) {
				component->SetGroup(this);
				this->components.push_back(std::move(component));
			}
		}
		void Clear() {
			for (const auto& component : this->components) {
				component->Selected(false);
			}
		}
		auto Selected() -> const std::shared_ptr<Base::Selectable>& {
			for (const auto& component : this->components) {
				if (component->Selected()) {
					return component;
				}
			}
		}

	private:
		std::vector<std::shared_ptr<Base::Selectable>> components;
	};

	class VerticalLayout final : public Base::Renderable {
	public:
		VerticalLayout(std::vector<std::shared_ptr<Renderable>> elements) :
			elements(std::move(elements)) {
		}

		auto Init() -> void override {
			Renderable::Height = 0;
			Renderable::Width = 0;
			Renderable::FlexX = 0;
			Renderable::FlexY = 0;

			for (const auto& element : this->elements) {
				element->Init();

				Renderable::Height += element->Height;
				Renderable::Width = std::max(Renderable::Width, element->Width);
				Renderable::FlexX += element->FlexX;
				Renderable::FlexY += element->FlexY;
			}
		}
		auto Set(Rectangle dimension) -> void override {
			Renderable::Set(dimension);

			int spaceY = (Renderable::Dimension.Bottom - Renderable::Dimension.Top - Renderable::Height) / (Renderable::FlexY == 0 ? 1 : Renderable::FlexY);
			int spaceX = (Renderable::Dimension.Right - Renderable::Dimension.Left - Renderable::Width) / (Renderable::FlexX == 0 ? 1 : Renderable::FlexX);

			for (const auto& element : this->elements) {
				if (element->FlexX == 1) {
					//dimension.Right = dimension.Left + Renderable::Dimension.Right;
				}
				else {
					dimension.Right = dimension.Left + element->Width;
				}

				if (element->FlexY == 1) {
					dimension.Bottom = dimension.Top + element->Height + spaceY;
				}
				else {
					dimension.Bottom = dimension.Top + element->Height;
				}

				element->Set(dimension);

				dimension.Top = dimension.Bottom;
			}
		}
		auto Render(Buffer& buf) -> void override {
			for (const auto& element : this->elements) {
				element->Render(buf);
			}
		}

	private:
		std::vector<std::shared_ptr<Renderable>> elements;
	};
	class HorizontalLayout final : public Base::Renderable {
	public:
		HorizontalLayout(std::vector<std::shared_ptr<Renderable>> elements) :
			elements(std::move(elements)) {
		}

		auto Init() -> void override {
			Renderable::Height = 0;
			Renderable::Width = 0;
			Renderable::FlexX = 0;
			Renderable::FlexY = 0;

			for (const auto& element : this->elements) {
				element->Init();

				Renderable::Height = std::max(Renderable::Height, element->Height);
				Renderable::Width += element->Width;
				Renderable::FlexX += element->FlexX;
				Renderable::FlexY += element->FlexY;
			}
		}
		auto Set(Rectangle dimension) -> void override {
			Renderable::Set(dimension);

			int spaceY = (Renderable::Dimension.Bottom - Renderable::Dimension.Top - Renderable::Height) / (Renderable::FlexY == 0 ? 1 : Renderable::FlexY);
			int spaceX = (Renderable::Dimension.Right - Renderable::Dimension.Left - Renderable::Width) / (Renderable::FlexX == 0 ? 1 : Renderable::FlexX);

			for (const auto& element : this->elements) {
				if (element->FlexX == 1) {
					dimension.Right = dimension.Left + element->Width + spaceX;
				}
				else {
					dimension.Right = dimension.Left + element->Width;
				}

				if (element->FlexY == 1) {
					//dimension.Bottom = dimension.Top + element->Height + spaceY;
				}
				else {
					dimension.Bottom = dimension.Top + element->Height;
				}

				element->Set(dimension);

				dimension.Left = dimension.Right;
			}
		}
		auto Render(Buffer& buf) -> void override {
			for (const auto& element : this->elements) {
				element->Render(buf);
			}
		}

	private:
		std::vector<std::shared_ptr<Renderable>> elements;
	};
	class Text final : public Base::Renderable {
	public:
		Text(std::string value) :
			value(std::move(value)) {
		}

		auto Init() -> void override {
			Renderable::Height = 1;
			Renderable::Width = static_cast<int>(this->value.size());
		}
		auto Render(Buffer& buf) -> void {
			// Render value kedalam buffer
			for (int y = Renderable::Dimension.Top, i = 0; y < Renderable::Dimension.Bottom; ++y) {
				for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x, ++i) {
					if (i < this->value.size()) {
						buf.At(y, x).Value = this->value[i];
					}
					else { return; }
				}
			}
		}

	private:
		std::string value;
	};

	class VerticalContainer final : public Base::Focusable {
	public:
		VerticalContainer(std::vector<std::shared_ptr<Focusable>> components) :
			components(std::move(components)) {
		}

		auto Focused(bool flag) -> void {
			Focusable::Focused(flag);

			this->components[this->focusedComponent]->Focused(flag);
		}
		auto OnKey(const KEY_EVENT_RECORD& keyEvent) -> bool override {
			if (this->components[this->focusedComponent]->OnKey(keyEvent)) {
				return true;
			}

			if (
				((keyEvent.dwControlKeyState & SHIFT_PRESSED) && keyEvent.wVirtualKeyCode == VK_TAB) ||
				keyEvent.wVirtualKeyCode == VK_UP ||
				keyEvent.uChar.AsciiChar == 'k' ||
				keyEvent.uChar.AsciiChar == 'K'
				) {
				if (this->focusedComponent > 0) {
					this->components[this->focusedComponent]->Focused(false);
					this->components[--this->focusedComponent]->Focused(true);
					return true;
				}

				return false;
			}

			if (
				keyEvent.wVirtualKeyCode == VK_TAB ||
				keyEvent.wVirtualKeyCode == VK_DOWN ||
				keyEvent.uChar.AsciiChar == 'j' ||
				keyEvent.uChar.AsciiChar == 'J'
				) {
				if (this->focusedComponent < this->components.size() - 1) {
					this->components[this->focusedComponent]->Focused(false);
					this->components[++this->focusedComponent]->Focused(true);
					return true;
				}

				return false;
			}

			return false;
		}

	private:
		int focusedComponent = 0;
		std::vector<std::shared_ptr<Focusable>> components;
	};
	class HorizontalContainer final : public Base::Focusable {
	public:
		HorizontalContainer(std::vector<std::shared_ptr<Focusable>> components) :
			components(std::move(components)) {
		}

		auto Focused(bool flag) -> void {
			Focusable::Focused(flag);

			this->components[this->focusedComponent]->Focused(flag);
		}
		auto OnKey(const KEY_EVENT_RECORD& keyEvent) -> bool override {
			if (this->components[this->focusedComponent]->OnKey(keyEvent)) {
				return true;
			}

			if (
				((keyEvent.dwControlKeyState & SHIFT_PRESSED) && keyEvent.wVirtualKeyCode == VK_TAB) ||
				keyEvent.wVirtualKeyCode == VK_LEFT ||
				keyEvent.uChar.AsciiChar == 'h' ||
				keyEvent.uChar.AsciiChar == 'H'
				) {
				if (this->focusedComponent > 0) {
					this->components[this->focusedComponent]->Focused(false);
					this->components[--this->focusedComponent]->Focused(true);
					return true;
				}

				return false;
			}

			if (
				keyEvent.wVirtualKeyCode == VK_TAB ||
				keyEvent.wVirtualKeyCode == VK_RIGHT ||
				keyEvent.uChar.AsciiChar == 'l' ||
				keyEvent.uChar.AsciiChar == 'L'
				) {
				if (this->focusedComponent < this->components.size() - 1) {
					this->components[this->focusedComponent]->Focused(false);
					this->components[++this->focusedComponent]->Focused(true);
					return true;
				}

				return false;
			}

			return false;
		}

	private:
		int focusedComponent = 0;
		std::vector<std::shared_ptr<Focusable>> components;
	};
	class Button final : public Base::Renderable, public Base::Focusable {
	public:
		Button(std::string name) :
			name(std::move(name)) {
		}
		Button(std::string name, std::function<void()> logic) :
			name(std::move(name)),
			logic(std::move(logic)) {
		}

		auto Init() -> void override {
			Renderable::Height = 1;
			Renderable::Width = static_cast<int>(this->name.size()) + 2;
		}
		auto Render(Buffer& buf) -> void override {
			// Render [] kedalam buffer
			buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left).Value = "[";
			buf.At(Renderable::Dimension.Top, Renderable::Dimension.Right - 1).Value = "]";

			// Render name kedalam buffer
			for (int y = Renderable::Dimension.Top, i = 0; y < Renderable::Dimension.Bottom; ++y) {
				for (int x = Renderable::Dimension.Left + 1; x < Renderable::Dimension.Right - 1; ++x, ++i) {
					buf.At(y, x).Value = this->name[i];
				}
			}

			// Jika cursor focus maka invert foreground dan background
			if (Focusable::Focused()) {
				for (int y = Renderable::Dimension.Top; y < Renderable::Dimension.Bottom; ++y) {
					for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x) {
						buf.At(y, x).Invert = true;
					}
				}
			}
		}

		auto OnKey(const KEY_EVENT_RECORD& keyEvent) -> bool override {
			switch (keyEvent.wVirtualKeyCode) {
			case VK_RETURN:
				if (this->logic) {
					logic();
					return true;
				}
			}

			return false;
		}

	private:
		std::string name;
		std::function<void()> logic;
	};
	class Dropdown final : public Base::Renderable, public Base::Focusable {
	public:
		Dropdown(std::vector<std::string>&& values) :
			values(std::move(values)) {
		}
		Dropdown(const std::vector<std::string>& values) :
			values(values) {
		}
		Dropdown(std::string placeholder, std::vector<std::string>&& values) :
			placeholder(std::move(placeholder)),
			values(std::move(values)) {
		}
		Dropdown(std::string placeholder, const std::vector<std::string>& values) :
			placeholder(std::move(placeholder)),
			values(values) {
		}

		auto Init() -> void override {
			if (Renderable::Width == 0) {
				Renderable::Width = static_cast<int>(
					std::max(
						std::max_element(
							this->values.begin(),
							this->values.end(),
							[](const std::string& a, const std::string& b) {
								return a.size() < b.size();
							}
						)->size(),
						this->placeholder.size()
					)
					) + 1;
			}
			Renderable::Height = Focusable::Focused() ? std::min(7, static_cast<int>(this->values.size())) : 1;
		}
		auto Render(Buffer& buf) -> void override {
			// Render area untuk dropdown
			for (int y = Renderable::Dimension.Top; y < Renderable::Dimension.Bottom; ++y) {
				for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x) {
					buf.At(y, x).Invert = true;
				}
			}

			if (Focusable::Focused()) {
				// Render list values kedalam buffer
				for (int y = Renderable::Dimension.Top, i = this->textBegin; y < Renderable::Dimension.Bottom; ++y, ++i) {
					for (int x = Renderable::Dimension.Left + 1, ii = 0; x < Renderable::Dimension.Right; ++x, ++ii) {
						if (ii < this->values[i].size()) {
							buf.At(y, x).Value = this->values[i][ii];
						}
						else { break; }

						// Tandai index yang telah dipilih
						if (i == this->selectedIndex) {
							buf.At(y, Renderable::Dimension.Left).Value = "*";
						}
					}
				}

				// Tandai index yang sedang focus
				for (int y = Renderable::Dimension.Top, i = 0; y < Renderable::Dimension.Bottom; ++y) {
					for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x, ++i) {
						buf.At(Renderable::Dimension.Top + this->yCursor, x).Invert = false;
					}
				}

				return;
			}

			// Jika index belum dipilih dan placeholder diisi maka
			// render placeholder kedalam buffer
			if (this->selectedIndex < 0 && !this->placeholder.empty()) {
				for (int y = Renderable::Dimension.Top, i = 0; y < Renderable::Dimension.Bottom; ++y) {
					for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x, ++i) {
						if (i < this->placeholder.size()) {
							buf.At(y, x).Italic = true;
							buf.At(y, x).Value = this->placeholder[i];
						}
						else { break; }
					}
				}
			}
			// Jika index telah dipilih maka render index kedalam buffer
			else {
				for (int y = Renderable::Dimension.Top, i = 0; y < Renderable::Dimension.Bottom; ++y) {
					for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x, ++i) {
						if (i < this->values[this->selectedIndex].size()) {
							buf.At(y, x).Value = this->values[this->selectedIndex][i];
						}
					}
				}
			}
		}

		auto OnKey(const KEY_EVENT_RECORD& keyEvent) -> bool override {
			if (
				keyEvent.wVirtualKeyCode == VK_DOWN ||
				keyEvent.uChar.AsciiChar == 'j' ||
				keyEvent.uChar.AsciiChar == 'J'
				) {
				if (this->index < this->values.size() - 1) {
					++this->index;
					this->moveCursor(1);
					return true;
				}

				return false;
			}

			if (
				keyEvent.wVirtualKeyCode == VK_UP ||
				keyEvent.uChar.AsciiChar == 'k' ||
				keyEvent.uChar.AsciiChar == 'K'
				) {
				if (this->index > 0) {
					--this->index;
					this->moveCursor(-1);
					return true;
				}

				return false;
			}

			if (keyEvent.wVirtualKeyCode == VK_RETURN) {
				this->selectedIndex = this->index;
				return true;
			}

			return false;
		}

	private:
		auto moveCursor(int y) -> void {
			if (y > 0) {
				if (this->yCursor < Renderable::Height - 1) {
					++this->yCursor;
				}
				else { ++textBegin; }
			}
			else if (y < 0) {
				if (this->yCursor > 0) {
					--this->yCursor;
				}
				else { --textBegin; }
			}
		}

	private:
		int index = 0;
		int selectedIndex = -1;
		int yCursor = 0;
		int textBegin = 0;
		std::string placeholder;
		std::vector<std::string> values;
	};
	class Input final : public Base::Renderable, public Base::Focusable {
	public:
		Input() = default;
		Input(std::string placeholder) :
			placeholder(std::move(placeholder)) {
		}

		auto Init() -> void override {
			if (Renderable::Height == 0) {
				Renderable::Height = 1;
			}
			if (Renderable::Width == 0) {
				Renderable::Width = 30;
			}
		}
		auto Render(Buffer& buf) -> void override {
			// Render area untuk input
			for (int y = Renderable::Dimension.Top; y < Renderable::Dimension.Bottom; ++y) {
				for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x) {
					buf.At(y, x).Invert = true;
				}
			}

			// Render posisi cursor jika focus
			if (Focusable::Focused()) {
				buf.At(
					Renderable::Dimension.Top + this->yCursor,
					Renderable::Dimension.Left + this->xCursor
				).Invert = false;
			}

			// Render placeholder jika terisi
			if (this->value.empty() && !this->placeholder.empty()) {
				for (int y = Renderable::Dimension.Top, i = 0; y < Renderable::Dimension.Bottom; ++y) {
					for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x, ++i) {
						if (i < this->placeholder.size()) {
							buf.At(y, x).Italic = true;
							buf.At(y, x).Value = this->placeholder[i];
						}
						else { break; }
					}
				}

				return;
			}

			// Render jika karakter disembunyikan, atau biasa dikenal dengan password
			if (this->Hide) {
				for (int y = Renderable::Dimension.Top, i = this->textBegin; y < Renderable::Dimension.Bottom; ++y) {
					for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x, ++i) {
						if (i < this->value.size()) {
							buf.At(y, x).Value = u8"•";
						}
						else { break; }
					}
				}

				return;
			}

			// Render karakter biasa
			for (int y = Renderable::Dimension.Top, i = this->textBegin; y < Renderable::Dimension.Bottom; ++y) {
				for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x, ++i) {
					if (i < this->value.size()) {
						buf.At(y, x).Value = this->value[i];
					}
					else { break; }
				}
			}
		}

		auto OnKey(const KEY_EVENT_RECORD& keyEvent) -> bool override {
			switch (keyEvent.wVirtualKeyCode) {
			case VK_LEFT:
				if (this->index > 0) {
					--this->index;
					this->moveCursor(0, -1);
					return true;
				}
				break;
			case VK_UP:
				if (this->index - Renderable::Width >= 0) {
					this->index -= Renderable::Width;
					this->moveCursor(-1, 0);
					return true;
				}
				break;
			case VK_RIGHT:
				if (this->index < this->value.size()) {
					++this->index;
					this->moveCursor(0, 1);
					return true;
				}
				break;
			case VK_DOWN:
				if (this->index + Renderable::Width <= this->value.size()) {
					this->index += Renderable::Width;
					this->moveCursor(1, 0);
					return true;
				}
				break;
			case VK_BACK:
				if (this->index > 0) {
					this->value.erase(this->value.begin() + --this->index);
					this->moveCursor(0, -1);
					return true;
				}
				break;
			default:
				if (this->Pattern(keyEvent.uChar.AsciiChar) && this->index < this->Limit) {
					this->value.insert(this->value.begin() + index++, keyEvent.uChar.AsciiChar);
					this->moveCursor(0, 1);
					return true;
				}
			}

			return false;
		}

	public:
		bool Hide = false;
		int Limit = std::numeric_limits<int>::max();
		std::function<bool(int)> Pattern = [](int ch) { return ch > 0x1F && ch < 0x7F; };

	private:
		auto moveCursor(int y, int x) -> void {
			if (y > 0) {
				if (this->yCursor < Renderable::Height - 1) {
					++this->yCursor;
				}
				else { this->textBegin += Renderable::Width; }
			}
			else if (y < 0) {
				if (this->yCursor > 0) {
					--this->yCursor;
				}
				else { this->textBegin -= Renderable::Width; }
			}

			if (x > 0) {
				if (this->xCursor < Renderable::Width - 1) {
					++this->xCursor;
				}
				else if (this->yCursor < Renderable::Height - 1) {
					this->xCursor = 0;
					++this->yCursor;
				}
				else {
					this->xCursor = 0;
					this->textBegin += Renderable::Width;
				}
			}
			else if (x < 0) {
				if (this->xCursor > 0) {
					--this->xCursor;
				}
				else if (this->yCursor > 0) {
					this->xCursor = Renderable::Width - 1;
					--this->yCursor;
				}
				else {
					this->xCursor = Renderable::Width - 1;
					this->textBegin -= Renderable::Width;
				}
			}
		}

	private:
		int index = 0;
		int yCursor = 0;
		int xCursor = 0;
		int textBegin = 0;
		std::string value;
		std::string placeholder;
	};
	class CheckBox final : public Base::Renderable, public Base::Focusable, public Base::Selectable {
	public:
		CheckBox() = default;
		CheckBox(std::string name) :
			Selectable(std::move(name)) {
		}

		auto Init() -> void override {
			Renderable::Height = 1;
			Renderable::Width = 3 + static_cast<int>(Selectable::name.size());
		}
		auto Render(Buffer& buf) -> void override {
			// Render [] kedalam buffer
			buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left).Value = "[";
			buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left + 2).Value = "]";

			// Jika nama terisi
			if (!Selectable::name.empty()) {
				for (int y = Renderable::Dimension.Top, i = 0; y < Renderable::Dimension.Bottom; ++y) {
					for (int x = Renderable::Dimension.Left + 3; x < Renderable::Dimension.Right; ++x, ++i) {
						buf.At(y, x).Value = Selectable::name[i];
					}
				}
			}

			// Jika cursor focus pada komponen ini
			if (Focusable::Focused()) {
				for (int y = Renderable::Dimension.Top; y < Renderable::Dimension.Bottom; ++y) {
					for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x) {
						buf.At(y, x).Invert = true;
					}
				}
			}

			// Jika item ini dipilih
			if (Selectable::Selected()) {
				buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left + 1).Value = u8"■";
			}
		}

		auto OnKey(const KEY_EVENT_RECORD& keyEvent) -> bool override {
			if (keyEvent.wVirtualKeyCode == VK_RETURN || keyEvent.uChar.AsciiChar == ' ') {
				if (Selectable::group) {
					Selectable::group->Clear();
				}

				Selectable::Selected(!Selectable::Selected());
				return true;
			}

			return false;
		}
	};
	class RadioBox final : public Base::Renderable, public Base::Focusable, public Base::Selectable {
	public:
		RadioBox() = default;
		RadioBox(std::string name) :
			Selectable(std::move(name)) {
		}

		auto Init() -> void override {
			Renderable::Height = 1;
			Renderable::Width = 3 + static_cast<int>(Selectable::name.size());
		}
		auto Render(Buffer& buf) -> void override {
			// Render [] kedalam buffer
			buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left).Value = "(";
			buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left + 2).Value = ")";

			// Jika nama terisi
			if (!Selectable::name.empty()) {
				for (int y = Renderable::Dimension.Top, i = 0; y < Renderable::Dimension.Bottom; ++y) {
					for (int x = Renderable::Dimension.Left + 3; x < Renderable::Dimension.Right; ++x, ++i) {
						buf.At(y, x).Value = Selectable::name[i];
					}
				}
			}

			// Jika cursor focus pada komponen ini
			if (Focusable::Focused()) {
				for (int y = Renderable::Dimension.Top; y < Renderable::Dimension.Bottom; ++y) {
					for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x) {
						buf.At(y, x).Invert = true;
					}
				}
			}

			// Jika item ini dipilih
			if (Selectable::Selected()) {
				buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left + 1).Value = u8"●";
			}
		}

		auto OnKey(const KEY_EVENT_RECORD& keyEvent) -> bool override {
			if (keyEvent.wVirtualKeyCode == VK_RETURN || keyEvent.uChar.AsciiChar == ' ') {
				if (Selectable::group) {
					Selectable::group->Clear();
				}

				Selectable::Selected(true);
				return true;
			}

			return false;
		}
	};
	class Toggle final : public Base::Renderable, public Base::Focusable, public Base::Selectable {
	public:
		Toggle() = default;
		Toggle(std::string name) :
			Selectable(std::move(name)) {
		}

		auto Init() -> void override {
			Renderable::Height = 1;
			Renderable::Width = (Selectable::Selected() ? 4 : 5) + static_cast<int>(Selectable::name.size());
		}
		auto Render(Buffer& buf) -> void override {
			// Render jika on atau off
			if (Selectable::Selected()) {
				buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left).Value = "[";
				buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left + 1).Value = "O";
				buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left + 2).Value = "N";
				buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left + 3).Value = "]";
			}
			else {
				buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left).Value = "[";
				buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left + 1).Value = "O";
				buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left + 2).Value = "F";
				buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left + 3).Value = "F";
				buf.At(Renderable::Dimension.Top, Renderable::Dimension.Left + 4).Value = "]";
			}

			// Render nama kedalam buffer
			for (int y = Renderable::Dimension.Top, i = 0; y < Renderable::Dimension.Bottom; ++y) {
				for (int x = Renderable::Dimension.Left + (Selectable::Selected() ? 4 : 5); x < Renderable::Dimension.Right; ++x, ++i) {
					buf.At(y, x).Value = Selectable::name[i];
				}
			}

			// Jika cursor focus
			if (Focusable::Focused()) {
				for (int y = Renderable::Dimension.Top; y < Renderable::Dimension.Bottom; ++y) {
					for (int x = Renderable::Dimension.Left; x < Renderable::Dimension.Right; ++x) {
						buf.At(y, x).Invert = true;
					}
				}
			}
		}

		auto OnKey(const KEY_EVENT_RECORD& keyEvent) -> bool override {
			if (keyEvent.wVirtualKeyCode == VK_RETURN || keyEvent.uChar.AsciiChar == ' ') {
				if (Selectable::group) {
					Selectable::group->Clear();
				}

				Selectable::Selected(!Selectable::Selected());
				return true;
			}

			return false;
		}
	};

	class Bold final : public Base::Modifier {
	public:
		Bold(std::shared_ptr<Renderable> element) :
			Modifier(std::move(element)) {
		}

		auto Render(Buffer& buf) -> void override {
			Modifier::Render(buf);

			for (int y = Modifier::Dimension.Top; y < Modifier::Dimension.Bottom; ++y) {
				for (int x = Modifier::Dimension.Left; x < Modifier::Dimension.Right; ++x) {
					buf.At(y, x).Bold = true;
				}
			}
		}
	};
	class Dim final : public Base::Modifier {
	public:
		Dim(std::shared_ptr<Renderable> element) :
			Modifier(std::move(element)) {
		}

		auto Render(Buffer& buf) -> void override {
			Modifier::Render(buf);

			for (int y = Modifier::Dimension.Top; y < Modifier::Dimension.Bottom; ++y) {
				for (int x = Modifier::Dimension.Left; x < Modifier::Dimension.Right; ++x) {
					buf.At(y, x).Dim = true;
				}
			}
		}
	};
	class Italic final : public Base::Modifier {
	public:
		Italic(std::shared_ptr<Renderable> element) :
			Modifier(std::move(element)) {
		}

		auto Render(Buffer& buf) -> void override {
			Modifier::Render(buf);

			for (int y = Modifier::Dimension.Top; y < Modifier::Dimension.Bottom; ++y) {
				for (int x = Modifier::Dimension.Left; x < Modifier::Dimension.Right; ++x) {
					buf.At(y, x).Italic = true;
				}
			}
		}
	};
	class Underline final : public Base::Modifier {
	public:
		Underline(std::shared_ptr<Renderable> element) :
			Modifier(std::move(element)) {
		}

		auto Render(Buffer& buf) -> void override {
			Modifier::Render(buf);

			for (int y = Modifier::Dimension.Top; y < Modifier::Dimension.Bottom; ++y) {
				for (int x = Modifier::Dimension.Left; x < Modifier::Dimension.Right; ++x) {
					buf.At(y, x).Underline = true;
				}
			}
		}
	};
	class Blink final : public Base::Modifier {
	public:
		Blink(std::shared_ptr<Renderable> element) :
			Modifier(std::move(element)) {
		}

		auto Render(Buffer& buf) -> void override {
			Modifier::Render(buf);

			for (int y = Modifier::Dimension.Top; y < Modifier::Dimension.Bottom; ++y) {
				for (int x = Modifier::Dimension.Left; x < Modifier::Dimension.Right; ++x) {
					buf.At(y, x).Blink = true;
				}
			}
		}
	};
	class Invert final : public Base::Modifier {
	public:
		Invert(std::shared_ptr<Renderable> element) :
			Modifier(std::move(element)) {
		}

		auto Render(Buffer& buf) -> void override {
			Modifier::Render(buf);

			for (int y = Modifier::Dimension.Top; y < Modifier::Dimension.Bottom; ++y) {
				for (int x = Modifier::Dimension.Left; x < Modifier::Dimension.Right; ++x) {
					buf.At(y, x).Invert = true;
				}
			}
		}
	};
	class Invisible final : public Base::Modifier {
	public:
		Invisible(std::shared_ptr<Renderable> element) :
			Modifier(std::move(element)) {
		}

		auto Render(Buffer& buf) -> void override {
			Modifier::Render(buf);

			for (int y = Modifier::Dimension.Top; y < Modifier::Dimension.Bottom; ++y) {
				for (int x = Modifier::Dimension.Left; x < Modifier::Dimension.Right; ++x) {
					buf.At(y, x).Invisible = true;
				}
			}
		}
	};
	class Strikethrough final : public Base::Modifier {
	public:
		Strikethrough(std::shared_ptr<Renderable> element) :
			Modifier(std::move(element)) {
		}

		auto Render(Buffer& buf) -> void override {
			Modifier::Render(buf);

			for (int y = Modifier::Dimension.Top; y < Modifier::Dimension.Bottom; ++y) {
				for (int x = Modifier::Dimension.Left; x < Modifier::Dimension.Right; ++x) {
					buf.At(y, x).Strikethrough = true;
				}
			}
		}
	};
	class Foreground final : public Base::Modifier {
	public:
		Foreground(std::shared_ptr<Renderable> element, Color color) :
			Modifier(std::move(element)),
			color(color) {
		}

		auto Render(Buffer& buf) -> void override {
			Modifier::Render(buf);

			for (int y = Modifier::Dimension.Top; y < Modifier::Dimension.Bottom; ++y) {
				for (int x = Modifier::Dimension.Left; x < Modifier::Dimension.Right; ++x) {
					if (buf.At(y, x).Foreground == buf.Style().Foreground)
						buf.At(y, x).Foreground = this->color;
				}
			}
		}

	private:
		Color color;
	};
	class Background final : public Base::Modifier {
	public:
		Background(std::shared_ptr<Renderable> element, Color color) :
			Modifier(std::move(element)),
			color(color) {
		}

		auto Init() -> void override {
			Modifier::Init();

			Renderable::Height = Modifier::element->Height;
			Renderable::Width = Modifier::element->Width;
		}
		auto Set(Rectangle dimension) -> void override {
			Modifier::Set(dimension);
			Renderable::Set(dimension);
		}
		auto Render(Buffer& buf) -> void override {
			Modifier::Render(buf);

			for (int y = Modifier::Dimension.Top; y < Modifier::Dimension.Bottom; ++y) {
				for (int x = Modifier::Dimension.Left; x < Modifier::Dimension.Right; ++x) {
					if (buf.At(y, x).Background == buf.Style().Background)
						buf.At(y, x).Background = this->color;
				}
			}
		}

	private:
		Color color;
	};
	class Border final : public Base::Modifier {
	public:
		Border(std::shared_ptr<Renderable> element) :
			Modifier(std::move(element)) {
		}
		Border(std::shared_ptr<Renderable> element, BorderStyle style) :
			Modifier(std::move(element)),
			style(style) {
		}

		auto Init() -> void override {
			Modifier::Init();

			Renderable::Height = Modifier::element->Height + 2;
			Renderable::Width = Modifier::element->Width + 2;
		}
		auto Set(Rectangle dimension) -> void override {
			Modifier::Set({ dimension.Left + 1, dimension.Top + 1, dimension.Right - 1, dimension.Bottom - 1 });
			Renderable::Set(dimension);
		}
		void Render(Buffer& buffer) override {
			Modifier::Render(buffer);

			buffer.At(Renderable::Dimension.Top, Renderable::Dimension.Left).Value = this->style.Top.Left;
			buffer.At(Renderable::Dimension.Top, Renderable::Dimension.Right - 1).Value = this->style.Top.Right;
			buffer.At(Renderable::Dimension.Bottom - 1, Renderable::Dimension.Left).Value = this->style.Bottom.Left;
			buffer.At(Renderable::Dimension.Bottom - 1, Renderable::Dimension.Right - 1).Value = this->style.Bottom.Right;

			for (int x = Renderable::Dimension.Left + 1; x < Renderable::Dimension.Right - 1; ++x) {
				buffer.At(Renderable::Dimension.Top, x).Value = this->style.Horizontal;
				buffer.At(Renderable::Dimension.Bottom - 1, x).Value = this->style.Horizontal;
			}
			for (int y = Renderable::Dimension.Top + 1; y < Renderable::Dimension.Bottom - 1; ++y) {
				buffer.At(y, Renderable::Dimension.Left).Value = this->style.Vertical;
				buffer.At(y, Renderable::Dimension.Right - 1).Value = this->style.Vertical;
			}
		}

	private:
		BorderStyle style = {
			"-", "|",
			{"+", "+", "+"},
			{"+", "+", "+"},
			{"+", "+", "+"}
		};
	};
	class FlexX final : public Base::Modifier {
	public:
		FlexX(std::shared_ptr<Renderable> element) :
			Modifier(std::move(element)) {
		}

		auto Init() -> void override {
			Modifier::Init();
			Modifier::FlexX = 1;
			Modifier::FlexY = Renderable::FlexY;

			Renderable::Height = Modifier::Height;
			Renderable::Width = Modifier::Width;
			Renderable::FlexX = 1;
		}
	};
	class FlexY final : public Base::Modifier {
	public:
		FlexY(std::shared_ptr<Renderable> element) :
			Modifier(std::move(element)) {
		}

		auto Init() -> void override {
			Modifier::Init();
			Modifier::FlexY = 1;
			Modifier::FlexX = Renderable::FlexX;

			Renderable::Height = Modifier::Height;
			Renderable::Width = Modifier::Width;
			Renderable::FlexY = 1;
		}
	};
}

template<class... Args>
auto SelectableGroup(Args&&... components) -> Simple::SelectableGroup {
	return Simple::SelectableGroup(
		Simple::Utility::ToVector<std::shared_ptr<Simple::Base::Selectable>>(
			std::forward<Args>(components)...
		)
	);
}

template<class... Args>
auto VLayout(Args&&... elements) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::VerticalLayout>(
		Simple::Utility::ToVector<std::shared_ptr<Simple::Base::Renderable>>(
			std::forward<Args>(elements)...
		)
	);
}
template<class... Args>
auto HLayout(Args&&... elements) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::HorizontalLayout>(
		Simple::Utility::ToVector<std::shared_ptr<Simple::Base::Renderable>>(
			std::forward<Args>(elements)...
		)
	);
}
auto Text(std::string value) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::Text>(std::move(value));
}

template<class... Args>
auto VContainer(Args&&... elements) -> std::shared_ptr<Simple::Base::Focusable> {
	return std::make_shared<Simple::VerticalContainer>(
		Simple::Utility::ToVector<std::shared_ptr<Simple::Base::Focusable>>(
			std::forward<Args>(elements)...
		)
	);
}
template<class... Args>
auto HContainer(Args&&... elements) -> std::shared_ptr<Simple::Base::Focusable> {
	return std::make_shared<Simple::HorizontalContainer>(
		Simple::Utility::ToVector<std::shared_ptr<Simple::Base::Focusable>>(
			std::forward<Args>(elements)...
		)
	);
}
auto Button(std::string name) -> std::shared_ptr<Simple::Button> {
	return std::make_shared<Simple::Button>(std::move(name));
}
auto Button(std::string name, std::function<void()> logic) -> std::shared_ptr<Simple::Button> {
	return std::make_shared<Simple::Button>(std::move(name), std::move(logic));
}
auto Dropdown(std::vector<std::string>&& values) -> std::shared_ptr<Simple::Dropdown> {
	return std::make_shared<Simple::Dropdown>(std::move(values));
}
auto Dropdown(const std::vector<std::string>& values) -> std::shared_ptr<Simple::Dropdown> {
	return std::make_shared<Simple::Dropdown>(values);
}
auto Dropdown(std::string placeholder, std::vector<std::string>&& values) -> std::shared_ptr<Simple::Dropdown> {
	return std::make_shared<Simple::Dropdown>(std::move(placeholder), std::move(values));
}
auto Dropdown(std::string placeholder, const std::vector<std::string>& values) -> std::shared_ptr<Simple::Dropdown> {
	return std::make_shared<Simple::Dropdown>(std::move(placeholder), values);
}
auto Input() -> std::shared_ptr<Simple::Input> {
	return std::make_shared<Simple::Input>();
}
auto Input(std::string placeholder) -> std::shared_ptr<Simple::Input> {
	return std::make_shared<Simple::Input>(std::move(placeholder));
}
auto CheckBox() -> std::shared_ptr<Simple::CheckBox> {
	return std::make_shared<Simple::CheckBox>();
}
auto CheckBox(std::string name) -> std::shared_ptr<Simple::CheckBox> {
	return std::make_shared<Simple::CheckBox>(std::move(name));
}
auto RadioBox() -> std::shared_ptr<Simple::RadioBox> {
	return std::make_shared<Simple::RadioBox>();
}
auto RadioBox(std::string name) -> std::shared_ptr<Simple::RadioBox> {
	return std::make_shared<Simple::RadioBox>(std::move(name));
}
auto Toggle() -> std::shared_ptr<Simple::Toggle> {
	return std::make_shared<Simple::Toggle>();
}
auto Toggle(std::string name) -> std::shared_ptr<Simple::Toggle> {
	return std::make_shared<Simple::Toggle>(std::move(name));
}

auto Bold(std::shared_ptr<Simple::Base::Renderable> element) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::Bold>(std::move(element));
}
auto Dim(std::shared_ptr<Simple::Base::Renderable> element) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::Dim>(std::move(element));
}
auto Italic(std::shared_ptr<Simple::Base::Renderable> element) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::Italic>(std::move(element));
}
auto Underline(std::shared_ptr<Simple::Base::Renderable> element) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::Underline>(std::move(element));
}
auto Blink(std::shared_ptr<Simple::Base::Renderable> element) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::Blink>(std::move(element));
}
auto Invert(std::shared_ptr<Simple::Base::Renderable> element) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::Invert>(std::move(element));
}
auto Invisible(std::shared_ptr<Simple::Base::Renderable> element) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::Invisible>(std::move(element));
}
auto Strikethrough(std::shared_ptr<Simple::Base::Renderable> element) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::Strikethrough>(std::move(element));
}
auto Foreground(Simple::Color color) -> std::function<std::shared_ptr<Simple::Base::Renderable>(std::shared_ptr<Simple::Base::Renderable>)> {
	return [color](std::shared_ptr<Simple::Base::Renderable> element) {
		return std::make_shared<Simple::Foreground>(std::move(element), color);
		};
}
auto Background(Simple::Color color) -> std::function<std::shared_ptr<Simple::Base::Renderable>(std::shared_ptr<Simple::Base::Renderable>)> {
	return [color](std::shared_ptr<Simple::Base::Renderable> element) {
		return std::make_shared<Simple::Background>(std::move(element), color);
		};
}
auto Border(std::shared_ptr<Simple::Base::Renderable> element) {
	return std::make_shared<Simple::Border>(std::move(element));
}
auto BorderStyle(Simple::BorderStyle style) -> std::function<std::shared_ptr<Simple::Base::Renderable>(std::shared_ptr<Simple::Base::Renderable>)> {
	return  [style](std::shared_ptr<Simple::Base::Renderable> element) {
		return std::make_shared<Simple::Border>(std::move(element), style);
		};
}
auto FlexY(std::shared_ptr<Simple::Base::Renderable> element) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::FlexY>(std::move(element));
}
auto FlexX(std::shared_ptr<Simple::Base::Renderable> element) -> std::shared_ptr<Simple::Base::Renderable> {
	return std::make_shared<Simple::FlexX>(std::move(element));
}
auto CenterY(std::shared_ptr<Simple::Base::Renderable> element) -> std::shared_ptr<Simple::Base::Renderable> {
	return FlexY(
		VLayout(
			FlexY(Text("")),
			std::move(element),
			FlexY(Text(""))
		)
	);
}
auto CenterX(std::shared_ptr<Simple::Base::Renderable> element) -> std::shared_ptr<Simple::Base::Renderable> {
	return FlexX(
		HLayout(
			FlexX(Text("")),
			std::move(element),
			FlexX(Text(""))
		)
	);
}

auto operator |(
	std::shared_ptr<Simple::Base::Renderable> rvalue,
	std::function<std::shared_ptr<Simple::Base::Renderable>(std::shared_ptr<Simple::Base::Renderable>)> nvalue
	) -> std::shared_ptr<Simple::Base::Renderable> {
	return nvalue(std::move(rvalue));
}

static const Simple::BorderStyle Ascii = {
	"-", "|",
	{"+", "+", "+"},
	{"+", "+", "+"},
	{"+", "+", "+"}
};
static const Simple::BorderStyle Line = {
	u8"━", u8"┃",
	{u8"┏", u8"┳", u8"┓"},
	{u8"┣", u8"╋", u8"┫"},
	{u8"┗", u8"┻", u8"┛"}
};
static const Simple::BorderStyle DoubleLine = {
	u8"═", u8"║",
	{u8"╔", u8"╦", u8"╗"},
	{u8"╠", u8"╬", u8"╣"},
	{u8"╚", u8"╩", u8"╝"}
};
static const Simple::BorderStyle None = {
	" ", " ",
	{" ", " ", " "},
	{" ", " ", " "},
	{" ", " ", " "}
};
static const Simple::BorderStyle Rounded = {
	u8"─", u8"│",
	{u8"╭", u8"─", u8"╮"},
	{u8"│", u8" ", u8"│"},
	{u8"╰", u8"─", u8"╯"}
};
static const Simple::BorderStyle Dashed = {
	u8"╌", u8"╎",
	{u8"╌", u8"╌", u8"╌"},
	{u8"╎", u8" ", u8"╎"},
	{u8"╌", u8"╌", u8"╌"}
};

#endif