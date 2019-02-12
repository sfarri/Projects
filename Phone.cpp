#include "Phone.hpp"

Phone::Phone(int areaCode, int exchange, int subscriber) 
{
    this.areaCode = areaCode, this.exchange = exchange, this.subscriber = subscriber;
    carrier = "";
}

Phone::Phone(int areaCode, int exchange, int subscriber, string carrier) 
{
    this.areaCode = areaCode, this.exchange = exchange, this.subscriber = subscriber;
    this.carrier = carrier;
}