#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
 
typedef struct{
    char nama[50];      
    char username[50];  
    char password[50];
    char email[50];
	char notelp[50];
}User;
User u;

typedef struct{
    char id_villa[10];      
    char nama_villa[255];
	char alamat_villa[255]; 
	char tipe_kamar[255]; 
    char tipe_fasilitas[255];
    int harga;    
}datavilla;
datavilla dv;

typedef struct{
	int	tm_mday;
	int tm_mon;
	int	tm_year;
	char ids_pesanan[10];
	char username[50]; 
	char id_villa[10];       
	char nama[50];  
	char notelp[50];         
	char email[50];                     
	int tglCI;             
	int blnCI;             
	int thnCI;                         
  	int tglCO;             
	int blnCO;             
	int thnCO;
	int lama_sewa;             
	int totalPembayaran ;        
	int sisaPembayaran ;  
	char status[15];
}pesanvilla;
pesanvilla pv; 

int hari1 ;
int hari2 = 1; 
int admin = 10000;
int deposito = 500000;
time_t waktuserver; 

void menu_utama();
void menu_registrasi();
void pilihan_login();
void login_admin();
void login_pengguna();
void menu_admin();
void menu_pelanggan(); 
void input_villa();
void hapus_villa();
void pesanan_villa();
void edit_pesanan();
void hapus_pesanan();
void update_status();
void tentang_kami();
void aturan_pemesanan();
void pilihan_villa();
void menu_pilihan_villa();
void tipe_villa();
void pesan_villa();
int Februari (int thn);
int BknFeb (int thn, int bln);
int id_generator();

int validasi_input(){
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

int validasi_lima(){
    int bilangan;
    bilangan=validasi_input();
    
    if(bilangan >=1 && bilangan <=5){
        return bilangan;
        
    }else{
        printf("Masukan pilihan yang sesuai (1/2/3/4/5): ");
    	return validasi_lima();
	}
}

int validasi_enam(){
    int bilangan;
    bilangan=validasi_input();
    
    if(bilangan >=1 && bilangan <=6){
        return bilangan;
        
    }else{
        printf("Masukan pilihan yang sesuai (1/2/3/4/5): ");
    	return validasi_enam();
	}
}

int validasi_tiga(){
    int bilangan;
    bilangan=validasi_input();
    
    if(bilangan >=1 && bilangan <=3){
        return bilangan;
        
    }else{
        printf("Masukan pilihan yang sesuai (1/2/3): ");
    	return validasi_tiga();
	}
}

int validasi_dua(){
    int bilangan;
    bilangan=validasi_input();
    
    if(bilangan >=1 && bilangan <=2){
        return bilangan;
        
    }else{
        printf("Masukan pilihan yang sesuai (1/2): ");
    	return validasi_dua();
	}
}

char exite_admin (){
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

char exite_pengguna (){
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

int main(){
	menu_utama();
}

void menu_utama(){
	int link;
	system("cls");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||                           EASY BOOK                         ||\n");
	printf("||       THE RIGHT SOLUTION FOR YOUR SHORT TRIP IN BALI        ||\n");
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
    char username[50];
    char password[50];
    char nama[50];
    char email[50];
	char notelp[50];

	system("cls");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||                  MENU REGISTRASI PENGGUNA BARU              ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n\n");
    printf("   Nama Lengkap     : "); fflush(stdin);
    scanf("%[^\n]", &nama);
    printf("   No Telepon       : "); fflush(stdin);
    scanf("%s", &notelp);
    printf("   Email            : "); fflush(stdin);
    scanf("%s", &email);
	printf("\n-----------------------------------------------------------------\n");
    printf("           !! Silahkan membuat username dan password !!            \n");
	printf("-----------------------------------------------------------------\n\n");
    printf("   Enter Username   : "); fflush(stdin);
    scanf ("%s", &username);
    printf("   Enter Password   : "); fflush(stdin);
    scanf ("%s", &password);
    
    int user_check;
    user_check = 0;
    
    FILE *AP;
    AP=fopen("AkunPelanggan.txt", "r");
    
	if(AP == NULL){
    	printf("File txt Tidak Tersedia\n");

	}else{
    	while(fscanf(AP, "Username: %s\t\t Password: %s\t\t Email: %s\t\t Notelp: %s\t\t Nama: %[^\n]\t\t\n", u.username, u.password, u.email, u.notelp, u.nama) != EOF){
    		if(strcmp(u.username,username)==0){
        	user_check = user_check + 1;
        	
			}else{
			user_check = user_check + 0;
        	}	
		}
    fclose(AP);
	}
	
	FILE *registrasi;
	registrasi = fopen("AkunPelanggan.txt","a");
	
	if(user_check==0){
		if(registrasi == NULL){
    		printf("File txt Tidak Tersedia\n");
    		
		}else{
	        fprintf(registrasi,"Username: %s\t\t Password: %s\t\t Email: %s\t\t Notelp: %s\t\t Nama: %s\t\t\n",username,password,email,notelp,nama);
		    fclose(registrasi);
		    
			printf("\n=================================================================\n");
			printf("||                                                             ||\n");
			printf("||                      REGISTRASI BERHASIL                    ||\n");
			printf("||         SELAMAT MENIKMATI LAYANAN DARI PROGRAM INI          ||\n");
			printf("||                                                             ||\n");
			printf("=================================================================\n");
			printf("Tekan apapun untuk melanjutkan. . .");
		    getch();
		    menu_pelanggan();
		}
    }else{
       	printf("\n   Maaf, username telah digunakan!");
       	printf("\n   Klik apapun untuk input ulang...");
        getch();
        menu_registrasi();
    }
}

void pilihan_login(){
	int link;
	system("cls");
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
		login_admin();
		
	}else if(link==2){
		login_pengguna();
		
	}else{
		menu_utama();
	}
}

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

void login_pengguna(){
    char username[50];
    char password[50];
    int link;

    FILE *AP;
    AP=fopen("AkunPelanggan.txt", "r");

	if(AP==NULL){
        printf("File txt Tidak Tersedia\n");
    }

	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||                       MENU LOGIN EASY BOOK                  ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n\n");
    printf ("   Username: "); 
    scanf  ("%s", username); 
    printf ("   Password: "); 
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
            menu_registrasi();

        }else if (link==2) {
            login_pengguna();
                
        }else if (link==3){
            pilihan_login();

        }else{
            printf("Masukan pilihan yang sesuai (1/2/3):\n");
            login_pengguna();
        }

	}else{
		menu_pelanggan();
		
	}
    fclose(AP);
}

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
        input_villa();

    }else if (link==2) {
        hapus_villa();
                
    }else if (link==3){
        pesanan_villa();
    
    }else if (link==4){
        edit_pesanan();
        
    }else if (link==5){
        menu_utama();

    }else{
        printf("Masukan pilihan yang sesuai (1/2/3/4/5):\n");
        menu_admin();
    }
		
}

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
        tentang_kami();

    }else if (link==2) {
        aturan_pemesanan();
                
    }else if (link==3){
        menu_pilihan_villa();
    
    }else if (link==4){
        tipe_villa();
        
    }else if (link==5){
        pesan_villa();

    }else if (link==6){
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

		int user_check;
		user_check = 0;
		
		FILE *DV;
		DV=fopen("DataVilla.txt", "r");
		
		if(DV == NULL){
			printf("File txt Tidak Tersedia\n");

		}else{
			while(fscanf(DV, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %[^\n]\t\t\n",&dv.id_villa,&dv.nama_villa,&dv.tipe_kamar,&dv.tipe_fasilitas,&dv.harga,&dv.alamat_villa) != EOF){
				if(strcmp(dv.id_villa,id_villa)==0){
					user_check = user_check + 1;
				
				}else{
					user_check = user_check + 0;
				}	
			}
		fclose(DV);
		}
		
		FILE *IV;
		IV = fopen("DataVilla.txt","a");
		
		if(user_check==0){
			if(IV == NULL){
				printf("File txt Tidak Tersedia\n");
				
			}else{
				fprintf(IV, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %s\t\t\n",id_villa,nama_villa,tipe_kamar,tipe_fasilitas,harga,alamat_villa);
				fclose(IV);
				
				printf("\n=================================================================\n");
				printf("||                                                             ||\n");
				printf("||                    INPUT DATA VILLA BERHASIL                ||\n");
				printf("||                                                             ||\n");
				printf("=================================================================\n");
			}
		}else{
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
		printf("   Pilih ID villa yang akan dihapus: "); fflush(stdin);
		scanf("%s",&id_hapus);

		FILE *fp1, *fp2;


		fp1 = fopen("DataVilla.txt", "r");
		fp2 = fopen("Temp_Data.txt", "a");
			

		if(fp1==NULL){
			fprintf(stderr,"Tidak dapat membuka file...");
			exit(0);
		}

		while(fscanf(fp1, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %[^\n]\t\t\n",&dv.id_villa,&dv.nama_villa,&dv.tipe_kamar,&dv.tipe_fasilitas,&dv.harga,&dv.alamat_villa) != EOF){
			if(strcmp(dv.id_villa,id_hapus)!=0){
				fprintf(fp2, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %s\t\t\n",dv.id_villa,dv.nama_villa,dv.tipe_kamar,dv.tipe_fasilitas,dv.harga,dv.alamat_villa); 
			}
		}

		fclose(fp1);
		fclose(fp2);

		remove("DataVilla.txt"); 
		rename("Temp_Data.txt", "DataVilla.txt");
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


void pesanan_villa(){
	char pilihan;
	char id_pesanan[10];
	int cek;
    FILE *cekdata;
	do{
		system("cls");
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
	printf("|| 3. KEmbali ke Menu Admin                                    ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n");
	printf("Masukan pilihan anda (1/2/3): ");
	link = validasi_tiga();
	system("cls");
	if(link==1){
		hapus_pesanan();
		
	}else if(link==2){
		update_status();
		
	}else{
		menu_admin();
	}


}

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
			while(fscanf(cekdata, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",&pv.tm_mday,&pv.tm_mon,&pv.tm_year,&pv.ids_pesanan,&pv.username,&pv.id_villa,&pv.tglCI,&pv.blnCI,&pv.thnCI,pv.lama_sewa,&pv.tglCO,&pv.blnCO,&pv.thnCO,&pv.totalPembayaran,&pv.sisaPembayaran,&pv.status) != EOF){
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
	printf("||   5. Lama waktu menginap semua villa sama yakni 2 hari 1     ||\n");
	printf("||      malam, bila ingin menambah hari maka harus memesan lagi ||\n");
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

void menu_pilihan_villa(){
	char pilihan;
	char id_villa[10];
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
		printf("\n-----------------------------------------------------------------\n");
		printf("|   Pilih Y jika ingin melihat data kembali                     |\n"); 
		printf("|   Pilih N jika ingin kembali ke menu admin                    |\n");
		printf("-----------------------------------------------------------------  \n");
		printf("    Masukan pilihan anda (Y/N): "); fflush(stdin);
		pilihan=exite_pengguna();
		system("cls");
	}while(pilihan=='y' || pilihan=='Y');

}

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
		
		sisaPembayaran = ((dv.harga/2) + deposito);
		totalPembayaran = ((dv.harga/2) + admin);
		
		FILE *fp1;
		FILE *fp2;
		fp1=fopen("DataPesanan.txt", "r");
		fp2=fopen("DataVilla.txt", "r");
		
		if(fp1 == NULL && fp2 == NULL ){
			printf("Salah Satu File txt Tidak Tersedia\n");

		}else{
			while(fscanf(fp2, "Id Villa: %s\t\t Nama Villa: %s\t\t Tipe Kamar: %s\t\t Tipe Fasilitas: %s\t\t Harga Sewa: %d\t\t Alamat Villa: %[^\n]\t\t\n",&dv.id_villa,&dv.nama_villa,&dv.tipe_kamar,&dv.tipe_fasilitas,&dv.harga,&dv.alamat_villa) != EOF, fscanf(fp1, "Waktu Pemesanan: %d/%d/%d\t\t Id Pesanan: %s\t\t Username: %s\t\t Id Villa: %s\t\t Tanggal Check-In: %d/%d/%d\t\t Lama Sewa: %d\t\t Tanggal Check-Out: %d/%d/%d\t\t Total Bayar: %d\t\t Sisa Bayar: %d\t\t Status: %s\t\t\n",&pv.tm_mday,&pv.tm_mon,&pv.tm_year,&pv.ids_pesanan,&pv.username,&pv.id_villa,&pv.tglCI,&pv.blnCI,&pv.thnCI,pv.lama_sewa,&pv.tglCO,&pv.blnCO,&pv.thnCO,&pv.totalPembayaran,&pv.sisaPembayaran,&pv.status) != EOF){
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

int id_generator(){
	srand(time(0));
	int id_pesanan = rand();
}
