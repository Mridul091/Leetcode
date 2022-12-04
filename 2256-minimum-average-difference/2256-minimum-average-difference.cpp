class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long int sum = 0;
        int ind;
        int temp = INT_MAX;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        long long int f_sum=0;
        long long int avg=0;
        for(int i=0;i<n;i++){
            f_sum+=nums[i];
            sum -= nums[i];
            if(i==n-1)
                avg = abs((f_sum/(i+1))-(sum));
            else
                avg = abs((f_sum/(i+1))-(sum)/(n-(i+1)));
            if(temp>avg){
                temp = avg;
                ind = i;
            }

        }
        return ind;
    }
};