#include<iostream>
using namespace std;
class person{
    protected:
    string name;
    public:
    void introduce(){
        cout<<"Hello my name is:"<<name<<endl;
    }
};

class employee:public person{
    protected:
    int salary;
    public:
    void monthly_salary(){
        cout<<"My monthly salary is:"<<monthly_salary<<endl;
    }
};

class manager:public employee{
    public:
    string department;

    manager(string name,int salary,string department){
        this->name=name;
        this->salary=salary;
        this->department=department;
    }

    void work(){
        cout<<"I am leading the department"<<department<<endl;
    }
};
int main(){

    manager A1("subho",200,"finance");
    A1.introduce();
    A1.monthly_salary();
    A1.work();
    return 0;
}

