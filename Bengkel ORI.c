
/*######################################################################################################
/////////////////////-----------PROJEK ALGORITMA PEMOGRAMAN-------------\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Kelompok 5
Nama Anggota     : 1.Yogi Setiawan          || 5301421044
                   2.Naufal Iilham Ramadhan || 5301421045
                   3.Surya Ravsanjani       || 5301421046
Studi Kasus ke 6 : Bengkel Motor

    Skenario:
           Bengkel sepeda motor menyediakan jasa service kendaraan dan penjualan sparepart sepeda motor.
    Dalam bengkel tersebut terdapat dua jenis mekanik yang mempunyai spesialis di bidang motor matic dan
    non matic.  Untuk biaya  service  sepeda  motor  matic  lebih mahal dibanding non matic. Untuk dapat
    menggunakan   menu  service,  pengguna   harus  memasukkan  plat   nomor   kendaraan,  nama pemilik,
    tanggal service,  dan  jenis kendaraan. Outputnya   nanti pengguna dapat mengetahui biaya servis dan
    nama mekanik yang menanganinya.Untuk  pembelian sparepart  sepeda motor, pengguna juga dapat membeli
    lebih  dari  satu  item.  Harga   yang  dimunculkan   belum  termasuk  biaya  pemasangan  sparepart.
######################################################################################################*/

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

time_t ambil_waktu;

struct barang
    {
        int aki,oli,ban,kampas,lampu,rantai,busi,karbu,tali;
    };

struct barang harga;
struct barang jum;
struct barang hrgPsg;
struct barang detek;

char platNomor[20];
char nama[100];
char tanggalService[20];
char jenisKendaraan[10];

char mekanikMatic [3][7] = {{"YOGI"},{"SURYA"},{"NAUFAL"}};
char mekaniknonMatic [3][11] = {{"SETIAWAN"},{"RAVSANJANI"},{"ILHAM"}};

int hargaService;
int a,pilser,pilmech=0;
bool servis,pasang,barang;

int jasa_service();
int jasa_pasang();
int harga_total (int a, int b, int c);
int harga_sparepart();
int harga_pasang ();
int struk ();

void form ()
{
    printf("\n===================================================\n");
    printf("  SILAHKAN ISI FORMULIR || ");
    printf("Gunakan Huruf Kapital !");
    fgets(platNomor, 20, stdin);
    printf("\n===================================================");
    printf ("\n  PLAT NOMOR\t\t: ");
    fgets(platNomor, 20, stdin);
    printf ("\n  NAMA\t\t\t: ");
    fgets(nama, 100, stdin);
    printf ("\n  TANGGAL SERVICE\t: ");
    fgets(tanggalService,20,stdin);
    printf ("\n  JENIS KENDARAAN\n  (MATIC / NON-MATIC)\t: ");
    fgets(jenisKendaraan, 10, stdin);
    system("cls");
}

void tampilan (int ser, int mek)
{
    char service [3][8] = {{" "},{"RINGAN"},{"LENGKAP"}};

    system("cls");
    printf ("\n Kendaraan berikut\n");
    printf ("  PLAT NOMOR\t\t: %s",platNomor);
    printf ("  NAMA\t\t\t: %s",nama);
    printf ("  TANGGAL SERVICE\t: %s",tanggalService);
    printf ("  JENIS KENDARAAN\t: %s",jenisKendaraan);
    printf ("  JENIS SERVICE\t\t: %s\n",service[ser]);
    if(jenisKendaraan[0]=='M'){printf ("  MEKANIK\t\t: %s\n\n",mekanikMatic[mek]);}
    if(jenisKendaraan[0]=='N'){printf ("  MEKANIK\t\t: %s\n\n",mekaniknonMatic[mek]);}
    printf ("  LANJUTKAN? (Y) : ");
}

void menu_sparepart ()
{
    char yt;
    int listBarang;
    barang=true;

    harga.aki=harga.ban=harga.busi=harga.kampas=harga.karbu=harga.lampu=harga.oli=harga.rantai=harga.tali=0;
    jum.aki=jum.ban=jum.busi=jum.kampas=jum.karbu=jum.lampu=jum.oli=jum.rantai=jum.tali=0;

    printf("\n\t    Selamat datang di bengkel pte.\n");
    printf("\tSilakan pilih sparepart yang Anda butuhkan :\n\n");
    printf(" ===================================================\n");
    printf (" |No.|     Spare Part    |   Harga    |\t\n");
    printf(" |--------------------------------------------------\n");
    printf(" | 1 | Aki Motor\t | Rp 200.000 |\t\n");
    printf(" | 2 | Oli\t\t | Rp 100.000 |\t\n");
    printf(" | 3 | Ban\t\t | Rp 150.000 |\t\n");
    printf(" | 4 | Kampas Rem\t | Rp  20.000 |\t\n");
    printf(" | 5 | Lampu\t\t | Rp  20.000 |\t\n");
    printf(" | 6 | Rantai/Belt\t | Rp 100.000 |\t\n");
    printf(" | 7 | Busi\t\t | Rp  30.000 |\t\n");
    printf(" | 8 | Karburator\t | Rp 200.000 |\t\n");
    printf(" | 9 | Tali Gas\t\t | Rp  10.000 |\t");
    printf("\n ==================================================\n");
    printf("\n ");
    printf("\n 99. Lanjutkan\n 55. Reset pilihan\n 00.  Kembali\n");
    printf("====================================================\n");

    for (listBarang!=0;listBarang!=99;){
            printf("Input Pilihan Barang : ");
            scanf("%d",&listBarang);



            switch(listBarang)
            {
                case 1:
                    printf("\nPembelian Aki Motor\n");
                    printf("jumlah pesan =  ");scanf("%d",&jum.aki);
                    printf("\n===============================================\n");
                    harga.aki=jum.aki*200000;
                break;

                case 2:
                    printf("\nPembelian Oli\n");
                    printf("jumlah pesan =  ");scanf("%d",&jum.oli);
                    printf("\n===============================================\n");
                    harga.oli=jum.oli*100000;
                break;

                case 3:
                    printf("\nPembelian Ban\n");
                    printf("jumlah pesan =  ");scanf("%d",&jum.ban);
                    printf("\n===============================================\n");
                    harga.ban=jum.ban*150000;
                break;

                 case 4:
                    printf("\nPembelian Kampas Rem\n");
                    printf("jumlah pesan =  ");scanf("%d",&jum.kampas);
                    printf("\n===============================================\n");
                    harga.kampas=jum.kampas*20000;
                break;

                 case 5:
                    printf("\nPembelian Lampu\n");
                    printf("jumlah pesan =  ");scanf("%d",&jum.lampu);
                    printf("\n===============================================\n");
                    harga.lampu=jum.lampu*20000;
                break;

                 case 6:
                    printf("\nPembelian Rantai/Belt\n");
                    printf("jumlah pesan =  ");scanf("%d",&jum.rantai);
                    printf("\n===============================================\n");
                    harga.rantai=jum.rantai*100000;
                break;

                 case 7:
                    printf("\nPembelian Busi\n");
                    printf("jumlah pesan =  ");scanf("%d",&jum.busi);
                    printf("\n===============================================\n");
                    harga.busi=jum.busi*30000;
                break;

                 case 8:
                    printf("\nPembelian Karburator\n");
                    printf("jumlah pesan =  ");scanf("%d",&jum.karbu);
                    printf("\n===============================================\n");
                    harga.karbu=jum.karbu*200000;
                break;

                 case 9:
                    printf("\nPembelian Tali Gas\n");
                    printf("jumlah pesan =  ");scanf("%d",&jum.tali);
                    printf("\n===============================================\n");
                    harga.tali=jum.tali*10000;
                break;

                case 99:
                     goto lanjutkan;
                break;

                case 55:
                    system("cls");
                    menu_sparepart();
                break;

                case 00:
                    system("cls");
                    main();
                break;

                default: ///
                    printf("Kesalahan inputan, menu no.%d tidak ada dalam daftar\n",listBarang);
                    printf("- Silakan input kembali\n");
                break;
        }
    }

    lanjutkan:

            printf("Apakah Anda Ingin Spare Part yang Anda Beli Dipasang?\n");
            printf("(Y/T)");
            scanf("%s",&yt);
            if(yt=='Y' || yt=='y'){jasa_pasang();}
            else if(yt=='T' || yt=='t'){}
}

void per_Sparepart (int aki, int oli, int ban, int kampas, int lampu, int rantai, int busi, int karbu, int tali)
{
    puts("\nPEMBELIAN PART");
    if(aki!=0){printf("Beli Aki Motor = %d pcs_______________________________________Rp %d\n",aki,harga.aki);}
    if(oli!=0){printf("Beli Oli = %d pcs_____________________________________________Rp %d\n",oli,harga.oli);}
    if(ban!=0){printf("Beli Ban = %d pcs_____________________________________________Rp %d\n",ban,harga.ban);}
    if(kampas!=0){printf("Beli Kampas Motor = %d pcs____________________________________Rp %d\n",kampas,harga.kampas);}
    if(lampu!=0){printf("Beli Lampu = %d pcs___________________________________________Rp %d\n",lampu,harga.lampu);}
    if(rantai!=0){printf("Beli Rantai/Vbelt = %d pcs____________________________________Rp %d\n",rantai,harga.rantai);}
    if(busi!=0){printf("Beli Busi = %d pcs____________________________________________Rp %d\n",busi,harga.busi);}
    if(karbu!=0){printf("Beli Karbu = %d pcs___________________________________________Rp %d\n",karbu,harga.karbu);}
    if(tali!=0){printf("Beli Tali Gas = %d pcs________________________________________Rp %d\n",tali,harga.tali);}
}

void per_Pasang (int aki, int oli, int ban, int kampas, int lampu, int rantai, int busi, int karbu, int tali)
{
    puts("PEMASANGAN SPAREPART");
    if(aki!=0 && detek.aki==1){printf("Pasang Aki Motor =___________________________________________Rp %d\n",hrgPsg.aki);}
    if(oli!=0 && detek.oli==1){printf("Pasang Oli =_________________________________________________Rp %d\n",hrgPsg.oli);}
    if(ban!=0 && detek.ban==1){printf("Pasang Ban =_________________________________________________Rp %d\n",hrgPsg.ban);}
    if(kampas!=0 && detek.kampas==1){printf("Pasang Kampas Motor =________________________________________Rp %d\n",hrgPsg.kampas);}
    if(lampu!=0 && detek.lampu==1){printf("Pasang Lampu =_______________________________________________Rp %d\n",hrgPsg.lampu);}
    if(rantai!=0 && detek.rantai==1){printf("Pasang Rantai/Vbelt =________________________________________Rp %d\n",hrgPsg.rantai);}
    if(busi!=0 && detek.busi==1){printf("Pasang Busi =________________________________________________Rp %d\n",hrgPsg.busi);}
    if(karbu!=0 && detek.karbu==1){printf("Pasang Karbu =_______________________________________________Rp %d\n",hrgPsg.karbu);}
    if(tali!=0 && detek.tali==1){printf("Pasang Tali Gas =____________________________________________Rp %d\n",hrgPsg.tali);}
}
void menu_pasang(int aki, int oli, int ban, int kampas, int lampu, int rantai, int busi, int karbu, int tali)
{
    //system("cls");
    puts("berikut daftar sparepart yang anda beli");
    if(aki!=0){printf("Aki\n");}
    if(oli!=0){printf("Oli\n");}
    if(ban!=0){printf("Ban\n");}
    if(kampas!=0){printf("Kampas\n");}
    if(lampu!=0){printf("Lampu\n");}
    if(rantai!=0){printf("Rantai/Vbelt\n");}
    if(busi!=0){printf("Busi\n");}
    if(karbu!=0){printf("Karbu\n");}
    if(tali!=0){printf("Tali Gas\n");}

}

void struk_servis (int mekanik, int servis)
{
    char service [3][8] = {{" "},{"RINGAN"},{"LENGKAP"}};

    puts("JASA SERVICE");
    printf(" JENIS KENDARAAN : %s\n",jenisKendaraan);
    if(jenisKendaraan[0]=='M'){printf (" NAMA MEKANIK\t : %s\n\n",mekanikMatic[mekanik]);}
    if(jenisKendaraan[0]=='N'){printf (" NAMA MEKANIK\t : %s\n\n",mekaniknonMatic[mekanik]);}
    printf("------------------------------------------------------------------------\n");
    printf(" Jenis Service\t : %s\n",service[servis]);
    //printf("Harga\t: %d\n",hargaService);

}

void struk_sparepart ()
{
    per_Sparepart (jum.aki,jum.oli,jum.ban,jum.kampas,jum.lampu,jum.rantai,jum.busi,jum.karbu,jum.tali);
    printf("                                                Harga Part : Rp %d",harga_sparepart());
}

void struk_jasa_pasang(int mekanik)
{
    //mekanik++;
    printf("JENIS KENDARAAN : %s\n",jenisKendaraan);
    if(jenisKendaraan[0]=='M'){printf ("NAMA MEKANIK\t: %s\n\n",mekanikMatic[mekanik]);}
    if(jenisKendaraan[0]=='N'){printf ("NAMA MEKANIK\t: %s\n\n",mekaniknonMatic[mekanik]);}
    printf("------------------------------------------------------------------------\n");
    per_Pasang(jum.aki,jum.oli,jum.ban,jum.kampas,jum.lampu,jum.rantai,jum.busi,jum.karbu,jum.tali);
    printf("                                              Harga pasang : Rp %d",harga_pasang());
}

int main ()
{
    while(1){
    int pilMenu;
    int ulang=1;

    servis=false;
    barang=false;
    pasang=false;

    hargaService=0;
    harga.aki=harga.ban=harga.busi=harga.kampas=harga.karbu=harga.lampu=harga.oli=harga.rantai=harga.tali=0;
    hrgPsg.aki=hrgPsg.ban=hrgPsg.busi=hrgPsg.kampas=hrgPsg.karbu=hrgPsg.lampu=hrgPsg.oli=hrgPsg.rantai=hrgPsg.tali=0;

    while(ulang==1)
        {
            printf("===================================================\n");
            printf("\tSELAMAT DATANG DI BENGKEL PTE\n");
            printf("===================================================\n");
            printf("\n  Silahkan Pilih Menu Pelayanan Kami\n\n");
            printf("   1. JASA SERVICE\n   2. SPARE PART\n\n  69. KELUAR\n\n");
            printf("  Masukan Pilihan Anda : ");
            scanf("%d",&pilMenu);

            switch (pilMenu)
            {
                case 1 :
                    ulang=0;jasa_service();
                break;

                case 2 :
                    ulang=0;menu_sparepart();
                break;

                case 69 :
                    system("cls");
                    puts("\n====\tTERIMA KASIH TELAH MENGGUNAKAN PELAYANAN KAMI\t====");ulang=0;
                    sleep(2);
                    system("cls");
                    return 0;
                break;

                default :ulang=1;
                         printf("\n\tPERINTAH YANG ANDA MASUKAN SALAH!!\n\n");
        }
    }
    struk();
    }
}

int jasa_service ()
{
    char lanjut;
    int pilihan;
    servis=true;

    form();
    //if(jenisKendaraan[0]!='M' || jenisKendaraan[0]!='N'){puts("bjir");}
    if(jenisKendaraan[0]=='M'){goto Matic;}
    if(jenisKendaraan[0]=='N'){goto nonMatic;}

    Matic :
        printf("\n\t        Selamat datang di bengkel pte.\n");
        printf("\t   Silakan pilih pelayanan yang Anda butuhkan :\n\n");
        printf("\t=================================================\n");
        printf("\t|No.|        Jasa       |   Harga motor matic   | \t\n");
        printf("\t|-----------------------------------------------|\n");
        printf("\t| 1 | Service Ringan\t|\tRp 35.000\t| \n");
        printf("\t| 2 | Service Lengkap\t|\tRp 50.000\t| \n");
        printf("\t=================================================\n");
        printf("\n\tSilahkan Pilih Menu Service : ");
        scanf("%d",&pilihan);
        if(pilihan==1){hargaService=35000; pilser=1; pilmech++;}
        if(pilihan==2){hargaService=50000; pilser=2; pilmech++;}
        goto loop;

    nonMatic:
        printf("\n\t        Selamat datang di bengkel pte.\n");
        printf("\t   Silakan pilih pelayanan yang Anda butuhkan :\n\n");
        printf("\t=================================================\n");
        printf ("\t|No.|        Jasa       | Harga motor non matic | \t\n");
        printf("\t|-----------------------------------------------|\n");
        printf("\t| 1 | Service ringan\t|\tRp 25.000\t| \n");
        printf("\t| 2 | Service lengkap\t|\tRp 40.000\t| \n");
        printf("\t=================================================\n");
        printf("\n\tSilahkan Pilih Menu Service : ");
        scanf("%d",&pilihan);
        if(pilihan==1){hargaService=25000;pilser=1;pilmech++;}
        if (pilihan==2){hargaService=40000;pilser=2;pilmech++;}
        goto loop;

    loop:
        tampilan(pilser,pilmech);
        scanf("%s",&lanjut);
        if(lanjut=='Y'){/*struk servis*/}
        else{ printf("Input Invalid!");sleep(2);goto loop;}
}

int jasa_pasang()
{
    system("cls");
    char barang[20];
    pasang=true;
    hrgPsg.aki=hrgPsg.ban=hrgPsg.busi=hrgPsg.kampas=hrgPsg.karbu=hrgPsg.lampu=hrgPsg.oli=hrgPsg.rantai=hrgPsg.tali=0;
    detek.aki=detek.ban=detek.busi=detek.kampas=detek.karbu=detek.lampu=detek.oli=detek.rantai=detek.tali=0;
    menu_pasang(jum.aki,jum.oli,jum.ban,jum.kampas,jum.lampu,jum.rantai,jum.busi,jum.karbu,jum.tali);
    form();
   if(jenisKendaraan[0]=='M'){ goto pasangMatic;}
   if(jenisKendaraan[0]=='N'){goto pasangNon;}


   pasangMatic:
        //printf(" ");
        //gets(barang);
        printf("masukan nama barang yang ingin dipasang : ");
        gets(barang);
        if (barang[0]=='A' && barang[1]=='k'){detek.aki=1;hrgPsg.aki=10000;}
        if (barang[0]=='O' && barang[1]=='l'){detek.oli=1;hrgPsg.oli=10000;}
        if (barang[0]=='B' && barang[2]=='n'){detek.ban=1;hrgPsg.ban=15000;}
        if (barang[0]=='K' && barang[2]=='m'){detek.kampas=1;hrgPsg.kampas=15000;}
        if (barang[0]=='L' && barang[3]=='p'){detek.lampu=1;hrgPsg.lampu=15000;}
        if (barang[0]=='R' && barang[3]=='t'){detek.rantai=1;hrgPsg.rantai=20000;}
        if (barang[0]=='B' && barang[1]=='u'){detek.busi=1;hrgPsg.busi=20000;}
        if (barang[0]=='K' && barang[2]=='r'){detek.karbu=1;hrgPsg.karbu=20000;}
        if (barang[0]=='T' && barang[2]=='l'){detek.tali=1;hrgPsg.tali=10000;}
        if (barang[0]=='s'){return 0;}
        goto pasangMatic;


    pasangNon:
        //printf(" ");
        //gets(barang);
        printf("masukan nama barang yang ingin dipasang : ");
        gets(barang);
        if (barang[0]=='A' && barang[1]=='k'){detek.aki=1;hrgPsg.aki=15000;}
        if (barang[0]=='O' && barang[1]=='l'){detek.oli=1;hrgPsg.oli=8000;}
        if (barang[0]=='B' && barang[2]=='n'){detek.ban=1;hrgPsg.ban=13000;}
        if (barang[0]=='K' && barang[2]=='m'){detek.kampas=1;hrgPsg.kampas=13000;}
        if (barang[0]=='L' && barang[3]=='p'){detek.lampu=1;hrgPsg.lampu=13000;}
        if (barang[0]=='R' && barang[3]=='t'){detek.rantai=1;hrgPsg.rantai=15000;}
        if (barang[0]=='B' && barang[1]=='u'){detek.busi=1;hrgPsg.busi=10000;}
        if (barang[0]=='K' && barang[2]=='r'){detek.karbu=1;hrgPsg.karbu=15000;}
        if (barang[0]=='T' && barang[2]=='l'){detek.tali=1;hrgPsg.tali=8000;}
        if (barang[0]=='s'){return 0;}
        goto pasangNon;

}

int harga_pasang ()
{
    int hargaJasa=hrgPsg.aki + hrgPsg.oli + hrgPsg.ban + hrgPsg.kampas + hrgPsg.lampu + hrgPsg.rantai + hrgPsg.busi + hrgPsg.karbu + hrgPsg.tali;

    return hargaJasa;
}

int harga_sparepart()
{
    int rego;

    rego=harga.aki + harga.ban + harga.busi + harga.kampas + harga.karbu + harga.lampu + harga.oli + harga.rantai + harga.tali;

    return rego;
}

int harga_total (int a, int b, int c)
{
    int total;
    if (a+b+c == 0){total = 0;}
    else {total=a+b+c;}

    return total;
}

int struk ()
{
    time(&ambil_waktu);
    system("cls");
    printf("========================================================================\n");
    printf("\n\t\t\t    BENGKEL PTE\t\n");
    printf("\tJln Taman Siswa No 01, Sekaran, Gunung Pati, Kota Semarang\n");
    printf("\t\t      %s", ctime (&ambil_waktu));
    printf("========================================================================\n");
    if(servis==true){struk_servis(pilmech,pilser);}
    if(pasang==true){struk_jasa_pasang(pilmech);}
    if(barang==true){struk_sparepart();}
    printf("\n                                               total harga : Rp %d\n",harga_total(hargaService,harga_pasang(),harga_sparepart()));
    sleep(2);
    puts("\ntekan enter untuk mengakhiri");
    system("pause");
    system("cls");
    puts("\n====\tTERIMA KASIH TELAH MENGGUNAKAN PELAYANAN KAMI\t====\n\n\t\t Have a good day :D");
    sleep(2);
    system("cls");

}
