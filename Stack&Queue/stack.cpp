#include<bits/stdc++.h>
using namespace std;
int Stack[10];

int push(int size,int top){
    int item;
    cout<<"enter item to insert: ";
    cin>>item;
    if(top==size-1) cout<<"Overflow Detected";
    else{
        top=top+1;
        Stack[top]=item;
        cout<<Stack[top]<<" is inserted into stack";
    }
    cout<<endl;
    return top;
}
int pop(int top){
    if(top==-1) cout<<"Stack is empty";
    else{
        int item=Stack[top];
        top=top-1;
        cout<<item<<" is popped from stack";
    }
    cout<<endl;
    return top;
}
int topf(int top){
    if(top==-1) cout<<"Stack is empty";
    else{
        cout<<Stack[top]<<" is the top element";
    }
    cout<<endl;
    return top;
}
int display(int top){
    if(top==-1) cout<<"Stack is empty";
    else{
        cout<<"Stack is:";
        for(int i=0;i<top;i++){
            cout<<Stack[i]<<" ";
        }
    }
    cout<<endl;
    return top;
}
int menu(){
    cout<<"Enter 1 for push,2 for pop,3 for top,4 for display";
    cout<<endl;
    int choice;
    cout<<"Enter your choice: ";
    cin>>choice;
    return choice;
}
int main(){
    int size;
    cout<<"enter size of the stack: ";
    cin>>size;
    int top=-1;
    while(true){
        int choice=menu();
        switch(choice){
            case 1: push(size,top);
                    break;
            case 2: pop(top);
                    break;
            case 3: topf(top);
                    break;
            case 4: display(top);
                    break;
            default: printf("enter valid choice.");

        }
    }
    return 0;
}