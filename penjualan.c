#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int a = 0, c, harga['0'], jumlahBarang['0'], total['0'], pemasukan, pengeluaran, kode['0'], e = 10100, b, d;
char namaBarang['0'][100];
struct tm *ptr;
time_t t;

FILE *nota;

void inputPenjualan();
void viewJual();
void cariJual();
void cari();
void updateJual();
void hasilJual();
void hapusJual();
int menu();

void inputPenjualan()
{
    b = 1;
    d = 0;

    while (b == 1)
    {
        a++;
        e++;
        kode[a] = e;
        printf("Barang Ke-%d\n", a);
        printf("kode Barang : %d\n", kode[a]);
        printf("Masukana nama barang : ");
        scanf("%s", namaBarang[a]);
        printf("Jumlah Barang: ");
        scanf("%d", &jumlahBarang[a]);
        printf("Harga Barang : Rp.");
        scanf("%d", &harga[a]);
        total[a] = jumlahBarang[a] * harga[a];
        printf("Total harga: Rp.%d\n", total[a]);
        t = time(NULL);
        ptr = localtime(&t);
        fprintf(nota, "\nWaktu: %s%d.Kode Barang : %d\nnama barang: %s\njumhlah barang: %d\nHarga Barang: Rp.%d\nTotal Harga: Rp.%d\n", asctime(ptr), a, kode[a], namaBarang[a], jumlahBarang[a], harga[a], total[a]);
        d = d + total[a];
        printf("Jumllah yang harus di bayar : %d", d);
        printf("\napakah masih ada barang (tekan 1) : ");
        scanf("%d", &b);
        if (b == 0)
        {
            menu();
        }
    }
}
void viewJual()
{
    int pilihan;
    pemasukan = 0;
    puts("");
    if (a < 1)
    {
        printf("Data Masih Kosong");
    }
    else
    {
        b = 1;
        while (b <= a)
        {
            printf("\n%d.Kode barang :%d\n", b, kode[b]);
            printf("Nama barang: %s\n", namaBarang[b]);
            printf("Jumlah barang : %d\n", jumlahBarang[b]);
            printf("Harga barang : %d\n", harga[b]);
            printf("Total Harga : %d\n", total[b]);
            pemasukan = pemasukan + total[b];
            b++;
        }
        printf("Total pemasukan : %d", pemasukan);
    }
    puts("");
    printf("Kembali ke menu (tekan 0):");
    scanf("%d", &pilihan);
    if (pilihan == 0)
    {
        menu();
    }
}

void cariJual()
{
    int pilihan;
    printf("Masukan kode yang di cari : ");
    scanf("%d", &c);
    cari();
    if (d > 0)
    {
        b--;
        printf("%d.Kode barang :%d\n", b, kode[b]);
        printf("Nama barang: %s\n", namaBarang[b]);
        printf("Jumlah barang : %d\n", jumlahBarang[b]);
        printf("Harga barang : %d\n", harga[b]);
        printf("Total Harga : %d\n", total[b]);
    }
    else
    {
        printf("Kode anda lama");
    }
    printf("Kembali ke menu (tekan 0):");
    scanf("%d", &pilihan);
    if (pilihan == 0)
    {
        menu();
    }
}
void cari()
{
    b = 1;
    d = 0;
    while (b <= a && d == 0)
    {
        if (c == kode[b])
        {
            d++;
        }
        b++;
    }
}

void updateJual()
{
    int pilihan;
    printf("Kode Jual yang akan di update: \n");
    scanf("%d", &c);
    cari();
    puts("");
    if (d < 1)
    {
        printf("Data anda tidak ada");
    }
    else
    {
        b--;
        printf("%d.Kode barang :%d\n", b, kode[b]);
        printf("Nama barang: %s\n", namaBarang[b]);
        printf("Jumlah barang : %d\n", jumlahBarang[b]);
        printf("Harga barang : %d\n", harga[b]);
        printf("Total Harga : %d\n", total[b]);
        printf("--------------------------\n");
        printf("\nNama Barang : ");
        scanf("%s", namaBarang[b]);
        printf("Jumlah barang : ");
        scanf("%d", &jumlahBarang[b]);
        printf("Harga barang: Rp.");
        scanf("%d", &harga[b]);
        total[b] = jumlahBarang[b] * harga[b];
        printf("Total harga: Rp.%d", total[b]);
        fprintf(nota, "Update data jual: \n%d.Kode Barang : %d\nnama barang: %s\njumhlah barang: %d\nHarga Barang: Rp.%d\nTotal Harga: Rp.%d\n", b, kode[b], namaBarang[b], jumlahBarang[b], harga[b], total[b]);
    }
    puts("");
    printf("Kembali ke menu (tekan 0):");
    scanf("%d", &pilihan);
    if (pilihan == 0)
    {
        menu();
    }
}

void hasilJual()
{
    fclose(nota);
    nota = fopen("penjualan.txt", "w+");
    fclose(nota);
    nota = fopen("penjualan.txt", "a+");
    fprintf(nota, "Data Penjualan");
    b = 1;
    while (b <= a)
    {
        fprintf(nota, "Kode Barang : %d\nnama barang: %s\njumhlah barang: %d\nHarga Barang: Rp.%d\nTotal Harga: Rp.%d\n", kode[b], namaBarang[b], jumlahBarang[b], harga[b], total[b]);
        b++;
    }
}
void hapusJual()
{

    printf("Kode Jual yang akan di hapus: ");
    scanf("%d", &c);
    cari();
    puts("");
    if (d < 1)
    {
        printf("Data anda tidak di temukan\n");
    }
    else
    {
        b--;
        printf("Data %d berhasil di hapus", kode[b]);
        fprintf(nota, "\nData %d ini di hapus", kode[b]);
        while (b < a)
        {
            kode[b] = kode[b + 1];
            strcpy(namaBarang[b], namaBarang[b + 1]);
            jumlahBarang[b] = jumlahBarang[b + 1];
            harga[b] = harga[b + 1];
            total[b] = total[b + 1];
            b++;
        }
        a--;
    }
    puts("");
    menu();
}

int main()
{
    printf("---- Selamat Datang di toko kami ------\n");
    printf("------ Kami siap melayani --------\n");
    menu();
}

int menu()
{
    int pilihan;
    nota = fopen("penjualan.txt", "a+");
    printf("Silahkan memilih beberapa menu yang tersedia: \n");
    printf("===========================\n");
    printf("          M E N U          \n");
    printf("===========================\n");
    printf(" 1. Input Penjualan\n");
    printf(" 2. View Penjualan\n");
    printf(" 3. Search Penjualan\n");
    printf(" 4. Update Penjualan\n");
    printf(" 5. Delete Penjualan\n");
    printf("===========================\n");
    printf(" 6. Exit\n");
    printf("===========================\n : ");
    scanf("%d", &pilihan);

    system("clear");
    switch (pilihan)
    {
    case 1:
        inputPenjualan();
        break;
    case 2:
        viewJual();
        break;
    case 3:
        cariJual();
        break;
    case 4:
        updateJual();
        break;
    case 5:
        hapusJual();
        break;
    default:
        printf("Silahkan masukan menu yang sesuai");
        return 0;
        hasilJual();
        break;
    }
    fclose(nota);
    return 0;
}