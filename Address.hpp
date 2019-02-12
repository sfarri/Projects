class Address {
public:
    //Constructors
    Address()
    {
        houseNumber = 0;
        street = "", city = "", state = "", country = "";
    }
    ~Address(){}

    //Member functions
    int getHouseNumber() { return this.houseNumber; }
    void setHouseNumber(int houseNumber) { this.houseNumber = houseNumber; }

private:
    //Member variables
    int houseNumber;
    string street, city, state, country;
    
}