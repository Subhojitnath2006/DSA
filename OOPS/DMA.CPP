#include <iostream>
using namespace std;
class Student
{
public:
    string name;
    int roll;
    int age;
    string grade;
};
int main()
{
    Student *s1 = new Student; //dynamic memory allocation
    (*s1).name = "Subhojit";
    (*s1).roll = 19;
    (*s1).age = 19;
    (*s1).grade = "A+";
    s1->name = "Subhojit";
    cout << (*s1).name << endl;
    cout << (*s1).roll << endl;
    cout << (*s1).age << endl;
    cout << (*s1).grade << endl;
}