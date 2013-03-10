//FIRAT KARAKUSOGLU
//0401020037
//16.1.2007      
 
#include <cstdlib> 
#include <iostream>
#include <conio.h>      
#include "menus.h"  
           
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
 
using namespace std;      
                   
  
int main(int argc, char *argv[])          
{ 
   gf.clrscr();  
   gf.setcolor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
   colcout.setcursor(col_ostream::CURSOR_OFF); 
   gf.headCaption("HOTEL IS SETTING..."); 
   gf.settitle(spc4"HOTEL PROJECT - FIRAT KARAKUSOGLU");
   
   gf.box(5,5,75,20); //center - out box      
   gf.box(7,6,27,19); //left - menu box     
   gf.box(29,6,73,19); //right - screen box
   
takeSettings:    
                 
    gf.footCaption("Do you want to set with the default Hotel Infos [Y/N]: "); 
           
    char userChoice;        
    userChoice = getch();
    if(userChoice == 'y' || userChoice == 'Y')
    defaultSettings();
    else if(userChoice == 'n' || userChoice == 'N')    
    specialSettings();     
    else { gf.blink("Press Y or N !!!"); goto takeSettings;};    
      
beginning:
                          
    gf.leftMenu("1.Reservations*2.Check In*3.Services*4.Check Out*5.Hotel Settings*6.Statistic Infos*7.Exit#");
    gf.footCaption("Enter your choice [1-7]: ");
    userChoice = getch();    
    putchar(userChoice); gf.wait(100);
    gf.clearScreen();  
     
    if(userChoice == '1')          
    { 
                  gf.leftMenu("1.New Res.*2.Cancel Res.*3.View Res. Infos#");
                  gf.footCaption("Enter your choice [1-3]: ");
                  userChoice = getch();      
                  putchar(userChoice);  gf.wait(100); 
                  if(userChoice == '1')  menuReservation_1_makeReservation(); 
                  if(userChoice == '2')  menuReservation_2_cancelReservation();
                  if(userChoice == '3')  menuReservation_3_viewReservation();
                  userChoice = 'a';
                  };   
     
    if(userChoice == '2')          
    { 
                  menuService_1_checkIn();    
                  userChoice = 'a';
                  };
    
    if(userChoice == '3')                     
    {   
                  gf.leftMenu("1.Make Service.*2.Add Service.*3.View Service*4.See All Services#");
                  gf.footCaption("Enter your choice [1-4]: ");
                  userChoice = getch();      
                  putchar(userChoice);  gf.wait(100);   
                  if(userChoice == '1')  menuService_1_makeService();
                  if(userChoice == '2')  menuService_2_addService();
                  if(userChoice == '3')  menuService_4_viewService(); 
                  if(userChoice == '4')  menuService_5_viewAllServices();   
                  userChoice = 'a';          
                  };
     if(userChoice == '4')   
     {  
                   menuService_1_checkOut();           
                   userChoice = 'a';
                   };
     if(userChoice == '5')     
     {
                   gf.leftMenu("1.Hotel Infos*2.Change Infos.*3.Add Floor*4.Add Room*5.Add Service*6.View Services*7.Room Prices#");
                   gf.footCaption("Enter your choice [1-7]: ");
                   userChoice = getch(); 
                   if(userChoice == '1') menuSettings_1_displayHotelInfos();
                   if(userChoice == '2') 
                   { 
                                 gf.leftMenu("1.Change Name*2.Change Address*3.Change Phone.#"); 
                                 gf.footCaption("Enter your choice [1-3]: ");  
                                 userChoice = getch();
                                 
                                   if(userChoice == '1') menuSettings_1_chName();
                                   if(userChoice == '2') menuSettings_2_chAddress();
                                   if(userChoice == '3') menuSettings_3_chPhone(); 
                                   userChoice = 'a';
                                 };  
                   if(userChoice == '3') menuSettings_3_addFloor();
                   if(userChoice == '4') menuSettings_4_addRooms(); 
                   if(userChoice == '5') menuSettings_5_addService();
                   if(userChoice == '6') menuSettings_6_viewService();    
                   if(userChoice == '7')  
                   { 
                                 gf.leftMenu("1.View King's*2.View Suit's*3.View Lux's*4.View Standard's*5.Change King's*6.Change Suit's*7.Change Lux's*8.Change Standard's*#"); 
                                 gf.footCaption("Enter your choice [1-8]: ");  
                                 userChoice = getch();                              
                                  
                                 if(userChoice == '1') menuSettings_1_viewKings();
                                 if(userChoice == '2') menuSettings_2_viewSuits();
                                 if(userChoice == '3') menuSettings_3_viewLuxs();
                                 if(userChoice == '4') menuSettings_4_viewStandards();
                                 
                                 if(userChoice == '5') menuSettings_5_chngKings();                            
                                 if(userChoice == '6') menuSettings_6_chngSuits();                            
                                 if(userChoice == '7') menuSettings_7_chngLuxs();                            
                                 if(userChoice == '8') menuSettings_8_chngStandards();                            
                                 userChoice = 'a';
                                 }; 
                   }; 
     if(userChoice == '6')    
     {
                   gf.leftMenu("1.Room Res. Perc.*2.Types Res. Perc.#");
                   
                  gf.footCaption("Enter your choice [1-2]: ");  
                  userChoice = getch();                              
                  
                  if(userChoice == '1') menuStatics_1_roomPerct();
                  if(userChoice == '2') menuStatics_2_typePerct(); 
                  userChoice = 'a';                   
                  };
     if(userChoice == '7') { finish(); return 0; };

goto beginning;
    
    getch(); 
    system("PAUSE"); 
    return EXIT_SUCCESS;
}
