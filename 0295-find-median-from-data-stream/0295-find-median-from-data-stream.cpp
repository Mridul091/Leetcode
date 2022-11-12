class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(maxpq.empty() || num<maxpq.top()){
       		maxpq.push(num);
  		}
       	else minpq.push(num);
        
        if((int)(minpq.size()-maxpq.size())>1){
            maxpq.push(minpq.top());
            minpq.pop();
        }
        else if((int)(maxpq.size()-minpq.size())>1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
    }
    
    double findMedian() {
        int size = maxpq.size() + minpq.size();
        double ans;
        if(size%2==0){
            ans = (maxpq.top() + minpq.top())/2.0;
        }
        else{
            if(maxpq.size()>minpq.size()) ans = maxpq.top();
            else ans = minpq.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */