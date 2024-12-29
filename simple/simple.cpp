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
	SetConsoleOutputCP(CP_UTF8);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	auto canvas = simple::canvas(csbi.srWindow.Bottom - csbi.srWindow.Top + 1, csbi.srWindow.Right - csbi.srWindow.Left + 1);

	std::vector<std::string> address{
		"Cecilia Chapman 711 - 2880 Nulla St. Mankato Mississippi 96522  (257) 563 - 7401",
		"Iris Watson P.O.Box 283 8562 Fusce Rd. Frederick Nebraska 20620  (372) 587 - 2335",
		"Celeste Slater 606 - 3727 Ullamcorper.Street Roseville NH 11523  (786) 713 - 8616",
		"Theodore Lowe Ap #867 - 859 Sit Rd. Azusa New York 39531  (793) 151 - 6230",
		"Calista Wise 7292 Dictum Av. San Antonio MI 47096  (492) 709 - 6392",
		"Kyla Olsen Ap #651 - 8679 Sodales Av. Tamuning PA 10855  (654) 393 - 5734",
		"Forrest Ray 191 - 103 Integer Rd. Corona New Mexico 08219 (404) 960 - 3807",
		"Hiroko Potter P.O.Box 887 2508 Dolor.Av. Muskegon KY 12482  (314) 244 - 6306",
		"Nyssa Vazquez 511 - 5762 At Rd. Chelsea MI 67708  (947) 278 - 5929",
		"Lawrence Moreno 935 - 9940 Tortor.Street Santa Rosa MN 98804  (684) 579 - 1879",
		"Ina Moran P.O.Box 929 4189 Nunc Road Lebanon KY 69409  (389) 737 - 2852",
		"Aaron Hawkins 5587 Nunc.Avenue Erie Rhode Island 24975  (660) 663 - 4518",
		"Hedy Greene Ap #696 - 3279 Viverra.Avenue Latrobe DE 38100  (608) 265 - 2215",
		"Melvin Porter P.O.Box 132 1599 Curabitur Rd. Bandera South Dakota 45149  (959) 119 - 8364",
		"Keefe Sellers 347 - 7666 Iaculis St. Woodruff SC 49854  (468) 353 - 2641",
		"Joan Romero 666 - 4366 Lacinia Avenue Idaho Falls Ohio 19253  (248) 675 - 4007",
		"Davis Patrick P.O.Box 147 2546 Sociosqu Rd. Bethlehem Utah 02913 (939) 353 - 1107",
		"Leilani Boyer 557 - 6308 Lacinia Road San Bernardino ND 09289 (570) 873 - 7090",
		"Colby Bernard Ap #285 - 7193 Ullamcorper Avenue Amesbury HI 93373  (302) 259 - 2375",
		"Bryar Pitts 5543 Aliquet St. Fort Dodge GA 20783  (717) 450 - 4729",
		"Rahim Henderson 5037 Diam Rd. Daly City Ohio 90255  (453) 391 - 4650",
		"Noelle Adams 6351 Fringilla Avenue Gardena Colorado 37547  (559) 104 - 5475",
		"Lillith Daniel 935 - 1670 Neque.St. Centennial Delaware 48432  (387) 142 - 9434",
		"Adria Russell 414 - 7533 Non Rd. Miami Beach North Dakota 58563  (516) 745 - 4496",
		"Hilda Haynes 778 - 9383 Suspendisse Av. Weirton IN 93479  (326) 677 - 3419",
		"Sheila Mcintosh P.O.Box 360 4407 Et Rd. Santa Monica FL 30309  (746) 679 - 2470",
		"Rebecca Chambers P.O.Box 813 5982 Sit Ave Liberal Vermont 51324  (455) 430 - 098",
		"Christian Emerson P.O.Box 886 4118 Arcu St. Rolling Hills Georgia 92358  (490) 936 - 4694",
		"Nevada Ware P.O.Box 597 4156 Tincidunt Ave Green Bay Indiana 19759  (985) 834 - 8285",
		"Margaret Joseph P.O.Box 508 3919 Gravida St. Tamuning Washington 55797  (662) 661 - 1446",
		"Edward Nieves 928 - 3313 Vel Av. Idaho Falls Rhode Island 37232  (802) 668 - 8240",
		"Imani Talley P.O.Box 262 4978 Sit St. Yigo Massachusetts 50654  (477) 768 - 9247",
		"Bertha Riggs P.O.Box 206 6639 In St. Easthampton TN 31626  (791) 239 - 9057",
		"Wallace Ross 313 Pellentesque Ave Villa Park Hawaii 43526  (832) 109 - 0213",
		"Chester Bennett 3476 Aliquet.Ave Minot AZ 95302  (837) 196 - 3274",
		"Castor Richardson P.O.Box 902 3472 Ullamcorper Street Lynchburg DC 29738  (268) 442 - 2428",
		"Sonya Jordan Ap #443 - 336 Ullamcorper.Street Visalia VA 54886  (850) 676 - 5117",
		"Harrison Mcguire 574 - 8633 Arcu Street San Fernando ID 77373  (861) 546 - 5032",
		"Malcolm Long 9291 Proin Road Lake Charles Maine 11292  (176) 805 - 4108",
		"Raymond Levy Ap #643 - 7006 Risus St. Beaumont New Mexico 73585  (715) 912 - 6931",
		"Hedley Ingram 737 - 2580 At Street Independence Texas 87535  (993) 554 - 0563",
		"David Mathews 1011 Malesuada Road Moscow Kentucky 77382  (357) 616 - 5411",
		"Xyla Cash 969 - 1762 Tincidunt Rd. Boise CT 35282  (121) 347 - 008",
		"Madeline Gregory 977 - 4841 Ut Ave Walla Walla Michigan 82776  (304) 506 - 6314",
		"Griffith Daniels 6818 Eget St. Tacoma AL 92508  (425) 288 - 2332",
		"Anne Beasley 987 - 4223 Urna St. Savannah Illinois 85794  (145) 987 - 4962",
		"Chaney Bennett P.O.Box 721 902 Dolor Rd. Fremont AK 19408  (187) 582 - 9707",
		"Daniel Bernard P.O.Box 567 1561 Duis Rd. Pomona TN 08609 (750) 558 - 3965",
		"Willow Hunt Ap #784 - 1887 Lobortis Ave Cudahy Ohio 31522  (492) 467 - 3131",
		"Judith Floyd 361 - 7936 Feugiat St. Williston Nevada 58521  (774) 914 - 2510",
		"Seth Farley 6216 Aenean Avenue Seattle Utah 81202  (888) 106 - 8550",
		"Zephania Sanders 3714 Nascetur St. Hawthorne Louisiana 10626  (539) 567 - 3573",
		"Calista Merritt Ap #938 - 5470 Posuere Ave Chickasha LA 58520  (693) 337 - 2849",
		"Craig Williams P.O.Box 372 5634 Montes Rd. Springdale MO 57692  (545) 604 - 9386",
		"Lee Preston 981 Eget Rd. Clemson GA 04645  (221) 156 - 5026",
		"Katelyn Cooper 6059 Sollicitudin Road Burlingame Colorado 26278  (414) 876 - 086",
		"Lacy Eaton 1379 Nulla.Av. Asbury Park Montana 69679  (932) 726 - 8645",
		"Driscoll Leach P.O.Box 120 2410 Odio Avenue Pass Christian Delaware 03869 (726) 710 - 9826",
		"Merritt Watson P.O.Box 686 7014 Amet Street Corona Oklahoma 55246  (622) 594 - 1662",
		"Nehru Holmes P.O.Box 547 4764 Sed Road Grand Rapids CT 87323  (948) 600 - 8503",
		"Quamar Rivera 427 - 5827 Ac St. Schaumburg Arkansas 84872  (605) 900 - 7508",
		"Hiram Mullins 754 - 6427 Nunc Ave Kennewick AL 41329  (716) 977 - 5775",
		"Kim Fletcher Ap #345 - 3847 Metus Road Independence CO 30135  (368) 239 - 8275",
		"Rigel Koch P.O.Box 558 9561 Lacus.Road Laughlin Hawaii 99602  (725) 342 - 0650",
		"Jeanette Sharpe Ap #364 - 2006 Ipsum Avenue Wilmington Ohio 91750  (711) 993 - 5187",
		"Dahlia Lee 1293 Tincidunt Street Atwater Pennsylvania 76865  (882) 399 - 5084",
		"Howard Hayden P.O.Box 847 8019 Facilisis Street Joliet SC 73490  (287) 755 - 9948",
		"Hyatt Kramer 1011 Massa Av. Kent ID 63725  (659) 551 - 3389",
		"Sonya Ray Ap #315 - 8441 Eleifend Street Fairbanks RI 96892  (275) 730 - 6868",
		"Cara Whitehead 4005 Praesent St. Torrance Wyoming 22767  (725) 757 - 4047",
		"Blythe Carroll 7709 Justo.Ave Princeton TX 77987  (314) 882 - 1496",
		"Dale Griffin P.O.Box 854 8580 In Ave Revere South Dakota 43841  (639) 360 - 7590",
		"McKenzie Hernandez Ap #367 - 674 Mi Street Greensboro VT 40684  (168) 222 - 1592",
		"Haviva Holcomb P.O.Box 642 3450 In Road Isle of Palms New York 03828 (896) 303 - 1164",
		"Ezra Duffy Ap #782 - 7348 Dis Rd. Austin KY 50710  (203) 982 - 6130",
		"Eleanor Jennings 9631 Semper Ave Astoria NJ 66309  (906) 217 - 1470",
		"Remedios Hester 487 - 5787 Mollis St. City of Industry Louisiana 67973  (614) 514 - 1269",
		"Jasper Carney 1195 Lobortis Rd. New Orleans New Hampshire 71983  (763) 409 - 5446",
		"Vielka Nielsen Ap #517 - 7326 Elementum Rd. Fort Smith North Dakota 79637  (836) 292 - 5324",
		"Wilma Pace Ap #676 - 6532 Odio Rd. Darlington CO 06963 (926) 709 - 3295",
		"Palmer Gay 557 - 2026 Purus St. Watertown TN 07367  (963) 356 - 9268",
		"Lyle Sutton Ap #250 - 9843 Elementum St. South Gate Missouri 68999  (736) 522 - 8584",
		"Ina Burt Ap #130 - 1685 Ut Street Tyler KS 73510  (410) 483 - 0352",
		"Cleo Best 282 - 8351 Tincidunt Ave Sedalia Utah 53700  (252) 204 - 1434",
		"Hu Park 1429 Netus Rd. Reedsport NY 48247  (874) 886 - 4174",
		"Liberty Walton 343 - 6527 Purus.Avenue Logan NV 12657  (581) 379 - 7573",
		"Aaron Trujillo Ap #146 - 3132 Cras Rd. Kingsport NH 56618  (983) 632 - 8597",
		"Elmo Lopez Ap #481 - 7473 Cum Rd. Yorba Linda South Carolina 28423  (295) 983 - 3476",
		"Emerson Espinoza Ap #247 - 5577 Tincidunt St. Corpus Christi WI 97020  (873) 392 - 8802",
		"Daniel Malone 2136 Adipiscing Av. Lima RI 93490  (360) 669 - 3923",
		"Dante Bennett 481 - 8762 Nulla Street Dearborn OR 62401  (840) 987 - 9449",
		"Sade Higgins Ap #287 - 3260 Ut St. Wilmington OR 05182 (422) 517 - 6053",
		"Zorita Anderson 1964 Facilisis Avenue Bell Gardens Texas 87065  (126) 940 - 2753",
		"Jordan Calderon 430 - 985 Eleifend St. Duluth Washington 92611  (427) 930 - 5255",
		"Ivor Delgado Ap #310 - 1678 Ut Av. Santa Barbara MT 88317  (689) 721 - 5145",
		"Pascale Patton P.O.Box 399 4275 Amet Street West Allis NC 36734  (676) 334 - 2174",
		"Nasim Strong Ap #630 - 3889 Nulla.Street Watervliet Oklahoma 70863  (437) 994 - 5270",
		"Keaton Underwood Ap #636 - 8082 Arcu Avenue Thiensville Maryland 19587  (564) 908 - 6970",
		"Keegan Blair Ap #761 - 2515 Egestas.Rd. Manitowoc TN 07528 (577) 333 - 6244",
		"Tamara Howe 3415 Lobortis.Avenue Rocky Mount WA 48580  (655) 840 - 6139"
	};

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
				hlayout(hfill(), b_daftar) | hflex,
				hlayout(hfill(), b_exit) | hflex
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