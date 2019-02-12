class Date
{
private:
	int month, day, year;
public:
	//These are constructors
	Date()
    {
	    //Initialize variables.
	    month = 0, day = 0, year = 0;
    }
	Date(int, int, int);
	//Destructor 
	~Date(){}
	//void do not return values
	void setDay(int);
    int getDay() { return this.day; }
	void setMonth(int);
    int getMonth() { return this.month; }
	void setYear(int);
    int getYear() {return this.year; }
	void showDate1();
	void showDate2();
	void showDate3();
};