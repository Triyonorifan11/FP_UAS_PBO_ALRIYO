#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <windows.h>

// Nama = 1. Triyono Rifan (20081010003)
//        2. Alfian Rachmad Dianto (20081010011)
// Kelas = Pemrograman Berorientasi Objek C081

using namespace std;

void mainMenu();
void dashboard();
void pelayanan();
void bookingTempat();
void pilihMenuPesan();
void metodeBayarBank();

int nomor_pesanan_note;
string nama_pemesan_note;

// simpan data menu
// class daftar menu
class Menu
{

private:
    string nama_menu;
    double harga;

public:
    Menu(string nama_menu, double harga)
    {
        this->nama_menu = nama_menu;
        Menu::harga = harga;
    }

    string getMenu()
    {
        return "\n" + nama_menu;
    }

    double getharga()
    {
        return harga;
    }
};

// class untuk overloading function
class Print
{
public:
    void print(int kode_pesanan)
    {
        cout << "Kode Pesanan \t\t= " << kode_pesanan << endl;
    }

    void print(string nama_pemesan)
    {
        cout << "Pemesan \t\t= " << nama_pemesan << endl;
    }

    void print(double total_pesanan)
    {
        cout << "Total pesanan \t\t= Rp " << total_pesanan << endl;
    }
};

class Counting
{
private:
    int total;

public:
    Counting(int pajak = 0)
    {
        total = pajak;
    }

    Counting operator+(Counting const &pesanan)
    {
        Counting bayar;
        bayar.total = this->total + pesanan.total;
        return bayar;
    }

    int get_total()
    {
        return this->total;
    }

    void printBayar()
    {
        cout << "Pajak + Total Pesanan \t= Rp " << this->total << endl;
    }
};

// class database untuk menyimpan data Menu ke file txt
class Db
{
private:
    ifstream output;
    ofstream input;
    string fileName;
    string menu_pilih;

    double harga_pilih = 0;
    double bayar;

public:
    int nomor_pesanan;

public:
    // nama database txt
    Db(const char *fileName)
    {
        Db::fileName = fileName;
    }

    // mengambil data Nama Menu
    string getNamaMenu()
    {
        return menu_pilih;
    }

    // Mengambil data Harga Menu
    double getHargaMenu()
    {
        return harga_pilih;
    }

    // fungsi menyimpan data
    void save(Menu data)
    {
        Db::input.open(Db::fileName, ios::app);
        Db::input << data.getMenu();
        Db::input << "\t" << data.getharga();
        Db::input.close();
    }

    // save repository menu yang dipilih,harga untuk transaksi
    void save(string namapilih, double hargapilih, int porsi)
    {
        Db::input.open(Db::fileName, ios::app);
        Db::input << "\n"
                  << namapilih;
        Db::input << " " << hargapilih;
        Db::input << " " << porsi;
        Db::input << " " << hargapilih * porsi;
        Db::input.close();
    }

    // Update database menu
    void updateMenu(int indexUpdate)
    {
        Db::output.open(Db::fileName, ios::in);
        Db::input.open("temp.txt", ios::app);
        string updateNama;
        double updateHarga;

        int index = 1;
        int flag = 0;

        while (!Db::output.eof())
        {
            Db::output >> updateNama;
            Db::output >> updateHarga;
            index++;
            if (indexUpdate == index - 1)
            {
                flag = 1;
                cout << "Nama menu : ";
                cin >> updateNama;
                cout << "Harga menu : ";
                cin >> updateHarga;
            }
            Db::input << "\n"
                      << updateNama;
            Db::input << "\t" << updateHarga;
        }

        Db::output.close();
        Db::input.close();

        if (flag == 0)
        {
            cout << "Data tidak ditemukan!!\n\n"
                 << endl;
            remove("temp.txt");
        }
        else
        {
            cout << "\nData Menu Anda Telah Sukses Diperbarui\n\n"
                 << endl;
            remove("Menu_restoran.txt");
            rename("temp.txt", "Menu_restoran.txt");
        }
    }

    // fungsi tampilkan data
    void showAll()
    {
        Db::output.open(Db::fileName, ios::in);
        string tampilNama;
        double tampilHarga;
        int index = 1;

        cout << "No "
             << "\t"
             << "Daftar Menu"
             << "\t"
             << "Daftar Harga" << endl;
        while (!Db::output.eof())
        {
            Db::output >> tampilNama;
            Db::output >> tampilHarga;

            cout << index++ << "\t" << tampilNama << "\t"
                 << "Rp " << tampilHarga << endl;
        }

        cout << "\nJumlah Menu: " << index - 1 << endl;
        Db::output.close();
    }

    // delete database menu
    void deleteMenu(int indexDelete)
    {
        Db::output.open(Db::fileName, ios::in);
        Db::input.open("temp.txt", ios::app);

        string hapusNama;
        double hapusHarga;

        int util = 0;
        int index = 1;

        while (!Db::output.eof())
        {
            Db::output >> hapusNama;
            Db::output >> hapusHarga;
            index++;
            if (indexDelete != index - 1)
            {
                util = 1;
                Db::input << "\n"
                          << hapusNama;
                Db::input << "\t" << hapusHarga;
            }
        }

        Db::output.close();
        Db::input.close();

        if (util == 0 || indexDelete > index - 1)
        {
            cout << "Data tidak ditemukan!!\n\n"
                 << endl;
            remove("temp.txt");
        }
        else
        {
            cout << "Data berhasil dihapus !! \n\n"
                 << endl;
            remove("Menu_restoran.txt");
            rename("temp.txt", "Menu_restoran.txt");
        }
    }

    // untuk pilih menu pesanan dan ambil harga pesanan
    void pesanMenu(int pilih, int porsi)
    {
        Db::output.open(Db::fileName, ios::in);
        string pilihNama;
        double pilihHarga;

        int index = 1;

        while (!Db::output.eof())
        {
            Db::output >> pilihNama;
            Db::output >> pilihHarga;
            index++;
            if (pilih == index - 1)
            {
                Db::menu_pilih = pilihNama;
                Db::harga_pilih = pilihHarga;
            }
        }
        if (pilih > index - 1)
        {
            cout << "nomer salah. input lagi" << endl;
            system("pause");
            pilihMenuPesan();
        }

        Db::output.close();
    }

    // fungsi total pesanan
    void totalpesanan()
    {
        Db::output.open(Db::fileName, ios::in);
        string namaPilih;
        double total_fee = 0, bayar, fee;
        int porsi;
        int index = 1;
        while (!Db::output.eof())
        {
            Db::output >> namaPilih;
            Db::output >> fee;
            Db::output >> porsi;
            Db::output >> total_fee;
            cout << index++ << " " << namaPilih << " " << fee << " x " << porsi << " = Rp " << total_fee << endl;
            bayar = bayar + total_fee;
        }
        cout << "\ntotal Pesanan = Rp " << bayar << endl;
        Db::bayar = bayar;
        Db::output.close();
    }

    void bayarpesanan()
    {
        system("cls");
        Print customer;

        double pesanan = this->bayar;
        double pajak = 0.001 * pesanan;
        double diskon = 0;
        double bayar_pelanggan = 0;
        double kembalian = 0;
        double total_bayar_pelanggan = 0;

        if (pesanan >= 100000.0)
        {
            diskon = 0.1 * pesanan;
        }

        cout << "====== N O T A  P E S A N A N ======\n"
             << endl;
        customer.print(nomor_pesanan_note);
        customer.print(nama_pemesan_note);
        cout << "------------------------------------\n";
        customer.print(pesanan);

        Counting total(pajak), pesan(pesanan);
        Counting hasil = total + pesan;

        cout << "Pajak \t\t\t= Rp " << pajak << endl;
        cout << "Diskon \t\t\t= Rp " << diskon << endl;

        total_bayar_pelanggan = hasil.get_total() - diskon;
        hasil.printBayar();
        cout << "------------------------------------\n";
        cout << "Total harus Dibayar \t= Rp " << total_bayar_pelanggan << endl;
        cout << "Dibayar \t\t= Rp ";
        cin >> bayar_pelanggan;
        kembalian = bayar_pelanggan - total_bayar_pelanggan;
        cout << "Kembali \t\t= Rp " << kembalian << endl;
        cout << "\n";

        remove("RepoFee.txt");
    }
};

// buat metode bayar
class Metode
{
private:
    string kodebankBRI;
    string kodebankBSI;

public:
    Metode()
    {
        this->kodebankBRI = "003";
        this->kodebankBSI = "103";
    }

    string getBankBRI()
    {
        return kodebankBRI;
    }
    string getBankBSI()
    {
        return kodebankBSI;
    }
};

// turunan kelass metode
class Bank : public Metode
{
private:
    string bank;

public:
    Bank()
    {
        cout << "Metode bayar dengan Bank/Mbanking" << endl;
    }

    void pilihbank(string namabank)
    {
        cout << "Pilih Bank : " << namabank;
        this->bank = namabank;
    }
};

// class untuk linked list
class Node
{
public:
    string nama_pemesan;
    int nomer_pesanan, nomer_meja;
    Node *next;
};

Node *head, *tail, *newNode, *utils, *delete_node, *before;

class SetAntrian : public Node
{
public:
    // set data pertama
    void set_first_data(string nama_pemesan, int nomer_pesanan, int nomer_meja)
    {
        head = new Node();
        head->nama_pemesan = nama_pemesan;
        head->nomer_meja = nomer_meja;
        head->nomer_pesanan = nomer_pesanan;
        head->next = NULL;
        tail = head;
    }

    // jumlahData antrian
    int count_data()
    {
        utils = head;
        int jumlah = 0;
        while (utils != NULL)
        {
            jumlah++;
            utils = utils->next;
        }
        return jumlah;
    }

    // tambah data di akhir linked list
    void add_dataAkhir(string nama_pemesan, int nomer_pesanan, int nomer_meja)
    {
        newNode = new Node();
        newNode->nama_pemesan = nama_pemesan;
        newNode->nomer_meja = nomer_meja;
        newNode->nomer_pesanan = nomer_pesanan;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }

    // edit data tengah sesuai posisi
    void update_dataPosisi(string nama_pemesan, int nomer_pesanan, int nomer_meja, int posisi)
    {
        if (posisi < 1 || posisi > count_data())
        {
            cout << "Meja Tidak tersedia" << endl;
        }
        // isi /update posisi 1
        else if (posisi == 1)
        {
            head->nama_pemesan = nama_pemesan;
            head->nomer_pesanan = nomer_pesanan;
            head->nomer_meja = nomer_meja;
        }
        // isi /update posisi terakhir
        else if (posisi == count_data())
        {
            tail->nama_pemesan = nama_pemesan;
            tail->nomer_pesanan = nomer_pesanan;
            tail->nomer_meja = nomer_meja;
        }
        else
        {
            utils = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                utils = utils->next;
                nomor++;
            }
            utils->nama_pemesan = nama_pemesan;
            utils->nomer_meja = nomer_meja;
            utils->nomer_pesanan = nomer_pesanan;
        }
    }

    // tampilkan data node
    void print_data()
    {
        utils = head;
        int i = 1;
        cout << "No";
        cout << "  Nama Pemesan";
        cout << "  Nomor Meja";
        cout << "  Kode Pesanan" << endl;
        while (utils != NULL)
        {
            cout << i++;
            cout << "\t" << utils->nama_pemesan;
            cout << "\t   Meja " << utils->nomer_meja;
            cout << "\t  " << utils->nomer_pesanan << endl;
            utils = utils->next;
        }
        cout << "\nJumlah data : " << count_data() << endl;
    }
};

// 1. fungsi input menu restaurant
void inputMenu()
{
    system("cls");
    Db dataBase_Menu = Db("Menu_restoran.txt");

    string namaMenu;
    double harga;
    int tipe;
    cout << "===============  HALAMAN TAMBAH MENU  ==============" << endl;
    cout << "Catatan : Tolong masukkan menu menggunakan tanda '_'" << endl;
    cout << "\nTambah" << endl;
    cout << "Nama : ";
    cin >> namaMenu;
    cout << "Harga : ";
    cin >> harga;

    Menu menu1 = Menu(namaMenu, harga);
    dataBase_Menu.save(menu1);
    cout << "\nSelamat, Data Menu Baru Anda Telah Sukses Ditambah\n"
         << endl;
    system("pause");

    mainMenu();
}

// 2. menampilkan daftar menu
void tampilMenu()
{
    system("cls");
    Db dataBase = Db("Menu_restoran.txt");

    dataBase.showAll();

    system("Pause");
    mainMenu();
}

// 3. memilih menu untuk pemesanan
void pilihMenuPesan()
{

    Db dataBase = Db("Menu_restoran.txt");
    Db repo_fee = Db("RepoFee.txt");

    int pilihPesanan, porsi, tambah;

    system("cls");
    dataBase.showAll();

    cout << "\n====== F O R M U L I R  P E M E S A N A N  ======\n"
         << endl;
    cout << "Pilih menu diatas : ";
    cin >> pilihPesanan;
    cout << "Banyak porsi yang dipesan : ";
    cin >> porsi;

    dataBase.pesanMenu(pilihPesanan, porsi);
    repo_fee.save(dataBase.getNamaMenu(), dataBase.getHargaMenu(), porsi);
    repo_fee.totalpesanan();

    cout << "tambah pesanan ? 1(yes)/2(no) = ";
    cin >> tambah;

    switch (tambah)
    {
    case 1:
        pilihMenuPesan();
        break;

    case 2:
        int pilihbayar;
        cout << "Pilih Metode bayar? (1)Tunai / (2) Bank (BSI/BRI) = ";
        cin >> pilihbayar;
        if (pilihbayar == 1)
        {
            repo_fee.bayarpesanan();
        }
        else if (pilihbayar == 2)
        {
            metodeBayarBank();
            repo_fee.bayarpesanan();
        }
        break;
    default:
        cout << "Harap masukkan pilihan dengan benar" << endl
             << endl;
        break;
        pilihMenuPesan();
    }

    system("pause");
    pelayanan();
}

// 4. fungsi update data menu
void update()
{
    Db dataBase = Db("Menu_restoran.txt");

    int update;
    system("cls");
    cout << "===============  HALAMAN PERBARUI MENU  ==============" << endl
         << endl;
    dataBase.showAll();
    cout << "\nCatatan : Tolong perbarui menu menggunakan tanda '_'" << endl;
    cout << "\nPilih nomor menu yang akan diperbarui : ";
    cin >> update;
    cout << "\nPerbarui : " << endl;

    dataBase.updateMenu(update);
    // dataBase.showAll();
    system("pause");
    mainMenu();
}

// 5. fungsi hapus menu
void deleteItem()
{
    Db dataBase = Db("Menu_restoran.txt");

    int selected;
    system("cls");
    cout << "===============  HALAMAN HAPUS MENU  ==============\n"
         << endl;
    dataBase.showAll();
    cout << "\n\nPilih nomor menu yang akan di Hapus = ";
    cin >> selected;

    dataBase.deleteMenu(selected);
    // dataBase.showAll();
    system("pause");
    mainMenu();
}

// 6. fungsi bayar dengan bank
void metodeBayarBank()
{
    Bank metode;
    int pilihbank;
    cout << "Pilih bank (1)BRI / (2)BSI ? ";
    cin >> pilihbank;
    if (pilihbank == 1)
    {
        metode.pilihbank("BRI");
        cout << "\nKode bank BRI = " << metode.getBankBRI() << endl;
    }
    else if (pilihbank == 2)
    {
        metode.pilihbank("BSI");
        cout << "\nKode bank BSI = " << metode.getBankBSI() << endl;
    }
}

// 7. fungsi Tampil Meja dan daftar antrian pelanggan
void showMejaDanAntrian()
{
    SetAntrian data_antrian;
    data_antrian.print_data();
}

// booking tempat
void bookingTempat()
{
    system("cls");
    SetAntrian update_data;
    string nama_pemesan;
    int nomer_meja;
    int nomor_pesanan = rand() % 1000 + 1000;

    showMejaDanAntrian();

    cout << "\n====== B O O K I N G  M E J A ======" << endl;
    cout << "\nIdentitas ";
    cout << "Nama Pemesan : ";
    cin >> nama_pemesan;
    cout << "Nomor pesanan : " << nomor_pesanan << endl;
    nomor_pesanan_note = nomor_pesanan;
    nama_pemesan_note = nama_pemesan;
    cout << "Nomor Meja : ";
    cin >> nomer_meja;
    int posisi = nomer_meja;

    update_data.update_dataPosisi(nama_pemesan, nomor_pesanan, nomer_meja, posisi);
    cout << "\nBooking Tempat Sukses Dilakukan\n"
         << endl;
    system("pause");
    // pelayanan();
}

void delete_set_booking()
{
    SetAntrian update_data;
    int nomer_meja;
    showMejaDanAntrian();

    cout << "Pilih Nomer Meja yang akan dihapus : ";
    cin >> nomer_meja;
    int posisi = nomer_meja;
    update_data.update_dataPosisi("-----", 0, nomer_meja, posisi);
    cout << "Update Tempat selesai..." << endl;
    system("pause");
}

void setDataAntri()
{

    SetAntrian data_antrian;
    data_antrian.set_first_data("-----", 0, 1);
    data_antrian.add_dataAkhir("-----", 0, 2);
    data_antrian.add_dataAkhir("-----", 0, 3);
    data_antrian.add_dataAkhir("-----", 0, 4);
    data_antrian.add_dataAkhir("-----", 0, 5);
    data_antrian.add_dataAkhir("-----", 0, 6);
    data_antrian.add_dataAkhir("-----", 0, 7);
    data_antrian.add_dataAkhir("-----", 0, 8);
    data_antrian.add_dataAkhir("-----", 0, 9);
    data_antrian.add_dataAkhir("-----", 0, 10);
    // data_antrian.print_data();
    // system("pause");
}

// tutup Aplikasi
void close()
{
    system("cls");
    cout << "RESTO PIXEL.ID" << endl;
    cout << "Terima kasih" << endl;
}

// Main menu admin
void mainMenu()
{
    ofstream createMakan;
    createMakan.open("Menu_restoran.txt", ios::app);
    // createMinum.open("Minum_restoran.txt", ios::app);
    createMakan.close();
    // createMinum.close();

    system("cls");
    int input;
    cout << "===========  H A L A M A N  A D M I N  ===========" << endl;
    cout << "SILAHKAN PILIH SESUAI DENGAN SITUASI ANDA SEKARANG" << endl;
    cout << "\t\tRESTORAN PIXEL.ID" << endl
         << endl;
    cout << "1. Tambah Menu" << endl;
    cout << "2. Lihat Menu" << endl;
    cout << "3. Perbarui Menu" << endl;
    cout << "4. Hapus Menu" << endl;
    cout << "5. Halaman Utama" << endl
         << endl;
    cout << "Pilih fitur: ";
    cin >> input;

    if (input == 1)
    {
        inputMenu();
    }
    else if (input == 2)
    {
        tampilMenu();
    }
    else if (input == 3)
    {
        update();
    }
    else if (input == 4)
    {
        deleteItem();
    }
    else if (input == 5)
    {
        dashboard();
    }

    else
    {
        cout << "Menu tidak tersedia" << endl;
        system("pause");
        mainMenu();
    }
}

void pelayanan()
{

    system("cls");
    int input;
    cout << "===========  H A L A M A N  P E L A Y A N A N  ===========" << endl;
    cout << "SILAHKAN PILIH SESUAI DENGAN SITUASI ANDA SEKARANG" << endl;
    cout << "\t\t   RESTO PIXEL.ID" << endl
         << endl;

    cout << "1. Pesan Menu" << endl;
    cout << "2. Lihat Antrian" << endl;
    cout << "3. Hapus Daftar Antrian" << endl;
    cout << "4. Halaman Utama" << endl;
    cout << "Pilih : ";
    cin >> input;

    switch (input)
    {
    case 1:
        system("cls");
        cout << "===========  H A L A M A N  P E L A Y A N A N  ===========" << endl;
        cout << "SILAHKAN PILIH SESUAI DENGAN SITUASI ANDA SEKARANG" << endl;
        cout << "\t\t   RESTO PIXEL.ID" << endl
             << endl;
        int pilih;
        cout << "====== P E S A N  M E N U ======" << endl;
        cout << "Pilihan layanan" << endl;
        cout << "1. Makan di tempat\n2. Bawa pulang" << endl;
        cout << "pilih : ";
        cin >> pilih;
        if (pilih == 1)
        {
            cout << "\n";
            bookingTempat();
            pilihMenuPesan();
        }
        else if (pilih == 2)
        {
            string nama_pemesan;
            int nomor_pesanan = rand() % 1000 + 1000;
            cout << "\nIdentias Nama Pemesan : ";
            cin >> nama_pemesan;
            cout << "Nomor pesanan : " << nomor_pesanan << endl;
            nomor_pesanan_note = nomor_pesanan;
            nama_pemesan_note = nama_pemesan;
            system("pause");
            pilihMenuPesan();
        }
        break;

    case 2:
        system("cls");
        showMejaDanAntrian();
        system("pause");
        pelayanan();
        break;
    case 3:
        system("cls");
        delete_set_booking();
        pelayanan();
        break;
    case 4:
        dashboard();
        break;
    default:
        cout
            << "Menu tidak tersedia"
            << endl;
        system("pause");
        mainMenu();
    }
}

void dashboard()
{
    system("cls");
    int input;
    cout << "       SELAMAT DATANG DI RESTO PIXEL.ID" << endl;
    cout << "SILAHKAN PILIH SESUAI DENGAN SITUASI ANDA SEKARANG" << endl
         << endl;
    cout << "========== HALAMAN UTAMA PIXEL.ID ==========" << endl
         << endl;
    cout << "1. Admin" << endl;
    cout << "2. Kasir" << endl;
    cout << "3. Close" << endl
         << endl;

    cout << "Masukkan Pilihan = ";
    cin >> input;

    switch (input)
    {
    case 1:
        mainMenu();
        break;
    case 2:
        pelayanan();
        break;
    case 3:
        close();
        break;
    default:
        cout << "MA'AF ANDA SALAH MEMASUKKAN PILIHAN, MOHON PILIH DENGAN BENAR" << endl;
        system("pause");
        dashboard();
        break;
    }
}

int main(int argc, char const *argv[])
{
    srand(time(0));
    setDataAntri();
    dashboard();
    // mainMenu();
    return 0;
}
