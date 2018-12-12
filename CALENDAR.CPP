		   /*         CALENDAR         */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>

#define  gt  gotoxy
#define  tc  textcolor
#define  tb  textbackground

struct dosdate_t date ;
/*Function shows current time*/
void cur_time()
{
	char *mer = (char *)malloc(2*sizeof(char)) ;
	while( !kbhit() )
	{
	    struct dostime_t t ;
	    _dos_gettime(&t) ;
	    gt (28,21);
	    tb( 0 );
	    tc(15);
	    if (t.hour<12)
		 mer = "AM";
	    else
		strcpy (mer,"PM");
	    if (t.hour>12)
		t.hour = t.hour - 12 ;
	    cprintf (" Current Time: %d:%02d:%02d  %s",t.hour,t.minute,t.second,mer) ;
	}
}

void public_day() ;
	//****************** main ******************
void main()
{
	/*Declare the name of day*/
	char *day[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"} ;
	/*Declare the name of month*/
	char *month[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"} ;
	char ca[]="Calendar of year" ;
	/*declare how many day per month*/
	long tdm[] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
	long year,i,j,n,T,Startday,color,k=0,ch,endday,to,lastday ;
	tb(0);
	window(0,0,80,25);
	clrscr();
	tc(15) ;
	gt(16,5);
	cprintf(" This program is show calendar of each years");
	gt(22,3);
	cprintf("DR. VIRENDRA SWARUP EDUCATION CENTER");
	gt(23,18);
	tc(3);
	cprintf(" Prepared by:");
	gt(37,18);
	tc(10);
	cprintf("Ashwani Tripathi ");

	start:
	_setcursortype(_NORMALCURSOR);
	tc(6);
	gt(18,10);
	cprintf("ษออออออออออออออออออออออออออออออออออป");
	gt(18,11);
	cprintf("บ                                  บ");
	gt(18,12);
	cprintf("วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ");
	gt(18,13);
	cprintf("บ                                  บ");
	gt(18,14);
	cprintf("ศออออออออออออออออออออออออออออออออออผ");

	iy:
	gt(42,11);
	clreol() ;
	gt(53,11);
	tc(6);
	cprintf("บ");
	gt(20,11);
	tc(15);
	cprintf("Please enter the year:");
	gt(42,11);
	scanf("%ld",&year);
	if (year<=0 || year>=999999999)
	goto iy ;

	im:
	gt(40,13);
	clreol();
	gt(53,13);
	tc(6);
	cprintf("บ");
	gt(20,13);
	tc(15);
	cprintf("and enter the month:");
	gt(40,13);
	scanf("%ld",&k);

	if (k<1 || k>12)
		goto im ;
	else
		k-- ;

	_setcursortype(_NOCURSOR) ;
	clrscr();
	for (i=0;i<strlen(ca);i++)
	{
		 gt(30+strlen(ca)-1-i,2);
		 cprintf("%c",ca[strlen(ca)-1-i]);
		 delay(30);

	}
	for (i=0;i<strlen(ca);i++)
	{
		 gt(30+strlen(ca)-1-i,2);
		 cprintf(" ");
		 delay(30);
	}
	for (i=0;i<strlen(ca);i++)
	{
		 gt(30+i,2);
		 cprintf("%c",ca[i]);
		 delay(30);
	}
	gt(47,2);
	cprintf("%ld",year);

	tha:
	tb(14);
	tc(WHITE);
	gt(5,23);
	cprintf("  nput year ");
	gt(43,23);
	cprintf(" Public holiays ");
	gt(23,23);
	cprintf(" Current  ate ");
	gt(65,23);
	cprintf(" E it = Esc ");
	tc(10);
	gt(6,23);
	cprintf("I");
	gt(45,23);
	cprintf("u");
	gt(32,23);
	cprintf("d");
	gt(67,23);
	cprintf("x");
	tb(0);
	tc(3);
	gt(6,24);
	cprintf("฿฿฿฿฿฿฿฿฿฿฿฿");
	gt(17,23);
	cprintf("Ü");
	gt(24,24);
	cprintf("฿฿฿฿฿฿฿฿฿฿฿฿฿฿");
	gt(37,23);
	cprintf("Ü");
	gt(44,24);
	cprintf("฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿฿") ;
	gt(59,23);
	cprintf("Ü");
	gt(66,24) ;
	cprintf("฿฿฿฿฿฿฿฿฿฿฿฿")     ;
	gt(77,23) ;
	cprintf("Ü") ;
	gt(2,10)  ;
	cprintf("%c increase year" ,24) ;
	gt(65,10) ;
	cprintf("%c increase month",26) ;
	gt(2,12)  ;
	cprintf("%c decrease year" ,25) ;
	gt(65,12) ;
	cprintf("%c decrease month",27) ;
	tc(7)     ;
	gt(7,25)  ;
	cprintf("Prepared by: Ashwani Tripathi   ")   ;
	tt:
	tb(0);
	to=0;
	lastday = 0 ;
	/*Formula of the firstday(1 Jan)*/
	T = ((year-1)*365) + ((year-1)/4) - ((year-1)/100) + ((year-1)/400) + 1 ;
	Startday = T % 7 ;
	/*Form of Leap year or not*/
	tdm[1]=(!((year%4) || !(year%100) && (year%400)))? 29 :  28 ;

	if(k>0)
	{
		for (i=0;i<k;i++) to = to + tdm[i] ;
		lastday = to % 7 ; }
		Startday = Startday + lastday ;
		_dos_getdate(&date) ;
		j = 0 ;
		tb(0) ;
		tc(15) ;
		gt(47,2) ;
		clreol() ;
		gt(30,2) ;
		cprintf("Calendar of year %ld",year) ;
		gt(36,3) ;
		cprintf(" ฤฤฤฤฤฤ") ;
		gt(39,4) ;
		cprintf("%s",month[k]) ;
		/*the last day in the month*/
		endday = tdm[k] ;

		tc(11)   ;
		gt(21,5) ;
		cprintf("ษอออออออออออออออออออออออออออออออออออออป") ;
		gt(21,6) ;
		cprintf("บ                                     บ") ;
		gt(21,7) ;
		cprintf("วฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤถ") ;
		gt(22,8) ;
		cprintf("                                     "  ) ;
		for (i=0;i<10;i++)
		{
			gt(21,10+i) ;
			cprintf("                                       "  ) ;
		}

		for (i=0;i<7;i++)
		{
			if (i==0) color = 12 ;
			else color = 7 ;
			gt(24+5*i,6) ;
			tc(color) ;
			cprintf("%s",day[i]) ;
		}
		for(i=1;i<=endday;i++)
		{
			if(Startday>6)
			{
				Startday = Startday - 7 ;
				j++ ;
			}

			if(Startday==0)
				color = 12 ;
			else
				color = 7 ;
			/*public day*/
			if(year>1993)
				{
					if(k==0)
					if(i==1 || i==7)
						color = 12 ;
					if(k==2)
					if(i==8)
					color = 12 ;
					if(k==3)
					if(i==13 || i==14 || i==15 || i==16 || i==30)
					color = 12 ;
					if(k==4)
					if(i==1)
					color = 12 ;
					if(k==5)
					if(i==1 || i==18)
					color = 12 ;
					if(k==8)
					if(i==24)
					color = 12 ;
					if(k==9)
					if(i==23 || i==30 || i==31)
					color = 12 ;
					if(k==10)
					if(i==1 || i==9)
					color = 12 ;
					if(k==11)
					if(i==10)
					color = 12 ;
			}
		if(Startday==0) color = 12 ;
		if(i==1) j = 0 ;
		/*show the current date*/
		((i==date.day) && ((k+1)==date.month) && (year==date.year)) ?
			tb(9) : tb(0) ;
		/*Output calendar of each month*/
		gt(25+5*Startday,8+2*j) ; tc(color) ; cprintf("%ld",i) ;

		Startday++ ;
		}

	tc(11) ; tb(0) ;
	for (i=8;i<=8+2*j;i++) { gt(21,i) ; cprintf("บ") ;
				 gt(59,i) ; cprintf("บ") ; }
	gt(21,8+2*j+1) ; cprintf("ศอออออออออออออออออออออออออออออออออออออผ") ;
     again:
	cur_time() ;       /*call function for time*/

	ch = getch() ;
	if(ch==77)
	      { if (k<11) k++ ;
		else { k=0 ; year++ ; }
		goto tt ; }
	else if(ch==72) { year++  ; goto tt ; }
	else if(ch==80) {
		if(year>1) year-- ; goto tt ; }
	else if(ch==75) {
		if(k>0) k = k - 1 ;
		else { if(year>1) { year-- ; k = 11 ; }
		       else k=0   ; }
		       goto tt    ; }
	else if(ch==27  || ch=='x' || ch=='X') exit(1) ;
	else if(ch=='d' || ch=='D') { k=date.month-1 ; year=date.year ; goto tt ; }
	else if(ch=='I' || ch=='i') { clrscr() ; goto start; }
	else if(ch=='u' || ch=='U') { public_day() ; clrscr() ; goto tha ; }
	else goto again ;
	}
	/****************** End main *******************/
void public_day ()
    {
    int i,j = 0 ;
    clrscr() ;
    tc(3) ; gt(3,5)  ; cprintf("ษ") ;
	    gt(78,5) ; cprintf("ป") ;
    for(i=0;i<74;i++) { gt(4+i,5) ; cprintf("อ") ; gt(4+i,21) ; cprintf("อ") ; }
    for(i=0;i<15;i++) { gt(3,i+6) ; cprintf("บ") ; gt(78,i+6) ; cprintf("บ") ;
			gt(41,i+6); cprintf("ณ") ; }
    gt(3,21) ; cprintf("ศ") ; gt(78,21) ; cprintf("ผ") ;
    gt(41,5) ; cprintf("ั") ; gt(41,21) ; cprintf("ฯ") ;
       tc(1) ; gt(7,7)  ; cprintf("1-Jan : ") ;
       tc(7) ; cprintf("New Year")            ;
       tc(1) ; gt(7,9)  ; cprintf("7-Jan : ") ;
       tc(7) ; cprintf("Liberation Day")      ;
       tc(1) ; gt(7,11) ; cprintf("8-Mar : ") ;
       tc(7) ; cprintf("Women's Day")         ;
       tc(1) ; gt(7,13) ; cprintf("13,14,15,16 Apr : ") ;
       tc(7) ; cprintf("Khmer New Year")      ;
       tc(1) ; gt(7,15) ; cprintf("30-Apr : ");
       tc(7) ; cprintf("Royal Plowing Day")   ;
       tc(1) ; gt(7,17) ; cprintf("1-May : ") ;
       tc(7) ; cprintf("Labor Day")           ;
       tc(1) ; gt(7,19) ; cprintf("1-Jun : ") ;
       tc(7) ; cprintf("Children's Day")      ;
       tc(1) ; gt(44,7) ; cprintf("18-Jun : ");
       tc(7) ; cprintf("Queen's Birthday")    ;
       tc(1) ; gt(44,9) ; cprintf("24-Sep : ");
       tc(7) ; cprintf("Royal Re-coronation Day") ;
       tc(1) ; gt(44,11); cprintf("23-Oct : ");
       tc(7) ; cprintf("Paris Peace Accord")  ;
       tc(1) ; gt(44,13); cprintf("30,31-Oct : ");
       tc(7) ; cprintf("King's Birthday")     ;
       tc(1) ; gt(44,15); cprintf("1-Nov : ") ;
       tc(7) ; cprintf("King's Birthday")     ;
       tc(1) ; gt(44,17); cprintf("9-Nov : ") ;
       tc(7) ; cprintf("Independence Day")    ;
       tc(1) ; gt(44,19); cprintf("10-Dec : ");
       tc(7) ; cprintf("Human Rights Day")    ;
    gt(18,23); cprintf("All of these days started to practice since 1994") ;
       tc(14+BLINK) ; gt(28,24) ; cprintf("Press Any Key to go back.....") ;

    while(!kbhit()){
	if(i>15) i = 1 ;
	if(j>10) j = 0 ;
	tc(15) ; gt(34,4)  ; cprintf("    ออออออ     ") ;
	tc(i)  ; gt(34,3)  ; cprintf("PUBLIC HOLIDAYS") ;
	tc(j)  ; gt(35+j,4); cprintf("อ")               ;
	i++    ; j++       ; }
	}
	//************** End of Program ************