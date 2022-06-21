class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // int n = heights.size();
        // int ans;
        // for(int i=n-1;i>=0;i--){
        //     cout << i  << endl;
        //     int j =i;
        //     int temp_bricks = bricks;
        //     int temp_ladders = ladders;
        //     while(j >0){
        //         cout<<j<<" " << temp_bricks << " " << temp_ladders << endl;
        //         if(temp_bricks<=0 && temp_ladders<=0 ) break;
        //         if(heights[j-1] >= heights[j]){
        //             j--;
        //             continue;
        //         } 
        //         else if(heights[j]-heights[j-1] > temp_bricks) temp_ladders--;
        //         else temp_bricks = temp_bricks - (heights[j] - heights[j-1]);
        //         j--;
        //     }
        //     cout << j << " ";
        //     if(j==0 && heights[j+1] <= heights[j]){
        //         ans = i;
        //         break;
        //     }
        //     else if(j==0 && (height[j]))
        //     cout<<endl;
        // }
        // return ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        int i=0;
        for( i=0;i<n-1;i++){
            if(heights[i+1]<=heights[i]) continue;
            int diff = heights[i+1] - heights[i];
            
            if(diff>0){
                pq.push(diff);
            }
            if(pq.size()>ladders){
                int temp = pq.top();
                pq.pop();
                bricks-=temp;
                if(bricks<0) break;
            }
        }
        return i;
    }
};
    //     int n=a.size();
    //     int i=0;
    //     priority_queue<int, vector<int>, greater<int>> pq;
    //     for(i=0;i<n-1;i++)
    //     {
    //         if(a[i]<a[i+1])
    //             pq.push(a[i+1]-a[i]);
    //         if(pq.size()>l)
    //         {
    //             int temp = pq.top();
    //             pq.pop();
    //             b-=temp;
    //             if(b<0)
    //                 break;
    //         }
    //     }
    //     return i;
    // }