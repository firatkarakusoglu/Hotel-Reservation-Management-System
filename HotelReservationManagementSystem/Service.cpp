#include <stdlib.h>
#include <cstring>
using namespace std;

struct structService
{
       char serviceName[50];
       double servicePrice;
       int serviceId;
       bool involveKing;
       bool involveSuit;
       bool involveLux;
       bool involveStandard;
       };
typedef structService service;
class Service
{
      private:
              service thisService;
              static int numberOfServices;
      protected:
      public:
             Service();
             ~Service();
             
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
      };
int Service::numberOfServices = 0;
Service::Service(){ numberOfServices++; };
Service::~Service(){};
 
 void Service::setServiceName(char * _serviceName) { strcpy(thisService.serviceName,_serviceName); };
 void Service::setServicePrice(double _servicePrice){};
 void Service::setInvolveKing(bool _involveKing){};
 void Service::setInvolveSuit(bool _involveSuit){};
 void Service::setInvolveLux(bool _involveLux){};
 void Service::setInvolveStandard(bool _involveStandard){};
 
 char * Service::getServiceName(){ return thisService.serviceName; };
 double Service::getServicePrice(){};
 int Service::getServiceId(){};
 bool Service::isInvolveKing(){};
 bool Service::isInvolveSuit(){};
 bool Service::isInvolveLux(){};
 bool Service::isInvolveStandard(){};
