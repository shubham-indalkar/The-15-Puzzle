/*15 Puzzle game by Andrio*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

/*int new_game_ary[4][4]={01,4,15,7,
                        8,10,2,11,
                        14,3,6,13,
                        12,9,5,16};*/

int ary[4][4];

int new_game_ary[4][4]={1,2,3,4,
                        5,6,7,8,
                        9,10,11,16,
                        13,14,15,12};


void read_update_array();
void save_array_to_file();
void new_game();
void print_start_screen();
void handle_menu(int mp);


void arrowWhere(int realPos, int arrowPos);
int menu();

void save_record();
void print_matrix(void);
int get_scancode(void);
int checkMatrix(void);
void gotoxy(int x, int y);

void move_right(void);
void move_left(void);
void move_up(void);
void move_dn(void);
int get_position();

int pos,turns;

void main(void)
{
    int a,sc,menu_position;
    system("cls");
    print_start_screen();
    menu_position = menu();

    handle_menu(menu_position);

    read_update_array();
    print_matrix();
    pos = get_position();

    //printf("Position = %d\n",pos);

    do
    {
        a = checkMatrix();
        gotoxy(60,10);
            printf("%d turns", turns);
        if(a == 1){
            gotoxy(25,17);
            printf("       !!!  CONGRATS  !!!  \n");
        }
        else

         {
            gotoxy(0,8);
            printf("Move        - Arrow keys\nNew game    - 'n'\nSave n quit - 's'\nMain Menu   - 'm'\nQuit        - 'q'\n");


           }


            sc = get_scancode();
            switch(sc)
            {
            case 72:
                        move_dn();
                        turns++;
                        break;
            case 75:
                        move_right();
                        turns++;

                        break;
            case 77:
                        move_left();
                        turns++;

                        break;
            case 80:
                        move_up();
                        turns++;

                        break;
            case 's':
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t  Saving Game!");
                        printf("\n\n\t\t\t\t  Please Wait...");
                        for(int del=1;del<=20000;del++)
                            for(int ay=1;ay<=20000;ay++)
                            {}
                        system("cls");
                        save_array_to_file();
                        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t   Game Saved ");
                        printf("\n\t\t\t\t       \2 ");
                        printf("\n\t\t\t\t    Quiting");
                        for(int del=1;del<=15000;del++)
                            for(int ay=1;ay<=15000;ay++)
                            {}
                        exit(0);
                        break;
            case 'n':
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tLoading New Game!");
                        printf("\n\n\t\t\t\t  Please Wait...");
                        for(int del=1;del<=20000;del++)
                            for(int ay=1;ay<=20000;ay++)
                            {}
                        system("cls");
                        new_game();
                        //save_array_to_file();
                        break;


            case 'q':
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t    Exiting :(");
                        printf("\n\n\t\t\t\t   See You Soon");
                        for(int del=1;del<=20000;del++)
                            for(int ay=1;ay<=20000;ay++)
                            {}
                        exit(0);

            case 'm':
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tTaking You Back");
                        for(int del=1;del<=20000;del++)
                            for(int ay=1;ay<=20000;ay++)
                            {}
                        system("cls");
                        print_start_screen();
                        menu_position = menu();
                        handle_menu(menu_position);

            }


    }while(a != 1);
    fflush(stdout);
    printf("\n");
    gotoxy(36,19);
    printf("  You WON\n");
    getch();
    save_record();


}

void save_record()
{
    FILE *fp;
    char ch,name[20];
    time_t mytime;
    mytime = time(NULL);
    system("cls");
    gotoxy(5,10);
    printf("\t\t Press 'y' to save your Record & any other key to Exit\n");
    ch = getch();
    if(ch == 'y')
    {
        printf("Enter Your Name \n");
        scanf("%s",&name);
        fp = fopen("record.txt","a");
        fprintf(fp,"\n\n\tName : %s  \tTurns : %d \tDate : %s\n",name,turns,ctime(&mytime));
        fclose(fp);
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t    Exiting :(");
    printf("\n\n\t\t\t\t   See You Soon");
    for(int del=1;del<=20000;del++)
    for(int ay=1;ay<=20000;ay++)
    {}
    exit(0);

}


void print_matrix(void)
{
    int j;
    gotoxy(5,1);
    printf("\t      *****************************************************\n");
    printf("\t      *              Welcome to 15 Puzzle game            *\n");
    printf("\t      *****************************************************\n\n");

    //printf("\n----|----|----|----|\n");
    printf("\n");
    gotoxy(30,5);
    printf("|----|----|----|----|");
    printf("\n");
    gotoxy(30,6);
    printf("|");

    for(j= 0; j < 4; j++)
        if(ary[0][j]<10)
        {
           if(ary[0][j] == 16)
                printf("    |");
            else
                printf(" 0%d |",ary[0][j]);
        }
        else
        {
            if(ary[0][j] == 16)
                printf("    |");
            else
                printf(" %d |",ary[0][j]);
        }


//    printf("\n----|----|----|----|\n");
    printf("\n");
    gotoxy(30,7);
    printf("|----|----|----|----|");
    printf("\n");
    gotoxy(30,8);
    printf("|");

    for(j= 0; j < 4; j++)
        if(ary[1][j]<10)
        {
           if(ary[1][j] == 16)
                printf("    |");
            else
                printf(" 0%d |",ary[1][j]);
        }
        else
        {
            if(ary[1][j] == 16)
                printf("    |");
            else
                printf(" %d |",ary[1][j]);
        }

//    printf("\n----|----|----|----|\n");
    printf("\n");
    gotoxy(30,9);
    printf("|----|----|----|----|");
    printf("\n");
    gotoxy(30,10);
    printf("|");

    for(j= 0; j < 4; j++)
        if(ary[2][j]<10)
        {
           if(ary[2][j] == 16)
                printf("    |");
            else
                printf(" 0%d |",ary[2][j]);
        }
        else
        {
            if(ary[2][j] == 16)
                printf("    |");
            else
                printf(" %d |",ary[2][j]);
        }


//    printf("\n----|----|----|----|\n");
    printf("\n");
    gotoxy(30,11);
    printf("|----|----|----|----|");
    printf("\n");
    gotoxy(30,12);
    printf("|");


    for(j= 0; j < 4; j++)
        if(ary[3][j]<10)
        {
           if(ary[3][j] == 16)
                printf("    |");
            else
                printf(" 0%d |",ary[3][j]);
        }
        else
        {
            if(ary[3][j] == 16)
                printf("    |");
            else
                printf(" %d |",ary[3][j]);
        }

//    printf("\n----|----|----|----|\n");
    printf("\n");
    gotoxy(30,13);
    printf("|----|----|----|----|");
    printf("\n");
    printf("\n");
    printf("\n");
    //gotoxy(30,9);



}

void move_up(void)
{
    int row,col,new_data;
    if(pos > 3)
    {
        row = pos / 4;
        col = pos % 4;
        new_data = ary[row - 1][col];
        ary[row][col] = new_data;
        ary[row-1][col] = 16;
        pos = ((row-1)*4)+col;
        print_matrix();
    }

}

void move_dn(void)
{
    int row,col,new_data;
    if(pos < 12)
    {
        row = pos / 4;
        col = pos % 4;
        new_data = ary[row + 1][col];
        ary[row][col] = new_data;
        ary[row+1][col] = 16;
        pos = ((row+1)*4)+col;
        print_matrix();
    }

}

void move_left(void)
{
    int row,col,new_data;

    row = pos / 4;
    col = pos % 4;
    if(col > 0)
    {
        new_data = ary[row][col-1];
        ary[row][col] = new_data;
        ary[row][col-1] = 16;
        pos = (row*4)+(col-1);
        print_matrix();
    }

}
void move_right(void)
{
    int row,col,new_data;

    row = pos / 4;
    col = pos % 4;
    if(col < 3)
    {
        new_data = ary[row][col+1];
        ary[row][col] = new_data;
        ary[row][col+1] = 16;
        pos = (row*4)+(col+1);
        print_matrix();
    }

}

int get_scancode()
{
    int i;
    i=getch();
    if(i==0||i==224)
        i=getch();
    return i;
}

int checkMatrix(void)
{
    int r,c;

{

        for(r=0;r<4;r++){
            for(c=0;c<4;c++){
                if(c < 3)
                {
                  if(ary[r][c] > ary[r][c+1])
                        return 0;
                }
                else
                {
                    if(r != 3)
                    {

                      if(ary[r][c] > ary[r+1][0])
                        return 0;
                    }
                }
            }


        }
            return 1;


}
}


void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
//fflush(stdout);
/*void printToCoordinates(int x, int y, const char *format)
{
    va_list args;
    va_start(args, format);
    printf("\033[%d;%dH", x, y);
    vprintf(format, args);
    va_end(args);

}*/

void read_update_array()
{
    FILE *fp;
    int n, i,j;
    fp=fopen("ary.txt", "r");
    if(fp==NULL){
        //printf("File missing\n");
        fp=fopen("ary.txt", "w");
        new_game();
    }

    else
    {

 /*       i = 0; j = 0;
       while(fscanf(fp,"%d\n",&n)!= EOF)
        {

            ary[i][j]=n;
            j++;
            if(j == 4)
            {
                i++;
                j = 0;
            }

        }
        fclose(fp);*/

       for(i = 0; i < 4; i++)
        {
            for(j=0;j<4;j++)
            {
                fscanf(fp,"%d\n",&ary[i][j]);
            }
        }
        fscanf(fp,"%d\n",&turns);
        fclose(fp);

    }

}
void save_array_to_file()
{
    FILE *fp;
    int n, i,j;
    fp=fopen("ary.txt", "w");
    if(fp==NULL)
        printf("File missing\n");
    else
    {
        //printf("Now reading an array and updating the file\n");
        for(i = 0; i < 4; i++)
        {
            for(j=0;j<4;j++)
            {
                fprintf(fp,"%d\n",ary[i][j]);
            }
        }
        fprintf(fp,"%d\n",turns);
        fclose(fp);
    }
}

void new_game()
{
    turns = 0;

                            for(int i = 0; i < 4; i++){
                            for(int j =0;j < 4; j++){
                                ary[i][j] = new_game_ary[i][j];
                            }
                        }
                        print_matrix();
                        save_array_to_file();


}

int get_position()
{
    int pos= 0;
    for(int i = 0; i < 4; i++){
       for(int j =0;j < 4; j++){
           if(ary[i][j] != 16)
                pos++;
           else
                return pos;

       }
    }
    return -1;

}


void print_start_screen()
{
    system("cls");
    gotoxy(5,1);
    printf("\t      *****************************************************\n");
    printf("\t      *                 Welcome to 15 Puzzle              *\n");
    printf("\t      *****************************************************\n\n");
    printf("\t                    Use Arrow Keys To Navigate \n ");
    printf("\t                      SpaceBar Key To Select \n\n");

}

int menu()
{
    int position=0;
    int keyPressed=0;
    int x;

    gotoxy(31,8);  printf(" * New Game\n\n");
    gotoxy(31,10); printf(" * Continue Saved Game\n\n");
    gotoxy(31,12); printf(" * View Previous Records\n\n");
    gotoxy(31,14); printf(" * About\n\n");
    gotoxy(31,16); printf(" * Exit\n\n");

    gotoxy(28,8);arrowWhere(0,position);
    gotoxy(28,10);arrowWhere(1,position);
    gotoxy(28,12);arrowWhere(2,position);
    gotoxy(28,14);arrowWhere(3,position);
    gotoxy(28,16);arrowWhere(4,position);

    gotoxy(31,8);

    do
    {
    keyPressed=get_scancode();

    if(keyPressed == 80 && position==4)
        position = 4;
    else if(keyPressed==72 && position==0)
        position = 0;
    else
        switch(keyPressed)
    {
        case 80:    position++;
                    gotoxy(28,8);arrowWhere(0,position);
                    gotoxy(28,10);arrowWhere(1,position);
                    gotoxy(28,12);arrowWhere(2,position);
                    gotoxy(28,14);arrowWhere(3,position);
                    gotoxy(28,16);arrowWhere(4,position);

                    break;

        case 72:    position--;
                    gotoxy(28,8);arrowWhere(0,position);
                    gotoxy(28,10);arrowWhere(1,position);
                    gotoxy(28,12);arrowWhere(2,position);
                    gotoxy(28,14);arrowWhere(3,position);
                    gotoxy(28,16);arrowWhere(4,position);

                    break;


    }

    }while(keyPressed != ' ');

    return position;

}

void arrowWhere(int realPos, int arrowPos)
{
    if(realPos== arrowPos)
        printf("--> ");
    else
        printf("    ");
}

void handle_menu(int mp)
{
    FILE *fp;
    char ch;
    system("cls");

    switch(mp)
    {
    case 0:
            system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    Loading...");
                        for(int del=1;del<=20000;del++)
                            for(int ay=1;ay<=20000;ay++)
                            {}
                system("cls");
            new_game();

            break;
    case 1:
            system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    Loading...");
                        for(int del=1;del<=20000;del++)
                            for(int ay=1;ay<=20000;ay++)
                            {}
                system("cls");
            //save_array_to_file();

            break;
    case 2:
            gotoxy(5,1);
            printf("\t      *****************************************************\n");
            printf("\t      *              Welcome to 15 Puzzle game            *\n");
            printf("\t      *****************************************************\n\n");

            fp= fopen("record.txt","r");
            if(fp == NULL){
            printf("\t\n\n\n\n                                 No Records Found                  \n\n");
            }
            else
            {

                while(ch != EOF)
                {
                    printf("%c",ch = fgetc(fp));
                }
                fclose(fp);
            }
            printf("\t                  !!! Press Any key For Menu !!!            \n");
            getch();
            print_start_screen();
            handle_menu(menu());


            break;
    case 3:
            gotoxy(5,1);
            printf("\t      *****************************************************\n");
            printf("\t      *              Welcome to 15 Puzzle game            *\n");
            printf("\t      *****************************************************\n\n");
            printf("\t                          Game Developed              \n");
            printf("\t                                by                \n");
            printf("\t                              Andrio             \n");
            printf("\t                          Version : 1.0                 \n");
            printf("\t                      Release Date : 22/08/19            \n\n");
            printf("\t                   !!! Press Any key For Menu !!!                        \n");
            printf("\t      *****************************************************\n\n");
            getch();
            print_start_screen();
            handle_menu(menu());

            break;
    case 4:
            exit(0);
            break;
    }

}

