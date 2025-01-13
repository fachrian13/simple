#include "simple.h"

#include "simple/renderable/vertical_layout.h"
#include "simple/renderable/horizontal_layout.h"
#include "simple/renderable/text.h"
#include "simple/renderable/center.h"
#include "simple/renderable/horizontal_space.h"
#include "simple/renderable/vertical_space.h"

#include "simple/focusable/vertical_container.h"
#include "simple/focusable/horizontal_container.h"
#include "simple/focusable/input.h"
#include "simple/focusable/button.h"
#include "simple/focusable/dropdown.h"

#include "simple/selectable/radiobox.h"
#include "simple/selectable/checkbox.h"

#include "simple/modifier/flex.h"
#include "simple/modifier/border.h"

class my_app final : public simple::application {
public:
	my_app(int height, int width) :
		application(height, width) {
	}

private:
	void main() override {
		std::vector<std::string> list_jurusan = {
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
		};

		auto input_nama_depan = input("Nama Depan");
		input_nama_depan->width = 25;
		auto input_nama_belakang = input("Nama Belakang (Opsional)");
		input_nama_belakang->width = 25;
		auto radiobox_laki_laki = radiobox("Laki-Laki");
		auto radiobox_perempuan = radiobox("Perempuan");
		auto selectable_group_jenis_kelamin = selectable_group(
			radiobox_laki_laki,
			radiobox_perempuan
		);
		auto input_alamat = input();
		input_alamat->width = 51;
		input_alamat->height = 3;
		auto radiobox_islam = radiobox("Islam");
		auto radiobox_kristen1 = radiobox("Kristen Katolik");
		auto radiobox_kristen2 = radiobox("Kristen Protestan");
		auto radiobox_hindu = radiobox("Hindu");
		auto radiobox_buddha = radiobox("Buddha");
		auto radiobox_konghuchu = radiobox("Konghuchu");
		auto selectable_group_agama = selectable_group(
			radiobox_islam,
			radiobox_kristen1,
			radiobox_kristen2,
			radiobox_hindu,
			radiobox_buddha,
			radiobox_konghuchu
		);
		auto input_nomor_hp = input();
		input_nomor_hp->width = 47;
		input_nomor_hp->pattern = isdigit;
		input_nomor_hp->limit = 13;
		auto dropdown_jurusan = dropdown("Silakan pilih", list_jurusan);
		dropdown_jurusan->width = 51;
		auto checkbox_sdk = checkbox("Saya menyetujui syarat dan ketentuan.");
		auto checkbox_email = checkbox("Kirim saya email notifikasi.");
		auto function_wrap_alamat = [&]() -> std::shared_ptr<simple::renderable> {
			std::istringstream ist(input_alamat->get_value());
			std::string word;
			std::string line;
			std::vector<std::shared_ptr<simple::renderable>> elements;

			while (ist >> word) {
				if (line.length() + word.length() + 1 > 50) {
					elements.emplace_back(text(line));
					line = word;
				}
				else {
					if (!line.empty()) {
						line += " ";
					}
					line += word;
				}
			}

			if (!line.empty()) {
				elements.emplace_back(text(line));
			}

			return vlayout(std::move(elements));
			};
		auto function_daftar = [&]() -> bool {
			if (input_nama_depan->get_value().empty()) {
				notification("Silakan isi Nama depan.");
				return false;
			}
			else if (!selectable_group_jenis_kelamin.selected()) {
				notification("Pilih Jenis kelamin.");
				return false;
			}
			else if (input_alamat->get_value().empty()) {
				notification("Silakan isi Alamat.");
				return false;
			}
			else if (!selectable_group_agama.selected()) {
				notification("Silakan pilih Agama.");
				return false;
			}
			else if (input_nomor_hp->get_value().empty()) {
				notification("Silakan isi nomor telepon.");
				return false;
			}
			else if (dropdown_jurusan->get_value().empty()) {
				notification("Silakan pilih jurusan.");
				return false;
			}
			else if (!checkbox_sdk->selected())
			{
				notification("Syarat dan ketentuan harus disetujui.");
				return false;
			}
			return true;
			};
		auto function_konfirmasi = [&]() -> bool {
			bool result = false;
			bool looping = true;
			auto button_lanjutkan = button("Lanjutkan", [&]() { looping = false; result = true; });
			auto button_kembali = button("Kembali", [&]() { looping = false; });

			auto layout_konfirmasi = vlayout(
				vlayout(
					text("Apakah data berikut sudah benar?")
					| center
					| border_rounded
					| hflex,
					vlayout(
						hlayout(text("Nama lengkap   : "), text(input_nama_depan->get_value()), hspace(), text(input_nama_belakang->get_value())),
						hlayout(text("Jenis kelamin  : "), text(selectable_group_jenis_kelamin.selected()->get_name())),
						hlayout(text("Alamat lengkap : "), function_wrap_alamat()),
						hlayout(text("Agama          : "), text(selectable_group_agama.selected()->get_name())),
						hlayout(text("Nomor telepon  : "), text(input_nomor_hp->get_value())),
						hlayout(text("Jurusan        : "), text(dropdown_jurusan->get_value()))
					) | border_rounded,
					hlayout(
						button_kembali,
						hspace(),
						button_lanjutkan
					) | hcenter
				)
				| border_double_line
				| center
				| hflex
			);

			auto container_konfirmasi = hcontainer(
				button_kembali,
				button_lanjutkan
			);

			application::render(looping, layout_konfirmasi, container_konfirmasi);

			return result;
			};
		auto button_daftar = button("Daftar",
			[&]() {
				if (function_daftar()) {
					if (function_konfirmasi()) {
						notification("Pendaftaran mahasiswa berhasil.");
						application::stop();
					}
				}
			}
		);
		auto button_keluar = button("Keluar", [&]() { application::stop(); });

		auto layout_register = vlayout(
			vlayout(
				text("PENDAFTARAN MAHASISWA BARU")
				| hcenter
				| border_rounded
				| hflex,
				text("Nama lengkap"),
				hlayout(input_nama_depan, hspace(), input_nama_belakang),
				text("Jenis kelamin"),
				hlayout(radiobox_laki_laki, hspace(), radiobox_perempuan),
				text("Alamat lengkap"),
				input_alamat,
				text("Agama"),
				hlayout(radiobox_islam, hspace(), radiobox_kristen1, hspace(), radiobox_kristen2),
				hlayout(radiobox_hindu, hspace(), radiobox_buddha, hspace(), radiobox_konghuchu),
				text("Nomor telepon"),
				hlayout(text("+62-"), input_nomor_hp),
				text("Jurusan"),
				dropdown_jurusan,
				vlayout(
					checkbox_sdk,
					checkbox_email
				) | hcenter,
				button_daftar | hflex,
				button_keluar | hflex
			)
			| border_double_line
			| center
			| hflex
		);

		auto container_register = vcontainer(
			hcontainer(input_nama_depan, input_nama_belakang),
			hcontainer(radiobox_laki_laki, radiobox_perempuan),
			input_alamat,
			hcontainer(radiobox_islam, radiobox_kristen1, radiobox_kristen2),
			hcontainer(radiobox_hindu, radiobox_buddha, radiobox_konghuchu),
			input_nomor_hp,
			dropdown_jurusan,
			checkbox_sdk,
			checkbox_email,
			button_daftar,
			button_keluar
		);

		application::render(layout_register, container_register);
	}
	void notification(std::string value) {
		bool looping = true;
		auto button_ok = button("Ok", [&]() { looping = false; });
		auto layout_notification = vlayout(
			vlayout(
				text("Notification")
				| hcenter
				| border_rounded
				| hflex,
				vspace(),
				hlayout(
					hspace(2),
					text(value) | hcenter,
					hspace(2)
				) | hflex,
				vspace(),
				button_ok
				| hcenter
				| hflex
			)
			| border_double_line
			| center
			| hflex
		);

		application::render(looping, layout_notification, button_ok);
	}
};

int main() {
	HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(output_handle, &csbi);
	my_app app(csbi.srWindow.Bottom - csbi.srWindow.Top + 1, csbi.srWindow.Right - csbi.srWindow.Left + 1);
	app.run();
	return 0;
}