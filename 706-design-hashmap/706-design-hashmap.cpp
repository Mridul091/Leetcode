class MyHashMap {
public:
    vector<list<pair<int,int>>> s;
    int siz;
    MyHashMap() {
        siz = 100;
        s.resize(siz);
    }
    int hash(int key){
        return key%siz;
    }
    
    list<pair<int,int>> :: iterator search(int key){
        int i = hash(key);
        list<pair<int,int>> :: iterator it=s[i].begin();
        while(it!=s[i].end()){
            if(it->first == key) return it;
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        remove(key);
        s[i].push_back({key, value});
    }
    
    int get(int key) {
        int i= hash(key);
        list<pair<int, int>> :: iterator it =search(key);
        if(it==s[i].end()) return -1;
        else return it->second;
    }
    
    void remove(int key) {
        int i = hash(key);
        list<pair<int, int>> :: iterator it =search(key);
        if(it!=s[i].end()) s[i].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */