#include<bits/stdc++.h>

using namespace std;

int evalInfix(string infix);
int solver(int a,int b,char c);
int priority(char a);
void displaystack(stack<int> s);
void displaystackop(stack<char> s);

int main(){
    string infix;
    cout<<"Enter infix expression : ";
    getline(cin, infix);//space sepearated string;
    cout<<"Value of this expression : "<<evalInfix(infix)<<endl;
    

    return 0;
}
int evalInfix(string str){
    stack<int> num;
    stack<char> op;
    int len=str.size();
    for(int i=0;i<len;i++){
        if(str[i]==' '){
            continue;
        }
        else if(str[i]==')'){
            while(op.top()!='('){
                int n2=num.top();
                num.pop();
                int n1=num.top();
                num.pop();
                num.push(solver(n1,n2,op.top()));
                op.pop();
            }
            op.pop();
        }
        else if(str[i]=='('){
            op.push(str[i]);
        }
        else if(str[i]=='^'||str[i]=='*'||str[i]=='/'||str[i]=='+'||str[i]=='-'){
            while(!op.empty() && priority(str[i])<=priority(op.top())){
                int n2=num.top();
                num.pop();
                int n1=num.top();
                num.pop();
                num.push(solver(n1,n2,op.top()));
                op.pop();
            }
            op.push(str[i]);
        }
        else{
            int val=0;
            while(i<len && isdigit(str[i])){
                val=val*10+str[i]-'0';
                i++;
            }
            i--;
            num.push(val);
        }

    }
    //displaystack(num);
   // displaystackop(op);
   // cout<<endl;
    while(!op.empty()){
        int n2=num.top();
        num.pop();
        int n1=num.top();
        num.pop();
        num.push(solver(n1,n2,op.top()));
        op.pop();
    }

    return num.top();
}
int solver(int a,int b,char c){
    int ans=0;
    if(c=='+'){
        ans=a+b;
    }
    else if(c=='-'){
        ans=a-b;
    }
    else if(c=='/'){
        ans=a/b;
    }
    else if(c=='*'){
        ans=a*b;
    }
    else if(c=='^'){
        ans=pow(a,b);
    }
    return ans;

}
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
void displaystackop(stack<char> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}