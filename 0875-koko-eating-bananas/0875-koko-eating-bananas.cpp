class Solution {    
private:
    // Czy Koko da radę zjeść wszystkie banany w 'maxHours', jedząc z prędkością 'eatingSpeed'?
    bool canEatAllBananas(const vector<int>& bananaPiles, int maxHours, int eatingSpeed) {
        int hoursNeeded = 0;

        for (int pileSize : bananaPiles) {
            // Zaokrąglenie w górę: ile godzin potrzeba na jeden stos
            hoursNeeded += (pileSize + eatingSpeed - 1) / eatingSpeed;

            // Optymalizacja: przerwij wcześniej, jeśli już za długo
            if (hoursNeeded > maxHours)
                return false;
        }

        return true;
    }

public:
    int minEatingSpeed(vector<int>& bananaPiles, int maxHours) {
        int minSpeed = 1;
        int maxSpeed = *max_element(bananaPiles.begin(), bananaPiles.end());
        int bestSpeed = maxSpeed;

        while (minSpeed <= maxSpeed) {
            int currentSpeed = minSpeed + (maxSpeed - minSpeed) / 2;

            if (canEatAllBananas(bananaPiles, maxHours, currentSpeed)) {
                bestSpeed = currentSpeed;         // da się zjeść – spróbuj wolniej
                maxSpeed = currentSpeed - 1;
            } else {
                minSpeed = currentSpeed + 1;      // za wolno – jedz szybciej
            }
        }

        return bestSpeed;
    }

};
