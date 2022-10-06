class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> &v = mp[key];
        int start = 0;
        int end = v.size()-1;
        int idx = -1;
        while(start<=end){
            int mid = (start + end) >> 1;
            if(timestamp >= v[mid].first){
                start = mid + 1;
                idx = mid;
            }
            else  end  = mid-1;
        }
        if(idx==-1) return "";
        return v[idx].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */