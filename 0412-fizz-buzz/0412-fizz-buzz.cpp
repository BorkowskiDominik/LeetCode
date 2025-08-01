class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answers;
        answers.resize(n);
        for (int i = 1; i < n + 1; ++i ) {
            if ( i % 3 && i % 5 ) {
                answers[i-1] = to_string(i);
            } else {
                if (!(i%3)) {
                    answers[i-1] += "Fizz";
                }
                if (!(i%5)) {
                    answers[i-1] += "Buzz";
                }
            }
        }
        return answers;
    }
};