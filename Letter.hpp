#ifndef LETTER_H
#define LETTER_H
#include "Date.cpp"
#include "Address.cpp"
#include "Person.hpp"

class Letter
{
  public:

  Letter()
  {
    message = "";
    estimatedDaysUntilDelivery = 5;
  }
  ~Letter(){}
  
  string getMessage() { return this.message; }
  void setMessage(string message) { this.message = message; }
  Person getSender() { return this.sender; }
  void setSender(Person sender) { this.sender = sender; }
  Person getRecipient() { return this.recipient; }
  void setRecipient(Person recipient) { this.recipient = recipient; }
  Address getSenderAddress() { return this.senderAddress; }
  void setSenderAddress(Address senderAddress) { this.senderAddress = senderAddress; }
  Address getRecipientAddress() { return this.recipientAddress; }
  void setRecipientAddress(Address recipientAddress) { this.recipientAddress = recipientAddress; }
  Date getDateSent() { return this.dateSent; }
  void setDateSent(Date dateSent) { this.dateSent = dateSent; }
  Date getDateReceived() { return this.dateReceived; }
  void setDateReceived(Date dateReceived) { this.dateReceived = dateReceived; }
  Date deliveryDate(Date dateSent, int estimatedDays);
  
  private:
  string message;
  Person sender, recipient; 
  Address senderAddress, recipientAddress;
  Date dateSent, dateReceived;
  int estimatedDaysUntilDelivery;
};

#endif