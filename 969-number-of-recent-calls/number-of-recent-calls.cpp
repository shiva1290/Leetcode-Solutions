class RecentCounter {
public:
queue<int> rc;
    RecentCounter() {
    }
    
    int ping(int t) {
        rc.push(t);
        while(rc.front()<t-3000){
            rc.pop();
        }
        return rc.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */