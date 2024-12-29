#include "simple/canvas.h"
#include "simple/renderable/text.h"
#include "simple/renderable/vertical_layout.h"
#include "simple/focusable/button.h"
#include "simple/modifier/border.h"
#include "simple/modifier/horizontal_flex.h"
#include "simple/renderable/horizontal_layout.h"
#include "simple/focusable/input.h"
#include "simple/focusable/vertical_container.h"
#include "simple/focusable/horizontal_container.h"
#include "simple/focusable/dropdown.h"
#include "simple/renderable/horizontal_center.h"
#include "simple/renderable/horizontal_fill.h"
#include "simple/renderable/vertical_fill.h"
#include "simple/renderable/vertical_space.h"
#include "simple/renderable/horizontal_space.h"
#include "simple/selectable/selectable.h"
#include "simple/selectable/checkbox.h"
#include "simple/selectable/radiobox.h"
#include "simple/selectable/toggle.h"
#include <iostream>

int main() {
	auto i_nama_depan = input("nama depan");
	i_nama_depan->width = 20;
	auto i_nama_belakang = input("nama belakang");
	i_nama_belakang->width = 20;
	auto r_laki_laki = radiobox("laki-laki");
	auto r_perempuan = radiobox("perempuan");
	auto g_jenis_kelamin = selectable_group(r_laki_laki, r_perempuan);
	auto i_alamat = input();
	i_alamat->width = 41;
	i_alamat->height = 3;
	auto r_islam = radiobox("islam");
	auto r_kristen = radiobox("kristen katolik");
	auto r_kristen2 = radiobox("kristen protestan");
	auto r_hindu = radiobox("hindu");
	auto r_budha = radiobox("budha");
	auto r_konghucu = radiobox("konghucu");
	auto g_agama = selectable_group(r_islam, r_kristen, r_kristen2, r_hindu, r_budha, r_konghucu);
	auto i_no_hp = input();
	i_no_hp->width = 41;
	i_no_hp->limit = 13;
	i_no_hp->pattern = isdigit;
	auto d_jurusan = dropdown(
		"silakan pilih",
		{
			"Matematika",
			"Fisika",
			"Biologi",
			"Kimia",
			"Statistika",
			"Aktuaria",
			"Meteorologi",
			"Astronomi",
			"Geofisika",
			"Geologi",
			"Ilmu Kedokteran",
			"Pendidikan Dokter",
			"Kedokteran Gigi",
			"Kedokteran Hewan",
			"Gizi",
			"Ilmu Keperawatan",
			"Apoteker",
			"Kebidanan",
			"Kesehatan Lingkungan",
			"Keselamatan dan Kesehatan Kerja",
			"Kesehatan Masyarakat",
			"Farmasi / Ilmu Farmasi",
			"Teknik Elektro",
			"Teknik Sipil",
			"Teknik Listrik",
			"Teknik Bangunan",
			"Teknik Biomedis",
			"Teknik Geodesi",
			"Teknik Geologi",
			"Teknik Kimia",
			"Pendidikan Teknologi Agroindustri",
			"Teknik Lingkungan",
			"Teknik Mesin",
			"Teknik Perkapalan",
			"Teknik Nuklir",
			"Rekayasa Keselamatan Kebakaran",
			"Teknik Kimia",
			"Teknologi Bioproses",
			"Teknik Informatika",
			"Teknik Industri",
			"Teknik Biomedis",
			"Teknik Pertambangan",
			"Teknik Perminyakan",
			"Teknik Material",
			"Teknik Geodesi dan Geomatika",
			"Teknik Dirgantara / Penerbangan",
			"Teknik Metalurgi",
			"Ilmu Komputer",
			"Teknologi Informasi",
			"Sistem Informasi",
			"Teknik Komputer",
			"Arsitektur",
			"Perencanaan Wilayah dan Kota",
			"Teknik Pengairan",
			"Arsitektur Interior",
			"Kehutanan",
			"Agronomi",
			"Akuakultur",
			"Teknik Pertanian",
			"Teknologi Pangan",
			"Teknologi Industri Pertanian",
			"Pertanian dan Agribisnis",
			"Agribisnis",
			"Peternakan",
			"Ilmu Kelautan",
			"Ilmu Perikanan / Teknologi Perikanan",
			"Agrobisnis Perikanan",
			"Bioteknologi",
			"Agriekoteknologi",
			"Hubungan Internasional",
			"Ilmu Politik",
			"Ilmu Pemerintahan",
			"Kriminologi",
			"Sosiologi",
			"Ilmu Administrasi Negara",
			"Ilmu Administrasi Niaga",
			"Ilmu Administrasi Fiskal",
			"Administrasi Bisnis / Tata Niaga",
			"Administrasi Publik",
			"Administrasi Pemerintahan",
			"Antropologi Sosial / Antropologi Budaya",
			"Arkeologi",
			"Sejarah",
			"Ilmu Komunikasi",
			"Ilmu Perpustakaan",
			"Kearsipan Digital",
			"Jurnalistik",
			"Hubungan Masyarakat",
			"TV dan Film",
			"Manajemen Komunikasi",
			"Bahasa dan Kebudayaan Korea",
			"Bahasa dan Budaya Tiongkok",
			"Sastra Belanda",
			"Sastra Cina",
			"Sastra Indonesia",
			"Sastra Jawa / Sunda / Daerah",
			"Sastra Jepang",
			"Sastra Jerman",
			"Sastra Inggris",
			"Sastra Prancis",
			"Sastra Rusia / Slavia",
			"Sastra Arab",
			"Sejarah dan Kebudayaan Islam",
			"Ilmu Filsafat",
			"Ilmu Ekonomi",
			"Ekonomi Pembangunan",
			"Hubungan Masyarakat",
			"Manajemen",
			"Manajemen Bisnis",
			"Akuntansi",
			"Ilmu Ekonomi Islam",
			"Bisnis Islam",
			"Bisnis Digital",
			"Bisnis Internasional",
			"Keuangan dan Perbankan",
			"Kewirausahaan",
			"Ilmu Hukum",
			"Psikologi",
			"Geografi",
			"Ilmu Kesejahteraan Sosial",
			"Studi Agama",
			"Peradilan Agama",
			"Politik Islam",
			"Teologi",
			"Pariwisata",
			"Perhotelan",
			"Teknologi Pendidikan",
			"Administrasi Pendidikan",
			"Manajemen Pendidikan",
			"Psikologi Pendidikan dan Bimbingan",
			"Pendidikan Masyarakat",
			"Pendidikan Khusus",
			"Bimbingan dan Konseling",
			"Perpustakaan & Sains Informasi",
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
			"Tata Boga",
			"Sekretaris",
			"Administrasi Asuransi dan Aktuaria",
			"Administrasi Keuangan dan Perbankan",
			"Administrasi Perkantoran dan Sekretaris",
			"Administrasi Perpajakan",
			"Administrasi Bisnis",
			"Fisioterapi",
			"Hubungan Masyarakat",
			"Manajemen Informasi dan Dokumentasi",
			"Vokasional Pariwisata",
			"Okupasi Terapi",
			"Penyiaran Multimedia",
			"Periklanan Kreatif",
			"Akuntansi",
			"Administrasi Perumahsakitan",
			"Manajemen Perhotelan",
			"Desain Grafis",
			"Batik dan Fashion",
			"Akuntansi perpajakan",
			"Akuntansi sektor publik",
			"Bisnis internasional",
			"Pemasaran digital"
		}
	);
	d_jurusan->width = 41;
	auto c_tac = checkbox("saya telah membaca ketentuan");
	auto c_acc = checkbox("saya menyetujui peraturan kampus");
	auto t_notifikasi = toggle("notifikasi email");
	auto b_daftar = button("daftar");
	bool running = true;
	auto b_exit = button("exit", [&running]() { running = false; });

	auto vLayout = vlayout(
		vfill(),
		hlayout(
			hfill(),
			vlayout(
				text("pendaftaran mahasiswa baru") | border_rounded | hcenter,
				text("nama lengkap"),
				hlayout(i_nama_depan, hspace(), i_nama_belakang),
				text("jenis kelamin"),
				hlayout(r_laki_laki, hspace(), r_perempuan),
				text("alamat rumah"),
				i_alamat,
				text("agama"),
				hlayout(r_islam, hspace(), r_kristen),
				hlayout(r_kristen2, hspace(), r_hindu),
				hlayout(r_budha, hspace(), r_konghucu),
				text("nomor telepon"),
				i_no_hp,
				text("jurusan yang dituju"),
				d_jurusan,
				c_tac,
				c_acc,
				t_notifikasi,
				b_daftar | hflex,
				b_exit | hflex
			) | border_rounded,
			hfill()
		) | hflex,
		vfill()
	) | border_rounded;

	auto vContainer = vcontainer(
		hcontainer(i_nama_depan, i_nama_belakang),
		hcontainer(r_laki_laki, r_perempuan),
		i_alamat,
		hcontainer(r_islam, r_kristen),
		hcontainer(r_kristen2, r_hindu),
		hcontainer(r_budha, r_konghucu),
		i_no_hp,
		d_jurusan,
		c_tac,
		c_acc,
		t_notifikasi,
		b_daftar,
		b_exit
	);
	vContainer->focused(true);

	SetConsoleOutputCP(CP_UTF8);
	std::cout << "\x1b[?25l" << std::flush;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	auto canvas = simple::canvas(csbi.srWindow.Bottom - csbi.srWindow.Top + 1, csbi.srWindow.Right - csbi.srWindow.Left + 1);
	bool update = true;
	INPUT_RECORD input_record[128];
	DWORD events;
	HANDLE input_handle = GetStdHandle(STD_INPUT_HANDLE);
	while (running) {
		ReadConsoleInput(input_handle, input_record, 128, &events);
		for (DWORD i = 0; i < events; ++i) {
			if (input_record[i].EventType == KEY_EVENT && input_record[i].Event.KeyEvent.bKeyDown) {
				if (vContainer->on_key(input_record[i].Event.KeyEvent)) {
					update = true;
				}
			}
		}

		if (update) {
			canvas.clear();
			vLayout->init();
			vLayout->set({ 0, 0, canvas.get_width(), canvas.get_height() });
			vLayout->render(canvas);
			std::cout << "\x1b[H" << canvas.render() << std::flush;
			update = false;
		}
	}
}