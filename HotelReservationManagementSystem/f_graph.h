#include "col_iostream.h"
#include "stdlib.h"
#include "winbase.h"


class f_graph
{
      public:
             f_graph(){};
             
             void wait(int _miliSecond)
             {
                  Sleep(_miliSecond);
                  };
             
             void gotoxy(const int x, const int y){colcout.gotoxy(x,y);};
                             
             void goRight()
                {
                     int x;
                     int y;
                     x = colcout.wherex();
                     y = colcout.wherey();
                     colcout.gotoxy(x+1,y);
                     };
             void goLeft()
                {
                     int x;
                     int y;
                     x = colcout.wherex();
                     y = colcout.wherey();
                     colcout.gotoxy(x-1,y);
                     };                             
             void goUp()
                {
                     int x;
                     int y;
                     x = colcout.wherex();
                     y = colcout.wherey();
                     colcout.gotoxy(x,y-1);
                     };
                void goDown()
                {
                     int x;
                     int y;
                     x = colcout.wherex();
                     y = colcout.wherey();
                     colcout.gotoxy(x,y+1);
                     };

                void clearDimension(int x1,int y1,int x2,int y2)
                {
                	int i,j;
                	int x = colcout.getdimensionx();
                	int y = colcout.getdimensiony();
                	//cout<<"x : "<<x<<endl<<"y: "<<y;
                	colcout.gotoxy(x1,y1);
                	for(j = y1; j<=y2 ; j++)
                	{
                        for(i = x1;i<=x2;i++)
                    	{
                              colcout.gotoxy(i,j);
                              printf(" ");
                              }
                         };
                     //colcout.gotoxy(x,y);
                }

                void box(int x1,int y1,int x2,int y2)
                {
                	int i;
                	colcout.gotoxy(x1,y1); printf("%c",201);      //sol ust kose
                	for(i = x1+1;i<x2;i++) printf("%c",205); //ust satir
                	colcout.gotoxy(x2,y1); printf("%c",187); //sag ust kose
                	for(i= y1+1;i<y2;i++) //dikey cizgiler
                	{
                		colcout.gotoxy(x1,i);printf("%c",186);
                		colcout.gotoxy(x2,i);printf("%c",186);
                
                	}
                	colcout.gotoxy(x1,y2); printf("%c",200); //sol alt kosse
                	for(i=x1+1;i<x2;i++) printf("%c",205); //alt kose
                	colcout.gotoxy(x2,y2); printf("%c",188); //sag alt kose<
                }
                void leftMenu(char * menuList)
                {
                     clearDimension(7,6,27,19);
                     box(7,6,27,19);
                     int x = 0;
                     int beginy = 9;
                     int beginx = 9;
                     colcout.gotoxy(beginx,beginy-1);
                     cout<<"      MENU      "<<endl;
                     colcout.gotoxy(beginx,beginy++);
                     while(menuList[x] != '#')
                     {
                                       if(menuList[x] != '*')
                                       {
                                       colcout.gotoxy(beginx++,beginy);
                                       putchar(menuList[x]);
                                       }
                                       else
                                       {
                                           beginy ++;
                                           beginx = 9;
                                           }
                                       x++;
                                       };
                     }
                static int count;
                void showOnScreen(char *_shownInfo,int _controlKey=1,int _newBeginKey=0)
                {
                     if(_newBeginKey==1) { clearDimension(31,7,72,18); count=7; };
                     count++;
                     gotoxy(31,count);
                     
                     if(count == 18 && _controlKey == 0) 
                     {
                              count = 9;
                              //cout<<endl<<"kayma olayi";
                              clearDimension(31,7,72,18);
                              gotoxy(31,count);
                              }
                     if(count == 18 && _controlKey == 1) 
                     {
                              count = 8;
                              colcout.setcolor(FOREGROUND_RED | FOREGROUND_INTENSITY);
                              footSign("Press any key to go to the next page");
                              getch();
                              clearDimension(31,7,72,18);
                              colcout.setcolor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                              clearDimension(1,24,80,24);
                              gotoxy(31,count);
                              }
                              cout<<_shownInfo;
                     };
                void clearScreen()
                {
                     clearDimension(31,7,72,18);
                     };
                //caption make a caption with the name that has been given to it
                void headCaption(char headString[20])
                
                {
                	int strLength;
                	clearDimension(6,3,74,3);
                	box(5,2,75,4);
                	strLength = strlen(headString);
                	strLength =strLength / 2;
                	colcout.gotoxy((40 - strLength),3);
                	puts(headString);
                }
                void footCaption(char *footString)
                {
                	int strLength;
                	clearDimension(6,22,74,22);
                	box(5,21,75,23);
                	int dimX;
                	dimX = colcout.getdimensionx();
                	strLength = strlen(footString);
                	strLength =strLength;
                	colcout.gotoxy(8,22);
                	puts(footString);

                	colcout.gotoxy( strLength + 9,22);
                	//return (40 + strLength + 1);//this takes our arrow after writing
                }
                void footSign(char headString[20])
                {
                    colcout.setcolor(FOREGROUND_RED | FOREGROUND_INTENSITY);
                	char *ptrLetter;
                	int ctr=0;
                	int xAxes = 75;
                	ptrLetter = headString;
                	while(*ptrLetter != '\0') {
                	ptrLetter++;
                	ctr++;
                	}
                
                	for(;ctr != -1;ctr--)
                	{
                		colcout.gotoxy(xAxes,24);
                		printf("%c",*ptrLetter--) ;
                		xAxes--;
                	}
                	colcout.gotoxy(75,24);
                	colcout.setcolor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                }
                
                void blink(char bottomString[20])
                {
                     int i=0;
                     for(;i<1;i++)
                     {
                         colcout.setcolor(FOREGROUND_RED | FOREGROUND_INTENSITY);
                         footSign(bottomString);
                         Sleep(500);
                         clearDimension(1,24,75,24);
                         Sleep(700);
                         colcout.setcolor(FOREGROUND_RED | FOREGROUND_INTENSITY);
                         footSign(bottomString);
                         };
                         getch();
                         clearDimension(1,24,75,24);
                     }
                
                void setcolor(const WORD wAttributes){colcout.setcolor(wAttributes);};
                
                   // clears console window with special color
                   void clrscr(const WORD wAttributes){colcout.clrscr(wAttributes);};
                
                   // clears console window (white text on black background)
                   void clrscr(void){colcout.clrscr();};
                
                   // sets cursor to given position
                   // (1, 1) means upper left corner
                   //void colcout.gotoxy(const int x, const int y){colcout.colcout.gotoxy(x,y);};
                
                   // sets cursor to (1, 1)
                   void home(void) {colcout.home();};
                
                   // gets current cursor position (X)
                   int wherex(void){colcout.wherex();};
                
                   // gets current cursor position (Y)
                   int wherey(void){colcout.wherey();};
                
                   // gets current screen dimension (X)
                   int getdimensionx(void){colcout.getdimensionx();};
                
                   // gets current screen dimension (Y)
                   int getdimensiony(void){colcout.getdimensiony();};
                
                   // sets title of console window
                   void settitle(const char* title){colcout.settitle(title);};
                     
      };
int f_graph::count = 7;
f_graph gf;


