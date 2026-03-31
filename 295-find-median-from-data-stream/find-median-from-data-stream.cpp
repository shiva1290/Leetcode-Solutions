class MedianFinder {
public:
    priority_queue<double> maxPq;
    priority_queue<double, vector<double>, greater<double>> minPq;
    int size = 0;
    MedianFinder() {}

    void addNum(int num) {
        size++;
        if (maxPq.empty()) {
            maxPq.push(num);
            return;
        }
        if (!maxPq.empty()) {
            if (num <= maxPq.top()) {
                maxPq.push(num);
            }
            else minPq.push(num);
        }

        if (!maxPq.empty() && maxPq.size() > minPq.size()+1) {
            minPq.push(maxPq.top());
            maxPq.pop();
        }
        if(!minPq.empty() && minPq.size()>maxPq.size()){
            maxPq.push(minPq.top());
            minPq.pop();
        }
    }

    double findMedian() {
        if (size % 2 == 0) {
            return (maxPq.top() + minPq.top()) / 2.0;
        } else
            return maxPq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */