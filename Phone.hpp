class Phone {
public:
    //Constructors
    Phone()
    {
        areaCode = 0, exchange = 0, subscriber = 0;
        carrier = "";
    }
    ~Phone(){}

    //Member Functions
    int getAreaCode() { return this.areaCode; }
    void setAreaCode(int areaCode) { this.areaCode = areaCode; }
    int getExchange() { return this.exchange; }
    void setExchange(int exchange) { this.exchange = exchange; }
    int getSubscriber() { return this.subscriber; }
    void setSubscriber(int subscriber) { this.subscriber = subscriber; }
    string getCarrier() { return this.carrier; }
    void setCarrier(string carrier) { this.carrier = carrier; }
private:
    //Member Variables
    int areaCode, exchange, subscriber;
    string carrier;
}