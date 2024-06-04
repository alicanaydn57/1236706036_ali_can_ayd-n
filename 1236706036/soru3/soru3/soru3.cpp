// soru3.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
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



/*Trie(Metin Ağacı) yapısı nedir ? Çalışma şeklini açıklayıp
algoritmasını yazınız.Örnek bir Trie oluşturma kodunu C
programlama dili ile yazınız.*/

/*Trie(Metin Ağacı) Yapısı
Trie, kelime tabanlı arama problemleri için optimize edilmiş bir veri yapısıdır.
Özellikle string verileri hızlı bir şekilde eklemek, aramak ve silmek için kullanılır.
Temel olarak bir kök düğüm(root) ve her biri bir karakteri temsil eden alt düğümlerden oluşur.
Metin ağaçları, her düğümün kendisinden sonra gelen harfi işaret ettiği ağaçlardır.
Basitçe ağacın üzerine bir metin kodlanabilir ve bu metni veren ağacın üzerinde tek bir yol izlenebilir(deterministic).*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALFABE_BOYUTU 26

typedef struct TrieNode {
    struct TrieNode* children[ALFABE_BOYUTU];
    bool isEndOfWord;
} TrieNode;

TrieNode* newTrieNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node) {
        node->isEndOfWord = false;
        for (int i = 0; i < ALFABE_BOYUTU; i++)
            node->children[i] = NULL;
    }
    return node;
}

void kelimeEkle(TrieNode* root, const char* kelime) {
    if (root == NULL || kelime == NULL) {
        printf("Hata: Geçersiz argümanlar\n");
        return;
    }

    TrieNode* gezici = root;
    int uzunluk = strlen(kelime);
    for (int seviye = 0; seviye < uzunluk; seviye++) {
        int indeks = kelime[seviye] - 'a';
        if (indeks < 0 || indeks >= ALFABE_BOYUTU) {
            printf("Hata: Gecersiz indeks\n");
            return;
        }

        if (!gezici->children[indeks]) {
            TrieNode* yeniNode = newTrieNode();
            if (yeniNode == NULL) {
                printf("Hata: Bellek ayırma başarısız\n");
                return;
            }
            gezici->children[indeks] = yeniNode;
        }
        gezici = gezici->children[indeks];
    }
    gezici->isEndOfWord = true;
}


bool kelimeAra(TrieNode* root, const char* kelime) {
    TrieNode* gezici = root;
    int uzunluk = strlen(kelime);
    for (int seviye = 0; seviye < uzunluk; seviye++) {
        int indeks = kelime[seviye] - 'a';
        if (!gezici->children[indeks])
            return false;
        gezici = gezici->children[indeks];
    }
    return (gezici != NULL && gezici->isEndOfWord);
}

int main() {
    TrieNode* root = newTrieNode();

    const char* kelimeler[] = { "kitap", "kalem", "defter", "kedi", "köpek" };

    for (int i = 0; i < sizeof(kelimeler) / sizeof(kelimeler[0]); i++)
        kelimeEkle(root, kelimeler[i]);

    printf("%s %s\n", "kitap", kelimeAra(root, "kitap") ? "bulundu" : "bulunamadi");
    printf("%s %s\n", "ayakkabi", kelimeAra(root, "ayakkabı") ? "bulundu" : "bulunamadi");

    return 0;
}


/*Trie yapısı, her bir düğümünün bir harfi temsil ettiği ve alt düğümleri olduğu bir ağaç yapısıdır.
Kelimeler, her bir karakteri bir düğümde saklanır ve bu düğümler birbirine bağlanarak oluşturulur.
newTrieNode fonksiyonu yeni bir düğüm oluşturur ve başlangıç değerlerini ayarlar.
kelimeEkle fonksiyonu Trie'ye yeni bir kelime ekler. Her karakter için bir düğüm oluşturulur ve bağlantılar sağlanır.
kelimeAra fonksiyonu Trie'de bir kelime arar. Her karakter için ilerler ve sonunda kelime bulunursa true döner.
Ana programda, Trie yapısını oluşturur, bazı kelimeleri ekler ve ardından arama yapar.*/