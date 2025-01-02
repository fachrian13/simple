#include "simple.h"
#include "simple/renderable/vertical_layout.h"
#include "simple/renderable/text.h"
#include "simple/renderable/horizontal_center.h"
#include "simple/renderable/vertical_center.h"
#include "simple/renderable/center.h"
#include "simple/renderable/horizontal_space.h"
#include "simple/renderable/vertical_space.h"

#include "simple/focusable/input.h"
#include "simple/focusable/dropdown.h"
#include "simple/focusable/button.h"
#include "simple/focusable/vertical_container.h"
#include "simple/focusable/horizontal_container.h"

#include "simple/selectable/radiobox.h"
#include "simple/selectable/checkbox.h"

#include "simple/modifier/border.h"

class app final : public simple::application {
public:
	app(int height, int width) :
		application(height, width) {
	}

private:
	int main() override {
		auto i_nama_depan = input("Nama Depan");
		i_nama_depan->width = 25;
		auto i_nama_belakang = input("Nama belakang");
		i_nama_belakang->width = 25;
		auto r_laki_laki = radiobox("Laki-Laki");
		auto r_perempuan = radiobox("Perempuan");
		auto gr_jenis_kelamin = selectable_group(r_laki_laki, r_perempuan);
		auto i_alamat = input();
		i_alamat->height = 3;
		i_alamat->width = 51;
		auto r_islam = radiobox("Islam");
		auto r_kristen1 = radiobox("Kristen Katolik");
		auto r_kristen2 = radiobox("Kristen Protestan");
		auto r_hindu = radiobox("Hindu");
		auto r_buddha = radiobox("Buddha");
		auto r_konghuchu = radiobox("Konghuchu");
		auto gr_agama = selectable_group(
			r_islam,
			r_kristen1,
			r_kristen2,
			r_hindu,
			r_buddha,
			r_konghuchu
		);
		auto i_hp = input();
		i_hp->width = 48;
		i_hp->pattern = isdigit;
		auto d_jurusan = dropdown(
			"Silakan Pilih",
			{
				"Matematika", "Fisika", "Biologi", "Kimia", "Statistika", "Aktuaria",
				"Meteorologi", "Astronomi", "Geofisika", "Geologi", "Ilmu Kedokteran",
				"Pendidikan Dokter", "Kedokteran Gigi", "Kedokteran Hewan", "Gizi",
				"Ilmu Keperawatan", "Apoteker", "Kebidanan", "Kesehatan Lingkungan",
				"Keselamatan dan Kesehatan Kerja", "Kesehatan Masyarakat", "Farmasi / Ilmu Farmasi",
				"Teknik Elektro", "Teknik Sipil", "Teknik Listrik", "Teknik Bangunan",
				"Teknik Biomedis", "Teknik Geodesi", "Teknik Geologi", "Teknik Kimia",
				"Pendidikan Teknologi Agroindustri", "Teknik Lingkungan", "Teknik Mesin",
				"Teknik Perkapalan", "Teknik Nuklir", "Rekayasa Keselamatan Kebakaran",
				"Teknik Kimia", "Teknologi Bioproses", "Teknik Informatika", "Teknik Industri",
				"Teknik Biomedis", "Teknik Pertambangan", "Teknik Perminyakan", "Teknik Material",
				"Teknik Geodesi dan Geomatika", "Teknik Dirgantara / Penerbangan", "Teknik Metalurgi",
				"Ilmu Komputer", "Teknologi Informasi", "Sistem Informasi", "Teknik Komputer",
				"Arsitektur", "Perencanaan Wilayah dan Kota", "Teknik Pengairan", "Arsitektur Interior",
				"Kehutanan", "Agronomi", "Akuakultur", "Teknik Pertanian", "Teknologi Pangan",
				"Teknologi Industri Pertanian", "Pertanian dan Agribisnis", "Agribisnis", "Peternakan",
				"Ilmu Kelautan", "Ilmu Perikanan / Teknologi Perikanan", "Agrobisnis Perikanan",
				"Bioteknologi", "Agriekoteknologi", "Hubungan Internasional", "Ilmu Politik",
				"Ilmu Pemerintahan", "Kriminologi", "Sosiologi", "Ilmu Administrasi Negara",
				"Ilmu Administrasi Niaga", "Ilmu Administrasi Fiskal", "Administrasi Bisnis / Tata Niaga",
				"Administrasi Publik", "Administrasi Pemerintahan", "Antropologi Sosial / Antropologi Budaya",
				"Arkeologi", "Sejarah", "Ilmu Komunikasi", "Ilmu Perpustakaan", "Kearsipan Digital",
				"Jurnalistik", "Hubungan Masyarakat", "TV dan Film", "Manajemen Komunikasi",
				"Bahasa dan Kebudayaan Korea", "Bahasa dan Budaya Tiongkok", "Sastra Belanda",
				"Sastra Cina", "Sastra Indonesia", "Sastra Jawa / Sunda / Daerah", "Sastra Jepang",
				"Sastra Jerman", "Sastra Inggris", "Sastra Prancis", "Sastra Rusia / Slavia",
				"Sastra Arab", "Sejarah dan Kebudayaan Islam", "Ilmu Filsafat", "Ilmu Ekonomi",
				"Ekonomi Pembangunan", "Hubungan Masyarakat", "Manajemen", "Manajemen Bisnis",
				"Akuntansi", "Ilmu Ekonomi Islam", "Bisnis Islam", "Bisnis Digital", "Bisnis Internasional",
				"Keuangan dan Perbankan", "Kewirausahaan", "Ilmu Hukum", "Psikologi", "Geografi",
				"Ilmu Kesejahteraan Sosial", "Studi Agama", "Peradilan Agama", "Politik Islam",
				"Teologi", "Pariwisata", "Perhotelan", "Teknologi Pendidikan", "Administrasi Pendidikan",
				"Manajemen Pendidikan", "Psikologi Pendidikan dan Bimbingan", "Pendidikan Masyarakat",
				"Pendidikan Khusus", "Bimbingan dan Konseling", "Perpustakaan & Sains Informasi",
				"Pendidikan Guru Sekolah Dasar(PGSD)", "Pendidikan Guru Anak Usia Dini(PAUD)",
				"Pendidikan Luar Sekolah(PLS)", "Pendidikan Luar Biasa", "Pendidikan Bahasa Indonesia",
				"Pendidikan Bahasa Daerah", "Pendidikan Bahasa Inggris", "Pendidikan Bahasa Arab",
				"Pendidikan Bahasa Jepang", "Pendidikan Bahasa Jerman", "Pendidikan Bahasa Prancis",
				"Pendidikan Bahasa Korea", "Pendidikan Pancasila dan Kewarganegaraan", "Pendidikan Sejarah",
				"Pendidikan Geografi", "Pendidikan Sosiologi", "Pendidikan IPS", "Pendidikan Agama Islam",
				"Manajemen Pemasaran Pariwisata", "Pendidikan Matematika", "Pendidikan Fisika",
				"Pendidikan Biologi", "Pendidikan Kimia", "Pendidikan IPA", "Pendidikan Ilmu Komputer",
				"Pendidikan Seni Rupa", "Pendidikan Seni Tari", "Pendidikan Seni Musik",
				"Pendidikan Kepelatihan Olahraga", "Pendidikan Jasmani, Kesehatan, dan Rekreasi",
				"Pendidikan Teknik Otomotif", "Teknologi Pendidikan", "Administrasi Pendidikan",
				"Manajemen Pendidikan", "Psikologi Pendidikan dan Bimbingan", "Pendidikan Masyarakat",
				"Pendidikan Khusus", "Bimbingan dan Konseling", "Perpustakaan& Sains Informasi",
				"Pendidikan Guru Sekolah Dasar(PGSD)", "Pendidikan Guru Anak Usia Dini(PAUD)",
				"Pendidikan Luar Sekolah(PLS)", "Pendidikan Luar Biasa", "Pendidikan Bahasa Indonesia",
				"Pendidikan Bahasa Daerah", "Pendidikan Bahasa Inggris", "Pendidikan Bahasa Arab",
				"Pendidikan Bahasa Jepang", "Pendidikan Bahasa Jerman", "Pendidikan Bahasa Prancis",
				"Pendidikan Bahasa Korea", "Pendidikan Pancasila dan Kewarganegaraan", "Pendidikan Sejarah",
				"Pendidikan Geografi", "Pendidikan Sosiologi", "Pendidikan IPS", "Pendidikan Agama Islam",
				"Manajemen Pemasaran Pariwisata", "Pendidikan Matematika", "Pendidikan Fisika",
				"Pendidikan Biologi", "Pendidikan Kimia", "Pendidikan IPA", "Pendidikan Ilmu Komputer",
				"Pendidikan Seni Rupa", "Pendidikan Seni Tari", "Pendidikan Seni Musik",
				"Pendidikan Kepelatihan Olahraga", "Pendidikan Jasmani, Kesehatan, dan Rekreasi",
				"Pendidikan Teknik Otomotif", "Seni Rupa Murni", "Seni Kriya", "Seni Tari", "Seni Musik",
				"Desain dan Komunikasi Visual", "Desain Interior", "Desain Produk", "Tata Kelola Seni",
				"Film dan Televisi", "Film dan Animasi", "Musik", "Tata Rias", "Tata Busana", "Tata Boga",
				"Sekretaris", "Administrasi Asuransi dan Aktuaria", "Administrasi Keuangan dan Perbankan",
				"Administrasi Perkantoran dan Sekretaris", "Administrasi Perpajakan", "Administrasi Bisnis",
				"Fisioterapi", "Hubungan Masyarakat", "Manajemen Informasi dan Dokumentasi",
				"Vokasional Pariwisata", "Okupasi Terapi", "Penyiaran Multimedia", "Periklanan Kreatif",
				"Akuntansi", "Administrasi Perumahsakitan", "Manajemen Perhotelan", "Desain Grafis",
				"Batik dan Fashion", "Akuntansi perpajakan", "Akuntansi sektor publik", "Bisnis internasional",
				"Pemasaran digital"
			}
		);
		d_jurusan->width = 51;
		auto c_sdk = checkbox("Saya menyetujui syarat dan ketentuan");
		auto c_notif = checkbox("Saya ingin menerima notifikasi");
		auto confirm = [&]() -> bool {
			bool loop = true;
			bool returning = false;
			auto b_ok = button("Lanjut", [&]() { loop = false; returning = true; });
			auto b_no = button("Kembali", [&]() { loop = false; returning = false; });
			auto layout = vlayout(
				vlayout(
					text("Konfirmasi") | border_rounded | hcenter,
					text("Apakah data yang anda masukkan sudah benar?") | hcenter,
					vspace(),
					vlayout(
						hlayout(text("Nama Lengkap        : "), text(i_nama_depan->get_value()), hspace(), text(i_nama_belakang->get_value())),
						hlayout(text("Jenis Kelamin       : "), text(gr_jenis_kelamin.selected()->get_name())),
						hlayout(text("Alamat Rumah        : "), text(i_alamat->get_value())),
						hlayout(text("Agama               : "), text(gr_agama.selected()->get_name())),
						hlayout(text("Nomor Telepon       : "), text(i_hp->get_value())),
						hlayout(text("Jurusan yang dituju : "), text(d_jurusan->get_value()))
					) | border_rounded | hcenter,
					hlayout(b_no, hspace(), b_ok) | hcenter
				) | border_double_line | center | hflex
			);
			auto component = hcontainer(b_no, b_ok);

			application::render_by_condition(loop, layout, component);

			return returning;
			};
		auto b_daftar = button("Daftar",
			[&]() {
				if (i_nama_depan->get_value().empty()) {
					notification("Nama depan tidak boleh kosong.");
				}
				else if (i_nama_belakang->get_value().empty()) {
					notification("Nama belakang tidak boleh kosong.");
				}
				else if (!gr_jenis_kelamin.selected()) {
					notification("Jenis kelamin harus dipilih.");
				}
				else if (i_alamat->get_value().empty()) {
					notification("Alamat tidak boleh kosong.");
				}
				else if (!gr_agama.selected()) {
					notification("Agama harus dipilih.");
				}
				else if (i_hp->get_value().empty()) {
					notification("Nomor telepon tidak boleh kosong.");
				}
				else if (d_jurusan->get_value() == "") {
					notification("Jurusan harus dipilih.");
				}
				else if (!c_sdk->selected()) {
					notification("Syarat dan ketentuan harus disetujui.");
				}
				else {
					if (confirm()) {
						notification("Pendaftaran berhasil");
						application::stop();
					}
				}
			}
		);
		auto b_exit = button("Keluar", [&]() { application::stop(); });
		auto form_daftar_layout = vlayout(
			vlayout(
				text("PENDAFTARAN MAHASISWA BARU")
				| border_rounded
				| hcenter,
				text("Nama Lengkap"),
				hlayout(i_nama_depan, hspace(), i_nama_belakang),
				text("Jenis Kelamin"),
				hlayout(r_laki_laki, hspace(), r_perempuan),
				text("Alamat Rumah"),
				i_alamat,
				text("Agama"),
				hlayout(r_islam, hspace(), r_kristen1, hspace(), r_kristen2),
				hlayout(r_hindu, hspace(), r_buddha, hspace(), r_konghuchu),
				text("Nomor Telepon"),
				hlayout(text("+62"), i_hp),
				text("Jurusan yang dituju"),
				d_jurusan,
				vlayout(c_sdk, c_notif) | hcenter,
				b_daftar | hflex,
				b_exit | hflex
			)
			| border_double_line
			| center
			| hflex
		);
		auto form_daftar_container = vcontainer(
			hcontainer(i_nama_depan, i_nama_belakang),
			hcontainer(r_laki_laki, r_perempuan),
			i_alamat,
			hcontainer(r_islam, r_kristen1, r_kristen2),
			hcontainer(r_hindu, r_buddha, r_konghuchu),
			i_hp,
			d_jurusan,
			c_sdk,
			c_notif,
			b_daftar,
			b_exit
		);
		application::render(form_daftar_layout, form_daftar_container);
		return 0;
	}
	void notification(std::string message) {
		bool loop = true;
		auto b_ok = button("OK", [&loop]() { loop = false; });
		auto layout = vlayout(
			vlayout(
				text("Notification")
				| border_rounded
				| hcenter,
				text(message) | hcenter,
				vspace(),
				b_ok | hcenter
			)
			| border_double_line
			| center
			| hflex
		);
		auto component = vcontainer(b_ok);

		application::render_by_condition(loop, layout, component);
	}
};

int main() {
	HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(output_handle, &csbi);
	app app(csbi.srWindow.Bottom - csbi.srWindow.Top + 1, csbi.srWindow.Right - csbi.srWindow.Left + 1);
	app.run();
}