class MedianFinder {
private:
    int signum(int a, int b){
        if(a == b)
            return 0;
        else if(a > b)
            return 1;
        else
            return -1;
    }
    void callMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int> > &mini, double &median){
        switch(signum(maxi.size(), mini.size())){
            case 0:
                if(element > median){
                    mini.push(element);
                    median = mini.top();
                }
                else{
                    maxi.push(element);
                    median = maxi.top();
                }
                break;
            case 1:
                if(element > median){
                    mini.push(element);
                    median = double(mini.top() + maxi.top())/2;
                }
                else{
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(element);
                    median = double(mini.top() + maxi.top())/2;
                }
                break;
            case -1:
                if(element > median){
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(element);
                    median = double(mini.top() + maxi.top())/2;
                }
                else{
                    maxi.push(element);
                    median = double(mini.top() + maxi.top())/2;
                }
                break;
        }
    }
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    double median;
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        callMedian(num, maxHeap, minHeap, median);
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */