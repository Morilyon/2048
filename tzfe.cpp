#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "tzfe.h"
using namespace std;
//return 2 and 4
int rando(){
    int tmp = rand() % 4 + 1;
    return (tmp == 2 || tmp == 4)? tmp: 2;
}

//return 1 and 16
int randx(){
    return rand() % 16;
 }

Tzfe::Tzfe(){
    int t = 0;
    for(int x = 0; x < 4; x++){
        for(int y = 0; y < 4; y++){
            if(x == randx() / 4 && t < 2){
                value[x][y] = rando();
                t++;                            
            }
            else
                value[x][y] = 0; 
        }
    }
}

void 
Tzfe::print() const {
    for(int x = 0; x < 4; x++){
        for(int y = 0; y < 4; y++){
            cout << value[x][y] << "\t";
        }
        cout << "\n\n"<<endl;
    }
}    

int 
Tzfe::control(){
    char ch;
    ch = getch();
    switch(ch){
        case 'w':
            upper();
            break;
        case 's':
            under();
            break;
        case 'a':
            left();
            break;
        case 'd':
            right();
            break;
        default:break;
    }
    if(generate() != 0)
        return -1;
    system("cls");
    if(win() == 0)
        return 1;
    return 0;
}

void 
Tzfe::upper(){
    for(int i = 0; i < 4; i++){
        for(int x = 0; x < 4; x++){
            for(int y = 1; y < 4; y++){
                if(value[y - 1][x] == 0){
                    value[y - 1][x] = value[y][x];    
                    value[y][x] = 0;            
                }
            }
        }
    }       
    for(int i = 0; i < 4; i++){    
        for(int x = 1; x < 4; x++){
            if(value[x - 1][i] == value[x][i]){
                value[x - 1][i] += value[x][i];
                value[x][i] = 0;
            }
        }
    }
}
void
Tzfe::under(){
    for(int k = 0; k < 4; k++){
        for(int x = 0; x < 4; x++){
            for(int y = 3; y > 0; y--){
                if(value[y][x] == 0){
                    value[y][x] = value[y - 1][x];    
                    value[y - 1][x] = 0;            
                }
            }
        }
    }
    for(int i = 0; i < 4; i++){    
        for(int x = 3; x > 0; x--){
            if(value[x][i] == value[x - 1][i]){
                value[x][i] += value[x - 1][i];
                value[x - 1][i] = 0;
            }
        }
    }
}

void
Tzfe::left(){
    for(int i = 0; i < 4; i++){
        for(int x = 0; x < 4; x++){
            for(int y = 1; y < 4; y++){
                if(value[x][y - 1] == 0){
                    value[x][y - 1] = value[x][y];
                    value[x][y] = 0;
                }
            }
        }
    }
    for(int x = 0; x < 4; x++){
        for(int y = 1; y < 4; y++){
            if(value[x][y - 1] == value[x][y]){
                value[x][y - 1] += value[x][y];
                value[x][y] = 0;
            }
        }
    }
}

void
Tzfe::right(){
    for(int i = 0; i < 4; i++){
        for(int x = 0; x < 4; x++){
            for(int y = 3; y > 0; y--){
                if(value[x][y] == 0){
                    value[x][y] = value[x][y - 1];
                    value[x][y - 1] = 0;
                }
            }
        }
    }
    for(int x = 0; x < 4; x++){
        for(int y = 3; y > 0; y--){
            if(value[x][y] == value[x][y - 1]){
                value[x][y] += value[x][y - 1];
                value[x][y - 1] = 0;
            }
        }
    }
}

int
Tzfe::generate(){
    int pos = randx();
    if(value[pos/4][pos%4] == 0){
        value[pos/4][pos%4] = rando();
        return 0;
    }
    else
        generate();
}

int
Tzfe::win() const {
    for(int x = 0; x < 4; x++){
        for(int y = 0; y < 4; y++){
            if(value[x][y] == 2048)
                return 0;
        }
    }
    return -1;
}
