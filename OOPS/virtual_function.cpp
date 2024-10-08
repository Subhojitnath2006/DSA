#include <iostream>
#include <vector>
using namespace std;
class Animal
{
public:
    virtual void speak()
    {
        cout << "Hu hu" << endl;
    }
    //virtual void speak()=0; pure virtual function
    //abstract class-->we cant directly create a object of animal class
    
};
class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Bark\n";
    }
};
class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Meow\n";
    }
};
int main()
{
    Animal *p;
    vector<Animal *> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Animal());
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    for (int i = 0; i < animals.size(); i++)
    {
        p = animals[i];
        p->speak();
    }
}