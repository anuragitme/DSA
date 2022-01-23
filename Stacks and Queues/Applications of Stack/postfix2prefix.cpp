#include<bits/stdc++.h>

using namespace std;
string posTopre(string prefix);
int main(){
    cout<<"Enter the postfix expression : ";
    string postfix;
    cin>>postfix;
    cout<<"Prefix expression : "<<posTopre(postfix)<<endl;

    return 0;
}
string posTopre(string postfix){
    
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
            temp=op+first+second;
            stacky.push(temp);
        }
        else{
            string val="";
            val=val+postfix[i];
            //stacky.push(string(1,postfix[i]));
            stacky.push(val);
        }
    }
    return stacky.top();
}