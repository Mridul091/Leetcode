class NumArray {
public:
    vector<int> bittree, num;
    void init(int i, int val) {
        i = i + 1;
        while(i <= bittree.size() - 1) {
            bittree[i] += val;
            i += i & (-i);
        }
    }
    int getsum(int i) {
        i = i + 1;
        int sum = 0;
        while(i > 0) {
            sum += bittree[i];
            i -= i & (-i);
        }
        return sum;
    }
    NumArray(vector<int>& nums) {
        num = nums;
        bittree.resize(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++) {
            init(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - num[i];
		num[i] = val;
		init(i, diff);
    }
    
    int sumRange(int i, int j) {
        return getsum(j) - getsum(i -1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */