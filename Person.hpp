#include "Address.cpp"
#include "Phone.cpp"

class Person {
public:
    //Member functions
    //Constructors
    Person()
    {
        firstName = "", middleName = "", lastName = "";
        age = 0;
    }
    ~Person(){}
private:
    //Member variables
    string firstName, middleName, lastName;
    int age;
    Address address;
    Phone phone;
}