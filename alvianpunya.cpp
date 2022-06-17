#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Menu{
	public:
		int Q1, Q2, Q3, Q4, Q5;
		void HargaMakanan1 (){
			string N1 = "Ayam Goreng Crispy\t(Paha Atas)\t+ Nasi 'Free Es Teh'";
			int M1 = 20;
			int totalM1;
			totalM1 = Q1*M1;
			cout <<"\t"<<Q1<<" Pcs\t"<<N1<<" : \t""Rp"<<totalM1<<".000\n\n";
		}
		void HargaMakanan2 (){
			string N2 = "Ayam Goreng Crispy\t(Paha Bawah)\t+ Nasi 'Free Es Teh'";
			int M2 = 19;
			int totalM2;
			totalM2 = Q2*M2;
			cout <<"\t"<<Q2<<" Pcs\t"<<N2<<" : \t""Rp"<<totalM2<<".000\n\n";
		}
		void HargaMakanan3 (){
			string N3 = "Ayam Goreng Crispy\t(Dada)\t\t+ Nasi 'Free Es Teh'";
			int M3 = 21;
			int totalM3;
			totalM3 = Q3*M3;
			cout <<"\t"<<Q3<<" Pcs\t"<<N3<<" : \t""Rp"<<totalM3<<".000\n\n";
		}
		void HargaMakanan4 (){
			string N4 = "Ayam Goreng Crispy\t(Sayap)\t\t+ Nasi 'Free Es Teh'";
			int M4 = 18;
			int totalM4;
			totalM4 = Q4*M4;
			cout <<"\t"<<Q4<<" Pcs\t"<<N4<<" : \t""Rp"<<totalM4<<".000\n\n";
		}
		void HargaMakanan5 (){
			string N5 = "Es Teh\t\t\t(Besar)\t\t";
			int M5 = 10;
			int totalM5;
			totalM5 = Q5*M5;
			cout <<"\t"<<Q5<<" Pcs\t"<<N5<<"\t\t     : \t""Rp"<<totalM5<<".000\n\n";
		}
};

void Kasir(){
	cout << "\n\tMasukkan Username dan Password anda\n";
	CobaLagi:
	int salah;
	string username_in, pass_in;
	string username = "Alfian";
	string pass = "161002";
	salah = 1;
	do {
		cout << "\tUsername : "; cin >> username_in;
		cout << "\tPassword : "; cin >> pass_in;
	if (username_in == username && pass_in == pass){
		system ("cls");
		cout << "\t\t   ==============================================================\n";
		cout << "\t\t   SELAMAT DATANG DI APLIKASI KASIR RESTORAN KASIH FRIED CHICKEN\n\t\t   ==============================================================\n";
		cout << "\t\t\t    Jl. Harapan Masa Depan No.16, Kota Surabaya\n\n";
		return;
	}
	else {
		cout <<"Percobaan Ke-"<<salah<<"\n\n";
		cout << "Username atau Password anda Salah\n";
		salah++;
		}
	}
	while (salah<=3); {
		cout << "Anda Sudah Salah 3 Kali\nSilahkan coba beberapa saat lagi\n\n";
		cout << "Ingin Mnecoba Lagi ?\n";
		string cek1 = "Yes";
		string cek2;
		cout << "Pilih Salah Satu Jawaban : Yes or No\n"; cin >> cek2;
		if (cek2 == cek1){
		goto CobaLagi;
		}
		else {
			exit(0);
		}
	}
}

void login(){
	UlangLogin:
	cout << "\t\t\t\t     Apakah Anda Operator Kasir ?\n";
	char cek;
	cout << "\t\t\t\t\t1.Yes   2.No   3.Exit\n\t\t\t\t\t\t "; cin >> cek;
	if (cek == '1'){
		Kasir();
	}
	else if (cek == '2'){
		cout << "\t\t\t\tMohon Maaf Anda Tidak Memiliki Akses\n";
		exit(0);
	}
	else if (cek == '3'){
		system ("cls");
		cout << "Sampai Jumpa di Hari Berikutnya, Semoga Harimu Menyenangkan, Terima Kasih :) ";
		exit(0);
	}
	else {
		cout << "\n\t\t\t       Perhatikan dengan benar pilihan anda\n\n";
		goto UlangLogin;
	}
}


int main (){
	UlangBeranda:
	cout << "\t\t   ==============================================================\n";
	cout << "\t\t   SELAMAT DATANG DI APLIKASI KASIR RESTORAN KASIH FRIED CHICKEN\n\t\t   ==============================================================\n";
	cout << "\t\t\t    Jl. Harapan Masa Depan No.16, Kota Surabaya\n\n";
	login();
	UlangProses:
	cout << "\t ================================== DAFTAR MENU ==================================\n";
	cout << "\t ---------------------------------------------------------------------------------\n";
	cout << "\t   No.\t\tNama\t\t   Size\t\t\tBonus\t\t  Harga\n";
	cout << "\t   1.\tAyam Goreng Crispy\t(Paha Atas)\t+ Nasi 'Free Es Teh'\tRp20.000\n";
	cout << "\t   2.\tAyam Goreng Crispy\t(Paha Bawah)\t+ Nasi 'Free Es Teh'\tRp19.000\n";
	cout << "\t   3.\tAyam Goreng Crispy\t(Dada)\t\t+ Nasi 'Free Es Teh'\tRp21.000\n";
	cout << "\t   4.\tAyam Goreng Crispy\t(Sayap)\t\t+ Nasi 'Free Es Teh'\tRp18.000\n";
	cout << "\t   5.\tEs Teh\t\t\t(Besar)\t\t\t\t\tRp10.000\n";
	
	int itm, itm0;
	cout << "\n\t---------------";
	cout << "\n\tPenentuan Harga";
	cout << "\n\t---------------";
	cout << "\n\tJumlah Menu yang dibeli : ";
	cin >> itm;
	cout << "\n";
	for (itm0 = 1; itm0 <= itm; itm0 ++){
		char option1, option2; 
		UlangMakanan:
		cout << "\tMasukkan Menu ke-" << itm0 << " yang dipilih\t: ";
		cin >> option1;
		switch (option1){
			case '1':
				Menu Makanan1;
				cout << "\t\tKuantitas (pcs)\t\t: "; 
				cin >> Makanan1.Q1;
				Makanan1.HargaMakanan1();
				break;
			case '2':
				Menu Makanan2;
				cout << "\t\tKuantitas (pcs)\t\t: ";
				cin >> Makanan2.Q2;
				Makanan2.HargaMakanan2();
				break;
			case '3':
				Menu Makanan3;
				cout << "\t\tKuantitas (pcs)\t\t: ";
				cin >> Makanan3.Q3;
				Makanan3.HargaMakanan3();
				break;
			case '4':
				Menu Makanan4;
				cout << "\t\tKuantitas (pcs)\t\t: ";
				cin >> Makanan4.Q4;
				Makanan4.HargaMakanan4();
				break;
			case '5':
				Menu Makanan5;
				cout << "\t\tKuantitas (pcs)\t\t: ";
				cin >> Makanan5.Q5;
				Makanan5.HargaMakanan5();
				break;
			default:
				cout << "\tMohon maaf pilihan tidak tersedia, silahkan memilih kembali\n\n";
				goto UlangMakanan;
		}
	}
	
    int data[5];
    int total = 0;
    int totalFix;
    int pesan, out;
    
	cout << "\t----------";
	cout << "\n\tPembayaran";
	cout << "\n\t----------\n";
	cout << "\t===========================================\n";
	
    if (itm == 1){
	for (int i = 0; i < itm; i++){
		cout << "\tMasukkan total harga Menu ke-"<<i+1<<"\t: Rp";
		cin >> data[i];	
	}
    int length = (sizeof(data) / sizeof(*data));
    for(int i = 0; i < length; i++) {
        total += data[i];
	}
	totalFix = total - data[2] - data[3] - data[4];
    cout << "\t===========================================\n\t\tTotal Harga\t\t: Rp" << totalFix <<endl;
    
    cout << "\n\tApakah ada pesanan lain ?\n\t1.Yes 2.No\t"; cin >> pesan;
    if (pesan == 1){
    	system ("cls");
    	cout << "\t\t   ==============================================================\n";
		cout << "\t\t   SELAMAT DATANG DI APLIKASI KASIR RESTORAN KASIH FRIED CHICKEN\n\t\t   ==============================================================\n";
		cout << "\t\t\t    Jl. Harapan Masa Depan No.16, Kota Surabaya\n\n";
    	goto UlangProses;
	}
	else {
    	cout << "\n\tApakah anda ingin keluar ?\n\t1.Yes 2.No\t"; cin >> out;
		if (out == 1){
			system ("cls");
			goto UlangBeranda;
		}
		else {
			system ("cls");
    		cout << "\t\t   ==============================================================\n";
			cout << "\t\t   SELAMAT DATANG DI APLIKASI KASIR RESTORAN KASIH FRIED CHICKEN\n\t\t   ==============================================================\n";
			cout << "\t\t\t    Jl. Harapan Masa Depan No.16, Kota Surabaya\n\n";
			goto UlangProses;
		}
	}
}
	
	else if (itm == 2){
	for (int i = 0; i < itm; i++){
		cout << "\tMasukkan total harga Menu ke-"<<i+1<<"\t: Rp";
		cin >> data[i];	
	}
    int length = (sizeof(data) / sizeof(*data));
    for(int i = 0; i < length; i++) {
        total += data[i];
    }
	totalFix = total - data[2] - data[3] - data[4];
    cout << "\t===========================================\n\t\tTotal Harga\t\t: Rp" << totalFix <<endl;
    
    cout << "\n\tApakah ada pesanan lain ?\n\t1.Yes 2.No\t"; cin >> pesan;
    if (pesan == 1){
    	system ("cls");
    	cout << "\t\t   ==============================================================\n";
		cout << "\t\t   SELAMAT DATANG DI APLIKASI KASIR RESTORAN KASIH FRIED CHICKEN\n\t\t   ==============================================================\n";
		cout << "\t\t\t    Jl. Harapan Masa Depan No.16, Kota Surabaya\n\n";
    	goto UlangProses;
	}
	else {
    	cout << "\n\tApakah anda ingin keluar ?\n\t1.Yes 2.No\t"; cin >> out;
		if (out == 1){
			system ("cls");
			goto UlangBeranda;
		}
		else {
			system ("cls");
    		cout << "\t\t   ==============================================================\n";
			cout << "\t\t   SELAMAT DATANG DI APLIKASI KASIR RESTORAN KASIH FRIED CHICKEN\n\t\t   ==============================================================\n";
			cout << "\t\t\t    Jl. Harapan Masa Depan No.16, Kota Surabaya\n\n";
			goto UlangProses;
		}
	}
}
	
	else if (itm == 3){
	for (int i = 0; i < itm; i++){
		cout << "\tMasukkan total harga Menu ke-"<<i+1<<"\t: Rp";
		cin >> data[i];	
	}
    int length = (sizeof(data) / sizeof(*data));
    for(int i = 0; i < length; i++) {
        total += data[i];
    }
	totalFix = total - data[4];
    cout << "\t===========================================\n\t\tTotal Harga\t\t: Rp" << totalFix <<endl;
    
    cout << "\n\tApakah ada pesanan lain ?\n\t1.Yes 2.No\t"; cin >> pesan;
    if (pesan == 1){
    	system ("cls");
    	cout << "\t\t   ==============================================================\n";
		cout << "\t\t   SELAMAT DATANG DI APLIKASI KASIR RESTORAN KASIH FRIED CHICKEN\n\t\t   ==============================================================\n";
		cout << "\t\t\t    Jl. Harapan Masa Depan No.16, Kota Surabaya\n\n";
    	goto UlangProses;
	}
	else {
    	cout << "\n\tApakah anda ingin keluar ?\n\t1.Yes 2.No\t"; cin >> out;
		if (out == 1){
			system ("cls");
			goto UlangBeranda;
		}
		else {
			system ("cls");
    		cout << "\t\t   ==============================================================\n";
			cout << "\t\t   SELAMAT DATANG DI APLIKASI KASIR RESTORAN KASIH FRIED CHICKEN\n\t\t   ==============================================================\n";
			cout << "\t\t\t    Jl. Harapan Masa Depan No.16, Kota Surabaya\n\n";
			goto UlangProses;
		}
	}
}
		
	else if (itm == 4){
	for (int i = 0; i < itm; i++){
		cout << "\tMasukkan total harga Menu ke-"<<i+1<<"\t: Rp";
		cin >> data[i];	
	}
    int length = (sizeof(data) / sizeof(*data));
    for(int i = 0; i < length; i++) {
        total += data[i];
    }
	totalFix = total - data[4];
    cout << "\t===========================================\n\t\tTotal Harga\t\t: Rp" << totalFix <<endl;
    cout << "\n\tApakah ada pesanan lain ?\n\t1.Yes 2.No\t"; cin >> pesan;
    if (pesan == 1){
    	system ("cls");
    	cout << "\t\t   ==============================================================\n";
		cout << "\t\t   SELAMAT DATANG DI APLIKASI KASIR RESTORAN KASIH FRIED CHICKEN\n\t\t   ==============================================================\n";
		cout << "\t\t\t    Jl. Harapan Masa Depan No.16, Kota Surabaya\n\n";
    	goto UlangProses;
	}
	else {
    	cout << "\n\tApakah anda ingin keluar ?\n\t1.Yes 2.No\t"; cin >> out;
		if (out == 1){
			system ("cls");
			goto UlangBeranda;
		}
		else {
			system ("cls");
    		cout << "\t\t   ==============================================================\n";
			cout << "\t\t   SELAMAT DATANG DI APLIKASI KASIR RESTORAN KASIH FRIED CHICKEN\n\t\t   ==============================================================\n";
			cout << "\t\t\t    Jl. Harapan Masa Depan No.16, Kota Surabaya\n\n";
			goto UlangProses;
		}
	}
}
	
	else {
	for (int i = 0; i < itm; i++){
		cout << "\tMasukkan total harga Menu ke-"<<i+1<<"\t: Rp";
		cin >> data[i];	
	}
    int length = (sizeof(data) / sizeof(*data));
    for(int i = 0; i < length; i++) {
        total += data[i];
    }
    cout << "\t===========================================\n\t\tTotal Harga\t\t: Rp" << total <<endl;
    cout << "\n\tApakah ada pesanan lain ?\n\t1.Yes 2.No\t"; cin >> pesan;
    if (pesan == 1){
    	system ("cls");
    	cout << "\t\t   ==============================================================\n";
		cout << "\t\t   SELAMAT DATANG DI APLIKASI KASIR RESTORAN KASIH FRIED CHICKEN\n\t\t   ==============================================================\n";
		cout << "\t\t\t    Jl. Harapan Masa Depan No.16, Kota Surabaya\n\n";
    	goto UlangProses;
	}
	else {
    	cout << "\n\tApakah anda ingin keluar ?\n\t1.Yes 2.No\t"; cin >> out;
		if (out == 1){
			system ("cls");
			goto UlangBeranda;
		}
		else {
			system ("cls");
    		cout << "\t\t   ==============================================================\n";
			cout << "\t\t   SELAMAT DATANG DI APLIKASI KASIR RESTORAN KASIH FRIED CHICKEN\n\t\t   ==============================================================\n";
			cout << "\t\t\t    Jl. Harapan Masa Depan No.16, Kota Surabaya\n\n";
			goto UlangProses;
		}
	  }
	}
}