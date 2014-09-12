#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void CPos(int i, int j)
{
     COORD cPos;
     cPos.X = j;
     cPos.Y = i;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cPos);
}

void StdColor()
{
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

char map[20][30] = {"XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X             P             X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX"};
                    
void DrawArray()
{
     CPos(20,0);
     for(int i =0; i < 20; i++)
     {
             for(int j = 0; j < 30; j++)
             {
                     cout << map[i][j];
             }
             cout << endl;
     }
}

void DrawMap();
void Map();
void Keys();
void Inst();
void Check();

int Key;
int x,y;
char player = (char)1;
char back = ' ';
char s_save = ' ';
bool switcher = false;
bool draw = false;
int s_side;

int main()
{
    SetConsoleTitle("Console PhysX");
    DrawMap();
    while(Key != 27)
    {
    Map();
    Inst();
    Check();
    if(draw == true) DrawArray();
    if(kbhit()){ Key = getch(); Keys(); }
    if(kbhit()){ Key = getch(); Keys(); }
    if(kbhit()){ Key = getch(); Keys(); }
    CPos(21,0);
    Sleep(100);
    }
    return 0;
}

void DrawMap()
{
     for(int i = 0; i < 20; i++)
     {
             for(int j = 0; j < 30; j++)
             {
                     switch(map[i][j])
                     {
                                      case 'X':
                                           CPos(i,j);
                                           cout << (char)219;
                                           break;
                     }
             }
             cout << endl;
     }
}

void Map()
{
     for(int i = 0; i < 20; i++)
     {
             for(int j = 0; j < 30; j++)
             {
                     switch(map[i][j])
                     {
                                      case 'P':
                                           y = i;
                                           x = j;
                                           map[y][x] = 'P';
                                           CPos(i,j);
                                           cout << player;
                                           break;
                                      case '#':
                                           CPos(i,j);
                                           cout << '#';
                                           switch(switcher)
                                           {
                                                           case true:
                                                                if (s_side == 1 && map[i][j-2] == ' ' && map[i][j-1] != 'W' || map[i][j-2] == 'W' && map[i][j-1] != '~' || map[i][j-2] == '~'){ s_save = map[i][j-1];
                                                                                                                                                    map[i][j-1] = ' ';
                                                                                                                                                    CPos(i,j-1); cout << ' ';
                                                                                                                                                    map[i][j-2] = s_save; }
                                                                if (s_side == 2 && map[i][j+2] == ' ' && map[i][j+1] != 'W' || map[i][j+2] == 'W' && map[i][j+1] != '~' || map[i][j+2] == '~'){ s_save = map[i][j+1];
                                                                                                                                                    map[i][j+1] = ' ';
                                                                                                                                                    CPos(i,j+1); cout << ' ';
                                                                                                                                                    map[i][j+2] = s_save; }
                                                                break;
                                           }
                                           break;
                                      case 'l':
                                           map[i][j] = 'L';
                                           CPos(i,j);
                                           cout << (char)176;
                                           break;
                                      case '5':
                                           map[i][j] = 'b';
                                           CPos(i,j);
                                           cout << (char)178;
                                           break;
                                      case 'L':
                                           CPos(i,j); 
                                           cout << (char) 176;
                                           if(map[i+1][j] == ' ' || map[i+1][j] == 'W'){ map[i][j] = ' '; CPos(i,j); cout << ' '; map[i+1][j] = 'l'; }
                                           break;
                                      case 'b':
                                           CPos(i,j);
                                           cout << (char)178;
                                           if(map[i+1][j] == ' ' || map[i+1][j] == 'W'){ map[i][j] = ' '; CPos(i,j); cout << ' '; map[i+1][j] = '5'; }
                                           break;
                                      case 'B':
                                           CPos(i,j);
                                           cout << (char)219;
                                           break;
                                      case 'w':
                                           CPos(i,j);
                                           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 153);
                                           cout << ' ';
                                           StdColor();
                                           map[i][j] = 'W';
                                           break;
                                      case 'W':
                                           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 153);
                                           CPos(i,j);
                                           cout << ' ';
                                           if(map[i-1][j] == '~'  && map[i+1][j] == '~' || map[i-1][j] == 'W') map[i][j] = '~';
                                           if(map[i+1][j] == ' ') map[i+1][j] = '`';
                                           if(map[i+1][j] == 'W' || map[i+1][j] == 'w' || map[i+1][j] == '~' || map[i+1][j] == '`');
                                           else if(map[i+1][j] == 'P');
                                           else{
                                           if(map[i][j-1] == ' ' && map[i+1][j] != 'P') map[i][j-1] = 'W';
                                           if(map[i][j+1] == ' ' && map[i+1][j] != 'P') map[i][j+1] = 'w';
                                           // Light block physx
                                           if(map[i][j-1] == 'L' && map[i][j-2] == ' '){ map[i][j-1] = 'W'; map[i][j-2] = 'L'; }
                                           if(map[i][j+1] == 'L' && map[i][j+2] == ' '){ map[i][j+1] = 'w'; map[i][j+2] = 'L'; }
                                           }
                                           StdColor();
                                           break;
                                      case '~':
                                           CPos(i,j); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 153); cout << ' '; StdColor();
                                           if(map[i-1][j] != 'W' && map[i-1][j] != 'w' && map[i-1][j] != '~' && map[i-1][j] != '`'){ map[i][j] = ' '; CPos(i,j); cout << ' '; }  
                                           if(map[i+1][j] == ' ' && map[i+1][j] != 'P'){ map[i+1][j] = '`'; }
                                           if(map[i+1][j] != 'W' && map[i+1][j] != 'w' && map[i+1][j] != '~' && map[i+1][j] != '`' && map[i+1][j] != ' ' && map[i+1][j] != 'P')
                                           {
                                                          map[i][j] = 'W';
                                           }
                                           break;
                                      case '`':
                                           map[i][j] = '~';
                                           CPos(i,j); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 153); cout << ' '; StdColor();
                                           break;
                     }
             }
     }
     switcher = false;
}

void Keys()
{
     switch(Key)
     {
                case 9: // TAB
                     for(int i = 0; i < 20; i++)
                     {
                             for(int j = 0; j < 30; j++)
                             {
                                     switch(map[i][j])
                                     {
                                                      case 'P':
                                                              break; 
                                                      case 'X':
                                                              break;
                                                      default:
                                                              map[i][j] = ' ';
                                                              CPos(i,j);
                                                              cout << ' ';
                                                              break;
                                     }
                             }
                     }
                     DrawMap();
                     CPos(y,x);
                     cout << (char)1;
                     back = ' ';
                     break;
                case 112: // P
                     switch(draw)
                     {
                                 case true:
                                      draw = false;
                                      system("CLS");
                                      DrawMap();
                                      break;
                                 case false:
                                      draw = true;
                                      break;
                     }
                     break;
                case 32: // SPACE
                     back = ' ';
                     break;
                case 114: // R
                     switcher = false;
                     back = '#';
                     break;
                case 99: // C
                     back = 'L';
                     break;
                case 102: // F
                     back = 'b';
                     break;
                case 113: // Q
                     back = 'B';
                     break;
                case 101: // E
                     back = 'W';
                     break;
                case 75: // LEFT
                     switcher = true;
                     s_side = 1;
                     break;
                case 77: // RIGHT
                     switcher = true;
                     s_side = 2;
                     break;
                case 119: // W
                if(map[y-1][x] == 'X') break;
                     map[y][x] = back;
                     CPos(y,x);
                     cout << back;
                     back = map[y-1][x];
                     y--;
                     map[y][x] = 'P';
                     CPos(y,x);
                     cout << player;
                     break;
                case 115: // S
                if(map[y+1][x] == 'X') break;
                     map[y][x] = back;
                     CPos(y,x);
                     cout << back;
                     back = map[y+1][x];
                     y++;
                     map[y][x] = 'P';
                     CPos(y,x);
                     cout << player;
                     break;
                case 97: // A
                if(map[y][x-1] == 'X') break;
                     map[y][x] = back;
                     CPos(y,x);
                     cout << back;
                     back = map[y][x-1];
                     x--;
                     map[y][x] = 'P';
                     CPos(y,x);
                     cout << player;
                     break;
                case 100: // D
                if(map[y][x+1] == 'X') break;
                     map[y][x] = back;
                     CPos(y,x);
                     cout << back;
                     back = map[y][x+1];
                     x++;
                     map[y][x] = 'P';
                     CPos(y,x);
                     cout << player;
                     break;
     }
}

void Check()
{
     if(back == '~' || back == '`') back = ' ';
}

void Inst()
{
     CPos(1,32);
     cout << "WASD - move";
     CPos(2,32);
     cout << "L/R arrows - switchers";
     CPos(3,32);
     cout << "Q - place block " << (char)219;
     CPos(4,32);
     cout << "F - place falling block " << (char)178;
     CPos(5,32);
     cout << "E - place water block "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 153); cout << ' '; StdColor();
     CPos(6,32);
     cout << "R - place switcher " << '#';
     CPos(7,32);
     cout << "C - place light block " << (char)176;
     CPos(8,32);
     cout << "P - draw array";
     CPos(9,32);
     cout << "TAB - clean the map";
     CPos(10,32);
     cout << "ESC - exit";
     CPos(21,0);
}
