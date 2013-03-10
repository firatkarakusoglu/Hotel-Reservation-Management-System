#include "Hotel.h"

#define ob cout<<endl<<      
#define e <<endl<<     
#define ol <<endl          
    
#define i cin>>   
#define o cout<<
#define spc "          " //10
#define spc2 "                    " //20
#define spc3 "                              " //30
#define spc4 "                                        " //40
#define errMsg; cout<<endl<<endl<<spc"Error: Wrong choice please press \"Y or N\"";

Hotel hotel;

void defaultSettings()
{
     
      char *hotelName = new char[25];
      char *hotelAddress = new char[50];
      char *hotelPhoneNumber = new char[15];
      
      hotelName=("MAGIC HOTEL");
      hotelAddress = ("1. High Street. 21323. Building.");
      hotelPhoneNumber = ("+123111222333");
      
      hotel.setHotelName(hotelName);
      hotel.setHotelAddress(hotelAddress);
      hotel.setHotelPhoneNumber(hotelPhoneNumber);
      
      
      
      hotel.setKingRoomPrice(40);
      hotel.setSuitRoomPrice(30);
      hotel.setLuxRoomPrice(20);
      hotel.setStandardRoomPrice(10);
      
      int numberOfFloors = 2;
      hotel.addFloorsToTheHotel(numberOfFloors);  

      int kingRoomNumber,suitRoomNumber,luxRoomNumber,standardRoomNumber;
      kingRoomNumber = 1;
      suitRoomNumber = 1;
      luxRoomNumber = 1;  
      standardRoomNumber = 2; 
      for(int ctr=0; ctr<hotel.getHotelFloorNumber(); ctr++)
      {       
              hotel.addRoomToTheHotel(ctr+1,kingRoomNumber,1); //floor id, number of rooms, room type
              hotel.addRoomToTheHotel(ctr+1,suitRoomNumber,2);
              hotel.addRoomToTheHotel(ctr+1,luxRoomNumber,3);
              hotel.addRoomToTheHotel(ctr+1,standardRoomNumber,4);
              }; 
              
      hotel.addService("Car service",100,1,0,0,0 );  
      hotel.addService("Meat service",40,1,1,0,0);
      
      hotel.displayHotelInfos();  
      
      gf.headCaption(hotelName);
      //gf.blink("Default Settings Has Been Used.");
};//end - defaultSettings
void specialSettings() 
{   
    hotel.setKingRoomPrice(0);
    hotel.setSuitRoomPrice(0);
    hotel.setLuxRoomPrice(0);
    hotel.setStandardRoomPrice(0);
    ///////SPECIAL SETTINGS//////////// 
    char *hotelName = new char[25];
    gf.footCaption("What is the name of your hotel:"); 
    gets(hotelName);
    hotel.setHotelName(hotelName);
    gf.showOnScreen("Hotel Name: ",0);
    cout<<hotelName;
    gf.footCaption("What is the address of your hotel:");
    char *hotelAddress = new char[100];
    gets(hotelAddress);
    hotel.setHotelAddress(hotelAddress);
    gf.showOnScreen("Hotel Address: ",0);
    cout<<hotelAddress;
    
    gf.footCaption("What is the phone number of your hotel: ");
    char *hotelPhoneNumber = new char[15];
    gets(hotelPhoneNumber);
    hotel.setHotelPhoneNumber(hotelPhoneNumber); 
    gf.showOnScreen("Hotel Phone Number: ",0); 
    cout<<hotelPhoneNumber;
    
    gf.footCaption("How many floor your hotel has got:");
    int floorNumber;
    i floorNumber;
    hotel.addFloorsToTheHotel(floorNumber);
    gf.showOnScreen("Number Of Floors In The Hotel: ",0);
    cout<<floorNumber;

takeRoomInfos:
    
    gf.footCaption("Is the number of rooms on floors are the same [Y/N]:");
    char theNumberAreTheSame;
    theNumberAreTheSame = getch();
    
    if(theNumberAreTheSame == 'y' || theNumberAreTheSame == 'Y')
    {
        gf.footCaption("How many king rooms are there in the floors:");
        int kingRoomNumber;
        i kingRoomNumber;
        gf.showOnScreen("King Room Number On Each Floor: ",0);
        cout<<kingRoomNumber;
        
        gf.footCaption("How many suit rooms are there in the floors:");
        int suitRoomNumber;
        i suitRoomNumber;
        gf.showOnScreen("Suit Room Number On Each Floor: ",0);
        cout<<suitRoomNumber;
                
        gf.footCaption("How many lux. rooms are there in the floors:");
        int luxRoomNumber;
        i luxRoomNumber;
        gf.showOnScreen("Lux. Room Number On Each Floor: ",0);
        cout<<luxRoomNumber;
                
        gf.footCaption("How many standard rooms are there in the floors:");
        int standardRoomNumber;
        i standardRoomNumber;
        gf.showOnScreen("Standard Room Number On Each Floor: ",0);
        cout<<standardRoomNumber;
                  
        //ob "hotel floor number is" <<hotel.getHotelFloorNumber();
            for(int ctr=0; ctr<hotel.getHotelFloorNumber(); ctr++)
            {
                 hotel.addRoomToTheHotel(ctr+1,kingRoomNumber,1); //floor id, number of rooms, room type
                 hotel.addRoomToTheHotel(ctr+1,suitRoomNumber,2);
                 hotel.addRoomToTheHotel(ctr+1,luxRoomNumber,3);
                 hotel.addRoomToTheHotel(ctr+1,standardRoomNumber,4);
                 };          
        }
      else if(theNumberAreTheSame == 'n' || theNumberAreTheSame == 'N')
      {
           for(int ctr=0; ctr<hotel.getHotelFloorNumber(); ctr++)
           {
                gf.footCaption("How many king rooms are there in the ");
                cout<<ctr+1<<". floor: ";
                int kingRoomNumber;
                i kingRoomNumber;
                hotel.addRoomToTheHotel(ctr+1,kingRoomNumber,1);
                
                gf.footCaption("How many suit rooms are there in the ");
                cout<<ctr+1<<". floor: ";
                int suitRoomNumber;
                i suitRoomNumber;
                hotel.addRoomToTheHotel(ctr+1,suitRoomNumber,2);
                
                gf.footCaption("How many lux. rooms are there in the ");
                cout<<ctr+1<<". floor: ";
                int luxRoomNumber;
                i luxRoomNumber;
                hotel.addRoomToTheHotel(ctr+1,luxRoomNumber,3);
                
                gf.footCaption("How many standard rooms are there in the ");
                cout<<ctr+1<<". floor: ";
                
                int standardRoomNumber;
                i standardRoomNumber;
                hotel.addRoomToTheHotel(ctr+1,standardRoomNumber,4);
                }//end - for(int ctr=0; ctr<hotel.getHotelFloorNumber(); ctr++)
           }//end - else if(theNumberAreTheSame == 'n' || theNumberAreTheSame == 'N')
      else 
      { 
           gf.blink("Please press Y or N!!!");
           goto takeRoomInfos;
           };

           hotel.addService("Car service",100,1,0,0,0 );  
           hotel.addService("Meat service",40,1,1,0,0);                 
           hotel.addService("Bus service",15.1,1,1,0,0);
           hotel.addService("Garbage service",5,1,1,1,1);

           hotel.displayHotelInfos();    
           gf.headCaption(hotelName);
     };  
