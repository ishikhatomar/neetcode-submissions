class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMaxHeap.empty() || num <= leftMaxHeap.top())
            leftMaxHeap.push(num);
        else
            rightMinHeap.push(num);// if(num > leftMaxHeap.top())

        //Balance the size
        if(leftMaxHeap.size() > rightMinHeap.size()+1){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
        else if(leftMaxHeap.size() < rightMinHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }


    }
    
    double findMedian() {
        if(leftMaxHeap.size() > rightMinHeap.size())
            return leftMaxHeap.top();
        
        long long num1 = leftMaxHeap.top();
        long long num2 = rightMinHeap.top();
        double ans = (num1+num2)/2.0;
        return ans;
    }
};
