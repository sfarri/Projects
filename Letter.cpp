#include "Letter.hpp"

using namespace std;

Letter::Letter(string message, int estimatedDaysUntilDelivery)
{
  this.message = message;
  this.estimatedDaysUntilDelivery = estimatedDaysUntilDelivery;
}

Date Letter::deliveryDate(Date dateSent, int estimatedDaysUntilDelivery)
{

}
