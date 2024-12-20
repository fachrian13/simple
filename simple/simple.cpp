#include "simple.h"
#include <iostream>

using Simple::Buffer;
using Simple::Color;
using Simple::Palette16;
using Simple::Palette256;

int main() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

	// Set console agar support unicode
	SetConsoleOutputCP(CP_UTF8);

	// Ambil ukuran console
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hOut, &csbi);

	Buffer mainBuffer = Buffer(csbi.dwSize.Y, csbi.dwSize.X);
	bool update = true;
	bool running = true;

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
	auto bDaftar = Button("Daftar");
	auto bExit = Button("Exit", [&running]() { running = false; });

	auto vLayout = //HLayout(
		VLayout(
			Text("PENDAFTARAN MAHASISWA BARU") | CenterX | BorderStyle(DoubleLine) | FlexX,
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
		) | BorderStyle(Rounded) | CenterX;
	//);

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
	vContainer->Focused(true);

	INPUT_RECORD record[128];
	DWORD eventsRead;
	while (running) {
		ReadConsoleInput(hIn, record, 128, &eventsRead);

		for (DWORD i = 0; i < eventsRead; ++i) {
			if (record[i].EventType == KEY_EVENT && record[i].Event.KeyEvent.bKeyDown) {
				update = true;
				vContainer->OnKey(record[i].Event.KeyEvent);
			}

			if (update) {
				update = false;
				mainBuffer.Clear();
				vLayout->Init();
				vLayout->Set({ 0, 0, csbi.dwSize.X, csbi.dwSize.Y });
				vLayout->Render(mainBuffer);
				std::cout << "\x1b[H" << mainBuffer.ToString() << std::flush;
			}
		}
	}

	return 0;
}