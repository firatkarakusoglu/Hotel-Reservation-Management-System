#include "Floor.h"
#include "Service.h"
#include "f_graph.h"

class Hotel
{
      private:
              char *hotelName;
              char *hotelAddress;
              char *hotelPhoneNumber;
              
              int totalServices;
              
              int numberOfFloors;
              
              double *roomPrices;
              
      public:
             Floor *allFloors; //floor nesnesi olacak
             //CONSTRUCTOR - DESTRUCTOR
             Hotel();
             Hotel(char * _hotelName, char * _hotelAddress, char * _hotelPhoneNumber);
             ~Hotel();
             //~CONSTRUCTOR - DESTRUCTOR
             
             //GET - SET METHODS
             void setHotelName(char * _hotelName );
             void setHotelAddress(char * _hotelAddress );
             void setHotelPhoneNumber(char * _hotelPhoneNumber );
             
             char * getHotelName(void);
             char * getHotelAddress(void);
             char * getHotelPhoneNumber(void);
             
             void setKingRoomPrice(double _newPrice){roomPrices[0]=_newPrice;};
             void setSuitRoomPrice(double _newPrice){roomPrices[1]=_newPrice;};
             void setLuxRoomPrice(double _newPrice){roomPrices[2]=_newPrice;};
             void setStandardRoomPrice(double _newPrice){roomPrices[3]=_newPrice;};
             
             double getKingRoomPrice(){return roomPrices[0];};
             double getSuitRoomPrice(){return roomPrices[1];};
             double getLuxRoomPrice(){return roomPrices[2];};
             double getStandardRoomPrice(){return roomPrices[3];};
             
             double getRoomPrice(int _sortOfRoom) {return roomPrices[_sortOfRoom-1];};
             
             //~GET - SET METHODS
             
             //PROPERTY FUNCTIONS
             void addService(char *_serviceName, double _servicePrice, bool _involveKing, bool _involveSuit, bool _involveLux, bool _involveStandard);
             void displayHotelInfos(void);
             void viewServiceInfos(int _serviceId, int flowControl);
             void viewAllServices(void);
             
             int getHotelFloorNumber(){return numberOfFloors; };
             void addFloorToTheHotel();
             void addFloorsToTheHotel(int _foorNumberToAdd);
             void addRoomToTheHotel(int _floorId,int _numberOfRooms, int _roomType);
             //~PROPERTY FUNCTIONS
             static Service *allServices;
             
             //Room class functions
             int findFreeRoom(Date _reservationBeginDate,Date _reservationEndDate,int _roomType);
             void newReservation(Date _reservationBeginDate,Date _reservationEndDate,int _roomType);
             void cancelReservation(int _roomNumber, Date _reservationBeginDate);
             void viewReservation(int _roomNumber, Date _reservationBeginDate);
            // void newReservation(int _roomNumber,char *_customerName_Surname,char *_customerAddress,char *_customerCreditCardNumber,char *_customerPhoneNumber,Date _reservationBeginDate,Date _reservationEndDate, double _roomDailyPrice);
            // hotel.allFloors[1].rooms[0].registerNewReservation("FIRAT K.","NEW AVENUE","123445","+012344",begin,end,15.0);
            int makeService(int _roomNumber, int _serviceId); 
            int checkIn(int _roomNumber, char * _customerName);
            int checkOut(int _roomNumber, char * _customerName);
            
            int getStatistikInfos(int _roomNumber, int _month);
            int getStatistikInfos_Type(int _roomType, int _month);
            bool isValidRoomNumber(int _roomNumber);
      };
Service * Hotel::allServices;
//Floor * Hotel::allFloors;

Hotel::Hotel()
{
                  roomPrices = new double[4];
                  numberOfFloors = 0; 
                  totalServices = 0; 
                  };//allServices = new Service[1]; numberOfFloors kadar floor nesnesi üretilecek
Hotel::Hotel(char * _hotelName, char * _hotelAddress, char * _hotelPhoneNumber)
{
           numberOfFloors = 0;      
           hotelName = new char[strlen(_hotelName)+1];
           hotelName = _hotelName;
           hotelAddress = new char[strlen(_hotelAddress)+1];
           hotelAddress = _hotelAddress;
           hotelPhoneNumber = new char[strlen(_hotelPhoneNumber)+1];
           hotelPhoneNumber = _hotelPhoneNumber;
           
           };//allServices = new Service[1];

bool Hotel::isValidRoomNumber(int _roomNumber)
{
    int count = 0;
    for(int ctr=0; ctr<numberOfFloors; ctr++)
    {
            for(int ctr2 = 0; ctr2<allFloors[ctr].getNumberOfRooms();ctr2++)
            {
                    if(allFloors[ctr].rooms[ctr2].getThisRoomNumber() == _roomNumber)
                    {
                            return true;                                          
                            };
                    };
            };     
    return false;
};

int Hotel::findFreeRoom(Date _reservationBeginDate,Date _reservationEndDate,int _roomType)
{
    
showAgain:
          
    int foundKey = 0;
    int count = 0;
    for(int ctr=0; ctr<numberOfFloors; ctr++)
    {
            for(int ctr2 = 0; ctr2<allFloors[ctr].getNumberOfRooms();ctr2++)
            {
                    bool isFree = allFloors[ctr].rooms[ctr2].isItFree(_reservationBeginDate,_reservationEndDate);
                    if(isFree)
                    {
                            if(allFloors[ctr].rooms[ctr2].getSortOfRoom() == _roomType)
                            {
                                 count++;
                                 
                                 //cout<<endl<<"Free room found";
                                 //gf.showOnScreen("Do you want the room ",0);
                                 foundKey = 1;
                                 gf.showOnScreen(" ",0,1);
                                 cout<<count<<". Free Room ["<<
                                 allFloors[ctr].rooms[ctr2].getThisRoomNumber();
                                 cout<<"]";
                                 gf.showOnScreen("    ",0);
                                 cout<<Room::getSequenceNumber(allFloors[ctr].rooms[ctr2].getThisRoomNumber() );
                                 cout<<". Room In The "<<Room::getStairNumber(allFloors[ctr].rooms[ctr2].getThisRoomNumber());
                                 cout<<". Floor";
                                 
takeAgain:
                                 
                                 gf.footCaption("Do you want this room [Y/N]: ");
                                 char choice;
                                 choice = getch();
                                 if(choice == 'y' || choice == 'Y')
                                 {
                                    // cout<<endl<<"In yes decleration.";
                                     return  allFloors[ctr].rooms[ctr2].getThisRoomNumber();
                                     }
                                     else if(choice == 'n' || choice == 'N') 
                                     {
                                               //cout<<endl<<"In continue...";
                                               continue;
                                         }
                                         else 
                                         {
                                              gf.blink("You should enter \"Y\" or \"N\"");
                                              goto takeAgain;
                                              };
                             };
                    };
            };
    };
    if(foundKey==1)
    {
                   gf.blink("For this room type, there is no other free room in these days.");
                   gf.footCaption("Do you want to see free rooms, again [Y/N]: ");
                   char answ;
                   answ = getch();
                   if(answ == 'y'  || answ == 'Y') goto showAgain;
                   }
    if(foundKey==0)gf.blink("Sorry, for this room type, there is no free room in these days.");
    return 0;
};           


Hotel::~Hotel(){ delete [] hotelName; delete [] hotelAddress; delete [] hotelPhoneNumber;  };  //delete [] allServices;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         

void Hotel::cancelReservation(int _roomNumber, Date _reservationBeginDate)
{
     double warningKey = -2;
               int stairNumber,sortOfRoom,sequenceNumber;
               stairNumber = Room::getStairNumber(_roomNumber);
               sortOfRoom = Room::getSortOfRoom(_roomNumber);
               sequenceNumber = Room::getSequenceNumber(_roomNumber);
               
warningKey = allFloors[stairNumber-1].rooms[sequenceNumber-1].cancelPreviousReservation(_reservationBeginDate);
int remainedDay = 0;
Date today;
remainedDay = _reservationBeginDate - today;

    if(warningKey==0) gf.blink("Reservation Canceled.");
    else if(warningKey==-1) gf.blink("Reservation could not find.");
    else if(warningKey==-2) gf.blink("Customer Checked In.");
    else if(warningKey==-3) gf.blink("Customer Checked Out.");
    else 
    {
                gf.showOnScreen("     ---------------------------",1,1);
                gf.showOnScreen("     -------CUSTOMER BILL-------");
                gf.showOnScreen("");
                
                ///hotel infos  
                gf.showOnScreen("Hotel Informations:");
                gf.showOnScreen("Name: "); //kontrollu akis, yeni sayfa
                cout<<hotelName;
                gf.showOnScreen("Address: ");
                cout<<hotelAddress ;
                gf.showOnScreen("Phone Number: ");
                cout<<hotelPhoneNumber;     
            
               gf.showOnScreen("-----------------------------------");
               gf.showOnScreen("Your daily room price: ");
               cout<<roomPrices[sortOfRoom-1]<<"$";
               gf.showOnScreen("There are ");
               cout<<remainedDay<<" days to your reservation.";
               gf.showOnScreen("You must pay ");
               double rate = (1.0-((1.0/4.0)*remainedDay));
               cout<<rate<<" of your total room price.";
               gf.showOnScreen("-----------------------------------");
               gf.showOnScreen("Total Payment: "); cout<<warningKey<<"$";
               gf.showOnScreen("-----------------------------------");   
         };
    
     };
void Hotel::viewReservation(int _roomNumber, Date _reservationBeginDate)
{
               int resSequence = 0;
               int stairNumber,sortOfRoom,sequenceNumber;
               stairNumber = Room::getStairNumber(_roomNumber);
               sortOfRoom = Room::getSortOfRoom(_roomNumber);
               sequenceNumber = Room::getSequenceNumber(_roomNumber);
               
               Date begin, end;
               
resSequence = allFloors[stairNumber-1].rooms[sequenceNumber-1].searchForReservation(_reservationBeginDate);
    if(resSequence==0) gf.blink("Reservation could not find.");
    
    else
    {
        //cout<<"------------>"<<endl<<resSequence<<endl;
        gf.showOnScreen("Customer Name&Surname: ",1,1);
        
        cout<<allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getCustomerName_Surname();
        gf.showOnScreen("Customer Address: ",1,0);
        cout<<allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getCustomerAddress();
        gf.showOnScreen("Customer Credit Card Number: ",1,0);
        cout<<allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getCustomerCreditCardNumber();
        gf.showOnScreen("Customer Phone Number: ",1,0);
        cout<<allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getCustomerPhoneNumber();
        gf.showOnScreen("Customer Payment: ",1,0);
        cout<<allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getPayment();
        
        gf.showOnScreen("Reservation Begin Date: ",1,0);
        begin = allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getReservationBeginDate();
        cout<<begin;
        
        gf.showOnScreen("Reservation End Date: ",1,0);
        end = allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getReservationEndDate();
        cout<<end;
        
        int checkInKey = allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getCheckInInfo();
        int checkOutKey = allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getCheckOutInfo();
        
        if(checkInKey == true) gf.showOnScreen("Customer Checked In.");
        else 
        {
             if(checkOutKey) gf.showOnScreen("Customer Checked Out.");
             else gf.showOnScreen("Customer Does NOT Checked In.");
             };
        
        if(checkInKey)
        {
                      int serNumber = allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getNumberOfMadeReservation();
                      int ctr = 0;
                      for(;ctr<serNumber; ctr++)
                      {
                                          int serviceId;
                                          serviceId = allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].gotServices[ctr];
                                          gf.showOnScreen("",1,0);
                                          gf.showOnScreen("Taken Services...",1,0);
                                          viewServiceInfos(serviceId,1);
                                          };
                      };
       
       
        };
    
     };
void Hotel::newReservation(Date _reservationBeginDate,Date _reservationEndDate,int _roomType)
{
       int roomNumber = 0;
       roomNumber = findFreeRoom(_reservationBeginDate,_reservationEndDate,_roomType);
     if(roomNumber)
     {
               int stairNumber,sortOfRoom,sequenceNumber;
               stairNumber = Room::getStairNumber(roomNumber);
               sortOfRoom = Room::getSortOfRoom(roomNumber);
               sequenceNumber = Room::getSequenceNumber(roomNumber);
               //burada olusan atlamayi onlemek icin
               char a[2];
               gets(a);
               
               
               gf.footCaption("Customer Name&Surname: ");
               char _customerName_Surname[25];
               gets(_customerName_Surname);
               gf.showOnScreen("Name&Surname: ",0,1);
               cout<<_customerName_Surname;

               gf.footCaption("Customer Address: ");
               char _customerAddress[25];
               gets(_customerAddress);
               gf.showOnScreen("Address: ",0);
               cout<<_customerAddress;

               gf.footCaption("Customer Credit Card Number: ");
               char _customerCreditCardNumber[25];
               gets(_customerCreditCardNumber);
               gf.showOnScreen("Credit Card Number: ",0);
               cout<<_customerCreditCardNumber;

               gf.footCaption("Customer Phone Number: ");
               char _customerPhoneNumber[25];
               gets(_customerPhoneNumber);
               gf.showOnScreen("Phone Number: ",0);
               cout<<_customerPhoneNumber;
               
               double _dailyPrice =  getRoomPrice(sortOfRoom);
              
              /* cout<<endl<<"In hotel class "<<_dailyPrice;
               cout<<endl<<"In hotel class "<<getRoomPrice(sortOfRoom);
               cout<<endl<<"In hotel sort of room"<< sortOfRoom;*/
               

               allFloors[stairNumber-1].rooms[sequenceNumber-1].registerNewReservation(_customerName_Surname,_customerAddress,_customerCreditCardNumber,_customerPhoneNumber,_reservationBeginDate,_reservationEndDate,_dailyPrice);
               
               
               ///////////////////////////////////////FOR STATISTIC INFOS....
               Date today;
               int year = today.getYear();
               Date newYear(1,1,year);
               
               int dayFromTheBeginning = 0;
               dayFromTheBeginning = _reservationBeginDate - newYear;
               
               while(_reservationBeginDate != _reservationEndDate)
               {
                                           dayFromTheBeginning++;
                                           
                                           allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[dayFromTheBeginning] = 1;
                                           //cout<<endl<<"hotel class - new res."<<allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[dayFromTheBeginning];
                                           //cout<<endl<<"hotel.h icindeyim";
                                           _reservationBeginDate++;
                                           
                                           };
               
               ///////////////////////////////////////END FOR STATISTIC INFOS....
               gf.blink("Reservation done."); 
               };
     };
int Hotel::getStatistikInfos_Type(int _roomType, int _month)
{
    double totalPercentage = 0.0;
    int numberOfRooms=0;
    for(int ctr=0; ctr<numberOfFloors ; ctr++)
    {
        for(int ctr2=0; ctr2<allFloors[ctr].getNumberOfRooms(); ctr2++)
        {
            if(allFloors[ctr].rooms[ctr2].getSortOfRoom() == _roomType)
            {
                   int roomNumber = allFloors[ctr].rooms[ctr2].getThisRoomNumber();
                   totalPercentage += getStatistikInfos(roomNumber,_month);
                   numberOfRooms++;
                   };
             };
        };
        return (totalPercentage/numberOfRooms);
    };
int Hotel::getStatistikInfos(int _roomNumber, int _month)
{
    int stairNumber,sortOfRoom,sequenceNumber;
    stairNumber = Room::getStairNumber(_roomNumber);
    sortOfRoom = Room::getSortOfRoom(_roomNumber);
    sequenceNumber = Room::getSequenceNumber(_roomNumber);
    int resFound = 0;
    switch(_month)
    {
                  case 1:
                       for(int ctr=0;ctr<31; ctr++)
                       {
                       if(allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[ctr] == 1)
                       resFound++;
                       }
                       return (resFound*100)/31;
                       break;
                  case 2:
                       for(int ctr=31;ctr<59; ctr++)
                       {
                       if(allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[ctr] == 1)
                       resFound++;
                       }
                       return (resFound*100)/28;
                       break;
                  case 3:
                       for(int ctr=59;ctr<90; ctr++)
                       {
                       if(allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[ctr] == 1)
                       resFound++;
                       }
                       return (resFound*100)/31;
                       break;
                  case 4:
                       for(int ctr=90;ctr<120; ctr++)
                       {
                       if(allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[ctr] == 1)
                       resFound++;
                       }
                       return (resFound*100)/30;
                       break;
                  case 5:
                       for(int ctr=120;ctr<151; ctr++)
                       {
                       if(allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[ctr] == 1)
                       resFound++;
                       }
                       return (resFound*100)/31;
                       break;
                  case 6:
                       for(int ctr=151;ctr<181; ctr++)
                       {
                       if(allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[ctr] == 1)
                       resFound++;
                       }
                       return (resFound*100)/30;
                       break;
                  case 7:
                       for(int ctr=181;ctr<212; ctr++)
                       {
                       if(allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[ctr] == 1)
                       resFound++;
                       }
                       return (resFound*100)/31;
                       break;
                  case 8:
                       for(int ctr=212;ctr<243; ctr++)
                       {
                       if(allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[ctr] == 1)
                       resFound++;
                       }
                       return (resFound*100)/31;
                       break;
                  case 9:
                       for(int ctr=243;ctr<273; ctr++)
                       {
                       if(allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[ctr] == 1)
                       resFound++;
                       }
                       return (resFound*100)/30;
                       break;
                  case 10:
                       for(int ctr=273;ctr<304; ctr++)
                       {
                       if(allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[ctr] == 1)
                       resFound++;
                       }
                       return (resFound*100)/31;
                       break;
                  case 11:
                       for(int ctr=304;ctr<334; ctr++)
                       {
                       if(allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[ctr] == 1)
                       resFound++;
                       }
                       return (resFound*100)/30;
                       break;
                  case 12:
                       for(int ctr=334;ctr<365; ctr++)
                       {
                       if(allFloors[stairNumber-1].rooms[sequenceNumber-1].forStatisticInfos[ctr] == 1)
                       resFound++;
                       }
                       return (resFound*100)/31;
                       break;
                  default:
                       gf.blink("Month is wrong.");
                       return 0;
                       break;
                  };    
    };
void Hotel::setHotelName(char * _hotelName ){hotelName = new char[strlen(_hotelName)+1]; hotelName = _hotelName;};
void Hotel::setHotelAddress(char * _hotelAddress ){hotelAddress = new char[strlen(_hotelAddress)+1]; hotelAddress = _hotelAddress;};
void Hotel::setHotelPhoneNumber(char * _hotelPhoneNumber ){hotelPhoneNumber = new char[strlen(_hotelPhoneNumber)+1]; hotelPhoneNumber = _hotelPhoneNumber;};

char * Hotel::getHotelName(void){return hotelName;};
char * Hotel::getHotelAddress(void){return hotelAddress;};
char * Hotel::getHotelPhoneNumber(void){return hotelPhoneNumber;};

void Hotel::addService(char *_serviceName, double _servicePrice, bool _involveKing, bool _involveSuit, bool _involveLux, bool _involveStandard)
{
     totalServices++;
     //cout<<endl<<" totalServices:"<<totalServices;
     if(totalServices == 1) allServices = new Service[totalServices];
     
     else {
          Service * tempServices;
          tempServices = new Service[totalServices];
          tempServices = allServices;
          allServices = new Service[totalServices];
          allServices = tempServices;
          };
     
     //Last service has been setting according to the given informations.
     allServices[totalServices-1].setServiceName(_serviceName);
     allServices[totalServices-1].setServicePrice(_servicePrice);
     allServices[totalServices-1].setInvolveKing(_involveKing);
     allServices[totalServices-1].setInvolveSuit(_involveSuit);
     allServices[totalServices-1].setInvolveLux(_involveLux);
     allServices[totalServices-1].setInvolveStandard(_involveStandard);
     };
     
void Hotel::viewServiceInfos(int _serviceId,int flowControl = 0)
{
     if(_serviceId<1 || _serviceId>totalServices)
     { gf.blink("Error: Unpresent service id has been given."); }
     else
     {
         //getch();
         if(flowControl == 1)gf.showOnScreen("",1,0);
         else gf.showOnScreen("",1,1);
         
         
         cout<<_serviceId<<". Service Infos";
         gf.showOnScreen("Service Name: ",1);
         cout<<allServices[_serviceId-1].getServiceName();
         gf.showOnScreen("Service Price: ",1);
         cout<<allServices[_serviceId-1].getServicePrice();
         for(int ctr=0;ctr<4;ctr++)
         {
             int key = allServices[_serviceId-1].isThisRoomIncludeThisService(ctr+1);
                   if(key == 1)
                   {
                            switch(ctr)
                            {
                                       case 0:
                                            gf.showOnScreen("This service includes in King Rooms.",1,0); 
                                       break;
                                       case 1:
                                            gf.showOnScreen("This service includes in Suit Rooms.",1);
                                       break;
                                       case 2:
                                            gf.showOnScreen("This service includes in Luxury Rooms.",1);
                                       break;
                                       case 3:
                                            gf.showOnScreen("This service includes in Standard Rooms.",1);
                                       break;
                                       default:
                                               gf.blink("Unknown Error Occured.");
                                       };//end switch(ctr)                                             
                            };//end if(key == 1)
                   };//end for(int ctr=0;ctr<4;ctr++) 
           };//end else
     };//end void Hotel::viewHotelServices(int _serviceId)
     
void Hotel::viewAllServices(void)
{
     for(int ctr=0; ctr<totalServices; ctr++)
     {
          viewServiceInfos(ctr+1);
          if(ctr+1 != totalServices) 
          {
                   gf.blink("Press any key to go to the next page.");
                   //getch();
                   };
          };//end for(int ctr=0; ctr<totalServices; ctr++)
     };//end void Hotel::viewAllServices(void)

void Hotel::addFloorsToTheHotel(int _floorNumberToAdd)
{
     for(int ctr=0; ctr<_floorNumberToAdd; ctr++)
     {
             addFloorToTheHotel();
             };
     };

void Hotel::addFloorToTheHotel()
{
             numberOfFloors;
             //cout<<endl<<numberOfFloors;
             numberOfFloors++; //at the beginning it will be 1
             if(numberOfFloors == 1) allFloors = new Floor[1];
             else
             {
                 //cout<<endl<< "Else icindeyim";
                 Floor *tempFloors= new Floor[numberOfFloors];
                 tempFloors = allFloors;
                 allFloors = new Floor[numberOfFloors];
                 allFloors = tempFloors;
                 };
                  
         allFloors[numberOfFloors-1].setNumberOfRooms(0);
         allFloors[numberOfFloors-1].setNumberOfKingRooms(0);
         allFloors[numberOfFloors-1].setNumberOfSuitRooms(0);
         allFloors[numberOfFloors-1].setNumberOfLuxRooms(0);
         allFloors[numberOfFloors-1].setNumberOfStandardRooms(0);
         allFloors[numberOfFloors-1].setFloorSequence(numberOfFloors);
         
         //cout<<endl<<"Floor id is: "<<allFloors[numberOfFloors-1].getFloorSequence(); 
          
         //cout<<endl<<"allFloors[numberOfFloors-1].getFloorId() :"<<allFloors[numberOfFloors-1].getFloorId();  
         
     };
void Hotel::addRoomToTheHotel(int _floorId, int _numberOfRooms, int _roomType)
{
     if(_floorId<=numberOfFloors && _floorId>0 && _numberOfRooms>=0 && _numberOfRooms<10 && _roomType<5 && _roomType>0)
     {
                                 allFloors[_floorId-1].addRooms(_numberOfRooms, _roomType);
                                 //gf.blink("Room added.");
     }
     else gf.blink("Errors: Your parameters are out of limits.");
     };

/*void Hotel::displayHotelInfos(void)
{
     gf.showOnScreen("Name: ",1,1); cout<<hotelName;
     gf.showOnScreen("Address: "); cout<<hotelAddress;
     gf.showOnScreen("Phone Number: "); cout<<hotelPhoneNumber;
     };*/

void Hotel::displayHotelInfos(void)
{
     gf.showOnScreen("Name: ",1,1); //kontrollu akis, yeni sayfa
     cout<<hotelName;
     gf.showOnScreen("Address: ");
     cout<<hotelAddress ;
     gf.showOnScreen("Phone Number: ");
     cout<<hotelPhoneNumber;
     //gf.showOnScreen("");
     gf.showOnScreen("->Technical Information ");
     //gf.showOnScreen("");
     gf.showOnScreen("Number of Floors is: ");
     cout<<numberOfFloors;
     for(int ctr=0; ctr<numberOfFloors;ctr++)
     {
         gf.showOnScreen("");
         cout<<ctr+1<<". Floor";
         gf.showOnScreen("Number of King Rooms: "); cout<<allFloors[ctr].getNumberOfKingRooms();
         gf.showOnScreen("Number of Suit Rooms: "); cout<<allFloors[ctr].getNumberOfSuitRooms();
         gf.showOnScreen("Number of Lux Rooms: "); cout<<allFloors[ctr].getNumberOfLuxRooms();
         gf.showOnScreen("Number of Standard. Rooms: "); cout<<allFloors[ctr].getNumberOfStandardRooms();
         };
     };
int Hotel::makeService(int _roomNumber, int _serviceId)
{
    if(_serviceId>0 && _serviceId<=totalServices)
    {
        int stairNumber,sortOfRoom,sequenceNumber;
        stairNumber = Room::getStairNumber(_roomNumber);
        sortOfRoom = Room::getSortOfRoom(_roomNumber);
        sequenceNumber = Room::getSequenceNumber(_roomNumber);
       
        return  (allFloors[stairNumber-1].rooms[sequenceNumber-1].makeService(_serviceId));
        }
    else gf.blink("Error: Given service id is OUT OF LIMITS.");
     //makeService
     };
int Hotel::checkIn(int _roomNumber, char * _customerName)
{
    int stairNumber,sortOfRoom,sequenceNumber;
    stairNumber = Room::getStairNumber(_roomNumber);
    sortOfRoom = Room::getSortOfRoom(_roomNumber);
    sequenceNumber = Room::getSequenceNumber(_roomNumber);
    
    return (allFloors[stairNumber-1].rooms[sequenceNumber-1].checkIn(_customerName));
    };
    
int Hotel::checkOut(int _roomNumber, char * _customerName)
{
    int stairNumber,sortOfRoom,sequenceNumber;
    stairNumber = Room::getStairNumber(_roomNumber);
    sortOfRoom = Room::getSortOfRoom(_roomNumber);
    sequenceNumber = Room::getSequenceNumber(_roomNumber);
    int resSequence;
    int checkKey = allFloors[stairNumber-1].rooms[sequenceNumber-1].checkOut(_customerName,resSequence);
    if( checkKey == 1) //fatura hazirlanacak
    {
                    double customerPayment = 0.0;   
                    Date begin, end;
gf.showOnScreen("     ---------------------------",1,1);
gf.showOnScreen("     -------CUSTOMER BILL-------");
gf.showOnScreen("");

///hotel infos  
gf.showOnScreen("Hotel Informations:");
gf.showOnScreen("Name: "); //kontrollu akis, yeni sayfa
cout<<hotelName;
gf.showOnScreen("Address: ");
cout<<hotelAddress ;
gf.showOnScreen("Phone Number: ");
cout<<hotelPhoneNumber;       

gf.showOnScreen("");
gf.showOnScreen("Customer Informations:");
///customer infos
gf.showOnScreen("Name&Surname: ",1,0);
cout<<allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getCustomerName_Surname();
gf.showOnScreen("Address: ",1,0);
cout<<allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getCustomerAddress();
gf.showOnScreen("Credit Card Number: ",1,0);
cout<<allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getCustomerCreditCardNumber();
gf.showOnScreen("Phone Number: ",1,0);
cout<<allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getCustomerPhoneNumber();
gf.showOnScreen("Payment: ",1,0);
cout<<allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getPayment();

gf.showOnScreen("Reservation Begin Date: ",1,0);
begin = allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getReservationBeginDate();
cout<<begin;

gf.showOnScreen("Reservation End Date: ",1,0);
end = allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getReservationEndDate();
cout<<end;
           /////               

//////taken services
int serNumber = allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].getNumberOfMadeReservation();

int saveHowManyTimes[totalServices];
for(int ctr=0; ctr<totalServices; ctr++) saveHowManyTimes[ctr] = 0;
for(int ctr=0;ctr<serNumber; ctr++)
{
              int serviceId;
              serviceId = allFloors[stairNumber-1].rooms[sequenceNumber-1].reservations[resSequence-1].gotServices[ctr];
              saveHowManyTimes[serviceId-1]++;
              };

for(int ctr=0;ctr<totalServices;ctr++)
{
     if(saveHowManyTimes[ctr]>0)
     {
                    gf.showOnScreen("Service That Belove Was Taken ");
                    cout<<saveHowManyTimes[ctr]<<" Times.";
                    viewServiceInfos(ctr+1,1);
                    if(!(allServices[ctr].isThisRoomIncludeThisService(sortOfRoom)))
                    {//eger oda bu servisi icermiyorsa para hesaba ekleniyor.
                        customerPayment += (saveHowManyTimes[ctr])* (allServices[ctr].getServicePrice());
                        }
                    };//end if(saveHowManyTimes[ctr]>0)
            };//end for(int ctr=0;ctr<totalServices;ctr++)
            int numberOfDays = end-begin;
           double roomPrice = (roomPrices[sortOfRoom-1]*(numberOfDays));
           gf.showOnScreen("-----------------------------------");
           gf.showOnScreen("Your daily room price: ");
           cout<<roomPrices[sortOfRoom-1]<<"$";
           gf.showOnScreen("Total room price :");
           cout<<roomPrices[sortOfRoom-1]<<" * "<<numberOfDays<<" :"<<roomPrice<<"$";
           gf.showOnScreen("Your payment for services: "); cout<<customerPayment<<"$";
           gf.showOnScreen("-----------------------------------");
           gf.showOnScreen("Total Payment: "); cout<<customerPayment+roomPrice<<"$";
           gf.showOnScreen("-----------------------------------");
           
     };
//////// 
    return (checkKey);
};
