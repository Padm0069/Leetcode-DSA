class MyStack {
public:
    queue<int> q1;
    /** Push element x onto stack. */
void push(int x) {
    q1.push(x);        //bitchass queue bruh
}

/** Removes the element on top of the stack and returns that element. */
int pop() {
    int len = q1.size();
    for(int i = 0; i < len - 1; i++) {
        int tmp = q1.front();
        q1.pop();
        q1.push(tmp);
    }
    int res = q1.front();
    q1.pop();
    
    return res;
}

/** Get the top element. */
int top() {
    return q1.back();
}

/** Returns whether the stack is empty. */
bool empty() {
    return !q1.size()?true:false;
}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */