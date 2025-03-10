class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long countOfSubstrings(string word, int k) {
        long res = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int> vowel;
        int consonant = 0;

        vector<int> nextConsonant(word.size());
        int nxtConsonantIDX = word.size();
        for (int i = word.size() - 1; i >= 0; i--) {
            nextConsonant[i] = nxtConsonantIDX;
            if (!isVowel(word[i])) {
                nxtConsonantIDX = i;
            }
        }

        while (right < word.size()) {
            char newLetter = word[right];
            if (isVowel(newLetter)) {
                vowel[newLetter]++;
            } else {
                consonant++;
            }

            while (consonant > k) {
                char startLetter = word[left];
                if (isVowel(startLetter)) {
                    vowel[startLetter]--;
                    if (vowel[startLetter] == 0) {
                        vowel.erase(startLetter);
                    }
                } else {
                    consonant--;
                }
                left++;
            }

            while (left < word.size() && vowel.size() == 5 &&
                   consonant == k) {
                res += nextConsonant[right] - right;
                char startLetter = word[left];
                if (isVowel(startLetter)) {
                    vowel[startLetter]--;
                    if (vowel[startLetter] == 0) {
                        vowel.erase(startLetter);
                    }
                } else {
                    consonant--;
                }
                left++;
            }
            right++;
        }
        return res;
    }
};