#ifndef VARLIK_H
#define VARLIK_H

struct Varlik{
    char ad[20];
    double miktar;
    double alisFiyati;
    double guncelFiyat;
};


void varlik_ekle();
void varlik_sil();
void portfoy_listele();
void fiyat_guncelle();
double guvenli_sayi_al(char *mesaj);


#endif