class MedianFinder {
public:
    priority_queue<int> min_heap;
    priority_queue<int,vector<int>, greater<int>> max_heap;
    MedianFinder() {
        while(!min_heap.empty()){
            min_heap.pop();
        }
        while(!max_heap.empty()){
            max_heap.pop();
        }
    }
    void check(){
        if(min_heap.size()<max_heap.size()){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size()-max_heap.size()>1){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        return;
    }
    void addNum(int num) {
        if(min_heap.empty()){
            min_heap.push(num);
            return;
        }
        else{
            if(num<min_heap.top()){
                min_heap.push(num);
                check();
            }
            else{
                max_heap.push(num);
                check();
            }
            return;
        }
    }
    
    double findMedian() {
        double ans;
        if(min_heap.size()==max_heap.size() && !max_heap.empty()){
            return (min_heap.top()+max_heap.top())/2.0;
        }
        else{
            return min_heap.top()*1.0;
        }
    }
};
