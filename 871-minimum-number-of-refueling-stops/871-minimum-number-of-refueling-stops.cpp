class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int reach = startFuel;
        priority_queue<int> pq;
        int cnt = 0;
        int ind = 0;
        while(reach < target){
            while(ind < stations.size() && stations[ind][0] <= reach){
                pq.push(stations[ind][1]);
                ind++;
            }
            if(pq.empty()) return -1;
            reach += pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};