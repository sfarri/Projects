#include "Person.hpp"

Person::Person(string firstName, string middleName, string lastName)
{
    this.firstName = firstName, this.middleName = middleName, this.lastName = lastName;
    age = 0;
}

Person::Person(string firstName, string middleName, string lastName, int age)
{
    this.firstName = firstName, this.middleName = middleName, this.lastName = lastName;
    this.age = age;
}