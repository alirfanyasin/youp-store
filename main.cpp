#include <iostream>
#include <string>
#include<unistd.h>
using namespace std;

// Deklarasi prototipe fungsi
void tampilkanInfo(string* merk_tas, int* harga_tas);
void masukkanData();
void pembayaran(string merkDipilih[], int hargaDipilih[], int jmlProduk[], int jumlahDipilih);

// variable global
string nama, alamat, email;


int main() {
  // Variable
  char kode_tas;
  int harga_tas;
  string merk_tas;
  const int MAX_PRODUK = 100; // Tentukan maksimal produk yang dapat dipilih
  string merkDipilih[MAX_PRODUK];  // Array untuk menyimpan merk produk yang dipilih
  int hargaDipilih[MAX_PRODUK];  // Array untuk menyimpan harga produk yang dipilih
  int jumlahDipilih = 0; // Jumlah produk yang dipilih
  int jmlProduk[MAX_PRODUK];

start:
  // Menu
  while (1) {
    // Clear screen
    system("cls");
    // Menu
    cout << "==============================" << endl;
    cout << "          AYOP STORE          " << endl;
    cout << "==============================" << endl;
    cout << "| KODE |   BRAND   |  HARGA  |" << endl;
    cout << "------------------------------" << endl;
    cout << "|  C   |   Gucci   | 350000  |" << endl;
    cout << "|  D   |   Eiger   | 500000  |" << endl;
    cout << "|  E   |   Osprey  | 800000  |" << endl;
    cout << "Masukkan kode tas [C/D/E] : "; cin >> kode_tas;

    switch (kode_tas) {
    case 'C':
      merk_tas = "Gucci";
      harga_tas = 350000;
      tampilkanInfo(&merk_tas, &harga_tas);
      // tampilkanInfo(merk_tas, harga_tas);
      break;
    case 'D':
      merk_tas = "Eiger";
      harga_tas = 500000;
      tampilkanInfo(&merk_tas, &harga_tas);
      // tampilkanInfo(merk_tas, harga_tas);
      break;
    case 'E':
      merk_tas = "Osprey";
      harga_tas = 800000;
      tampilkanInfo(&merk_tas, &harga_tas);
      // tampilkanInfo(merk_tas, harga_tas);
      break;
    default:
      cout << "Mohon maaf kode tas tidak tersedia!\n";
      sleep(2);
      goto start;
      break;
    }

    int jumlah;
    cout << "Masukkan jumlah : "; cin >> jumlah;

    merkDipilih[jumlahDipilih] = merk_tas;  // Menambahkan merk ke dalam array
    hargaDipilih[jumlahDipilih] = harga_tas * jumlah;  // Menambahkan harga ke dalam array
    jmlProduk[jumlahDipilih] = jumlah; // Menambahkan harga ke dalam array
    jumlahDipilih++;

    char input;
    cout << "Apakah mau beli lagi ? (y/n) : "; cin >> input;
    if (input != 'y' && input != 'Y') {
      masukkanData();
      pembayaran(merkDipilih, hargaDipilih, jmlProduk, jumlahDipilih);
      break;
    }
  }

  return 0;
}

// void tampilkanInfo(string merk_tas, int harga_tas) {
//   cout << "Merk Tas\t\t: " << merk_tas << endl;
//   cout << "Harga Tas\t\t: " << harga_tas << endl;
// }

// Menggunakan operator dereference (*) untuk mengakses nilai yang ditunjuk oleh pointer
void tampilkanInfo(string* merk_tas, int* harga_tas) {
    cout << "Merk Tas\t\t: " << *merk_tas << endl;
    cout << "Harga Tas\t\t: " << *harga_tas << endl;
}

void masukkanData() {
  system("cls");
  cout << "==============================" << endl;
  cout << "           DATA DIRI          " << endl;
  cout << "==============================" << endl;
  cout << "Masukkan nama\t: ";
  cin.ignore();  // Membersihkan buffer
  getline(cin, nama);
  cout << "Masukkan alamat\t: ";
  getline(cin, alamat);
  cout << "Masukkan email\t: ";
  getline(cin, email);
}

void pembayaran(string merkDipilih[], int hargaDipilih[], int jmlProduk[],int jumlahDipilih) {
  pembayaran:
  system("cls");
  int totalHarga = 0;
  int bayar;

  // Tampilkan data produk yang sudah dipilih menggunakan perulangan
  cout << "===============================" << endl;
  cout << "|           INVOICE           |" << endl;
  cout << "===============================" << endl;
  cout << "|   MERK   |  HARGA  | JUMLAH |" << endl;
  cout << "-------------------------------" << endl;

  for (int i = 0; i < jumlahDipilih; i++) {
    cout << "   " << merkDipilih[i] << "     " << hargaDipilih[i] << "      "<< jmlProduk[i] <<" " << endl;
    totalHarga += hargaDipilih[i] * jmlProduk[i];
  }

  cout << "------------------------------" << endl;
  cout << "NAMA\t\t: " << nama << endl;
  cout << "ALAMAT\t\t: " << alamat << endl;
  cout << "EMAIL\t\t: " << email << endl;
  cout << "TOTAL HARGA\t: Rp." << totalHarga << endl;
  cout << "BAYAR\t\t: Rp."; cin >> bayar;

  if(bayar < totalHarga) {
    cout << "Uang Anda tidak cukup!\n";
    sleep(2);
    goto pembayaran;
  }else {
    cout << "KEMBALIAN\t: Rp." << bayar - totalHarga << endl;
    cout << "\n";
    cout << "Terimakasih :)\n";
  }
}
