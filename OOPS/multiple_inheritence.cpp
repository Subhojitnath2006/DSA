#include<iostream>
using namespace std;
class Engineer{
    public:
    string specilization;
    void work(){
        cout<<"I have specilization in:"<<specilization<<endl;
    }
};

class Youtuber
{
    public:
    int subscribers;

    void contentCreator(){
        cout<<"I have subscriber:"<<subscribers<<endl;
    }
};
class CodeTeacher: public Engineer,public Youtuber{
    public:
    string name;

    CodeTeacher(string specilization,int subscribers,string name){
        this->specilization=specilization;
        this->subscribers=subscribers;
        this->name=name;
    }

    void display(){
        cout<<"My name is:"<<name<<endl;
        work();
        contentCreator();
    }
};

int main(){
    CodeTeacher A1("cse",94357,"Subho");
    A1.display();
}