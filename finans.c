#include <stdio.h>
#include <stdlib.h>
#include "varlik.h"



int main() {
    int secim;

  

    while(1) {
        printf("\n=== VARLIK TAKIP TERMINALI v1.0 ===\n");
        printf("1. Yeni Varlik Ekle\n");
        printf("2. Varlik sil\n");
        printf("3. Fiyat guncelle\n");
        printf("4. Portfoyu Goruntule ve Analiz Et\n");
        printf("5. Cikis\n");
        
        
   

        secim = (int)guvenli_sayi_al("Seciminiz: ");

        switch(secim) {
            case 1:
                varlik_ekle();
                break;
            case 2:
                varlik_sil();
                break;
            case 3:
                fiyat_guncelle();
                break;
            case 4:
                portfoy_listele();
                break;
            case 5:
                printf("Sistemden cikiliyor... Bol kazanclar!\n");
                exit(0);
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
        }
    }

    return 0;
}

