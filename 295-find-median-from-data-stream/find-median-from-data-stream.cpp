class MedianFinder {
public:
priority_queue<double> maxPq;
priority_queue<double,vector<double>,greater<double>> minPq;
int size=0;
    MedianFinder() {
    }

    void addNum(int num) {
        if(maxPq.size()==0 || maxPq.top()>num){
        maxPq.push(num);
        }
        else minPq.push(num);
        if(!maxPq.empty() && maxPq.size()>minPq.size()+1){
            double n=maxPq.top();
            maxPq.pop();
            minPq.push(n);
        }
        if(!minPq.empty() && minPq.size()>maxPq.size()){
            double n=minPq.top();
            minPq.pop();
            maxPq.push(n);
        }
        size++;
    }
    
    double findMedian() {
        if(size%2==0) return (minPq.top()+maxPq.top())/2.0;
        else return maxPq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */