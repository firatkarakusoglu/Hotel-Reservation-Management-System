#include <stdlib.h>
#include <cstring>
using namespace std;

class Service
{
      private:
              char *serviceName;
              double servicePrice;
              int serviceId;
            
                 bool involveKing;
                 bool involveSuit;
                 bool involveLux;
                 bool involveStandard;              
             
              //static int numberOfServices;
              
      protected:
      public:
             Service();
             Service(char *_serviceName, double _servicePrice, bool _involveKing, bool _involveSuit, bool _involveLux, bool _involveStandard);
             //~Service();
             
             //GET - SET METHODS
             void setServiceName(char * _serviceName);
             void setServicePrice(double _servicePrice);
             void setInvolveKing(bool _involveKing);
             void setInvolveSuit(bool _involveSuit);
             void setInvolveLux(bool _involveLux);
             void setInvolveStandard(bool _involveStandard);
             
             char * getServiceName();
             double getServicePrice();
             int getServiceId();
             bool isInvolveKing();
             bool isInvolveSuit();
             bool isInvolveLux();
             bool isInvolveStandard();
             //~GET - SET METHODS
             
             //PROPERTY FUNCTIONS
             bool isThisRoomIncludeThisService(int _roomType);
      };
//int Service::numberOfServices = 0;

Service::Service(){  };//numberOfServices++; serviceId = numberOfServices;
Service::Service(char *_serviceName, double _servicePrice, bool _involveKing, bool _involveSuit, bool _involveLux, bool _involveStandard)
{
             //numberOfServices++;
             //serviceId = numberOfServices; 
             
             serviceName = new char[strlen(_serviceName)+1];
            strcpy( serviceName , _serviceName);
             
             servicePrice = _servicePrice;
             
              involveKing = _involveKing;
              involveSuit = _involveSuit;
              involveLux = _involveLux;
              involveStandard = _involveStandard;              
             
             };
//Service::~Service(){ delete [] serviceName; };
 
 void Service::setServiceName(char * _serviceName) { serviceName = new char[strlen(_serviceName)+1]; strcpy(serviceName ,_serviceName);};
 void Service::setServicePrice(double _servicePrice){ servicePrice = _servicePrice; };
 void Service::setInvolveKing(bool _involveKing){ involveKing =_involveKing; };
 void Service::setInvolveSuit(bool _involveSuit){ involveSuit =_involveSuit; };
 void Service::setInvolveLux(bool _involveLux){ involveLux =_involveLux; };
 void Service::setInvolveStandard(bool _involveStandard){ involveStandard =_involveStandard; };
 
 char * Service::getServiceName(){ return serviceName; };
 double Service::getServicePrice(){return servicePrice;};
 int Service::getServiceId(){return serviceId;};
 
 bool Service::isInvolveKing(){return involveKing ;};
 bool Service::isInvolveSuit(){return involveSuit;};
 bool Service::isInvolveLux(){return involveLux;};
 bool Service::isInvolveStandard(){return involveStandard;};

 bool Service::isThisRoomIncludeThisService(int _roomType)
 {
      if(_roomType == 1) return involveKing;
      if(_roomType == 2) return involveSuit;
      if(_roomType == 3) return involveLux;
      if(_roomType == 4) return involveStandard;
      
      else cout<<endl<<"Error: Wrong room type.";
      };
