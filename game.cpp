/* 
    NAMA KELOMPOK : NPM
    BUNGARAN NATANAEL SIAHAAN : 2317051048
    DEA DELVINATA             : 2317051027
    RIZKY KURNIA ANTASARI     : 2357051011
*/

// INCLUDING LIBRARY
#include <bits/stdc++.h> 
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <time.h>
#include <windows.h>
#include <iomanip> // menepatkan bar agar tidak geser
#include <ncurses/curses.h>

// COLORING
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CLAY "\033[36m"
#define WHITE "\033[37m"
#define GRAY "\033[1;30m"
#define WHITE_BG "\033[47m"

using namespace std;
using std::setw;

//POSITIONING 
short int X, Y;
COORD coord = {X=0, Y=0};

void gotoxy(int x, int y) {
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// DEKLARASI SYSTEM
    string username;
    string name;
    string user[99]={""}; // default
    string pass[99]={""}; // default
    string password;
    int pemberhentian=0;int i=0,j=0;

    char option;char jawaban;char belanja;

    bool found = false;

// DEKLARASI IN-GAME
    int health = 1000, gold=100000, defense = 0, SwordLevel = 0;int stamina=20;
    int SwordCost1 = 50;int experience=0; // pvp, monster,shop;
    char timeExplore;//hours
    char up;
    char sword;
    string todo;
    bool Exit = false; // untuk bolak baik ke main menu- how to plays
    bool muncul=false; // ngeliatain kalo udah max sword 
    bool warna; // warna temple

    int N; // lama berperang;
// Global Loading
void global(){
    char x = 219;
            for(int i=0;i<=29;i++){
            Sleep(90);
            cout << "\033[34m" << x << "\033[0m";}
}
// Global Loading

int dmg;
int HealthBar(int dmg){
    for(int i=30;i>0;i--){
        char x=219; 
        if(i >= 22){
            gotoxy(60,13);
            for(int j=i;j>0;--j){cout << GREEN << x;}
        }else if(i >= 12 ){
            gotoxy(60,13);
            for(int j=i;j>0;--j){cout << YELLOW << x << RESET;}
        }else{
            gotoxy(60,13);
            for(int j=i;j>0;--j){cout << RED << x << RESET;}
        }
            for(int j=30-i;j>0;--j){cout << " ";}
        Sleep(200);    
    }
    // gotoxy nya belom di set.
}

void success(){
    gotoxy(48,28);cout << MAGENTA << "Success !" <<RESET;
}

void ShopStatus(){
int z=1;int i=2;
gotoxy(z,i);cout << setw(5) << ".=~=.                            .=~=.";i++;
gotoxy(z,i);cout << setw(5) << "(__)-._.-=-._.-=-._.-=-._.-=-._.-=(__)";i++;
gotoxy(z,i);cout << setw(5) << "(__)                              (__)";i++;
gotoxy(z,i);cout << setw(5) << "(__)-._.-=-._.-=-._.-=-._.-=-._.-=(__)";i++;
gotoxy(z,i);cout << setw(5) << "(__)                              (__)";i++;
gotoxy(z,i);cout << setw(5) << "(__)  " << RED << "Health  : "     << setw(7) << health     << WHITE << "           (__)";i++;
gotoxy(z,i);cout << setw(5) << "(__)  " << BLUE << "Defense : "    << setw(7) << defense    << WHITE << "           (__)";i++;
gotoxy(z,i);cout << setw(5) << "(__)  " << YELLOW << "Gold    : "  << setw(7) << gold       << WHITE << "           (__)";i++;
gotoxy(z,i);cout << setw(5) << "(__)  " << GREEN << "Stamina : "   << setw(7) << stamina    << WHITE << "           (__)";i++;
gotoxy(z,i);cout << setw(5) << "(__)  " << MAGENTA << "EXP     : " << setw(7) << experience << WHITE << "           (__)";i++;
gotoxy(z,i);cout << setw(5) << "(__)                              (__)";i++;
gotoxy(z,i);cout << setw(5) << "(__)-._.-=-._.-=-._.-=-._.-=-._.-=(__)";i++;
gotoxy(z,i);cout << setw(5) << "'._.'                            '._.'";i++;
cout << RESET;
}

void barStatus() {
    int z=50;int i=2;
    cout << GREEN;
gotoxy(z,i);cout << "      _________________________________";i++;
gotoxy(z,i);cout << "     /      B A R     S T A T U S      \\";i++;
gotoxy(z,i);cout << "    /___________________________________\\";i++;
gotoxy(z,i);// Menggunakan setw untuk menetapkan lebar tetapi++;
gotoxy(z,i);cout << setw(5) << "   |" << RED <<"  Health      : "<< setw(7) << health << GREEN << "            |";i++;
gotoxy(z,i);cout << setw(5) << "   |" << BLUE <<"  Defense     : " << setw(7) << defense << GREEN << "            |";i++;
gotoxy(z,i);cout << setw(5) << "   |" << YELLOW << "  Gold        : " << setw(7) << gold << GREEN << "            |";i++;
gotoxy(z,i);cout << setw(5) << "   |" << MAGENTA <<"  Experience  : " << setw(7) << experience << GREEN << "            |";i++;
gotoxy(z,i);cout << "    \\__________________________________/";i++;
    //HealthBar();
    cout << RESET;
}

//Menu login with Boolean
void login(){name.clear();password.clear(); // found = false; - revisi
    int W=42;int V=7;
cout << BLUE;
gotoxy(W,V);cout << "   .'_________________________________________  '." ;V++;
gotoxy(W,V);cout << "  : .'                                         '. :";V++;
gotoxy(W,V);cout << "  | |    ____________________________________   | |";V++;
gotoxy(W,V);cout << "  | |  .:____________________________________:. | |";V++;
gotoxy(W,V);cout << "  | |  |               LOGIN                 |  | |";V++;
gotoxy(W,V);cout << "  | |  |                                     |  | |";V++;
gotoxy(W,V);cout << "  | |  | User ID  :                          |  | |";V++;
gotoxy(W,V);cout << "  | |  | Password :                          |  | |";V++;
gotoxy(W,V);cout << "  | |  |                                     |  | |";V++;    
gotoxy(W,V);cout << "  | |  '.________|__|__|__|__|__|__|________.'  | |";V++;
gotoxy(W,V);cout << "  | |                                           | |";V++;
gotoxy(W,V);cout << "  : '._________________________________________.' :";V++;
gotoxy(W,V);cout << "   .____________________\\__/____________________." ;V++;
cout << RESET;
        gotoxy(V+42,13);cin >> name;
        gotoxy(V+42,14);cin >> password;
        for(int a=0;a<99;a++){
        if(name == user[a] && password == pass[a] || name == "dev" && password == "devpass")
        {   int W=42,V=7;
            global();
            system("cls");
            found = true;
            name.clear();password.clear();
            break;
        }
        if(!found)
        {   int W=42,V=7;
            system("cls");
            name.clear();password.clear();
            gotoxy(W+14,22);cout << "\033[31m"<< "Wrong Password or User-ID !" << "\033[0m"<< endl;
            login();
        }
        }
}

rule(){

}
// Registration
void Register(){
    //rule();

    system("cls");
    system("color 07");
    int W=42;int V=7;
   while(true){
        if(pemberhentian == 1){
            break;
        }
cout << WHITE;
gotoxy(W,V);cout << "   .'_________________________________________  '." ;V++;
gotoxy(W,V);cout << "  : .'                                         '. :";V++;
gotoxy(W,V);cout << "  | |    ____________________________________   | |";V++;
gotoxy(W,V);cout << "  | |  .:____________________________________:. | |";V++;
gotoxy(W,V);cout << "  | |  |              REGISTER               |  | |";V++;
gotoxy(W,V);cout << "  | |  |                                     |  | |";V++;
gotoxy(W,V);cout << "  | |  | User ID  :                          |  | |";V++;
gotoxy(W,V);cout << "  | |  | Password :                          |  | |";V++;
gotoxy(W,V);cout << "  | |  |                                     |  | |";V++;    
gotoxy(W,V);cout << "  | |  '.________|__|__|__|__|__|__|________.'  | |";V++;
gotoxy(W,V);cout << "  | |                                           | |";V++;
gotoxy(W,V);cout << "  : '._________________________________________.' :";V++;
gotoxy(W,V);cout << "   .____________________\\__/____________________." ;V++;
cout << RESET;
        gotoxy(V+42,13);cin >> user[i];i++;
        gotoxy(V+42,14);cin >> pass[j];j++;
        gotoxy(V+20,21);cout << "Your New-Account is Be Able to Create !";
        gotoxy(V+20,22);cout << "Create Account (y/n) : ";
                cin >> jawaban;
        if(jawaban == 'y'){
        pemberhentian+=1;
         }else{
            V =7;W=42;
            i = i - i;
            j = j - j;
            system("cls");
         }
    }
    gotoxy(V+19,23);global();
    gotoxy(V+19,24);cout << "Account has been created ! " << endl;
    system("cls");
    login();
}

void potion(){
    cout << "   ________" << endl;
    cout << "  /        \\" << endl;
    cout << " |   (o)    |" << endl;
    cout << " |   _\\/_   |" << endl;
    cout << "  \\________/" << endl;
}

void ShopDesc(){
    int i=22;
gotoxy(57+26,i);cout << " ________________________________________________";i++;
gotoxy(57+26,i);cout << "( |                                            | )";i++;
gotoxy(57+26,i);cout << "| | Armor can make your defense more great !   | |";i++;
gotoxy(57+26,i);cout << "| | Sword can make your adventure easier       | |";i++;
gotoxy(57+26,i);cout << "| | HP POT can Restore your health up to 35%   | |";i++;
gotoxy(57+26,i);cout << "| | Stamina POT can restore 25 of your stamina | |";i++;
gotoxy(57+26,i);cout << "(_|____________________________________________|_)";i++;
}

/*
        B A T T L E    F I E L D
*/

int Temple(bool warna = false){
    system("cls");
    int z=30;int i=0;
if(!warna){
    cout << RED;
}
else if(warna){
    cout << GREEN;
}
gotoxy(z,i);cout << "                   )\\         O_._._._A_._._._O         /(                    ";i++;
gotoxy(z,i);cout << "                    \\`--.___,'=================`.___,--'/                     ";i++;
gotoxy(z,i);cout << "                     \\`--._.__                 __._,--'/                      ";i++;
gotoxy(z,i);cout << "                       \\  ,. l`~~~~~~~~~~~~~~~'l ,.  /                        ";i++;
gotoxy(z,i);cout << "           _s_            \\||(_)!_!_!_.-._!_!_!(_)||/            __            ";i++;
gotoxy(z,i);cout << "           \\`-.__        ||_|____!!_|;|_!!____|_||        __,-'//             ";i++;
gotoxy(z,i);cout << "            \\    `==---='-----------'='-----------`=---=='    //              ";i++;
gotoxy(z,i);cout << "            | `--.                                         ,--' |              ";i++;
gotoxy(z,i);cout << "             \\  ,.`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~',.  /              ";i++;
gotoxy(z,i);cout << "               \\||  ____,-------._,-------._,-------.____  ||/                ";i++;
gotoxy(z,i);cout << "                ||\\|___!`======= !`======= !`======= !___|/||                 ";i++;
gotoxy(z,i);cout << "                || |---||--------||-| | |-!!--------||---| ||                  ";i++;
gotoxy(z,i);cout << "      __O_____O_ll_lO_____O_____O|| |'|'| ||O_____O_____Ol_ll_O_____O__        ";i++;
gotoxy(z,i);cout << "      o H o o H o o H o o H o o |-----------| o o H o o H o o H o o H o        ";i++;
gotoxy(z,i);cout << "     ___H_____H_____H_____H____O =========== O____H_____H_____H_____H___       ";i++;
gotoxy(z,i);cout << "                              /|=============|\\                               ";i++;
gotoxy(z,i);cout << "    ()______()______()______() '==== +-+ ====' ()______()______()______()      ";i++;
gotoxy(z,i);cout << "    ||{_}{_}||{_}{_}||{_}{_}/| ===== |_| ===== |\\{_}{_}||{_}{_}||{_}{_}||     ";i++;
gotoxy(z,i);cout << "    ||      ||      ||     / |==== s(   )s ====| \\     ||      ||      ||     ";i++;
gotoxy(z,i);cout << "    ======================()  =================  ()======================      ";i++;
gotoxy(z,i);cout << "    ----------------------/| ------------------- |\\----------------------     ";i++;
gotoxy(z,i);cout << "                         / |---------------------| \\                          ";i++;
gotoxy(z,i);cout << "    -'--'--'           ()  '---------------------'  ()                         ";i++;
gotoxy(z,i);cout << "                       /| ------------------------- |\\    --'--'--'           ";i++; 
gotoxy(z,i);cout << "           --'--'     / |---------------------------| \\    '--'               ";i++;
gotoxy(z,i);cout << "                    ()  |___________________________|  ()           '--'-      ";i++;
gotoxy(z,i);cout << "      --'-          /| _______________________________  |\\                    ";i++;
gotoxy(z,i);cout << "     --'           / |__________________________________| \\                   ";i++;

cout << RESET;
}

void Dataran(){
    int z=0;
    int i=24;                                                                                                  
gotoxy(z,i);cout << "~~^ ~~^-~^_~^~/  \\~^-~^~_~                                               \\~^-~^~_~^-~_^~-^~_^~~-^~_~^~^~-^~_^~~-^~_~^~-~_~-^~_^/  -~^_~^~/  \\~^-~^~_ ";i++;
gotoxy(z,i);cout << "~ _~~- ~~^-~^_~^~/  \\~^-~^~_~_~                                       - ^~_^-^~~_ -~^_ -~_-~~^- _~~^~-^~_^~~-^~_~^~-~_~-^~_^/  -~^_~^~/  \\~^-~^~";i++;
gotoxy(z,i);cout << "~ ^- ~~^-~^_~^~/  \\~^-~^~_~^-~_^~-^~_^~~-^~_~                      ~/  \\~^-~^~_~^-~_^~-^~_^~~-^~_~^~-~_~-   _~~_-  ~~ _ ~  ^~  - ~~^ -~_-~~^- ";i++;
gotoxy(z,i);cout << "~-  ^_  ~^ -  ^~ _ - ~^~ _   _~^~-  _ ~~^ - _ ~ - _ ~~^ -      ~~^-~^_~^~/  \\~^-~^~_~^-~_^~-^~_^~~-^~_~^~-~_~-^~_^/  ~~^-~^_~^~/  \\~^-~^~_~^-~_^~";i++;
gotoxy(z,i);cout << "~~^-~^_~^~/  \\~^-~^~_~^-~_^~-^~_^~~-^~_~^~-~_~-^~_^/  ~~^-~^_~^~/  \\~^-~^~_~^-~_^~-^~_^~~-^~_~^~-~_~-^~_^/  ~^ -_ ~^^ -_ ~ _ - _ ~^~-  _~ -_   ~ ";i++;
gotoxy(z,i);cout << "~~^-~^_~^~/ ~~^-~^_~^~/  \\~^-~^~_~^-~_^~-^~_^~~-^~_~^~-~_~-^~_^/    \\~^-~^~_~^-~_^~-^~_^~~-^~_~^~-~_~-^~_^/ ~^~ - _ ^ - ~~~ _ - _ ~-^ ~ __- ~~   ";i++;
gotoxy(z,i);cout << "~~^-~^_~^~/  \\~^-~^~_~^-~_^~-^~_^~~-^~_~^~-~_~-^~_^/     ~ ~- ^~ -  ~^ -  ~ ^~ - ~~  ^~ - ~\\~^-~^~_~^-~\\~^-~^~_~^-~ -~_-~~^- _~~_~-^";i++;

}

int a=56,b=23,stopSlash=0;
void Slash(){
    //z=56
while(true){

    for(int i = 0; i < 5; i++){
    gotoxy(a,b); cout << "\\ " ;
    gotoxy(a+1,b+1); cout << "} " ;
    gotoxy(a,b+2); cout << "/ " ;

        Sleep(500);
    gotoxy(a,b); cout << "   " ;
    gotoxy(a+1,b+1); cout << "  " ;
    gotoxy(a,b+2); cout << "  " ;

        a+=6;
        b = 23;
    }
    a=56;b=23;

    stopSlash++;
    if(stopSlash==4){
        break;}
    
    HealthBar(dmg);
}


}

void Helbert1(){

int z=37,i=17+1+6;
cout << GREEN;
gotoxy(z,i);cout << "    ---==|- ";i++;
gotoxy(z,i);cout << "      \\o-\\";i++;
gotoxy(z,i);cout << "       |v(  ";i++;
gotoxy(z,i);cout << "      /\\/  ";i++;
cout << RESET;

}


void Helbert(){ 
int z=37;int i=17+1+6;
cout << GREEN;
gotoxy(z,i);cout << "   .|.   o  /\\   ";i++;
gotoxy(z,i);cout << "   -|- / | `)o    ";i++;
gotoxy(z,i);cout << "        / \\ \\/  ";i++;


cout << RESET;

}

int Monster(int N){
int z=67;int i=9+6+1;
N = N - 47;

while(N > 0){
    barStatus();
    Dataran();
    Helbert(); // memisahkan helbert 
    Helbert1();
    cout << RED;
gotoxy(z,i);cout << "_        __                    ";i++;
gotoxy(z,i);cout << "       o)/)_    /  \\_         ";i++;
gotoxy(z,i);cout << "   o^^^  _  \\  /     \\       ";i++;
gotoxy(z,i);cout << "   'v!!!' !  \\/   !   \\      ";i++;
gotoxy(z,i);cout << "       ___/ ) ' _/  !  !       ";i++;
gotoxy(z,i);cout << "      (/^==/    /!_ /. !       ";i++;
gotoxy(z,i);cout << "           !__  \\  !/ /       ";i++;
gotoxy(z,i);cout << "           /     \\  !/     .  ";i++;
gotoxy(z,i);cout << "          ( /_    \\_      _/) ";i++;
gotoxy(z,i);cout << "         _)\\ ^-_  ^^--^^ /    ";i++;
gotoxy(z,i);cout << "        'v--^    ^^-----^^     ";i++;

    int x=66,y=12+1+6;int p=0;
    for(int j=1;j<=4;i++){
    // x=38,y=21,
    gotoxy(x,y);cout << " O ";
    Sleep(300);
    gotoxy(x,y);cout << "   ";
    x-=3;
    y++;
    Sleep(300);
    if(y==21+4)
    {
        break;
    }
    p++;
}   health-=91;
    stamina-=10;
    experience+=187;
    if(health<=0){ // jika health kurang dari atau sama dengan 0, maka akan Game Over.
        break;
    }
    if(p==1){
        int x=66,y=12+6+1;
    }

N--;
if(N<=1){break;};
z=67,i=9+1+6;

};
barStatus();
cout << RESET;

return N;
}

void HelpShop(){
    int z=1;int i=16;
gotoxy(z,i);cout << "   _____________________";i++;
gotoxy(z,i);cout << " / \\                    \\.";i++;
gotoxy(z,i);cout << "|   |'1' Armor (500g)   |.";i++;
gotoxy(z,i);cout << " \\_ |                   |.";i++;
gotoxy(z,i);cout << "    |'2' Sword (430g)   |.";i++;
gotoxy(z,i);cout << "    |                   |.";i++;
gotoxy(z,i);cout << "    |'3' HP POT (200g)  |.";i++;
gotoxy(z,i);cout << "    |                   |.";i++;
gotoxy(z,i);cout << "    |'4' Energy (100g)  |.";i++;
gotoxy(z,i);cout << "    |                   |.";i++;
gotoxy(z,i);cout << "    |'9' Exit           |.";i++;
gotoxy(z,i);cout << "    |   ________________|___";i++;
gotoxy(z,i);cout << "    |  /                   /";i++;
gotoxy(z,i);cout << "    \\_/___________________/.";i++;
}

void Shop(){
    ShopStatus();
int z = 39;int i = 2;
cout << GREEN;
gotoxy(z,i);cout << "{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}";i++;
gotoxy(z,i);cout << "{}                                                                                          {}";i++;
gotoxy(z,i);cout << "{}                                 ____  _   _  ___  ____                                   {}";i++;
gotoxy(z,i);cout << "{}                                / ___|| | | |/ _ \\|  _ \\                                  {}";i++;
gotoxy(z,i);cout << "{}                                \\___ \\| |_| | | | | |_) |                                 {}";i++;
gotoxy(z,i);cout << "{}                                 ___) |  _  | |_| |  __/                                  {}";i++;
gotoxy(z,i);cout << "{}                                |____/|_| |_|\\___/|_|                                     {}";i++;
gotoxy(z,i);cout << "{}                                                                                          {}";i++;
gotoxy(z,i);cout << "{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}";i++;
gotoxy(z,i);cout << "{}                                                                                          {}";i++;
gotoxy(z,i);cout << "{}         __   __                    __                                                    {}";i++;
gotoxy(z,i);cout << "{}   1.   /  `-'  \\           2.     _||_            3.                  4.      .-.        {}";i++;
gotoxy(z,i);cout << "{}       /_|     |_\\                ( || )                   |~|                .' `.       {}";i++;
gotoxy(z,i);cout << "{}         |     |                    ||                     | |                |   |       {}";i++;
gotoxy(z,i);cout << "{}         |     |                    ||                   .'   `.              |   |       {}";i++;
gotoxy(z,i);cout << "{}         |_____|                    \\/                   '.___.'              `...'       {}";i++;
gotoxy(z,i);cout << "{}                                                                                          {}";i++;
gotoxy(z,i);cout << "{}         "<< BLUE << "-ARMOR-" << "                 " WHITE << "-SWORD 1-" << "             " RED << " -HP POT-" << "        " YELLOW << "  -ENERGY POT-" << GREEN << "    {}" ;i++;
gotoxy(z,i);cout << "{}                                                                                          {}";i++;
gotoxy(z,i);cout << "{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}";i++;
cout << RESET;
}


void HowToPlay(){ // login menu
int i =0;int z=37;
system("cls");
cout << GREEN;
gotoxy(z,i);cout<< "   _________________________________________________________________";i++;
gotoxy(z,i);cout<< " / \\                    BAGAIMANA CARA BERMAIN ?                    \\.";i++;
gotoxy(z,i);cout<< "|   |                                                               |.";i++;
gotoxy(z,i);cout<< " \\_ |  Memulai Permainan:                                           |.";i++;
gotoxy(z,i);cout<< "    |  Saat memulai, Anda akan diminta untuk memilih senjata untuk  |.";i++;
gotoxy(z,i);cout<< "    |  karakter Anda.                                               |.";i++;
gotoxy(z,i);cout<< "    |                                                               |.";i++;
gotoxy(z,i);cout<< "    |  Mode Train:                                                  |.";i++;
gotoxy(z,i);cout<< "    |  Dalam mode ini, Anda akan melawan dummy.                     |.";i++;
gotoxy(z,i);cout<< "    |  Setiap kali Anda menyerang dummy, Anda akan mendapatkan 20   |.";i++;
gotoxy(z,i);cout<< "    |  emas.                                                        |.";i++;
gotoxy(z,i);cout<< "    |                                                               |.";i++;
gotoxy(z,i);cout<< "    |  Mode explore :                                               |.";i++;
gotoxy(z,i);cout<< "    |  Pemain akan berjalan dan mengeksplor area sekitar.           |.";i++;
gotoxy(z,i);cout<< "    |  Selama eksplorasi, pemain dapat bertemu dengan monster kecil |.";i++;
gotoxy(z,i);cout<< "    |  atau mendapatkan quest mendadak (sudden quest).              |.";i++;
gotoxy(z,i);cout<< "    |                                                               |.";i++;
gotoxy(z,i);cout<< "    |  Bertarung dengan monster:                                    |.";i++;
gotoxy(z,i);cout<< "    |  Dalam mode explore, Anda akan bertemu dengan monster. Defeat |.";i++;
gotoxy(z,i);cout<< "    |  mereka untuk mendapatkan emas dan hadiah lainnya.            |.";i++;
gotoxy(z,i);cout<< "    |  Ingat, monster dapat menyerang dan mengurangi hp karakter    |.";i++;
gotoxy(z,i);cout<< "    |  anda.                                                        |.";i++;
gotoxy(z,i);cout<< "    |                                                               |.";i++;
gotoxy(z,i);cout<< "    |  Membeli senjata baru :                                       |.";i++;
gotoxy(z,i);cout<< "    |  Anda dapat menggunakan emas yang telah dikumpulkan untuk     |.";i++;
gotoxy(z,i);cout<< "    |  membeli senjata yang lebih baik. Senjata yang lebih baik akan|.";i++;
gotoxy(z,i);cout<< "    |  meningkatkan kemampuan karakter Anda dalam pertarungan.      |.";i++;
gotoxy(z,i);cout<< "    |                                                               |.";i++;
gotoxy(z,i);cout<< "    |  HP karakter :                                                |.";i++;
gotoxy(z,i);cout<< "    |  Karakter Anda memiliki sejumlah HP. Jika HP ini              |.";i++;
gotoxy(z,i);cout<< "    |  habis karena serangan monster, permainan akan berakhir.      |.";i++;
gotoxy(z,i);cout<< "    |                                                               |.";i++;
gotoxy(z,i);cout<< "    |  Akhiri permainan :                                           |.";i++;
gotoxy(z,i);cout<< "    |  permainan akan berakhir saat karakter anda mati.             |.";i++;
gotoxy(z,i);cout<< "    |   ____________________________________________________________|___";i++;
gotoxy(z,i);cout<< "    |  /                                                               /.";i++;
gotoxy(z,i);cout<< "    \\_/_______________________________________________________________/.";i++;
cout << RESET;
cout << endl; system("pause");

}
// Main Menu
void mainMenu(){
    system("cls");
             cout << endl;// The Adventure Of Halbert
gotoxy(31,4);cout << "*************************************************************************         ";
gotoxy(31,5);cout << "*  _____ _               _       _                 _                    *         ";
gotoxy(31,6);cout << "* |_   _| |__   ___     / \\   __| |_   _____ _ __ | |_ _   _ _ __ ___   *        ";
gotoxy(31,7);cout << "*   | | | '_ \\ / _ \\   / _ \\ / _` \\ \\ / / _ \\ '_ \\| __| | | | '__/ _ \\  * ";
gotoxy(31,8);cout << "*   | | | | | |  __/  / ___ \\ (_| |\\ V /  __/ | | | |_| |_| | | |  __/  *       ";
gotoxy(31,9);cout << "*   |_| |_| |_|\\___| /_/   \\_\\__,_| \\_/ \\___|_| |_|\\__|\\__,_|_|  \\___|  * ";
gotoxy(31,10);cout << "*                                                                       *        ";
gotoxy(31,11);cout << "*                    __   _   _       _ _               _               *        ";
gotoxy(31,12);cout << "*              ___  / _| | | | | __ _| | |__   ___ _ __| |_             *        ";
gotoxy(31,13);cout << "*             / _ \\| |_  | |_| |/ _` | | '_ \\ / _ \\ '__| __|            *     ";
gotoxy(31,14);cout << "*            | (_) |  _| |  _  | (_| | | |_) |  __/ |  | |_             *        ";
gotoxy(31,15);cout << "*             \\___/|_|   |_| |_|\\__,_|_|_.__/ \\___|_|   \\__|            *    "; 
gotoxy(31,16);cout << "*                                                                       *        ";
gotoxy(31,17);cout << "*************************************************************************        ";
gotoxy(31,18);cout << "Selamat datang, " << username;
gotoxy(31,19);cout << "1. Login";
gotoxy(31,20);cout << "2. Register";
gotoxy(31,21);cout << "3. How To Play";
//gotoxy(31,22);cout << "4. Exit";
gotoxy(31,24);cout << " your choise : ";
    cin >> option;

    switch(option){
        case '1' :
            login();
            break;
        case '2' :
            Register();
            break;
        //case '4' : 
        //    Exit=true;
        //    break;
        case '3':
            HowToPlay();
        default:
            mainMenu();
    }
}

// Loading for Main Menu
void Loading(){
    char x = 219;
    for(int i=0;i<=27;i++){
        Sleep(90);
        cout << x;
    }
    system("cls");
    HowToPlay();
    // system("pause"); == press any key to continue
    mainMenu();
}

//Take your user name 
void opening(){
//  cout << " Selamat datang di game advanture !\n\n ";
    cout << " Insert your name : ";
    getline(cin,username);
    //HealthBar();
    Loading();
}
//////////////////////////////////////////////////////////////////////////////////////
int main(){

    //system("color 02");
    opening();

    if(Exit){
     return 0;
    }

    //while true
    bool Move = true;
    while(Move){
        if(health<=0){Move=false;system("cls");cout << RED << "G A M E  O V E R ~ ";break;}
    //system("cls");
    barStatus();
    cout << "\n\nHello ! Good Morning, " << username << endl;
    cout << "What would like you in this morning ?" << endl;
    cout << "1. Train" << endl; //sword level == train ==weapon
    cout << "2. Explore" << endl;
    cout << "3. Shop" << endl;
    cout << "9. Exit" << endl;
    cout << "  your choise : ";
    cin >> todo;

    if(todo == "1" || todo == "2" || todo == "3" || todo == "9")
    {
    system("cls");
    if(todo == "1")
        {
            Temple(warna = false);
            cout << endl << "Your current gold : " << gold;
            cout << endl << "Your current sword level : " << SwordLevel << endl;
            if(SwordLevel>=7){muncul=true;cout << RED <<"You Need To Buy New Sword in Shop ! \n\n" << RESET;}else{muncul=false;};
            cout << "Would you like to upgrade your (y/n) :";
            // health /potion, defense, pedang
            // switch(){ // equipment
            //     case '1':
            //         //goto health;
            //         break;
            //     case '2':
            //         //goto defense
            //         break;
            //     case '3';
            //         //goto sword
            //         break;
            // }
            cin >> up; // items ada 

            if (up == 'y') {
            // system("cls");
            // barStatus();
            cout << endl << "Your current gold : " << gold;
            cout << endl << "Your current sword : " << SwordLevel << endl;
            cout << "to upgrade u need : "<< SwordCost1 << endl;
            cout << "Upgrade sword (y/n) : ";
            cin >> sword;

                if (gold >= SwordCost1 && sword == 'y'){
                    if(SwordLevel>=7){
                        system("cls");
                        SwordLevel-=1;
                        gold=gold+50+SwordCost1;
                    }
                    else if(SwordLevel<7){
                        SwordLevel += 1;
                        gold = gold - SwordCost1;
                        SwordCost1 += 60;
                    }
                }

                else if(gold < SwordCost1 && sword == 'y'){
                    system("cls");
                    cout << "\033[31m Your gold is not Enough !\033[0m";
                }
                else if (sword == 'n'){
                    system("cls");
                    //break;
                }
                else{
                    //break;
                }
                //cout << endl << "Current gold        : " << gold << " " << "\nCurrent Sword Level : " << SwordLevel << endl; 
            }
            else if (up == 'n') {
                system("cls");
                //break;
            } 
        if(up == 'y'){
        global();
        system("cls");
        Temple(warna = true);
        cout << endl << "Current gold        : " << gold << " " << "\nCurrent Sword Level : " << SwordLevel << endl; 
        system("pause");
        system("cls");  
        }
        }


    //game:
    else if(todo == "2")
        {
//            Helbert();
//            Monster();
            cout << "\nExplore (max 8 hours)\n";
            cout << "Mau Explore berapa lama ? : ";
            cin >> timeExplore; // cin tipe data char, jika bertemu dengan value aneh, akan di konversi menggunakan kode ascii

            if(timeExplore <= 0){
                timeExplore = (int)(timeExplore);
                timeExplore-=100000;
            }
            N = timeExplore;

            if (timeExplore <= 56 && timeExplore >= 49) {   // Stamina
                int earn =0;earn=earn+(20*(int)(timeExplore-48)); // buat nampilihn hasil gold yang diperoleh

        Monster(N);
        //HealthBar();
        //global();
        Slash();
     
                gold = gold + (20*(int)(timeExplore-48)); // ((int)(timeExplore)) => mengubah nilai 'char' menjadi kode ascii type data int
                cout << endl;
                cout << "Congratulation ! You have earned " << earn << " gold ! " << endl << endl;
                system("pause");
                //goto weapon;
                //break;//goto in_game;
            }
            else if(timeExplore < -99999){
                //break;
            }
            else if(timeExplore > 56 && timeExplore < 49){
                system("cls");
                cout << "Invalid Value !";
                //break;//goto game;
            }
            else {
                system("cls");
                //break;//goto game;
            }


        system("cls");
        }
        
    else if(todo == "3"){
        Move = false;
        //shop:
        while(!Move)
        {
        Shop();HelpShop();ShopDesc();
        gotoxy(48,23);cout << " Welcome to Adventure Shop !";
        gotoxy(46,25);cout << "What item would you like to buy ? ";
        gotoxy(48,26);cout << "                                   ";
        gotoxy(46,26);cout << "your answer : ";cin >> belanja;
        switch(belanja){
            case '1': // armor 350
                if(defense==100 && gold >= 350){system("cls");gotoxy(48,29);cout<< YELLOW <<"Your Armor is Already Complete !"<< RESET;}
                else if(defense <= 99 &&defense>=80 && gold >=350 ){system("cls");success();defense=100;gold-=350;}
                else if(gold>=350 && defense<80){success();gold-=350;defense+=20;}
                else if(gold < 350){system("cls");gotoxy(48,29);cout<< RED <<"Your Gold is Not Enough !"<< RESET;}
                break;
            case '2': // sword 460
                if(SwordLevel>=7 && gold >= 430){system("cls");success();gotoxy(48,29);SwordLevel+=1;gold-=430;cout<< YELLOW <<"Upgrade Sword Complete !"<< RESET;}
                else if(SwordLevel < 7 && gold >=430 ){system("cls");gotoxy(48,29);cout << RED << "Your Sword Level is To Low ! (required level 7)" << RESET;}
                else if(gold < 430){system("cls");gotoxy(48,29);cout<< RED <<"Your Gold is Not Enough !"<< RESET;}
                break;
            case '3': // hp pot 200
                if(health==1000 && gold >= 200){system("cls");gotoxy(48,29);cout<< YELLOW <<"Your HP is Already Full !"<< RESET;}
                else if(health <= 999 &&health>=650 && gold >=200 ){system("cls");success();health=1000;gold-=200;}
                else if(gold>=200 && health<650){success();gold-=200;health+=35;}
                else if(gold < 200){system("cls");gotoxy(48,29);cout<< RED <<"Your Gold is Not Enough !"<< RESET;}
                break;
            case '4': // energypot
                if(stamina==100 && gold >=100){system("cls");gotoxy(48,29);cout<< YELLOW <<"Your Stamina is Already Full !"<< RESET;}
                else if(stamina <= 99 && stamina>=75 && gold >=100){system("cls");success();stamina=100;gold-=100;}
                else if(stamina < 75 && gold >= 100){success();gold-=100;stamina+=25;}
                else if(gold < 100){system("cls");gotoxy(48,29);cout<< RED <<"Your Gold is Not Enough !"<< RESET;}
                break;
            case '9': // back to in game
                system("cls");
                Move = true;
                //goto in_game;
                break;
            default:
                //goto shop;
                break;
        }
        //system("cls");
        //break; // back to main menu.
        //goto shop;
        }
    }

    else if(todo == "9"){
        Move = false;
    }
    
    }
    else{
        todo.clear();
        system("cls");}//goto in_game;}
    }// punya while

return 0;
}
