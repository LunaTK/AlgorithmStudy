class Solution {
public:
    bool isValid(string s) {
    
        vector<char> pvec;
    
        for(auto c : s) {
            switch(c) {
                case ')' :
                    if(pvec.empty() || pvec.back() != '(') return 0;
                    pvec.pop_back();
                    break;
                case ']' :
                    if(pvec.empty() || pvec.back() != '[') return 0;
                    pvec.pop_back();
                    break;
                case '}' :
                    if(pvec.empty() || pvec.back() != '{') return 0;
                    pvec.pop_back();
                    break;
                default : 
                    pvec.push_back(c);
                    break;
            }
        }
        if(pvec.empty()) return 1;
        else return 0;
    }
};
