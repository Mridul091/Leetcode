class Solution {
private:
    struct cmp{
        bool operator() (const pair<int, string>& a,const pair<int, string>& b){
            if(a.first!=b.first){
                return a.first > b.first;
            }
            else{
                return a.second < b.second;
            }
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(int i = 0;i<words.size();i++){
            mp[words[i]]++;
        }
        
        priority_queue<pair<int, string>,vector<pair<int, string>>, cmp> pq;
        for(auto it = mp.begin(); it!=mp.end();it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > k) pq.pop();
        }
        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};