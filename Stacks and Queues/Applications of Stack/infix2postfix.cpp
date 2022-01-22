#include<bits/stdc++.h>

using namespace std;

int priority(char a){
    if(a=='^')return 3;
    if(a=='*'||a=='/') return 2;
    if(a=='+'|| a=='-') return 1;
    return 0;
}
void displaystack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
string infToPost(string str){
    string postfix="";
    stack<char> convertor;
    int len=str.size();
    for(int i=0;i<len;i++){
        if(str[i]=='('){
            convertor.push(str[i]);
        }
        else if(str[i]==')'){
            while(convertor.top()!='('){
                postfix=postfix+convertor.top();
                convertor.pop();
            }
            convertor.pop();
        }
        else if(str[i]=='^'||str[i]=='*'||str[i]=='/'||str[i]=='+'|| str[i]=='-'){
            while((!convertor.empty()) && priority(convertor.top())>=priority(str[i])){
                postfix=postfix+convertor.top();
                convertor.pop();
            }
            convertor.push(str[i]);
        }
        else{
            postfix=postfix+str[i];
        }
    }
    while(!convertor.empty()){
        postfix=postfix+convertor.top();
        convertor.pop();
    }
    return postfix;


}

int evaluatePostfix(string postfix){

    stack<int> stackz;
    int len=postfix.size();
    int first,second,next;
    for(int i=0;i<len;i++){
       if(postfix[i]=='^'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='+'|| postfix[i]=='-'){
          second= stackz.top();
          stackz.pop();
          first=stackz.top();
          stackz.pop();
            if(postfix[i]=='^'){
                next=pow(first,second);
            }
            else if(postfix[i]=='*'){
                next=first*second;
            }
            else if(postfix[i]=='/'){
                next=first/second;
            }
            else if(postfix[i]=='+'){
                next=first+second;
            }
            else{
                next=first-second;
            }
          stackz.push(next);
       }
       else{
           stackz.push(postfix[i]-'0');
       }
       //displaystack(stackz);
    }

    return stackz.top();
}


int main(){
    
    cout<<"Enter the infix expression : \n";
    string infix;
    cin>>infix;

    cout<<"Postfix expression : "<<infToPost(infix)<<"\n";
    cout<<"Value of the expression is = "<<evaluatePostfix(infToPost(infix));

    return 0;
}