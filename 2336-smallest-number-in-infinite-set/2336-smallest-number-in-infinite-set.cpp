class SmallestInfiniteSet {
public:
    // set<int> set1;
    priority_queue<int,vector<int>, greater<int>>pq;
    int temp = 1;
    SmallestInfiniteSet() {
        // set1.clear();
        for(int i=1;i<=1000;i++){
            pq.push(i);
            // set1.insert(i);
        }
    }

    int popSmallest() {
        if(!pq.empty()){
            temp = pq.top();
            while(!pq.empty() && pq.top() == temp)
                pq.pop();
        }
        return temp;
    }

    void addBack(int num) {
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */