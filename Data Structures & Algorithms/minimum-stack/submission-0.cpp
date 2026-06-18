class MinStack {
public:
stack<int>st;
stack<int>minSt;
    MinStack() {
        }
    
    void push(int val) {
        if(minSt.empty() ||val<=minSt.top()){
            st.push(val);
            minSt.push(val);
        }
        else{
            st.push(val);
        }
       
        
    }
    
    void pop() {
        if(st.top()==minSt.top()){
            st.pop();
            minSt.pop();
        }
        else{
            st.pop();
        }
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return minSt.top();
        
    }
};
