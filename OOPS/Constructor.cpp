#include <iostream>
using namespace std;
class Customer
{
private:
    string name;
    string account_number;
    int balance;
public:
    //defalut constructor
    Customer(){
        cout<<"Inside default constructor"<<endl;
    }
    //parametrized constructor
    Customer(string n,string a,int b){
        name=n;
        account_number=a;
        balance=b;
    }
    //constructor overloading
    // Customer(string name,string account_number,int balance){
    //     this->name=name;
    //     this->account_number=account_number;
    //     this->balance=balance;
    // }
    //Inline constructor
    // inline Customer(string a,string b,int c): name(a),account_number(b),balance(c){
    //     cout<<"Inside inline constructor"<<endl;
    // }
     //copy constructor
    Customer(Customer &b){
        name=b.name;
        account_number=b.account_number;
        balance=b.balance;
    }
    void display(){
        cout<<name<<" "<<account_number<<" "<<balance<<endl;
    }
};
int main()
{
    Customer A;
    Customer B("abc","12345",654);
    Customer C(A);
    A.display();
    B.display();
    C.display();
    
}