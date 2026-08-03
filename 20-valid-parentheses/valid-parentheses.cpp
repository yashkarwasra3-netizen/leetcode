class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st1;   
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] =='[' || s[i] =='{'){
                st1.push(s[i]);
            }
           else{
                if(st1.empty()) return false;
                char top = st1.top();
                st1.pop();
                if(s[i] == ')' && top != '(') return false;
                else if(s[i] =='}' && top != '{') return false;
                else if(s[i] == ']' && top != '[') return false;
           }
        }
        return st1.empty();
    }
};