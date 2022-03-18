class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        if(n==0)
            return tasks.size();
        int count =0;
        
        for(auto it:tasks){
            m[it]++;
            count = max(m[it],count);
        }
        int job = 0;
        for(auto a: m){
            if(a.second==count)
                job++;
        }
        return max((n+1)*(count-1) +job, (int)tasks.size());
    }
};