#include<bits/stdc++.h>

using namespace std;

string infToPre(string infix);
int priority(char a);
int evaluatePrefix(string prefix);

int main(){
    string infix;
    cout<<"Enter infix expression :\n";
    cin>>infix;
    cout<<"Prefix expression : "<<infToPre(infix)<<"\n";
    cout<<"Value of this expression : "<<evaluatePrefix(infToPre(infix))<<"\n";

    return 0;
}

string infToPre(string infix){
    reverse(infix.begin(),infix.end());
    int len=infix.size();
    stack<char> convertor;
    string prefix="";
    for(int i=0;i<len;i++){
        if(infix[i]==')'){
            convertor.push(infix[i]);
        }
        else if(infix[i]=='('){
            while(convertor.top()!=')'){
                prefix+=convertor.top();
                convertor.pop();
            }
            convertor.pop();
        }
        else if(infix[i]=='^'||infix[i]=='*'||infix[i]=='/'||infix[i]=='+'||infix[i]=='-'){
            while(!convertor.empty() && priority(infix[i])<priority(convertor.top())){
                prefix+=convertor.top();
                convertor.pop();
            }
            convertor.push(infix[i]);
        }
        else{
            prefix+=infix[i];
        }
    }
    while(!convertor.empty()){
        prefix+=convertor.top();
        convertor.pop();
    }
    reverse(prefix.begin(),prefix.end());
    return prefix;
}
int priority(char a){
    if(a=='^')return 3;
    if(a=='*'||a=='/') return 2;
    if(a=='+'|| a=='-') return 1;
    return 0;
}
int evaluatePrefix(string prefix){
    reverse(prefix.begin(),prefix.end());
    int len=prefix.size();
    stack<int> mystack;
    int second,first,next;
    for(int i=0;i<len;i++){
        if(prefix[i]=='^'||prefix[i]=='*'||prefix[i]=='/'||prefix[i]=='+'||prefix[i]=='-'){
            first=mystack.top();
            mystack.pop();
            second=mystack.top();
            mystack.pop();
            switch(prefix[i]){
                case '^': 
                    next=pow(first,second);
                    break;
                case '*':
                    next=first*second;
                    break;
                case '/':
                    next=first/second;
                    break;
                case '+':
                    next=first+second;
                    break;
                case '-':
                    next=first-second;
                    break;
            }
            mystack.push(next);
        }
        else{
            mystack.push(prefix[i]-'0');
        }
    }
    return mystack.top();
}