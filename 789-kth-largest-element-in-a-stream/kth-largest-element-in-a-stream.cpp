class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int s;
    KthLargest(int k, vector<int>& nums) {
        s = k;
        for (auto num : nums) {
            pq.push(num);
            while (pq.size() > s) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        while (pq.size() > s) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */