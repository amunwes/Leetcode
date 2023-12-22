class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        lower.push(num);
        if (lower.size()-1>higher.size()){
            higher.push(lower.top());
            lower.pop();
        }
        while(higher.size()> 0 && lower.top() > higher.top()){
            int temp = higher.top();
            higher.pop();
            higher.push(lower.top());
            lower.pop();
            lower.push(temp);
        }

    }
    
    double findMedian() {
        double median;
        if (lower.size() == higher.size()){
            median = (lower.top()+higher.top())/2.0;
        }else{
            median = lower.top();
        }
        return median;
    }
private:
    priority_queue<int> lower;  
    priority_queue<int, vector<int>, greater<int>> higher;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */