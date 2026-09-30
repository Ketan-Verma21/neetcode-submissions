class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int capacity;
    void check(int a){
        if(pq.size()>=capacity){
            if(a>=pq.top()){
                pq.pop();
                pq.push(a);
            } 
        }
        else{
            pq.push(a);
        }
    }
    KthLargest(int k, vector<int>& nums) {
        this->capacity=k;
        for(int i=0;i<nums.size();i++){
            check(nums[i]);
            // pq.push(nums[i]);
        }
        // check();
    }
    
    int add(int val) {
        check(val);
        return pq.top();
    }
};
