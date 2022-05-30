#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
int number_guess_auto(int a,int l,int h)
{
    int mid=(l+h)/2;
    printf("\n\t\t\t              Number : ");
    printf("%d",mid);
    printf("\n\t\t\t                ");
    if(a==mid)
        return mid;
    else if(a<mid)
    {
        printf("Too Low\n\n");
        mid=number_guess_auto(a,l,mid-1);
    }
    else
    {
        printf("Too High\n\n");
        mid=number_guess_auto(a,mid+1,h);
    }
}
void number_guess()
{
    int a,n;
    char c;
    system("cls");
    printf("\t\t\t             NUMBER GUESS\n\n");
    printf("\t\t\t       Number is between : 0-10\n\n");
        for(;;a=rand()%10)
        {
            if(kbhit())
                break;
        }
    for(;;)
    {
    printf("\t\t\t              Number : ");
        c=getch();
    if(c==27)
        return;
    else if(c==13){printf("AUTOFILL\n");n=number_guess_auto(a,0,10);}
    else if(c>47||c<58){n=(int)c-48;printf("%d",n);}
    printf("\n\t\t\t                ");
        if(n<a)
            printf("Too Low\n\n");
        else if(n>a)
            printf("Too High\n\n");
        else
        {
            printf("You Win\n\n");
            getch();
            return;
        }
    }
}
void sudoku_display(int a[9][9])
{
    int i,j;
    for(i=0;i<9;i++)
    {
        printf("\t\t\t         ");
        for(j=0;j<9;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
void sudoku_accept(int a[9][9],int b[9])
{
    int i=0,j,c,k,temp;
    for(k=0;k<9;k=k+3)
    {
        for(i=0,c=0;i<3;i++,c=c+3)
        {
            for(j=0;j<9;j++)
                a[i+k][j]=b[((j+c)%9)];
        }
        for(j=0;j<8;j++)
        {
            temp=b[j];
            b[j]=b[j+1];
            b[j+1]=temp;
        }
    }
}
void sudoku_shuffle_small(int a[9][9])
{
    int i,temp;
    int o=(rand()%3)*3,x=rand()%3,y=rand()%3;
    int rc=rand()%2;
    switch(rc)
    {
    case 0:
        for(i=0;i<9;i++)
        {
            temp=a[i][o+x];
            a[i][o+x]=a[i][o+y];
            a[i][o+y]=temp;
        }
        break;
    case 1:
        for(i=0;i<9;i++)
        {
            temp=a[o+x][i];
            a[o+x][i]=a[o+y][i];
            a[o+y][i]=temp;
        }
        break;
    }
}
void sudoku_shuffle_large(int a[9][9])
{
    int i,j,temp;
    int o=(rand()%3)*3;
    int x=(rand()%3)*3;
    int rc=rand()%2;
    switch(rc)
    {
    case 0:
        for(i=0;i<9;i++)
        {
            for(j=0;j<3;j++)
            {
                temp=a[i][o+j];
                a[i][o+j]=a[i][x+j];
                a[i][x+j]=temp;
            }
        }
        break;
    case 1:
        for(i=0;i<9;i++)
        {
            for(j=0;j<3;j++)
            {
                temp=a[o+j][i];
                a[o+j][i]=a[x+j][i];
                a[x+j][i]=temp;
            }
        }
        break;
    }
}
void sudoku_shuffle_basic(int b[9])
{
    int i=rand()%9;
    int j=rand()%9;
    int temp;
    temp=b[i];
    b[i]=b[j];
    b[j]=temp;
}
void sudoku_outline(char s[37][55],int q[9][9])
{
    int i,j,k;
    int a[81];
    for(i=0,k=0;i<9;i++)
        for(j=0;j<9;j++)
            a[k++]=q[i][j];
    k=-1;
    for(i=0;i<37;i++)
    {
        for(j=0;j<55;j++)
        {
                if(!i)
                {
                    if(!j)
                        s[i][j]=201;
                    else if(j==54)
                        s[i][j]=187;
                    else
                        s[i][j]=205;
                }
                else if(i==36)
                {
                    if(!j)
                        s[i][j]=200;
                    else if(j==54)
                        s[i][j]=188;
                    else
                        s[i][j]=205;
                }
                else if(!j||j==54)
                    s[i][j]=186;
        }
    }
    for(i=0;i<37;i++)
    {
        for(j=0;j<55;j=j+3)
        {
            if(j&&j!=54)
            {
                if(j%18==0)
                {
                    if(s[i][j]==' ')
                        s[i][j]=186;
                    else if(!i)
                        s[i][j]=203;
                    else
                        s[i][j]=202;
                }
                else if(j%6==0&&i&&i!=36)
                {
                    s[i][j]=179;
                }
            }
        }
    }
    for(i=0;i<37;i=i+4)
    {
        for(j=0;j<55;j++)
        {
            if(i&&i!=36)
            {
                if(i%12==0)
                {
                    if(!j)
                        s[i][j]=204;
                    else if(j==54)
                        s[i][j]=185;
                    else if(s[i][j]==(char)186)
                        s[i][j]=206;
                    else
                        s[i][j]=205;
                }
                else if(i%4==0)
                {
                    if(s[i][j]==' ')
                        s[i][j]=196;
                    else if(s[i][j]==(char)179)
                        s[i][j]=197;
                }
            }
        }
    }
    for(i=2;i<37;i=i+4)
    {
        for(j=3;j<55;j=j+6)
        {
            if(a[++k])
                s[i][j]=(a[k]+48);
            else
                s[i-1][j+2]=250;
        }
    }
}
void sudoku_draw(char s[37][55])
{
    int i,j;
    printf("\n\n\t\t\t                SUDOKU\n\n");
    for(i=0;i<37;i++)
    {
        printf("\t       ");
        for(j=0;j<55;j++)
        {
            printf("%c",s[i][j]);
        }
        printf("\n");
    }
}
void sudoku_autofill(char s[37][55],int a[9][9])
{
    int y,x,i,j,ox,oy,first=1,k;
    for(y=2;y<37;y=y+4)
    {
        for(x=3;x<55;x=x+6)
        {
            if(s[y-1][x+2]==(char)250)
            {
               printf("\n\t\t\t              AUTOFILL");
                if(!first)
                {
                s[oy+1][ox]=' ';
                s[oy-1][ox]=' ';
                s[oy][ox-2]=' ';
                s[oy][ox+2]=' ';
                }
                s[y+1][x]=24;
                s[y-1][x]=25;
                s[y][x-2]=26;
                s[y][x+2]=27;
                s[y][x]=(char)(a[y/4][x/6]+48);
                getch();
                system("cls");
                sudoku_draw(s);
                oy=y;ox=x;first=0;
            }
        }
    }
}
int sudoku_win(int q[9][9],int a[9][9])
{
    int i,j;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            if(a[i][j]!=q[i][j])
                return 0;
    return 1;
}
int sudoku_play(char s[37][55],int q[9][9],int a[9][9])
{
    int i,j,x,y,ox,oy,flag=0,count=1,win=0;
    char c;
    for(i=2;i<=34&&!flag;i=i+4)
        for(j=3;j<=51&&!flag;j=j+6)
            if(s[i][j]==' ')
            {
                y=i;x=j;
                flag=1;
                break;
            }
    s[y+1][x]=24;
    s[y-1][x]=25;
    s[y][x-2]=26;
    s[y][x+2]=" ";
    sudoku_draw(s);
    while(!win)
    {
        j=ox=x;i=oy=y;flag=1;
        if(kbhit())
        {
            switch(c=getch())
            {
                case 'w':case 72:for(i=y-4,count=1;(flag);i=i-4,count++)
                        {
                            if(i<0&&count==9)
                            {
                                j=j+6;i=34;
                            }
                            if(i<0)
                            {
                                i=34;
                            }
                            if(s[i-1][j+2]==(char)250)
                            {y=i;x=j;flag=0;}
                        }
                        break;
                case 's':case 'x':case 80:for(i=y+4,count=1;flag;i=i+4,count++)
                        {
                            if(i>35&&count==9)
                            {
                                j=j+6;i=2;
                            }
                            if(i>35)
                            {
                                i=2;
                            }
                           if(s[i-1][j+2]==(char)250)
                            {y=i;x=j;flag=0;}
                        }
                        break;
                case 'a':case 75:for(j=x-6,count=1;flag;j=j-6,count++)
                        {
                            if(j<0&&count==9)
                            {
                                i=i+4;j=51;
                            }
                            if(j<0)
                            {
                                j=51;
                            }
                            if(s[i-1][j+2]==(char)250)
                                {y=i;x=j;flag=0;}
                        }
                        break;
                case 'd':case 77:for(j=x+6,count=1;flag;j=j+6,count++)
                        {
                            if(j>52&&count==9)
                            {
                                i=i+4;j=0;
                            }
                            if(j>52)
                            {
                                j=3;
                            }
                            if(s[i-1][j+2]==(char)250)
                                {y=i;x=j;flag=0;}
                        }
                        break;
                case 'q':if(s[y-5][x-4]==(char)250){x=x-6;y=y-4;}
                        break;
                case 'e':if(s[y-5][x+8]==(char)250){x=x+6;y=y-4;}
                        break;
                case 'z':if(s[y+3][x-4]==(char)250){x=x-6;y=y+4;}
                        break;
                case 'c':if(s[y+3][x+8]==(char)250){x=x+6;y=y+4;}
                        break;
                case 13:sudoku_display(a);getch();break;
                case 'f':sudoku_autofill(s,a);getch();return 1;
                case (char)8:s[y][x]=' ';q[(y/4)][(x/6)]=0;win=sudoku_win(a,q);break;
                case (char)27:return 0;
                default:if(c>48&&c<58){s[y][x]=c;q[(y/4)][(x/6)]=((int)c)-48;win=sudoku_win(a,q);}
            }
            s[oy+1][ox]=' ';
            s[oy-1][ox]=' ';
            s[oy][ox-2]=' ';
            s[oy][ox+2]=' ';
            s[y+1][x]=24;
            s[y-1][x]=25;
            s[y][x-2]=26;
            s[y][x+2]=" ";
            system("cls");
            sudoku_draw(s);
        }
    }
    return win;
}
void sudoku()
{
    int a[9][9],c=1,b[9],i=0,j=0;
    int q[9][9],win=0;
    char s[37][55];
    for(i=0;i<37;i++)
        for(j=0;j<55;j++)
            s[i][j]=' ';
    for(i=0;i<9;i++)
        b[i]=i+1;
    for(i=0;i<100;i++)
        for(j=0;j<100;j++)
            sudoku_shuffle_basic(b);
        sudoku_accept(a,b);
    for(i=0;i<1000;i++)
        for(j=0;j<1000;j++)
            sudoku_shuffle_small(a);
    for(i=0;i<1000;i++)
        for(j=0;j<1000;j++)
            sudoku_shuffle_large(a);
    for(;;)
    {
        system("cls");
        printf("\n\n\t\t\t                SUDOKU\n\n");
        printf("\t\t\t        Press Enter to Start\n");
        sudoku_display(a);
        if(kbhit())
            break;
        else
        {
            sudoku_shuffle_small(a);
            sudoku_shuffle_large(a);
        }
    }
    getch();
    getch();
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            q[i][j]=a[i][j];
    for(i=0;i<50;i++)
    {
        q[rand()%9][rand()%9]=0;
    }
    sudoku_outline(s,q);
    system("cls");
    win=sudoku_play(s,q,a);
    system("cls");
    if(win)
        printf("\n\n\t\t\t               YOU WIN\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
struct maze
{
    char a[31][55];
    int w[31][55];
    int points[31][55];
};
typedef struct maze maze;
    maze m;int dots=246;
    int pac_x=28,pac_y=23,blinky_x=26,blinky_y=14,pinky_y=14,pinky_x=28;
    int rem_x,rem_y,life=1;
void space(int y1,int x1,int y2,int x2)
{
    int i,j;
    y1=y1*2;y2=y2*2;
    for(j=y1;j<=y2;j++)
    {
        for(i=x1;i<=x2;i++)
        {
            m.w[i][j]=0;
            m.a[i][j]=' ';
        }
    }
}
void border()
{
        int i,j;
    for(i=0;i<31;i++)
    {
        for(j=0;j<55;j++)
        {
            if(j%2==0)
            m.a[i][j]='.';
            else
            m.a[i][j]=' ';
        }
    }
    for(i=0;i<31;i++)
    {
        for(j=0;j<55;j++)
        {
            m.w[i][j]=0;
        }
    }
m.a[0][0]=201;for(i=1;i<=25;i++){m.a[0][i]=205;m.w[0][i]=1;}m.a[0][26]=187; m.a[0][28]=201;for(i=29;i<=53;i++){m.a[0][i]=205;m.w[0][i]=1;}m.a[0][54]=187;
m.w[0][0]=1;for(i=1;i<=3;i++){m.a[i][26]=186;m.a[i][28]=186;m.w[i][26]=1;m.w[i][28]=1;}m.w[0][26]=1;m.w[0][28]=1;m.w[0][54]=1;
                 m.a[4][26]=200;m.a[4][27]=205;m.a[4][28]=188;
                 m.w[4][26]=1;  m.w[4][27]=1;  m.w[4][28]=1;
for(i=1;i<=8;i++){m.a[i][0]=m.a[i][54]=186;m.w[i][0]=m.w[i][54]=1;}
m.a[9][0]=200;for(i=1;i<=9;i++){m.a[9][i]=205;m.w[9][i]=1;}m.a[9][10]=187;m.a[9][44]=201;for(i=45;i<=53;i++){m.a[9][i]=205;m.w[9][i]=1;}m.a[9][54]=188;
m.w[9][0]=1;                                               m.w[9][10]=1;  m.w[9][44]=1;                                                 m.w[9][54]=1;
for(i=10;i<=12;i++){m.a[i][10]=m.a[i][44]=186;m.w[i][10]=m.w[i][44]=1;}
m.a[13][10]=188;m.a[13][44]=200;for(i=0;i<=9;i++){m.a[13][i]=205;m.w[13][i]=1;}
m.w[13][10]=m.w[13][44]=1;for(i=45;i<=54;i++){m.a[13][i]=205;m.w[13][i]=1;}

m.a[15][10]=187;m.a[15][44]=201;for(i=0;i<=9;i++){m.a[15][i]=205;m.w[15][i]=1;}
m.w[15][10]=m.w[15][44]=1;for(i=45;i<=54;i++){m.a[15][i]=205;m.w[15][i]=1;}
for(i=16;i<=18;i++){m.a[i][10]=m.a[i][44]=186;m.w[i][10]=m.w[i][44]=1;}
m.a[19][10]=188;m.a[19][44]=200;for(i=1;i<=9;i++){m.a[19][i]=205;m.w[19][i]=1;}
m.w[19][10]=m.w[19][44]=1;for(i=45;i<=53;i++){m.a[19][i]=205;m.w[19][i]=1;}
m.a[19][0]=201;m.a[19][54]=187;
m.w[19][0]=m.w[19][54]=1;

for(i=20;i<=23;i++){m.a[i][0]=m.a[i][54]=186;m.w[i][0]=m.w[i][54]=1;}

m.a[24][0]=200;for(i=1;i<=3;i++){m.a[24][i]=205;}m.a[24][4]=187;
m.a[24][50]=201;for(i=51;i<=53;i++){m.a[24][i]=205;}m.a[24][54]=188;
m.a[25][0]=201;for(i=1;i<=3;i++){m.a[25][i]=205;}m.a[25][4]=188;
m.a[25][50]=200;for(i=51;i<=53;i++){m.a[25][i]=205;}m.a[25][54]=187;
m.w[24][0]=1;for(i=1;i<=3;i++){m.w[24][i]=1;}m.w[24][4]=1;
m.w[24][50]=1;for(i=51;i<=53;i++){m.w[24][i]=1;}m.w[24][54]=1;
m.w[25][0]=1;for(i=1;i<=3;i++){m.w[25][i]=1;}m.w[25][4]=1;
m.w[25][50]=1;for(i=51;i<=53;i++){m.w[25][i]=1;}m.w[25][54]=1;

for(i=26;i<=29;i++){m.a[i][0]=m.a[i][54]=186;m.w[i][0]=m.w[i][54]=1;}
m.a[30][0]=200;             for(i=1;i<=53;i++){m.a[30][i]=205;m.w[30][i]=1;}                    m.a[30][54]=188;
m.w[30][0]=1;                                                                                   m.w[30][54]=1;
}
//void ob(int x1,int y1,int x2,int y2)
void ob(int y1,int x1,int y2,int x2)
{
    int i,j;
    y1=y1*2;y2=y2*2;
    for(j=y1;j<=y2;j++)
    {
        for(i=x1;i<=x2;i++)
        {
            m.w[i][j]=1;
            m.a[i][j]=' ';
        }
    }
    /*
    |- 201          -| 187
    |_ 200          _| 188
    || 186
    = 205
    */
    m.a[x1][y1]=201;m.a[x2][y1]=200;
    m.a[x1][y2]=187;m.a[x2][y2]=188;
    for(j=y1+1;j<y2;j++){m.a[x1][j]=205;}
    for(j=y1+1;j<y2;j++){m.a[x2][j]=205;}
    for(i=x1+1;i<x2;i++){m.a[i][y1]=186;}
    for(i=x1+1;i<x2;i++){m.a[i][y2]=186;}
}
void spaces()
{
    space(0,10,4,12);
    space(23,10,27,12);
    space(0,14,5,14);
    space(22,14,27,14);
    space(0,16,4,18);
    space(23,16,27,18);
    space(7,9,20,19);
    ob(10,12,17,16);
    space(13,12,14,13);
    space(11,13,16,15);
}
void obstacles()
{
    ob(2,2,5,4);
    ob(7,2,11,4);
    ob(16,2,20,4);
    ob(22,2,25,4);
    ob(2,6,5,7);
    ob(7,6,8,13);
    ob(10,6,17,7);
    ob(19,6,20,13);
    ob(22,6,25,7);
    ob(8,9,11,10);
    ob(16,9,19,10);
    ob(13,7,14,10);
    ob(7,15,8,19);
    ob(19,15,20,19);
    ob(10,18,17,19);
    ob(13,19,14,22);
    ob(2,21,5,22);
    ob(7,21,11,22);
    ob(16,21,20,22);
    ob(22,21,25,22);
    ob(4,22,5,25);
    ob(22,22,23,25);
    ob(2,27,11,28);
    ob(16,27,25,28);
    ob(7,24,8,27);
    ob(10,24,17,25);
    ob(13,25,14,28);
    ob(19,24,20,27);
}
void display()
{
        int i,j;
        if(m.a[pac_y][pac_x]=='.')
            {
                dots--;
                m.points[pac_y][pac_x]=0;
            }
        m.a[pac_y][pac_x]='O';
        for(i=0;i<31;i++)
    {
        for(j=0;j<55;j++)
        {
            printf("%c",m.a[i][j]);
        }
        printf("\n");
    }
    printf("%d\tX=%d\tY=%d\n",dots,pac_x,pac_y);
}
void move(int n)
{
    switch(n)
    {
        case 1:if(m.w[pac_y-1][pac_x]!=1){m.a[pac_y--][pac_x]=' ';}break;
        case 2:if((pac_y==14)&&(pac_x==54)){m.a[pac_y][pac_x]=' ';pac_x=0;break;}else if(m.w[pac_y][pac_x+2]!=1){m.a[pac_y][pac_x]=' ';pac_x=pac_x+2;}break;
        case 3:if(m.w[pac_y+1][pac_x]!=1){m.a[pac_y++][pac_x]=' ';}break;
        case 4:if((pac_y==14)&&(pac_x==0)){m.a[pac_y][pac_x]=' ';pac_x=54;break;}else if(m.w[pac_y][pac_x-2]!=1){m.a[pac_y][pac_x]=' ';pac_x=pac_x-2;}break;
    }
}
int pathfind(int y,int x,int *ghost_y,int *ghost_x,int g_d,char c)
{
    float h[4],least;
    int g_y=(*ghost_y),g_x=(*ghost_x),i;
    if(g_d==2&&(*ghost_y==14)&&(*ghost_x==54)){m.a[*ghost_y][*ghost_x]=' ';*ghost_x=0;return g_d;}
    if(g_d==4&&(*ghost_y==14)&&(*ghost_x==0)){m.a[*ghost_y][*ghost_x]=' ';*ghost_x=54;return g_d;}
    h[0]=sqrt(pow((g_y-1-y),2)+pow((g_x-x),2));
    h[1]=sqrt(pow((g_y-y),2)+pow((g_x+2-x),2));
    h[2]=sqrt(pow((g_y+1-y),2)+pow((g_x-x),2));
    h[3]=sqrt(pow((g_y-y),2)+pow((g_x-2-x),2));
    if(m.w[g_y-1][g_x])
        h[0]=999;
    if(m.w[g_y][g_x+2])
        h[1]=999;
    if(m.w[g_y+1][g_x])
        h[2]=999;
    if(m.w[g_y][g_x-2])
        h[3]=999;
    switch(g_d)
    {
        case 3:h[0]=999;break;
        case 4:h[1]=999;break;
        case 1:h[2]=999;break;
        case 2:h[3]=999;break;
    }
    least=h[0];
    g_d=1;
    for(i=1;i<4;i++)
    {
        if(least>h[i])
        {
            g_d=i+1;
            least=h[i];
        }
    }
    if(m.points[*ghost_y][*ghost_x])
    {
        m.a[*ghost_y][*ghost_x]='.';
    }
    else
    {
        m.a[*ghost_y][*ghost_x]=' ';
    }
    switch(g_d)
    {
        case 1:(*ghost_y)--;break;
        case 2:(*ghost_x)=(*ghost_x)+2;break;
        case 3:(*ghost_y)++;break;
        case 4:(*ghost_x)=(*ghost_x)-2;break;
    }
        m.a[*ghost_y][*ghost_x]=c;
    return g_d;
}
void play()
{
    int i,still=0,blinky_dir=0,pinky_dir=0,blinky_in=1,pinky_in=1;
    for(;;)
    {
    for(i=0;i<80000000;i++);
       if((!life)||(!dots))
        {
            if(life==0)
            {
                printf("\n\t\t\t\tYOU LOSE\n");
                return;
            }
            if(dots==0)
            {
                system("cls");
                printf("YOU WIN\n");
                return;
            }
        }
        system("cls");
       display();
       if(kbhit())
       {
           switch(getch())
           {
               case 'w':move(1);still=1;break;
               case 'd':move(2);still=2;break;
               case 's':move(3);still=3;break;
               case 'a':move(4);still=4;break;
           }
       }
       else
       {
           switch(still)
           {
               case 1:move(1);break;
               case 2:move(2);break;
               case 3:move(3);break;
               case 4:move(4);break;
           }
       }
       if(blinky_in)
       {
           blinky_dir=pathfind(11,28,&blinky_y,&blinky_x,blinky_dir,'B');
           if(blinky_y==11&&blinky_x==28)
           {
               blinky_in=0;
           }
       }
       else
           blinky_dir=pathfind(pac_y,pac_x,&blinky_y,&blinky_x,blinky_dir,'B');
       if(pinky_in&&!blinky_in)
       {
           pinky_dir=pathfind(11,26,&pinky_y,&pinky_x,pinky_dir,'P');
           if(pinky_y==11&&pinky_x==26)
           {
               pinky_in=0;
               if(!pinky_in&&!blinky_in)
               {
                   m.w[12][26]=m.w[12][27]=m.w[12][28]=1;
                   m.a[12][26]=m.a[12][27]=m.a[12][28]='-';
               }
           }
       }
       else if(!pinky_in)
       {
           switch(still)
           {
               case 1:pinky_dir=pathfind(pac_y-4,pac_x,&pinky_y,&pinky_x,pinky_dir,'P');break;
               case 2:pinky_dir=pathfind(pac_y,pac_x+4,&pinky_y,&pinky_x,pinky_dir,'P');break;
               case 3:pinky_dir=pathfind(pac_y+4,pac_x,&pinky_y,&pinky_x,pinky_dir,'P');break;
               case 4:pinky_dir=pathfind(pac_y,pac_x-4,&pinky_y,&pinky_x,pinky_dir,'P');break;
               default:pinky_dir=pathfind(pac_y,pac_x,&pinky_y,&pinky_x,pinky_dir,'P');break;
           }
       }
       /*if(clyde_in&&!blinky_in)
       {
           if(blinky_y==11&&blinky_x==28)
           {
               m.w[12][26]=m.w[12][27]=m.w[12][28]=1;
               m.a[12][26]=m.a[12][27]=m.a[12][28]='-';
               blinky_in=0;
           }
       }*/
       if((pac_x==blinky_x&&pac_y==blinky_y)||(pac_x==pinky_x&&pac_y==pinky_y))
            life--;
    }
}
void pacman()
{
    int i,j;
    border();
    spaces();
    obstacles();
    for(i=0;i<31;i++)
        for(j=0;j<55;j++)
        {
            if(m.a[i][j]=='.')
                m.points[i][j]=1;
            else
                m.points[i][j]=0;
        }
    play();
}
struct node
{
    int y,x,dir;
    struct node*rlink;
    struct node*llink;
};
typedef struct node nd;
struct fruit
{
    int y,x;
};
typedef struct fruit fruit;
void snake_outline(char s[30][88])
{
    int i,j,k=-1;
    for(i=0;i<30;i++)
    {
        for(j=0;j<88;j++)
        {
            s[i][j]=' ';
            if(i==0||i==29||j==0||j==87)
                s[i][j]=(char)176;
        }
    }
}
void snake_display(char s[30][88],nd*hd,fruit*a)
{
    int i,j;nd*t;
    char v;
    for(t=hd;t!=0;t=t->rlink)
        s[t->y][t->x]=(char)219;
    s[a->y][a->x]='*';
    system("cls");
    for(i=0;i<30;i++)
    {
        for(j=0;j<88;j++)
        {
            if(s[i][j]==(char)219)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            else if(s[i][j]=='*')
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
            printf("%c",s[i][j]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
        printf("\n");
    }
    for(t=hd;t!=0;t=t->rlink)
        s[t->y][t->x]=' ';
}
void snake_headcontrol(char s[30][88],nd*hd)
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'w':hd->dir=1;break;
            case 's':hd->dir=3;break;
            case 'a':hd->dir=4;break;
            case 'd':hd->dir=2;break;
            default:break;
        }
    }
}
void snake_move(nd*hd)
{
    nd*t;
    switch(hd->dir)
    {
        case 1:(hd->y)--;break;
        case 2:(hd->x)++;break;
        case 3:(hd->y)++;break;
        case 4:(hd->x)--;break;
        default:break;
    }
   for(t=hd->rlink;t->rlink!=0;t=t->rlink);
   for(;t->llink!=0;t=t->llink)
   {
       t->dir=(t->llink)->dir;
       switch(t->dir)
       {
           case 1:t->y=((t->llink)->y);t->x=(t->llink)->x;break;
           case 2:t->x=((t->llink)->x);t->y=(t->llink)->y;break;
           case 3:t->y=((t->llink)->y);t->x=(t->llink)->x;break;
           case 4:t->x=((t->llink)->x);t->y=(t->llink)->y;break;
       }
   }
}
void snake()
{
    char s[30][88];
    int i,length=1;
    nd hd,tl,*t,*l;
    fruit a;
    hd.x=44;hd.y=15;hd.dir=0;hd.llink=0;
    tl.x=45;tl.y=15;tl.dir=0;tl.llink=&hd;tl.rlink=0;hd.rlink=&tl;
    a.x=(rand()%86)+1;a.y=(rand()%28)+1;
    snake_outline(s);
    for(;;)
    {
        for(t=(hd.rlink)->rlink;length&&t!=0;t=t->rlink)
            if((t->y==hd.y)&&(t->x==hd.x))
            {
                printf("\n\n\t\t\t\t  GAME OVER!!!\n");
                printf("\t\t\t\tFINAL LENGTH = %d",length);
                return;
            }
        snake_headcontrol(s,&hd);
        if(hd.x==a.x&&hd.y==a.y)
        {
            length++;
            a.x=(rand()%86)+1;a.y=(rand()%28)+1;
            t=(nd*)malloc(sizeof(nd));
            for(l=&hd;l->rlink!=0;l=l->rlink);
            t->dir=l->dir;
            switch(t->dir)
            {
                case 1:t->y=(l->y)+1;t->x=l->x;break;
                case 2:t->x=(l->x)-1;t->y=l->y;break;
                case 3:t->y=(l->y)-1;t->x=l->x;break;
                case 4:t->x=(l->x)+1;t->y=l->y;break;
            }
            t->rlink=0;
            t->llink=l;
            l->rlink=t;
        }
        snake_move(&hd);
        if(hd.x==0||hd.x==87||hd.y==0||hd.y==29)
         {
                printf("\n\n\t\t\t\t  GAME OVER!!!\n");
                printf("\t\t\t\tFINAL LENGTH = %d",length);
                return;
            }
        snake_display(s,&hd,&a);
        for(i=0;i<20000000;i++);
    }
}
void minesweeper_generate_mines(int mines[10])
{
    int c,k=0,i,j,flag;
    for(;;)
    {
        k=0;
        for(i=0;i<10;i++)
            mines[i]=0;
        for(i=0,flag=1;i<10;i++,flag=1)
        {
            c=rand()%81;
            for(j=0;j<10;j++)
                if(mines[j]==c)
                {
                    i--;
                    flag=0;
                    break;
                }
            if(flag)
                mines[k++]=c;
        }
        if(kbhit())
            break;
    }
}
void minesweeper_tile_numbering(int b[10],int a[11][11])
{
    int i,j,y,x;
    for(i=0;i<11;i++)
        for(j=0;j<11;j++)
            a[i][j]=0;
    for(i=0;i<10;i++)
        a[(b[i]/9)+1][(b[i]%9)+1]=-1;
    for(i=1;i<10;i++)
        for(j=1;j<10;j++)
            if(a[i][j]!=-1)
            {
                for(y=-1;y<2;y++)
                {
                    for(x=-1;x<2;x++)
                    {
                        if(!x&&!y)
                            continue;
                        if(a[i+y][j+x]==-1)
                            (a[i][j])++;
                    }
                }
            }
    for(i=0;i<11;i++)
        for(j=0;j<11;j++)
            if(i==0||j==0||i==10||j==10)
                a[i][j]=99;
}
void minesweeper_display(char s[37][63])
{
    int i,j;
    system("cls");
    for(i=0;i<37;i++)
    {
         for(j=0;j<63;j++)
         {
             if(s[i][j]==(char)219)
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                printf("%c",s[i][j]);
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
         }
         printf("\n");
    }
}
void minesweeper_tile_draw(char s[37][63],int n)
{
    int i,j,x1,y1,x2,y2;
    x1=(7*(n%9)+1);
    x2=x1+4;
    y1=(4*(n/9))+1;
    y2=y1+2;
    for(i=y1;i<=y2;i++)
        for(j=x1;j<=x2;j++)
            s[i][j]=219;
}
void minesweeper_create_board(char s[37][63])
{
    int i,j;
    for(i=0;i<37;i++)
        for(j=0;j<63;j++)
            s[i][j]=' ';
    for(i=0;i<81;i++)
       minesweeper_tile_draw(s,i);
}
void minesweeper_arrow(char s[37][63],int now,int prev)
{
    //18 , 31
    int y,x;
    if(prev!=-1)
    {
       x=(7*(prev%9))+3;
        y=(4*(prev/9))+2;
        s[y-2][x]=' ';
        s[y+2][x]=' ';
        s[y][x-3]=' ';
        s[y][x+3]=' ';
    }
    x=(7*(now%9))+3;
    y=(4*(now/9))+2;
    s[y-2][x]=25;
    s[y+2][x]=24;
    s[y][x-3]=26;
    s[y][x+3]=27;
}
void minesweeper_open_tile(char s[37][63],int n,int a)
{
    int i,j,x1,y1,x2,y2;
    x1=(7*(n%9)+1);
    x2=x1+4;
    y1=(4*(n/9))+1;
    y2=y1+2;
    for(i=y1;i<=y2;i++)
        for(j=x1;j<=x2;j++)
            s[i][j]=' ';
    s[y1][x1]=201;s[y1][x1+1]=s[y1][x1+2]=s[y1][x1+3]=205;s[y1][x2]=187;
    s[y1+1][x1]=186; if(a>0){s[y1+1][x1+2]=(char)(a+48);}else if(a==-1){s[y1+1][x1+2]=15;}s[y1+1][x2]=186;
    s[y2][x1]=200;s[y2][x1+1]=s[y2][x1+2]=s[y2][x1+3]=205;s[y2][x2]=188;
}
int minesweeper_reveal(char s[37][63],int n,int board[11][11],int revealed[9][9],int flagged[9][9])
{
    int y=(n/9),x=(n%9);
    if(board[y+1][x+1]==-1)
        return 1;
    if(revealed[y][x])
        return 0;
    else if((board[y+1][x+1]>0)&&(!flagged[y][x]))
    {
        revealed[y][x]=1;
        minesweeper_open_tile(s,n,board[y+1][x+1]);
        return 0;
    }
    else if((board[y+1][x+1]==0)&&(!flagged[y][x]))
    {
        revealed[y][x]=1;
        minesweeper_open_tile(s,n,board[y+1][x+1]);
        if(y&&x){minesweeper_reveal(s,n-10,board,revealed,flagged);}
        if(y){minesweeper_reveal(s,n-9,board,revealed,flagged);}
        if(y&&x!=8){minesweeper_reveal(s,n-8,board,revealed,flagged);}
        if(x){minesweeper_reveal(s,n-1,board,revealed,flagged);}
        if(x!=8){minesweeper_reveal(s,n+1,board,revealed,flagged);}
        if(y!=8&&x){minesweeper_reveal(s,n+8,board,revealed,flagged);}
        if(y!=8){minesweeper_reveal(s,n+9,board,revealed,flagged);}
        if(y!=8&&x!=8){minesweeper_reveal(s,n+10,board,revealed,flagged);}
        return 0;
    }
}
int minesweeper_win(char s[37][63],int revealed[9][9],int flagged[9][9])
{
    int i,j;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            if(!revealed[i][j])
                return 0;
    return 1;
}
void minesweeper_flagged_tile(char s[37][63],int n)
{
    int i,j,x1,y1,x2,y2;
    x1=(7*(n%9)+1);
    x2=x1+4;
    y1=(4*(n/9))+1;
    y2=y1+2;
    for(i=y1;i<=y2;i++)
        for(j=x1;j<=x2;j++)
            s[i][j]=176;
    s[y1+1][x1+2]=6;
}
void minesweeper_flag(char s[37][63],int n,int board[11][11],int revealed[9][9],int flagged[9][9])
{
    int y=(n/9),x=(n%9);
    if(flagged[y][x])
    {
        /*if(board[y+1][x+1]!=-1)
            revealed[y][x]=0;*/
        flagged[y][x]=0;
        minesweeper_tile_draw(s,n);
    }
    else if(!revealed[y][x]&&!flagged[y][x])
    {
        flagged[y][x]=1;
        minesweeper_flagged_tile(s,n);
    }
    else if(revealed[y][x]&&board[y+1][x+1]==-1&&!flagged[y][x])
    {
        flagged[y][x]=1;
        minesweeper_flagged_tile(s,n);
    }
}
void minesweeper_play(char s[37][63],int board[11][11])
{
    int i,j,n=40,p=-1,moved=0,win=0,loss=0;
    int revealed[9][9]={0},flagged[9][9]={0};
    char c;
    minesweeper_arrow(s,n,p);
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            if(board[i+1][j+1]==-1)
                revealed[i][j]=1;
    for(;win==0&&loss==0;moved=0)
    {
        if(kbhit())
        {
            p=n;
            switch(getch())
            {
                case 'w':case 72:moved++;if(n-9>-1){n=n-9;}else{n=n+72;}break;
                case 's':case 80:moved++;if(n+9<81){n=n+9;}else{n=n-72;}break;
                case 'a':case 75:moved++;if(n-1>-2){if(n%9==0){n=n+8;}else{n=n-1;}}break;
                case 'd':case 77:moved++;if(n+1<82){if((n-8)%9==0){n=n-8;}else{n=n+1;}}break;
                case 'x':exit(0);return;
                case 13 :moved++;n=40;break;
      /*reveal*/case 32 :loss=minesweeper_reveal(s,n,board,revealed,flagged);break;
      /*flag  */ case 9 :{minesweeper_flag(s,n,board,revealed,flagged);}break;
            }
            if(moved){minesweeper_arrow(s,n,p);}
            else{win=minesweeper_win(s,revealed,flagged);}
            minesweeper_display(s);
        }
    }
    printf("\n\n\t\t\t\tGAME OVER!!!");
}
void minesweeper()
{
    char s[37][63];
    int mines[10],board[11][11];
        minesweeper_generate_mines(mines);
        minesweeper_tile_numbering(mines,board);
        minesweeper_create_board(s);
        minesweeper_play(s,board);
}
void tetris_display(char s[55][66],char cstack[24][12])
{
    int i,j,x,y,k=0;
    system("cls");
    for(i=0;i<55;i++)
    {
        for(j=0;j<66;j++)
        {
            if((s[i][j]==(char)219)&&j>24)
            {
                y=(i/3)+5;
                x=((j-24)/4)+1;
                switch(cstack[y][x])
                {
                    case 'i':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);break;
                    case 'o':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);break;
                    case 't':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);break;
                    case 'j':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);break;
                    case 'l':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);break;
                    case 'z':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);break;
                    case 's':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);break;
                    case 'g':SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);break;
                }
                 printf("%c",s[i][j]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
            else
            {
                               printf("%c",s[i][j],k++);
            }
        }
        printf("\n");
    }
}
void tetris_stack_initial(int stack[24][12],char cstack[24][12])
{
    int i,j,y,x,n;
    for(i=0;i<24;i++)
        for(j=0;j<12;j++)
        {
            if(i==0||j==0||j==11||i==23)
            {
                stack[i][j]=3;
                cstack[i][j]='#';
            }
            else
            {
                stack[i][j]=0;
                cstack[i][j]=' ';
            }
        }
}
void tetris_stack_to_tiles(char s[55][66],int stack[24][12])
{
    int i,j,k=0,x1,y1,x2,y2,m,n;
    for(i=5;i<23;i++)
        for(j=1;j<11;j++,k++)
        {
            x1=((4*(k%10))+25);
            y1=(3*(k/10))+1;
            x2=x1+2;
            y2=y1+1;
            if(stack[i][j]==1||stack[i][j]==2||stack[i][j]==-1)
            {
                for(m=y1;m<=y2;m++)
                    for(n=x1;n<=x2;n++)
                        s[m][n]=219;
            }
            else
            {
                for(m=y1;m<=y2;m++)
                    for(n=x1;n<=x2;n++)
                        s[m][n]=' ';
            }
        }
}
void tetris_stack_display(int stack[24][12])
{
    int i,j;
    system("cls");
    for(i=0;i<24;i++)
    {
        for(j=0;j<12;j++)
            printf("%d",stack[i][j]);
        printf("\n");
    }
}
void tetris_cstack_display(char cstack[24][12])
{
    int i,j;
    system("cls");
    for(i=0;i<24;i++)
    {
        for(j=0;j<12;j++)
            printf("%c",cstack[i][j]);
        printf("\n");
    }
}
void tetris_randomize_bag(char bag[7])
{
    int i,j,k;
    char t;
    for(k=0;k<7;k++)
    {
        i=rand()%7;
        j=rand()%7;
        t=bag[i];
        bag[i]=bag[j];
        bag[j]=t;
    }
}
void tetris_bag_display(char bag[7])
{
    int i;
    for(i=0;i<7;i++)
        printf("%c ",bag[i]);
    printf("\n");
}
void tetris_append_bags(char bag[14],char bag1[7],char bag2[7])
{
    int i,k;
    for(k=0,i=0;k<14;i=(i+1)%7,k++)
    {
        if(k<7)
           bag[k]=bag1[i];
        else
            bag[k]=bag2[i];
    }
}
void tetris_pick_piece(char *piece,char *next_piece,int *bag_top,char bag[14],char bag1[7],char bag2[7])
{
    if((*bag_top)>6&&(*bag_top)!=13)
    tetris_randomize_bag(bag1);
    if((*bag_top)<6&&(*bag_top)!=6)
    tetris_randomize_bag(bag2);
    tetris_append_bags(bag,bag1,bag2);
    (*piece)=bag[(*bag_top)];
    (*next_piece)=bag[(*bag_top)+1];
    (*bag_top)=((*bag_top)+1)%14;
}
void tetris_dimensions(char piece,int*dimensions,int tiles[4],int*tile_pos)
{
    switch(piece)
    {
        case 'i':(*dimensions)=4;tiles[0]=4;tiles[1]=5;tiles[2]=6;tiles[3]=7;*tile_pos=24;break;
        case 'o':(*dimensions)=2;tiles[0]=0;tiles[1]=1;tiles[2]=2;tiles[3]=3;*tile_pos=25;break;
        case 't':(*dimensions)=3;tiles[0]=1;tiles[1]=3;tiles[2]=4;tiles[3]=5;*tile_pos=24;break;
        case 'j':(*dimensions)=3;tiles[0]=0;tiles[1]=3;tiles[2]=4;tiles[3]=5;*tile_pos=24;break;
        case 'l':(*dimensions)=3;tiles[0]=2;tiles[1]=3;tiles[2]=4;tiles[3]=5;*tile_pos=24;break;
        case 'z':(*dimensions)=3;tiles[0]=0;tiles[1]=1;tiles[2]=4;tiles[3]=5;*tile_pos=24;break;
        case 's':(*dimensions)=3;tiles[0]=1;tiles[1]=2;tiles[2]=3;tiles[3]=4;*tile_pos=24;break;
    }
}
void tetris_orientation(int orientation,int dimensions,int**numbers)
{
    int i,j,c;
    switch(orientation)
    {
        case 0:for(i=0,c=0;i<dimensions;i++)
                for(j=0;j<dimensions;j++,c++)
                    numbers[i][j]=c;
                break;
        case 1:for(i=dimensions-1,c=0;i>-1;i--)
                for(j=0;j<dimensions;j++,c++)
                    numbers[j][i]=c;
                break;
        case 2:for(i=dimensions-1,c=0;i>-1;i--)
                for(j=dimensions-1;j>-1;j--,c++)
                    numbers[i][j]=c;
                break;
        case 3:for(i=0,c=0;i<dimensions;i++)
                for(j=dimensions-1;j>-1;j--,c++)
                    numbers[j][i]=c;
                break;
    }
}
void tetris_i_z_s_orientation(int orientation,int dimensions,int**numbers)
{
    int i,j,c;
    switch(orientation)
    {
    case 0:case 2:for(i=0,c=0;i<dimensions;i++)
                for(j=0;j<dimensions;j++,c++)
                    numbers[i][j]=c;
                break;
    case 1:case 3:for(i=0,c=0;i<dimensions;i++)
                for(j=0;j<dimensions;j++,c++)
                    numbers[j][i]=c;
                break;
    }
}
void tetris_spawn_piece(int dimensions,int**numbers,int tiles[4],int stack[24][12],int tile_pos,char cstack[24][12],char piece)
{
    int i,j,k;
    for(i=0;i<dimensions;i++)
        for(j=0;j<dimensions;j++)
            for(k=0;k<4;k++)
                if(tiles[k]==numbers[i][j])
                {
                    stack[(tile_pos/10)+i][(tile_pos%10)+j]=1;
                    cstack[(tile_pos/10)+i][(tile_pos%10)+j]=piece;
                }
}
void tetris_gravity(int dimensions,int**numbers,int tiles[4],int stack[24][12],int*tile_pos,char cstack[24][12],char piece)
{
    int i,j,k;
    for(i=0;i<dimensions;i++)
        for(j=0;j<dimensions;j++)
            for(k=0;k<4;k++)
                if(tiles[k]==numbers[i][j])
                {
                    stack[((*tile_pos)/10)+i][((*tile_pos)%10)+j]=0;
                    cstack[((*tile_pos)/10)+i][((*tile_pos)%10)+j]=' ';
                }
    (*tile_pos)=(*tile_pos)+10;
    for(i=0;i<dimensions;i++)
        for(j=0;j<dimensions;j++)
            for(k=0;k<4;k++)
                if(tiles[k]==numbers[i][j])
                {
                    stack[((*tile_pos)/10)+i][((*tile_pos)%10)+j]=1;
                    cstack[((*tile_pos)/10)+i][((*tile_pos)%10)+j]=piece;
                }
}
int tetris_check_landing(int tile_pos,int**numbers,int dimensions,int tiles[4],int stack[24][12])
{
    int i,j,k;
    for(i=0;i<dimensions;i++)
        for(j=0;j<dimensions;j++)
            for(k=0;k<4;k++)
                if(tiles[k]==numbers[i][j])
                    if(stack[(tile_pos/10)+i+1][(tile_pos%10)+j]==3||(stack[(tile_pos/10)+i+1][(tile_pos%10)+j]==2))
                        return 1;
    return 0;
}
void tetris_piece_block(int tile_pos,int**numbers,int dimensions,int tiles[4],int stack[24][12])
{
    int i,j,k,land=0;
    for(i=0;i<dimensions;i++)
        for(j=0;j<dimensions;j++)
            for(k=0;k<4;k++)
                if(tiles[k]==numbers[i][j])
                    stack[(tile_pos/10)+i][(tile_pos%10)+j]=2;
}
void tetris_hold(int tile_pos,int**numbers,int dimensions,int tiles[4],int stack[24][12],char cstack[24][12])
{
    int i,j,k=0,c=0,piece,tile[4];
    for(i=0;i<dimensions;i++)
        for(j=0;j<dimensions;j++,c++)
            for(k=0;k<4;k++)
                if(tiles[k]==numbers[i][j])
                {
                    stack[(tile_pos/10)+i][(tile_pos%10)+j]=0;
                    cstack[(tile_pos/10)+i][(tile_pos%10)+j]=' ';
                }
}
int tetris_top(int stack[24][12])
{
    int i,j,stack_top=0,flag;
    for(i=22,flag=0;i>3;i--,flag=0)
    {
        for(j=1;(j<11)&&(!flag);j++)
        {
            if(stack[i][j]==2)
            {
                stack_top++;
                flag=1;
            }
        }
    }
    return stack_top;
}
void tetris_move_piece(char move,int dimensions,int**numbers,int tiles[4],int stack[24][12],int*tile_pos,char cstack[24][12],char piece)
{
    int i,j,k;
    switch(move)
    {
        case 'a':
        for(i=0;i<dimensions;i++)
            for(j=0;j<dimensions;j++)
                for(k=0;k<4;k++)
                    if(tiles[k]==numbers[i][j])
                        if(stack[((*tile_pos)/10)+i][((*tile_pos)%10)+j-1]==3||(stack[((*tile_pos)/10)+i][((*tile_pos)%10)+j-1]==2))
                            return;
        break;
        case 'd':
        for(i=0;i<dimensions;i++)
            for(j=0;j<dimensions;j++)
                for(k=0;k<4;k++)
                    if(tiles[k]==numbers[i][j])
                        if(stack[((*tile_pos)/10)+i][((*tile_pos)%10)+j+1]==3||(stack[((*tile_pos)/10)+i][((*tile_pos)%10)+j+1]==2))
                            return;
        break;
    }
    switch(move)
    {
    case 'a':
    for(i=0;i<dimensions;i++)
            for(j=0;j<dimensions;j++)
                for(k=0;k<4;k++)
                    if(tiles[k]==numbers[i][j])
                    {
                        stack[((*tile_pos)/10)+i][((*tile_pos)%10)+j]=0;
                        stack[((*tile_pos)/10)+i][((*tile_pos)%10)+j-1]=1;
                        cstack[((*tile_pos)/10)+i][((*tile_pos)%10)+j]=' ';
                        cstack[((*tile_pos)/10)+i][((*tile_pos)%10)+j-1]=piece;
                    }
    (*tile_pos)--;
     break;
     case 'd':
    for(i=dimensions-1;i>-1;i--)
            for(j=dimensions-1;j>-1;j--)
                for(k=0;k<4;k++)
                    if(tiles[k]==numbers[i][j])
                    {
                        stack[((*tile_pos)/10)+i][((*tile_pos)%10)+j]=0;
                        stack[((*tile_pos)/10)+i][((*tile_pos)%10)+j+1]=1;
                        cstack[((*tile_pos)/10)+i][((*tile_pos)%10)+j]=' ';
                        cstack[((*tile_pos)/10)+i][((*tile_pos)%10)+j+1]=piece;
                    }
    (*tile_pos)++;
     break;
    }
}
void tetris_rotate(char cstack[24][12],char piece,int*orientation,int dimensions,int**numbers,int tiles[4],int stack[24][12],int*tile_pos)
{
    int i,j,k,a=(*tile_pos);
    if((*tile_pos)%10==0)
        a=(*tile_pos)+1;
    if(piece=='i')
    {
        if((*tile_pos)%10==8)
            a=(*tile_pos)-1;
        if((*tile_pos)%10==9)
            a=(*tile_pos)-2;
    }
    else if(piece!='o')
    {
        if((*tile_pos)%10==9)
            a=(*tile_pos)-1;
    }
    int**check=(int**)malloc(dimensions*(sizeof(int*)));
    for(i=0;i<dimensions;i++)
        check[i]=(int*)malloc(sizeof(int));
    if(piece=='i'||piece=='z'||piece=='s')
        tetris_i_z_s_orientation(((*orientation)+1)%4,dimensions,check);
    else
        tetris_orientation(((*orientation)+1)%4,dimensions,check);
    for(i=0;i<dimensions;i++)
        for(j=0;j<dimensions;j++)
            for(k=0;k<4;k++)
                if(tiles[k]==check[i][j])
                    if(stack[(a/10)+i][(a%10)+j]==3||(stack[(a/10)+i+1][(a%10)+j]==2))
                        return;
    for(i=0;i<dimensions;i++)
        for(j=0;j<dimensions;j++)
        {
            for(k=0;k<4;k++)
                if(tiles[k]==numbers[i][j])
                {
                    stack[((*tile_pos)/10)+i][((*tile_pos)%10)+j]=0;
                    cstack[((*tile_pos)/10)+i][((*tile_pos)%10)+j]=' ';
                }
        }
    (*tile_pos)=a;
    for(i=0;i<dimensions;i++)
        for(j=0;j<dimensions;j++)
        {
            numbers[i][j]=check[i][j];
            for(k=0;k<4;k++)
                if(tiles[k]==check[i][j])
                  {
                      stack[(a/10)+i][(a%10)+j]=1;
                      cstack[(a/10)+i][(a%10)+j]=piece;
                  }
        }
    (*orientation)=((*orientation)+1)%4;
    free(check);
}
void tetris_clear(char s[55][66],int*cleared,int stack[24][12],char cstack[24][12])
{
    int i,j,k,c;
    char piece;
    for(i=22,c=0;i>3;i--,c=0)
    {
        for(j=1;j<11;j++)
        {
            if(stack[i][j]==2)
                c++;
        }
        if(c==10)
        {
            for(j=1;j<11;j++)
            {
                stack[i][j]=-1;
                piece=cstack[i][j];
                cstack[i][j]='g';
            }
        tetris_stack_to_tiles(s,stack);
        tetris_display(s,cstack);
        //tetris_stack_display(stack);
        //tetris_cstack_display(cstack);
            for(j=0;j<300000000;j++);
                for(j=1;j<11;j++)
                {
                    stack[i][j]=2;
                    cstack[i][j]=piece;
                }
            break;
        }
    }
    if(i==3)
        return;
    for(k=i;k>4;k--)
    {
        for(j=1;j<11;j++)
        {
            stack[k][j]=stack[k-1][j];
            stack[k-1][j]=0;
            cstack[k][j]=cstack[k-1][j];
            cstack[k-1][j]=' ';
        }
    }
    (*cleared)++;
    tetris_clear(s,cleared,stack,cstack);
}
void tetris_boundary(char s[55][66],int n1,int n2)
{
    int x1,y1,x2,y2,i,j;
    x1=n1%66;
    y1=n1/66;
    x2=n2%66;
    y2=n2/66;
    for(i=y1;i<=y2;i++)
    {
        for(j=x1;j<=x2;j++)
        {
            if(i==y1||i==y2)
                s[i][j]=205;
            if(j==x1||j==x2)
                s[i][j]=186;
            if(i==y1&&j==x1)
                s[i][j]=201;
            if(i==y1&&j==x2)
                s[i][j]=187;
            if(i==y2&&j==x1)
                s[i][j]=200;
            if(i==y2&&j==x2)
                s[i][j]=188;
        }
    }
}
void tetris()
{
    int stack[24][12]={0};
    char cstack[24][12]={' '};
    char s[55][66]={' '};
    char bag1[7]={'i','z','o','t','s','j','l'};
    char bag2[7]={'z','t','j','l','s','o','i'};
    char bag[14]={' '},held_piece;
    int **numbers;
    int tiles[4];
    char piece,next_piece,wait_piece,move,q;
    int i,j,hold=0,release=0,tile_pos=4,dimensions,orientation=0,no_block=0,bag_top=0,stack_top=-1,r,land=0,flag=0,instant=0,speed=10000,cleared=0,temp=0;
    tetris_boundary(s,23,3629);
    //int e=12;
    //int h1=1+(66*(e)),h2=20+(66*(e+6));
    //tetris_boundary(s,h1,h2);//661 1737
    //tetris_boundary(s,h1+1188,h2+1188);
    tetris_stack_initial(stack,cstack);
    for(;stack_top<19;land=0,instant=0,cleared=temp,no_block=0,instant=0,speed=10000,orientation=0)
    {
        if(!release)
            {tetris_pick_piece(&piece,&next_piece,&bag_top,bag,bag1,bag2);release=0;}
        else
            release=0;
        tetris_dimensions(piece,&dimensions,tiles,&tile_pos);
        numbers=(int**)malloc(dimensions*sizeof(int*));
        for(i=0;i<dimensions;i++)
            numbers[i]=(int*)malloc(dimensions*sizeof(int));
        tetris_orientation(orientation,dimensions,numbers);
        tetris_spawn_piece(dimensions,numbers,tiles,stack,tile_pos,cstack,piece);
        tetris_stack_to_tiles(s,stack);
        tetris_display(s,cstack);
        //tetris_stack_display(stack);
        //tetris_cstack_display(cstack);
        for(i=0;!land;i++)
        {
            if(!((i)%(speed-(1000*cleared))))
            {
                tetris_gravity(dimensions,numbers,tiles,stack,&tile_pos,cstack,piece);
                if(!instant)
                {
                    tetris_stack_to_tiles(s,stack);
                    tetris_display(s,cstack);
                    //tetris_stack_display(stack);
                    //tetris_cstack_display(cstack);
                }
            }
            if(kbhit())
            {
                switch(getch())
                {
                    case 'w':case 72:flag=2;break;
                    case 'a':case 75:move='a';flag=1;break;
                    case 'd':case 77:move='d';flag=1;break;
                    case 's':case 80:instant=1;speed=1;temp=cleared;cleared=0;break;
                    case 32:tetris_hold(tile_pos,numbers,dimensions,tiles,stack,cstack);
                    if(hold==1){wait_piece=piece;piece=held_piece;held_piece=wait_piece;release=1;}
                    else{held_piece=piece;hold=1;release=0;}
                    land=1;no_block=1;continue;break;
                    case 'x':return;
                }
                if(flag==1)
                    tetris_move_piece(move,dimensions,numbers,tiles,stack,&tile_pos,cstack,piece);
                if(flag==2)
                    tetris_rotate(cstack,piece,&orientation,dimensions,numbers,tiles,stack,&tile_pos);
                flag=0;
                tetris_stack_to_tiles(s,stack);
                tetris_display(s,cstack);
                //tetris_stack_display(stack);
                //tetris_cstack_display(cstack);
            }
            land=tetris_check_landing(tile_pos,numbers,dimensions,tiles,stack);
        }
        if(!no_block)
        tetris_piece_block(tile_pos,numbers,dimensions,tiles,stack);
        tetris_clear(s,&cleared,stack,cstack);
        stack_top=tetris_top(stack);
        free(numbers);
    }
}
void main()
{
    for(;;)
    {
        system("cls");
        printf("\n1)Number Guess\n2)Sudoku\n3)Minesweeper\n4)Snake\n5)PacMan\n6)Tetris\n");
        switch(getch())
        {
            case '1':number_guess();getch();break;
            case '2':sudoku();getch();break;
            case '3':minesweeper();getch();break;
            case '4':snake();getch();break;
            case '5':pacman();getch();break;
            case '6':tetris();getch();break;
            default:exit(0);
        }
    }
}
