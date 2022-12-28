#include <stdio.h> //header standar input output dalam bahasa c
#include <stdlib.h> //header standar input output dalam bahasa c
#include <string.h> //header yang berisi fungsi-fungsi yang digunakan untuk pengoperasian string
#include <conio.h> //header standar input output dalam bahasa c
#include <time.h> //header yang digunakan untuk menampilkan format tanggal dan waktu

// Struct User untuk menyimpan member nama, username, password, email, no telp 
typedef struct{
    char nama[50];  //untuk menyimpan nama dengan maksimal 50 karakter pada saat registrasi pengguna    
    char username[50]; //untuk menyimpan username dengan maksimal 50 karakter pada saat registrasi serta login pengguna 
    char password[50]; //untuk menyimpan password dengan maksimal 50 karakter pada saat registrasi serta login pengguna
    char email[50]; //untuk menyimpan email dengan maksimal 50 karakter pada saat registrasi pengguna
	char notelp[50]; //untuk menyimpan no telp dengan maksimal 50 karakter pada saat registrasi pengguna
}User;
User u; //Mendeklarasikan variabel u pada struct User


// Struct untuk menyimpan Data Villa
typedef struct{
    char id_villa[10];      
    char nama_villa[255];
	char alamat_villa[255]; 
	char tipe_kamar[255]; 
    char tipe_fasilitas[255];
    int harga;    
}datavilla;
datavilla dv;

// Struct untuk menyimpan Pesanan Villa
typedef struct{
	int	tm_mday;                             //untuk menyimpan tm_mday yang dipesan ke dalam variabel integer saat input pemesanan villa   
	int tm_mon;                             //untuk menyimpan tm_mon yang dipesan ke dalam variabel integer saat input pemesanan villa   
	int	tm_year;                           //untuk menyimpan tm_year yang dipesan ke dalam variabel integer saat input pemesanan villa   
	char ids_pesanan[10];                 //untuk menyimpan id_pemesan yang dipesan ke dalam variabel char saat input pemesanan villa      
	char username[50];                   //untuk menyimpan username ke dalam variabel char dengan maksimal 50 karakter saat input pemesanan villa
	char id_villa[10];                  //untuk menyimpan id_villa yang dipesan ke dalam variabel char saat input pemesanan villa     
	char nama[50];                     //untuk menyimpan nama_pemesan ke dalam variabel char dengan maksimal 50 karakter saat input pemesanan villa
	char notelp[50];                  //untuk menyimpan noHP pemesan ke dalam variabel char dengan maksimal 50 karakter saat input pemesanan villa         
	char email[50];                  //untuk menyimpan email pemesan ke dalam variabel char dengan maksimal 50 karakter saat input pemesanan villa                    
	int tglCI;                      //berfungsi untuk menyimpan tanggal check in saat input pemesanan villa ke dalam variabel bertipe integer             
	int blnCI;                     //berfungsi untuk menyimpan bulan check in saat input pemesanan villa ke dalam variabel bertipe integer      
	int thnCI;                    //berfungsi untuk menyimpan tahun check in saat input pemesanan villa ke dalam variabel bertipe integer                  
  	int tglCO;                   //berfungsi untuk menyimpan tanggal check out saat input pemesanan villa ke dalam variabel bertipe integer         
	int blnCO;                  //berfungsi untuk menyimpan bulan check out saat input pemesanan villa ke dalam variabel bertipe integer          
	int thnCO;                 //berfungsi untuk menyimpan tahun check out saat input pemesanan villa ke dalam variabel bertipe integer
	int lama_sewa;            //berfungsi untuk menyimpan lama_sewa saat input pemesanan villa ke dalam variabel bertipe integer     
	int totalPembayaran ;    //berfungsi untuk menyimpan total_pembayaran saat input pemesanan villa ke dalam variabel bertipe integer    
	int sisaPembayaran ;    //berfungsi untuk menyimpan sisa pembayaran villa ke dalam variabel bertipe integer
	char status[15];
}pesanvilla;
pesanvilla pv; //Mendeklarasikan variabel pesanvilla pada struct pesan_villa

int hari1 ;
int hari2 = 1; 
int admin = 10000;
int deposito = 500000;
time_t waktuserver; 

//Deklarasi fungsi-fungsi yang digunakan pada program pemesanan villa :
void menu_utama();                      /*Merupakan fungsi yang digunakan untuk menampilkan menu utama*/
void menu_registrasi();                 /*Merupakan fungsi yang digunakan untuk menampilkan menu registrasi*/
void pilihan_login();                   /*Merupakan fungsi yang digunakan untuk menampilkan menu pilihan_login*/
void login_admin();                     /*Merupakan fungsi untuk masuk admin (login admin) dengan memasukkan password admin atau pegawai villa easy book*/
void login_pengguna();                  /*Merupakan fungsi untuk masuk pengguna (login) yang berisi input username dan password*/
void menu_admin();                      /*Merupakan fungsi untuk menu admin yang berisi 5 opsi yaitu Input Data Villa, Hapus Data Villa, Data Pesanan Villa, Edit Pesanan Villa, dan kembali ke menu utama*/
void menu_pelanggan();                  /*Merupakan fungsi untuk menu pelanggan yang berisi 6 opsi yaitu Tentang Kami, Aturan Pemesan Villa, Pilihan Villa, Tipe dan Fasilitas Villa, Pesan Villa dan kembali ke menu utama*/
void input_villa();                     /*Merupakan fungsi bagian dari menu admin untuk input data villa easy book yang dilakukan oleh pegawai atau adminn*/
void hapus_villa();                     /*Merupakan fungsi bagian dari menu admin untuk hapus data villa easy book yang dilakukan oleh pegawai atau adminn*/
void pesanan_villa();                   /*Merupakan fungsi bagian dari menu admin untuk data pesanan villa easy book yang dilakukan oleh pegawai atau adminn*/
void edit_pesanan();                    /*Merupakan fungsi bagian dari menu admin untuk edit data pesanan villa easy book yang dilakukan oleh pegawai atau adminn*/
void hapus_pesanan();                   /*Merupakan fungsi bagian dari menu admin untuk menghapus data pesanan villa easy book yang dilakukan oleh pegawai atau adminn*/
void update_status();                   /*Merupakan fungsi bagian dari menu admin untuk update status data pesanan villa easy book yang dilakukan oleh pegawai atau adminn*/
void tentang_kami();                    /*Merupakan fungsi bagian dari menu pengguna untuk melihat apasih itu villa easy book yang dilakukan oleh pengguna*/
void aturan_pemesanan();                /*Merupakan fungsi bagian dari menu pengguna untuk melihat aturan pemesanan villa easy book yang dilakukan oleh pengguna*/
void pilihan_villa();                   /*Merupakan fungsi bagian dari menu pengguna untuk melihat pilihan villa easy book yang dilakukan oleh pengguna*/
void menu_pilihan_villa();              /*Merupakan fungsi bagian dari menu pengguna untuk melihat menu pilihan villa easy book yang dilakukan oleh pengguna*/
void tipe_villa();                      /*Merupakan fungsi bagian dari menu pengguna untuk melihat tipe villa easy book yang dilakukan oleh pengguna*/
void pesan_villa();                     /*Merupakan fungsi bagian dari menu pengguna untuk memesan villa easy book yang dilakukan oleh pengguna*/
void check_villa();                     /*Merupakan fungsi bagian dari menu pengguna untuk mengecheck villa yang tersedia di villa easy book yang dilakukan oleh pengguna*/
int Februari (int thn);
int BknFeb (int thn, int bln);
int id_generator();

int validasi_input(){ //validasi ini digunakan untuk memastikan user melakukan input berupa bilangan saja
    int bilangan;
    char cr; 
	
	printf("");
    scanf("%d%c", &bilangan, &cr);

    if(cr != '\n' || bilangan <= 0){
        printf("Masukan pilihan yang sesuai: ", bilangan, cr);
        fflush(stdin);
        validasi_input();
        
    }else{
        return bilangan;
    }
}

int validasi_lima(){ //validasi ini digunakan untuk memastikan user melakukan input berupa bilangan 1-5 saja
    int bilangan;
    bilangan=validasi_input();
    
    if(bilangan >=1 && bilangan <=5){
        return bilangan;
        
    }else{
        printf("Masukan pilihan yang sesuai (1/2/3/4/5): ");
    	return validasi_lima();
	}
}

int validasi_enam(){ //validasi ini digunakan untuk memastikan user melakukan input berupa bilangan 1-6 saja
    int bilangan;
    bilangan=validasi_input();
    
    if(bilangan >=1 && bilangan <=6){
        return bilangan;
        
    }else{
        printf("Masukan pilihan yang sesuai (1/2/3/4/5/6): ");
    	return validasi_enam();
	}
}

int validasi_tiga(){ //validasi ini digunakan untuk memastikan user melakukan input berupa bilangan 1-3 saja
    int bilangan;
    bilangan=validasi_input();
    
    if(bilangan >=1 && bilangan <=3){
        return bilangan;
        
    }else{
        printf("Masukan pilihan yang sesuai (1/2/3): ");
    	return validasi_tiga();
	}
}

int validasi_dua(){ //validasi ini digunakan untuk memastikan user melakukan input berupa bilangan 1 dan 2 saja
    int bilangan;
    bilangan=validasi_input();
    
    if(bilangan >=1 && bilangan <=2){
        return bilangan;
        
    }else{
        printf("Masukan pilihan yang sesuai (1/2): ");
    	return validasi_dua();
	}
}

char exite_admin (){ //validasi ini digunakan untuk memastikan user melakukan input berupa karakter y atau n saja (pada menu admin)
    char masukan[100];
    while(1){
        int i=0;
        int salah;
        scanf("%[^\n]",&masukan);
        fflush(stdin);
        if(masukan [i+1] =='\0'){
            if(masukan[0]=='y'  || masukan[0]=='Y' && masukan[1]=='\0'){
                return masukan[0];
            }else if (masukan[0]=='n'  || masukan [0]=='N' && masukan[1]=='\0'){
				system("cls");
				menu_admin();
            }else{
                salah=1;
            }
        }
        salah=1;
        if(salah==1){
            printf("   Format anda salah, silahkan pilih lagi : ");
        }
    }
}

char exite_pengguna (){ //validasi ini digunakan untuk memastikan user melakukan input berupa karakter y atau n saja (pada menu pengguna)
    char masukan[100];
    while(1){
        int i=0;
        int salah;
        scanf("%[^\n]",&masukan);
        fflush(stdin);
        if(masukan [i+1] =='\0'){
            if(masukan[0]=='y'  || masukan[0]=='Y' && masukan[1]=='\0'){
                return masukan[0];
            }else if (masukan[0]=='n'  || masukan [0]=='N' && masukan[1]=='\0'){
				system("cls");
				menu_pelanggan();
            }else{
                salah=1;
            }
        }
        salah=1;
        if(salah==1){
            printf("   Hanya menerima masukan (Y/N): ");
        }
    }
}

int main(){        //fungsi utama pada program ini
	menu_utama(); //memanggil fungsi menu_utama
}

void menu_utama(){
	int link;
	system("cls");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||                           EASY BOOK                         ||\n");
	printf("||         THE RIGHT SOLUTION FOR YOUR HOLIDAY IN BALI         ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n");
	printf("                                                                 \n");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||                           MENU UTAMA                        ||\n");
	printf("||                                                             ||\n");
	printf("|| 1.	REGISTRASI PENGGUNA                                    ||\n");
	printf("|| 2.	LOGIN                                                  ||\n");
	printf("|| 3.	KELUAR DARI PROGRAM                                    ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n");
	printf("Silakan Masukan Pilihan Anda (1/2/3): ");
	link = validasi_tiga();
	system("cls");
	
	if(link==1){
		menu_registrasi();
		
	}else if(link==2){
		pilihan_login();
		
	}else{
	system("cls");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||          TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI         ||\n");
	printf("||                                                             ||\n");
	printf("||                  Program ini disusun oleh:                  ||\n");
	printf("||     1. I Made Arya Adi Pramana             (2205551016)     ||\n");
	printf("||     2. I Kadek Nanda Surya Agusta          (2205551022)     ||\n");
	printf("||                                                             ||\n");
	printf("||     Tugas Besar Mata Kuliah Algoritma dan Pemrograman       ||\n");
	printf("||              Program Studi Teknologi Informasi              ||\n");
	printf("||                      Fakultas Teknik                        ||\n");
	printf("||                    Universitas Udayana                      ||\n");
	printf("||                           2022                              ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n");
	}
}

void menu_registrasi(){
    char username[50];   //Variabel yang digunakan untuk menyimpan input username yang dilakukan oleh pengguna
    char password[50];  //Variabel yang digunakan untuk menyimpan input password yang dilakukan oleh pengguna
    char nama[50];     //Variabel yang digunakan untuk menyimpan input nama yang dilakukan oleh pengguna
    char email[50];   //Variabel yang digunakan untuk menyimpan input email yang dilakukan oleh pengguna
	char notelp[50]; //Variabel yang digunakan untuk menyimpan input nomor telepon yang dilakukan oleh pengguna

	system("cls");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||                  MENU REGISTRASI PENGGUNA BARU              ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n\n");
    printf("   Nama Lengkap     : "); fflush(stdin);
    scanf("%[^\n]", &nama);                          //"%[^\n]" digunakan agar input nama dengan spasi dapat diterima
    printf("   No Telepon       : "); fflush(stdin);
    scanf("%s", &notelp);                          //input nomor telpon menggunakan string dengan jumlah maksimal 50
    printf("   Email            : "); fflush(stdin);
    scanf("%s", &email);                          //input email menggunakan string dengan jumlah maksimal 50
	printf("\n-----------------------------------------------------------------\n");
    printf("           !! Silahkan membuat username dan password !!            \n");
	printf("-----------------------------------------------------------------\n\n");
    printf("   Enter Username   : "); fflush(stdin);
    scanf ("%s", &username);                   //input username menggunakan string dengan jumlah maksimal 50
    printf("   Enter Password   : "); fflush(stdin);
    scanf ("%s", &password);                 //input password menggunakan string dengan jumlah maksimal 50
    
    int user_check;  //variabel yang digunakan untuk memisahkan proses fprintf dari while loop
    user_check = 0; //pemberian nilai pada variabel user_check
    
    FILE *AP;                               //Membuat pointer AP untuk menunjuk pada file "AkunPelanggan.txt"
    AP=fopen("AkunPelanggan.txt", "r");    //Membuka file AkunPelanggan.txt dengan mode r yakni mode membaca apa yang ada di dalam file tersebut
    
	if(AP == NULL){
    	printf("File txt Tidak Tersedia\n");

	}else{
    	while(fscanf(AP, "Username: %s\t\t Password: %s\t\t Email: %s\t\t Notelp: %s\t\t Nama: %[^\n]\t\t\n", u.username, u.password, u.email, u.notelp, u.nama) != EOF){ //fungsi untuk membaca keseluruhan record yang ada di dalam file
    		if(strcmp(u.username,username)==0){ //fungsi yang membandingkan dua buah string untuk memeriksa apakah username yang diinputkan sudah digunakan sebelumnya atau tidak
        	user_check = user_check + 1;
        	
			}else{
			user_check = user_check + 0;
        	}	
		}
    fclose(AP); //fungsi untuk menutup file AkunPelanggan.txt
	}
	
	FILE *registrasi;                              //Membuat pointer registrasi untuk menunjuk pada file "AkunPelanggan.txt"
	registrasi = fopen("AkunPelanggan.txt","a");  //Membuka file AkunPelanggan.txt dengan mode a yakni mode yang dapat menambahkan record di dalam file tersebut
	
	if(user_check==0){
		if(registrasi == NULL){
    		printf("File txt Tidak Tersedia\n");
    		
		}else{
	        fprintf(registrasi,"Username: %s\t\t Password: %s\t\t Email: %s\t\t Notelp: %s\t\t Nama: %s\t\t\n",username,password,email,notelp,nama); //fungsi menambahkan record ke dalam file
		    fclose(registrasi); //fungsi untuk menutup file AkunPelanggan.txt
		    
			printf("\n=================================================================\n");
			printf("||                                                             ||\n");
			printf("||                      REGISTRASI BERHASIL                    ||\n");
			printf("||         SELAMAT MENIKMATI LAYANAN DARI PROGRAM INI          ||\n");
			printf("||                                                             ||\n");
			printf("=================================================================\n");
			printf("Tekan apapun untuk melanjutkan. . ."); //pernyataan bahwa registasi telah berhasil dilakukan
		    getch();           //untuk memasukkan sebuah karakter dan tanpa diakhiri dengan enter
		    menu_pelanggan(); //memanggil fungsi menu_pelanggan
		}
    }else{
       	printf("\n   Maaf, username telah digunakan!");   //pernyataan bahwa registasi gagal dilakukan karena terdapat username yang sama telah digunakan
       	printf("\n   Klik apapun untuk input ulang..."); //intruksi untuk melanjutkan ke tahap berikutnya
        getch();            //untuk memasukkan sebuah karakter dan tanpa diakhiri dengan enter
        menu_registrasi(); //memanggil fungsi menu_registrasi
    }
}



//=======================================================================//
//*****         Fungsi Untuk Menampilkan Menu Masuk Program         *****//
//=======================================================================//
// Nama Fungsi    : menu_login                                           //
// Input Argumen  : int pilihan                                          //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini berfungsi untuk menampilkan menu masuk    //
//                  ke program dengan menginputkan angka sesuai dengan   //
//                  pilihan dari pengguna program                        //
//                                                                       //
// I Made Arya Adi Pramana - 2205551016                                  //
// Kelas B                                                               //
//=======================================================================//

void pilihan_login(){
	int link; 
	system("cls");
	
	// Instruksi yang diberikan kepada pengguna
	printf("\n=================================================================\n");
	printf("||                                                             ||\n");
	printf("||                        PILIHAN MENU LOGIN                   ||\n");
	printf("||                                                             ||\n");
	printf("|| 1.	LOGIN SEBAGAI ADMIN                                    ||\n");
	printf("|| 2.	LOGIN SEBAGAI PENGGUNA                                 ||\n");
	printf("|| 3.	KEMBALI KE MENU UTAMA                                  ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n");
	printf("Silakan Masukan Pilihan Anda (1/2/3): ");
	link = validasi_tiga();
	system("cls");
	if(link==1){
	// Jika pengguna menginput angka 1 maka dipanggil fungsi login admin
		login_admin();
		
	}else if(link==2){
	// Jika pengguna menginput angka 2 maka dipanggil fungsi login pengguna
		login_pengguna();
		
	}else{
		menu_utama();
	}
}

//=======================================================================//
//*****                  Fungsi Untuk Masuk Pegawai                 *****//
//=======================================================================//
// Nama Fungsi    : login_admin                                          //
// Input Argumen  : -                                                    //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini berfungsi khusus bagi pegawai atau admin  //
//                  untuk masuk ke dalam program, dengan menginputkan    //
//                  password yang sudah terdapat pada file databases     //
//                  'passwordAdmin.txt'                                  //
//                                                                       //
// I Kadek Nanda Surya Agusta - 2205551022                               //
// Kelas B                                                               //
//=======================================================================//
void login_admin(){
	int link;
	int passwordbenar;
	char passP[20]; 
	char passwordP[20];
	
	system("cls");
	FILE *AA;
	AA=fopen("AkunAdmin.txt", "r");
	fscanf(AA, "%s", passwordP);
	fclose(AA); 
	
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||               MENU LOGIN ADMINISTRATOR EASY BOOK            ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n\n");
    printf ("   Password: ");
	scanf("%s", &passP);
	passwordbenar=strcmp(passP,passwordP);
	if(passwordbenar==0){
		menu_admin();
	} else {
		system("cls");
		printf("=================================================================\n");
		printf("||                                                             ||\n");
		printf("||                        PASSWORD SALAH                       ||\n");
		printf("||                                                             ||\n");
		printf("=================================================================\n\n");

        printf("=================================================================\n");
		printf("||                                                             ||\n");
        printf("||   1. LOGIN KEMBALI                                          ||\n");
        printf("||   2. KEMBALI KE MENU PILIHAN LOGIN                          ||\n");
		printf("||                                                             ||\n");
		printf("=================================================================\n");
		printf("Silakan Masukan Pilihan Anda (1/2): ");
        link=validasi_dua();
        if(link==1){
            login_admin();

        }else if (link==2) {
			pilihan_login();

        }else {
            printf ("Masukan pilihan yang sesuai (1/2):\n");
            login_admin();
        }	
	}
	fclose(AA); 
}

//=======================================================================//
//*****                 Fungsi Untuk Login Pengguna                ******//
//=======================================================================//
// Nama Fungsi    : masuk_pengguna                                       //
// Input Argumen  : char username[50], char password[50], dan int pilihan//
// Output Argumen : -                                                    //
// Deskripsi      : Menginput username dan passowrd saat masuk pengguna  //
//                  yang sesuai dengan rekaman pada logrecord.txt        //
//                  akan berlanjut pada menu pengunjung                  //
//                                                                       //
// I Made Arya Adi Pramana - 2205551016                               //
// Kelas B                                                               //
//=======================================================================//
void login_pengguna(){
    char username[50];
    char password[50];
    int link;

    FILE *AP;
    // Membuka file dengan mode "AP"
    AP=fopen("AkunPelanggan.txt", "r");

	if(AP==NULL){
        printf("File txt Tidak Tersedia\n");
    }
    // MENU LOGIN
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||                       MENU LOGIN EASY BOOK                  ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n\n");
    printf ("   Username: "); //input username
    scanf  ("%s", username); 
    printf ("   Password: "); //input password
    scanf  ("%s", password);
    system ("cls");
    
    int user_check;
    user_check = 0;

    while(fscanf(AP, "Username: %s\t\t Password: %s\t\t Email: %s\t\t Notelp: %s\t\t Nama: %[^\n]\t\t\n", u.username, u.password, u.email, u.notelp, u.nama) != EOF){
    	if(strcmp(u.username,username)==0 && strcmp(u.password,password)==0){
        	user_check = user_check + 1;
        	
		}else{
			user_check = user_check + 0;
        }
    }
    
    //  Jika akun tidak ditemukan maka akan diberikan pilihan untuk melakukan registrasi, melakukan login kembali atau kembali ke menu pilihan login
    if(user_check==0){
    	printf("=================================================================\n");
		printf("||                                                             ||\n");
		printf("||                       AKUN TIDAK DITEMUKAN                  ||\n");
		printf("||                                                             ||\n");
		printf("=================================================================\n\n");

        printf("=================================================================\n");
		printf("||                                                             ||\n");
        printf("||   1. MELAKUKAN REGISTRASI                                   ||\n");
        printf("||   2. MELAKUKAN LOGIN KEMBALI                                ||\n");
        printf("||   3. KEMBALI KE MENU PILIHAN LOGIN                          ||\n");
		printf("||                                                             ||\n");
		printf("=================================================================\n");
		printf("Silakan Masukan Pilihan Anda (1/2/3): ");
        link=validasi_tiga();
        system ("cls");

        if(link==1){
        // Jika pengguna mengetik nomor 1 maka akan dialihkan kepada fungsi registrasi
            menu_registrasi();

        }else if (link==2) {
        // Jika pengguna mengetik nomor 2 maka akan dialihkan kepada fungsi login kembali	
            login_pengguna();
                
        }else if (link==3){
        // Jika pengguna mengetik nomor 3 maka akan dialihkan kepada fungsi pilihan login    	
            pilihan_login();

        }else{
            printf("Masukan pilihan yang sesuai (1/2/3):\n");
            login_pengguna();
        }

	}else{
		menu_pelanggan();
		
	}
    fclose(AP); //menutup file "AP.txt"
}


//=======================================================================//
//*****             Fungsi Untuk Menampilkan Menu Admin             *****//
//=======================================================================//
// Nama Fungsi    : menu admin                                           //
// Input Argumen  : int                                                  //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini berfungsi untuk menampilkan kategori menu //
//                  khusus untuk pegawai atau admin, yaitu 1 untuk input //
//                  data villa, 2 untuk hapus data villa, 3 untuk data   //
//                  pesanan villa, 4 untuk edit pesanan villa dan 5      //
//                  untuk kembali ke menu utama                          //
//                                                                       //
// I Kadek Nanda Surya Agusta - 2205551022                               //
// Kelas B                                                               //
//=======================================================================//
void menu_admin(){
	int link;
	system("cls");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
    printf("||                      MENU ADMINISTRATOR                     ||\n");
    printf("||                           EASY BOOK                         ||\n");
    printf("||                                                             ||\n");
    printf("=================================================================\n");
    printf("                                                                 \n");
    printf("=================================================================\n");
	printf("||                                                             ||\n");
    printf("||   1. INPUT DATA VILLA                                       ||\n");
    printf("||   2. HAPUS DATA VILLA                                       ||\n");
    printf("||   3. DATA PESANAN VILLA                                     ||\n");
    printf("||   4. EDIT PESANAN VILLA                                     ||\n"); 
    printf("||   5. KEMBALI KE MENU UTAMA                                  ||\n");
	printf("||                                                             ||\n");
    printf("=================================================================\n");
    printf("Silakan Masukan Pilihan Anda (1/2/3/4/5): ");
    link=validasi_lima();
    system ("cls");

    if(link==1){
    // Jika admin mengetik nomor 1 maka akan dialihkan kepada fungsi input_villa 	
        input_villa();

    }else if (link==2) {
    // Jika admin mengetik nomor 2 maka akan dialihkan kepada fungsi hapus_villa	
        hapus_villa();
                
    }else if (link==3){
    // Jika admin mengetik nomor 3 maka akan dialihkan kepada fungsi pesanan_villa	
        pesanan_villa();
    
    }else if (link==4){
    // Jika admin mengetik nomor 4 maka akan dialihkan kepada fungsi edit_pesanan
        edit_pesanan();
        
    }else if (link==5){
    // Jika admin mengetik nomor 5 maka akan dialihkan kepada fungsi menu_utama	
        menu_utama();

    }else{
        printf("Masukan pilihan yang sesuai (1/2/3/4/5):\n");
        menu_admin();
    }
		
}

//=======================================================================//
//*****             Fungsi Untuk Menampilkan Menu Pengguna          *****//
//=======================================================================//
// Nama Fungsi    : menu pengguna                                        //
// Input Argumen  : int                                                  //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini berfungsi untuk menampilkan kategori menu //
//                  khusus untuk pengguna, yaitu 1 untuk melihat apa itu //
//                  villa easy book, 2 untuk melihat aturan pemesanan    //
//                  villa, 3 untuk melihat pilighan villa, 4 untuk       //
//                  melihat tipe dan fasilitas villa, 5 untuk memesan    //
//                  villa, dan 6 untuk kembali ke menu utama             //
//                                                                       //
// I Made Arya  Adi Pramana - 2205551016                                 //
// Kelas B                                                               //
//=======================================================================//
void menu_pelanggan(){
	int link;
	system("cls");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
    printf("||                         MENU PENGGUNA                       ||\n");
    printf("||                           EASY BOOK                         ||\n");
    printf("||                                                             ||\n");
    printf("=================================================================\n");
    printf("                                                                 \n");
    printf("=================================================================\n");
	printf("||                                                             ||\n");
    printf("||   1. TENTANG KAMI                                           ||\n");
    printf("||   2. ATURAN PEMESANAN VILLA                                 ||\n");
    printf("||   3. PILIHAN VILLA                                          ||\n");
    printf("||   4. TIPE DAN FASILITAS VILLA                               ||\n");
    printf("||   5. PESAN VILLA                                            ||\n"); 
    printf("||   6. KEMBALI KE MENU UTAMA                                  ||\n");
	printf("||                                                             ||\n");
    printf("=================================================================\n");
    printf("Silakan Masukan Pilihan Anda (1/2/3/4/5/6): ");
    link=validasi_enam();
    system ("cls");

    if(link==1){
    // Jika pengguna mengetik nomor 1 maka akan dialihkan kepada fungsi tentang_kami	
        tentang_kami();

    }else if (link==2) {
    // Jika pengguna mengetik nomor 2 maka akan dialihkan kepada fungsi aturan_pemesanan	
        aturan_pemesanan();
                
    }else if (link==3){
    // Jika pengguna mengetik nomor 3 maka akan dialihkan kepada fungsi menu_pilihan_villa	
        menu_pilihan_villa();
    
    }else if (link==4){
    // Jika pengguna mengetik nomor 4 maka akan dialihkan kepada fungsi tipe_villa 	
        tipe_villa();
        
    }else if (link==5){
    // Jika pengguna mengetik nomor 5 maka akan dialihkan kepada fungsi pesan_villa 	
        pesan_villa();

    }else if (link==6){
    // Jika pengguna mengetik nomor 1 maka akan dialihkan kepada fungsi menu_utama	
        menu_utama();

    }else{
        printf("Masukan pilihan yang sesuai (1/2/3/4/5):\n");
        menu_pelanggan();
    }
}

void input_villa(){
	char pilihan;
    char id_villa[10];      
    char nama_villa[255];
	char alamat_villa[255]; 
	char tipe_kamar[255]; 
    char tipe_fasilitas[255];
    int harga; 

	system("cls");
	do{
	//intruksi untuk menginput data villa	
		printf("=================================================================\n");
		printf("||                                                             ||\n");
		printf("||                       MENU INPUT DATA VILLA                 ||\n");
		printf("||                             EASY BOOK                       ||\n");
		printf("||                                                             ||\n");
		printf("=================================================================\n\n");
		printf("   VILLA YANG TELAH TERSEDIA:                                    \n");
		pilihan_villa();
		printf("                                                                 \n");
		printf("-----------------------------------------------------------------\n");
		printf("\n   Id Villa         : "); fflush(stdin);
		scanf("%s", &id_villa);
		printf("   Nama Villa       : "); fflush(stdin);
		scanf("%s", &nama_villa);
		printf("   Alamat Villa     : "); fflush(stdin);
		scanf ("%[^\n]", &alamat_villa);
		printf("   Tipe Kamar       : "); fflush(stdin);
		scanf ("%s", &tipe_kamar);
		printf("   Tipe Fasilitas   : "); fflush(stdin);
		scanf ("%s", &tipe_fasilitas);
		printf("   Harga Sewa       : "); fflush(stdin);
		scanf ("%d", &harga);

		int user_check; //disini user akan mengecek data yang ada di villa tersebut
		user_check = 0; // Inisialisasi value sama dengan 0
		
		FILE *DV; // variable pointer bernama DV dengan tipe FILE
		DV=fopen("DataVilla.txt", "r"); //data akan diambil dari file txt
		
		if(DV == NULL){ //jika hasilnya == NULL maka akan muncul tampilan file txt tidak tersedia
			printf("File txt Tidak Tersedia\n");

		}else{
		// EOF atau End Of File sesuai namanya, kondisi while akan terus dijalankan hingga fscanf berada pada akhir dari file
			while(fscanf(DV, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %[^\n]\t\t\n",&dv.id_villa,&dv.nama_villa,&dv.tipe_kamar,&dv.tipe_fasilitas,&dv.harga,&dv.alamat_villa) != EOF){
				if(strcmp(dv.id_villa,id_villa)==0){ // akan di cek apakah id villa pada file txt sama dengan id villa yang diinputkan user
					user_check = user_check + 1; // jika benar maka beri tambahan nilai 1 pada user check
				
				}else{
					user_check = user_check + 0; // jika salah maka tidak beri tambahan apa-apa
				}	
			}
		fclose(DV);
		}
		
		FILE *IV;   // variable pointer bernama IV dengan tipe FILE
		IV = fopen("DataVilla.txt","a"); // mengakses file txt yang memiliki list data villa
		
		if(user_check==0){  // akan masuk ke if atau akan diproses input villa jika user_check == 0
			if(IV == NULL){ // akan di cek apakah txt berhasil di buka, jika ternyata NULL maka print text dibawah
				printf("File txt Tidak Tersedia\n");
				
			}else{ // Jika berhasil di buka maka tambahkan data kedalam file txt
				fprintf(IV, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %s\t\t\n",id_villa,nama_villa,tipe_kamar,tipe_fasilitas,harga,alamat_villa);
				fclose(IV);
				
				printf("\n=================================================================\n");
				printf("||                                                             ||\n");
				printf("||                    INPUT DATA VILLA BERHASIL                ||\n");
				printf("||                                                             ||\n");
				printf("=================================================================\n");
			}
		}else{ // Jika ternyata user_check bukan 0, maka tidak diperbolehkan input data villa
			printf("\n   Maaf, id telah digunakan!");
			printf("\n   Klik apapun untuk input ulang...");
			getch();
			input_villa();
		}
		printf("\n-----------------------------------------------------------------\n");
		printf("|   Pilih Y jika ingin menginputkan data kembali                |\n"); 
		printf("|   Pilih N jika ingin kembali ke menu admin                    |\n");
		printf("-----------------------------------------------------------------  \n");
		printf("    Masukan pilihan anda (Y/N): "); fflush(stdin);
		pilihan=exite_admin();
		system("cls");

	}while(pilihan=='y' || pilihan=='Y');
}

void hapus_villa(){
	char pilihan;
	datavilla dv;
	char id_hapus[10];
	do{
	//intruksi untuk hapus data villa	
		printf("=================================================================\n");
		printf("||                                                             ||\n");
		printf("||                       MENU HAPUS DATA VILLA                 ||\n");
		printf("||                             EASY BOOK                       ||\n");
		printf("||                                                             ||\n");
		printf("=================================================================\n");
		printf("                                                                 \n");
		printf("-----------------------------------------------------------------\n");
		printf("                                                                 \n");
		printf("   PILIHAN VILLA EASY BOOK:                                      \n");	
		pilihan_villa();
		printf("                                                                 \n");
		printf("-----------------------------------------------------------------\n");
		printf("   Pilih ID villa yang akan dihapus: "); fflush(stdin); //setelah muncul menu pilihan villa admin akan diminta untuk memasukkan id villa yang nantinya akan di hapus datanya
		scanf("%s",&id_hapus);

		FILE *fp1, *fp2;


		fp1 = fopen("DataVilla.txt", "r"); // mengakses file txt DataVilla dengan mode r atau read (tidak bisa mengedit file, hanya untuk baca data saja)
		fp2 = fopen("Temp_Data.txt", "a"); // mengakses/membuat file txt dengan nama file Temp_Data dengan mode a atau append (Bisa mengedit fil
			

		if(fp1==NULL){ // Jika ternyata DataVilla gagal dibuka maka masuk ke if
			fprintf(stderr,"Tidak dapat membuka file...");
			exit(0);
		}
	    // Lakukan looping while sebanyak baris data yang ada di file DataVilla, dan akhiri saat sudah stop di akhir file
		while(fscanf(fp1, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %[^\n]\t\t\n",&dv.id_villa,&dv.nama_villa,&dv.tipe_kamar,&dv.tipe_fasilitas,&dv.harga,&dv.alamat_villa) != EOF){
			if(strcmp(dv.id_villa,id_hapus)!=0){ // selama perulangan jika id villa di file DataVilla TIDAK SAMA dengan id inputan user, maka akan menyalin data baris saat ini ke file Temp_Data
				fprintf(fp2, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %s\t\t\n",dv.id_villa,dv.nama_villa,dv.tipe_kamar,dv.tipe_fasilitas,dv.harga,dv.alamat_villa); 
			}
		}

		fclose(fp1);
		fclose(fp2);

		remove("DataVilla.txt"); // Menghapus file asli
		rename("Temp_Data.txt", "DataVilla.txt"); // Merename nama Temp_Data menjadi nama file asli. Ini untuk mereplika aksi delete (mengurangi jumlah data pada file)
		printf("   Data villa telah berhasil dihapus\n");
		printf("\n-----------------------------------------------------------------\n");
		printf("|   Pilih Y jika ingin menghapus data kembali                   |  \n"); 
		printf("|   Pilih N jika ingin kembali ke menu admin                    |  \n");
		printf("-----------------------------------------------------------------  \n");
		printf("    Masukan pilihan anda (Y/N): "); fflush(stdin);
		pilihan=exite_admin();
		system("cls");
	}while(pilihan=='y' || pilihan=='Y');
}

//=======================================================================//
//***********   Fungsi Untuk Menampilkan Data Pesananan     *************//
//=======================================================================//
// Nama Fungsi    : pesanan_villa                                        //
// Input Argumen  : char                                                 //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini digunakan untuk menampilkan data pesanan  //
//                  villa easy book                                      //
//                                                                       //
// I Kadek Nanda Surya Agusta- 2205551022                                //
// Kelas B                                                               //
//=======================================================================//
void pesanan_villa(){
	char pilihan;
	char id_pesanan[10];
	int cek;
    FILE *cekdata;
	do{
		system("cls");
		printf("=================================================================\n");
		printf("||                                                             ||\n");
		printf("||                        DATA PESANAN VILLA                   ||\n");
		printf("||                             EASY BOOK                       ||\n");
		printf("||                                                             ||\n");
		printf("=================================================================\n");
		printf("                                                                 \n");
		printf("=================================================================\n");
		printf("|     ID PEMESAN    |       TANGGAL CI    |        STATUS       |\n");
		printf("=================================================================\n");

		cekdata=fopen("DataPesanan.txt","r");

		if(cekdata==NULL){
			printf("file txt tidak ada!");
		}else{
			while(fscanf(cekdata, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",&pv.tm_mday,&pv.tm_mon,&pv.tm_year,&pv.ids_pesanan,&pv.username,&pv.id_villa,&pv.tglCI,&pv.blnCI,&pv.thnCI,&pv.lama_sewa,&pv.tglCO,&pv.blnCO,&pv.thnCO,&pv.totalPembayaran,&pv.sisaPembayaran,&pv.status) != EOF){
				printf("\t%s\t\t%d/%d/%d\t\t%s\n", pv.ids_pesanan, pv.tglCI, pv.blnCI, pv.thnCI, pv.status);
			}
		}

		fclose(cekdata);
		printf("=================================================================\n");
		printf("   Masukan id untuk melihat detail pesanan: "); fflush(stdin);
		scanf("%s", &id_pesanan);

		cek=0;
		FILE *cekdata;
		cekdata=fopen("DataPesanan.txt","r");

		if(cekdata==NULL){
			printf("file txt tidak ada!");

		}else{
			while(fscanf(cekdata, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",&pv.tm_mday,&pv.tm_mon,&pv.tm_year,&pv.ids_pesanan,&pv.username,&pv.id_villa,&pv.tglCI,&pv.blnCI,&pv.thnCI,&pv.lama_sewa,&pv.tglCO,&pv.blnCO,&pv.thnCO,&pv.totalPembayaran,&pv.sisaPembayaran,&pv.status) != EOF){
				if(strcmp(pv.ids_pesanan,id_pesanan)==0){
					system("cls");
					printf("=================================================================\n");
					printf("||                                                             ||\n");
					printf("||                      DETAIL PESANAN VILLA                   ||\n");
					printf("||                   PENGGUNA PROGRAM EASY BOOK                ||\n");
					printf("||                                                             ||\n");
					printf("=================================================================\n");
					printf("                                                                 \n");
					printf("   Waktu Pemesanan   : %d/%d/%d\n",pv.tm_mday,pv.tm_mon,pv.tm_year);  fflush(stdin);
					printf("   Id Pemesanan      : %s\n",pv.ids_pesanan);                         fflush(stdin);
					printf("   Username          : %s\n",pv.username);                            fflush(stdin);
					printf("   Id Villa          : %s\n",pv.id_villa);                            fflush(stdin);
					printf("   Tanggal Check In  : %d/%d/%d\n",pv.tglCI, pv.blnCI, pv.thnCI);     fflush(stdin);
					printf("   Lama Sewa         : %d Hari\n",pv.lama_sewa);                           fflush(stdin);
					printf("   Tanggal Check Out : %d/%d/%d\n",pv.tglCO, pv.blnCO, pv.thnCO);     fflush(stdin);
					printf("   Total Bayar       : %d\n",pv.totalPembayaran);                     fflush(stdin);
					printf("   Sisa Bayar        : %d\n",pv.sisaPembayaran);                      fflush(stdin);
					printf("   Status            : %s\n",pv.status);                              fflush(stdin);
					printf("                                                                 \n");
					printf("=================================================================\n");
					cek=1;
				}
	
			}
			fclose(cekdata);
		}
		if(cek !=1){
			printf("\n   Id villa tidak dapat ditemukan");
			printf("\n   Klik apapun untuk mencari ulang...");
			getch();
			pesanan_villa();
		}
		printf("\n-----------------------------------------------------------------\n");
		printf("|   Pilih Y jika ingin melihat data kembali                     |\n"); 
		printf("|   Pilih N jika ingin kembali ke menu admin                    |\n");
		printf("-----------------------------------------------------------------  \n");
		printf("    Masukan pilihan anda (Y/N): "); fflush(stdin);
		pilihan=exite_admin();
		system("cls");
	}while(pilihan=='y' || pilihan=='Y');
}

//=======================================================================//
//*****             Fungsi Untuk Menampilkan Menu Edit Data Pesanan *****//
//=======================================================================//
// Nama Fungsi    : menu Edit Data Pesanan                               //
// Input Argumen  : int                                                  //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini berfungsi untuk menampilkan kategori menu //
//                  khusus untuk pegawai atau admin, yaitu 1 untuk hapus //
//                  data pesanan, 2 untuk update data pesanan, 3 untuk   //
//                  kembali ke menu admin                                //
//                                                                       //
// I Kadek Nanda Surya Agusta - 2205551022                               //
// Kelas B                                                               //
//=======================================================================//
void edit_pesanan(){
	int link;
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||                      MENU EDIT DATA PESANAN                 ||\n");
	printf("||                             EASY BOOK                       ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n");
	printf("                                                                 \n");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("|| PILIHAN PROSES EDIT:                                        ||\n");                           
	printf("|| 1. Hapus Data Pesanan                                       ||\n");
	printf("|| 2. Update Data Pesanan                                      ||\n");
	printf("|| 3. Kembali ke Menu Admin                                    ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n");
	printf("Masukan pilihan anda (1/2/3): ");
	link = validasi_tiga();
	system("cls");
	if(link==1){
	// Jika admin mengetik nomor 1 maka akan dialihkan kepada fungsi hapus_pesanan	
		hapus_pesanan();
		
	}else if(link==2){
	// Jika admin mengetik nomor 2 maka akan dialihkan kepada fungsi update_status
		update_status();
		
	}else{
	// Jika admin mengetik nomor 3 maka akan dialihkan kepada fungsi menu_admin	
		menu_admin();
	}
}

//=======================================================================//
//**********   Fungsi Untuk Menampilkan Hapus Data Pesananan  ***********//
//=======================================================================//
// Nama Fungsi    : Hapus_pesanan                                        //
// Input Argumen  : char                                                 //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini digunakan untuk menampilkan hapus data    //
//                  pesanan villa easy book                              //
//                                                                       //
// I Kadek Nanda Surya Agusta- 2205551022                                //
// Kelas B                                                               //
//=======================================================================//
void hapus_pesanan(){
	char pilihan;
	datavilla dv;
	char id_hapus[10];
	do{
		system("cls");
		printf("=================================================================\n");
		printf("||                                                             ||\n");
		printf("||                      MENU HAPUS DATA PESANAN                ||\n");
		printf("||                             EASY BOOK                       ||\n");
		printf("||                                                             ||\n");
		printf("=================================================================\n");
		printf("                                                                 \n");
		printf("=================================================================\n");
		printf("|     ID PEMESAN    |       TANGGAL CI    |        STATUS       |\n");
		printf("=================================================================\n");

		FILE *cekdata;
		cekdata=fopen("DataPesanan.txt","r");

		if(cekdata==NULL){
			printf("file txt tidak ada!");
		}else{
			while(fscanf(cekdata, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",&pv.tm_mday,&pv.tm_mon,&pv.tm_year,&pv.ids_pesanan,&pv.username,&pv.id_villa,&pv.tglCI,&pv.blnCI,&pv.thnCI,&pv.lama_sewa,&pv.tglCO,&pv.blnCO,&pv.thnCO,&pv.totalPembayaran,&pv.sisaPembayaran,&pv.status) != EOF){
				printf("\t%s\t\t%d/%d/%d\t\t%s\n", pv.ids_pesanan, pv.tglCI, pv.blnCI, pv.thnCI, pv.status);
			}
		}
		fclose(cekdata);
		printf("=================================================================\n");
		printf("   Pilih ID pemesanan yang akan dihapus: "); fflush(stdin);
		scanf("%s",&id_hapus);

		FILE *fp1, *fp2;


		fp1 = fopen("DataPesanan.txt", "r");
		fp2 = fopen("Temp_Data2.txt", "a");
				

		if(fp1==NULL){
			fprintf(stderr,"Tidak dapat membuka file...");
			exit(0);
		}

		while(fscanf(fp1, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",&pv.tm_mday,&pv.tm_mon,&pv.tm_year,&pv.ids_pesanan,&pv.username,&pv.id_villa,&pv.tglCI,&pv.blnCI,&pv.thnCI,&pv.lama_sewa,&pv.tglCO,&pv.blnCO,&pv.thnCO,&pv.totalPembayaran,&pv.sisaPembayaran,&pv.status) != EOF){
			if(strcmp(pv.ids_pesanan,id_hapus)!=0){
				fprintf(fp2, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",pv.tm_mday,pv.tm_mon,pv.tm_year,pv.ids_pesanan,pv.username,pv.id_villa,pv.tglCI,pv.blnCI,pv.thnCI,pv.lama_sewa,pv.tglCO,pv.blnCO,pv.thnCO,pv.totalPembayaran,pv.sisaPembayaran,pv.status); 
			}
		}

		fclose(fp1);
		fclose(fp2);

		remove("DataPesanan.txt"); 
		rename("Temp_Data2.txt", "DataPesanan.txt");
		printf("\n   Data pesanan telah berhasil dihapus\n"); fflush(stdin);
		printf("\n-----------------------------------------------------------------\n");
		printf("|   Pilih Y jika ingin menghapus data kembali                   |  \n"); 
		printf("|   Pilih N jika ingin kembali ke menu admin                    |  \n");
		printf("-----------------------------------------------------------------  \n");
		printf("    Masukan pilihan anda (Y/N): "); fflush(stdin);
		pilihan=exite_admin();
		system("cls");
	}while(pilihan=='y' || pilihan=='Y');
}

//=======================================================================//
//**********     Fungsi Untuk Menampilkan Update Status       ***********//
//=======================================================================//
// Nama Fungsi    : Update_Status                                        //
// Input Argumen  : char                                                 //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini digunakan untuk menampilkan update status //
//                  pesanan villa easy book                              //
//                                                                       //
// I Kadek Nanda Surya Agusta- 2205551022                                //
// Kelas B                                                               //
//=======================================================================//
void update_status(){
	char status[15] = "BOOKED";
	char id_update[10];
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen("DataPesanan.txt", "r");
	fp2 = fopen("Update.txt", "a");
	pesanvilla pv; 
	system("cls");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||                     MENU UPDATE DATA PESANAN                ||\n");
	printf("||                             EASY BOOK                       ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n");
	printf("                                                                 \n");
	printf("=================================================================\n");
	printf("|     ID PEMESAN    |       TANGGAL CI    |        STATUS       |\n");
	printf("=================================================================\n");

	FILE *cekdata;
	cekdata=fopen("DataPesanan.txt","r");

	if(cekdata==NULL){
		printf("file txt tidak ada!");
	}else{
		while(fscanf(cekdata, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",&pv.tm_mday,&pv.tm_mon,&pv.tm_year,&pv.ids_pesanan,&pv.username,&pv.id_villa,&pv.tglCI,&pv.blnCI,&pv.thnCI,&pv.lama_sewa,&pv.tglCO,&pv.blnCO,&pv.thnCO,&pv.totalPembayaran,&pv.sisaPembayaran,&pv.status) != EOF){
			printf("\t%s\t\t%d/%d/%d\t\t%s\n", pv.ids_pesanan, pv.tglCI, pv.blnCI, pv.thnCI, pv.status);
		}
	}
	fclose(cekdata);
	printf("=================================================================\n");
	printf("   Masukan id pemesanan yang ingin diperbaharui: ");
	scanf("%s", id_update);


	if(fp1==NULL){
		fprintf(stderr,"Tidak dapat membuka file...");
		exit(1);
	}

	while(fscanf(fp1, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",&pv.tm_mday,&pv.tm_mon,&pv.tm_year,&pv.ids_pesanan,&pv.username,&pv.id_villa,&pv.tglCI,&pv.blnCI,&pv.thnCI,&pv.lama_sewa,&pv.tglCO,&pv.blnCO,&pv.thnCO,&pv.totalPembayaran,&pv.sisaPembayaran,&pv.status) != EOF){
		if(strcmp(pv.ids_pesanan,id_update)!=0){
			fprintf(fp2, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",pv.tm_mday,pv.tm_mon,pv.tm_year,pv.ids_pesanan,pv.username,pv.id_villa,pv.tglCI,pv.blnCI,pv.thnCI,pv.lama_sewa,pv.tglCO,pv.blnCO,pv.thnCO,pv.totalPembayaran,pv.sisaPembayaran,pv.status);
		}
	}

	fprintf(fp2, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",pv.tm_mday,pv.tm_mon,pv.tm_year,id_update,pv.username,pv.id_villa,pv.tglCI,pv.blnCI,pv.thnCI,pv.lama_sewa,pv.tglCO,pv.blnCO,pv.thnCO,pv.totalPembayaran,pv.sisaPembayaran,status);
	fclose(fp1);
	fclose(fp2);
	remove("DataPesanan.txt"); 
	rename("Update.txt", "DataPesanan.txt");
	printf("\n   Data pesanan telah berhasil diperbaharui\n"); fflush(stdin);
	printf("\n   Klik apapun untuk kembali ke menu admin..."); fflush(stdin);
	getch();
	menu_admin();
}

//=======================================================================//
//*****             Fungsi Untuk Menampilkan Menu Tentang Kami      *****//
//=======================================================================//
// Nama Fungsi    : menu tentang kami                                    //
// Input Argumen  : -                                                    //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini berfungsi untuk menampilkan tentang       //
//                  program easy book itu sendiri                       //
//                                                                       //
// I Made Arya  Adi Pramana - 2205551016                                 //
// Kelas B                                                               //
//=======================================================================//
void tentang_kami(){
	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||                            TENTANG                           ||\n");
	printf("||                        PROGRAM EASY BOOK                     ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("                                                                  \n");
	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("|| Easy Book merupakan program yang dikembangkan guna memenuhi  ||\n");
	printf("|| tugas besar mata kuliah algoritma dan pemrograman. Hal ini   ||\n");
	printf("|| didasari oleh keberadaan Pulau Bali sebagai tujuan yang      ||\n");
	printf("|| marak dikunjungi oleh wisatawan. Sehingga, terdapat banyak   ||\n");
	printf("|| villa yang tersedia di Bali. Beranjak dari hal tersebut,     ||\n");
	printf("|| kami memiliki keinginan untuk mengembangkan program yang     ||\n");
	printf("|| dapat mensentralisasi kegiatan transaksi antara pemilik      ||\n");
	printf("|| dan pengunjung villa. Program  sederhana ini masih dalam     ||\n");
	printf("|| tahap pengembangan dan tentunya masih banyak terdapat        ||\n");
	printf("|| kekurangan. Oleh sebab itu kami sangat mengharapkan masukan  ||\n");
	printf("|| dari pengguna guna membantu dalam pengembangan program       ||\n");
	printf("|| ini selanjutnya. Akhir kata, kami sebagai pengembang         ||\n");
	printf("|| mengucapkan terima kasih sebab telah menggunakan program ini ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("Klik apapun untuk kembali ke menu pengguna... ");
	getch();
	menu_pelanggan();
}

//=======================================================================//
//*****          Fungsi Untuk Menampilkan Menu Aturan Pemesanan     *****//
//=======================================================================//
// Nama Fungsi    : menu aturan pemesanan                                //
// Input Argumen  : -                                                    //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini berfungsi untuk menampilkan tentang       //
//                  aturan pemesanan villa easy book                     //
//                                                                       //
// I Made Arya  Adi Pramana - 2205551016                                 //
// Kelas B                                                               //
//=======================================================================//
void aturan_pemesanan(){
	system ("cls");
	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||                             ATURAN                           ||\n");
	printf("||            PEMESANAN VILLA MELALUI PROGRAM EASY BOOK         ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("                                                                  \n");
	printf("==================================================================\n");
	printf("||                                                              ||\n");
	printf("||   Berikut adalah hal yang harus diketahui sebelum memesan    ||\n");
	printf("||   villa menggunakan program easybook:                        ||\n");
	printf("||   1. Setiap pememesan harus mempersiapkan DP dan membayar    ||\n");
	printf("||      maksimal H+1 dari waktu pemesanan. Apabila tidak,       ||\n");
	printf("||      pesanan akan dihapus oleh admin                         ||\n");
	printf("||   2. Setiap pemesanan akan dikenakan biaya admin Rp. 10.000  ||\n");
	printf("||   3. Pemesan akan dikenakan deposito Rp.500.000. Deposito    ||\n");
	printf("||      akan dikembalikan pada saat check out bila tidak ada    ||\n");
	printf("||      kerusakan barang atau fasilitas saat menempati villa    ||\n");
	printf("||   4. Waktu check in setiap villa sama pukul 13.00 WITA dan   ||\n");
	printf("||      waktu check out pukul 12.00 WITA                        ||\n");
	printf("||                                                              ||\n");
	printf("==================================================================\n");
	printf("Klik apapun untuk kembali ke menu pengguna... ");
	getch();
	menu_pelanggan();
}

void pilihan_villa(){
    FILE *cekdata;

    cekdata=fopen("DataVilla.txt","r");

    if(cekdata==NULL){
        printf("file txt tidak ada!");
    }else{
		while(fscanf(cekdata, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %[^\n]\t\t\n",&dv.id_villa,&dv.nama_villa,&dv.tipe_kamar,&dv.tipe_fasilitas,&dv.harga,&dv.alamat_villa) != EOF){
			printf("   %s. Villa %s: %s\n", dv.id_villa, dv.nama_villa, dv.alamat_villa);
		}
	}
	fclose(cekdata);
}

//=======================================================================//
//*****             Fungsi Untuk Menampilkan Menu Pilihan Villa     *****//
//=======================================================================//
// Nama Fungsi    : menu pilihan villa                                   //
// Input Argumen  : char, int                                            //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini berfungsi untuk menampilkan tentang       //
//                  pilihan villa yang tersedia di villa easy book       //
//                                                                       //
// I Made Arya  Adi Pramana - 2205551016                                 //
// Kelas B                                                               //
//=======================================================================//
void menu_pilihan_villa(){
	char pilihan;
	char id_villa[10];
	int link;
	int cek;
	do{
		system("cls");
		printf("=================================================================\n");
		printf("||                                                             ||\n");
		printf("||                          PILIHAN VILLA                      ||\n");
		printf("||                  YANG TERSEDIA DALAM EASY BOOK              ||\n");
		printf("||                                                             ||\n");
		printf("=================================================================\n");
		printf("                                                                 \n");
		pilihan_villa();
		printf("                                                                 \n");
		printf("-----------------------------------------------------------------\n");
		printf("   Masukan id untuk melihat detail villa: "); fflush(stdin);
		scanf("%s", &id_villa);

		cek=0;
		FILE *cekdata;
		cekdata=fopen("DataVilla.txt","r");

		if(cekdata==NULL){
			printf("file txt tidak ada!");

		}else{
			while(fscanf(cekdata, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %[^\n]\t\t\n",&dv.id_villa,&dv.nama_villa,&dv.tipe_kamar,&dv.tipe_fasilitas,&dv.harga,&dv.alamat_villa) != EOF){
				if(strcmp(dv.id_villa,id_villa)==0){
					system("cls");
					printf("=================================================================\n");
					printf("||                                                             ||\n");
					printf("||                          PILIHAN VILLA                      ||\n");
					printf("||                  YANG TERSEDIA DALAM EASY BOOK              ||\n");
					printf("||                                                             ||\n");
					printf("=================================================================\n");
					printf("                                                                 \n");
					printf("   Id Villa        : %s\n",dv.id_villa);          fflush(stdin);
					printf("   Nama Villa      : %s Villa\n",dv.nama_villa);  fflush(stdin);
					printf("   Alamat Villa    : %s\n",dv.alamat_villa);      fflush(stdin);
					printf("   Tipe Kamar      : %s\n",dv.tipe_kamar);        fflush(stdin);
					printf("   Tipe Fasilitas  : %s\n",dv.tipe_fasilitas);    fflush(stdin);
					printf("   Harga           : Rp. %d\n",dv.harga);         fflush(stdin);
					printf("                                                                 \n");
					printf("=================================================================\n");
					cek=1;
				}
	
			}
			fclose(cekdata);
		}
		if(cek !=1){
			printf("\n   Id villa tidak dapat ditemukan");
			printf("\n   Klik apapun untuk mencari ulang...");
			getch();
			menu_pilihan_villa();
		}

		printf("\n   Apakah anda ingin melihat ketersediaan villa?\n");
		printf("\n   Pilih 1 jika ingin melihat ketersediaan villa\n");
		printf("   Pilih 2 jika tidak ingin melihat ketersediaan villa\n\n");
		printf("   Masukan pilihan anda: ");
		link=validasi_dua();

		if(link==1){
			check_villa();

		}else{
			printf("\n-----------------------------------------------------------------\n");
			printf("|   Pilih Y jika ingin melihat data kembali                     |\n"); 
			printf("|   Pilih N jika ingin kembali ke menu pengguna                 |\n");
			printf("-----------------------------------------------------------------  \n");
			printf("    Masukan pilihan anda (Y/N): "); fflush(stdin);
			pilihan=exite_pengguna();
			system("cls");
		}
	}while(pilihan=='y' || pilihan=='Y');

}

//=======================================================================//
//*****             Fungsi Untuk Menampilkan Menu Check Villa       *****//
//=======================================================================//
// Nama Fungsi    : menu check villa                                     //
// Input Argumen  : char, int                                            //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini berfungsi untuk menampilkan tentang       //
//                  check ketersediaan villa yang tersedia dalam villa   //
//                  easy book                                            //
//                                                                       //
// I Made Arya  Adi Pramana - 2205551016                                 //
// Kelas B                                                               //
//=======================================================================//
void check_villa(){
	char pilihan;
	char id_villa[10];
	int blnCI;
	int thnCI;
	int cek;
	int link;
    FILE *cekdata;
	do{
		system("cls");
		printf("=================================================================\n");
		printf("||                                                             ||\n");
		printf("||                      CHECK KETERSEDIAAN VILLA               ||\n");
		printf("||                           DALAM EASY BOOK                   ||\n");
		printf("||                                                             ||\n");
		printf("=================================================================\n");
		printf("                                                                 \n");
		pilihan_villa();
		printf("                                                                 \n");
		printf("-----------------------------------------------------------------\n");
		printf("\n   Masukan id untuk melihat ketersediaan villa : "); fflush(stdin);
		scanf("%s", &id_villa);
		printf("   Masukan bulan yang ingin dicari             : "); fflush(stdin);
		scanf("%s", &blnCI);
		printf("   Masukan tahun yang ingin dicari             : "); fflush(stdin);
		scanf("%s", &thnCI);
		cekdata=fopen("DataPesanan.txt","r");

		if(cekdata==NULL){
			printf("file txt tidak ada!");

		}else{
			system("cls");
			printf("=================================================================\n");
			printf("||                                                             ||\n");
			printf("||                      CHECK KETERSEDIAAN VILLA               ||\n");
			printf("||                           DALAM EASY BOOK                   ||\n");
			printf("||                                                             ||\n");
			printf("=================================================================\n\n");
			while(fscanf(cekdata, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",&pv.tm_mday,&pv.tm_mon,&pv.tm_year,&pv.ids_pesanan,&pv.username,&pv.id_villa,&pv.tglCI,&pv.blnCI,&pv.thnCI,&pv.lama_sewa,&pv.tglCO,&pv.blnCO,&pv.thnCO,&pv.totalPembayaran,&pv.sisaPembayaran,&pv.status) != EOF){
				if(strcmp(pv.id_villa,id_villa)==0 || blnCI==pv.blnCI || thnCI==pv.thnCI){
					printf("   Tanggal yang telah terpesan : %d\n",pv.tglCI);     fflush(stdin);
				}
			}
			printf("\n   Selain tanggal di atas berarti villa masih tersedia!\n");
			printf("\n=================================================================\n");
		}

		fclose(cekdata);

		printf("\n   Apakah anda ingin melihat memesan villa?\n");
		printf("\n   Pilih 1 jika ingin memesan villa\n");
		printf("   Pilih 2 jika tidak ingin memesan villa\n\n");
		printf("   Masukan pilihan anda: ");
		link=validasi_dua();

		if(link==1){
			pesan_villa();

		}else{
			printf("\n-----------------------------------------------------------------\n");
			printf("|   Pilih Y jika ingin melihat data kembali                     |\n"); 
			printf("|   Pilih N jika ingin kembali ke menu pengguna                 |\n");
			printf("-----------------------------------------------------------------  \n");
			printf("    Masukan pilihan anda (Y/N): "); fflush(stdin);
			pilihan=exite_pengguna();
			system("cls");
		}
	}while(pilihan=='y' || pilihan=='Y');
}

//=======================================================================//
//*****             Fungsi Untuk Menampilkan Menu Tipe Villa        *****//
//=======================================================================//
// Nama Fungsi    : menu tipe villa                                      //
// Input Argumen  : -                                                    //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini berfungsi untuk menampilkan tipe villa    //
//                  yang tersedia di villa easy book                     //
//                                                                       //
// I Made Arya  Adi Pramana - 2205551016                                 //
// Kelas B                                                               //
//=======================================================================//
void tipe_villa(){
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||                   TIPE FASILITAS DAN KAMAR                  ||\n");
	printf("||              VILLA YANG TERSEDIA DALAM EASY BOOK            ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n");
	printf("                                                                 \n");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
    printf("|| Tipe Fasilitas Villa                                        ||\n");
    printf("|| 1. Prime : Dilengkapi dengan AC, bathtub, billyard, ruang,  ||\n");
    printf("||            tamu luas, villa 3 lantai, 3 TV, ruang mandi     ||\n");
    printf("||            air hangat, dapur yang luas, Wi-Fi, view         ||\n");
    printf("||            pinggir pantai, ruang makan, dan balkon.         ||\n");
    printf("|| 2. Style : Dilengkapi dengan AC, bathtub, ruang tamu        ||\n");
    printf("||            memadai, towel, 2 TV, villa 3 lantai, ruang      ||\n");
    printf("||            makan, kolam renang, balkon, ruang mandi air     ||\n");
    printf("||            hangat, dan 1 dapur sedang.                      ||\n");
    printf("|| 3. Trend : Dilengkapi dengan AC, kolam renang, dan dapur    ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n");
	printf("                                                                 \n");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
    printf("|| Tipe Kamar Villa                                            ||\n");
    printf("|| 1. Twin Room   : 2 kamar dengan masing-masing 1 kasur besar ||\n"); 
    printf("|| 2. Triple Room : 3 kamar dengan masing-masing 1 kasur besar ||\n");  
    printf("|| 3. Deluxe Room : 5 kamar besar dengan masing-masing 1 kasur ||\n");  
	printf("||                  besar                                      ||\n"); 
	printf("||                                                             ||\n"); 
    printf("||=============================================================||\n");
	printf("Klik apapun untuk kembali ke menu pengguna... ");
	getch();
	menu_pelanggan();
}

//=======================================================================//
//*****             Fungsi Untuk Menampilkan Menu Pesan Villa       *****//
//=======================================================================//
// Nama Fungsi    : menu pesan villa                                     //
// Input Argumen  : char, int                                            //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini berfungsi untuk menampilkan cara          //
//                  memesan villa yang tersedia di villa easy book       //
//                  nanti disini aan ditampilan pilihan villa yang       //
//                  tersedia                                             //
//                                                                       //
// I Made Arya  Adi Pramana - 2205551016                                 //
// Kelas B                                                               //
//=======================================================================//
void pesan_villa(){
	int waktu;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int id_pesanan;
	int lama_sewa;
	char pilihan;
	char ids_pesanan[10];
	char username[50];  
	char id_villa[10];
	int tglCI;             
	int blnCI;             
	int thnCI; 
 	int tglCO;             
	int blnCO;             
	int thnCO;             
	int totalPembayaran;        
	int sisaPembayaran;  
	char status[15] = "PENDING";
	do{
		system("cls");
		printf("=================================================================\n");
		printf("||                                                             ||\n");
		printf("||                          PESAN VILLA                        ||\n");
		printf("||                           EASY BOOK                         ||\n");
		printf("||                                                             ||\n");
		printf("=================================================================\n");
		printf("                                                                 \n");
		printf("   PILIHAN VILLA YANG TERSEDIA:                                  \n");
		pilihan_villa();
		printf("                                                                 \n");
		printf("-----------------------------------------------------------------\n");
		printf("   Username                      : "); fflush(stdin);
		scanf("%s", &username);
		printf("   Id Villa                      : "); fflush(stdin);
		scanf("%s", &id_villa);
		printf("   Tanggal Check In [DD/MM/YYYY] : "); fflush(stdin);
		scanf ("%d/%d/%d", &tglCI, &blnCI, &thnCI);
		printf("   Lama Sewa (Jumlah Hari)       : "); fflush(stdin);
		scanf ("%d", &lama_sewa);

		hari1=hari1+(lama_sewa%7);
		while(hari1>7)
			hari1=hari1%7;	

		tglCO = 0 ;
		blnCO = 0 ;
		thnCO = 0 ;

		do {
			if (lama_sewa <= 31)
			{
				if (blnCI == 2) 
					tglCO = Februari (thnCI);
				else 
					tglCO = BknFeb (thnCI,blnCI);
					
				if (tglCI + lama_sewa > tglCO) 
				{
					blnCO = blnCI + 1 ;
					
					if (blnCO>12){
						thnCO=thnCI+1;
						blnCO=1;
					}
					else 
					thnCO = thnCI ;
					tglCO = tglCI + lama_sewa - tglCO ;

				}
				else 
				{
					tglCO=tglCI+lama_sewa;
					blnCO=blnCI;
					thnCO=thnCI;
				}
			
			}
			else
			{
				if (blnCI == 2)
					tglCO = Februari (blnCI);
				else
					tglCO = BknFeb (thnCI,blnCI);
					lama_sewa = lama_sewa - tglCO;
				if (blnCI == 12)
				{
					blnCI = 1 ; 
					thnCI = thnCI + 1 ;
				}
				else
					blnCI = blnCI + 1 ;
			}
		}
		while (thnCO== 0);

		int user_check;
		user_check = 0;
		
		sisaPembayaran = (((dv.harga*lama_sewa)/2) + deposito);
		totalPembayaran = (((dv.harga*lama_sewa)/2) + admin);
		
		FILE *fp1;
		FILE *fp2;
		fp1=fopen("DataPesanan.txt", "r");
		fp2=fopen("DataVilla.txt", "r");
		
		if(fp1 == NULL && fp2 == NULL ){
			printf("Salah Satu File txt Tidak Tersedia\n");

		}else{
			while(fscanf(fp2, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %[^\n]\t\t\n",&dv.id_villa,&dv.nama_villa,&dv.tipe_kamar,&dv.tipe_fasilitas,&dv.harga,&dv.alamat_villa) != EOF, fscanf(fp1, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",&pv.tm_mday,&pv.tm_mon,&pv.tm_year,&pv.ids_pesanan,&pv.username,&pv.id_villa,&pv.tglCI,&pv.blnCI,&pv.thnCI,&pv.lama_sewa,&pv.tglCO,&pv.blnCO,&pv.thnCO,&pv.totalPembayaran,&pv.sisaPembayaran,&pv.status) != EOF){
				if(strcmp(pv.id_villa,id_villa)==0 && (pv.tglCI==tglCI) && (pv.blnCI==blnCI) && (pv.thnCI==thnCI)){
					user_check = user_check + 1;
					
				}else{
					user_check = user_check + 0;
				}	
			}
		fclose(fp1);
		fclose(fp2);
		}
			
		FILE *fp3;
		FILE *fp4;
		FILE *fp5;
		FILE *fp6;
		fp3 = fopen("AkunPelanggan.txt","r");
		fp4 = fopen("DataVilla.txt","r");
		fp5 = fopen("DataPesanan.txt","a");
		fp6 = fopen("DataPesanan.txt","r");
			
		if(user_check==0){

			if(fp5== NULL){
				printf("File txt Tidak Tersedia\n");
					
			}else{
				id_pesanan = id_generator();
				sprintf(ids_pesanan, "%d", id_pesanan);
				printf("   Id Pesanan                    : %s\n", ids_pesanan);
				time_t waktuserver; 
    			time( & waktuserver);
    			struct tm *waktu = localtime( & waktuserver);
				fprintf(fp5, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",waktu->tm_mday,waktu->tm_mon+1,waktu->tm_year+1900,ids_pesanan,username,id_villa,tglCI,blnCI,thnCI,lama_sewa,tglCO,blnCO,thnCO,totalPembayaran,sisaPembayaran,status);
				fclose(fp5);
				
				printf("\n=================================================================\n");
				printf("||                                                             ||\n");
				printf("||                  INPUT PESANAN VILLA BERHASIL               ||\n");
				printf("||                                                             ||\n");
				printf("=================================================================\n");
			}
		}else{
			printf("\n   Maaf, villa telah telah terpesan!");
			printf("\n   Klik apapun untuk input ulang...");
			getch();
			pesan_villa();
		}

        //=======================================================================//
		//*****             Fungsi Untuk Menampilkan Struk Pesanan Villa    *****//
		//=======================================================================//
		// Nama Fungsi    : struk pesanan villa easy book                        //
		// Input Argumen  : -                                                    //
		// Output Argumen : -                                                    //
		// Deskripsi      : Fungsi ini berfungsi untuk menampilkan struk         //
		//                  pesanan villa yang telah dipesan oleh pengguna       //
		//                                                                       //
		// I Made Arya  Adi Pramana - 2205551016                                 //
		// Kelas B                                                               //
		//=======================================================================//
		printf("Klik apapun untuk melihat struk pemesanan..."); fflush(stdin);
		getch();
		while(fscanf(fp3, "Username: %s\t\t Password: %s\t\t Email: %s\t\t Notelp: %s\t\t Nama: %[^\n]\t\t\n", u.username, u.password, u.email, u.notelp, u.nama) != EOF, fscanf(fp4, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %[^\n]\t\t\n",&dv.id_villa,&dv.nama_villa,&dv.tipe_kamar,&dv.tipe_fasilitas,&dv.harga,&dv.alamat_villa) != EOF, fscanf(fp2, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %[^\n]\t\t\n",&dv.id_villa,&dv.nama_villa,&dv.tipe_kamar,&dv.tipe_fasilitas,&dv.harga,&dv.alamat_villa) != EOF, fscanf(fp6, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %d\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",&pv.tm_mday,&pv.tm_mon,&pv.tm_year,&pv.ids_pesanan,&pv.username,&pv.id_villa,&pv.tglCI,&pv.blnCI,&pv.thnCI,&pv.lama_sewa,&pv.tglCO,&pv.blnCO,&pv.thnCO,&pv.totalPembayaran,&pv.sisaPembayaran,&pv.status) != EOF){
			if(strcmp(id_villa,dv.id_villa)==0 && strcmp(u.username,username)==0 && strcmp(pv.id_villa,dv.id_villa)==0 && strcmp(u.username,pv.username)==0){
				system("cls");
				printf("=================================================================\n");
				printf("||                                                             ||\n");
				printf("||                       STRUK PESANAN VILLA                   ||\n");
				printf("||                             EASY BOOK                       ||\n");
				printf("||                                                             ||\n");
				printf("=================================================================\n");
				printf("                                                                 \n");
    			time( & waktuserver);
    			struct tm *waktu = localtime( & waktuserver);
				printf("   Waktu Pemesanan     : %d/%d/%d\n",waktu->tm_mday,waktu->tm_mon+1,waktu->tm_year+1900);    fflush(stdin);
				printf("   Id Pesanan          : %s\n", ids_pesanan);                                                fflush(stdin);
				printf("   Nama Pemesan        : %s\n",u.nama);                                                      fflush(stdin);
				printf("   No Telepon          : %s\n",u.notelp);                                                    fflush(stdin);
				printf("   Email               : %s\n",u.email);                                                     fflush(stdin);
				printf("   Nama Villa          : %s Villa\n",dv.nama_villa);                                         fflush(stdin);
				printf("   Alamat Villa        : %s\n",dv.alamat_villa);                                             fflush(stdin);
				printf("   Tanggal Check In    : %d/%d/%d\n",tglCI,blnCI,thnCI);                                     fflush(stdin);
				printf("   Lama Sewa           : %d Hari\n",lama_sewa);                                              fflush(stdin);
				printf("   Tanggal Check Out   : %d/%d/%d\n",tglCO,blnCO,thnCO);                                     fflush(stdin);
				printf("   Harga per Malam     : Rp. %d\n",dv.harga);                                                fflush(stdin);
				printf("   Biaya Admin         : Rp. %d\n",admin);                                                   fflush(stdin);
				printf("   Biaya Deposito      : Rp. %d\n",deposito);                                                fflush(stdin);
				printf("   Total Pembayaran DP : Rp. %d\n",totalPembayaran);                                         fflush(stdin);
				printf("   Sisa Pembayaran     : Rp. %d\n",sisaPembayaran);                                          fflush(stdin);
				printf("                                                                 \n");
				printf("=================================================================\n");
				printf("                                                                 \n");
				printf("=================================================================\n");
				printf("||                                                             ||\n");
				printf("||             PEMBAYARAN DP MELALUI TRANSFER BANK             ||\n");
				printf("||      BCA: 3161523666 (a.n PT. Mudah Jaya Kemana Saja)       ||\n");
				printf("||                                                             ||\n");
				printf("||        DATA PESANAN AKAN DIHAPUS OLEH ADMIN APABILA         ||\n");
				printf("||  TIDAK MEMBAYAR SELAMA 1X24 JAM SETELAH TANGGAL PEMESANAN   ||\n");
				printf("||                                                             ||\n");
				printf("=================================================================\n");
			}
		}
		fclose(fp3);
		fclose(fp4);
		fclose(fp6);

		printf("\n-----------------------------------------------------------------\n");
		printf("|   Pilih Y jika ingin memesan villa kembali                    |\n"); 
		printf("|   Pilih N jika ingin kembali ke menu pengguna                 |\n");
		printf("-----------------------------------------------------------------  \n");
		printf("    Masukan pilihan anda (Y/N): "); fflush(stdin);
		pilihan=exite_pengguna();
		system("cls");

	}while(pilihan=='y' || pilihan=='Y');
}


int Februari (int thn){
	int thnCI; 
	thn = thnCI;
	if ((thnCI % 100 != 0) && (thnCI % 4 == 0)||(thnCI % 400 == 0)){
		return 29 ;
	}
	else {
		return 28 ; 
	}		
}

int BknFeb (int thn, int bln){
	int thnCI; 
	int blnCI; 
	thn = thnCI;
	bln = blnCI;
	if ((blnCI==1) || (blnCI==3) || (blnCI==5) || (blnCI==7) || (blnCI==8) || (blnCI==10) || (blnCI==12)){
		return 31 ;
	}
	else {
		return 30 ;
	}
}

int id_generator(){ //fungsi untuk menghasilkan bilangan random secara otomatis
	srand(time(0)); //berfungsi untuk menghasilkan bilangan random yang berbeda pada setiap id pemesanan
	int id_pesanan = rand();
}
