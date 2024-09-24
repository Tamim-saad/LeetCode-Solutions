class Solution {
public:
    string getbin(int n)
{
    int i=n;
    string s="",an="";

    while(i>0)
    {
        if(i%2==0) s="0"+s;
        if(i%2==1) s="1"+s;
        i=i/2;
    }

    return s;
}

long long getdec(long long n)
{
    long long ans=0,i=1;

    while(n>0)
    {
        if(n%10==1) ans+=i;
        n/=10;

        i*=2;
    }

    return ans;
}

string getstr(long long z)
{
    string x=getbin(z);
    string s;

    for(int k=0; k<x.size(); k++)
    {
        if(x[k]=='0') s=s+")";
        if(x[k]=='1') s=s+"(";
    }
    return s;
}


bool check(string s)
{
    stack<char> st;

    for(int m=0; m<s.size(); m++)
    {
        if(s[m]=='(')
        {
            st.push('(');
            continue;
        }

        if(st.empty()==true||!(s[m]==')'&& st.top()=='(')) return false;

        st.pop();
    }

    if(st.empty()==true) return true;
    else return false;
}






    vector<string> generateParenthesis(int n) {
        long long i,low=10,up=1,t=n;
        vector<string> x;

        while(n-->1) low=(low*10+1)*10;
        n=t;
        while(n-->1) up=up*10+1;
        n=t;
        while(n--) up=up*10;


        low=getdec(low);
        up=getdec(up);


        //cout<<""
        //string x="[";
        for(i=low; i<=up; i++)
        {
            string s=getstr(i);
            if(check(s)==true)
                x.push_back(s); 
                //cout<<"\""<<s<<"\""<<endl;
                //x=x+"\""+s+"\""+",";
        }
        //x.erase(x.size()-1);
        //x=x+"]";
        return x;
    }
};