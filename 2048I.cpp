
/*Author: Akul Kanojia (13114005)*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include<windows.h>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <list>
#include <string>
#include<conio.h>
#include <set>
#include <queue>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits>




using namespace std;
struct node
{
	int count;
	node *left;
	node *right;
	node *up;
	node *down;
};

int stacki[10];
int length=0;
void push(int count)
{
	stacki[length] = count;
	length++;
}

int pop()
{
	int temp;
	if(length)
	{ temp = stacki[length-1];
	stacki[length-1] = 0;
	length--;}
	else temp = 0;
	return temp;
}
void sum()
{
	if(length)
	{
		int temp = length -1;
		for(int i =temp;i>0;i--)
		{
			if(stacki[i] == stacki[i-1]&&stacki[i]!=0)
			{
				stacki[i-1] = stacki[i] + stacki[i-1];
				stacki[i] = 0;

				for(int j = i;j<length-1;j++)
				{
					stacki[j] =stacki[j+1];
					stacki[j+1] = 0;
				}
				i--;
					length--;
				//--i;
			}
		}
	}
}
int play_game()
{
return rand()%16;
}

void CPos(int i,int j)
{
	COORD cPos;
	cPos.X = i ;
	cPos.Y = j ;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cPos);
}
void StdColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

}

//for dislay purposes

 char mapi[24][44];
 void MAP()
 {
 	//horizontal
 	for(int i =0;i<44;i++)
	{
		mapi[0][i] = 'X';
		mapi[23][i] = 'X';
		mapi[5][i] = 'X';
		mapi[11][i] = 'X';
		mapi[17][i] = 'X';
	}
	//vertical
	for(int i =0;i<24;i++)
	{
		mapi[i][43] = 'X';
		mapi[i][0] = 'X';
		mapi[i][10] = 'X';
		mapi[i][21] = 'X';
		mapi[i][32] = 'X';
	}
 }

void drawMAP()
{
	//ios_base::sync_with_stdio(false);
	CPos(0,0);
	for(int i =0;i<24;i++)
	{
		for(int j=0;j<44;j++)
		{
			if(mapi[i][j]=='X')
			{
				cout<<(char)219;
				//printf("%s",(char)219);
			}
			else{
					if(mapi[i][j]==0)
				//printf("%s",mapi[i][j]);
				cout<<mapi[i][j];
				else
			{
				cout<<(int)mapi[i][j];
			}
			}
		}
		cout<<endl;
	}
}
void INIT()
{
	CPos(50,5);
	cout<<"Controls: ";
	CPos(50,7);
	cout<<"w - Up ("<<(char)24<<")";
	CPos(50,9);
	cout<<"s - Down ("<<(char)25<<")";
	CPos(50,11);
	cout<<"d - Right ("<<(char)26<<")";
	CPos(50,13);
	cout<<"a - Left ("<<(char)27<<")";
	CPos(50,15);
	cout<<"Tab - Play Again";
	CPos(50,17);
	cout<<"Esc - Quit";

}
int main()
{
	playagain:
	//ios_base::sync_with_stdio(false);
	SetConsoleTitle("2048 - Akul ");
//	drawRect(50,50);
MAP();
INIT();
drawMAP();





	//declaring 2-D list for the game
	node **one= new node *[4];
	for(int i =0;i<4;i++)
	{
		for(int j=0;j<4;j++)
         one[i] = new node[4];
	}
	//linking everything here
	//initializing everything to 0;

	for(int i =0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
				one[i][j].count = 0;
				if(j<3)
				one[i][j].right = &one[i][j+1];
				else if(j==3)
					one[i][j].right = NULL;
				if(j>0)
				one[i][j].left = &one[i][j-1];
				else if(j==0)
					one[i][j].left = NULL;
				if(i>0)
				one[i][j].up = &one[i-1][j];
				else if(i==0)
					one[i][j].up = NULL;
				if(i<3)
				one[i][j].down = &one[i+1][j];
				else if(i==3)
					one[i][j].down = NULL;
				//cout<<one[i][j].count<<" ";
		}
		//cout<<endl;
	}


char ch;
//cout<<play_game();
bool still_play,won;


again:
	system("cls");
	drawMAP();
	INIT();
	do_again:
	 still_play = false;
	 won = false;
for(int i =0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(one[i][j].count==0)
			{
				still_play = true;

			}
			if(one[i][j].count == 2048)
			{
				won = true;
			}
		}
	}
	if(won)
	{
		cout<<"You Won!";
		return 0;
	}
	if(still_play){
int randno = play_game();
int r = randno%4;
int q = randno/4;
if(one[q][r].count==0){
one[q][r].count += 2;
}
else goto do_again;
	}
	else  {
		cout<<"You Lost!"<<endl;
	}

//==================only-for-display---------------================

int x,y;
for(int i=0;i<4;i++)
{
	for(int j=0;j<4;j++)
	{
		switch(i){
		case 0:
			{
				x = 3;
				break;
			}
		case 1:
			{
				x=8;
				break;
			}
		case 2:
			{
				x=14;
				break;
			}
		case 3:
			{
				x= 20;
				break;
			}
		}
		switch(j){
	case 0:
		{
			y=4;
			break;
		}
	case 1:
		{
			y=15;
			break;
		}
	case 2:
		{
			y=26;
			break;
		}
	case 3:
		{
			y=37;
			break;
		}

		}
		CPos(y,x);
		if(one[i][j].count !=0)
		cout<<one[i][j].count;
	}


}

//actual display

//=================only for display=============================
node current;
//if(kbhit()) //for input buffer
	ch = getch();
//cin>>ch;

if(ch==9) //tab
{
	goto playagain;
}
if(ch==27){return 0;}
//for upward movement
if(ch=='w')
{
	for(int j=0;j<4;j++)
	{
		//current = one[3][j];
		for(int i=3;i>=0;i--)
		{
			current = one[i][j];
		//	cout<<i<<"   "<<j<<endl;
			if(current.count==0)
			{
				if(current.up!=NULL)
				current = *current.up;
			}
			else
			{
				//cout<<current.count;
				push(current.count);
				current.count = 0;
				if(current.up!=NULL)
				current = *current.up;
			}
		}
		//delete current;
		sum();
	//	for(int i =0;i<4;i++) cout<<stacki[i]<<endl;
	//	cout<<endl<<length<<endl;
		for(int i = 0;i<4;i++)
		{
			one[i][j].count = pop();
		}
	}
	goto again;
}
//cout<<endl;



//for downward movement

if(ch=='s')
{
	for(int j=0;j<4;j++)
	{
		//current = one[0][j];
		for(int i=0;i<4;i++)
		{
			current = one[i][j];
		//	cout<<i<<"   "<<j<<endl;
			if(current.count==0)
			{
				if(current.down!=NULL)
				current = *current.down;
			}
			else
			{
				//cout<<current.count;
				push(current.count);
				current.count = 0;
				if(current.down!=NULL)
				current = *current.down;
			}
		}
		//delete current;
		sum();
	//for(int i =0;i<4;i++) cout<<stacki[i]<<endl;
	//cout<<endl<<length<<endl;
		for(int i = 3;i>=0;i--)
		{
			one[i][j].count = pop();
		}
	}
	goto again;
}
//cout<<endl;

// for right movement
if(ch=='d')
{
	for(int i=0;i<4;i++)
	{
		//current = one[i][0];
		for(int j=0;j<4;j++)
		{
			current = one[i][j];
		//	cout<<i<<"   "<<j<<endl;
			if(current.count==0)
			{
				if(current.right!=NULL)
				current = *current.right;
			}
			else
			{
				//cout<<current.count;
				push(current.count);
				current.count = 0;
				if(current.right!=NULL)
				current = *current.right;
			}
		}
		//delete current;
		sum();
	//	for(int i =0;i<4;i++) cout<<stacki[i]<<endl;
	//	cout<<endl<<length<<endl;
		for(int j=3;j>=0;j--)
		{
			one[i][j].count = pop();
		}
	}
	goto again;
}
//cout<<endl;

//for left movement
if(ch=='a')
{
	for(int i=0;i<4;i++)
	{
		//current = one[3][j];
		for(int j=3;j>=0;j--)
		{
			current = one[i][j];
		//	cout<<i<<"   "<<j<<endl;
			if(current.count==0)
			{
				if(current.left!=NULL)
				current = *current.left;
			}
			else
			{
				//cout<<current.count;
				push(current.count);
				current.count = 0;
				if(current.left!=NULL)
				current = *current.left;
			}
		}
		//delete current;
		sum();
	//	for(int i =0;i<4;i++) cout<<stacki[i]<<endl;
	//	cout<<endl<<length<<endl;
		for(int j = 0;j<4;j++)
		{
			one[i][j].count = pop();
		}
	}
	goto again;
}
//cout<<endl;




//====================only for display========================
cout<<endl;

for(int i=0;i<4;i++)
{
	for(int j=0;j<4;j++)
		cout<<one[i][j].count<<" ";
	cout<<endl;
}
//=======================================================
}

//Yo Yo Honey Singh : Volume 1......//////


//========================END OF THE GAME+=======================
