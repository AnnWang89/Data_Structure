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
void push(int,int);
void showthepath();
element pop();
int top=-1;
int shorttop=top;
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
    push(1,1);
    maze[1][1]=-1;
    int r=0,c=0;
    element backroad;
    while(top!=-1)
    {
        backroad=pop();
        r=backroad.row;
        c=backroad.col;
        for(int i=0;i<8;i++)
        {
            if( maze[r+Dir[i].vert][c+Dir[i].horiz] < maze[r][c]-1 || maze[r+Dir[i].vert][c+Dir[i].horiz]==0)
            {
                push(r+Dir[i].vert,c+Dir[i].horiz);
                maze[r+Dir[i].vert][c+Dir[i].horiz] = maze[r][c]-1;
            }
        }
    }

    r=row;
    c=col;
    push(r,c);
    //cout <<"top"<<top<<endl;
    //cout <<"maze[row-1][col-1]"<<maze[row][col]<<endl;
    while(top<(-maze[row][col])-1)
    {
        //cout <<"top"<<top<<endl;

        for(int i=0;i<8;i++)
        {
            if(maze[r+Dir[i].vert][c+Dir[i].horiz]==maze[r][c]+1)
            {
                r=r+Dir[i].vert;
                c=c+Dir[i].horiz;
                push(r,c);
                //cout <<"top"<<top<<endl;
                break;
            }
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
    //element path;
    //cout <<"top"<<top;
    /*
    while(top>0)
    {
        path=pop();
        cout <<"top"<<top;
        //cout << path.row << " " << path.col <<endl;
    }
    path=pop();
    cout << path.row << " " << path.col ;
    */

    showthepath();
    return 0;
}
void push(int row,int col)
{
    movepath[++top].row=row;
    movepath[top].col=col;

}
element pop()
{
    return movepath[top--];
}
void showthepath()
{
    element path;
    while(top>0)
    {
        path=pop();
        cout << path.row << " " << path.col <<endl;
    }
    path=pop();
    cout << path.row << " " << path.col ;
}
/******************************************************
#include <iostream>
#define MAX_TERM 100
using namespace std;
typedef struct {
    int row;
    int col;
}element;
typedef struct{
    int ver;
    int hor;
}offset;
offset direction[8];
element stackstack[MAX_TERM];
int top = -1;
void push(int,int);
element pop();
int main()
{
    direction[0].hor=-1;
    direction[0].ver=-1;
    direction[1].hor=-1;
    direction[1].ver=0;
    direction[2].hor=-1;
    direction[2].ver=1;
    direction[3].hor=0;
    direction[3].ver=-1;
    direction[4].hor=0;
    direction[4].ver=1;
    direction[5].hor=1;
    direction[5].ver=-1;
    direction[6].hor=1;
    direction[6].ver=0;
    direction[7].hor=1;
    direction[7].ver=1;
    int row,col;
    cin >> row >> col;
    int maze[row+2][col+2];
    for(int i=0;i<row+2;i++)
    {
        for(int j=0;j<col+2;j++)
        {
            maze[i][j]=1;
        }
    }
    for(int i=1;i<row+1;i++)
    {
        for(int j=1;j<col+1;j++)
        {
            cin >> maze[i][j];
        }
    }
    push(1,1);
    maze[1][1]=-1;
    element road;
    while(top>=0)
    {
        for(int i=0;i<8;i++)
        {
            if( maze[road.row+direction[i].ver][road.col+direction[i].hor]==0 || maze[road.row+direction[i].ver][road.col+direction[i].hor] < (maze[road.row][road.col]-1))
            {
                maze[road.row+direction[i].ver][road.col+direction[i].hor] = maze[road.row][road.col]-1;
                push(road.row+direction[i].ver,road.col+direction[i].hor);
            }
        }
    }
    push(row,col);
    road.col=col;
    road.row=row;
    for(int i = maze[row][col]-1;i<0;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(maze[road.row+direction[j].ver][road.col+direction[j].hor] == i)
            {
                 push(road.row+direction[j].ver,road.col+direction[j].hor);
                 road.col=road.col+direction[j].hor;
                 road.row=road.row+direction[j].ver;
                 break;
            }
        }
    }
    while(top!=-1)
    {
        road = pop();
        cout << road.row << " " << road.col;
        if(top!=-1)
            cout <<endl;
    }
    return 0;
}
void push(int row_1,int col_1)
{
    stackstack[++top].col=col_1;
    stackstack[top].row=row_1;
}
element pop()
{
    return stackstack[top--];
}
************************************************/
