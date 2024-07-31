#include<iostream>
using namespace std;
//#define string n1 = "";
//#define string n2 = "";

char space[3][3] =  {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
string n1;
string n2;
int row;
int coloumn;
char token = 'X';
bool tie = false;
int turn = 0;
void board()
{
    cout<<"  |     |  \n";
    cout<<space[0][0]<<" |  "<<space[0][1]<<"  | "<<space[0][2]<<endl;
    cout<<"__|_____|__\n";
    cout<<"  |     |  \n";
    cout<<space[1][0]<<" |  "<<space[1][1]<<"  | "<<space[1][2]<<endl;
    cout<<"__|_____|__\n";
    cout<<"  |     |  \n";
    cout<<space[2][0]<<" |  "<<space[2][1]<<"  | "<<space[2][2]<<endl;
    cout<<"  |     |  \n";
}


void fillingplaces()
{
    int digit;

    if(token == 'X')
    {
        cout<<n1<<" enter place: ";
        cin>>digit;
    }

    if(token == 'O')
    {
        cout<<n2<<" enter place: ";
        cin>>digit;
    }


    if(digit == 1)
    {
        row = 0;
        coloumn = 0;
    }
    if(digit == 2)
    {
        row = 0;
        coloumn = 1;
    }
    if(digit == 3)
    {
        row = 0;
        coloumn = 2;
    }
    if(digit == 4)
    {
        row = 1;
        coloumn = 0;
    }
    if(digit == 5)
    {
        row = 1;
        coloumn = 1;
    }
    if(digit == 6)
    {
        row = 1;
        coloumn = 2;
    }
    if(digit == 7)
    {
        row = 2;
        coloumn = 0;
    }
    if(digit == 8)
    {
        row = 2;
        coloumn = 1;
    }
    if(digit == 9)
    {
        row = 2;
        coloumn = 2;
    }
    if(digit>9 || digit < 1)
    {
        cout<<"invalid place"<<endl;
    }


    if(turn != 9)
    {
    if(token == 'X' && space[row][coloumn] != 'X' && space[row][coloumn] != 'O')
    {
        space[row][coloumn] = 'X';
        token = 'O';
        turn++;
        cout<<turn<<"------"<<endl;
    }
    else if(token == 'O' && space[row][coloumn] != 'O' && space[row][coloumn] != 'X')
    {
        space[row][coloumn] = 'O';
        token = 'X';
        turn++;
        cout<<turn<<"------"<<endl;
    }

    else
    {
        cout<<"this place is filled press any other digit"<<endl;
        fillingplaces();
    }
    }
    
 //board();
}

bool cuttingline()
{
    //for checking vertical and horizontal places
    for(int i=0; i<3; i++)
    {
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2])
        return true;
        if(space[0][i] == space[1][i] && space[0][i] == space[2][i])
        return true;
    }
    //for checking diagonals
    if(space[0][0] == space[1][1] && space[0][0]== space[2][2] || space[0][2] == space[1][1] && space[0][2] == space[2][0])
    {
        return true;
    }

    //for checking of is there any empty places
    /*for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j] != 'x' || space[i][j] != 'O')
            {
                return false;
            }
        }
    }*/
    if(turn == 9)
    {
        tie = true;
        return true;
    }
    else
    {
        return false;
    }
    
}


int main()
{
    
        cout<<"first player name is "<<endl;
        cin>>n1;
        //getline(cin,n1);
        cout<<"second player name is "<<endl;
        cin>>n2;
        //getline(cin,n2);

        
        while(!cuttingline())
        {
            system("cls");
            board();
            fillingplaces();
            cuttingline();
        }

        if(token == 'X' && tie == false)
        {
            system("cls");
            board();
            cout<<n2<<" wins"<<endl;
        }
        
        if(token == 'O' && tie == false)
        {
            system("cls");
            board();
            cout<<n1<<" wins"<<endl;
        }
        if(tie == true)
        {
            system("cls");
            board();
            cout<<"its a draw"<<endl;
        }
    
    
}


