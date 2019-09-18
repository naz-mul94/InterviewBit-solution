stack<int> st;
stack<int> st_min;
MinStack::MinStack() {
    while(!st.empty())
    st.pop();
    while(!st_min.empty())
    st_min.pop();
}

void MinStack::push(int x) {
    st.push(x);
    if(st_min.empty())st_min.push(x);
    else
    {
        if(x<=st_min.top())st_min.push(x);
    }
}

void MinStack::pop() {
    if(!st.empty())
    {
        int x=st.top();
        st.pop();
        if(x==st_min.top())st_min.pop();
    }
    
}

int MinStack::top() {
    if(st.empty())return -1;
    return st.top();
}

int MinStack::getMin() {
    if(st.empty())return -1;
    return st_min.top();
}

