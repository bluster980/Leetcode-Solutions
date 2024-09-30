class CustomStack {
public:
    vector<int> custom;
    int length;
    int max_size;
    CustomStack(int maxSize) {
        custom.resize(maxSize, 0);
        length = 0;
        max_size = maxSize;
    }
    
    void push(int x) {
        if(length < max_size) 
        {
            custom[length]=x;
            length++;
        }

    }
    
    int pop() {
        if(length == 0) {return -1;}
        else{
            length--;
            return custom[length];
        }
    }
    
    void increment(int k, int val) {
        int p = 0;
        while(p<length  && k>0){
            custom[p] += val;
            ++p;
            --k;
        }
    }
};
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */