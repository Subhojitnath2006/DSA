#include<iostream>
using namespace std;
//student
//boy
//girl
//male
//female

class student{
    public:
    void print(){
        cout<<"I ma student\n";
    }
};
class Male{
    public:
    void malePrint(){
        cout<<"I am male\n";
    }
};
class Female{
    public:
    void femalePrint(){
        cout<<"I am female\n";
    }
};

class boy:public student,public Male{
    public:
    void boyPrint(){
        cout<<"I am boy\n";
    }
};
class girl:public student,public Female{
    public:
    void girlPrint(){
        cout<<"I am girl\n";
    }
};
int main(){
    girl G1;
    G1.girlPrint();
    G1.print();
    G1.femalePrint();

    boy B1;
    B1.print();
    B1.boyPrint();
    B1.malePrint();
}