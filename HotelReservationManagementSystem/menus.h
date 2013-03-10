#include "hotelSettings.h"

/////////////////RESERVATIONS/////////////
void menuReservation_1_makeReservation()       
{   
takeAgainRoomType:
     gf.footCaption("Room Type [King-Suit-Lux.-Standard]->[1-4]: "); 
     int roomType=0;
     cin>>roomType;
     if(roomType<=0 || roomType>4) 
     {
         gf.blink("Error: Room types should be between [1-4]!!!");
         goto takeAgainRoomType;
         };
        
     int day=0, month=0, year=0;
     
     gf.footCaption("Reservation Begin Date like \"16.1.2007\": ");
     scanf("%2d.%2d.%4d",&day, &month, &year);
     Date begin(day, month, year);
     
     gf.footCaption("Reservation End Date: ");
     scanf("%2d.%2d.%4d",&day, &month, &year);
     Date end(day, month, year);        

     Date today;
     
     if(begin<today) gf.blink("Error: Beginning date can not be before today!!!");
     else if(end<begin) gf.blink("Error: End date, can not be before beginning date!!!");
     else if((end-today)>365) gf.blink("Error: You can make reservation only for one year!!!");
     else hotel.newReservation(begin,end,roomType);
     };
void menuReservation_2_cancelReservation()
{
takeAgainRoomNumber:
                    
     gf.footCaption("Room Number like ->\"10011\": "); 
     int _roomNumber=0;
     cin>>_roomNumber;
     if(!(hotel.isValidRoomNumber(_roomNumber)))
     {
     gf.blink("Error: There is no such numbered room!!!"); 
     goto takeAgainRoomNumber;   
     };
        
     int day=0, month=0, year=0;
     
     gf.footCaption("Reservation Begin Date: ");
     scanf("%2d.%2d.%4d",&day, &month, &year);
     Date begin(day, month, year);    
     
     hotel.cancelReservation(_roomNumber,begin);
     };
void menuReservation_3_viewReservation()
{
takeAgainRoomNumber:
                    
     gf.footCaption("Room Number like ->\"10011\": "); 
     int _roomNumber=0;
     cin>>_roomNumber;
     if(!(hotel.isValidRoomNumber(_roomNumber)))
     {
     gf.blink("Error: There is no such numbered room!!!"); 
     goto takeAgainRoomNumber;   
     };
        
     int day=0, month=0, year=0;
     
     gf.footCaption("Reservation Begin Date: ");
     scanf("%2d.%2d.%4d",&day, &month, &year);
     Date begin(day, month, year);
     
     hotel.viewReservation(_roomNumber,begin);
     };
     
///////////////////////CHECK IN///////////////
void menuService_1_checkIn()
{
takeAgainRoomNumber:
                    
     gf.footCaption("Room Number like ->\"10011\": "); 
     int _roomNumber=0;
     cin>>_roomNumber;
     if(!(hotel.isValidRoomNumber(_roomNumber)))
     {
     gf.blink("Error: There is no such numbered room!!!"); 
     goto takeAgainRoomNumber;   
     };
     

     gf.footCaption("Customer Name: "); 
     char customerName[25];
     cin>>customerName;
     
     int resultKey;
     resultKey = hotel.checkIn(_roomNumber,customerName);
    
     
     if(resultKey == 1) gf.blink("Customer Checked In.");
     if(resultKey == -1) gf.blink("Error: Customer's reservation does not include this day.");
     if(resultKey == -2) gf.blink("Error: Customer is CHECKED OUT before.");     
     if(resultKey == 0) gf.blink("There is no reservation that includes today.");
     };
///////////////////////CHECK OUT///////////////
void menuService_1_checkOut()
{
takeAgainRoomNumber:
                    
     gf.footCaption("Room Number like ->\"10011\": "); 
     int _roomNumber=0;
     cin>>_roomNumber;
     if(!(hotel.isValidRoomNumber(_roomNumber)))
     {
     gf.blink("Error: There is no such numbered room!!!"); 
     goto takeAgainRoomNumber;   
     };
     

     gf.footCaption("Customer Name: "); 
     char customerName[25];
     cin>>customerName;
     
     int resultKey;
     resultKey = hotel.checkOut(_roomNumber,customerName);
    
     if(resultKey == 1) gf.blink("Customer Checked Out.");
     if(resultKey == -1) gf.blink("Error: Customer Does NOT Check In.");
     if(resultKey == -2) gf.blink("Error: Your reservation does not include this day...");    
     if(resultKey == 0) gf.blink("There is no reservation that includes today.");
     };

///////////////////////SERVICES///////////////
void menuService_1_makeService()
{
takeAgainRoomNumber:
                    
     gf.footCaption("Room Number like ->\"10011\": "); 
     int _roomNumber=0;
     cin>>_roomNumber;
     if(!(hotel.isValidRoomNumber(_roomNumber)))
     {
     gf.blink("Error: There is no such numbered room!!!"); 
     goto takeAgainRoomNumber;   
     };
     
     gf.footCaption("Service Id.: "); 
     int serviceId;
     cin>>serviceId;
     int resultKey=-2;
     resultKey = hotel.makeService(_roomNumber,serviceId);
     
     if(resultKey == 1) gf.blink("Service made.");
     if(resultKey == -1) gf.blink("No Check In. - Service Aborted.");
     if(resultKey == 0) gf.blink("Today, there is no reservation for that room");
     };
void menuService_2_addService()
{
     char a[2];
     gets(a); //neden meydana geldigini bulamadigim atlamayi engellemek icin :)
     
     gf.footCaption("Service Name: "); 
     char serName[25];
     gets(serName);
     gf.showOnScreen("Service Name: ",0,1);
     cout<<serName;

     gf.footCaption("Service Price: "); 
     double serPrice=0.0;
     cin>>serPrice;
     gf.showOnScreen("Service Price: ",0);
     cout<<serPrice;
 
     char yOrN;
     
     gf.footCaption("King rooms include this service [Y/N]: "); 
     bool incKing;
     yOrN = getch();
     if(yOrN == 'y' || yOrN=='Y'){incKing=true; gf.showOnScreen("King rooms include this service."); }
     else { incKing=false; gf.showOnScreen("King rooms does NOT include this service.");};
     
     
     gf.footCaption("Suit. rooms include this service [Y/N]: "); 
     bool incSuit;
     yOrN = getch();
     if(yOrN == 'y' || yOrN=='Y'){incSuit=true; gf.showOnScreen("Suit rooms include this service."); }
     else { incSuit=false; gf.showOnScreen("Suit rooms does NOT include this service.");};
     
     gf.footCaption("Lux. rooms include this service [Y/N]: "); 
     bool incLux;
     yOrN = getch();
     if(yOrN == 'y' || yOrN=='Y'){incLux=true; gf.showOnScreen("Lux. rooms include this service."); }
     else { incLux=false; gf.showOnScreen("Lux. rooms does NOT include this service.");};
     
     gf.footCaption("Standard rooms include this service [Y/N]: "); 
     bool incStandard;
     yOrN = getch();
     if(yOrN == 'y' || yOrN=='Y'){incStandard=true; gf.showOnScreen("Standard rooms include this service."); }
     else { incStandard=false; gf.showOnScreen("Standard rooms NOT include this service.");};
     
    hotel.addService(serName,serPrice,incKing,incSuit,incLux,incStandard);

     };
void menuService_3_changeService()
{
     
     };
     
void menuService_4_viewService()
{
     gf.footCaption("Service Id: ");
     int serviceId=0;
     cin>>serviceId;
     hotel.viewServiceInfos(serviceId);
     };
     
void menuService_5_viewAllServices()
{
     hotel.viewAllServices();
     };
//////////////////HOTEL SETTINGS////////////
void menuSettings_1_displayHotelInfos()
{
  hotel.displayHotelInfos();
};
void menuSettings_3_addFloor()
{
     gf.footCaption("How Many Floor Do You Want To Add: ");
     int floorNumberToAdd=0;
     cin>>floorNumberToAdd;
     hotel.addFloorsToTheHotel(floorNumberToAdd);
     gf.showOnScreen("After this change, hotel infos...");
     hotel.displayHotelInfos();
     };
void menuSettings_4_addRooms()
{
     int _floorId=0,_numberOfRooms=0,_roomType=0;
     gf.footCaption("How Many Room: ");
     cin>>_numberOfRooms;
 
     gf.footCaption("What Kind Of Room [King-Suit-Lux.-Standard]->[1-4]: ");
     cin>>_roomType;

     gf.footCaption("On Whic Floor: ");
     cin>>_floorId;
    
     hotel.addRoomToTheHotel(_floorId,_numberOfRooms,_roomType);
     
     };
void menuSettings_5_addService() //menuSettings_5_addService
{
     char a[2];
     gets(a);//atlama sorununu cozuyor...
     
     gf.footCaption("Service Name: ");
     char _serviceName[25];
     gets(_serviceName);
     gf.footCaption("Service Price: ");
     double _servicePrice=0.0;
     cin>>_servicePrice;
     bool _involveKing,_involveSuit,_involveLux,_involveStandard;
     char userAnswer;
     gf.footCaption("King Rooms Include This Service [Y/N]: ");
     userAnswer = getch();
     putchar(userAnswer);
     gf.wait(100);
     if(userAnswer == 'y' || userAnswer == 'Y') _involveKing=true;
     else _involveKing = false;
     
     gf.footCaption("Suit Rooms Include This Service [Y/N]: ");
     userAnswer = getch();
     putchar(userAnswer);
     gf.wait(100);
     if(userAnswer == 'y' || userAnswer == 'Y') _involveSuit=true;
     else _involveSuit = false;

     gf.footCaption("Lux. Rooms Include This Service [Y/N]: ");
     userAnswer = getch();
     putchar(userAnswer);
     gf.wait(100);
     if(userAnswer == 'y' || userAnswer == 'Y') _involveLux=true;
     else _involveLux = false;

     gf.footCaption("Standard Rooms Include This Service [Y/N]: ");
     userAnswer = getch();
     putchar(userAnswer);
     gf.wait(100);
     if(userAnswer == 'y' || userAnswer == 'Y') _involveStandard=true;
     else _involveStandard = false;
 
     hotel.addService(_serviceName,_servicePrice, _involveKing, _involveSuit, _involveLux, _involveStandard);
    
     };
void menuSettings_6_viewService()
{
     hotel.viewAllServices();
     };

/////change hotel infos
void menuSettings_1_chName()
{
     gf.footCaption("Hotel New Name: ");
     char hotelName[25];
     gets(hotelName);
     gf.showOnScreen("Hotel Old Name: ",0);
     cout<<hotel.getHotelName();
     gf.showOnScreen("");
     gf.showOnScreen("Hotel New Name: ");
     cout<<(hotelName);
     hotel.setHotelName(hotelName);
     gf.blink("Hotel Name Changed.");
     gf.headCaption(hotelName);
     };
void menuSettings_2_chAddress()
{
     gf.footCaption("Hotel New Address: ");
     char hotelAddress[50];
     gets(hotelAddress);
     gf.showOnScreen("Hotel Old Address: ",0);
     cout<<hotel.getHotelAddress();
     gf.showOnScreen("");
     gf.showOnScreen("Hotel New Address: ");
     cout<<(hotelAddress);
     hotel.setHotelName(hotelAddress);
     gf.blink("Hotel Address Changed.");
     };
void menuSettings_3_chPhone()
{
     gf.footCaption("Hotel New Phone Number: ");
     char hotelPhoneNumber[50];
     gets(hotelPhoneNumber);
     gf.showOnScreen("Hotel Old Phone Number: ",0);
     cout<<hotel.getHotelAddress();
     gf.showOnScreen("");
     gf.showOnScreen("Hotel New Phone Number: ");
     cout<<(hotelPhoneNumber);
     hotel.setHotelName(hotelPhoneNumber);
     gf.blink("Hotel Phone Number Changed.");
     };

 void menuSettings_1_viewKings()
 {
                        gf.showOnScreen("King Room Daily Price: ",1,1);
                        cout<<hotel.getKingRoomPrice()<<"$";
                        };
void  menuSettings_2_viewSuits()
 {
                        gf.showOnScreen("Suit Room Daily Price: ",1,1);
                        cout<<hotel.getSuitRoomPrice()<<"$";                           
                        };
void  menuSettings_3_viewLuxs()
 {
                        gf.showOnScreen("Lux. Room Daily Price: ",1,1);
                        cout<<hotel.getLuxRoomPrice()<<"$";
                        };
void  menuSettings_4_viewStandards()
 {
                        gf.showOnScreen("Standard Room Daily Price: ",1,1);
                        cout<<hotel.getStandardRoomPrice()<<"$";
                        };
 double roomPrice;
void  menuSettings_5_chngKings()
 {
                           gf.footCaption("New King Room Price: ");
                           cin>>roomPrice;
                           gf.showOnScreen("King Room Old. Daily Price: ");
                           cout<<hotel.getKingRoomPrice();
                           
                           hotel.setKingRoomPrice(roomPrice);
                           gf.showOnScreen("King Room New. Daily Price: ");
                           cout<<hotel.getKingRoomPrice();
                           
                           gf.blink("King Room Daily Price Changed");
                           };                            
void  menuSettings_6_chngSuits()
 {
                           gf.footCaption("New Suit Room Price: ");
                           cin>>roomPrice;
                           gf.showOnScreen("Suit Room Old. Daily Price: ");
                           cout<<hotel.getSuitRoomPrice();
                           
                           hotel.setKingRoomPrice(roomPrice);
                           gf.showOnScreen("Suit Room New. Daily Price: ");
                           cout<<hotel.getSuitRoomPrice();
                           
                           gf.blink("Suit Room Daily Price Changed");
                           };                            
void  menuSettings_7_chngLuxs()
 {
                           gf.footCaption("New Lux. Room Price: ");
                           cin>>roomPrice;
                           gf.showOnScreen("Lux Room Old. Daily Price: ");
                           cout<<hotel.getLuxRoomPrice();
                           
                           hotel.setLuxRoomPrice(roomPrice);
                           gf.showOnScreen("Lux Room New. Daily Price: ");
                           cout<<hotel.getLuxRoomPrice();
                           
                           gf.blink("Lux Room Daily Price Changed");
                           };                            
void  menuSettings_8_chngStandards()
 {
                            gf.footCaption("New Standard Room Price: ");
                           cin>>roomPrice;
                           gf.showOnScreen("Standard Room Old. Daily Price: ");
                           cout<<hotel.getStandardRoomPrice();
                           
                           hotel.setStandardRoomPrice(roomPrice);
                           gf.showOnScreen("Standard Room New. Daily Price: ");
                           cout<<hotel.getStandardRoomPrice();
                           gf.blink("Standard Room Daily Price Changed");
                           }; 
void menuStatics_1_roomPerct()
{
takeAgainRoomNumber:
                    
     gf.footCaption("Room Number like ->\"10011\": "); 
     int _roomNumber=0;
     cin>>_roomNumber;
     if(!(hotel.isValidRoomNumber(_roomNumber)))
     {
     gf.blink("Error: There is no such numbered room!!!"); 
     goto takeAgainRoomNumber;   
     };

     gf.footCaption("Which Month [1-12]: "); 
     int month;
     cin>>month;
     
     int perct = hotel.getStatistikInfos(_roomNumber,month);
     gf.showOnScreen("This Room Reserved ");
     cout<<perct<<"%"<<" in "<<Date::getMonthName(month);
     };
void menuStatics_2_typePerct()
{
     gf.footCaption("Room Type [1-4]: "); 
     int roomType=0;
     cin>>roomType;

     gf.footCaption("Which Month [1-12]: "); 
     int month;
     cin>>month;
     
     int perct = hotel.getStatistikInfos_Type(roomType,month);
     gf.showOnScreen("This Room Types Reserved ");
     cout<<perct<<"%"<<" in "<<Date::getMonthName(month);    
     };
void finish()
{
           gf.clearScreen();
           int a = 0;
           gf.home();
           while(a!=50)
           {
               a++;
               gf.goRight();
               gf.setcolor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
               gf.goDown();
               cout<<"THANK";
               gf.wait(50);
               gf.goRight();
               gf.setcolor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
               gf.goDown();
               cout<<"THANK";
               gf.wait(50);
               gf.goRight();
               gf.setcolor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
               gf.goDown();
               cout<<"YOU";
               gf.wait(50);
               gf.goRight();
               gf.setcolor(FOREGROUND_RED | FOREGROUND_INTENSITY);
               gf.goDown();
               cout<<"YOU";
               };
               
           };
