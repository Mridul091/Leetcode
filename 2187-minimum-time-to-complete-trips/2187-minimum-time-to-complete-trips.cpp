class Solution {
public:
    
    bool canComplete(vector<int> &time, long long givenTime, int totalTrips){
        long long possibleTrips = 0;
        for(int i=0;i<time.size();i++){
            possibleTrips += (givenTime/time[i]);
        }
        
        return possibleTrips >= totalTrips;
    }
    
    long long minimumTime(vector<int>& time,  long long totalTrips) {
        long long  l =1;
        long long  h = time[0]*totalTrips;
        
        while(l<=h){
            long long mid = (l+h) >> 1;
            if(canComplete(time, mid, totalTrips))
                h=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};