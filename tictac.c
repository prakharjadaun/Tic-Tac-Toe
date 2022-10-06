//header files
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/*----------------------------------------------------------------function declaration--------------------------------------------------*/
void displayName( char name[30],int num);
void matrixShow(char arr[3][3]);
int checkChar(char arr[3][3],char ch);
int checkFill(char arr[3][3]);
void insertSymbol(char arr[3][3],char n, char ch );
int checkWin(char arr[3][3],char ch);
void rulesOfGame();

/*-------------------------------------------------------------------main function----------------------------------------------------*/
int main()
{
    char name1[30],name2[30];
    int i,j;
    
    rulesOfGame();

    printf("\n\nNow enter your names : \n");

    printf("Enter the name of the player 1 : ");
    fgets(name1,30,stdin);
    printf("Enter the name of the player 2 : ");
    fgets(name2,30,stdin);

    displayName(name1,1);
    displayName(name2,2);

    char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    printf("The format of the Tic Tac Toe is :");
    matrixShow(a);

    int m=0;
    char box1;
    char box2;
    int z=1;
    int k=0;
        printf("\nChance of %s  ",name1);
        printf("\nInput the number where you have to insert '*' : ");
        scanf("%c",&box1);
        insertSymbol(a,box1,'*');
        matrixShow(a);
        
        
        e1:
        printf("\n\nchance of %s \n",name2);
        printf("Input the number where you have to insert 'O' : ");
        while(getchar()!='\n');
        scanf("%c",&box2);
        int e=checkChar(a,box2);
        if(e==1)
        {
            printf("That place is already assigned. Enter again!\n");
            goto e1;
        }
        insertSymbol(a,box2,'O');
        matrixShow(a);
       
    while(z)
    {
        k=checkFill(a);
        if(k==1)
        {
            goto l3;
        }
        printf("\nChance of %s  ",name1);
        enter1 :
        printf("\nInput the number where you have to insert '*' : ");
        while(getchar()!='\n');
        scanf("%c",&box1);
        m=checkChar(a,box1);
        if(m==1)
        {
            printf("That place is already assigned. Enter again!\n");
            goto enter1;
        }
        insertSymbol(a,box1,'*');
        matrixShow(a);
        z=checkWin(a,'*');
        if(z==0)
        {
            goto l1;
        }

        k=checkFill(a);
        if(k==1)
        {
            goto l3;
        }
        printf("\n\nchance of %s \n",name2);
        enter2:
        printf("Input the number where you have to insert 'O' : ");
        while(getchar()!='\n');
        scanf("%c",&box2);
        m=checkChar(a,box2);
        if(m==1)
        {
            printf("That place is already assigned. Enter again!\n");
            goto enter2;
        }
        insertSymbol(a,box2,'O');
        matrixShow(a);
        z=checkWin(a,'O');
        if(z==0)
        {
            goto l2;
        }

        k=checkFill(a);
        if(k==1)
        {
            goto l3;
        }
    }
    l1:
    {
        printf("\n\t\t\t\tCongratulations %s",name1);
        printf("\t\t\t\tYou have won the game!");
        return 0;
    }

    l2: 
    {
       printf("\n\t\t\t\tCongratulations %s",name2);
       printf("\t\t\t\tYou have won the game!");
        return 0;
    }

    l3:
    printf("\nOOPs no one won. Better Luck next time!");
    return 0;
}  

/*------------------------------------------------------------------function definitions----------------------------------------------*/
//function to print the rules of game
void rulesOfGame()
{
    printf("\n\n \t\t\t\t\t\tGAME BEGINS!\n");
    printf("\n\t\t\tRules Of the Games :\n\n");
    printf("  1. Player one will have the first chance and the chances will be followed accordingly.");
    printf("\n  2. You wil be shown an example of the boxes and their numbers. You have to enter the number  of that box in which you want your sign! ");
    printf("\n  3. Player 1 will have '*' symbol and player 2 will have 'O' symbol.");
    printf("\n  4. You should not enter a value where a symbol has been inserted before!");
}


//to display the name of the players
void displayName( char name[30],int num)
{
    printf("Player %d : %s",num, name);
}


//to display the matrix  
void matrixShow(char arr[3][3])
{
    printf("\n\t\t\t\t");
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if(j==2)
            printf(" %c ",arr[i][j]);
            else
            {
                printf(" %c |",arr[i][j]);
            }
            
        }
       if(i==2) 
       printf("\n\t\t\t\t");
       else
       {
           printf("\n\t\t\t\t-----------\n\t\t\t\t");
       }
       
    }
}

//to insert the character passed
void insertSymbol(char arr[3][3],char n, char ch )
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(n==arr[i][j])
            {
                arr[i][j]=ch;
            }
        }
    }
}

int  checkChar(char arr[3][3],char ch)
{
    char b[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(b[i][j]==ch)
            {
                if((arr[i][j]=='*')||(arr[i][j]=='O'))
                return 1;
            }
        }
    }
    return 0;
}

//check if all the boxes have been filled
int checkFill(char arr[3][3])
{
    int count=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if((arr[i][j]=='*')||(arr[i][j]=='O'))
            {
                count++;
            }
        }
    }
    if(count==9)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

//to check if the three boxes have been filled
int checkWin(char arr[3][3],char ch)
{
    if((arr[0][0]==ch)&&(arr[1][1]==ch)&&(arr[2][2]==ch))
    {
        return 0;
    }
    if((arr[0][2]==ch)&&(arr[1][1]==ch)&&(arr[2][0]==ch))
    {
        return 0;
    }
    
    for(int i=0;i<3;i++)
    {
        if((arr[i][0]==ch)&&(arr[i][1]==ch)&&(arr[i][2]==ch))
        return 0;   
    }
    for(int i=0;i<3;i++)
    {
        if((arr[0][i]==ch)&&(arr[1][i]==ch)&&(arr[2][i]==ch))
        return 0;
    }
    return 1;
}