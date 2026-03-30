#include <iostream> //Untuk input (cin) dan output (cout).
#include <string> //Karena kita mengolah angka biner sebagai teks (string).
#include <algorithm>//Menyediakan fungsi seperti mencari nilai terbesar (max), terkecil (min), mengurutkan data (sort), atau membalikkan urutan (reverse).
#include <windows.h> //Khusus untuk fungsi Sleep
#include <iomanip> //Singkatan dari Input/Output Manipulation. Dipakai untuk mengatur jarak teks (setw) dan format angka (hex, oct).
#include <sstream> //Digunakan untuk mengubah string menjadi tipe data lain (seperti int atau float) atau sebaliknya dengan cara yang lebih fleksibel dibanding cin biasa.

using namespace std;

// Fungsi pembantu untuk konversi angka ke string biner
string keBiner(unsigned long long n) {
    if (n == 0) return "0";
    string r = "";
    while (n > 0) {
        r = (n % 2 == 0 ? "0" : "1") + r; // Ambil sisa bagi 2
        n /= 2; // Bagi terus sampai habis
    }
    return r;
}

// Fungsi animasi utama
void animasiTambahBiner(string a, string b) {
    string hasil = "";
    // Variabel s: Ini adalah simpanan. Kalau $1+1$, hasilnya $0$ simpan $1$.
    int s = 0; 
    int i = a.size() - 1, j = b.size() - 1;
    int step = 1;
    
    cout << "\n[ MEMULAI ANIMASI PENJUMLAHAN BINER ]" << endl;
    int width = max(a.size(), b.size());
    cout << "  " << setw(width) << a << " (A)" << endl;
    cout << "  " << setw(width) << b << " (B)" << endl;
    cout << "  " << string(width + 2, '-') << " +" << endl;

    // Loop while: Berjalan dari bit paling kanan ke kiri (seperti kita menghitung di kertas).
    while (i >= 0 || j >= 0 || s == 1) {
        // Baris bitA = a[i] - '0': Ini trik C++ untuk mengubah karakter '1' menjadi angka 1 sungguhan supaya bisa dijumlahkan secara matematika.
        int bitA = (i >= 0) ? a[i] - '0' : 0;
        int bitB = (j >= 0) ? b[j] - '0' : 0;
        
        int sum = bitA + bitB + s;
        hasil = to_string(sum % 2) + hasil;
        s = sum / 2;
        
        cout << "Step " << step++ << ": BitA(" << bitA << ") + BitB(" << bitB << ") + Carry(" << (sum-bitA-bitB) << ")";
        cout << " -> Hasil: " << (sum%2) << ", Carry Baru: " << s << endl;
        cout << "Temporary: " << hasil << endl;
        cout << "-------------------------------------------" << endl;
        
        Sleep(800); 
        if (i >= 0) i--; 
        if (j >= 0) j--;
    }
    
    unsigned long long desimal = stoull(hasil, nullptr, 2);
    //Setelah animasi selesai, kita punya hasil dalam bentuk string biner. Untuk menampilkan basis lainnya, kita pakai manipulator:
    cout << "\n======================================" << endl;
    cout << "          HASIL KONVERSI AKHIR        " << endl;
    cout << "======================================" << endl;
    cout << left << setw(15) << "BINER"       << ": " << hasil << endl;
    cout << left << setw(15) << "DESIMAL"     << ": " << dec << desimal << endl;
    cout << left << setw(15) << "OKTAL"       << ": " << oct << desimal << endl;
    cout << left << setw(15) << "HEKSADESIMAL" << ": " << hex << uppercase << desimal << endl;
    cout << "======================================" << dec << endl; 
}

int main() {
    int pilihan;
    string input1, input2;
    unsigned long long n1, n2;

    cout << "=== KALKULATOR MULTI-BASIS RENA SHOP ===" << endl;
    cout << "Pilih basis input:\n";
    cout << "1. Biner (Base 2)\n";
    cout << "2. Desimal (Base 10)\n";
    cout << "3. Oktal (Base 8)\n";
    cout << "4. Heksadesimal (Base 16)\n";
    cout << "Pilihan (1-4): "; cin >> pilihan;

    cout << "Masukkan angka pertama: "; cin >> input1;
    cout << "Masukkan angka kedua: "; cin >> input2;
//stoull(input, nullptr, basis): Ini fungsi kunci. Singkatannya String To Unsigned Long Long. Parameter terakhirnya (basis) sangat fleksibel. Kalau user input oktal, kita kasih basis 8, otomatis dia jadi angka desimal di memori komputer.
//try-catch: Ini untuk jaga-jaga. Kalau user pilih menu "Biner" tapi malah ngetik "99" (yang mana bukan biner), program akan loncat ke bagian catch dan menampilkan pesan error daripada crash.
    try {
        // Konversi input user ke Desimal dulu sebagai perantara
        if (pilihan == 1) {
            n1 = stoull(input1, nullptr, 2);
            n2 = stoull(input2, nullptr, 2);
        } else if (pilihan == 2) {
            n1 = stoull(input1, nullptr, 10);
            n2 = stoull(input2, nullptr, 10);
        } else if (pilihan == 3) {
            n1 = stoull(input1, nullptr, 8);
            n2 = stoull(input2, nullptr, 8);
        } else if (pilihan == 4) {
            n1 = stoull(input1, nullptr, 16);
            n2 = stoull(input2, nullptr, 16);
        } else {
            cout << "Pilihan tidak valid!";
            return 1;
        }

        // Jalankan animasi dengan mengubah n1 & n2 ke biner string
        animasiTambahBiner(keBiner(n1), keBiner(n2));

    } catch (...) {
        cout << "\n[!] Error: Input tidak sesuai dengan basis yang dipilih!\n";
    }

    return 0;
}