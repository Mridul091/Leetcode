class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b ){
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> pq;
        int time = 0;
        for(auto & a: courses){
            if(a[0] <= a[1]){
                if(a[0] + time <= a[1]){
                    pq.push(a[0]);
                    time+= a[0];
                }
                else{
                    if(pq.top() > a[0]){
                        time-=pq.top();
                        time+= a[0];
                        pq.pop();
                        pq.push(a[0]);
                    }
                }
            }
        }
        return pq.size();
    }
};