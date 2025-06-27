class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        auto f_size = flowerbed.size();
        if (n > (f_size + 1) / 2) return false;        
        if (f_size == 1) return flowerbed[0] == 0 && n == 1;

        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            --n;
        }
        if (flowerbed[f_size-2] == 0 && flowerbed[f_size-1] == 0) {
            flowerbed[f_size-1] = 1;
            --n;
        }

        for (size_t i = 1; n > 0 && i < f_size - 1; ++i) {
            if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                --n;
                ++i; // skip one step
            }
        }
        return n <= 0;;
    }
};