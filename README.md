# 📈 Portföy Takip ve Analiz Sistemi (Portfolio Management & Analysis System)

Bu proje; finansal varlıklarınızı (Hisse Senetleri, BIST/Yurt Dışı Piyasalar, Fonlar vb.) tek bir merkezden yönetmek, maliyet analizlerini yapmak ve yatırımlarınızın kâr/zarar durumunu takip etmek için geliştirilmiş bir **portföy yönetim aracıdır**. 

Modüler bir yapıyla geliştirilen bu yazılım, yatırımcının sermaye dağılımını optimize etmesine ve finansal durumunu net bir şekilde görmesine yardımcı olur.

---

## 🚀 Öne Çıkan Özellikler

*   **Varlık Yönetimi (CRUD):** Portföye yeni hisse senedi/varlık ekleme, miktar güncelleme ve varlık silme işlemleri.
*   **Dinamik Ortalama Maliyet Hesaplaması:** Farklı zamanlarda ve farklı fiyatlardan yapılan kademeli alımlarda, varlığın ağırlıklı ortalama maliyetini otomatik olarak hesaplar.
*   **Anlık Kâr / Zarar Analizi:** Güncel piyasa fiyatları üzerinden hem varlık bazında hem de toplam portföy genelinde nominal (TL/USD) ve yüzdesel (%) kâr/zarar durumunu listeler.
*   **Portföy Ağırlık Dağılımı:** Toplam sermayenizin hangi varlığa yüzde kaç oranında dağıldığını hesaplayarak risk analizi yapmanızı sağlar.
*   **Veri Yapıları ve Optimizasyon:** Verilerin güvenli ve performanslı işlenmesi için özelleştirilmiş yapılar (structs) ve dinamik diziler/bellek yönetimi kullanılmıştır.

---

## 🛠️ Kullanılan Teknolojiler ve Yapılar

*   **Programlama Dili:** C 
*   **Algoritmalar ve Yapılar:** Nesne benzeri yapılar (Structs), Dinamik Bellek Yönetimi, Diziler (Arrays) ve Arama/Sıralama Algoritmaları.
*   **Geliştirme Ortamı:** Visual Studio Code / GCC Derleyicisi

---

## ⚙️ Kurulum ve Çalıştırma

Projeyi yerel bilgisayarınızda çalıştırmak için aşağıdaki adımları takip edebilirsiniz:

1. Projeyi bilgisayarınıza indirin veya klonlayın:
   ```bash
   git clone https://github.com/Babur48/portfoy-takip-sistemi-portfolio-analysis-system.git
2.Derleme ve çalıştırma:
   Windows:
     gcc finans.c varlik.c -o portfoy_analiz.exe
     .\portfoy_analiz.exe
     
   MacOS ve Linux:
    gcc finans.c varlik.c -o portfoy_analiz
    ./portfoy_analiz

Bu proje; finansal varlıklarınızı (Hisse Senetleri, BIST/Yurt Dışı Piyasalar, Fonlar vb.) tek bir merkezden yönetmek, maliyet analizlerini yapmak ve yatırımlarınızın kâr/zarar durumunu takip etmek için geliştirilmiş bir **portföy yönetim aracıdır**. 

Modüler bir yapıyla geliştirilen bu yazılım, yatırımcının sermaye dağılımını optimize etmesine ve finansal durumunu net bir şekilde görmesine yardımcı olur.

---




