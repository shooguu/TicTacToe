#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char board[] = {' ', ' ', ' ',
                ' ', ' ', ' ',
                ' ', ' ', ' '};


void reset_board()
{
    memset(board, ' ', sizeof(board));
}

int set_as_marked(int position, char user)
{
    if (board[position] == 'X' || board[position] == 'O' || position < 0 || position > 8)
        return -1;
    else if (user == '1')
        board[position] = 'X';
    else
        board[position] = 'O';
    return 0;
}

void print_board()
{
    for (int i = 0; i < 9; ++i)
    {
        printf("%c", board[i]);

        if ((i + 1) % 3 == 0)
        {
            printf("\n");
            if (i != 8)
                printf("---------\n");    
        }
        else
            printf(" | ");
    }
    printf("\n");
}


int check_condition()
{
    
    // Check for vertical
    if (board[0] != ' ' && board[0] == board[1] && board[1] == board[2])
        return 1;
    else if (board[3] != ' ' && board[3] == board[4] && board[4] == board[5])
        return 1;
    else if (board[6] != ' ' && board[6] == board[7] && board[7] == board[8])
        return 1;

    // Check for horizontal
    else if (board[0] != ' ' && board[0] == board[3] && board[3] == board[6])
        return 1;
    else if (board[1] != ' ' && board[1] == board[4] && board[4] == board[7])
        return 1;
    else if (board[2] != ' ' && board[2] == board[5] && board[5] == board[8])
        return 1;

    // Check for diagnals
    else if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8])
        return 1;
    else if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6])
        return 1;
    return 0;
}


int main()
{
    char user_position;
    int position;
    char user = '1';
    bool switch_user = true;

    while (1)
    {
        print_board();

        printf("It's Player %c's turn!\n", user);
        printf("Please enter a space in the board (1 - 9): ");
        scanf("%d", &position);

        if (set_as_marked(position - 1, user) == -1)
        {
            printf("Space is already marked / Invalid space\n");
            switch_user = false;
        }

        if (user == '1' && switch_user)
            user = '2';
        else if (switch_user)
            user = '1';

        switch_user = true;

        if (check_condition())
        {
            printf("Player %c has won!\n", user);
            print_board();
            reset_board();
        }
    }

    return 0;
}
