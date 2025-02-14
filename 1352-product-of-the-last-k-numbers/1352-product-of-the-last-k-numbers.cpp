class ProductOfNumbers {
public:
    vector<int> nums;
    vector<long long> cumProdNums;
    vector<int> zeroidx;
    ProductOfNumbers() {}

    void add(int num) {
        nums.push_back(num);
        if (cumProdNums.empty() && num != 0)
            cumProdNums.push_back(num);
        else if (num != 0)
            cumProdNums.push_back(cumProdNums.back() * num);
        if(num==0){
            zeroidx.push_back(nums.size() - 1);
            cumProdNums.push_back(1);
        }

    }

    int getProduct(int k) {
        for (int idx : zeroidx) {
            if (idx >= nums.size() - k)
                return 0;
        }
        if(k<cumProdNums.size())
        return cumProdNums.back()/
               cumProdNums[cumProdNums.size() - 1 - k];
        return cumProdNums.back();
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */