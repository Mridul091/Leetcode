class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int k = stones.size();
        sort(stones.begin(), stones.end());
        
        while(k>=2){
            int p1 = stones[k-1];
            int p2 = stones[k-2];
            
            if(p1==p2){
                stones.pop_back();
                stones.pop_back();
            }
            else{
                stones[k-2]=p1-p2;
                stones.pop_back();
            }
            
            sort(stones.begin(), stones.end());
            k = stones.size();
        }
        if(stones.size()==0) return 0;
        else return stones[0];
    }
};