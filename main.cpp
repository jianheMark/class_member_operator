#include <iostream>
#include <string>

class Employee{
private:
    int age;
public:
    std::string name;
    Employee(int _age, std::string _name)
        :age(_age), name(std::move(_name)) {}

    void DoSomething() {
        std::cout<< age<<'\n';
    }
    static void DisplayAge(const Employee& emp) {
        std::cout<<emp.age<<'\n';
    }
};

std::string Races[] = {
        "Demon",
        "Human",
        "ELf",
        "Orc",
        "Aliens"
};

struct User {
    unsigned int RaceID;
    std::string Race;
    explicit User(unsigned int rid) //struct construct with one argument.
    : RaceID(rid)   //RaceID will be the assign during construction.
    ,Race(Races[rid]) //Inner container access element then assign.
            {} //empty constructor. can construct with Nothing.
};


int main() {
    User user(3);
    std::cout<<user.Race<<'\n';


    /*
     * a::b is only used if b is a member of the class (or namespace) a.
     * That is, in this case a will always be the name of a class (or namespace).
     */
    Employee Emp1(12, "alison");
    std::cout<<"directly dot operator: "<<Emp1.name<<'\n';

    //use Pointer operator (->).
     Employee* Emp2 = new Employee(24,"lane");
     std::cout<<"pointer operator: "<<Emp2 -> name<<'\n'; //member attributes access.

    //deferening member attributes access.
     std::cout<<"deference access: "<<(*Emp2).name<<'\n';

     //deference accessing member function.
    std::cout<<"using deferencing to access member function ";
    (*Emp2).DoSomething();

    //Double Colon to member access.
    //error: invalid use of non-static data member 'Employee::name'
    std::cout<<"class then access static member function ";
    Employee::DisplayAge(Emp1);

    delete(Emp2);


    return 0;
}
