// soru1.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>



// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
/*Bir X dizisine 0 - 1000 arası rasgele 500 tamsayı eleman yerleştirip
daha sonra bu diziyi hem “Birleştirmeli Sıralama(Insertion Sort)”
hem de “Seçmeli Sırlama(Selection Sort)” algoritmaları ile
sıralayıp her bir algoritmanın sıralama sürelerini ölçerek ekrana
uygun bir mesaj ile gösteren program parçasını C programlama
dili ile yazınız.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#define BOYUT 500

void birlestirmeliSirala(int dizi[], int n) {
    for (int i = 1; i < n; i++) {
        int anahtar = dizi[i];
        int j = i - 1;
        while (j >= 0 && dizi[j] > anahtar) {
            dizi[j + 1] = dizi[j];
            j--;
        }
        dizi[j + 1] = anahtar;
    }
}

void secmeliSirala(int dizi[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_indeks = i;
        for (int j = i + 1; j < n; j++)
            if (dizi[j] < dizi[min_indeks])
                min_indeks = j;
        int temp = dizi[min_indeks];
        dizi[min_indeks] = dizi[i];
        dizi[i] = temp;
    }
}

double zamanOlc(void (*sirala)(int[], int), int dizi[], int n) {
    clock_t baslangic = clock();
    sirala(dizi, n);
    return ((double)(clock() - baslangic)) / CLOCKS_PER_SEC;
}

int main() {
    int dizi[BOYUT], dizi_kopya[BOYUT];
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < BOYUT; i++)
        dizi[i] = rand() % 1001;

    for (int i = 0; i < BOYUT; i++)
        dizi_kopya[i] = dizi[i];

    printf("Birleştirmeli Sıralama %f saniye sürdü\n", zamanOlc(birlestirmeliSirala, dizi, BOYUT));
    printf("Seçmeli Sıralama %f saniye sürdü\n", zamanOlc(secmeliSirala, dizi_kopya, BOYUT));

    return 0;
}
