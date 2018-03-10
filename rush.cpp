#include <bits/stdc++.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#define  rd (rand())%99+1
#define  V 12

using namespace std;
int l[25][3],ans[V],user[V],top,graph[V][V],status[25],bstts[V],curr,topu;

void xy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void tc(unsigned short color) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

int minDistance(int dist[], bool sptSet[])
{
   int mini = INT_MAX, min_index;

   for (int u = 0; u < V; u++)
    if (sptSet[u] == false && dist[u] <= mini)
         mini = dist[u], min_index = u;

   return min_index;
}

void dijkstra(int src,int dest)
{
     int dist[V];
     int prev[V];
     bool sptSet[V];

     for (int i = 0; i < V; i++) dist[i] = INT_MAX, sptSet[i] = false,prev[i]=-1;

     dist[src] = 0;

     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);

       if(u==dest) break;

       sptSet[u] = true;

       for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v],prev[v]=u;
     }

     int u=dest;
     while(prev[u]!=-1)
     {
         cout<<u<<endl;
         ans[top++]=u;
         u=prev[u];
     }
     ans[top]=u;
}

void box(int x, int y,int val)
{
    xy(x,y);   printf("%c%c%c%c",218,196,196,191);
    xy(x,y+1); printf("%c%d",179,val); xy(x+3,y+1); printf("%c",179);
    xy(x,y+2); printf("%c%c%c%c\n",192,196,196,217);

}

void streets()
{
    int u=8;
    tc(14); box(10,5,1); tc(bstts[1]); box(25,5,2); tc(bstts[2]); box(40,5,3); tc(bstts[3]); box(55,5,4);
    tc(bstts[4]); box(10,13,5); tc(bstts[5]); box(25,13,6); tc(bstts[6]); box(40,13,7); tc(bstts[7]); box(55,13,8);
    tc(bstts[8]); box(10,21,9); tc(bstts[9]); box(25,21,10); tc(bstts[10]); box(40,21,11); tc(12); box(55,21,12);

    tc(status[0]); xy(7,6); printf("%c%c%c",218,196,196); //1
    xy(7,22); printf("%c%c%c",192,196,196);
    for(int i=7; i<=21; i++) xy(7,i),printf("%c",179);
    xy(5,14); cout<<l[0][2]; tc(u);

    tc(status[1]); for(int i=9; i<=19; i++) xy(i+5,6),printf("%c",196); xy(21,5); cout<<l[1][2]; tc(u);//2
    tc(status[2]); for(int i=9; i<=19; i++) xy(i+5,14),printf("%c",196); xy(21,13); cout<<l[2][2];tc(u);//3
    tc(status[3]); for(int i=9; i<=19; i++) xy(i+5,22),printf("%c",196); xy(21,21); cout<<l[3][2];tc(u);//4

    tc(status[4]); for(int i=24; i<=34; i++) xy(i+5,6),printf("%c",196); xy(34,5); cout<<l[4][2];tc(u); //5
    tc(status[5]); for(int i=24; i<=34; i++) xy(i+5,14),printf("%c",196); xy(34,13); cout<<l[5][2];tc(u); //6
    tc(status[6]); for(int i=24; i<=34; i++) xy(i+5,22),printf("%c",196); xy(34,21); cout<<l[6][2];tc(u); //7

    tc(status[7]); for(int i=39; i<=49; i++) xy(i+5,6),printf("%c",196); xy(51,5); cout<<l[7][2];tc(u); //8
    tc(status[8]); for(int i=39; i<=49; i++) xy(i+5,14),printf("%c",196); xy(51,13); cout<<l[8][2];tc(u); //9
    tc(status[9]); for(int i=39; i<=49; i++) xy(i+5,22),printf("%c",196); xy(51,21); cout<<l[9][2];tc(u); //10

    tc(status[10]); for(int i=8; i<=12; i++) xy(11,i),printf("%c",179); xy(12,12); cout<<l[10][2]; tc(u);//11
    tc(status[11]); for(int i=16; i<=20; i++) xy(11,i),printf("%c",179); xy(12,20); cout<<l[11][2]; tc(u);//12

    tc(status[12]); for(int i=8; i<=12; i++) xy(27,i),printf("%c",179); xy(28,12); cout<<l[12][2]; tc(u);//13
    tc(status[13]); for(int i=16; i<=20; i++) xy(27,i),printf("%c",179); xy(28,20); cout<<l[13][2]; tc(u);//14

    tc(status[14]); for(int i=8; i<=12; i++) xy(41,i),printf("%c",179); xy(42,12); cout<<l[14][2]; tc(u);//15
    tc(status[15]); for(int i=16; i<=20; i++) xy(41,i),printf("%c",179); xy(42,20); cout<<l[15][2]; tc(u);//16

    tc(status[16]); for(int i=8; i<=12; i++) xy(57,i),printf("%c",179); xy(58,12); cout<<l[16][2]; tc(u);//17
    tc(status[17]); for(int i=16; i<=20; i++) xy(57,i),printf("%c",179); xy(58,20); cout<<l[17][2]; tc(u);//18

    tc(status[18]); for(int i=8; i<=10; i++) xy(12,i),printf("%c",179);//19
    for(int i=10; i<=12; i++) xy(26,i),printf("%c",179);
    for(int i=8; i<=20; i++) xy(i+5,10),printf("%c",196);
    xy(16,9); cout<<l[18][2];
    xy(12,10); printf("%c",192); xy(26,10); printf("%c",191); tc(u);

    tc(status[19]); for(int i=8; i<=10; i++) xy(12,i+8),printf("%c",179); //20
    for(int i=10; i<=12; i++) xy(26,i+8),printf("%c",179);
    for(int i=8; i<=20; i++) xy(i+5,10+8),printf("%c",196);
    xy(16,17); cout<<l[19][2];
    xy(12,10+8); printf("%c",192); xy(26,10+8); printf("%c",191); tc(u);

    tc(status[20]); for(int i=8; i<=10; i++) xy(12+30,i),printf("%c",179); //21
    for(int i=10; i<=12; i++) xy(26+30,i),printf("%c",179);
    for(int i=8; i<=20; i++) xy(i+5+30,10),printf("%c",196);
    xy(46,9); cout<<l[20][2];
    xy(12+30,10); printf("%c",192); xy(26+30,10); printf("%c",191); tc(u);

    tc(status[21]); for(int i=8; i<=10; i++) xy(12+30,i+8),printf("%c",179); //22
    for(int i=10; i<=12; i++) xy(26+30,i+8),printf("%c",179);
    for(int i=8; i<=20; i++) xy(i+5+30,10+8),printf("%c",196);
    xy(46,17); cout<<l[21][2];
    xy(12+30,10+8); printf("%c",192); xy(26+30,10+8); printf("%c",191); tc(u);

    tc(status[22]);
    xy(11,3); printf("%c",218); xy(11,4); printf("%c",179);  //23
    xy(56,3); printf("%c",191); xy(56,4); printf("%c",179);
    for(int i=12; i<=55; i++) xy(i,3),printf("%c",196);
    xy(34,2); cout<<l[22][2]; tc(u);

    tc(status[23]);
    xy(11,25); printf("%c",192); xy(11,24); printf("%c",179);  //24
    xy(41,25); printf("%c",217); xy(41,24); printf("%c",179);
    for(int i=12; i<=40; i++) xy(i,25),printf("%c",196);
    xy(26,24); cout<<l[23][2]; tc(u);

    tc(status[24]); xy(42,25); printf("%c",192); xy(42,24); printf("%c",179);  //25
    xy(59,14); printf("%c",196); xy(60,14); printf("%c",191);
    xy(60,25); printf("%c",217);
    for(int i=43; i<=59; i++) xy(i,25),printf("%c",196);
    for(int i=15; i<=24; i++) xy(60,i),printf("%c",179);
    xy(48,24); cout<<l[24][2]; tc(u);

    tc(11); box(5,26,00); xy(9,27); tc(7); cout<<"=Town";
    tc(14); box(16,26,00); xy(20,27); tc(7); cout<<"=source";
    tc(12); box(29,26,00); xy(33,27); tc(7); cout<<"=destination";
    tc(u);xy(47,27); printf("%c%c%c%c%c",196,196,196,196,196); tc(7); cout<<" =street";
    tc(7);xy(66,1); printf(" '-1' to exit");

}
void correction()
{
    dijkstra(0,11);
    for(int i=0; i<25; i++)
        for(int j=top; j>0; j--)
        {
            if((l[i][0]==ans[j]&&l[i][1]==ans[j-1])||(l[i][1]==ans[j]&&l[i][0]==ans[j-1]))
               status[i]=10;
        }
    system("cls");
    streets();
}

void user_data()
{
    int value,flag=1,check;
    do{
        do{
        check=0;
        xy(73,6); cout<<"  ";
        xy(62,5); cout<<"Enter next";
        xy(62,6); cout<<"town(1-12):";
        xy(73,6); cin>>value;
        if(value==-1) system("cls"),exit(100);
        if(value>=1&&value<=12)
        for(int i=0; i<topu&&topu>0; i++) if(user[i]==(value-1)) check=1;
      }while(graph[curr][value-1]==0||value<2||value>12||check||value==curr+1);
    value--;
    for(int i=0; i<25; i++)
        if((l[i][0]==curr&&l[i][1]==value)||(l[i][1]==curr&&l[i][0]==value))
           status[i]=9;
    for(int i=0; i<V; i++) bstts[i]=11; bstts[value]=10;
    system("cls"); streets(); user[topu++]=curr; curr=value;
    }while(curr!=11);
    user[topu]=curr;
    if(top==topu)
    for(int i=0; i<=topu; i++) {  if(user[i]!=ans[top-i]) { flag=0; break;} }
    else flag=0;
    if(flag==0)
    {
    for(int i=0; i<25; i++)
        for(int j=topu; j>0; j--)
        {
            if((l[i][0]==user[j]&&l[i][1]==user[j-1])||(l[i][1]==user[j]&&l[i][0]==user[j-1]))
               status[i]=12;
        }
    }
    getch();
    system("cls");
}

void maingame()
{
    curr=top=topu=0;
    system("cls");
    xy(6,10); tc(4); cout<<"-------------------------- RUSH-HOUR ------------------------------";
    xy(6,11); tc(2); cout<<"     Jackie has to reach his destination as soon as possible.      ";
    xy(6,12); tc(3); cout<<"Help him reach by finding shortest path from source to destination.";
    getch(); system("cls");
    for(int i=0; i<25; i++) status[i]=8;
    srand(time(NULL));
    l[0][0]=0; l[0][1]=8;  l[1][0]=0; l[1][1]=1; l[2][0]=4; l[2][1]=5;
    l[3][0]=8; l[3][1]=9;  l[4][0]=1; l[4][1]=2; l[5][0]=5; l[5][1]=6;
    l[6][0]=9; l[6][1]=10; l[7][0]=2; l[7][1]=3; l[8][0]=6; l[8][1]=7;
    l[9][0]=10; l[9][1]=11; l[10][0]=0; l[10][1]=4; l[11][0]=4; l[11][1]=8;
    l[12][0]=1; l[12][1]=5; l[13][0]=5; l[13][1]=9; l[14][0]=2; l[14][1]=6;
    l[15][0]=6; l[15][1]=10; l[16][0]=3; l[16][1]=7; l[17][0]=7; l[17][1]=11;
    l[18][0]=0; l[18][1]=5; l[19][0]=4; l[19][1]=9; l[20][0]=2; l[20][1]=7;
    l[21][0]=6; l[21][1]=11; l[22][0]=0; l[22][1]=3; l[23][0]=8; l[23][1]=10;
    l[24][0]=7; l[24][1]=10;

    for(int i=0; i<V; i++) for(int j=0; j<V; j++) graph[i][j]=0;
    for(int i=0; i<V; i++) bstts[i]=11;
    for(int i=0; i<25; i++)
        l[i][2]=rd,graph[l[i][0]][l[i][1]]=graph[l[i][1]][l[i][0]]=l[i][2];

    streets(); user_data(); correction(); getch(); system("cls");
    xy(30,1); tc(2); cout<<"THANK-YOU";
    xy(32,2);   tc(3); cout<<" FOR ";
    xy(31,3);  tc(4); cout<<"PLAYING!\n";
    getch();
    maingame();
}

int main()
{
    maingame();
    return 0;
}
