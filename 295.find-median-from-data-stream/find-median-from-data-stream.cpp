class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int> > minn;
    priority_queue<int, vector<int>, greater<int> >maxx;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minn.size() > maxx.size())
        {
            if(num >= minn.top()) maxx.push(num);
            else
            {
                minn.push(num);
                maxx.push(minn.top());
                minn.pop();
            }
        }
        else
        {
            if(minn.empty())
            {
                minn.push(num);
                return ;
            }
            if(num >= minn.top())
            {
                
                maxx.push(num);
                minn.push(maxx.top());
                maxx.pop();
            }
            else minn.push(num);
            
        }
        
    }
    
    double findMedian() {
        if((minn.size() + maxx.size()) & 1) return minn.top();
        return (1.0 * minn.top() + maxx.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */