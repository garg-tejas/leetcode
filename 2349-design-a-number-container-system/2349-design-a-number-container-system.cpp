class NumberContainers {
public:
    unordered_map<int, int> idx;
    unordered_map<int, set<int>> num;
    NumberContainers() {}

    void change(int index, int number) {
        if (idx.find(index) != idx.end()) {
            int prevNum = idx[index];
            if (prevNum != number) {
                if (num.find(prevNum) != num.end())
                    num[prevNum].erase(index);
            }
        }
        idx[index] = number;
        num[number].insert(index);
    }

    int find(int number) {
        if (num.find(number) != num.end() &&  *num[number].begin()!=0) {
            return *num[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */