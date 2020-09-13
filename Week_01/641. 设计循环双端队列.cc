class MyCircularDeque {
private:
    int front_; // 头
    int back_; // 尾
    int nSize_; // 存储数量
    int nCapSize_; // 总大小
    int* nArray_; // 数组
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        front_ = 0;
        back_ = 0;
        nSize_ = 0;
        nCapSize_ = k;
        nArray_ = new int[k];
    }
    ~MyCircularDeque() {
        front_ = 0;
        back_ = 0;
        nSize_ = 0;
        nCapSize_ = 0;
        delete [] nArray_;
        nArray_ = nullptr;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(nSize_ == nCapSize_)
        {
            return false;
        }
        if(nSize_ != 0)
        {
            front_ = --front_<0?front_+nCapSize_:front_;
        }
        nArray_[front_] = value;
        ++nSize_;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(nSize_ == nCapSize_)
        {
            return false;
        }
        if(nSize_ != 0)
        {
            back_ = ++back_ % nCapSize_;
        }
        nArray_[back_] = value;
        ++nSize_;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(nSize_ == 0)
        {
            return false;
        }
        if(nSize_ != 1)
        {
            front_ = ++front_ % nCapSize_;
        }
        --nSize_;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(nSize_ == 0)
        {
            return false;
        }
        if(nSize_ != 1)
        {
            back_ = --back_ < 0? back_ + nCapSize_:back_;
        }
        
        --nSize_;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() 
    {
        if(nSize_ == 0)
        {
            return -1;
        }
        return nArray_[front_];
    }
    
    /** Get the last item from the deque. */
    int getRear() 
    {
        if(nSize_ == 0)
        {
            return -1;
        }
        return nArray_[back_];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return nSize_ == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return nSize_ == nCapSize_;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */