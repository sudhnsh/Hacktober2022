class MedianFinder {
public:
        priority_queue<int,vector<int>> mx;
        priority_queue<int,vector<int>,greater<int>> mn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.size()==mn.size())
        {
            if(mx.size()==0)
            {
                mx.push(num);
                return;
            }
            if(num>mx.top())
            {
                mn.push(num);
                return;
            }
            else
            {
                mx.push(num);
                return;
            }
        }
        else
        {
            if(mx.size()>mn.size())
            {
                if(num>mx.top())
                {
                    mn.push(num);
                    return;
                }
                else
                {
                    int temp=mx.top();
                    mx.pop();
                    mx.push(num);
                    mn.push(temp);
                }
            }
            if(mn.size()>mx.size())
            {
                if(num<mn.top())
                {
                    mx.push(num);
                    return;
                }
                else
                {
                    int temp=mn.top();
                    mn.pop();
                    mn.push(num);
                    mx.push(temp);
                }
            }
        }
    }
    
    double findMedian() {
        if(mn.size()==mx.size())
        {
            return (mn.top()+mx.top())/2.0;
        }
        else if(mn.size()>mx.size())
            return mn.top()/1.0;
        else
            return mx.top()/1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
