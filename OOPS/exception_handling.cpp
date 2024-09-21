#include <iostream>
using namespace std;
class InvalidAmountError: public runtime_error{
    public:
    InvalidAmountError(const string &msg):runtime_error(msg){}
};
class Customer
{
    string name;
    int balance, account_number;

public:
    Customer(string name, int balance, int account_number)
    {
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    }

    void deposit(int amount)
    {
        balance += amount;
        cout << amount << "is credited successfully\n";
    }
    void withdraw(int amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << amount << "is debited successfully\n";
        }
        else
        {
            throw InvalidAmountError("your balance is low");
        }
    }
};

int main()
{
    Customer C1("subho", 5000, 123);
    try
    {
        C1.deposit(100);
        C1.withdraw(6000);
    }
    catch (const InvalidAmountError &e)
    {
        cout << "Exception occurred:" << e.what() << endl;
    }

    // try{
    //     int *p=new int[100000];
    //     cout<<"Memory allocation is successful\n";
    //     delete []p;
    // }
    // catch(const exception &e){
    //     cout<<"Exception occurred:"<<e.what()<<endl;
    // }
}