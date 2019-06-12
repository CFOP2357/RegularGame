#include<iostream>
#include<windows.h>
#include "Jugador.h"
#include "main.h"
using namespace std;

bool dead=0; //smn = 0;

char m[10][15][15] =
    {
        {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', 'o', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '#', '*', 'x', '*', '#', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '2', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}

        },
        {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '#', '#', '#', '*', '#', '#', '#', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '#', '*', '*', '*', '#', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '#', '*', '*', '*', '#', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '#', '#', '#', '*', '#', '#', '#', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '#', '*', '#', '*', '#', '*', '#', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '#', '#', '#', '*', '#', '#', '#', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}

        }
    };


int mundoActual=0;

int JugX=1, JugY=1;

/*int posicionActual(char c){
    char c1 = c;
    if(m[mundoActual][JugY][JugX]==c1){
        smn =1;
    }
    return smn;
}
*/
void showMap()
{
    system("cls");
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            cout<<m[mundoActual][i][j];
        }
        cout<<"\n";
    }
}

int muerte(){
    if(m[mundoActual][JugY][JugX]=='*'){
        dead=0;
    }

    else {
        if(superSaiyan() == 1) dead = 0;
        else dead = 1;
    }
    return dead;
}



void jugD()
{
    if(m[mundoActual][JugY+1][JugX]!='#')
    {
        m[mundoActual][JugY][JugX] = '*';
        JugY++;
        if(m[mundoActual][JugY][JugX]=='2')
        {
            //turno();
            mundoActual = 1;
            showMap();
            JugX = JugY = 1;
        }
        if (muerte() == 1) gameOver();
        m[mundoActual][JugY][JugX] = 'o';
    }

}
void jugU()
{
    if(m[mundoActual][JugY-1][JugX]!='#')
    {
        m[mundoActual][JugY][JugX] = '*';
        JugY--;
        if (muerte() == 1) gameOver();
        /*if(m[mundoActual][y][x]=='2')
        {
            turno();
            mundoActual = 1;
            x = y = 0;
        }*/
        m[mundoActual][JugY][JugX] = 'o';
    }

}
void jugR()
{
    if(m[mundoActual][JugY][JugX+1]!='#')
    {
        m[mundoActual][JugY][JugX] = '*';
        JugX++;
        if (muerte() == 1) gameOver();
        /*if(m[mundoActual][y][x]=='2')
        {
            turno();
            mundoActual = 1;
            x = y = 0;
        }*/
        m[mundoActual][JugY][JugX] = 'o';
    }

}
void jugL()
{
    if(m[mundoActual][JugY][JugX-1]!='#')
    {
        m[mundoActual][JugY][JugX] = '*';
        JugX--;
        if (muerte() == 1) gameOver();
        /*if(m[mundoActual][y][x]=='2')
        {
            turno();
            mundoActual = 1;
            x = y = 0;
        }*/
        m[mundoActual][JugY][JugX] = 'o';
    }

}

