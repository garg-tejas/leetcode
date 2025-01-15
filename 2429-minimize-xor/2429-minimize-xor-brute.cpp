class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBit = 0, count = 0;
        vector<int> bit1;
        int N=num1;
        while (num1) {
            bit1.push_back(num1 % 2);
            if (num1 % 2 == 1)
                count++;
            num1 /= 2;
        }

        while (num2) {
            if (num2 % 2 == 1)
                setBit++;
            num2 /= 2;
        }

        if (setBit == count)
            return N;
        vector<int> result(30,0);
        for (int i = bit1.size() - 1; i >= 0; i--) {
            if (bit1[i] == 1 && setBit>0) {
                result[i] = 1;
                setBit--;
            }
        }
        int i = 0;
        while (setBit > 0 && i<30) {
            if (result[i] == 0) {
                result[i] = 1;
                setBit--;
            }
            i++;
        }
        int num = 0;
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == 1)
                num += pow(2, i);
        }
        return num;
    }
};