#include "Date.h"
class Reservation
{
      private:
              char *customerName_Surname;
              char *customerAddress;
              char *customerCreditCardNumber;
              char *customerPhoneNumber;
              
              Date reservationDoneDate; //In this date reservation has been done.
              Date reservationBeginDate; //In this date reservation will begin.
              Date reservationEndDate; //In this date reservation will be ended.
              
              int reservationSequence;
              
              bool isReservationCanceled;
              bool isCheckedIn;
              bool isCheckedOut;
              
               //which services this reservation has gotten
              int numberOfGotServices;
              
              double payment;
              
      public:
             int *gotServices;
             Reservation();
             
             void setCustomerName_Surname(char *_customerName_Surname);
             void setCustomerAddress(char *_customerAddress);
             void setCustomerCreditCardNumber(char *_customerCreditCardNumber);
             void setCustomerPhoneNumber(char *_customerPhoneNumber);
             
             void setReservationBeginDate(Date _reservationBeginDate);
             void setReservationEndDate(Date _reservationEndDate);
             
             void setPayment(double _payment);
             double getPayment();
             
             char *getCustomerName_Surname();
             char *getCustomerAddress();
             char *getCustomerCreditCardNumber();
             char *getCustomerPhoneNumber();
             
             Date getReservationBeginDate();
             Date getReservationEndDate();
             
             void setReservationSequence(int _reservationSequence);
             int getReservationSequence();
             
             void addServices(int _serviceSequence);
             
             bool getCancelationInfo();
             void setCancelationInfo(bool _isReservationCanceled ){isReservationCanceled = _isReservationCanceled; };

             bool getCheckInInfo(){return isCheckedIn;};
             void setCheckInInfo(bool _isCheckedIn ){ isCheckedIn = _isCheckedIn; };            
           
             bool getCheckOutInfo(){return isCheckedOut;};
             void setCheckOutInfo(bool _isCheckedOut ){ isCheckedOut = _isCheckedOut; };            
             
             int getNumberOfMadeReservation(){ return numberOfGotServices; };
             
      };
Reservation::Reservation()
{
 isCheckedIn = false;
 isCheckedOut = false;
 isReservationCanceled = false; 
 payment = 0.0;                
 numberOfGotServices = 0;       
                           };

void Reservation::setCustomerName_Surname(char *_customerName_Surname)
{
     customerName_Surname = new char[strlen(_customerName_Surname)+1];
     strcpy(customerName_Surname , _customerName_Surname);
     };
void Reservation::setCustomerAddress(char *_customerAddress)
{
     customerAddress  = new char[strlen(_customerAddress)+1];
     strcpy(customerAddress , _customerAddress);
     };
void Reservation::setCustomerCreditCardNumber(char *_customerCreditCardNumber)
{
     customerCreditCardNumber = new char[strlen(_customerCreditCardNumber)+1];
     strcpy(customerCreditCardNumber , _customerCreditCardNumber);
     };
void Reservation::setCustomerPhoneNumber(char *_customerPhoneNumber)
{
     customerPhoneNumber = new char[strlen(_customerPhoneNumber)+1];
     strcpy( customerPhoneNumber , _customerPhoneNumber);
     };

void Reservation::setReservationBeginDate(Date _reservationBeginDate)
{
     reservationBeginDate = _reservationBeginDate;
     };
void Reservation::setReservationEndDate(Date _reservationEndDate)
{
     reservationEndDate = _reservationEndDate;
     };
     
char *Reservation::getCustomerName_Surname()
{
     return customerName_Surname;
     };
char *Reservation::getCustomerAddress()
{
     return customerAddress;
     };
char *Reservation::getCustomerCreditCardNumber()
{
     return customerCreditCardNumber;
     };
char *Reservation::getCustomerPhoneNumber()
{
     return customerPhoneNumber;
     };
Date Reservation::getReservationBeginDate(){return reservationBeginDate; };
Date Reservation::getReservationEndDate(){return reservationEndDate; };
     
void Reservation::setReservationSequence(int _reservationSequence){reservationSequence = _reservationSequence;};
int Reservation::getReservationSequence(){ return reservationSequence;};

void Reservation::setPayment(double _payment){payment = _payment;};
double Reservation::getPayment(){return payment;};

bool Reservation::getCancelationInfo(){return isReservationCanceled;};

void Reservation::addServices(int _serviceSequence)
{
     numberOfGotServices++;
     if(numberOfGotServices == 1) gotServices = new int[1];
     else
     {
         int *tempGotServices = new int[numberOfGotServices];
         tempGotServices = gotServices;
         gotServices = new int[numberOfGotServices];
         gotServices = tempGotServices;
         };
         gotServices[numberOfGotServices-1] = _serviceSequence;
     };
