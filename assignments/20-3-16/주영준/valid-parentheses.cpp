class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }
        vector<char> st;
        st.push_back(s[0]);
        for(int i = 1; i<s.length();i++){
            if(s[i] == ']'){
                if(st.empty()){
                    return false;
                }
                if(st.back() == '['){
                    st.pop_back();
                    continue;
                }
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    return false;
                }
                if(st.back() == '('){
                    st.pop_back();
                    continue;
                }
            }
            else if(s[i] == '}'){
                if(st.empty()){
                    return false;
                }
                if(st.back() == '{'){
                    st.pop_back();
                    continue;
                }
            }
            st.push_back(s[i]);
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
