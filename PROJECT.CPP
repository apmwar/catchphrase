//catchphrase by aruna//

//header files
#include<dos.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<graphics.h>
#include<iomanip.h>

//function definitions

int lvlselect();
int checkgame(char grid[4][4],char phrase[],char blanks[]);
void menu();
void help();
void aboutgame();
void startgraphics();
void gridgraph(char grid[4][4]);
void spaceleft(char grid[4][4]);
void spaceright(char grid[4][4]);
void spaceup(char grid[4][4]);
void spacedown(char grid[4][4]);
void winscreen(int score,int &level);
void losescreen(int score,int &level);
void startgame(int level=1);
void displaygrid(char grid[4][4]);
void checkphrase(char grid[4][4],int i,int j,char blanks[]);
void up(char grid[4][4],int &score,char blanks[]);
void down(char grid[4][4],int &score,char blanks[]);
void left(char grid[4][4],int &score,char blanks[]);
void right(char grid[4][4],int &score,char blanks[]);
void scorecalc(char grid[4][4],int i,int j,int &score);
void getphrase(int level,char phrase[],char blanks[]);

//main function
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	startgraphics();
	menu();
	closegraph();
}

//display grid
void displaygrid(char grid[4][4])
{
	int i,j;
	clrscr();
	cleardevice();
	cout<<"\n\n\n\n\n\n";
	for(i=0;i<4;i++)
	{
	 cout<<"\t\t\t\t   ";
	 for(j=0;j<4;j++)
	  {
	   switch(grid[i][j])
	   {
	    case '1':
	     cout<<'A';
	     break;
	    case '2':
	     cout<<'B';
	     break;
	    case '3':
	     cout<<'C';
	     break;
	    case '4':
	     cout<<'D';
	     break;
	    case '5':
	     cout<<'E';
	     break;
	    case '6':
	     cout<<'F';
	     break;
	    case '7':
	     cout<<'G';
	     break;
	    case '8':
	     cout<<'H';
	     break;
	    case '9':
	     cout<<'I';
	     break;
	    default:
	     cout<<grid[i][j];
	     break;
	   }
	   cout<<"    ";
	  }
	  cout<<"\n\n";
	}
	//grid co-ordinates
	setlinestyle(0,0,2);
	line(264,88,423,88);
	line(264,88,264,216);
	line(264,118,423,118);
	line(304,88,304,216);
	line(264,150,423,150);
	line(343,88,343,216);
	line(264,183,423,183);
	line(383,88,383,216);
	line(264,216,423,216);
	line(423,88,423,216);
}

//start screen grid graphics
void gridgraph(char grid[4][4])
{
	cleardevice();
	displaygrid(grid);
	grid[2][2]='1';
	displaygrid(grid);
	delay(1000);
	grid[2][2]=' ';
	grid[3][2]='1';
	displaygrid(grid);
	delay(1000);
	grid[0][1]='1';
	displaygrid(grid);
	delay(1000);
	grid[3][1]='1';
	grid[0][1]=' ';
	displaygrid(grid);
	delay(1000);
	grid[1][0]='1';
	displaygrid(grid);
	delay(1000);
	grid[1][3]='1';
	grid[3][2]=grid[3][1]=grid[1][0]=' ';
	grid[3][3]='2';
	displaygrid(grid);
	delay(1000);
	grid[0][0]='1';
	displaygrid(grid);
	delay(1000);
	grid[1][3]=grid[3][3]=' ';
	grid[0][3]='1';
	grid[1][3]='2';
	displaygrid(grid);
	delay(1000);
	grid[2][1]='1';
	displaygrid(grid);
	delay(1000);
	cleardevice();
	grid[2][1]=' ';
	grid[0][1]='1';
	displaygrid(grid);
	delay(1000);
	cleardevice();
	grid[2][2]='1';
	displaygrid(grid);
	delay(1000);
	grid[2][3]='1';
	grid[0][2]='1';
	grid[0][0]=grid[0][1]=grid[2][2]=' ';
	grid[0][3]='2';
	displaygrid(grid);
	delay(1000);
	grid[3][3]='1';
	displaygrid(grid);
	delay(1000);
	grid[3][3]=grid[2][3]=' ';
	grid[1][3]='2';
	grid[0][3]='3';
	displaygrid(grid);
	delay(1000);
	for(int i=0;i<3;i++)
	{ grid[0][3]=' ';
	  displaygrid(grid);
	  delay(400);
	  grid[0][3]='3';
	  displaygrid(grid);
	  delay(400);
	}
	delay(1000);

}
//start screen graphics
void startgraphics()
{
	setbkcolor(8);
	char grid[4][4];
	for(int i=0;i<4;i++)
	  for(int j=0;j<4;j++)
	   grid[i][j]=' ';
	gridgraph(grid);

	//text animations
	settextstyle(3,0,6);
	outtextxy(160,300,"C");
	delay(400);
	settextstyle(3,0,6);
	outtextxy(160,300,"CA");
	delay(400);
	settextstyle(3,0,6);
	outtextxy(160,300,"CAT");
	delay(400);
	settextstyle(3,0,6);
	outtextxy(160,300,"CATC");
	delay(400);
	settextstyle(3,0,6);
	outtextxy(160,300,"CATCH");
	settextstyle(3,0,6);
	delay(400);
	outtextxy(160,300,"CATCHP");
	settextstyle(3,0,6);
	delay(400);
	outtextxy(160,300,"CATCHPH");
	delay(400);
	settextstyle(3,0,6);
	outtextxy(160,300,"CATCHPHR");
	delay(400);
	settextstyle(3,0,6);
	outtextxy(160,300,"CATCHPHRA");
	delay(400);
	settextstyle(3,0,6);
	outtextxy(160,300,"CATCHPHRAS");
	delay(400);
	settextstyle(3,0,6);
	outtextxy(160,300,"CATCHPHRASE");
	delay(2000);
	cleardevice();

	setbkcolor(0);
	settextstyle(7,0,7);
	outtextxy(170,200,"Created by");
	delay(2000);

	cleardevice();
	setbkcolor(6);
	settextstyle(9,0,3);
	outtextxy(160,200,"FIREBOLT STUDIOS");
	delay(1000);
	setbkcolor(3);
	settextstyle(9,0,3);
	outtextxy(160,200,"FIREBOLT STUDIOS");
	delay(1000);
	setbkcolor(4);
	settextstyle(9,0,3);
	outtextxy(160,200,"FIREBOLT STUDIOS");
	delay(1000);
	setbkcolor(7);
	settextstyle(9,0,3);
	outtextxy(160,200,"FIREBOLT STUDIOS");
	delay(1000);
	getch();
}

//menu
void menu()
{
	clrscr();
	setbkcolor(3);
	int choice;
	clrscr();
	cleardevice();
	settextstyle(3,0,7);
	outtextxy(250,50,"MENU");
	delay(300);
	settextstyle(2,0,6);
	delay(500);
	outtextxy(150,140,"1. START GAME");
	delay(300);
	outtextxy(150,160,"2. LEVEL SELECT");
	delay(300);
	outtextxy(150,180,"3. HELP");
	delay(300);
	outtextxy(150,200,"4. ABOUT GAME");
	delay(300);
	outtextxy(150,220,"5. EXIT");
	delay(300);
	settextstyle(2,0,6);
	outtextxy(50,299,"Enter your choice (1 to 5): ");
	gotoxy(42,20);
	cin>>choice;
	if(choice==1)
	  startgame(1);

	else if(choice==2)
	{
	 int n=lvlselect();
	 startgame(n);
	}

	else if(choice==3)
	{
	 help();
	 menu();
	}

	else if(choice==4)
	{
	 aboutgame();
	 menu();
	}

	else if(choice==5)
	 exit(0);
}

//help game screen
void help()
{
	clrscr();
	cleardevice();
	setbkcolor(12);
	settextstyle(9,0,3);
	outtextxy(280,50,"HELP");
	delay(600);
	settextstyle(11,0,30);
	outtextxy(15,150,"THE OBJECTIVE OF THE GAME IS TO COLLECT ALL THE MISSING LETTERS FROM THE");
	delay(400);
	outtextxy(15,165,"GIVEN PHRASE BY MOVING THE TILES ON THE BOARD. TWO SIMILAR TILES COLLIDE");
	delay(400);
	outtextxy(15,180,"TO FORM AN ENTIRELY NEW TILE.");
	delay(1000);
	outtextxy(180,230,"CONTROLS:");
	delay(500);
	outtextxy(180,250,"W - move up");
	outtextxy(180,270,"A - move left");
	outtextxy(180,290,"S - move down");
	outtextxy(180,310,"D - move right");
	delay(1000);
	outtextxy(200,400,"Press any key to continue.");
	delay(500);
	outtextxy(200,400,"Press any key to continue..");
	delay(500);
	outtextxy(200,400,"Press any key to continue...");
	delay(500);
	getch();
}

//about game screen
void aboutgame()
{
	clrscr();
	cleardevice();
	setbkcolor(12);
	settextstyle(9,0,3);
	outtextxy(195,50,"ABOUT GAME");
	delay(600);
	settextstyle(11,0,30);
	outtextxy(15,150,"CATCHPHRASE IS A GAME PLAYED OUT ON A 4X4 GRID. IT IS BASED ON THE POPULAR");
	delay(400);
	outtextxy(15,165,"INTERNET SENSATION '2048', THIS VERSION REPLACES THE NUMBERS WITH LETTERS.");
	delay(400);
	outtextxy(15,180,"IN THE PLACE OF 2 WE HAVE AN 'A', INSTEAD OF 4 WE HAVE 'B' AND SO ON WITH");
	delay(400);
	outtextxy(15,195,"THE POWERS OF 2. SO WHEN AN 'A' TILE COLLIDES WITH ANOTHER 'A' TILE, IT");
	delay(400);
	outtextxy(15,210,"FORMS A 'B' TILE.");
	delay(400);
	outtextxy(15,240,"THIS VERSION OF THE GAME CODED USING C++ IS BROUGHT TO YOU BY TWO TEEN");
	delay(400);
	outtextxy(15,255,"PROGRAMMERS WORKING FOR THE FIREBOLT STUDIOS. WE ARE THANKFUL TO ALL WHO'VE");
	delay(400);
	outtextxy(15,270,"PLAYED THE GAME AND SUPPORTED THIS PROJECT. HAPPY GAMING!");
	delay(1000);
	outtextxy(200,400,"Press any key to continue.");
	delay(500);
	outtextxy(200,400,"Press any key to continue..");
	delay(500);
	outtextxy(200,400,"Press any key to continue...");
	delay(500);
	getch();
}

//select level
int lvlselect()
{
	clrscr();
	cleardevice();
	int lvl;
	setbkcolor(9);
	do
	{
	 cleardevice();
	 settextstyle(9,0,4);
	 for(int i=0;i<4;i++)
	 {
	  cleardevice();
	  settextstyle(9,0,3);
	  outtextxy(180,50,"LEVEL SELECT");
	  delay(600);
	  gotoxy(54,14);
	  settextstyle(2,0,5);
	  outtextxy(200,207,"Choose a level from 1 to 10: ");
	  delay(400);
	 }
	 cin>>lvl;
	}while(lvl<1||lvl>10);
	return lvl;
}

//generate a phrase according to level
void getphrase(int level,char phrase[],char blanks[])
{
	fstream f1("phrase.txt",ios::in);
	fstream f2("blanks.txt",ios::in);
	int flag=0;
	while(!f1.eof()&&!f2.eof())
	{
	 f1.getline(phrase,101,'*');
	 f2.getline(blanks,101,'*');
	 flag++;
	 if(flag==level)
	  break;
	}
	f1.close();
	f2.close();
}

//play the game
void startgame(int level)
{
	 clrscr();
	 randomize();
	 cleardevice();
	 setbkcolor(1);
	 int flag=0,x,y,i,j,k,score=0;
	 char move,grid[4][4],phrase[100],blanks[100];
	 getphrase(level,phrase,blanks);
	 for(i=0;i<4;i++)
	  for(j=0;j<4;j++)
	   grid[i][j]=' ';
	 cleardevice();
	 delay(500);

	 //loading screen graphics
	 for(int a=0;a<3;a++)
	 {
	  settextstyle(2,0,10);
	  outtextxy(250,200,"L");
	  settextstyle(2,0,30);
	  outtextxy(250,220,".");
	  delay(400);
	  settextstyle(2,0,10);
	  outtextxy(250,200,"LO");
	  settextstyle(2,0,30);
	  outtextxy(250,220,"...");
	  settextstyle(2,0,10);
	  delay(400);
	  outtextxy(250,200,"LOA");
	  settextstyle(2,0,30);
	  outtextxy(250,220,"....");
	  delay(400);
	  settextstyle(2,0,10);
	  outtextxy(250,200,"LOAD");
	  settextstyle(2,0,30);
	  outtextxy(250,220,"......");
	  delay(400);
	  settextstyle(2,0,10);
	  outtextxy(250,200,"LOADI");
	  settextstyle(2,0,30);
	  outtextxy(250,220,".......");
	  delay(400);
	  cleardevice();
	  settextstyle(2,0,10);
	  outtextxy(250,200,"LOADIN");
	  settextstyle(2,0,30);
	  outtextxy(250,220,"........");
	  delay(400);
	  cleardevice();
	  settextstyle(2,0,10);
	  outtextxy(250,200,"LOADING");
	  settextstyle(2,0,30);
	  outtextxy(250,220,"..........");
	  delay(1500);
	  clrscr();
	  cleardevice();
	 }
	 delay(1000);
	 while(flag!=1&&flag!=2)
	 {
	  cleardevice();
	  setbkcolor(1);
	  x=random(4);
	  y=random(4);
	  while(grid[x][y]!=' ')
	  {
	   x=random(4);
	   y=random(4);
	  }
	  grid[x][y]='1';
	  help:    //goto statement label
	  setbkcolor(1);
	  displaygrid(grid);
	  gotoxy(1,1);
	  cout<<endl<<setw(70)<<"Press W,A,S,D to move the tiles, H for help and E to exit.";
	  cout<<endl<<endl<<endl<<setw(47)<<"SCORE:"<<setw(6)<<score;
	  gotoxy(1,18);
	  setlinestyle(2,0,2);
	  line(0,260,640,260);
	  line(0,300,640,300);
	  cout<<"\tPHRASE: ";
	  for(k=0;k<strlen(blanks);k++)
	  {
	  if(isdigit(blanks[k]))
	     cout<<"_";
	   else
	     cout<<blanks[k];
	  }
	  cout<<endl<<endl<<endl<<endl<<"\tMAKE A MOVE: ";
	  cin>>move;
	  again:     //go to statement label
	  switch(move)
	  {
	   case 'w':
	   case 'W':
	    up(grid,score,blanks);
	    break;
	   case 'A':
	   case 'a':
	    left(grid,score,blanks);
	    break;
	   case 'S':
	   case 's':
	    down(grid,score,blanks);
	    break;
	   case 'D':
	   case 'd':
	    right(grid,score,blanks);
	    break;
	   case 'H':
	   case 'h':
	    help();
	    goto help;
	   case 'E':
	   case 'e':
	    menu();
	   default:
	    cout<<"\nInvalid move. Press again: ";
	    cin>>move;
	    goto again;
	  }
	  displaygrid(grid);
	  delay(1000);
	  flag=checkgame(grid,phrase,blanks);
	 }
	 cleardevice();

	 //player wins game
	 if(flag==1)
	 {
	  displaygrid(grid);
	  delay(1000);
	  gotoxy(1,18);
	  setlinestyle(2,0,2);
	  line(0,260,640,260);
	  line(0,300,640,300);
	  cout<<"\tPHRASE: ";
	  delay(600);
	  for(k=0;k<strlen(blanks);k++)
	  {
	  if(blanks[k]==' ')
	   delay(400);
	  cout<<blanks[k];
	  }
	  getch();
	  winscreen(score,level);
	 }

	 //player loses game
	 else if(flag==2)
	 {
	  displaygrid(grid);
	  delay(1000);
	  gotoxy(1,18);
	  setlinestyle(2,0,2);
	  line(0,260,640,260);
	  line(0,300,640,300);
	  cout<<"\tPHRASE: ";
	  delay(600);
	  for(k=0;k<strlen(blanks);k++)
	  {
	  if(blanks[k]==' ')
	  {
	   delay(400);
	   cout<<blanks[k];
	  }
	  else if(isdigit(blanks[k]))
	   cout<<"_";
	  else
	   cout<<blanks[k];
	  }
	  getch();
	  losescreen(score,level);
	 }
}

//fill up the phrase blanks
void checkphrase(char grid[4][4],int i,int j,char blanks[])
{
	int k=0;
	  for(k=0;k<strlen(blanks);k++)
	   if(grid[i][j]==blanks[k])
	   {
	    switch(blanks[k])
	    {
	    case '1':
	     blanks[k]='A';
	     break;
	    case '2':
	     blanks[k]='B';
	     break;
	    case '3':
	     blanks[k]='C';
	     break;
	    case '4':
	     blanks[k]='D';
	     break;
	    case '5':
	     blanks[k]='E';
	     break;
	    case '6':
	     blanks[k]='F';
	     break;
	    case '7':
	     blanks[k]='G';
	     break;
	    case '8':
	     blanks[k]='H';
	     break;
	    case '9':
	     blanks[k]='I';
	     break;
	    case '10':
	     blanks[k]='J';
	     break;
	    }
	    break;
	}
}

//game status function
int checkgame(char grid[4][4],char phrase[],char blanks[])
{
	int tiles=0;
	for(int i=0;i<4;i++)
	 for(int j=0;j<4;j++)
	  if(grid[i][j]==' ')
	   tiles++;
	if(strcmp(phrase,blanks)==0)
	 return 1;
	else if(tiles==0)
	 return 2;
	else
	 return 0;
}

//moving functions
void spaceup(char grid[4][4])
{
	for(int i=0;i<3;i++)
	 {
	  for(int j=0;j<4;j++)
	  {
	   if(grid[i][j]==' ')
	   {
	    grid[i][j]=grid[i+1][j];
	    grid[i+1][j]=' ';
	   }
	  }
	}
}

void spacedown(char grid[4][4])
{
	for(int i=3;i>0;i--)
	 {
	  for(int j=0;j<4;j++)
	  {
	   if(grid[i][j]==' ')
	   {
	    grid[i][j]=grid[i-1][j];
	    grid[i-1][j]=' ';
	   }
	  }
	}
}
void spaceleft(char grid[4][4])
{
	for(int i=0;i<4;i++)
	 {
	  for(int j=0;j<3;j++)
	  {
	   if(grid[i][j]==' ')
	   {
	    grid[i][j]=grid[i][j+1];
	    grid[i][j+1]=' ';
	   }
	  }
	}
}

void spaceright(char grid[4][4])
{
	for(int i=0;i<4;i++)
	 {
	  for(int j=3;j>0;j--)
	  {
	   if(grid[i][j]==' ')
	   {
	    grid[i][j]=grid[i][j-1];
	    grid[i][j-1]=' ';
	   }
	  }
	}
}


void up(char grid[4][4],int &score,char blanks[])
{
	spaceup(grid);
	for(int i=1;i<4;i++)
	{
	 for(int j=0;j<4;j++)
	 {
	  if(grid[i][j]!=' '&&grid[i][j]==grid[i-1][j])
	  {
	   grid[i][j]+=1;
	   grid[i-1][j]=' ';
	   checkphrase(grid,i,j,blanks);
	   scorecalc(grid,i,j,score);
	   }
	   spaceup(grid);
	 }
	}
}

void down(char grid[4][4],int &score,char blanks[])
{
	spacedown(grid);
	for(int i=3;i>0;i--)
	 {
	  for(int j=0;j<4;j++)
	  {
	   if(grid[i][j]!=' '&&grid[i][j]==grid[i-1][j])
	   {
	    grid[i][j]+=1;
	    grid[i-1][j]=' ';
	    checkphrase(grid,i,j,blanks);
	    scorecalc(grid,i,j,score);
	    }
	    spacedown(grid);
	  }
	}
}
void left(char grid[4][4],int &score,char blanks[])
{
	spaceleft(grid);
	for(int i=0;i<4;i++)
	 {
	  for(int j=0;j<3;j++)
	  {
	   if(grid[i][j]!=' '&&grid[i][j]==grid[i][j+1])
	   {
	    grid[i][j]+=1;
	    grid[i][j+1]=' ';
	    checkphrase(grid,i,j,blanks);
	    scorecalc(grid,i,j,score);
	    }
	    spaceleft(grid);
	  }
	}
}
void right(char grid[4][4],int &score,char blanks[])
{
	spaceright(grid);
	for(int i=0;i<4;i++)
	 {
	  for(int j=4;j>0;j--)
	  {
	   if(grid[i][j]!=' '&&grid[i][j]==grid[i][j-1])
	   {
	    grid[i][j]+=1;
	    grid[i][j-1]=' ';
	    checkphrase(grid,i,j,blanks);
	    scorecalc(grid,i,j,score);
	    }
	    spaceright(grid);
	  }
	}
}

//calculation of score
void scorecalc(char grid[4][4],int i,int j,int &score)
{
	switch(grid[i][j])
	{

	    case '2':
	     score+=4;
	     break;
	    case '3':
	     score+=8;
	     break;
	    case '4':
	     score+=16;
	     break;
	    case '5':
	     score+=32;
	     break;
	    case '6':
	     score+=64;
	     break;
	    case '7':
	     score+=128;
	     break;
	    case '8':
	     score+=256;
	     break;
	    case '9':
	     score+=512;
	     break;
	    case '10':
	     score+=1024;
	     break;
	}
}

//win screen
void winscreen(int score,int &level)
{
	setbkcolor(8);
	clrscr();
	cleardevice();
	for(int a=0;a<4;a++)
	{
	 cleardevice();
	 delay(500);
	 cleardevice();
	 settextstyle(2,0,10);
	 outtextxy(250,200,"YOU WIN!");
	 delay(400);
	}
	settextstyle(2,0,7);
	outtextxy(175,400,"Press any key to continue");
	getch();
	char ch;
	cleardevice();
	gotoxy(12,2);
	outtextxy(10,10,"SCORE:");
	cout<<score;
	getch();
	cout<<endl<<endl<<endl<<"  Do you want to proceed to the next level? (Y/N) ";
	cin>>ch;

	if(ch=='y'||ch=='Y')
	{
	 level=level+1;
	 startgame(level);
	}
	else
	{
	 menu();
	}
}

//you lose screen
void losescreen(int score,int &level)
{
	setbkcolor(8);
	clrscr();
	cleardevice();
	settextstyle(2,0,10);
	for(int a=0;a<4;a++)
	{
	 cleardevice();
	 delay(400);
	 outtextxy(220,200,"YOU LOSE!");
	 delay(400);
	}
	delay(500);
	settextstyle(2,0,7);
	outtextxy(175,400,"Press any key to continue");
	getch();
	char ch;
	cleardevice();
	gotoxy(15,2);
	outtextxy(10,10,"SCORE:");
	cout<<score;
	getch();
	cout<<endl<<endl<<endl<<"  Do you want to retry the level? (Y/N) ";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
	 startgame(level);
	}
	else
	{
	 menu();
	}
}
