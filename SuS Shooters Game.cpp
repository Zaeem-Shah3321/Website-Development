#include <iostream> 
#include <windows.h>
#include<conio.h>
using namespace std;
void gotoxy (int x , int y);
char getCharAtxy(short int x, short int y);
void print_enemy_1();
void erase_enemy_1();
void print_enemy_2();
void erase_enemy_2();
string changeDirection_1(string);
string changeDirection_2(string);
void print_player();
void erase_player();
void move_player_left();
void move_player_right();
void move_player_up ();
void move_player_down ();
void move_enemy_1(string);
void move_enemy_2(string);
void print_maze();
void printfire();
void movefire();
void printName();
void score();
void won();
string setcolor(unsigned short color);
int eX1 = 15 , eY1 = 1;
int eX2 = 100, eY2 = 10;
int pX = 1 , pY = 24;
int bonus = 0;
int fX = 0 , fY = 0;
int scores = 0;
bool bullet = false;
int enemyhealth1 = 10;
int enemyhealth2 = 5;
main ()
{
    system ("cls");
    printName();
    getch();
    system("cls");
    print_maze ();
    print_enemy_1 ();
    print_enemy_2 ();
    print_player ();
    bool woon = false;
    string enemyDirection_1 = "right";
    string enemyDirection_2 = "down";
        while(true)
        {
        if (GetAsyncKeyState(VK_LEFT))
        {
            move_player_left();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            move_player_right();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            move_player_up();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            move_player_down();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            if (!bullet)
            {
                printfire();
                bullet = true;
            }
        }
        if (bullet)
        {
            movefire();
        }
        if (!woon)
        {
            score();
        }
        if (enemyhealth1 == 0 && enemyhealth2 == 0)
        {
            won();
            woon = true;
            return 0;
        }

        if (enemyhealth1 != 0)
        {
            move_enemy_1(enemyDirection_1);
        }
        enemyDirection_1 = changeDirection_1(enemyDirection_1);
        Sleep (1);
        if (enemyhealth2 != 0)
        {
            move_enemy_2(enemyDirection_2);
        }
        enemyDirection_2 = changeDirection_2(enemyDirection_2);
        Sleep (1);
        }
        
        return 0;
    }
void score()
{
    setcolor(14);
    gotoxy (0,26);
    cout << "########################################################################################################################" << endl;
    gotoxy (0,27);
    cout << "#   Score : " << scores << "                 Enemy 1 Health: " << enemyhealth1 << "                 Enemy 2 Health: " << enemyhealth2 <<"                                     #"<<endl;
    gotoxy (0,28);
    cout << "########################################################################################################################" << endl;
}

void print_maze ()
{
    setcolor(2);
    cout << "########################################################################################################################" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "#                                                                                                                      #" << endl;
    cout << "########################################################################################################################" << endl;
}
void print_player ()
{ 
    setcolor(5);
    gotoxy (pX , pY - 7);
    cout << "  ******** " << endl;
    gotoxy (pX , pY - 6);
    cout << "  *      * " << endl;
    gotoxy (pX , pY - 5);
    cout << "***    ****" << endl;
    gotoxy (pX , pY - 4);
    cout << "* *    ****" << endl;
    gotoxy (pX , pY - 3 );
    cout << "* *      * " << endl;
    gotoxy (pX , pY - 2);
    cout << "***  **  * " << endl;
    gotoxy (pX , pY - 1 );
    cout << "  ***  *** " << endl;
}
void erase_player ()
{
    gotoxy (pX , pY - 7);
    cout << "           " << endl;
    gotoxy (pX , pY - 6);
    cout << "           " << endl;
    gotoxy (pX , pY - 5);
    cout << "           " << endl;
    gotoxy (pX , pY - 4);
    cout << "           " << endl;
    gotoxy (pX , pY - 3);
    cout << "           " << endl;
    gotoxy (pX , pY - 2);
    cout << "           " << endl;
    gotoxy (pX , pY - 1);
    cout << "           " << endl;
}
string changeDirection_1(string direction)
{

    if (direction == "right" && eX1 >= 50)
    {
        direction = "left";
    }
    if (direction == "left" && eX1 <= 2)
    {
        direction = "right";
    }
    return direction;
}
string changeDirection_2(string direction)
{

    if (direction == "down" && eY2 >= 20)
    {
        direction = "up";
    }
    if (direction == "up" && eY2 <= 10)
    {
        direction = "down";
    }
    return direction;
}
void print_enemy_1 ()
{
    setcolor(4);
    gotoxy (eX1 , eY1);
    cout << "   ||||   " << endl;
    gotoxy (eX1 , eY1 + 1);
    cout << "  {    } " << endl;
    gotoxy (eX1 , eY1 + 2);
    cout << " ( O  O ) " << endl;
    gotoxy (eX1 , eY1 + 3);
    cout << "  {    }  " << endl;
    gotoxy (eX1 , eY1 + 4);
    cout << "   {xx}   " << endl;
} 
void erase_enemy_1 ()
{
    gotoxy (eX1 , eY1 );
    cout << "          " << endl;
    gotoxy (eX1 , eY1 + 1);
    cout << "          " << endl;
    gotoxy (eX1 , eY1 + 2);
    cout << "          " << endl;
    gotoxy (eX1 , eY1 + 3);
    cout << "           " << endl;
    gotoxy (eX1 , eY1 + 4);
    cout << "           " << endl;
}
void move_enemy_1 (string direction)
{
    erase_enemy_1();
    if (direction == "right")
    {
        eX1 = eX1 + 1;
    }
    if (direction == "left")
    {
        eX1 = eX1 - 1;
    }
    print_enemy_1();
}
void print_enemy_2()
{
    setcolor(3);
    gotoxy (eX2 , eY2);
    cout << " __/\\_  " << endl;
    gotoxy (eX2 , eY2 + 1);
    cout << "/o))))\\/" << endl; 
    gotoxy (eX2 , eY2 + 2);
    cout << "\\o))))/\\" << endl;
    gotoxy (eX2  , eY2 + 3);
    cout << " --\\/-   ";
}
void erase_enemy_2()
{
    gotoxy (eX2 , eY2);
    cout << "         " << endl;
    gotoxy (eX2 , eY2 + 1);
    cout << "         " << endl; 
    gotoxy (eX2  , eY2 + 2);
    cout << "         " << endl;
    gotoxy (eX2  , eY2 + 3);
    cout << "          " << endl ;
}
void move_enemy_2 (string direction)
{
    erase_enemy_2();
    if (direction == "down")
    {
        eY2 = eY2 + 1;
    }
    if (direction == "up")
    {
        eY2 = eY2 - 1;
    }
    print_enemy_2();
}
void move_player_left() 
{
    if (getCharAtxy(pX - 1 , pY) == '$'  || getCharAtxy(pX - 1 , pY-1) == '$' || getCharAtxy(pX - 1, pY-2) == '$'||getCharAtxy(pX - 1, pY-3) == '$'||getCharAtxy(pX -1 , pY-4) == '$'||getCharAtxy(pX  - 1, pY-5) == '$'||getCharAtxy(pX - 1, pY-6) == '$')
    {
        erase_player();
        bonus = bonus + 1;
        pX = pX + 1 ;
        print_player();
    } 
    if (getCharAtxy(pX - 1 , pY-1) == ' ')
    {
        erase_player();
        pX = pX - 1 ;
        print_player();
    }
}
void move_player_right()
{
    if (getCharAtxy(pX + 11, pY) == '$'  || getCharAtxy(pX + 11, pY-1) == '$' || getCharAtxy(pX + 11, pY-2) == '$'||getCharAtxy(pX + 11, pY-3) == '$'||getCharAtxy(pX + 11, pY-4) == '$'||getCharAtxy(pX + 11, pY-5) == '$'||getCharAtxy(pX + 11, pY-6) == '$')
    {
        erase_player();
        bonus = bonus + 1;
        pX = pX + 1 ;
        print_player();
    } 
    if (getCharAtxy(pX + 11, pY-1) == ' ')
    {
        erase_player();
        pX = pX + 1 ;
        print_player();
    } 
}
void move_player_up() 
{
    if (getCharAtxy(pX  , pY - 8) == ' ')
    {
        erase_player();
        pY = pY - 1 ;
        print_player();
    }
}
void move_player_down()
{
    if (getCharAtxy(pX, pY) == ' ')
    {
        erase_player();
        pY = pY + 1 ;
        print_player();
    }
}
void printfire()
{
    fX = pX + 12;
    fY = pY - 3;
    gotoxy(fX , fY);
    setcolor(14);
    cout << "!";
    bullet = true;
}
void movefire()
{
    gotoxy (fX ,fY);
    cout << " ";
    if (getCharAtxy(fX + 1 , fY) == ' ')
    {
        fX += 1;
        gotoxy(fX , fY);
        cout << "!";
    }
    else if (getCharAtxy(fX + 1 , fY) == '/' || getCharAtxy(fX + 1 , fY) == '\\' || getCharAtxy(fX + 1 , fY) == '-' || getCharAtxy(fX + 1 , fY) == '_')
    {
        enemyhealth2--;
        scores++;
        bullet = false;
        if(enemyhealth2 == 0)
        {
            erase_enemy_2();
        }
    }
    else if (getCharAtxy(fX + 1 , fY) == '{' || getCharAtxy(fX + 1 , fY) == '}' || getCharAtxy(fX + 1 , fY) == 'x' || getCharAtxy(fX + 1 , fY) == '('|| getCharAtxy(fX + 1 , fY) == ')')
    {
        enemyhealth1--;
        scores = scores + 2;
        bullet = false;
        if (enemyhealth1 == 0)
        {
            erase_enemy_1();
        }
    }
    else 
    {
        bullet = false;
    }
}
void printName()
{
    setcolor(6);
    cout << R"(   .-')                  .-')           .-')    ('-. .-.                           .-') _     ('-.  _  .-')    .-')    )" << endl; 
    cout << R"(  ( OO ).               ( OO ).        ( OO ). ( OO )  /                          (  OO) )  _(  OO)( \( -O )  ( OO ).  )" << endl; 
    cout << R"( (_)---\_) ,--. ,--.   (_)---\_)      (_)---\_),--. ,--. .-'),-----.  .-'),-----. /     '._(,------.,------. (_)---\_) )" << endl; 
    cout << R"( /    _ |  |  | |  |   /    _ |       /    _ | |  | |  |( OO'  .-.  '( OO'  .-.  '|'--...__)|  .---'|   /`. '/    _ |  )" << endl; 
    cout << R"( \  :` `.  |  | | .-') \  :` `.       \  :` `. |   .|  |/   |  | |  |/   |  | |  |'--.  .--'|  |    |  /  | |\  :` `.  )" << endl; 
    cout << R"(  '..`''.) |  |_|( OO ) '..`''.)       '..`''.)|       |\_) |  |\|  |\_) |  |\|  |   |  |  (|  '--. |  |_.' | '..`''.) )" << endl; 
    cout << R"( .-._)   \ |  | | `-' /.-._)   \      .-._)   \|  .-.  |  \ |  | |  |  \ |  | |  |   |  |   |  .--' |  .  '.'.-._)   \ )" << endl; 
    cout << R"( \       /('  '-'(_.-' \       /      \       /|  | |  |   `'  '-'  '   `'  '-'  '   |  |   |  `---.|  |\  \ \       / )" << endl; 
    cout << R"(  `-----'   `-----'     `-----'        `-----' `--' `--'     `-----'      `-----'    `--'   `------'`--' '--' `-----'  )" << endl;   
    cout << endl;
    cout << endl;
    cout << "<=============================================== Press Any Key to Start Game =============================================>";
}
void won()
{
    Sleep(1000);
    system("cls");
    setcolor(9);
    cout << R"(                                               (`\ .-') /`                  .-') _  )" << endl;
    cout << R"(                                                `.( OO ),'                 ( OO ) ) )" << endl;
    cout << R"(   ,--.   ,--..-'),-----.  ,--. ,--.         ,--./  .--.   .-'),-----. ,--./ ,--,'  )" << endl;
    cout << R"(    \  `.'  /( OO'  .-.  ' |  | |  |         |      |  |  ( OO'  .-.  '|   \ |  |\  )" << endl;
    cout << R"(  .-')     / /   |  | |  | |  | | .-')       |  |   |  |, /   |  | |  ||    \|  | ) )" << endl;
    cout << R"( (OO  \   /  \_) |  |\|  | |  |_|( OO )      |  |.'.|  |_)\_) |  |\|  ||  .     |/  )" << endl;
    cout << R"(  |   /  /\_   \ |  | |  | |  | | `-' /      |         |    \ |  | |  ||  |\    |   )" << endl;
    cout << R"(  `-./  /.__)   `'  '-'  '('  '-'(_.-'       |   ,'.   |     `'  '-'  '|  | \   |   )" << endl;
    cout << R"(    `--'          `-----'   `-----'          '--'   '--'       `-----' `--'  `--'   )" << endl;
    cout << endl;
    cout << endl;
    cout << "<=================== Good Job SuS , All Aliens Killed , Earth Is Saved ==============>";
}
void gotoxy (int x , int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy (short int x , short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
    : ' ';
}
string setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);   
    return"";
}
