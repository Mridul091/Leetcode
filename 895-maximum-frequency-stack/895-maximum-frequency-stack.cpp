class FreqStack {
public:
    unordered_map<int, stack<int>> map;
    unordered_map<int, int> freq;
    int maxfreq;
    FreqStack() {
        map.clear();
        freq.clear();
        maxfreq=0;
    }
    
    void push(int val) {
        freq[val]++;
        map[freq[val]].push(val);
        maxfreq = max(maxfreq, freq[val]);
    }
    
    int pop() {
        int ans = map[maxfreq].top();
        map[maxfreq].pop();
        freq[ans]--;
        
        if(map[maxfreq].empty())
            maxfreq--;
        return ans;
    }
    
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */