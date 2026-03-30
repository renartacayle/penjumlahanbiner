🧮 Multi-Basis Calculator (Rena Shop Edition)
Program kalkulator berbasis CLI (Command Line Interface) yang dirancang untuk membantu konversi dan penjumlahan antar berbagai basis bilangan. Program ini dilengkapi dengan fitur animasi proses untuk memvisualisasikan bagaimana komputer melakukan penjumlahan biner di tingkat rendah.

🌟 Fitur Utama
Multi-Basis Input: Mendukung input dalam format Biner (Base 2), Desimal (Base 10), Oktal (Base 8), dan Heksadesimal (Base 16).

Animasi Penjumlahan: Menampilkan simulasi step-by-step penjumlahan biner, termasuk penanganan carry bit (simpanan).

Auto-Conversion: Setelah perhitungan selesai, hasil akan ditampilkan langsung dalam 4 basis sekaligus.

Error Handling: Menggunakan blok try-catch untuk mencegah program crash jika pengguna memasukkan angka yang tidak sesuai dengan basis yang dipilih.

🚀 Cara Kerja Program
Input: User memilih basis awal dan memasukkan dua angka.

Processing:

Program mengonversi input ke tipe data unsigned long long menggunakan fungsi stoull.

Fungsi animasiTambahBiner dipanggil untuk memulai simulasi.

Visualization: Loop berjalan dari bit paling kanan ke kiri, menjumlahkan setiap bit, dan menampilkan status carry secara real-time.

Output: Hasil akhir ditampilkan dalam tabel yang rapi menggunakan setw dari library <iomanip>.

🛠️ Prasyarat & Menjalankan Program
Program ini menggunakan library <windows.h> untuk fungsi Sleep(), sehingga paling optimal dijalankan di lingkungan Windows.

Cara Compile (G++):
Bash
g++ -o kalkulator_rena main.cpp
./kalkulator_rena
📂 Struktur Kode
keBiner(): Fungsi rekursif/looping untuk mengubah angka desimal menjadi string biner.

animasiTambahBiner(): Inti dari visualisasi penjumlahan.

main(): Antarmuka menu utama dan penanganan input pengguna.

📝 Catatan Proyek
Proyek ini dikembangkan sebagai bagian dari studi Teknik Informatika di UDINUS. Fokus utama adalah pemahaman sistem bilangan dan logika pemrograman C++.

Dibuat oleh: [Rena/Renarta]

Owner of: RENA SHOP 🌿
