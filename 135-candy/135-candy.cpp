class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1) return 1;
        vector<int> candy(n,1);
        // for(int i =0;i<n;i++){
        //     if(i >0 && i<n-1 && ratings[i] > ratings[i+1] && ratings[i] > ratings[i-1])
        //         candy[i] = max(candy[i-1], candy[i+1]) + 1;
        //     else if( i >0 && ratings[i] > ratings[i-1])
        //         candy[i] = candy[i-1] + 1;
        //     else if(i< n-1 && ratings[i] > ratings[i+1]){
        //         candy[i] = candy[i+1] + 1;
        //     }
        // }
        // int ans= 0;
        // for(auto it: candy)
        //     ans += it;
        // return ans;
        for(int i =0;i<n-1;i++){
            if(ratings[i] < ratings[i+1])
                candy[i+1] = candy[i] + 1;
        }
        for(int i=n-1;i>0;i--){
            if(ratings[i-1] > ratings[i])
                candy[i-1] = max(candy[i] + 1, candy[i-1]);
        }
        int ans= 0;
        for(auto it: candy)
            ans += it;
        return ans;
    }
};

// [1,0,1,2,3,0,5]
// [2,1,2,3,4,1,2]
// 15
// [1,2,87,87,87,2,1]
// [1,2,3,1,2,2,1]