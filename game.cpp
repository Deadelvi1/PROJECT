/*  ini pepek 
    NAMA KELOMPOK : NPM
    BUNGARAN NATANAEL SIAHAAN : 2317051048
    DEA DELVINATA             : 2317051027
    RIZKY KURNIA ANTASARI     : 2357051011
*/
#include <bits/stdc++.h> 
#include <string>
#include <chrono>
#include <thread>
#include <time.h>
#include <windows.h>
using namespace std;

//POSITIONING 
int X, Y;
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
    int SwordCost1 = 50;
    char timeExplore;//hours
    char up;
    char sword;
    char todo;
    bool kembali = false;

// Global Loading
void global(){
    char x = 219;
            for(int i=0;i<=29;i++){
            Sleep(90);
            cout << "\033[34m" << x << "\033[0m";}
}
// Global Loading

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
            kembali = false;
        }
    }
    else if (up == 'n') {
        system("cls");
        return;
    }
    cout << endl << "Current gold : " << gold << " " << "Current Sword Level : " << SwordLevel << endl;
    kembali = true;
}

void game(int gold) {
   
}

void in_game(){


}

// In - Game
void startgame(){
    system("cls");
    cout << "game started !";
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
gotoxy(31,21);cout << "3. Exit\n\n";
gotoxy(31,23);cout << " your choise : ";
    cin >> option;

    switch(option){
        case '1' :
            login();
            break;
        case '2' :
            Register();
        //  return;
            break;
        case '3' : 
            return;
            break;
        default:
            mainMenu();
    }
}

void Loading(){
    char x = 219;
    for(int i=0;i<=27;i++){
        Sleep(90);
        cout << x;
    }
    system("cls");
    //system("pause"); // press any key to continue
    mainMenu();
}

void opening(){
//  cout << " Selamat datang di game advanture !\n\n ";
    cout << " Insert your name : ";
    getline(cin,username);
    Loading();
}
//////////////////////////////////////////////////////////////////////////////////////
int main(){

    system("color 02");
    opening();

in_game:
    cout << "Hello ! Good Morning, " << username << endl;
    cout << "What would like you in this morning ?" << endl;
    cout << "1. Train" << endl; //sword level == train ==weapon
    cout << "2. Explore" << endl;
    cout << "3. Shop" << endl;
    cin >> todo;
    
    switch(todo){
        case '1':
            system("cls");
            todo = '\0';
            goto weapon;
            break;
        case '2':
            system("cls");
            goto game;
            todo = '\0';
            break;
        case '3':
            system("cls");
            cout <<"kasus 3";
            todo = '\0';
            //goto shop;
            break;
    }

game:
    cout << "\nExplore (max 8 hours)\n";
    cout << "Mau Explore berapa lama ? : ";
    cin >> timeExplore; // cin tipe data char, jika bertemu dengan value aneh, akan di konversi menggunakan kode ascii

    if (timeExplore <= 56 && timeExplore >= 49) { // Stamina
        gold = gold + (20*(int)(timeExplore-48)); // ((int)(timeExplore)) => mengubah nilai 'char' menjadi kode ascii type data int
        global();cout << endl;
        cout << "Congratulation ! You have earned " << gold << " gold ! " << endl << endl;
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

weapon:
    system("cls");
    cout << "Welcome to train !\n";
    cout << endl << "Your current gold : " << gold;
    cout << endl << "Your current sword : " << SwordLevel << endl;
    cout << "Would you like to upgrade your weapon (y/n) :";
    cin >> up;
    
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
        else if (sword == 'n') {
            system("cls");
            kembali = false;
        }
        else{
            goto weapon;
        }
    cout << endl << "Current gold : " << gold << " " << "Current Sword Level : " << SwordLevel << endl; 
    goto weapon;
    }
    else if (up == 'n') {
        system("cls");
        goto in_game;
    }goto weapon;


return 0;
}