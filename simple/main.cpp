#include "simple.h"
#include <iostream>

using Simple::Buffer;

class Application {
public:
	Application() = delete;
	Application(int height, int width) :
		height(height),
		width(width),
		buf(height, width) {
		SetConsoleOutputCP(CP_UTF8);
	}
	auto Exit() -> void {
		this->loop = false;
	}
	auto Run() -> void {
		this->Main();

		if (this->layout.empty() || this->container.empty()) {
			return;
		}

		bool update = true;
		this->container[0]->Focused(true);
		while (this->loop) {
			ReadConsoleInput(this->hIn, this->inputEvents, 128, &this->eventsRead);
			for (DWORD i = 0; i < this->eventsRead; ++i) {
				if (this->inputEvents[i].EventType == KEY_EVENT && this->inputEvents[i].Event.KeyEvent.bKeyDown) {
					this->container[0]->OnKey(this->inputEvents[i].Event.KeyEvent);
					update = true;
				}
			}

			if (update) {
				this->buf.Clear();
				this->layout[0]->Init();
				int y = (this->height - this->layout[0]->Height) / 2;
				int x = (this->width - this->layout[0]->Width) / 2;
				this->layout[0]->Set({ x, y, x + this->layout[0]->Width , y + this->layout[0]->Height });
				this->layout[0]->Render(this->buf);
				std::cout << "\x1b[H" << this->buf.ToString() << std::flush;
				update = false;
			}
		}
	}

protected:
	virtual auto Main() -> void = 0;
	auto AddLayout(std::shared_ptr<Simple::Base::Renderable> layout) {
		this->layout.push_back(std::move(layout));
	}
	auto AddContainer(std::shared_ptr<Simple::Base::Focusable> container) {
		this->container.push_back(std::move(container));
	}
	auto Notification(std::string message) -> void {
		bool loop = true;
		auto bOk = Button("Ok", [&loop]() { loop = false; });
		bOk->Focused(true);
		auto vLayout = VLayout(
			Text(std::move(message)),
			Text(""),
			bOk
		) | BorderStyle(Rounded);

		bool update = true;
		bOk->Focused(true);
		while (loop) {
			ReadConsoleInput(this->hIn, this->inputEvents, 128, &this->eventsRead);
			for (DWORD i = 0; i < this->eventsRead; ++i) {
				if (this->inputEvents[i].EventType == KEY_EVENT && this->inputEvents[i].Event.KeyEvent.bKeyDown) {
					bOk->OnKey(this->inputEvents[i].Event.KeyEvent);
					update = true;
				}
			}

			if (update) {
				this->buf.Clear();
				vLayout->Init();
				int y = (this->height - vLayout->Height) / 2;
				int x = (this->width - vLayout->Width) / 2;
				vLayout->Set({ x, y, x + vLayout->Width , y + vLayout->Height });
				vLayout->Render(this->buf);
				std::cout << "\x1b[H" << this->buf.ToString() << std::flush;
				update = false;
			}
		}
	}

private:
	bool loop = true;
	int height = 0;
	int width = 0;
	Buffer buf;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD inputEvents[128];
	DWORD eventsRead = 0;
	std::vector<std::shared_ptr<Simple::Base::Renderable>> layout;
	std::vector<std::shared_ptr<Simple::Base::Focusable>> container;
};

class MyApp final : public Application {
public:
	MyApp(int height, int width) :
		Application(height, width) {
	}

protected:
	auto Main() -> void {
		auto iNamaDepan = Input("Nama Depan");
		iNamaDepan->Width = 24;
		auto iNamaBelakang = Input("Nama Belakang");
		iNamaBelakang->Width = 24;
		auto rLakiLaki = RadioBox("Laki Laki");
		auto rPerempuan = RadioBox("Perempuan");
		auto sgJenisKelamin = SelectableGroup(rLakiLaki, rPerempuan);
		auto iAlamat = Input();
		iAlamat->Width = 49;
		iAlamat->Height = 3;
		auto rIslam = RadioBox("Islam");
		auto rKristen1 = RadioBox("Kristen Protestan");
		auto rKristen2 = RadioBox("Kristen Katolik");
		auto rHindu = RadioBox("Hindu");
		auto rBuddha = RadioBox("Buddha");
		auto rKonghuchu = RadioBox("Konghuchu");
		auto sgAgama = SelectableGroup(rIslam, rKristen1, rKristen2, rHindu, rBuddha, rKonghuchu);
		auto iNoHP = Input();
		iNoHP->Width = 49;
		iNoHP->Limit = 14;
		iNoHP->Pattern = isdigit;
		auto dJurusan = Dropdown("Silakan Pilih",
			{
				"Teknologi Pendidikan",
				"Administrasi Pendidikan",
				"Manajemen Pendidikan",
				"Psikologi Pendidikan dan Bimbingan",
				"Pendidikan Masyarakat",
				"Pendidikan Khusus",
				"Bimbingan dan Konseling",
				"Perpustakaan& Sains Informasi",
				"Pendidikan Guru Sekolah Dasar(PGSD)",
				"Pendidikan Guru Anak Usia Dini(PAUD)",
				"Pendidikan Luar Sekolah(PLS)",
				"Pendidikan Luar Biasa",
				"Pendidikan Bahasa Indonesia",
				"Pendidikan Bahasa Daerah",
				"Pendidikan Bahasa Inggris",
				"Pendidikan Bahasa Arab",
				"Pendidikan Bahasa Jepang",
				"Pendidikan Bahasa Jerman",
				"Pendidikan Bahasa Prancis",
				"Pendidikan Bahasa Korea",
				"Pendidikan Pancasila dan Kewarganegaraan",
				"Pendidikan Sejarah",
				"Pendidikan Geografi",
				"Pendidikan Sosiologi",
				"Pendidikan IPS",
				"Pendidikan Agama Islam",
				"Manajemen Pemasaran Pariwisata",
				"Pendidikan Matematika",
				"Pendidikan Fisika",
				"Pendidikan Biologi",
				"Pendidikan Kimia",
				"Pendidikan IPA",
				"Pendidikan Ilmu Komputer",
				"Pendidikan Seni Rupa",
				"Pendidikan Seni Tari",
				"Pendidikan Seni Musik",
				"Pendidikan Kepelatihan Olahraga",
				"Pendidikan Jasmani, Kesehatan, dan Rekreasi",
				"Pendidikan Teknik Otomotif",
				"Seni Rupa Murni",
				"Seni Kriya",
				"Seni Tari",
				"Seni Musik",
				"Desain dan Komunikasi Visual",
				"Desain Interior",
				"Desain Produk",
				"Tata Kelola Seni",
				"Film dan Televisi",
				"Film dan Animasi",
				"Musik",
				"Tata Rias",
				"Tata Busana",
				"Tata Boga"
			}
		);
		dJurusan->Width = 49;
		auto cbTnC = CheckBox("Saya telah membaca peraturan.");
		auto cbAgree = CheckBox("Saya menyetujui peraturan.");
		auto bDaftar = Button("Daftar", [&]() {
			if (iNamaDepan->Value().empty()) {
				Notification("Silakan isi Nama Depan.");
			}
			});
		auto bExit = Button("Exit", [&]() { this->Exit(); });

		auto vLayout = VLayout(
			Text("PENDAFTARAN MAHASISWA BARU") | BorderStyle(DoubleLine),
			Text("Nama Lengkap"),
			HLayout(iNamaDepan, Text(" "), iNamaBelakang),
			Text("Jenis Kelamin"),
			HLayout(rLakiLaki, Text(" "), rPerempuan),
			Text("Alamat Rumah"),
			iAlamat,
			Text("Agama"),
			HLayout(rIslam, Text(" "), rKristen1, Text(" "), rKristen2),
			HLayout(rHindu, Text(" "), rBuddha, Text(" "), rKonghuchu),
			Text("Nomor Handphone"),
			iNoHP,
			Text("Jurusan yang dituju"),
			dJurusan,
			cbTnC,
			cbAgree,
			bDaftar,
			bExit
		) | BorderStyle(Rounded);
		this->AddLayout(vLayout);

		auto vContainer = VContainer(
			HContainer(iNamaDepan, iNamaBelakang),
			HContainer(rLakiLaki, rPerempuan),
			iAlamat,
			HContainer(rIslam, rKristen1, rKristen2),
			HContainer(rHindu, rBuddha, rKonghuchu),
			iNoHP,
			dJurusan,
			cbTnC,
			cbAgree,
			bDaftar,
			bExit
		);
		this->AddContainer(vContainer);
	}
};

int main() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hOut, &csbi);

	auto app = MyApp(csbi.dwSize.Y, csbi.dwSize.X);
	app.Run();
}