#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Permütasyonları bitwise işlemlerle üretme fonksiyonu
void generatePermutations(vector<int>& arr) {
    int n = arr.size();  // Dizi boyutunu alıyoruz

    // 1'den 2^n - 1'e kadar olan tüm bitmask'leri kontrol ediyoruz
    // 2^n = 1 << n, bu yüzden 1 << n kadar dönecek
    for (int mask = 1; mask < (1 << n); ++mask) {
        vector<int> selected_elements;  // Bu mask ile seçilen elemanları tutacak vektör

        // Her bit için kontrol yapıyoruz
        for (int i = 0; i < n; ++i) {
            // Eğer mask'in i'nci biti 1 ise, arr[i] elemanını seçiyoruz
            if (mask & (1 << i)) {
                selected_elements.push_back(arr[i]);
            }
        }

        // Seçilen elemanların tüm permütasyonlarını oluşturuyoruz
        // STL'deki next_permutation fonksiyonunu kullanarak tüm permütasyonları yazdırıyoruz
        sort(selected_elements.begin(), selected_elements.end());  // Permütasyonları sıralamak için
        do {
            for (int num : selected_elements) {
                cout << num << " ";  // Permütasyonu ekrana yazdırıyoruz
            }
            cout << endl;
        } while (next_permutation(selected_elements.begin(), selected_elements.end()));  // Tüm permütasyonlar için döngü
    }
}

int main() {
    vector<int> arr = {1, 2, 3};  // Örnek dizi
    generatePermutations(arr);  // Permütasyonları üretme fonksiyonunu çağırıyoruz

    return 0;
}