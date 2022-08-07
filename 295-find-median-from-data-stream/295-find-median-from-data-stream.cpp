class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (minHeap.empty() or num >= minHeap.top()) {
            minHeap.push(num);
            if (minHeap.size() > maxHeap.size()+1) {
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
            }
        }
        else {
            maxHeap.push(num);
            if (maxHeap.size() > minHeap.size()) {
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
            }
        }
    }
    
    double findMedian() {
        double ans = 0;
        if ((maxHeap.size() + minHeap.size()) % 2 == 0) {
            ans = ((double)minHeap.top() + (double)maxHeap.top())/2;
        }
        else {
            ans = (double)minHeap.top();
        }
        
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */