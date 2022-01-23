#include<bits/stdc++.h>

using namespace std;

string postToinf(string postfix);

int main(){
    cout<<"Enter the postfix expression : ";
    string postfix;
    cin>>postfix;
    cout<<"Infix expression : "<<postToinf(postfix)<<endl;

    return 0;
}
string postToinf(string postfix){
    int len=postfix.size();
    stack<string> stacky;
    for(int i=0;i<len;i++){
        if(postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^'||postfix[i]=='+'||postfix[i]=='-'){
            char op=postfix[i];
            string temp="";
            string second=stacky.top();
            stacky.pop();
            string first=stacky.top();
            stacky.pop();
            temp="("+first+op+second+")";
            stacky.push(temp);
        }
        else{
            string val="";
            val=val+postfix[i];
            //stacky.push(string(1,prefix[i]));
            stacky.push(val);
        }
    }
    return stacky.top();
}