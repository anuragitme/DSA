#include<bits/stdc++.h>

using namespace std;
string preToinf(string prefix);
int main(){
    cout<<"Enter the prefix expression : ";
    string prefix;
    cin>>prefix;
    cout<<"Infix expression : "<<preToinf(prefix)<<endl;

    return 0;
}
string preToinf(string prefix){
    reverse(prefix.begin(),prefix.end());
    int len=prefix.size();
    stack<string> stacky;
    for(int i=0;i<len;i++){
        if(prefix[i]=='*'||prefix[i]=='/'||prefix[i]=='^'||prefix[i]=='+'||prefix[i]=='-'){
            char op=prefix[i];
            string temp="";
            string first=stacky.top();
            stacky.pop();
            string second=stacky.top();
            stacky.pop();
            temp="("+first+op+second+")";
            stacky.push(temp);
        }
        else{
            string val="";
            val=val+prefix[i];
            //stacky.push(string(1,prefix[i]));
            stacky.push(val);
        }
    }
    return stacky.top();
}