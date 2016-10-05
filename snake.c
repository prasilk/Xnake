 #include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define row 30
#define col 50

char world[row][col];
int life[row][col];
char defc=' ';
char defp='X';
int i,j;
int curr=8;int curc=6;
int flength=5;

int refresh() {
    for (i=0;i<row;i++) {
            for (j=0;j<col;j++) {
                    world[i][j]=defc;
                    life[i][j]=-1;
            }
    }
    frog();
    return 1;
}

int print() {
    system("cls");
    world[curr][curc]=defp;
    life[curr][curc]=flength;

    for (i=0;i<row;i++) {
            for (j=0;j<col;j++) {
                    printf("%c",world[i][j]);
            }
            printf("\n");
    }
    update();
    return 1;
}

int frow,fcol;

int frog() {
    frow=rand()%30;
    fcol=rand()%50;

    world[frow][fcol]='O';
}

int frogcollision() {
    if ((curr==frow) && (curc==fcol)) {
            //collision
            flength++;
            return 2;
    }else {
        return 1;
    }
}//frogcollision

int deletesnake() {
    //check for positive values and delete
    for (i=0;i<row;i++) {
            for (j=0;j<col;j++) {
                if (life[i][j]>=0) {
                        life[i][j]=life[i][j]-1;
                            if (life[i][j]<0) {
                                    world[i][j]=defc;
                            }
                }
            }

    }
    return 1;
}//end function

int a;

int update() {
    char inp;
    inp=getch();

    if (inp) {
               deletesnake();
               a=frogcollision();
               if (a==2) {
                    frog();
               }
    }

    if (inp=='w') curr=curr-1;
    if (inp=='d') curc=curc+1;
    if (inp=='s') curr=curr+1;
    if (inp=='a') curc=curc-1;
    print();
}

int main() {
    refresh();
    update();
    return 1;
}

