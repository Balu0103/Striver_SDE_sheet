bool isBalanced(string S){
    stack<char> st;
    for(auto it:S){
        if(it=='(' || it=='{' || it=='['){
            st.push(it);
            continue;
        }
        if(st.empty()) return false;
        if((it==')' && st.top()=='(') ||
            (it=='}' && st.top()=='{') ||
            (it==']' && st.top()=='[')){
                st.pop();
            }
        else return false;
    }
    return true;
}
