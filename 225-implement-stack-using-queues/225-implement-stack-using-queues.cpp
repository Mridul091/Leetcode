class MyStack {
public:
    queue<int> p;
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
 
        p.push(x);
    }
    
    int pop() {
        while(p.size()!=1){
           q.push(p.front());
           p.pop();
        }
        int k = p.front();
        p.pop();
        
        while(q.size()!=0){
            p.push(q.front());
            q.pop();
        }
        
        return k;
    }
    
    int top() {
        int k= pop();
        p.push(k);
        return k;
    }
    
    bool empty() {
        return p.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */