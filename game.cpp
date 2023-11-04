/*  
    NAMA KELOMPOK : NPM
    BUNGARAN NATANAEL SIAHAAN : 2317051048
    DEA DELVINATA             : 2317051027
    RIZKY KURNIA ANTASARI     : 2357051011
*/

// INCLUDING LIBRARY
#include <bits/stdc++.h> 
#include <string>
#include <chrono>
#include <thread>
#include <time.h>
#include <windows.h>
#include <iomanip> // menepatkan bar agar tidak geser

// COLORING
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

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
    string user[10]={""};

    string pass[10]={""};string password;
    int pemberhentian=0;int i=0,j=0;

    char option;char jawaban;

    bool found = false;

// DEKLARASI IN-GAME
    int health = 100, gold, defense = 0, SwordLevel = 1;
    int SwordCost1 = 50;int experience=0; // pvp, monster,shop;
    char timeExplore;//hours
    char up;
    char sword;
    string todo;
    bool back = false; // untuk bolak baik ke main menu- how to play

// Global Loading
void global(){
    char x = 219;
            for(int i=0;i<=29;i++){
            Sleep(90);
            cout << "\033[34m" << x << "\033[0m";}
}
// Global Loading

void HealthBar(){
    for(int i=30;i>0;i--){
        char x=219; 
        if(i >= 22){
            gotoxy(13,13);
            for(int j=i;j>0;--j){cout << GREEN << x;}
        }else if(i >= 12 ){
            gotoxy(13,13);
            for(int j=i;j>0;--j){cout << YELLOW << x << RESET;}
        }else{
            gotoxy(13,13);
            for(int j=i;j>0;--j){cout << RED << x << RESET;}
        }
            for(int j=30-i;j>0;--j){cout << " ";}
        Sleep(200);    
    }
    // gotoxy nya belom di set.
}

void weapon(int gold) {
    cout << "Would you like to upgrade your weapon (y/n) :";
    cin >> up;

    if (up == 'y') {
        cout << endl << "Your current gold : " << gold;
        cout << endl << "Your current sword : " << SwordLevel << endl;
        cout << "Upgrade sword (y/n) : ";
        cin >> sword;

        if (gold >= SwordCost1 && sword == 'y') {
            SwordLevel += 1;
            gold = gold - SwordCost1;
            SwordCost1 += 60;
        }
        else if (up == 'n') {
            system("cls");
        }
    }
    else if (up == 'n') {
        system("cls");
        return;
    }
    cout << endl << "Current gold : " << gold << " " << "Current Sword Level : " << SwordLevel << endl;
}

void barStatus() {
    cout << "      _________________________________" << endl;
    cout << "     /      B A R     S T A T U S      \\" << endl;
    cout << "    /___________________________________\\" << endl;
    // Menggunakan setw untuk menetapkan lebar tetap
    cout << setw(5) << "   |" << "  Health      : " << setw(7) << health << "            |" << endl;
    cout << setw(5) << "   |" << "  Defense     : " << setw(7) << defense << "            |" << endl;
    cout << setw(5) << "   |" << "  Gold        : " << setw(7) << gold << "            |" << endl;
    cout << setw(5) << "   |" << "  experience  : " << setw(7) << experience << "            |" << endl;
    cout << "    \\__________________________________/" << endl;
    //HealthBar();
}

// In - Game
void startgame(){
    system("cls");
    //if(true){return;}//game(gold);
}

//Menu login with Boolean
void login(){
        cout << " \033[1m Menu Login \033[0m" << endl;
        cout << "enter user-id: ";
        cin >> name;
        cout << "enter password : ";
        cin >> password;
        cout << endl;
        for(int a=0;a<10;a++){
        if(name == user[a] && password == pass[a])
        {   
            global();
            startgame();
            found = true;
            break;
        }
        if(!found)
        {   
            system("cls");
            name.clear();password.clear();
            cout << "\033[31m"<< "Wrong Password or User-ID !" << "\033[0m"<< endl;
            login();
        }
        }
}

// Registration
void Register(){
    system("cls");
   while(true){

        if(pemberhentian == 1){
            break;
        }
        cout << "enter new user-id: ";
        cin >> user[i];
        i++;
        cout << "enter new password : ";
        cin >> pass[j];
        j++;
        cout << "Create Account (y/n) : ";
        cin >> jawaban;
        if(jawaban == 'y'){
        pemberhentian+=1;
         }else{
            i = i - i;
            j = j - j;
            system("cls");
         }
    }
    cout << endl << "Account has been created ! " << endl;
    global();
    system("cls");
    login();
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
gotoxy(z,i);cout<< "    |  Setiap kali Anda menyerang dummy, Anda akan mendapatkan 1    |.";i++;
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
gotoxy(z,i);cout<< "    |  hp karakter :                                                |.";i++;
gotoxy(z,i);cout<< "    |  Karakter Anda memiliki sejumlah hp. Jika hp ini              |.";i++;
gotoxy(z,i);cout<< "    |  habis karena serangan monster, permainan akan berakhir.      |.";i++;
gotoxy(z,i);cout<< "    |                                                               |.";i++;
gotoxy(z,i);cout<< "    |  Akhiri permainan :                                           |.";i++;
gotoxy(z,i);cout<< "    |  permainan akan berakhir saat karakter anda mati.             |.";i++;
gotoxy(z,i);cout<< "    |   ____________________________________________________________|___";i++;
gotoxy(z,i);cout<< "    |  /                                                               /.";i++;
gotoxy(z,i);cout<< "    \\_/_______________________________________________________________/.";i++;
cout << RESET;
cout << endl; system("pause");back=true;return;

}
// Main Menu
void mainMenu(){
    system("cls");
             cout << endl;// The Adventure Of Halbert
gotoxy(31,4);cout << "*************************************************************************" << endl;
gotoxy(31,5);cout << "*  _____ _               _       _                 _                    *" << endl;
gotoxy(31,6);cout << "* |_   _| |__   ___     / \\   __| |_   _____ _ __ | |_ _   _ _ __ ___   *" << endl;
gotoxy(31,7);cout << "*   | | | '_ \\ / _ \\   / _ \\ / _` \\ \\ / / _ \\ '_ \\| __| | | | '__/ _ \\  *" << endl;
gotoxy(31,8);cout << "*   | | | | | |  __/  / ___ \\ (_| |\\ V /  __/ | | | |_| |_| | | |  __/  *" << endl;
gotoxy(31,9);cout << "*   |_| |_| |_|\\___| /_/   \\_\\__,_| \\_/ \\___|_| |_|\\__|\\__,_|_|  \\___|  *" << endl;
gotoxy(31,10);cout << "*                                                                       *" << endl;
gotoxy(31,11);cout << "*                    __   _   _       _ _               _               *" << endl;
gotoxy(31,12);cout << "*              ___  / _| | | | | __ _| | |__   ___ _ __| |_             *" << endl;
gotoxy(31,13);cout << "*             / _ \\| |_  | |_| |/ _` | | '_ \\ / _ \\ '__| __|            *" << endl;
gotoxy(31,14);cout << "*            | (_) |  _| |  _  | (_| | | |_) |  __/ |  | |_             *" << endl;
gotoxy(31,15);cout << "*             \\___/|_|   |_| |_|\\__,_|_|_.__/ \\___|_|   \\__|            *" << endl; 
gotoxy(31,16);cout << "*                                                                       *" << endl;
gotoxy(31,17);cout << "*************************************************************************" << endl;
gotoxy(31,18);cout << "Selamat datang, " << username << " !\n\n";
gotoxy(31,19);cout << "1. Login\n";
gotoxy(31,20);cout << "2. Register\n";
gotoxy(31,21);cout << "3. How To Play\n";
gotoxy(31,22);cout << "4. Exit\n\n";
gotoxy(31,24);cout << " your choise : ";
    cin >> option;

    switch(option){
        case '1' :
            login();
            break;
        case '2' :
            Register();
        //  return;
            break;
        case '4' : 
            return;
            break;
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

    system("color 02");
    opening();

    // if(back){
    //     mainMenu();
    //     back=false;
    // }

in_game:
    barStatus();
    cout << "Hello ! Good Morning, " << username << endl;
    cout << "What would like you in this morning ?" << endl;
    cout << "1. Train" << endl; //sword level == train ==weapon
    cout << "2. Explore" << endl;
    cout << "3. Shop" << endl;
    cin >> todo;

    if(todo == "3" || todo == "2" || todo == "1"){
    if(todo == "3"){
        system("cls");
        cout <<"kasus 3";
        //goto shop;
        todo.clear();
    }else if(todo == "2"){
        system("cls");
        goto game;
        todo.clear();
    }else if(todo == "1"){
        system("cls");
        goto weapon;
        todo.clear();
    }
    }else{todo.clear();system("cls");goto in_game;}
game:
    cout << "\nExplore (max 8 hours)\n";
    cout << "Mau Explore berapa lama ? : ";
    cin >> timeExplore; // cin tipe data char, jika bertemu dengan value aneh, akan di konversi menggunakan kode ascii

    if (timeExplore <= 56 && timeExplore >= 49) { // Stamina
        gold = gold + (20*(int)(timeExplore-48)); // ((int)(timeExplore)) => mengubah nilai 'char' menjadi kode ascii type data int
        int earn =0;earn=earn+(20*(int)(timeExplore-48));  // buat nampilihn hasil gold yang diperoleh
        global();cout << endl;
        cout << "Congratulation ! You have earned " << earn << " gold ! " << endl << endl;
        //goto weapon;
        goto in_game;
    }
    else if(timeExplore > 56 && timeExplore < 49){
        system("cls");
        cout << "Invalid Value !";
        goto game;
    }
    else {
        system("cls");
        goto game;
    }

// if gold is not enough
invalid:
    system("cls");
    cout << "\033[31m Your gold is not Enough !\033[0m";
    goto weapon;

weapon:
    cout << endl << "Your current gold : " << gold;
    cout << endl << "Your current sword level : " << SwordLevel << endl;
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
        cout << endl << "Your current gold : " << gold;
        cout << endl << "Your current sword : " << SwordLevel << endl;
        cout << "to upgrade u need : "<< SwordCost1 << endl;
        cout << "Upgrade sword (y/n) : ";
        cin >> sword;

        if (gold >= SwordCost1 && sword == 'y') {
            SwordLevel += 1;
            gold = gold - SwordCost1;
            SwordCost1 += 60;
            goto weapon;
        }
        else if(gold <= SwordCost1 && sword == 'y'){
            goto invalid;
        }
        else if (sword == 'n') {
            system("cls");
            goto in_game;
        }
        else{
            goto in_game;
        }
    cout << endl << "Current gold : " << gold << " " << "Current Sword Level : " << SwordLevel << endl; 
    goto weapon;
    }
    else if (up == 'n') {
        system("cls");
        goto in_game;
    }
    goto in_game;

return 0;
}
