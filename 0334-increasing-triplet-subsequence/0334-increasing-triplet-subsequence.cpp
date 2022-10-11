class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for(auto itr : nums){
            if(itr <= a) a = itr;
            else if(itr <= b) b = itr;
            else return true;
        }
        return false;
    }
};