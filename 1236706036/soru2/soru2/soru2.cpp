// soru2.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
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






/*Öyle bir sıralama algoritması tasarlayınız ki, sıralama işlemini bir
en büyük bir en küçük eleman olacak şekilde yapsın. Örneğin
(60,80,3,9,57,11) gibi bir diziyi (80,3,60,9,57,11) şeklinde
sıralayacak. Program parçası C programlama dili ile yazılacaktır. */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[(low + high) / 2]; // Orta elemanı pivot olarak seçelim
        int i = low - 1, j = high + 1, temp;
        while (1) {
            do {
                i++;
            } while (arr[i] < pivot);

            do {
                j--;
            } while (arr[j] > pivot);

            if (i >= j)
                break;

            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        quickSort(arr, low, j);
        quickSort(arr, j + 1, high);
    }
}

void birbuyukbirkucuk(int arr[], int n) {
    quickSort(arr, 0, n - 1);
    int* result = (int*)malloc(n * sizeof(int));
    if (result == NULL) {
        printf("Bellek ayırma hatası!\n");
        return;
    }

    int left = 0, right = n - 1, index = 0;

    while (left <= right) {
        result[index++] = arr[right--];
        if (left <= right)
            result[index++] = arr[left++];
    }

    for (int i = 0; i < n; i++)
        arr[i] = result[i];

    free(result);
}

void diziYazdir(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int dizi[5];

    printf("Lütfen 5 tamsayı giriniz: ");
    for (int i = 0; i < 5; i++) {
        scanf_s("%d", &dizi[i]);
    }

    birbuyukbirkucuk(dizi, 5);

    printf("Özel sıralanmış dizi: ");
    diziYazdir(dizi, 5);

    return 0;
}