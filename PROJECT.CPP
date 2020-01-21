#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<fstream.h>

int in,count;
class show{
	int ab, noofseats, noseats[28]; //noseats[0] is not used for making the code less complex
	float d;
	int a,f,g,h,i;
	char na[20],ad[50],em[30],nu[20];
/*
Glossary:

ab=stores price of ticket.
noofseats=stores the noofseats.
a,f=stores the choice entered by the user after selecting any options displayed on the screen.
g=stores the credit card id
h=stores the password of the credit card.
i=variable used in loops.
in=movie choosen.
count=couter for array operations
noseats[array]=stores the specific postion of the seat which user books/selects.
-----------------------------
Following are used for entering details from the user:
na=name of the user.
ad=address of the user.
em=email id of the user.
nu=number of the user.
*/

	public:

	void aftercheckseats();
	void mainpage();
	void options();
	void disp();
	void movie();
	void details();
	void recipt();
	void choice();
	void fillseat(int);
/*
Function color used for randomizing color of seats on the output screen.
Here the program stores a random no between 1 and 3 and then stores it in a
Then the condition is checked. 1=Displayes red. Rest=displayes white.
This code enables us to toggle between the color red and white randomly.
*/
	void color(){
		int a;
		randomize();
		for(int i=1; i<=3; i++){
			a=1+random(i);       //storing of random number between 1 and 3.
		}
		if(a==1){
			setfillstyle(SOLID_FILL, RED);
			noseats[count]=0;
			count++;
		}   //Setfillstyle is used to fill certain object, here bar, to a certain color.
		else{
			setfillstyle(SOLID_FILL, WHITE);
			noseats[count]=1;
			count++;

		}
	}
	void layout();
	void checkseats();
} s;




void main(){
	int gdriver = 0, gmode;         //Initialization of graphics.
	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	int ch; char ch1;
	show s;
	do{
		cleardevice();
		s.mainpage();                      //Calling function mainpage.
		s.movie();
		cout<<"Press (Y/y) to continue to main menu, else press any keyword to exit->";
		cin>>ch1;
	} while(ch1=='y'||ch1=='Y');
	getch();
	closegraph();    //Closegraph closes graphics.
}


void show::mainpage()
{
	setcolor(6);
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	for(int i=165,j=0; j<=40; j++){    //Loop used to create animation, here text coming down.
		delay(100);
		cleardevice();
		outtextxy(i,j,"BOOK MY MOVIE.COM!");
	}
	delay(300);
	setcolor(BLUE);
	settextstyle(7,HORIZ_DIR,5);
	outtextxy(220,100,"PROJECT");
	setcolor(RED);
	settextstyle(6,HORIZ_DIR,2);
	outtextxy(280,170,"Made By");
	settextstyle(6,HORIZ_DIR,4);
	outtextxy(260,210,"SANYOG");
	settextstyle(6,HORIZ_DIR,2);
	outtextxy(310,250,"&");
	settextstyle(6,HORIZ_DIR,4);
	outtextxy(260,290,"RADHIKA");
	setcolor(GREEN);
	settextstyle(6,HORIZ_DIR,3);
	outtextxy(230,350,"Shop well smurfs :D");
	settextstyle(0,HORIZ_DIR,0);
	getch();
	cleardevice();
}

void show::movie(){
	count=1;
	gotoxy(1,1);
	cleardevice();
	cout<<"WE WELCOME YOU! \n \n";
	cout<<"MOVIE SELECTION PAGE"<<endl;
	cout<<endl<<endl;
	cout<<endl<<"1.Gully Boy"<<endl<<"2.Bumblebee"<<endl<<"3.Simmba"<<endl;
	cout<<"--------------------------------------------------------------------------------\n";
	cout<<"Enter the movie of your choice->";
	cin>>in;
	switch(in)
	{
	default:
		cout<<"The choice you enter does not exists";
		break;
	case 1:
		cleardevice();
		outtextxy(140, 340,"YOU CHOSE-Gully Boy");
		delay(300);
		s.disp();
		break;
	case 2:
		cleardevice();
		outtextxy(140, 340,"YOU CHOSE-Bumblebee");
		delay(300);
		s.disp();
		break;
	case 3:
		cleardevice();
		outtextxy(140, 340, "YOU CHOSE-Simmba");
		delay(300);
		s.disp();
		break;
	}
}

void show::disp(){
	s.layout();
	s.checkseats();
	s.aftercheckseats();
}

void show::layout()
{       settextstyle(0, HORIZ_DIR,0);
	//display of seats
	for(int y=0;y<3;y++){
		for(int l=0;l<3;l++){
			for(int i=10+(l*190),j=50+(l*190); i<160+(l*190), j<200+(l*190); i+=50, j+=50){
				delay(200);
				color();
				bar(i,100+(y*60),j,140+(y*60));
			}
			char *no;
			for(i=28+(l*187), j=1+(y*9)+(l*3); i<=128+(l*187), j<=3+(y*9)+(l*3); j++, i+=50){
				itoa(j, no, 10);
				setcolor(4);
				outtextxy(i,117+(y*60), no);
			}
		}
	}
//------------------------------------------
	settextstyle(3,HORIZ_DIR,3);
	outtextxy(125,350,"Auditorium Seating Layout");
	settextstyle(0,HORIZ_DIR,0);
	outtextxy(70,390,"Red seats are booked seats.You can only book the white seats");

}

void show::checkseats(){
	int i;
	gotoxy(2, 1);
	cout<<"Enter no of seats (max 5)->";
	cin>>noofseats;
	gotoxy(45,1);
	int counter=1;
	int g;
	setfillstyle(SOLID_FILL, GREEN);
	for(i=0 ;i<noofseats; i++){
		gotoxy(45, counter);
		cout<<"Enter seat no."<<i+1<<"->";
		cin>>g;
		if(noseats[g]==0){
			gotoxy(0,2);
			cout<<"Seat not available! Choose another...";
			i--;
			continue;
		}else if(noseats[g]==1){
			gotoxy(0,2);
			cout<<"Successfully booked the seat.........";
			counter++;
			noseats[g]=2;
			fillseat(g);
		}else{
			gotoxy(0,2);
			i--;
			cout<<"Seat already choosen or invalid......";
			continue;
		}
	}
	gotoxy(1,4);
	cout<<"Options: 1. Proceed || 2. Rebook"<<endl<<"Enter option->";
	int a;
	cin>>a;
/*
If the user chooses proceed then the program proceeds further otherwise
if the user chooses rebook then the program calls the function layout again.
*/
	if(a==1){
		s.aftercheckseats();
	}else if(a==2){
		cleardevice();
		s.movie();
	}
}

void show::fillseat(int e){
	if((e%9)>=1&&(e%9)<=3){
		bar(10+(((e-1)%9)*50),100+(((e-1)/9)*60),50+(((e-1)%9)*50),140+(((e-1)/9)*60));
	}
	if((e%9)>=4&&(e%9)<=6){
		bar(50+(((e-1)%9)*50),100+(((e-1)/9)*60),90+(((e-1)%9)*50),140+(((e-1)/9)*60));
	}
	if((e%9)==7||(e%9)==8||(e%9)==0){
		bar(90+(((e-1)%9)*50),100+(((e-1)/9)*60),130+(((e-1)%9)*50),140+(((e-1)/9)*60));
	}
}

void show::aftercheckseats(){
	cleardevice();
	gotoxy(2,1); //For positioning the cursor at the top of the page.
	cout<<"Price per ticket=";
	ab=120;
	cout<<ab;
	cout<<endl;
	d=noofseats*ab;
	s.options();    //Calling function options to display options.
	cin>>a;
	if(a==9){
		s.movie();
	}
	else if(a==1){
		cleardevice();
		gotoxy(1,1);
		cout<<"BILLING PAGE";
		cout<<endl<<"BILLING OPTIONS->"<<endl;
		cout<<"1. Pay via credit card"<<endl;
		cout<<"2. Pay via cash on delivery"<<endl;
		cout<<"Enter your option->";
		cin>>f;
		if(f==1){
			cout<<"\nEnter the credit card no.->";  cin>>g;
			cout<<"\nEnter the password->";   cin>>h;
			s.details();
		}
		else{
			s.details();
		}
	}
}

void show::details(){
	int w;
	cout<<endl;
	//Entering of details so as to book the seats and print the recipt.
	cout<<"Enter your name->"; gets(na);
	cout<<"Enter your address->"; gets(ad);
	cout<<"Enter your contact no.->"; gets(nu);
	cout<<"Enter your e-mail id->"; gets(em);
	cout<<"\n\nPress 1 to confirm and get recipt:";
	cin>>w;
	if(w==1){
		s.recipt(); //Function call to invoke recipt function.
	}
}

void show::recipt(){
	settextstyle(0,HORIZ_DIR,0);  //To set the text to default output text.
	setcolor(WHITE);
	int ex,xp;  //ex and xp used while entering choice from user where some options are displayed.
	cleardevice();
	rectangle(145,10,500,470); //Rectagle function used to create the outline of the recipt.
	outtextxy(260, 30, "RETAIL INVOICE");
	outtextxy(165, 40, "BOOKMYSHOW.COM (FUTURE VALUE RETAIL LTD)");
	outtextxy(210, 50, "INTERNET GENERATED INVOICE");
	outtextxy(150, 80, "TELL NO:  011-30202600/601");
	outtextxy(150, 90, "HELPLINE:    1800 200 2255");
	outtextxy(150, 110,"--------------------------------------------");
	outtextxy(280, 130, "INFORMATION");
	delay(200);
	outtextxy(150, 140, "NAME:");
	delay(200);
	outtextxy(200, 140, na);  //na=name.
	delay(200);
	outtextxy(150, 150, "ADDRESS:");
	outtextxy(220, 150, ad);            //ad=address.
	delay(200);
	outtextxy(150, 160, "CONTACT NO:");
	delay(200);
	outtextxy(240, 160, nu);          //nu=number.
	delay(200);
	outtextxy(150, 170, "EMAIL-ID:");
	outtextxy(230, 170, em);          //em=email_id.
	for(int j=150; j<=490; j+=10){
		delay(20);
		outtextxy(j, 190, "-");
	}
	outtextxy(260, 210, " BILLING DETAILS");
	outtextxy(240, 220, "----------------------");
	outtextxy(150, 230, "TICKET PRICE");
	outtextxy(310, 230, "NO OF SEATS");
	outtextxy(410, 230, "NET AMOUNT");
	delay(200);
	char *qty, *amount, *netamt;

/*
qty pointer to ab, where ab stores the price of the ticket.
amount pointer to noofseats, where noofseats stores no of seats booked by the user.
netamt pointer to d, where d stores noofseats*price and hence displayes the total cost.
*/

/*
itoa is used to convert int to char, or basically to store numbers to a string pointer.
Syntax is
itoa(int<number which u want to convert>, char <string in which u wanted to store>, base <conversion base);
*/
	itoa(ab, qty, 10);
	outtextxy(200, 250, qty);
	delay(200);
	itoa(noofseats, amount, 10);
	outtextxy(330, 250, amount);
	delay(200);
	itoa(d, netamt, 10);
	outtextxy(420, 250, netamt);
	outtextxy(410, 270, "_________");
	for(j=411; j<=480; j+=10){
		delay(20);
		outtextxy(j, 280, "-");
	}
	itoa(d, netamt, 10);
	outtextxy(200, 290, "TOTAL");
	outtextxy(420, 290, netamt);

//barcode generation code ---------------------------------

	delay(300);
	for(i=280; i<=290; i+=4)
	line(i,310, i, 350);
	for(i=292; i<=294; i+=1)
	line(i,310, i, 350);
	for(i=298; i<=300; i+=1)
	line(i,310, i, 350);
	for(i=302; i<=310; i+=2)
	line(i,310, i, 350);
	for(i=313; i<=315; i+=1)
	line(i,310, i, 350);
	for(i=318; i<=330; i+=4)
	line(i,310, i, 350);
	for(i=332; i<=340; i+=2)
	line(i,310, i, 350);
	for(i=342; i<=344; i+=1+a)
	line(i,310, i, 350);

//End of barcode generation code-----------------------------------------------------------

	delay(300);
	outtextxy(198,380, "IT WAS OUR PLEASURE SERVING YOU");
	outtextxy(230,390, "NAYE INDIA KA NAYA BAZAR");
	outtextxy(228,400, "Cashier Name: GeraJi");
	outtextxy(200,410, "TILL NO.9");
	outtextxy(290,410, "RECIEPT NO: *******");
	outtextxy(198,430, "THANK YOU FOR SHOPPING WITH US");
	getch();
	cleardevice();
	gotoxy(2,1);
	cout<<endl;
	cout<<"\nPress 1 to save the receipt";
	cout<<"\nPress 9 to change the details";
	cout<<"\nPress any other key to book tickets again.";
	cout<<endl<<"Enter any option->";
	cin>>ex;
	if(ex==1){
		fstream f("receipt.txt",ios::out);
		f<<"\t\t RECEIPT";
		f<<"\n\t\t -------";
		f<<"\n\n Thanks For Choosing BOOKMYMOVIE!";
		f<<"\n\n\n NAME: "<<na;
		f<<"\n ADDRESS: "<<ad;
		f<<"\n CONTACT NO: "<<nu;
		f<<"\n EMAIL-ID: "<<em;
		f<<"\n\n\n BILLING DETAILS";
		f<<"\n\n TICKET PRICE: 120";
		f<<"\n NO. OF SEATS: "<<d/120;
		f<<"\n NET AMOUNT: "<<d;
		f<<"\n\n MOVIE: ";
		if(in==1){
			f<<"GULLY BOY";
		}else if(in==2){
			f<<"BUMBLE BEE";
		}else if(in==3){
			f<<"SIMMBA";
		}
		f<<"\n SEATS SELECTED: ";
		for(int i=1;i<=27;i++){
			if(noseats[i]==2){
				f<<i<<",";
			}
		}
		f.close();
		cout<<"\nWe have booked your ticket and saved the receipt. Thank you for shopping with us. ^.^"<<endl;
		cout<<"\n(Receipt saved as receipt.txt)";
		cout<<"\n--------------------------------------------------------------------------------\n";
		cout<<"\nPress 1 to exit";
		cout<<"\nPress any other key to book tickets again\n";
		cout<<"--------------------------------------------------------------------------------\n";
		cout<<endl<<"Enter any option->";
		cin>>xp;
		if(xp==1){
			exit(0);
		}else{
			s.movie();
		}
	}
	else if(ex==9){
		clrscr();
		s.details();
	}
	else{
		s.movie();
	}
}

void show::options(){
	cout<<"--------------------------------------------------------------------------------\n";
	cout<<endl<<"Enter 1 to continue ";
	cout<<"\nPress 9 for back menu";
	cout<<"\nPress any other key to exit";
	cout<<"\n--------------------------------------------------------------------------------\n";
	cout<<"Enter your option->";
}