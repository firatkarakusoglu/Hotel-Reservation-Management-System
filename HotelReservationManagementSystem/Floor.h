#include "Room.h"

class Floor
{
      private:
              
              int numberOfRooms;
              
              int kingRoomNumber;
              int suitRoomNumber;
              int luxuryRoomNumber;
              int standardRoomNumber;
              
              int thisFloorSequence;
      public:
             Room *rooms;
             Floor();
             
             void addRoom(int _roomType);
             void addRooms(int _numberOfRooms, int _roomType);
             
             void setFloorSequence(int _floorSequence){ thisFloorSequence = _floorSequence; };
             void setNumberOfRooms(int _numberOfRooms) {numberOfRooms = _numberOfRooms;};
             int getFloorSequence(){return thisFloorSequence;};
             int getNumberOfRooms() {return numberOfRooms;};
             
             int getNumberOfKingRooms(){return kingRoomNumber;};
             int getNumberOfSuitRooms(){return suitRoomNumber;};
             int getNumberOfLuxRooms(){return luxuryRoomNumber;};
             int getNumberOfStandardRooms(){return standardRoomNumber;};
             
             void setNumberOfKingRooms(int _kingRoomNumber){kingRoomNumber = _kingRoomNumber;};
             void setNumberOfSuitRooms(int _suitRoomNumber){suitRoomNumber = _suitRoomNumber;};
             void setNumberOfLuxRooms(int _luxuryRoomNumber){luxuryRoomNumber = _luxuryRoomNumber;};
             void setNumberOfStandardRooms(int _standardRoomNumber){standardRoomNumber = _standardRoomNumber;};
             
             
      };
Floor::Floor()
{
              numberOfRooms = 0;
              kingRoomNumber = 0;
              suitRoomNumber = 0;
              luxuryRoomNumber = 0;
              standardRoomNumber = 0;              
              };

void Floor::addRoom(int _roomType)
{
             numberOfRooms++; //at the beginning it will be 1
             if(numberOfRooms == 1) rooms = new Room[1];
             else
             {
                 Room *tempRoomNumbers = new Room[numberOfRooms];
                 tempRoomNumbers = rooms;
                 rooms = new Room[numberOfRooms];
                 rooms = tempRoomNumbers;
                 };
         
             //cout<<endl<<endl<<"thisFloorSequence : "<<thisFloorSequence;
             //cout<<endl<<"numberOfRooms : "<<numberOfRooms;
             //cout<<endl<<"ODA URETILIYOR";
                 rooms[numberOfRooms-1].setSortOfRoom(_roomType);
                 rooms[numberOfRooms-1].setSequenceNumber(numberOfRooms);
                 rooms[numberOfRooms-1].setStairNumber(thisFloorSequence);
                 rooms[numberOfRooms-1].generateRoomNumber(thisFloorSequence, numberOfRooms,_roomType); //roomNumbers+1 = sequence number of the room
                 rooms[numberOfRooms-1].setNumberOfMadeReservations(0);
                 rooms[numberOfRooms-1].forStatisticInfos = new int[400];
                 //cout<<endl<<"Room number is : "<<rooms[numberOfRooms-1].getThisRoomNumber();
                // cout<<endl<<rooms[roomNumbers-1].getThisRoomNumber();  
         
     };
     
void Floor::addRooms(int _numberOfRooms, int _roomType)
{
     for(int ctr=0; ctr<_numberOfRooms; ctr++)
     {
             if(_roomType == 1) kingRoomNumber++;
             else if(_roomType == 2) suitRoomNumber++;
             else if(_roomType == 3) luxuryRoomNumber++;
             else if(_roomType == 4) standardRoomNumber++;
             
             addRoom(_roomType);
             };
     };
