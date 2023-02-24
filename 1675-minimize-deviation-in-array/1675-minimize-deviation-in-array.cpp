class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> heap;
        int minval = INT_MAX, deviation = INT_MAX;
        for(auto p : nums){
            p = p%2? 2*p : p;
            heap.push(p);
            minval=min(minval, p);
        }
        while(true){
            deviation = min(deviation, heap.top()-minval);
            int top = heap.top();
            heap.pop();
            if(top%2)break;
            top /=2;
            minval = min(minval, top);
            heap.push(top);
        }
        return deviation;
   }
};