#include <iostream>
using namespace std;
class Customer
{
private:
    string name;
    string account_number;
    int balance;
public:
    
    void display(){
        cout<<name<<" "<<account_number<<" "<<balance<<endl;
    }
};
int main()
{
    
}