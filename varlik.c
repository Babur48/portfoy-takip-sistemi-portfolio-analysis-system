#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "varlik.h"

double guvenli_sayi_al(char *mesaj){
    double sayi;
    int sonuc;

    while(1){
        printf("%s",mesaj);
        sonuc = scanf("%lf",&sayi);

        if(sonuc == 1 && sayi >= 0){
            while(getchar() != '\n');
            return sayi;
        }
        else{
            printf("[HATA] Gecersiz giris. Lutfen pozitif sayi giriniz!\n");
            while(getchar() != '\n');
        }
    }
}


void varlik_ekle() {
    struct Varlik yeni;

    FILE *dosya = fopen("portfoy.txt","a");

    if( dosya == NULL ){
        return;
    }
    printf("\nVarlik adi: ");
    scanf("%s",yeni.ad);

    yeni.miktar = guvenli_sayi_al("Miktar: ");
    yeni.alisFiyati = guvenli_sayi_al("Birim Alis Fiyati: ");
    yeni.guncelFiyat = guvenli_sayi_al("Anlik Piyasa Fiyati: ");

    fprintf(dosya,"%s %lf %lf %lf\n",yeni.ad, yeni.miktar,yeni.alisFiyati,yeni.guncelFiyat);
    fclose(dosya);
    printf("\nISLEM BASARI ILE KAYDEDILDI\n");
}

void portfoy_listele() {
    struct Varlik portfoy[100];
    FILE *dosya = fopen("portfoy.txt", "r");

    double genel_maliyet = 0;
    double genel_guncel_deger = 0;
    double genel_deger;
    double maliyet;
    double toplam_portfoy_degeri = 0;
    int varlik_sayisi = 0;
    int sayac = 0;


    if(dosya == NULL) {
        printf("\n[!] Kayitli varlik bulunamadi. Lutfen once ekleme yapin.\n");
        return;
    }

    // printf("\n%-15s %-10s %-15s %-15s\n", "AD", "ADET", "MALIYET", "K/Z DURUMU");
    // printf("------------------------------------------------------------\n");

    // fscanf okurken de & işaretlerine dikkat (String hariç hepsine ekledik)
    while(fscanf(dosya, "%s %lf %lf %lf", portfoy[sayac].ad, &portfoy[sayac].miktar, &portfoy[sayac].alisFiyati, &portfoy[sayac].guncelFiyat) == 4) {
        maliyet = portfoy[sayac].miktar * portfoy[sayac].alisFiyati;
        genel_deger = portfoy[sayac].miktar * portfoy[sayac].guncelFiyat;
        sayac++;

        // double kar_zarar = guncel_deger - maliyet;

        genel_maliyet += maliyet;
        genel_guncel_deger += genel_deger;
        toplam_portfoy_degeri += genel_deger;
        varlik_sayisi++;

        // printf("%-15s %-10.2f %-15.2f %-15.2f\n", 
        //        gecici.ad, gecici.miktar, maliyet, kar_zarar);
    }
    
    fclose(dosya);

    if(sayac == 0){
        return;
    }

    printf("\n%-12s %-10s %-12s %-10s %-8s\n", "VARLIK", "ADET", "MALIYET", "K/Z", "DAGILIM");
    printf("------------------------------------------------------------------\n");

    for(int i = 0; i < sayac ; i++){
        double m = portfoy[i].miktar * portfoy[i].alisFiyati;//maliyet
        double d =portfoy[i].miktar * portfoy[i].guncelFiyat;//değer
        double kz = d - m ;


        double agirlik = ( d/toplam_portfoy_degeri ) * 100;

        printf("%-12s %-10.2f %-12.2f %-10.2f %% %-6.1f\n",portfoy[i].ad, portfoy[i].miktar, m, kz, agirlik);
    }



    if(varlik_sayisi  > 0){
        double toplam_KZ = genel_guncel_deger - genel_maliyet;
        double performans = (toplam_KZ / genel_maliyet) * 100;

        printf("------------------------------------------------------------\n");
        printf("PORTFOY GENEL ANALIZ (%d VARLIK )\n ",varlik_sayisi);
        printf("TOPLAM YATIRIM (MALIYET): %.2f  TL\n ",genel_maliyet);
        printf("GUNCEL TOPLAM DEGER: %.2f TL\n ",genel_guncel_deger);
        printf("NET KAR / NET ZARAR: %.2f TL (%% %.2f)\n",toplam_KZ, performans );
        printf("------------------------------------------------------------\n");
    }
}

void varlik_sil() {
    struct Varlik gecici;
    char silinecekAd[20];
    int bulundu = 0;

    // Tampon temizliği
    while(getchar() != '\n'); 

    printf("\nSilinecek varlik adi: ");
    scanf(" %s", silinecekAd);

    FILE *fp = fopen("portfoy.txt", "r");
    FILE *ft = fopen("gecici.txt", "w");

    if (fp == NULL) {
        printf("[!] Hata: portfoy.txt acilamadi!\n");
        if(ft) fclose(ft);
        return;
    }
    if (ft == NULL) {
        printf("[!] Hata: gecici.txt olusturulamadi!\n");
        if(fp) fclose(fp);
        return;
    }

    // Dosyayı tara ve kopyala
    while (fscanf(fp, "%s %lf %lf %lf", 
                  gecici.ad, &gecici.miktar, &gecici.alisFiyati, &gecici.guncelFiyat) == 4) {
        
        if (strcmp(gecici.ad, silinecekAd) == 0) {
            bulundu = 1;
            printf(">> %s bulundu ve listeden cikariliyor...\n", silinecekAd);
        } else {
            // Eşleşmeyenleri geçici dosyaya yaz
            fprintf(ft, "%s %lf %lf %lf\n", 
                    gecici.ad, gecici.miktar, gecici.alisFiyati, gecici.guncelFiyat);
        }
    }

    // KRİTİK: Dosyaları ÖNCE kapatmalıyız!
    fclose(fp);
    fclose(ft);

    if (bulundu) {
        // Eski dosyayı silmeyi dene
        if (remove("portfoy.txt") == 0) {
            // İsim değiştirmeyi dene
            if (rename("gecici.txt", "portfoy.txt") == 0) {
                printf(">> Islem basarili. Dosya guncellendi.\n");
            } else {
                printf("[!!] KRITIK HATA: gecici.txt ismi degistirilemedi!\n");
                printf("Verileriniz 'gecici.txt' icinde sakli kaldi.\n");
            }
        } else {
            printf("[!!] KRITIK HATA: Orijinal dosya silinemedi! (Dosya acik kalmis olabilir)\n");
        }
    } else {
        remove("gecici.txt"); // Bulunamadıysa geçici dosyayı imha et
        printf("[!] Varlik bulunamadigi icin dosya degistirilmedi.\n");
    }
}


 
void fiyat_guncelle(){
    struct Varlik gecici;
    char hedef_ad[20];
    double yeniFiyat;
    int bulundu = 0;

    while(getchar() != '\n');

    printf("\nFiyatini guncellemek istedigin varlik ismi: ");
    scanf(" %s",hedef_ad);

    FILE *pf = fopen("portfoy.txt","r");
    FILE *pt = fopen("gecici.txt","w");

    if(pf == NULL || pt == NULL){
        printf("[HATA] Dosyalara erisilemedi.\n");
        return;
    }


    while(fscanf(pf,"%s %lf %lf %lf",gecici.ad,&gecici.miktar,&gecici.alisFiyati,&gecici.guncelFiyat) == 4){
        if(strcmp(gecici.ad , hedef_ad) == 0){
            bulundu = 1;
            printf("%s varligi bulundu. Mevcut fiyat %.2f TL\n",hedef_ad,gecici.guncelFiyat);
            printf("Yeni guncel fiyat: ");
            scanf("%lf",&yeniFiyat);

            gecici.guncelFiyat = yeniFiyat;
        }

        fprintf(pt,"%s %lf %lf %lf\n",gecici.ad,gecici.miktar,gecici.alisFiyati,gecici.guncelFiyat);
    }

    fclose(pf);
    fclose(pt);


    if(bulundu){
        remove("portfoy.txt");
        rename("gecici.txt","portfoy.txt");
        printf("\nFIYAT BASARILI SEKILDE GUNCELLENDI.\n");
    }
    else{
        remove("gecici.txt");
        printf("[HATA] '%s' bulunamadi",hedef_ad );
    }
}