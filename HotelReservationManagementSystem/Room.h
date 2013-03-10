#include "Reservation.h"
class Room
{
      private:
              
              int stairNumber;//this shows the stair number, that this room is inside.
              int sortOfRoom; //this shows which sort of room is. king, suit, luxury, standard
              int sequenceNumber; //It shows the sequence, in that stair
              
              int thisRoomNumber; // A _00B_ C  ; A stair number, B, sequence number, C is sort of room
              int numberOfMadeReservations;
              
              
      public:
             int *forStatisticInfos;
             
             Room();
             ~Room();
             
             Reservation *reservations; //each room has its reservation schedule, for each 
             
             void setStairNumber(int _stairNumber);
             void setSortOfRoom(int _sortOfRoom);
             void setSequenceNumber(int _sequenceNumber);
             void setNumberOfMadeReservations(int _numberOfMadeReservations) {numberOfMadeReservations = _numberOfMadeReservations;};
             
             int getStairNumber();
             int getSortOfRoom();
             int getSequenceNumber();
             int getThisRoomNumber();
             
             static int getStairNumber(int _roomNumber){return (_roomNumber/10000);};
             static int getSortOfRoom(int _roomNumber){return (_roomNumber-(_roomNumber/10)*10);};
             static int getSequenceNumber(int _roomNumber){return ((_roomNumber-((_roomNumber/10000)*10000))/10); };
             
             int generateRoomNumber(int _stairNumber, int _sequenceNumber, int _sortOfRoom);
             
             void registerNewReservation(char *_customerName_Surname,char *_customerAddress,char *_customerCreditCardNumber,char *_customerPhoneNumber,Date _reservationBeginDate,Date _reservationEndDate, double _roomDailyPrice);
      
             double cancelPreviousReservation(Date _reservationBeginDate);
             
             int searchForReservation(Date _reservationBeginDate);
             
             int checkIn(char * _customerName_Surname);
             
             int checkOut(char *_customerName_Surname, int & reservationSequence);
             
             int searchAccordingToTheName(char *_customerName_Surname);
             
             bool isItFree(Date _reservationBeginDate, Date _reservationEndDate);
             
             int makeService(int _serviceId);
      };

Room::Room()
{
            
            numberOfMadeReservations = 0;
            forStatisticInfos = new int[1];
            };
Room::~Room()
{
             delete [] reservations;
             };

void Room::setStairNumber(int _stairNumber){stairNumber = _stairNumber;};
void Room::setSortOfRoom(int _sortOfRoom){sortOfRoom = _sortOfRoom;};
void Room::setSequenceNumber(int _sequenceNumber){sequenceNumber = _sequenceNumber;};

int Room::getStairNumber(){return stairNumber;};
int Room::getSortOfRoom(){return sortOfRoom;};
int Room::getSequenceNumber(){return sequenceNumber;};
int Room::getThisRoomNumber(){return thisRoomNumber;};

int Room::generateRoomNumber(int _stairNumber, int _sequenceNumber, int _sortOfRoom)
{
    if(_sequenceNumber<1000 && _sequenceNumber>0)
    {
           thisRoomNumber =  ((_stairNumber*10000)+(_sequenceNumber*10)+_sortOfRoom);           
           return thisRoomNumber;
           }
           else 
           {
                cout<<endl<<_sequenceNumber;
                 cout<<endl<<"Error: Each stair can have max. 999 room.";
                 return 0;
                 };
    };
    
void Room::registerNewReservation(char *_customerName_Surname,char *_customerAddress,char *_customerCreditCardNumber,char *_customerPhoneNumber,Date _reservationBeginDate,Date _reservationEndDate, double _roomDailyPrice)
{
     numberOfMadeReservations++; //at the beginning, it will be 1
     if(numberOfMadeReservations == 1) reservations = new Reservation[2];
     else
     {
         Reservation *tempReservations= new Reservation[numberOfMadeReservations];
         tempReservations = reservations;
         reservations = new Reservation[numberOfMadeReservations];
         reservations = tempReservations;
         };
     reservations[numberOfMadeReservations-1].setCustomerName_Surname(_customerName_Surname);
     reservations[numberOfMadeReservations-1].setCustomerAddress(_customerAddress);
     //cout<<endl<<"deneme: adres"<<reservations[numberOfMadeReservations-1].getCustomerAddress();
     reservations[numberOfMadeReservations-1].setCustomerCreditCardNumber(_customerCreditCardNumber);
     reservations[numberOfMadeReservations-1].setCustomerPhoneNumber(_customerPhoneNumber);
     reservations[numberOfMadeReservations-1].setReservationBeginDate(_reservationBeginDate);
     reservations[numberOfMadeReservations-1].setReservationEndDate(_reservationEndDate);
     reservations[numberOfMadeReservations-1].setReservationSequence(numberOfMadeReservations);
     
     //cout<<endl<<"deneme: ad soyad"<<reservations[numberOfMadeReservations-1].getCustomerName_Surname();
     //cout<<endl<<"res sirasi"<<reservations[numberOfMadeReservations-1].getReservationSequence();
     
     //cout<<endl<<"deneme: ad soyad"<<reservations[0].getCustomerName_Surname();     
     
     double roomPayment = ((_reservationEndDate - _reservationBeginDate)*_roomDailyPrice);
     reservations[numberOfMadeReservations-1].setPayment(roomPayment);
     //cout<<endl<<" room class ROOM PAYMENT IS : "<<roomPayment;
      //cout<<endl<<" room class ROOM DAILY PRICE IS : "<<_roomDailyPrice;
     getch();
     
     };

int Room::searchForReservation(Date _reservationBeginDate)
{
     bool foundLogic = false;
     for(int ctr=0;ctr<numberOfMadeReservations;ctr++)
     {
                 Date beginDate = reservations[ctr].getReservationBeginDate();
                 //Date endDate = reservations[ctr].getReservationEndDate();
                 if(beginDate == _reservationBeginDate) 
                 {
                              Date begin = reservations[ctr].getReservationBeginDate();
                              //Date end = reservations[ctr].getReservationEndDate();
                              int a;
                              a = reservations[ctr].getReservationSequence();
                              return ctr+1;        
                              foundLogic = true;
                              };
                 };
     if(foundLogic == false) return 0;
     };
     
double Room::cancelPreviousReservation(Date _reservationBeginDate)
{
     int reservationOrder = searchForReservation(_reservationBeginDate);
     if(reservationOrder!=0 && ((reservations[reservationOrder-1].getCancelationInfo())!= true))
     {
          if((reservations[reservationOrder-1].getCheckInInfo())!= true )
          {          
              if((reservations[reservationOrder-1].getCheckOutInfo())!= true )
              {
                                                                   
          Date today2;
          int  remainDay = _reservationBeginDate - today2;
         // cout<<endl<<"in room class today: "<<today;
         //  cout<<endl<<"in room class _reservationBeginDate: "<<_reservationBeginDate;
      
                 if(remainDay<4)
                 {
                                
                       double payment = reservations[reservationOrder-1].getPayment();
                     //  cout<<endl<<"in room class remainDay:"<<remainDay;
                       payment = payment - ((payment/4)*remainDay);
                       reservations[reservationOrder-1].setCancelationInfo(true);
                       //"Customer should pay some money.";
                     //  cout<<endl<<"in room class:  payment"<<payment;
                       return payment;
                       }
                       else 
                       {
                            //cout<<endl<<endl<<"remainDay : "<<remainDay;
                          reservations[reservationOrder-1].setCancelationInfo(true);
                          //reservation canceled
                          return 0;
                          }
                      /////////////FOR STATISTIC INFOS - 1's IS MAKING 0
                      Date today;
                       int year = today.getYear();
                       Date newYear(1,1,year);
                       Date _reservationEndDate;
                       _reservationEndDate = reservations[reservationOrder-1].getReservationEndDate();
                       
                       int dayFromTheBeginning = 0;
                       dayFromTheBeginning = _reservationBeginDate - newYear;
                       while(_reservationBeginDate != _reservationEndDate)
                       {
                                                   dayFromTheBeginning++;
                                                   forStatisticInfos[dayFromTheBeginning] = 0;
                                                   _reservationBeginDate++;
                                                   };
                      /////////////////////////////////////////////////////                          
                     
                     
                      }return (-3); //reservation checked out before
               } return (-2);//reservation checked in
         }
     else {  return (-1); }; //that reservation could not find.
     };
     
int Room::checkIn(char * _customerName_Surname)
{
     Date today;
             int customerSequence = searchAccordingToTheName(_customerName_Surname);
             //cout<<endl<<"customer sequence: "<<customerSequence;
             if(customerSequence)
             {
                       Date reservationBeginDate = reservations[customerSequence-1].getReservationBeginDate();
                       Date reservationEndDate = reservations[customerSequence-1].getReservationEndDate();
                       
                       if(reservationBeginDate<=today && reservationEndDate>today)  
                       {
                                                      if(reservations[customerSequence-1].getCheckOutInfo() == false)
                                                      {
                                                              reservations[customerSequence-1].setCheckInInfo(true);  
                                                              return 1;  //cout<<endl<<"You checked in";                                           
                                                              }
                                   return -2; //you checked out before
                                  };                              
                         //cout<<endl<<"Error: Your reservation does not include this day...";  
                         return -1;                                                                 
                        };
           //cout<<endl<<"There is no reservation that includes today.";
           return 0;
};

int Room::checkOut(char * _customerName_Surname,int & reservationSequence)
{
         Date today;
             int customerSequence = searchAccordingToTheName(_customerName_Surname);
             if(customerSequence)
             {
                       Date reservationBeginDate = reservations[customerSequence-1].getReservationBeginDate();
                       Date reservationEndDate = reservations[customerSequence-1].getReservationEndDate();
                       
                       if(reservationBeginDate<=today && reservationEndDate >today)  
                       {
                                  if( reservations[customerSequence-1].getCheckInInfo() == true)
                                  {
                                      reservations[customerSequence-1].setCheckOutInfo(true);
                                      reservations[customerSequence-1].setCheckInInfo(false); 
                                      //gf. blink("check out icindeyim");
                                      reservationSequence = customerSequence;
                                      // cout<<endl<<"You checked out...";
                                       return 1;
                                      }
                                  else
                                  {
                                      //cout<<endl<<"Error: you have not checked in, yet";
                                      return -1;
                                      };
                                  };                              
                         //cout<<endl<<"Error: Your reservation does not include this day...";  
                         return -2;                                                                 
                        };
           //cout<<endl<<"There is no reservation that includes today.";
           return 0;
    };

int Room::searchAccordingToTheName(char *_customerName_Surname)
{
     for(int ctr = 0; ctr<numberOfMadeReservations; ctr++)
     {
             if(strcmp(reservations[ctr].getCustomerName_Surname(),_customerName_Surname)==0)
             {
                 if( reservations[ctr].getCheckOutInfo() == false || reservations[ctr].getCancelationInfo() == false)                            
                     return ctr+1;       
                     //returns the sequence of the reservation                                                          
                        };
           }
           cout<<endl<<"Error: There is no reservation";
           return 0;    
    };
    
bool Room::isItFree(Date _reservationBeginDate, Date _reservationEndDate)
{
     for(int ctr = 0; ctr<numberOfMadeReservations; ctr++)
     {
             Date reservationBeginDate = reservations[ctr].getReservationBeginDate();
             Date reservationEndDate = reservations[ctr].getReservationEndDate();
             
             //cout<<endl<<"reservationBeginDate : "<<reservationBeginDate;
             //cout<<endl<<"reservationEndDate: "<<reservationEndDate;
             
             if((_reservationBeginDate<reservationBeginDate && _reservationEndDate<=reservationBeginDate) || (_reservationBeginDate >= reservationEndDate && _reservationEndDate>reservationEndDate))
             {
                   //cout<<endl<<"IN TRUE FREE ROOM";
                    return true;
                    }
             else if(reservations[ctr].getCheckOutInfo() == true || reservations[ctr].getCancelationInfo() == true)
             {
                  //cout<<endl<<"IN TRUE FREE ROOM";
                  return true;
                 }
                 else 
                 {
                 //cout<<endl<<"IN FALSE FREE ROOM";
                  return false;
                 }
           }
           return true;
     };
     
int Room::makeService(int _serviceId)
{
     Date today; 
     int foundKey=0;
     int resOrder = 0;
     int ctr;
     //getCheckInInfo
     if(numberOfMadeReservations>0)
     {
         //cout<<endl<<endl<<"numberOfMadeReservations:" <<numberOfMadeReservations;
         for( ctr= 0; ctr<numberOfMadeReservations; ctr++)
         {
                 Date reservationBeginDate = reservations[ctr].getReservationBeginDate();
                 Date reservationEndDate = reservations[ctr].getReservationEndDate();
                 if(today<reservationEndDate && today>=reservationBeginDate && (reservations[ctr].getCancelationInfo()==false)) 
                 {
                                             foundKey = 1;
                                             resOrder = ctr;
                                             };
                 }; 
                 int checkInKey ;
                 checkInKey = reservations[ctr-1].getCheckInInfo();
                 if(checkInKey == true && foundKey==1 )
                 {
                             reservations[ctr-1].addServices(_serviceId);
                             return 1; // bulundu - servis yapilabilir
                             }
                 checkInKey = reservations[ctr-1].getCheckInInfo();
                 //cout<<endl<<endl<<"customer checked in: "<<checkInKey;
                 //cout<<endl<<"ctr: "<<ctr;
                 if( checkInKey == false && foundKey==1)
                 {
                                                       return -1; //bulundu fakat check in yapilmamis
                                                       };
         return 0; //bulunamadi
         }
     else return 0;
     };
    

