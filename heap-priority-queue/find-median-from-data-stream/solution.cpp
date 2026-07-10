class MedianFinder {
public:
    priority_queue<int> small; // max_heap containing smaller elements
    priority_queue<int,vector<int>,greater<int>> large; // min_heap containg larger elements

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        if(!small.empty() && !large.empty() && small.top()>large.top()){
            int val = small.top();
            small.pop();
            large.push(val);
        }
        if(small.size() > large.size()+1){
            int val = small.top();
            small.pop();
            large.push(val);
        }
        if(large.size() > small.size()+1){
            int val = large.top();
            large.pop();
            small.push(val);
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()) return small.top();
        else if(small.size() < large.size()) return large.top();

        return (double)(small.top() + large.top())/2.0 ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */