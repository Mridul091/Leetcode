class Solution {
public:
    static bool cmp(vector<int> & a, vector<int> & b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0;
        int n = boxTypes.size();
        for(int i=0;i<n;i++){
            if(truckSize >= boxTypes[i][0])
                ans += boxTypes[i][1]*boxTypes[i][0];
            else{
                ans += (truckSize)*boxTypes[i][1];
                break;
            }
            truckSize-= boxTypes[i][0];
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<2;j++){
        //         cout << boxTypes[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};