#include <ctime>

using namespace std;

class Date 
{
      public:
        Date(void);
        Date(int d, int m, int y);
        void Disp(void) const;
        int day, month, year;
        static int thisDay, thisMonth, thisYear;
        
           static int getThisDay() { return thisDay; };
           static int getThisMonth() { return thisMonth; };
           static int getThisYear() { return thisYear; };    
           
           void setDay(int _day) { day = _day; };
           void setMonth(int _month) { month = _month; };
           void setYear(int _year) { year = _year; };
           
           int getDay() { return day; };
           int getMonth() { return month; };
           int getYear() { return year; };
           
           static char *getMonthName(int _monthOrder)
           {
                  switch(_monthOrder)
                  {
                                     case 1:
                                          return ("January");
                                          break;
                                     case 2:
                                          return ("February");
                                          break;
                                     case 3:
                                          return ("March");
                                          break;
                                     case 4:
                                          return ("April");
                                          break;
                                     case 5:
                                          return ("May");
                                          break;
                                     case 6:
                                          return ("June");
                                          break;
                                     case 7:
                                          return ("July");
                                          break;
                                     case 8:
                                          return ("August");
                                          break;
                                     case 9:
                                          return ("September");
                                          break;
                                     case 10:
                                          return ("October");
                                          break;
                                     case 11:
                                          return ("November");
                                          break;
                                     case 12:
                                          return ("December");
                                          break;
                                     default:
                                          return ("Wrong Month Order!!!");
                                          break;
                                     };
                  };
           
           friend ostream & operator << (ostream & _output, Date & _date);
           
           bool operator==(Date &date)
           {
                if(this->day == date.day && this->month == date.month && this->year == date.year) return true;
                else return false;
                };
           
           bool operator!=(Date &date)
           {
                if(this->day == date.day && this->month == date.month && this->year == date.year) return false;
                else return true;
                };

           int operator-(Date &date)
           {
               int counter = 0;
               if(date<*this)
               {
                             while(*this != date)
                             {
                                         counter++; 
                                         date++;
                                         };
                             };
               return counter;
                };
             
           bool operator<(Date &date)
           {
                if(!(this->day == date.day && this->month == date.month && this->year == date.year))
                {
                               if(this->year < date.year) return true;
                               else if(this->year == date.year && this->month < date.month) return true;
                               else if(this->year == date.year && this->month == date.month && this->day < date.day) return true;
                               else return false;
                               }
                else return false;
                };
           bool operator<=(Date &date)
           {
                if((*this<date) || (*this == date)) return true;
                else return false;
                };
           bool operator>(Date &date)
           {
                if(!(this->day == date.day && this->month == date.month && this->year == date.year))
                {
                               if(this->year > date.year) return true;
                               else if(this->year == date.year && this->month > date.month) return true;
                               else if(this->year == date.year && this->month == date.month && this->day > date.day) return true;
                               else return false;
                               }
                else return false;
                };       
                
           bool operator>=(Date &date)
           {
                if((*this>date) || (*this == date)) return true;
                else return false;
                };    
                
           Date operator++(int)
           {
                //31,28-29,31,30,31,30,31,31,30,31,30,31
                switch (this->month)
                {
                       case 1:
                            if(this->day < 31 && this->day > 0) (this->day)++;
                            else { this->day = 1; (this->month)++; };
                            break;
                       case 2:
                            if(((this->year)%4) == 0)
                            {
                                if(this->day < 29 && this->day > 0) (this->day)++;
                                else { this->day = 1; (this->month)++; };         
                                }
                            else
                            {
                                if(this->day < 28 && this->day > 0) (this->day)++;
                                else { this->day = 1; (this->month)++; };         
                                };
                            break;
                       case 3:
                            if(this->day < 31 && this->day > 0) (this->day)++;
                            else { this->day = 1; (this->month)++; };
                            break;
                       case 4:
                            if(this->day < 30 && this->day > 0) (this->day)++;
                            else { this->day = 1; (this->month)++; };
                            break;
                       case 5:
                            if(this->day < 31 && this->day > 0) (this->day)++;
                            else { this->day = 1; (this->month)++; };
                            break;
                       case 6:
                            if(this->day < 30 && this->day > 0) (this->day)++;
                            else { this->day = 1; (this->month)++; };
                            break;
                       case 7:
                            if(this->day < 31 && this->day > 0) (this->day)++;
                            else { this->day = 1; (this->month)++; };
                            break;
                       case 8:
                            if(this->day < 31 && this->day > 0) (this->day)++;
                            else { this->day = 1; (this->month)++; };
                            break;
                       case 9:
                            if(this->day < 30 && this->day > 0) (this->day)++;
                            else { this->day = 1; (this->month)++; };
                            break;
                       case 10:
                            if(this->day < 31 && this->day > 0) (this->day)++;
                            else { this->day = 1; (this->month)++; };
                            break;
                       case 11:
                            if(this->day < 30 && this->day > 0) (this->day)++;
                            else { this->day = 1; (this->month)++; };
                            break;
                       case 12:
                            if(this->day < 31 && this->day > 0) (this->day)++;
                            else { this->day = 1; this->month = 1; (this->year)++;};
                            break;
                       default:
                               cout<<endl<<"There is an error while increasing the date";
                               break;
                       };
                       return *this;
                
                };
                
        ostream & operator << (Date & _date)
        {
        if(_date.day<10)cout<<"0"<<_date.day<<"."<<_date.month<<"."<<_date.year;
        else cout<<_date.day<<"."<<_date.month<<"."<<_date.year;
        
         return cout;
        };
           
        static int today()
        {
               long t;
               t = time(NULL);
               struct tm *p = localtime(&t);
            
               thisDay = p -> tm_mday;
               thisMonth = p -> tm_mon + 1;
               thisYear = p -> tm_year + 1900;
               };
};
int Date::thisDay = 0;
int Date::thisMonth = 0;
int Date::thisYear = 0;

Date::Date(int d, int m, int y)
{
    today();
    day = d;
    month = m;
    year = y;
}

Date::Date(void)
{
    today();
    long t;

    t = time(NULL);
    struct tm *p = localtime(&t);

    day = p -> tm_mday;
    month = p -> tm_mon + 1;
    year = p -> tm_year + 1900;
}

ostream & operator << (ostream & _output, Date & _date)
{
         _output << _date.day<<"."<<_date.month<<"."<<_date.year;
         return _output;
}

void Date::Disp(void) const
{
     cout.precision(10);
    cout<<endl<<this->day<<"/"<<this->month<<"/"<<this->year;
}
