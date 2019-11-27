#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<bios.h>
#include<string.h>
#include<stdio.h>
int speedx,speedy,n=1,a=1;
ifstream F("inst.txt");
void design2(void);

void show()
{
char l[200];
if(a==2)
 { F.getline(l,200);
   outtextxy(200,200,l);
 }
else
 { int i=0;
   while(!F.eof())
     { F.getline(l,200);
       outtextxy(200,200+i,l);
       i+=20;
     }
    getch();
    F.close();
 }
}
void design1()
{ outtextxy(10,35,"LABRYRINTH LEVEL 1");
  line(150,150,150,350);//vertical l
  line(150,150,260,150);//horizontal
  line(280,150,350,150); //entry
  line(350,150,350,350);//vertical r
  line(150,350,200,350); //exit
  line(240,350,350,350);//horizontal
  line(260,350,260,270); //v
  line(300,350,300,300);//v small
  line(200,350,200,310);
  line(200,310,230,310);
  line(260,270,200,270);
  line(350,250,290,250);//small extra
  line(280,150,280,190);//top drop
  line(180,190,280,190);//extension
  line(350,220,220,220);//big extra

}
void design2()
{
line(100,50,560,50);
line(600,50,600,450);
line(230,50,230,80);
line(350,50,350,80);
line(410,50,410,80);
line(470,50,470,80);
line(530,50,530,80);
line(270,110,270,130);
line(270,130,295,130);
line(295,130,295,150);
line(295,150,340,150);
line(340,150,340,185);
line(295,185,340,185);
line(295,185,295,230);
line(250,230,295,230);
line(250,230,250,280);
line(200,280,295,280);
line(200,280,200,320);
line(295,280,295,320);
line(250,360,250,400);
line(250,400,190,400);
line(250,400,150,400);
line(150,400,150,450);
line(100,150,170,150);
line(170,150,170,120);
line(380,90,380,130);
line(380,130,410,130);
line(410,130,410,160);
line(400,185,400,230);
line(400,230,470,230);
line(440,230,440,280);
line(450,320,500,320);
line(470,320,470,290);
line(470,290,600,290);
line(575,290,575,240);
line(470,230,470,185);
line(470,185,500,185);
line(500,160,500,185);
line(520,160,500,160);
line(520,120,520,160);
line(500,120,520,120);
line(500,80,500,120);
line(500,80,470,80);
line(295,230,340,230);
line(340,300,340,230);
line(340,300,360,300);
line(360,300,360,350);
line(360,350,450,350);
line(450,350,450,320);
line(500,320,500,350);
line(380,350,380,400);
line(470,450,470,400);
line(495,400,470,400);
line(365,450,365,420);
line(150,450,600,450);
line(100,50,100,450);
}
void incre(int ch)
{
cout<<"in fn..." <<n<<" ";//getch();
 if(n)
   switch(ch)
      { case 19712 : speedx+=15;
		     break;
	case 19200 : speedx-=15;
		     break;
	case 20480 : speedy+=15;
		     break;
	case 18432 : speedy-=15;
		     break;
	case 283   : exit(0);
       }
  else
     switch(ch)
      { case 19712 : speedx-=15;
		     break;
	case 19200 : speedx+=15;
		     break;
	case 20480 : speedy-=15;
		     break;
	case 18432 : speedy+=15;
		     break;
	case 283   : exit(0);
       }



}
void ascii1()
{ int i;
  while(1)
   {
     cleardevice();
     design1();
     circle( 270+speedx,140+speedy,3);
     int ch=bioskey(0);
     n=1;
     incre(ch);
//boundary check
if(speedx+270+3>=150 && speedx+270+3<=260)
   for(i=15;i>=1;i--)
      if(speedy-i+140+3==150)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedx+270+3>=280&& speedx+270+3<=350)
     for(i=15;i>=1;i--)
      if(speedy-i+140+3==150)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedy+140+3>=150 && speedy+140+3<=350)
      for(i=15;i>=1;i--)
      if(speedx-i+270+3==350)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedx+270+3>=240 && speedx+270+3<=350)
      for(i=15;i>=1;i--)
      if(speedy-i+140+3==350)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedx+270+3>=150 && speedx+270+3<=200)
       for(i=15;i>=1;i--)
      if(speedy-i+140+3==350)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedy+140+3>=150 && speedy+140+3<=350)
      for(i=15;i>=1;i--)
      if(speedx-i+270+3==150)
		{ n=0;
		  incre(ch);
		  break;}
//inside lines
 if(speedy+140+3>=150 && speedy+140+3<=190) //top drop
	  for(i=15;i>=1;i--)
      if(speedx-i+270+3==280)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedx+270+3>=180 && speedx+270+3<=280) //extension
    for(i=15;i>=1;i--)
      if(speedy-i+140+3==190)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedx+270+3>=220 && speedx+270+3<=350)//big extra
     for(i=15;i>=1;i--)
      if(speedy-i+140+3==220)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedx+270+3>=290 && speedx+270+3<=350)//small extra
     for(i=15;i>=1;i--)
      if(speedy-i+140+3==250)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedx+270+3>=200 && speedx+270+3<=260)//v extension
     for(i=15;i>=1;i--)
      if(speedy-i+140+3==270)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedx+270+3>=200 && speedx+270+3<=230)//v small extension
     for(i=15;i>=1;i--)
      if(speedy-i+140+3==310)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedy+140+3>=270 && speedy+140+3<=350)//v
     for(i=15;i>=1;i--)
      if(speedx-i+270+3==260)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedy+140+3>=300 && speedy+140+3<=350)//v small
      for(i=15;i>=1;i--)
       if(speedx-i+270+3==300)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedy+140+3>=310 && speedy+140+3<=350)//v extra
      for(i=15;i>=1;i--)
       if(speedx-i+270+3==200)
		{ n=0;
		  incre(ch);
		  break;}
 if(speedy+140+3>=350 && speedx+270+3>=200&&speedx+270+3<=240)
      { cleardevice();
	a++;
	show();
	getch();
	cleardevice;
	break;
       }

}

}
void ascii2()
{ int i;
  while(1)
   {
     cleardevice();
     design2();
     circle( 580+speedx,45+speedy,3);
     int ch=bioskey(0);
     n=1;
     incre(ch);
//boundary checks
 if(speedx+580+3>=100 && speedx+580+3<=560)
     for(i=15;i>=0;i--)
       if(speedy+45+3-i==50)
	   { n=0;incre(ch);break;}
 if(speedx+580+3>=150 && speedx+580+3<=600)
     for(i=15;i>=0;i--)
       if(speedy+45+3-i==450)
	   { n=0;incre(ch);break;}
 if(speedy+45+3>=50 && speedy+45+3<=450)
     for(i=15;i>=0;i--)
       if(speedx+580+3-i==600)
	 { n=0;incre(ch);break;}
 if(speedy+45+3>=50 && speedy+45+3<=450)
     for(i=15;i>=0;i--)
       if(speedx+580+3-i==100)
	{ n=0;incre(ch);break;}
if(speedy+45+3>=50 && speedy+45+3<=80)
  for(int i=15;i>=1;i--)
      if(speedx+580+3-i==230)
      {n=0;incre(ch);break;}

if(speedy+45+3>=50 && speedy+45+3<=80)
   for(int i=15;i>=1;i--)
      if(speedx+580+3-i==350)
      {n=0;incre(ch);break;}

if(speedy+45+3>=50 && speedy+45+3<=80)
   for(int i=15;i>=1;i--)
      if(speedx+580+3-i==410)
      {n=0;incre(ch);break;}

if(speedy+45+3>=50 && speedy+45+3<=80)
   for(int i=15;i>=1;i--)
     if(speedx+580+3-i==470)
     {n=0;incre(ch);break;}

if(speedy+45+3>=50 && speedy+45+3<=80)
  for(int i=15;i>=1;i--)
    if(speedx+580+3-i==530)
    {n=0;incre(ch);break;}

if(speedy+45+3>=120 && speedy+45+3<=150)
  for(int i=15;i>=1;i--)
    if(speedx+580+3-i==170)
    {n=0;incre(ch);break;}

if(speedy+45+3>=110 && speedy+45+3<=130)
  for(int i=15;i>=1;i--)
    if(speedx+580+3-i==270)
    {n=0;incre(ch);break;}

if(speedx+580+3>=270 && speedx+580+3<=295)
  for(int i=15;i>=1;i--)
   if(speedy+45+3-i==130)
   {n=0;incre(ch);break;}

if(speedy+45+3>=130 && speedy+45+3<=150)
  for(int i=15;i>=1;i--)
    if(speedx+580+3-i==295)
    {n=0;incre(ch);break;}

if(speedx+580+3>=295 && speedx+580+3<=340)
   for(int i=15;i>=1;i--)
    if(speedy+45+3-i==150)
    {n=0;incre(ch);break;}

if(speedy+45+3>=150 && speedy+45+3<=185)
  for(int i=15;i>1;i--)
   if(speedx+580+3-i==340)
   {n=0;incre(ch);break;}

if(speedx+580+3>=295 && speedx+580+3<=340)
  for(int i=15;i>=1;i--)
   if(speedy+45+3-i==185)
   {n=0;incre(ch);break;}

if(speedy+45+3>=185 && speedy+45+3<=230)
   for(int i=15;i>=1;i--)
    if(speedx+580+3-i==295)
    {n=0;incre(ch);break;}

if(speedx+580+3>=250 && speedx+580+3<=295)
   for(int i=15;i>=1;i--)
    if(speedy+45+3-i==230)
    {n=0;incre(ch);break;}

if(speedx+ 580+3>=295 && speedx+580+3<=340)
    for(int i=15;i>=1;i--)
     if(speedy+45+3-i==230)
     {n=0;incre(ch);break;}

if(speedy+45+3>=230 && speedy+45+3<=280)
   for(int i=15;i>=1;i--)
     if(speedx+580+3-i==250)
     {n=0;incre(ch);break;}

if(speedx+580+3>=200 && speedx+580+3<=295)
 for(int i=15;i>=1;i--)
    if(speedy+45+3-i==280)
    {n=0;incre(ch);break;}

if(speedy+45+3>=280 && speedy+45+3<=320)
   for(int i=15;i>=1;i--)
      if(speedx+580+3-i==200)
      {n=0;incre(ch);break;}

if(speedy+45+3>=280 && speedy+45+3<=320)
   for(int i=15;i>=1;i--)
    if(speedx+580+3-i==295)
    {n=0;incre(ch);break;}

if(speedy+45+3>=360 && speedy+45+3<=400)
  for(int i=15;i>=1;i--)
    if(speedx-i+580+3==250)
    {n=0;incre(ch);break;}

if(speedx+580+3>=150 && speedx+580+3<=250)
   for(int i=15;i>=1;i--)
    if(speedy+45+3-i==400)
    {n=0;incre(ch);break;}

if(speedy+45+3>=400 && speedy+45+3<=450)
  for(int i=15;i>=1;i--)
   if(speedx+580+3-i==150)
   {n=0;incre(ch);break;}

if(speedy+45+3>=420 && speedy+45+3<=450)
  for (int i=15;i>=1;i--)
     if(speedx+580+3-i==295)
     {n=0;incre(ch);break;}

if(speedy+45+3>=420 && speedy+45+3<=450)
  for (int i=15;i>=1;i--)
     if(speedx+580+3-i==365)
     {n=0;incre(ch);break;}

if(speedy+45+3>=400 && speedy+45+3<=450)
   for (int i=15;i>=1;i--)
     if(speedx+580+3-i==470)
     {n=0;incre(ch);break;}

if(speedy+45+3>=230 && speedy+45+3<=300)
   for (int i=15;i>=1;i--)
     if(speedx+580+3-i==340)
     {n=0;incre(ch);break;}

if(speedx+580+3>=340 && speedx+580+3<=360)
   for (int i=15;i>=1;i--)
     if(speedy+45+3-i==300)
     {n=0;incre(ch);break;}

if(speedy+45+3>=300 && speedy+45+3<=350)
   for (int i=15;i>=1;i--)
     if(speedx+580+3-i==360)
     {n=0;incre(ch);break;}

if(speedx+580+3>=360 && speedx+580+3<=450)
   for (int i=15;i>=1;i--)
     if(speedy+45+3-i==350)
     {n=0;incre(ch);break;}

if(speedy+45+3>=320 && speedy+45+3<=350)
   for (int i=15;i>=1;i--)
     if(speedx+580+3-i==450)
     {n=0;incre(ch);break;}

if(speedx+580+3>=450 && speedx+580+3<=500)
   for (int i=15;i>=1;i--)
     if(speedy+45+3-i==320)
     {n=0;incre(ch);break;}

if(speedy+45+3>=320 && speedy+45+3<=350)
   for (int i=15;i>=1;i--)
     if(speedx+580+3-i==500)
     {n=0;incre(ch);break;}

if(speedy+45+3>=290 && speedy+45+3<=320)
  for (int i=15;i>=1;i--)
     if(speedx+580+3-i==470)
     {n=0;incre(ch);break;}

if(speedx+580+3>=470 && speedx+580+3<=600)
  for (int i=15;i>=1;i--)
     if(speedy+45+3-i==290)
     {n=0;incre(ch);break;}

if(speedy+45+3>=240 && speedy+45+3<=290)
   for (int i=15;i>=1;i--)
     if(speedx+580+3-i==575)
     {n=0;incre(ch);break;}

if((speedy+45+3)>=50 && (speedy+45+3)<=80)
{ for(int i=15;i>=1;i--)
  if((speedx+580+3-i)==470)
  {n=0;incre(ch);break;}
}
if((speedy+45+3)>=50 &&( speedy+45+3)<=80)
{ for(int i=15;i>=1;i--)
  if((speedx+580+3-i)==530)
  {n=0;incre(ch);break;}
}
if((speedx+580+3)>=470 && (speedx+580+3)<=500)
{ for(int i=15;i>=1;i--)
  if((speedy+45+3-i)==80)
  {n=0;incre(ch);break;}
}
if(speedy+45+3>=80 && speedy+45+3<=120)
{ for(int i=15;i>=1;i--)
  if((speedx+580+3-i)==500)
  {n=0;incre(ch);break;}
}
if(speedx+580+3>=500 &&(speedx+580+3)<=520)
{ for(int i=15;i>=1;i--)
  if((speedy+45+3-i)==120)
  {n=0;incre(ch);break;}
}
if((speedy+45+3)>=120 && (speedy+45+3)<=160)
{ for(int i=15;i>=1;i--)
  if((speedx+580+3-i)==520)
  {n=0;incre(ch);break;}
}   //LOLOLOLOL
if((speedx+580+3)>=500 && (speedx+580+3)<=520)
{ for(int i=15;i>=1;i--)
  if((speedy+45+3-i)==160)
  {n=0;incre(n);break;}
}
if((speedy+45+3)>=160 && (speedy+45+3)<=185)
{ for(int i=15;i>=1;i--)
  if((speedx+580+3-i)==500)
  {n=0;incre(n);break;}
}
if((speedx+580+3)>=470 &&(speedx+580+3)<=500)
{ for(int i=15;i>=1;i--)
  if((speedy+45+3-i)==185)
  {n=0;incre(n);break;}
}
if((speedy+45+3)>=185 && (speedy+45+3)<=230)
{ for(int i=15;i>=1;i--)
  if((speedx+580+3-i)==470)
  {n=0;incre(n);break;}
}
if(( speedx+580+3)>=400 && (speedx+580+3)<=470)
{ for(int i=15;i>=1;i--)
  if((speedy+45+3-i)==230)
  {n=0;incre(n);break;}
}
if((speedy+45+3)>=230 &&(speedy+45+3)<=280)
{ for(int i=15;i>=1;i--)
  if((speedx+580+3-i)==440)
  {n=0;incre(n);break;}
}
if((speedy+45+3)>=185 && (speedy+45+3)<=230)
{ for(int i=15;i>=1;i--)
  if((speedx+580+3-i)==400)
  {n=0;incre(n);break;}
}
if((speedy+45+3)>=90 &&(speedy+45+3)<=130)
{ for(int i=15;i>=1;i--)
  if((speedx+580+3-i)==380)
  {n=0;incre(n);break;}
}
if((speedx+580+3)>=380 && (speedx+580+3)<=410)
{ for(int i=15;i>=1;i--)
  if((speedy+45+3-i)==130)
  {n=0;incre(n);break;}
}
if((speedy+45+3)>=130 &&(speedy+45+3)<=160)
{ for(int i=15;i>=1;i--)
  if((speedx+580+3-i)==410)
  {n=0;incre(n);break;}
}
if((speedy+45+3)>=350 && (speedy+45+3)<=400)
{ for(int i=15;i>=1;i--)
  if((speedx+580+3-i)==390)
  {n=0;incre(n);break;}
}
if((speedx+580+3)>=100 && (speedx+580+3)<=170)
{ for(int i=15;i>=1;i--)
  if((speedy+45+3-i)==150)
  {n=0;incre(n);break;}
}

if(speedx+580+3>=100 && speedx+580+3<=150 && speedy+45+3>=450)
    {   cleardevice();
	a++;
	show();
	getch();
	exit(0); }



}
}
void main()
{ clrscr();
  int z=0;
  char l[200];
  while(z!=5)
   { F.getline(l,200);
     puts(l);
     z++;
   }
  getch();
  int gm,gd=DETECT;
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  cleardevice();
  F.getline(l,200);
  outtextxy(200,180,l);
  getch();
  cleardevice();
  design1();
  ascii1();
  design2();
  ascii2();
  getch();
  closegraph();

}