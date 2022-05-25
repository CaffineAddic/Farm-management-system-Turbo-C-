#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
class cow{
int idc;
float milk;
float wgc;
float agc;
void enterc(int a);
public:
void entrecc();
void showc();
void func();
void findc();
void insc();
void delc();
void modc();
cow() //Constructor
{idc=0;
milk=0.0;
wgc=0.0;
agc=0.0;}
~cow()//Destructor
{ ; }};
void cow::enterc(int a)//Enter values
{cout<<"\nEnter the values of the cow with ID:"<<a;
idc=a;
re1:
cout<<"\nEnter the milk given:";
cin>>milk;
if(milk<=0|milk>50)
{cout<<"\nThe entered value is not valid enter a valid value.";
goto re1;}
re2:
cout<<"\nEnter the weight of the cow: ";
cin>>wgc;
if(wgc<=0|wgc>300)
{cout<<"\nThe entered value is not valid enter a valid value.";
goto re2;}
re3:
cout<<"\nEnter the age of the cow(In years): ";
cin>>agc;
if(agc<=0|agc>=25)
{cout<<"\nThe entered value is not valid enter a valid value.";
goto re3;}}
void cow::func()//Displaying the values
{cout<<"\nThe ID is: "<<idc<<" And the milk produced is: "<<milk<<" With the weight: "<<wgc<<" And the age is: "<<agc;}
void cow::entrecc()//Writting the data into a file
{ofstream f( "cow.dat",ios::binary);
cow s;
int i=1800;
char c;
do{
++i;
s.enterc(i);
f.write((char*)&s,sizeof(s));
cout<<"\nPress Y to enter data for a another cow othewise press any key.";
cin>>c;
}while(c=='y'|c=='Y');
f.close();}
void cow::showc()//Displaying data from the file
{ifstream f("cow.dat",ios::binary);
cow s;
f.read((char*)&s,sizeof (s));
while(!f.eof()){
s.func();
f.read((char*)&s,sizeof(s));}
f.close();}
void cow::findc()//Finding a particular value
{ifstream f("cow.dat",ios::binary);
int i,u=0;
cow s;
re:
cout<<"\nEnter the ID which has to be found:";
cin>>i;
if(i<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re;}
f.read((char*)&s,sizeof (s));
while(!f.eof())
{if(s.idc==i)
{s.func();
u=1;
break;}
f.read((char*)&s,sizeof(s));}
if(u!=1){cout<<"\nEntered record not found.";}
f.close();}
void cow::delc()//Deleting a record
{ifstream f("cow.dat",ios::binary);
ofstream t("re.dat",ios::binary);
int i,r=0;
char y;
cow s;
re:
cout<<"\nEnter the ID of the record to be deleted:";
cin>>i;
if(i<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re;}
f.read((char*)&s,sizeof(s));
while(!f.eof())
{if(s.idc==i){s.func();
cout<<"\nConfirm deletion, Press N to terminate the deletation process.";
cin>>y;
r=1;
if(y=='n'|y=='N')
t.write((char*)&s,sizeof(s));}
else
t.write((char*)&s,sizeof(s));
f.read((char*)&s,sizeof(s));}
f.close();
t.close();
remove("cow.dat");
rename("re.dat","cow.dat");
if(r!=1)
{cout<<"\nEntered value not found";}
cout<<"\nRECORD IS:";
s.showc();}
void cow::insc()//Instering a record in the data file
{ifstream f("cow.dat",ios::binary);
ofstream t("re.dat",ios::binary|ios::app);
cow s,stud;
char x='r';
int o,i=0;
re:
cout<<"\nEnter the ID for the new record:";
cin>>i;
s.enterc(i);
f.read((char*)&stud,sizeof(stud));
while(!f.eof()){
if(s.idc<stud.idc)
{t.write((char*)&s,sizeof(s));
x='t';
o=f.tellg();
break;}
else if(s.idc==stud.idc)
{cout<<"\nThe ID already exits pl re-enter.";
goto re;}
else
t.write((char*)&stud,sizeof(stud));
f.read((char*)&stud,sizeof(stud));}
o=o-sizeof(s);
f.seekg(o);
if(x=='r')
t.write((char*)&s,sizeof(s));
else if(!f.eof()){
f.read((char*)&stud,sizeof(stud));
while(!f.eof()){
t.write((char*)&stud,sizeof(stud));
f.read((char*)&stud,sizeof(stud));}}
f.close();
t.close();
remove("cow.dat");
rename("re.dat","cow.dat");
s.showc();}
void cow::modc()//Modifying a particular record
{ fstream f("cow.dat",ios::binary|ios::out|ios::in);
int i,t,r=0;
cow s,s1;
re:
cout<<"\nEnter the values of ID which has to be changed:";
cin>>i;
if(i<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re;}
f.read((char*)&s,sizeof(s));
while(!f.eof())
 {t=f.tellg();
if(s.idc==i)
{s1.enterc(i);
t=t-sizeof(s);
r=1;
f.seekg(t);
f.write((char*)&s1,sizeof(s1));}
f.read((char*)&s,sizeof(s));}
if(r!=1)
{cout<<"\nEntered record not found";}
f.close();
cout<<"\nRECORD IS:";
s.showc();}
class pig{
int idp;
float wgp;
float agp;
void enterp(int a);
public:
void entrecp();
void showp();
void funp();
void findp();
void insp();
void delp();
void modp();
pig() //Constructor
{idp=0;
wgp=0.0;
agp=0.0;}
~pig()//Destructor
{ ; }};
void pig::enterp(int a)//Enter values
{cout<<"\nEnter the values of the pig with ID:"<<a;
idp=a;
re2:
cout<<"\nEnter the weight of the pig: ";
cin>>wgp;
if(wgp<=0|wgp>150)
{cout<<"\nThe entered value is not valid enter a valid value.";
goto re2;}
re3:
cout<<"\nEnter the age of the pig(In years): ";
cin>>agp;
if(agp<=0|agp>2)
{cout<<"\nThe entered value is not valid enter a valid value.";
goto re3;}}
void pig::funp()//Displaying the values
{cout<<"\nThe ID is: "<<idp<<" With the weight: "<<wgp<<" And the age: "<<agp;}
void pig::entrecp()//Writting the data into a file
{ofstream f( "pig.dat",ios::binary);
pig s;
int i=2800;
char c;
do{
++i;
s.enterp(i);
f.write((char*)&s,sizeof(s));
cout<<"\nPress Y to enter data for a another pig othewise press any key.";
cin>>c;
}while(c=='y'|c=='Y');
f.close();}
void pig::showp()//Displaying data from the file
{ifstream f("pig.dat",ios::binary);
pig s;
f.read((char*)&s,sizeof (s));
while(!f.eof()){
s.funp();
f.read((char*)&s,sizeof(s));}
f.close();}
void pig::findp()//Finding a particular value
{ifstream f("pig.dat",ios::binary);
int i,u=0;
pig s;
re:
cout<<"\nEnter the ID which has to be found:";
cin>>i;
if(i<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re;}
f.read((char*)&s,sizeof (s));
while(!f.eof())
{if(s.idp==i)
{s.funp();
u=1;
break;}
f.read((char*)&s,sizeof(s));}
if(u!=1){cout<<"\nEntered record not found.";}
f.close();}
void pig::delp()//Deleting a record
{ifstream f("pig.dat",ios::binary);
ofstream t("re.dat",ios::binary);
int i,r=0;
char y;
pig s;
re:
cout<<"\nEnter the ID of the record to be deleted:";
cin>>i;
if(i<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re;}
f.read((char*)&s,sizeof(s));
while(!f.eof())
{if(s.idp==i){s.funp();
cout<<"\nConfirm deletion, Press N to terminate the deletation process.";
cin>>y;
r=1;
if(y=='n'|y=='N')
t.write((char*)&s,sizeof(s));}
else
t.write((char*)&s,sizeof(s));
f.read((char*)&s,sizeof(s));}
f.close();
t.close();
remove("pig.dat");
rename("re.dat","pig.dat");
if(r!=1)
{cout<<"\nEntered value not found";}
cout<<"\nRECORD IS:";
s.showp();}
void pig::insp()//Instering a record in the data file
{ifstream f("pig.dat",ios::binary);
ofstream t("re.dat",ios::binary|ios::app);
pig s,stud;
char x='r';
int o,i=0;
re:
cout<<"\nEnter the ID for the new record:";
cin>>i;
s.enterp(i);
f.read((char*)&stud,sizeof(stud));
while(!f.eof()){
if(s.idp<stud.idp)
{t.write((char*)&s,sizeof(s));
x='t';
o=f.tellg();
break;}
else if(s.idp==stud.idp)
{cout<<"\nThe ID already exits pl re-enter.";
goto re;}
else
t.write((char*)&stud,sizeof(stud));
f.read((char*)&stud,sizeof(stud));}
o=o-sizeof(s);
f.seekg(o);
if(x=='r')
t.write((char*)&s,sizeof(s));
else if(!f.eof()){
f.read((char*)&stud,sizeof(stud));
while(!f.eof()){
t.write((char*)&stud,sizeof(stud));
f.read((char*)&stud,sizeof(stud));}}
f.close();
t.close();
remove("pig.dat");
rename("re.dat","pig.dat");
s.showp();}
void pig::modp()//Modifying a particular record
{ fstream f("pig.dat",ios::binary|ios::out|ios::in);
int i,t,r=0;
pig s,s1;
re:
cout<<"\nEnter the values of ID which has to be changed:";
cin>>i;
if(i<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re;}
f.read((char*)&s,sizeof(s));
while(!f.eof())
 {t=f.tellg();
if(s.idp==i)
{s1.enterp(i);
t=t-sizeof(s);
r=1;
f.seekg(t);
f.write((char*)&s1,sizeof(s1));}
f.read((char*)&s,sizeof(s));}
if(r!=1)
{cout<<"\nEntered record not found";}
f.close();
cout<<"\nRECORD IS:";
s.showp();}class goat{
int idg;
float wgg;
float milkg;
float agg;
void enterg(int a);
public:
void entrecg();
void showg();
void fung();
void findg();
void insg();
void delg();
void modg();
goat() //Constructor
{idg=0;
wgg=0.0;
milkg=0.0;
agg=0.0;}
~goat()//Destructor
{ ; }};
void goat::enterg(int a)//Enter values
{cout<<"\nEnter the values of the goat with ID:"<<a;
idg=a;
re1:
cout<<"\nEnter the milk produed: ";
cin>>milkg;
if(milkg<=0|milkg>15)
{cout<<"\nThe entered value is not valid enter a valid value.";
goto re1;}
re2:
cout<<"\nEnter the weight of the goat: ";
cin>>wgg;
if(wgg<=0|wgg>25)
{cout<<"\nThe entered value is not valid enter a valid value.";
goto re2;}
re3:
cout<<"\nEnter the age of the goat(In years): ";
cin>>agg;
if(agg<=0|agg>10)
{cout<<"\nThe entered value is not valid enter a valid value.";
goto re3;}}
void goat::fung()//Displaying the values
{cout<<"\nThe ID is: "<<idg<<" With the milk: "<<milkg<<" With weight: "<<wgg<<" And the age: "<<agg;}
void goat::entrecg()//Writting the data into a file
{ofstream f( "goat.dat",ios::binary);
goat s;
int i=1600;
char c;
do{
++i;
s.enterg(i);
f.write((char*)&s,sizeof(s));
cout<<"\nPress Y to enter data for a another goat othewise press any key.";
cin>>c;
}while(c=='y'|c=='Y');
f.close();}
void goat::showg()//Displaying data from the file
{ifstream f("goat.dat",ios::binary);
goat s;
f.read((char*)&s,sizeof (s));
while(!f.eof()){
s.fung();
f.read((char*)&s,sizeof(s));}
f.close();}
void goat::findg()//Finding a particular value
{ifstream f("goat.dat",ios::binary);
int i,u=0;
goat s;
re:
cout<<"\nEnter the ID which has to be found:";
cin>>i;
if(i<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re;}
f.read((char*)&s,sizeof (s));
while(!f.eof())
{if(s.idg==i)
{s.fung();
u=1;
break;}
f.read((char*)&s,sizeof(s));}
if(u!=1){cout<<"\nEntered record not found.";}
f.close();}
void goat::delg()//Deleting a record
{ifstream f("goat.dat",ios::binary);
ofstream t("re.dat",ios::binary);
int i,r=0;
char y;
goat s;
re:
cout<<"\nEnter the ID of the record to be deleted:";
cin>>i;
if(i<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re;}
f.read((char*)&s,sizeof(s));
while(!f.eof())
{if(s.idg==i){s.fung();
cout<<"\nConfirm deletion, Press N to terminate the deletation process.";
cin>>y;
r=1;
if(y=='n'|y=='N')
t.write((char*)&s,sizeof(s));}
else
t.write((char*)&s,sizeof(s));
f.read((char*)&s,sizeof(s));}
f.close();
t.close();
remove("goat.dat");
rename("re.dat","goat.dat");
if(r!=1)
{cout<<"\nEntered value not found";}
cout<<"\nRECORD IS:";
s.showg();}
void goat::insg()//Instering a record in the data file
{ifstream f("goat.dat",ios::binary);
ofstream t("re.dat",ios::binary|ios::app);
goat s,stud;
char x='r';
int o,i=0;
re:
cout<<"\nEnter the ID for the new record:";
cin>>i;
s.enterg(i);
f.read((char*)&stud,sizeof(stud));
while(!f.eof()){
if(s.idg<stud.idg)
{t.write((char*)&s,sizeof(s));
x='t';
o=f.tellg();
break;}
else if(s.idg==stud.idg)
{cout<<"\nThe ID already exits pl re-enter.";
goto re;}
else
t.write((char*)&stud,sizeof(stud));
f.read((char*)&stud,sizeof(stud));}
o=o-sizeof(s);
f.seekg(o);
if(x=='r')
t.write((char*)&s,sizeof(s));
else if(!f.eof()){
f.read((char*)&stud,sizeof(stud));
while(!f.eof()){
t.write((char*)&stud,sizeof(stud));
f.read((char*)&stud,sizeof(stud));}}
f.close();
t.close();
remove("goat.dat");
rename("re.dat","goat.dat");
s.showg();}
void goat::modg()//Modifying a particular record
{ fstream f("goat.dat",ios::binary|ios::out|ios::in);
int i,t,r=0;
goat s,s1;
re:
cout<<"\nEnter the values of ID which has to be changed:";
cin>>i;
if(i<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re;}
f.read((char*)&s,sizeof(s));
while(!f.eof())
 {t=f.tellg();
if(s.idg==i)
{s1.enterg(i);
t=t-sizeof(s);
r=1;
f.seekg(t);
f.write((char*)&s1,sizeof(s1));}
f.read((char*)&s,sizeof(s));}
if(r!=1)
{cout<<"\nEntered record not found";}
f.close();
cout<<"\nRECORD IS:";
s.showg();}
class sheep{
int ids;
float wgs;
float milks;
float ags;
void enters(int a);
public:
void entrecs();
void shows();
void funs();
void finds();
void inss();
void dels();
void mods();
sheep() //Constructor
{ids=0;
wgs=0.0;
milks=0.0;
ags=0.0;}
~sheep()//Destructor
{ ; }};
void sheep::enters(int a)//Enter values
{cout<<"\nEnter the values of the sheep with ID:"<<a;
ids=a;
re1:
cout<<"\nEnter the milk produed: ";
cin>>milks;
if(milks<=0|milks>20)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re1;}
re2:
cout<<"\nEnter the weight of the sheep: ";
cin>>wgs;
if(wgs<=0|wgs>70)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re2;}
re3:
cout<<"\nEnter the age of the sheep(In years): ";
cin>>ags;
if(ags<=0|ags>15)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re3;}}
void sheep::funs()//Displaying the values
{cout<<"\nThe ID is: "<<ids<<" With the milk: "<<milks<<" With weight: "<<wgs<<" And the age: "<<ags;}
void sheep::entrecs()//Writting the data into a file
{ofstream f( "sheep.dat",ios::binary);
sheep s;
int i=600;
char c;
do{
++i;
s.enters(i);
f.write((char*)&s,sizeof(s));
cout<<"\nPress Y to enter data for a another sheep othewise press any key.";
cin>>c;
}while(c=='y'|c=='Y');
f.close();}
void sheep::shows()//Displaying data from the file
{ifstream f("sheep.dat",ios::binary);
sheep s;
f.read((char*)&s,sizeof (s));
while(!f.eof()){
s.funs();
f.read((char*)&s,sizeof(s));}
f.close();}
void sheep::finds()//Finding a particular value
{ifstream f("sheep.dat",ios::binary);
int i,u=0;
sheep s;
re:
cout<<"\nEnter the ID which has to be found:";
cin>>i;
if(i<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re;}
f.read((char*)&s,sizeof (s));
while(!f.eof())
{if(s.ids==i)
{s.funs();
u=1;
break;}
f.read((char*)&s,sizeof(s));}
if(u!=1){cout<<"\nEntered record not found.";}
f.close();}
void sheep::dels()//Deleting a record
{ifstream f("sheep.dat",ios::binary);
ofstream t("re.dat",ios::binary);
int i,r=0;
char y;
sheep s;
re:
cout<<"\nEnter the ID of the record to be deleted:";
cin>>i;
if(i<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re;}
f.read((char*)&s,sizeof(s));
while(!f.eof())
{if(s.ids==i){s.funs();
cout<<"\nConfirm deletion, Press N to terminate the deletation process.";
cin>>y;
r=1;
if(y=='n'|y=='N')
t.write((char*)&s,sizeof(s));}
else
t.write((char*)&s,sizeof(s));
f.read((char*)&s,sizeof(s));}
f.close();
t.close();
remove("sheep.dat");
rename("re.dat","sheep.dat");
if(r!=1)
{cout<<"\nEntered value not found";}
cout<<"\nRECORD IS:";
s.shows();}
void sheep::inss()//Instering a record in the data file
{ifstream f("sheep.dat",ios::binary);
ofstream t("re.dat",ios::binary|ios::app);
sheep s,stud;
char x='r';
int o,i=0;
re:
cout<<"\nEnter the ID for the new record:";
cin>>i;
s.enters(i);
f.read((char*)&stud,sizeof(stud));
while(!f.eof()){
if(s.ids<stud.ids)
{t.write((char*)&s,sizeof(s));
x='t';
o=f.tellg();
break;}
else if(s.ids==stud.ids)
{cout<<"\nThe ID already exits pl re-enter.";
goto re;}
else
t.write((char*)&stud,sizeof(stud));
f.read((char*)&stud,sizeof(stud));}
o=o-sizeof(s);
f.seekg(o);
if(x=='r')
t.write((char*)&s,sizeof(s));
else if(!f.eof()){
f.read((char*)&stud,sizeof(stud));
while(!f.eof()){
t.write((char*)&stud,sizeof(stud));
f.read((char*)&stud,sizeof(stud));}}
f.close();
t.close();
remove("sheep.dat");
rename("re.dat","sheep.dat");
s.shows();}
void sheep::mods()//Modifying a particular record
{ fstream f("sheep.dat",ios::binary|ios::out|ios::in);
int i,t,r=0;
sheep s,s1;
re:
cout<<"\nEnter the values of ID which has to be changed:";
cin>>i;
if(i<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re;}
f.read((char*)&s,sizeof(s));
while(!f.eof())
 {t=f.tellg();
if(s.ids==i)
{s1.enters(i);
t=t-sizeof(s);
r=1;
f.seekg(t);
f.write((char*)&s1,sizeof(s1));}
f.read((char*)&s,sizeof(s));}
if(r!=1)
{cout<<"\nEntered record not found";}
f.close();
cout<<"\nRECORD IS:";
s.shows();}
class stock{ //Class for the stock values
float milkc;
float milkg;
float milks;
float che;
float yo;
float pa;
float egg;
float meatp;
float meatb;
float meatm;
float meatl;
void enterk();
public:
void entreck();
void showk();
void funk();
int check1(float a) //Function to check the availability of product
{int q=0;
ifstream f("stock.dat",ios::binary);
stock s;
f.read((char*)&s,sizeof(s));
if(s.milkc<=a)
q=1;
else
q=2;
f.close();
return(q);}
void dec1(float a) //Function to update the stock values
{fstream f("stock.dat",ios::binary|ios::out|ios::in);
stock s;
float w;
f.read((char*)&s,sizeof(s));
w=s.milkc-a;
f.seekg(0,ios::beg);
f.write((char*)&w,sizeof(w));
f.close();}
int check2(float a) //Function to check the availability of product
{int q=0;
ifstream f("stock.dat",ios::binary);
stock s;
f.read((char*)&s,sizeof(s));
if(s.milkg<=a)
q=1;
else
q=2;
f.close();
return(q);}
void dec2(float a)//Function to update the stock values
{fstream f("stock.dat",ios::binary|ios::out|ios::in);
stock s;
float w;
f.read((char*)&s,sizeof(s));
w=s.milkg-a;
f.seekg(4,ios::beg);
f.write((char*)&w,sizeof(w));
f.close();}
int check3(float a)//Function to check the availability of product
{int q=0;
ifstream f("stock.dat",ios::binary);
stock s;
f.read((char*)&s,sizeof(s));
if(s.milks<=a)
q=1;
else
q=2;
f.close();
return(q);}
void dec3(float a)//Function to update the stock values
{fstream f("stock.dat",ios::binary|ios::out|ios::in);
stock s;
float w;
f.read((char*)&s,sizeof(s));
w=s.milks-a;
f.seekg(8,ios::beg);
f.write((char*)&w,sizeof(w));
f.close();}
int check4(float a)//Function to check the availability of product
{int q=0;
ifstream f("stock.dat",ios::binary);
stock s;
f.read((char*)&s,sizeof(s));
if(s.che<=a)
q=1;
else
q=2;
f.close();
return(q);}
void dec4(float a)//Function to update the stock values
{fstream f("stock.dat",ios::binary|ios::out|ios::in);
stock s;
float w;
f.read((char*)&s,sizeof(s));
w=s.che-a;
f.seekg(12,ios::beg);
f.write((char*)&w,sizeof(w));
f.close();}
int check5(float a)//Function to check the availability of product
{int q=0;
ifstream f("stock.dat",ios::binary);
stock s;
f.read((char*)&s,sizeof(s));
if(a>=s.yo)
q=1;
else
q=2;
f.close();
return(q);}
void dec5(float a)//Function to update the stock values
{fstream f("stock.dat",ios::binary|ios::out|ios::in);
stock s;
float w;
f.read((char*)&s,sizeof(s));
w=s.yo-a;
f.seekg(16,ios::beg);
f.write((char*)&w,sizeof(w));
f.close();}
int check6(float a)//Function to check the availability of product
{int q=0;
ifstream f("stock.dat",ios::binary);
stock s;
f.read((char*)&s,sizeof(s));
if(s.pa<=a)
q=1;
else
q=2;
f.close();
return(q);}
void dec6(float a)//Function to update the stock values
{fstream f("stock.dat",ios::binary|ios::out|ios::in);
stock s;
float w;
f.read((char*)&s,sizeof(s));
w=s.pa-a;
f.seekg(20,ios::beg);
f.write((char*)&w,sizeof(w));
f.close();}
int check7(float a)//Function to check the availability of product
{int q=0;
ifstream f("stock.dat",ios::binary);
stock s;
f.read((char*)&s,sizeof(s));
if(s.meatp<=a)
q=1;
else
q=2;
f.close();
return(q);}
void dec7(float a)//Function to update the stock values
{fstream f("stock.dat",ios::binary|ios::out|ios::in);
stock s;
float w;
f.read((char*)&s,sizeof(s));
w=s.meatp-a;
f.seekg(24,ios::beg);
f.write((char*)&w,sizeof(w));
f.close();}
int check8(float a)//Function to check the availability of product
{int q=0;
ifstream f("stock.dat",ios::binary);
stock s;
f.read((char*)&s,sizeof(s));
if(a>=s.meatb)
q=1;
else
q=2;
f.close();
return(q);}
void dec8(float a)//Function to update the stock values
{fstream f("stock.dat",ios::binary|ios::out|ios::in);
stock s;
float w;
f.read((char*)&s,sizeof(s));
w=s.meatb-a;
f.seekg(28,ios::beg);
f.write((char*)&w,sizeof(w));
f.close();}
int check9(float a)//Function to check the availability of product
{int q=0;
ifstream f("stock.dat",ios::binary);
stock s;
f.read((char*)&s,sizeof(s));
if(a>=s.meatm)
q=1;
else
q=2;
f.close();
return(q);}
void dec9(float a)//Function to update the stock values
{fstream f("stock.dat",ios::binary|ios::out|ios::in);
stock s;
float w;
f.read((char*)&s,sizeof(s));
w=s.meatm-a;
f.seekg(32,ios::beg);
f.write((char*)&w,sizeof(w));
f.close();}
int check10(float a)//Function to check the availability of product
{int q=0;
ifstream f("stock.dat",ios::binary);
stock s;
f.read((char*)&s,sizeof(s));
if(a>=s.meatl)
q=1;
else
q=2;
f.close();
return(q);}
void dec10(float a)//Function to update the stock values
{fstream f("stock.dat",ios::binary|ios::out|ios::in);
stock s;
float w;
f.read((char*)&s,sizeof(s));
w=s.meatl-a;
f.seekg(36,ios::beg);
f.write((char*)&w,sizeof(w));
f.close();}
int check15(float a)//Function to check the availability of product
{int q=0;
ifstream f("stock.dat",ios::binary);
stock s;
f.read((char*)&s,sizeof(s));
if(a>=s.egg)
q=1;
else
q=2;
f.close();
return(q);}
void dec15(float a)//Function to update the stock values
{fstream f("stock.dat",ios::binary|ios::out|ios::in);
stock s;
float w;
f.read((char*)&s,sizeof(s));
w=s.egg-a;
f.seekg(40,ios::beg);
f.write((char*)&w,sizeof(w));
f.close();}
stock() //Constructor
{milkc=0.0;
milkg=0.0;
milks=0.0;
che=0.0;
yo=0.0;
pa=0.0;
egg=0.0;
meatp=0.0;
meatb=0.0;
meatm=0.0;
meatl=0.0;}
~stock()//Destructor
{ ; }};
void stock::enterk()//Enter values
{cout<<"\nEnter the values of the stocks in the farm:";
re1:
cout<<"\nEnter the total milk given by cows:";
cin>>milkc;
if(milkc<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re1;}
req:
cout<<"\nEnter the total milk given by goats:";
cin>>milkg;
if(milkg<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto req;}
rew:
cout<<"\nEnter the total milk given by sheeps:";
cin>>milks;
if(milks<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto rew;}
re2:
cout<<"\nEnter the total cheese production:";
cin>>che;
if(che<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re2;}
re3:
cout<<"\nEnter the total curd production:";
cin>>yo;
if(yo<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto re3;}
rer:
cout<<"\nEnter the total production of cottage cheese:";
cin>>pa;
if(pa<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto rer;}
reg:
cout<<"\nEnter the total number of eggs:";
cin>>egg;
if(egg<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto rg;}
q1:
cout<<"\nEnter the total pork production:";
cin>>meatp;
if(meatp<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto q1;}
q2:
cout<<"\nEnter the total beef production:";
cin>>meatb;
if(meatb<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto q2;}
q3:
cout<<"\nEnter the total mutton production:";
cin>>meatm;
if(meatm<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto q3;}
rg:
cout<<"\nEnter the total lamb production:";
cin>>meatl;
if(meatl<=0)
{cout<<"\nThe entered value is not valid enter a valid value greater than 0.";
goto rg;}}
void stock::funk()//Displaying the values
{textcolor(67);
cout<<"\The total milk given by cows:";
cout<<milkc;
cout<<"\nThe total milk given by goats:";
cout<<milkg;
cout<<"\nThe total milk given by sheeps:";
cout<<milks;
cout<<"\nThe total cheese production is: ";
cout<<che;
cout<<"\nThe total curd production is:";
cout<<yo;
cout<<"\nThe total production of cottage cheese is:";
cout<<pa;
cout<<"\nThe total of eggs is:";
cout<<egg;
cout<<"\nThe total pork production is:";
cout<<meatp;
cout<<"\nThe total beef production is:";
cout<<meatb;
cout<<"\nThe total mutton production is:";
cout<<meatm;
cout<<"\nThe total lamb production is:";
cout<<meatl;}
void stock::entreck()//Writting the data into a file
{ofstream f( "stock.dat",ios::binary);
stock s;
s.enterk();
f.write((char*)&s,sizeof(s));
f.close();
s.showk();}
void stock::showk()//Displaying data from the file
{ifstream f("stock.dat",ios::binary);
stock s;
f.read((char*)&s,sizeof(s));
while(!f.eof()){
s.funk();
f.read((char*)&s,sizeof(s));}
f.close();}
int casecow() //Function for the interface of cow
{char chc,ic,u;
cow c;
do{rec:
ifstream f("cow.dat",ios::binary|ios::nocreate);
if(!f)
{cout<<"\nThere is no previous data, please enter data:";
c.entrecc();
goto le;}
if(f.read((char*)&u,sizeof(u))==NULL)
{cout<<"\nThere is no previous data, please enter data:";
c.entrecc();}
le:
cout<<"\nPress 1 to enter the entire record"
<<"\nPress 2 to add more records(i.e. append)"
<<"\nPress 3 to find a record"
<<"\nPress 4 to add missing records"
<<"\nPress 5 to edit record"
<<"\nPress 6 delete record"
<<"\nPress 7 to re-enter to main menu"
<<"\nEnter your choice: ";
cin>>ic;
if(isalpha(ic))
{cout<<"\nThe input is not recognised,Please reenter: ";
goto rec;}
switch(ic){
case '1':c.entrecc();
break;
case '2':c.insc();
break;
case '3':c.findc();
break;
case '4':c.insc();
break;
case '5':c.modc();
break;
case '6':c.delc();
break;
case '7':return(7);
break;
default:cout<<"\nPlease select a valid option:";
goto rec;
break;
f.close();}cout<<"\nEnter Y to use the interface for cow again: ";
cin>>chc;
}while(chc=='y'|chc=='Y');
return(0);}
int casepig() //Function for the interface of pig
{char chp,ip,up;
pig p;
do{rep:
ifstream fp("pig.dat",ios::binary|ios::nocreate);
if(!fp)
{cout<<"\nThere is no previous data, please enter data:";
p.entrecp();
goto la;}
if(fp.read((char*)&up,sizeof(up))==NULL)
{cout<<"\nThere is no previous data, please enter data:";
p.entrecp();}
la:
cout<<"\nPress 1 to enter the entire record"
<<"\nPress 2 to add more records(i.e. append)"
<<"\nPress 3 to find a record"
<<"\nPress 4 to add missing records"
<<"\nPress 5 to edit record"
<<"\nPress 6 delete record"
<<"\nPress 7 to re-enter to the main menu"
<<"\nEnter your choice: ";
cin>>ip;
if(isalpha(ip))
{cout<<"\nThe input is not recognised please re-enterthe value: ";
goto rep;}
switch(ip){
case '1':p.entrecp();
break;
case '2':p.insp();
break;
case '3':p.findp();
break;
case '4':p.insp();
break;
case '5':p.modp();
break;
case '6':p.delp();
break;
case '7':return(7);
break;
default: cout<<"\nPlease select a valid option:";
goto rep;
break;
fp.close();}
cout<<"\nEnter Y to use the interface for pig again: ";
cin>>chp;
}while(chp=='y'|chp=='Y');
return(0);}
int casegoat() //Function for the interface of goat
{char chg,ig,ug;
goat g;
do{reg:
ifstream fg("goat.dat",ios::binary|ios::nocreate);
if(!fg)
{cout<<"\nThere is no previous data, please enter data:";
g.entrecg();
goto lw;}
if(fg.read((char*)&ug,sizeof(ug))==NULL)
{cout<<"\nThere is no previous data, please enter data:";
g.entrecg();}
lw:
cout<<"\nPress 1 to enter the entire record"
<<"\nPress 2 to add more records(i.e. append)"
<<"\nPress 3 to find a record"
<<"\nPress 4 to add missing records"
<<"\nPress 5 to edit record"
<<"\nPress 6 delete record"
<<"\nPress 7 to re-enter to the main menu"
<<"\nPlease enter your choice: ";
cin>>ig;
if(isalpha(ig))
{cout<<"\nThe input is not recognised,Please reenter: ";
goto reg;}
switch(ig){
case '1': g.entrecg();
break;
case '2':g.insg();
break;
case '3':g.findg();
break;
case '4':g.insg();
break;
case '5':g.modg();
break;
case '6':g.delg();
break;
case '7':return(7);
break;
default: cout<<"\nPlease select a valid option:";
goto reg;
break;
fg.close();}
cout<<"\nEnter Y to use the interface for goat again: ";
cin>>chg;
}while(chg=='y'|chg=='Y');
return(0);}
int casesheep()//function for the interface of sheep
{char chs,is,us;
sheep s;
do{res:
ifstream fs("sheep.dat",ios::binary|ios::nocreate);
if(!fs)
{cout<<"\nThere is no previous data, please enter data:";
s.entrecs();
goto ta;}
if(fs.read((char*)&us,sizeof(us))==NULL)
{cout<<"\nThere is no previous data, please enter data:";
s.entrecs();}
ta:
cout<<"\nPress 1 to enter the entire record"
<<"\nPress 2 to add more records(i.e. append)"
<<"\nPress 3 to find a record"
<<"\nPress 4 to add missing records"
<<"\nPress 5 to edit record"
<<"\nPress 6 delete record"
<<"\nPress 7 to re-enter to the main menu"
<<"\nPlease enter your choice: ";
cin>>is;
if(isalpha(is))
{cout<<"\nThe input is not recognised,Please reenter: ";
goto res;}
switch(is){
case '1': s.entrecs();
break;
case '2':s.inss();
break;
case '3':s.finds();
break;
case '4':s.inss();
break;
case '5':s.mods();
break;
case '6':s.dels();
break;
case '7':return(7);
break;
default: cout<<"\nPlease select a valid option:";
goto res;
break;}
cout<<"\nEnter Y to use the interface for goat again:";
cin>>chs;
fs.close();}
while(chs=='y'|chs=='Y');
return(0);}
void getout()
{cout<<"\nYou are exitting."
<<"\nPress any key to exit.";
getch();
exit(0);}
char cus1() //Function for the interface for buying
{char c;
stock k;
r1:
clrscr();
cout<<"\nEnter 1 To Buy Milk And Milk Products."
<<"\nEnter 2 To Buy Meat."
<<"\nEnter 3 For Eggs."
<<"\nEnter 4 To Enter The Previous Menu."
<<"\nEnter Your Choice:";
cin>>c;
if(isalpha(c))
{cout<<"\nThe input is not recognised \nPress any key to be redirected.";
getch();
goto r1;}
if(c=='1'){
char c1;
r2:
clrscr();
cout<<"\nEnter 1 To Buy COWS milk"
<<"\nEnter 2 To Buy GOATS milk"
<<"\nEnter 3 To Buy SHEEPS milk"
<<"\nEnter 4 To Buy CHEESE"
<<"\nEnter 5 To Buy CURD"
<<"\nEnter 6 To Buy COTTAGE CHEESE"
<<"\nEnter 7 To Enter The Previous MENU"
<<"\nEnter Your Choice:";
cin>>c1;
if(isalpha(c1))
{cout<<"\nThe input is not recognised \nPress any key to return ";
getch();
goto r2;}
switch(c1)
{case '1':char cm,yc;
float mc,coc;
int q1;
cout<<"\nWe have cows milk for rs 35 per liter."
<<"If you want to buy at this cost press Y: ";
cin>>cm;
if(cm=='y'|cm=='Y')
{rc:
cout<<"\nEnter the quantity(In liters): ";
cin>>mc;
if(mc<=0)
{cout<<"\nThe input is unaceptable please renter: ";
getch();
goto rc;}
q1=k.check1(mc);
if(q1==1)
{cout<<"\nThe the entered quantity is not available.\nRedirecting to the menu.\nPress any key to goto main menu.";
goto r2;}
else{
coc=mc*35;
cout<<"\nYou have requested "<<mc<<" L of milk which will cost RS."
<<coc<<"\nIf you wish to continue press Y: ";
cin>>yc;
if(yc=='y'|yc=='Y')
{k.dec1(cm);
cout<<"\nThanks for your busines.\nPrinting your order...."
<<"\nPlease show this  parchment at the counter to collect your order and please make the payment there."
<<"\nWe accept credit and debit cards."; }
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";}}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";
break;
case '2':char gm,yg;
float mg,cog;
int q2;
cout<<"\nWe have goats milk for rs 55 per liter."
<<"If you want to buy at this cost press Y: ";
cin>>gm;
if(gm=='y'|cm=='Y')
{rg:
cout<<"\nEnter the quantity(In liters): ";
cin>>mg;
if(mg<=0)
{cout<<"\nThe input is unaceptable please renter: ";
goto rg;}
q2=k.check2(mg);
if(q2==1)
{cout<<"\nThe the entered quantity is not available.\nRedirecting to the menu.\nPress any key to goto main menu.";
getch();
goto r2;}
else{
cog=mg*55;
cout<<"\nYou have requested "<<mg<<" L of milk which will cost RS."
    <<cog<<"\nIf you wish to continue press Y: ";
cin>>yg;
if(yg=='y'|yg=='Y')
{k.dec2(mg);
cout<<"\nThanks for your busines.\nPrinting your order...."
<<"\nPlease show this parchment at the counter to collect your order and please make the payment there."
<<"\nWe accept credit and debit cards.";}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";}}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";
break;
case '3':char sm,ys;
float ms,cos;
int q3;
cout<<"\nWe have cows milk for rs 48 per liter."
<<"If you want to buy at this cost press Y: ";
cin>>sm;
if(sm=='y'|sm=='Y')
{rs:
cout<<"\nEnter the quantity(In liters): ";
cin>>ms;
q3=k.check3(ms);
if(q3==1)
{cout<<"\nThe the entered quantity is not available.\nRedirecting to the menu.\nPress any key to goto main menu.";
getch();
goto r2;}
else{
if(ms<=0)
{cout<<"\nThe input is unaceptable please renter: ";
goto rs;}
cos=ms*48;
cout<<"\nYou have requested "<<ms<<" L of milk which will cost RS."
<<cos<<"\nIf you wish to continue press Y: ";
cin>>ys;
if(ys=='y'|ys=='Y')
{k.dec3(ms);
cout<<"\nThanks for your busines.\nPrinting your order...."
<<"\nPlease show this parchment at the counter to collect your order and please make the payment there."
<<"\nWe accept credit and debit cards.";}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";}}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";
break;
case '4':char c,c1;
float cq,zc;
int q4;
cout<<"\nWe have only goats cheese for 660 per Kg."
<<"If you want to buy please press Y: ";
cin>>c;
if(c=='y'|c=='Y')
{ch:
cout<<"\nEnter the quantity(In Kg): ";
cin>>cq;
if(cq<=0)
{cout<<"\nThe input is unaceptable please renter: ";
goto ch;}
q4=k.check4(cq);
if(q4==1)
{cout<<"\nThe the entered quantity is not available.\nRedirecting to the menu.\nPress any key to goto main menu.";
getch();
goto r2;}
else{
zc=(cq*660);
cout<<"\nYou have requested "<<cq<<" Kg of cheese which will cost RS."
<<zc<<"\nIf you wish to continue press Y: ";
cin>>c1;
if(c1=='y'|c1=='Y')
{k.dec4(cq);
cout<<"\nThanks for your busines.\nPrinting your order...."
<<"\nPlease show this parchment at the counter to collect your order and please make the payment there."
<<"\nWe accept credit and debit cards.";}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate."; } }
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";
break;
case '5':char c12,c13;
float v1,v2;
int q5;
cout<<"\nWe have curd for rs 56 per liter."
<<"If you want to buy at this cost press Y: ";
cin>>c12;
if(c12=='y'|c12=='Y')
{r3:
cout<<"\nEnter the quantity(In liters): ";
cin>>v1;
if(v1<=0)
{cout<<"\nThe input is unaceptable please renter: ";
goto r3;}
q5=k.check5(v1);
if(q5==1)
{cout<<"\nThe the entered quantity is not available.\nRedirecting to the menu.\nPress any key to goto main menu.";
getch();
goto r2;}
else{
v2=v1*56;
cout<<"\nYou have requested "<<v1<<" L of curd which will cost RS."
<<v2<<"\nIf you wish to continue press Y: ";
cin>>c13;
if(c13=='y'|c13=='Y')
{k.dec5(v1);
cout<<"\nThanks for your busines.\nPrinting your order...."
<<"\nPlease show this parchment at the counter to collect your order and please make the payment there."
<<"\nWe accept credit and debit cards.";}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";} }
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";
break;
case '6':char p1,p2;
float v5,v6;
int q6;
cout<<"\nWe have cottage cheese for rs 260 per Kg."
<<"If you want to buy at this cost press Y: ";
cin>>p1;
if(p1=='y'|p1=='Y')
{cout<<"\nEnter the quantity(In Kg): ";
cin>>v5;
rv:
if(v5<=0)
{cout<<"\nThe input is unaceptable please renter: ";
goto rv;}
q6=k.check6(v5);
if(q6==1)
{cout<<"\nThe the entered quantity is not available.\nRedirecting to the menu.\nPress any key to goto main menu.";
getch();
goto r2;}
else{
v6=(v5*260);
cout<<"\nYou have requested "<<v5<<" Kg of cottage cheese which will cost RS."
<<v6<<"\nIf you wish to continue press Y: ";
cin>>p2;
if(p2=='y'|p2=='Y')
{k.dec6(v5);
cout<<"\nThanks for your busines.\nPrinting your order...."
<<"\nPlease show this  parchment at the counter to collect your order and please make the payment there."
<<"\nWe accept credit and debit cards.";}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";}}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";
break;
case '7':goto r1;
	 break;
default: cout<<"\nThe value was not recognised, please reenter: ";
	 goto r2;
	 break;}}
else if(c=='2'){
char gg;
r_1:
clrscr();
cout<<"\nEnter 1 To Buy PORK (pigs meat)."
<<"\nEnter 2 To Buy BEEF (cows meat)."
<<"\nEnter 3 To Buy MUTTON(goats meat)."
<<"\nEnter 4 To Buy LAMB (sheeps meat)."
<<"\nEnter 5 To Enter The Previous MENU."
<<"\nEnter choice: ";
cin>>gg;
if(isalpha(gg))
{cout<<"\nThe input is unrecognised. \nPress any key to re-enter.";
getch();
goto r_1;}
switch(gg)
{case '1':char po,yat;
float pty,pto;
cout<<"\nWe have pork for RS. 650 per Kg."
<<"\nDo you want to buy pork at this price, press Y to continue: ";
cin>>po;
if(po=='y'|po=='Y')
{re:
cout<<"\nEnter the quatity in Kg: ";
cin>>pty;
if(pty<=0)
{cout<<"\nThe input is unaceptable please renter: ";
goto re;}
int q=k.check7(pty);
if(q==1){
cout<<"\nThe the entered quantity is not available.\nRedirecting to the menu.\nPress any key to goto main menu.";
getch();
goto r_1;}
else{
pto=pty*650;
cout<<"\nYou have requested "<<pty<<" Kg of pork which will cost RS."
<<pto<<"\nIf you wish to continue press Y: ";
cin>>yat;
if(yat=='y'|yat=='Y')
{k.dec7(pty);
cout<<"\nThanks for your busines.\nPrinting your order...."
<<"\nPlease show this  parchment at the counter to collect your order and please make the payment there."
<<"\nWe accept credit and debit cards.";  }
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate."; } }
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";
break;
case '2':
char bo,bat;
float bty,bto;
cout<<"\nWe have beef for RS. 850 per Kg."
<<"\nDo you want to buy beef at this price press Y to continue: ";
cin>>bo;
if(bo=='y'|bo=='Y')
{rii:
cout<<"\nEnter the quatity in Kg: ";
cin>>bty;
if(bty<=0)
{cout<<"\nThe input is unaceptable please renter: ";
goto rii;}
int q1=k.check8(bty);
if(q1==1){
cout<<"\nThe the entered quantity is not available.\nRedirecting to the menu.\nPress any key to goto main menu.";
getch();
goto r_1;}
else{
bto=bty*850;
cout<<"\nYou have requested "<<bty<<" Kg of beef which will cost RS."
<<bto<<"\nIf you wish to continue press Y: ";
cin>>bat;
if(bat=='y'|bat=='Y')
{k.dec8(bty);
cout<<"\nThanks for your busines.\nPrinting your order...."
<<"\nPlease show this  parchment at the counter to collect your order and please make the payment there."
<<"\nWe accept credit and debit cards."; }
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate."; }}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";
break;
case '3':
char go,gat;
float gty,gto;
cout<<"\nWe have mutton for RS. 450 per Kg."
<<"\nDo you want to buy mutton at this price press Y to continue: ";
cin>>go;
if(go=='y'|go=='Y')
{gii:
cout<<"\nEnter the quatity in Kg: ";
cin>>gty;
if(gty<=0)
{cout<<"\nThe input is unaceptable please renter: ";
goto gii;}
int q2=k.check9(gty);
if(q2==1){
cout<<"\nThe the entered quantity is not available.\nRedirecting to the menu.\nPress any key to goto main menu.";
getch();
goto r_1;}
else{
gto=gty*450;
cout<<"\nYou have requested "<<gty<<" Kg of mutton which will cost RS."
<<gto<<"\nIf you wish to continue press Y: ";
cin>>gat;
if(gat=='y'|gat=='Y')
{k.dec9(gty);
cout<<"\nThanks for your busines.\nPrinting your order...."
<<"\nPlease show this  parchment at the counter to collect your order and please make the payment there."
<<"\nWe accept credit and debit cards."; }
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate."; }}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";
break;
case '4':
char mo,mat;
float mty,mto;
cout<<"\nWe have lamb for RS. 950 per Kg."
<<"\nDo you want to buy lamb at this price press Y to continue: ";
cin>>mo;
if(mo=='y'|mo=='Y')
{mii:
cout<<"\nEnter the quatity in Kg: ";
cin>>mty;
if(mty<=0)
{cout<<"\nThe input is unaceptable please renter: ";
goto mii;}
int q3=k.check10(mty);
if(q3==1)
{cout<<"\nThe the entered quantity is not available.\nRedirecting to the menu.\nPress any key to goto main menu.";
getch();
goto r_1;}
else{
mto=mty*950;
cout<<"\nYou have requested "<<mty<<" Kg of lamb which will cost RS."
<<mto<<"\nIf you wish to continue press Y: ";
cin>>mat;
if(mat=='y'|mat=='Y')
{k.dec10(mty);
cout<<"\nThanks for your busines.\nPrinting your order...."
<<"\nPlease show this  parchment at the counter to collect your order and please make the payment there."
<<"\nWe accept credit and debit cards."; }
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";}}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";
break;
case '5':goto r1;
	 break;
default:cout<<"\nEnter a valid option.";
	goto r_1;
       break;}}
else if(c=='3'){
char eg,ec;
int e1;
float r8= 0;
cout<<"\nWe are currently selling eggs 55 for a dozen(12 eggs)"
<<"\nShould you wish to continue press Y :";
cin>>eg;
if(eg=='y'|eg=='Y')
{p_1:
cout<<"\nHow many eggs do you want: ";
cin>>e1;
if(isalpha(e1)) {cout<<"\nThe entered value is not recognised.\nPress any key to re-enter.";
getch();
goto p_1;}
if(k.check15(e1)==1)
{cout<<"\nThe the entered quantity is not available.\nRedirecting to the menu.\nPress any key to goto main menu.";
getch();
goto r2;}
r8=e1*55/12;
cout<<"\nYou have requested "<<e1<<" number of eggs which will cost "
<<r8<<"\nIf you want to complete the order press Y : ";
cin>>ec;
if(ec=='y'|ec=='Y')
{k.dec15(e1);
cout<<"\nThanks for your busines.\nPrinting your order...."
<<"\nPlease show this  parchment at the counter to collect your order and please make the payment there."
<<"\nWe accept credit and debit cards."; }
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";}
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";
}
return(c);}
char buy1()
{char c1;
r1:
clrscr();
cout<<"\nPlease select the animal you want to purchase"
<<"\nPress 1 To Buy COWS."
<<"\nPress 2 To Buy GOATS."
<<"\nPress 3 To Buy SHEEPS."
<<"\nPress 4 To Buy PIGS. "
<<"\nPress 5 To Enter The Previous MENU."
<<"\nEnter your choice: ";
cin>>c1;
if(isalpha(c1))
{cout<<"\nEntered value is not recognised.\nPress any key to return.";
getch();
goto r1;}
if(c1=='1'){
char p_r;
cout<<"\nYou have requested to buy a cow.\nThe estimated price for a cow is RS. 56,000."
<<"\nShould you wish to continue press Y.";
cin>>p_r;
if(p_r=='y'|p_r=='Y')
cout<<"\nPrinting an appointment receipt."
<<"\nPlease show it to the customer desk."
<<"\nProceed with the purchase there.";
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";}
else if(c1=='4'){
char p_c;
cout<<"\nYou have requested to buy a pig.\nThe estimated price for a pig is RS. 6,000."
<<"\nShould you wish to continue press Y.";
cin>>p_c;
if(p_c=='y'|p_c=='Y')
cout<<"\nPrinting an appointment receipt."
<<"\nPlease show it to the customer desk."
<<"\nProceed with the purchase there.";
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";}
else if(c1=='2'){
char p_g;
cout<<"\nYou have requested to buy a goat.\nThe estimated price for a goat is RS. 7,000."
<<"\nShould you wish to continue press Y.";
cin>>p_g;
if(p_g=='y'|p_g=='Y')
cout<<"\nPrinting an appointment receipt."
<<"\nPlease show it to the customer desk."
<<"\nProceed with the purchase there.";
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";}
else if(c1=='3'){
char p_s;
cout<<"\nYou have requested to buy a sheep.\nThe estimated price for a sheep is RS. 8,000."
<<"\nShould you wish to continue press Y.";
cin>>p_s;
if(p_s=='y'|p_s=='Y')
cout<<"\nPrinting an appointment receipt."
<<"\nPlease show it to the customer desk."
<<"\nProceed with the purchase there.";
else
cout<<"\nThe prices are inclusive of a 10% donations towards the less fortunate.";}
return(c1);}
char sell() //Function for the interface of selling animals
{char c1;
r1:
clrscr();
cout<<"\nPlease select the animal you want to sell"
<<"\nPress 1 To Sell COWS."
<<"\nPress 2 To Sell GOATS."
<<"\nPress 3 To Sell SHEEPS."
<<"\nPress 4 To Sell PIGS. "
<<"\nPress 5 To Sell Any OTHER ANIMALS."
<<"\nPress 6 To Return To The previous MENU."
<<"\nEnter your choice: ";
cin>>c1;
if(isalpha(c1))
{cout<<"\nEntered value is not recognised.\nPress any key to return.";
getch();
goto r1;}
if(c1=='1'){
char p_r;
cout<<"\nYou have requested to sell a cow.\nThe estimated price for a cow is RS. 50,000."
<<"\nShould you wish to continue press Y.";
cin>>p_r;
if(p_r=='y'|p_r=='Y')
cout<<"\nPrinting an appointment receipt."
<<"\nPlease show it to the customer desk."
<<"\nProceed with the sale there.";
else
cout<<"\nWe provide a safe asylum for the your animals PLEASE reconsider.";}
else if(c1=='4'){
char p_c;
cout<<"\nYou have requested to sell a pig.\nThe estimated price for a pig is RS. 4,000."
<<"\nShould you wish to continue press Y.";
cin>>p_c;
if(p_c=='y'|p_c=='Y')
cout<<"\nPrinting an appointment receipt."
<<"\nPlease show it to the customer desk."
<<"\nProceed with the sale there.";
else
cout<<"\nWe provide a safe asylum for the your animals PLEASE reconsider.";}
else if(c1=='2'){
char p_g;
cout<<"\nYou have requested to sell a goat.\nThe estimated price for a goat is RS. 5,000."
<<"\nShould you wish to continue press Y.";
cin>>p_g;
if(p_g=='y'|p_g=='Y')
cout<<"\nPrinting an appointment receipt."
<<"\nPlease show it to the customer desk."
<<"\nProceed with the sale there.";
else
cout<<"\nWe provide a safe asylum for the your animals PLEASE reconsider.";}
else if(c1=='3'){
char p_s;
cout<<"\nYou have requested to sell a sheep.\nThe estimated price for a sheep is RS. 6,000."
<<"\nShould you wish to continue press Y.";
cin>>p_s;
if(p_s=='y'|p_s=='Y')
cout<<"\nPrinting an appointment receipt."
<<"\nPlease show it to the customer desk."
<<"\nProceed with the sale there.";
else
cout<<"\nWe provide a safe asylum for the your animals PLEASE reconsider.";}
else if(c1=='5'){
cout<<"\nPrinting an appointment receipt."
<<"\nPlease show it to the customer desk."
<<"\nProceed with the sale there.";}
return(c1);}
class commander{
char us[20];
char pa[20];
int a;
int b;
int c;
int d;
void erwin();
float smith(char o[20], char u[20]);
public:
void chg();
char* verify();};
void commander::chg(){
commander a;
a.erwin();}
char* commander::verify()
{commander a;
float r;
char e[20],q[20];
cout<<"\nEnter the username:";
gets(e);
cout<<"\nEnter the password:";
gets(q);
r=a.smith(e,q);
if(r==223798714)
return("ElPsyKongroo");
else
return("PikaPika");}
void commander :: erwin()//Fuction for updation of username and password.
{commander a;
int k,j;
unsigned int y;
time_t t;
y=(unsigned)time(&t);
srand(y);
a.a=(rand()%50)+1;
a.b=(rand()%50)+1;
a.c=(rand()%50)+1;
a.d=(rand()%50)+1;
cout<<a.a<<endl<<a.b<<endl<<a.c<<endl<<a.d;
ofstream f("data.bak",ios::trunc|ios::binary);
cout<<"\nEnter the new Username (MAX. 20 characters) : ";
gets(a.us);
k=strlen(a.us);
for(int i=0;i<k;i++)//Encryption algorithm
{if(i%2==0)
a.us[i]=a.us[i]-a.a;
else
a.us[i]=a.us[i]+a.b;}
puts(us);
cout<<"\nEnter the password (MAX.20 charaters) : ";
gets(a.pa);
j=strlen(a.pa);
for(int w=0;w<j;w++)
{if(w%2==0)
a.pa[w]=a.pa[w]-a.c;
else
a.pa[w]=a.pa[w]+a.d;}
puts(a.pa);
f.write((char*)&a,sizeof(a));
f.close();
cout<<"\nThe values have have been sucessfully updated.";}
float commander::smith(char w[],char v[]){   //Function for verification
char ch,us[20],pa[20];
commander a;
int k=0,j=0;
float e=0,i=0;
ifstream f("data.bak",ios::nocreate|ios::binary);
if(!f||f.read((char*)&a,sizeof(a))==NULL){
strcpy(us,"USER");
strcpy(pa,"PASSWORD");}
else{
strcpy(us,a.us);
strcpy(pa,a.pa);
f.read((char*)&a,sizeof(a));
k=strlen(us);
for(int d=0;d<k;d++)
{if(d%2==0)
us[d]=us[d]+a.a;
else
us[d]=us[d]-a.b;}
j=strlen(pa);
for(int y=0;y<j;y++)
{if(y%2==0)
pa[y]=pa[y]+a.c;
else
pa[y]=pa[y]-a.d;}
getch();}
f.close();
if(strcmp(w,us)==0 && strcmp(v,pa)==0){e=273908248;}
if(e==273908248)
{i=223798714;}
else
i=9;
return(i);}
void main(){
commander aot;
char ch,i,c,l17;
char* u2,*ki;
int q,w;
stock ew;
r1:
clrscr();
textcolor(10);
cout<<"\nEnter 1 to BUY";cprintf(" FRESH FARM GOODS");
cout<<"\nEnter 2 to BUY";cprintf(" FARM ANIMALS");
cout<<"\nEnter 3 to SELL";cprintf(" FARM ANIMALS");
cout<<"\nEnter 4 to MANAGE";cprintf(" FARM");
cout<<"\nEnter 5 to";cprintf(" EXIT");
cout<<"\nEnter your choice: ";
cin>>c;
if(c=='1')
{char ee;
textcolor(9);
clrscr();
u1:
clrscr();
ifstream fg("stock.dat",ios::binary|ios::nocreate);
if(!fg)
{cout<<"\nThere is a problem connecting to database.\nContact the customer support.\nRedirecting towards main menu.\nPress any key to go to main menu";
getch();
goto r1;}
if(fg.read((char*)&ew,sizeof(ew))==NULL)
{cout<<"\nThere is a problem connecting to database.\nContact the customer support.\nRedirecting towards main menu.\nPress any key to go to main menu";
getch();
goto r1;}
ee=cus1();
if(ee=='4')
goto r1;
else if(ee>'4')
{cout<<"\nThe value entered is invalid please reenter:";
goto u1;}
goto l1;}
else if(c=='2')
{clrscr();
textcolor(13);
char we;
rt:
clrscr();
we=buy1();
if(we=='5')
goto r1;
else if(we>'5')
{cout<<"\nThe value entered is invalid please reenter:";
goto rt;}
goto l1;}
else if(c=='3')
{clrscr();
textcolor(8);
char y1;
t2:
clrscr();
y1=sell();
if(y1=='6')
goto r1;
else if(y1>'6')
{cout<<"\nThe value entered is invalid please reenter:";
goto t2;}
goto l1;}
else if(c=='4')
{clrscr();
lel:
textcolor(12);
strcpy(u2,aot.verify());
if(strcmp(u2,"ElPsyKongroo")==0){
re:
clrscr();
textcolor(6);
cout<<"\nPress 1 to go to interface for COW"
    <<"\nPress 2 to go to interface for PIG"
    <<"\nPress 3 to go to interface for GOAT"
    <<"\nPress 4 to go to interface for SHEEP"
    <<"\nPress 5 to go to enter the values for the STOCK"
    <<"\nPress 6 to dispaly the STOCK"
    <<"\nPress 7 to change USERNAME and PASSWORD"
    <<"\nPress 8 to enter back to MAIN MENU"
    <<"\nEnter your choice:";
    cin>>i;
if(i=='1')
{clrscr();
int oi;
oi=casecow();
if(oi==7)
goto r1;
else
goto t1;}
else if(i=='2')
{clrscr();
int op;
op=casepig();
if(op==7)
goto r1;
else
goto t1;}
else if(i=='3')
{clrscr();
int og;
og=casegoat();
if(og==7)
goto r1;
else
goto t1;}
else if(i=='4')
{clrscr();
int os;
os=casesheep();
if(os==7)
goto r1;
else
goto t1;}
else if(i=='5')
{clrscr();
ew.entreck();
goto t1;}
else if(i=='6')
{clrscr();
ew.showk();
cout<<"\nDo you want to use this interface again \nPress Y to use it again otherwise press any other letter.";
cin>>l17;
if(l17=='y'|l17=='Y')
{goto re;}
else
cout<<"\nYou are being redirected to the main menu..\nPress any key";
getch();
goto r1;}
else if(i=='7')
{we:
clrscr();
cout<<"\nEnter your current ID & Password.";
strcpy(ki,aot.verify());
if(strcmp(ki,"ElPsyKongroo")==0)
{aot.chg();
goto t1;}
else
{cout<<"\nInvalid username or password.\nPlease re-enter.";
goto we;}}
else if(i=='8')
{goto r1;
exit(0);}
else{
cout<<"\nEnter a valid option.... \nPress any key to re-enter the values.";
getch();
goto re;}
char t2;
t1:
cout<<"\nDo you want to use this interface again \nPress Y to use it again otherwise press any other letter.";
cin>>t2;
if(t2=='y'|t2=='Y')
{goto re;}
else
cout<<"\nYou are being redirected to the main menu..\nPress any key";
getch();
goto r1;}
else
{cout<<"\nYou have entererd a wrong user name or password.\nPlease re-enter \n";
goto lel;}}
else if(c=='5')
getout();
else
{cout<<"\nThe input is not recognised,Please reenter:\nPress any key to return.";
getch();
goto r1;}
char l2;
l1:
textcolor(11);
cout<<"\nPress any key to continue:";
getch();
cout<<"\nDo you want to use the interface again \nPress Y to use it again.";
cin>>l2;
if(l2=='y'|l2=='Y')
{goto r1;}
else
{cout<<"\nYou are exitting from the interface.\nPress any key to exit.";
getch();
exit(0);}}

