#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define CLS color(112),system("cls");
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////
struct Button{
    int x,y,color;
    const char *name;
    int len;
};
void GetPos(POINT &pt){
    HWND hwnd=GetForegroundWindow();
    GetCursorPos(&pt);
    ScreenToClient(hwnd,&pt);
    pt.y=pt.y/16;
    pt.x=pt.x/16;
}
void color(int a){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);}
void gto(int x,int y){
    COORD pos;
    pos.X=y*2;
    pos.Y=x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
Button NewButton(int x,int y,int color,const char *name){
    Button t;
    t.x=x;
    t.y=y;
    t.name=name;
    t.color=color;
    t.len=strlen(name);
    return t;
}
bool Preserve(Button A){
    gto(A.x,A.y),color(A.color),printf("%s",A.name);
    POINT pt;
    GetPos(pt);
    if(pt.y==A.x&&(pt.x>=A.y&&pt.x<=A.y+A.len/2)){
        color(A.color+16),gto(A.x,A.y),printf("%s",A.name);
        if(KEY_DOWN(MOUSE_MOVED)) return 1;
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////
int cc=1;
int Rcolor();
void pout(int x,int y,int c,string s);
int main(){
    int k;
    //////////////////////////// 
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible=false;
    SetConsoleCursorInfo(handle, &CursorInfo);
    /////////////////////
    Button Px[105][105];
    Button blue,red,yellow,white,green,black,end,save,read,cls;
    srand((unsigned)time(NULL));
    system("title Simple Drawing Board");
    system("mode con cols=74 lines=27");
    //system("color 70");
    for(int i=1;i<=20;i++){
        for(int j=1;j<=35;j++){
            Px[i][j]=NewButton(i,j,112,"  ");
        }
    }
    blue=NewButton(22,5,144,"Blue");
    red=NewButton(22,10,192,"Red");
    yellow=NewButton(22,15,224,"Yellow");
    green=NewButton(22,20,160,"Green");
    white=NewButton(22,25,112,"White");
    black=NewButton(22,30,1,"Black");
    cls=NewButton(24,5,112,"Clean All");
    end=NewButton(24,10,112,"EXIT");
    save=NewButton(24,15,112,"SAVE");
    read=NewButton(24,20,112,"READ");
    while(1){
        gto(21,1),color(cc),cout<<"                                                                      ";
        for(int i=1;i<=20;i++){
            for(int j=1;j<=35;j++){
                if(Preserve(Px[i][j])){
                    Px[i][j].color=cc;
                }   
            }
        }
        if(Preserve(blue))cc=144;
        if(Preserve(red))cc=192;
        if(Preserve(yellow))cc=224;
        if(Preserve(green))cc=160;
        if(Preserve(white))cc=112;
        if(Preserve(black))cc=1;
        if(Preserve(end))return 0;
        if(Preserve(save)){
            ofstream fout;
            fout.open("pic.txt");
            for(int i=1;i<=20;i++){
                for(int j=1;j<=35;j++){
                    fout<<Px[i][j].color<<" "; 
                }
                fout<<endl;
            }
            fout.close();
        }
        if(Preserve(read)){
            ifstream fin;
            fin.open("pic.txt");
            for(int i=1;i<=20;i++){
                for(int j=1;j<=35;j++){
                    int a;
                    fin>>a;
                    Px[i][j].color=a;
                }
            }
            fin.close();
        }
        if(Preserve(cls)){
            for(int i=1;i<=20;i++){
                for(int j=1;j<=35;j++){
                    Px[i][j].color=cc;
                }
            }
        }
        //_sleep(40);
    }
    return 0;
}

int Rcolor(){
    int cl=rand()%15+1;
    return cl;
}
void pout(int x,int y,int c,string s){
    gto(x,y);
    color(c);
    cout<<s;
    color(7);
}
