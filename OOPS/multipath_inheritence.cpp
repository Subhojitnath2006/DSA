#include<iostream>
using namespace std;
class Human{
    public:
    string name;
    void display(){
        cout<<"My name is : "<<name<<endl;
    }
};
class Engineer: public virtual Human{
    public:
    string specilization;
    void work(){
        cout<<"I have specilization in:"<<specilization<<endl;
    }
};

class Youtuber: public virtual Human
{
    public:
    int subscribers;

    void contentCreator(){
        cout<<"I have subscriber:"<<subscribers<<endl;
    }
};
class CodeTeacher: public Engineer,public Youtuber{
    public:
    int salary;
    CodeTeacher(string specilization,int subscribers,string name,int salary){
        this->specilization=specilization;
        this->subscribers=subscribers;
        this->name=name;
        this->salary=salary;
    }
};

int main(){
    CodeTeacher A1("cse",94357,"Subho",1000);
    A1.display();
    
}