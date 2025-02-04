#include <iostream>
#include <vector>

using namespace std;

int countSubsetsWithSum(const vector<int>& nums, int target) {
    int n = nums.size();
    
    // dp[mask]: mask alt kümesindeki öğelerin toplamını saklar
    vector<bool> dp(target + 1, false);  // 0'dan target'a kadar olan tüm toplamlar
    dp[0] = true;  // Başlangıçta 0 toplamına sahip bir alt küme (boş küme)

    // Alt kümeleri oluştur
    for (int i = 0; i < n; ++i) {
        for (int j = target; j >= nums[i]; --j) {
            // Eğer (j - nums[i]) toplamını oluşturabilen bir alt küme varsa
            // Bu durumda j toplamını oluşturabiliriz
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    // Sonuç: dp[target] doğru ise, toplamı target olan en az bir alt küme var
    return dp[target] ? 1 : 0;
}

int main() {
    vector<int> nums = {2, 3, 7};  // Dizi
    int target = 5;  // Hedef toplam

    int result = countSubsetsWithSum(nums, target);

    if (result == 1) {
        cout << "Alt küme, hedef toplamı oluşturabiliyor." << endl;
    } else {
        cout << "Alt küme, hedef toplamı oluşturamıyor." << endl;
    }

    return 0;
}