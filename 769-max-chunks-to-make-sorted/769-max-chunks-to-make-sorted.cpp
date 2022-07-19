class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int max_ele = 0;
        for(int i=0;i<n;i++){
            max_ele = max(max_ele, arr[i]);
            if(max_ele == i) count++;
        }
        return count;
    }
};