class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int temp = 0;
        int water=INT_MIN;
        while(left<=right){
            temp= (right-left)*min(height[left], height[right]);
            water = max(water, temp);
            cout << water << " ";
            if(height[left]>=height[right])
                right--;
            else
                left++;
        }
        return water;
    }
};