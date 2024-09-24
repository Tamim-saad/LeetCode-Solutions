class Solution {
public:
    bool isValid(string s) {
         stack<char> st;

    for(int m=0; m<s.size(); m++)
    {
        if(s[m]=='(')  st.push('(');
        if(s[m]=='{')  st.push('{');
        if(s[m]=='[')  st.push('[');

        if(s[m]=='('||s[m]=='{'||s[m]=='[') continue;


        if(st.empty()==true) return false;

        char c=st.top();
        if(!((s[m]==')'&& c=='(')||(s[m]=='}'&& c=='{')||(s[m]==']'&& c=='['))) return false;
        st.pop();

    }

    if(st.empty()==true) return true;
    else return false;
    }
    
};