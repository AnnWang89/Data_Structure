#include <iostream>
#define MAX_TERM 100
using namespace std;

typedef struct{//8 direction
    int vert;
    int horiz;
    int dir;
}offsets;
typedef struct{//the road it walk
    int row;
    int col;
    int dir;
}element;
void push(int,int,int);
void showthepath();
element pop();
int top=-1;
offsets Dir[8];
element movepath[MAX_TERM];
//the move of dir
int main()
{
    int row,col;
    for(int i=0;i<8;i++)
    {
        Dir[i].dir=i;
    }
    Dir[0].vert=1;//SE
    Dir[0].horiz=1;
    Dir[1].vert=0;//E
    Dir[1].horiz=1;
    Dir[2].vert=1;//S
    Dir[2].horiz=0;
    Dir[3].vert=-1;//NE
    Dir[3].horiz=1;
    Dir[4].vert=1;//SW
    Dir[4].horiz=-1;
    Dir[5].vert=-1;//N
    Dir[5].horiz=0;
    Dir[6].vert=0;//W
    Dir[6].horiz=-1;
    Dir[7].vert=-1;//NW
    Dir[7].horiz=-1;
    cin >> row >> col ;
    int maze[row+2][col+2]={};//surround the maze by a border of ones
    for(int i = 0;i < row+2;i++)
    {
        for(int j = 0;j < col+2;j++)//surround the maze by a border of ones
        {
            maze[i][j]=1;
        }
    }
    for(int i = 1;i < row+1;i++)
    {
        for(int j = 1;j < col+1;j++)
        {
            cin >> maze[i][j];//input the maze
        }
    }
    //show the maze

    element backroad;
    int r=1,c=1,d=0;//r=row,c=col,d=dir
    while(1)
    {
        maze[r][c]=2;
        if(r == row && c == col )
        {
            //cout <<"Find the road\n";
            push(r,c,0);
            break;
        }
        for(int i=d;i<8;i++)
        {
            if( maze[r+Dir[i].vert][c+Dir[i].horiz] == 0)
            {
                push(r,c,i);
                r+=Dir[i].vert;
                c+=Dir[i].horiz;
                d=0;
                break;
            }
            if(i==7)
            {
                backroad=pop();
                d=backroad.dir;
                r=backroad.row;
                c=backroad.col;
            }
        }

        if(top==-1&& maze[1][2]!=0 && maze[2][1]!=0 && maze[2][2]!=0 )
        {
            //cout <<"Can't find the road\n";
            break;
        }
    }
    /*
    for(int i = 0;i < row+2;i++)
    {
        for(int j = 0;j < col+2;j++)
        {
            cout << maze[i][j] <<" ";//input the maze
        }
        cout << endl;
    }
    */
    showthepath();
    return 0;
}
void push(int row,int col,int dir)
{
    movepath[++top].row=row;
    movepath[top].col=col;
    movepath[top].dir=dir;
}
element pop()
{
    return movepath[top--];
}
void showthepath()
{
    for(int i=0; i<top ;i++)
    {
        cout << movepath[i].row << " " << movepath[i].col <<endl;
    }
    cout << movepath[top].row << " " << movepath[top].col ;
}
