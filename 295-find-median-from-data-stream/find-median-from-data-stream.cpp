class MedianFinder {
public:
    priority_queue<double, vector<double>, greater<double>> minpq;
    priority_queue<double> maxpq;
    int size;

    MedianFinder() { size = 0; }

    void addNum(int num) {
        size++;
        if(!maxpq.empty()) num <= maxpq.top() ? maxpq.push(num) : minpq.push(num);
        else maxpq.push(num);
        
        if(maxpq.size()>minpq.size()+1){
            int n=maxpq.top();
            maxpq.pop();
            minpq.push(n);
        }   
        else if(minpq.size()>maxpq.size()){
            int n=minpq.top();
            minpq.pop();
            maxpq.push(n);
        }
    }

    double findMedian() {
        if (size % 2 != 0) return maxpq.top();
        else  return (minpq.top() + maxpq.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */