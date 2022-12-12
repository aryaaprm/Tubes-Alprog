#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
 
typedef struct {
    char nama[50];      
    char username[50];  
    char password[50];
    char email[50];    
}User;
User u;

void menu_utama();
void menu_registrasi();
void pilihan_login();
void login_admin();
void login_pengguna();
void menu_admin();
void menu_pelanggan(); 

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

int main(){
	menu_utama();
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
	printf("|| 1.	REGISTRASI                                             ||\n");
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

	system("cls");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
	printf("||                  MENU REGISTRASI PENGGUNA BARU              ||\n");
	printf("||                                                             ||\n");
	printf("=================================================================\n\n");
    printf("   Nama Lengkap     : ");
    scanf("%s", &nama);
    printf("   Email            : ");
    scanf("%s", &email);
	printf("_________________________________________________________________  \n");
    printf("\n           !! Silahkan membuat username dan password !!          \n");
	printf("_________________________________________________________________\n\n");
    printf("   Enter Username   : ");
    scanf ("%s", &username);
    printf("   Enter Password   : ");
    scanf ("%s", &password);
    
    int user_check;
    user_check = 0;
    
    FILE *AP;
    AP=fopen("AkunPelanggan.txt", "r");
    
	if(AP == NULL){
    	printf("File txt Tidak Tersedia\n");

	}else{
    	while(fscanf(AP, "Username: %s\t\t Password: %s\t\t Nama: %s\t\t Email: %s\t\t\n", u.username, &u.password, &u.nama, &u.email) != EOF){
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
    		printf("\t\t\tFile txt Tidak Tersedia\n");
    		
		}else{
	        fprintf(registrasi,"Username: %s\t\t Password: %s\t\t Nama: %s\t\t Email: %s\t\t\n",username,password,nama,email);
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
	//fclose(AA); 
	
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
        printf("\t\t\tFile txt Tidak Tersedia\n");
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

    while(fscanf(AP, "Username: %s\t\t Password: %s\t\t Nama: %s\t\t Email: %s\t\t\n", u.username, &u.password, &u.nama, &u.email) != EOF){
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
    printf("||   4. HAPUS PESANAN VILLA                                    ||\n"); 
    printf("||   5. KEMBALI KE MENU UTAMA                                  ||\n");
	printf("||                                                             ||\n");
    printf("=================================================================\n");
    printf("Silakan Masukan Pilihan Anda (1/2/3/4/5): ");	
}

void menu_pelanggan(){
	system("cls");
	printf("=================================================================\n");
	printf("||                                                             ||\n");
    printf("||                          MENU PENGGUNA                      ||\n");
    printf("||                            EASY BOOK                        ||\n");
    printf("||                                                             ||\n");
    printf("=================================================================\n");
    printf("                                                                 \n");
    printf("=================================================================\n");
	printf("||                                                             ||\n");
    printf("||   1. TENTANG KAMI                                           ||\n");
    printf("||   2. ATURAN PEMESANAN VILLA                                 ||\n");
    printf("||   3. PILIHAN VILLA                                          ||\n");
    printf("||   4. PESAN VILLA                                            ||\n"); 
    printf("||   5. KEMBALI KE MENU UTAMA                                  ||\n");
	printf("||                                                             ||\n");
    printf("=================================================================\n");
    printf("Silakan Masukan Pilihan Anda (1/2/3/4/5): ");
}
