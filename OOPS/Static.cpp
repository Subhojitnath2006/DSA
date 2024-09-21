#include <iostream>
using namespace std;
class Customer
{
private:
    string name;
    string account_number;
    int balance;
    static int total_customers; //attribute of classes or class member
    static int total_balance;
public:
    Customer(string a,string b,int c){
        name=a;
        account_number=b;
        balance=c;
        total_customers++;
        total_balance+=balance;
    }
    
    void display(){
        cout<<"Account holders name:"<<name<<endl;
        cout<<"Account Number:"<<account_number<<endl;
        cout<<"Account Balance:"<<balance<<endl;

    }
    static void display_balance(){
        cout<<"The total balance is:"<<total_balance<<endl;
    }
    static void display_no_of_customers(){ //static member function
        cout<<"No of customers are:"<<total_customers<<endl; //only can access the static data members
    }
    void deposit(int amount){
        if(amount>0){
            balance+=amount;
            total_balance+=amount;
        }
        else{
            cout<<"Invalid Amount"<<endl;
        }
    }
    void withdraw(int amount){
        if(amount<=balance){
            balance-=amount;
            total_balance-=amount;
        }
        else{
            cout<<"Invalid Amount"<<endl;
        }
    }
};
int Customer::total_customers=0;
int Customer::total_balance=0;
int main()
{
    Customer A("abc","123",1000);
    A.display();
    Customer B("abc","123",1000);
    B.display();
    Customer C("abc","123",1000);
    C.display();
    Customer D("abc","123",1000);
    D.display();
    A.deposit(564);
    B.withdraw(986);
    Customer::display_no_of_customers();
    Customer::display_balance();
}