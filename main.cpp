#include <iostream>
#include <string>
using std::string;

//abstraction
class AbstractEmployee {
    virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee
{
private:
    string Company;
    int Age;
protected:
    string Name;
public:
    // setters
    void setName(string name)
    {
        Name = name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    void setAge(int age)
    {
        // important for validation
        if (age >= 18)
        {
            Age = age;
        }
    }
    // getters
    string getName()
    {
        return Name;
    }
    string getCompany()
    {
        return Company;
    }
    int getAge()
    {
        return Age;
    }
    // constructor
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
    // methods
    void hello()
    {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
    void AskForPromotion(){
        if(Age>30)
            std::cout << Name << " qualifies for promotion."<< std::endl;
        else
            std::cout << Name << ", sorry NO promotion." << std::endl;
    }
    virtual void Work(){
        std::cout << Name << " is checking email, tasks ... "<< std::endl;
    }
};

// inheritance
//public is used to ensure employee methods are accessible outside the class
class Developer:public Employee{
    public:
        string FavLanguage;

        Developer(string name, string company,int age, string favLanguage):Employee(name,company,age){
            FavLanguage=favLanguage;
        }
        void FixBug(){
            std::cout << Name <<" from "<<getCompany()<< " fixed bug with "<< FavLanguage << std::endl;
        }
        void Work(){
            std::cout << Name <<" is writing  "<< FavLanguage<< " code " << std::endl;
        }
};

class Teacher:public Employee{
public:
    string Subject;
    Teacher(string name,string company, int age, string subject): Employee(name,company,age){
        Subject=subject;
    }
    void PrepareLesson(){
        std::cout << Name << " is preparing " << Subject << " lesson" <<std::endl;
    }
    void Work(){
        std::cout << Name <<" is teaching  "<< Subject<< " in class now " << std::endl;
    }
};
int main()
{
    Employee emp1 = Employee("John", "dev", 23);
    // Employee emp2 = Employee("Jane", "snr dev", 33);
    Developer dev= Developer("Rich","freelance",23,"C++");
    Teacher t= Teacher("Joe","ABC",43,"Mathematics");
    // emp2.setAge(35);
    // dev.FixBug();
    // dev.AskForPromotion();
    // dev.Work();
    // t.PrepareLesson();
    // t.AskForPromotion();
    // t.Work();

    Employee* e1=&dev;
    Employee* e2=&t;
    e1->Work();
    e2->Work();

    // emp1.AskForPromotion();
    // emp2.AskForPromotion();

    // emp1.hello();

    // std::cout << emp1.getName() << " is a " << emp1.getCompany() << std::endl;
    return 0;
}
