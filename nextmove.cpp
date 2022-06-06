#include <iostream>
using namespace std;

struct Move
{
    int row;
    int col;
};

char player = 'x';
char opponent = 'o';

bool isMovesLeft(char space[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (space[i][j]=='_')
                return true;
    //if there is
    return false;
}



int evaluate(char b[3][3])
{
    // Checking for Rows for X or O victory.
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] &&
            b[row][1]==b[row][2])
        {
            if (b[row][0]==player)
                return +10;
            else if (b[row][0]==opponent)
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] &&
            b[1][col]==b[2][col])
        {
            if (b[0][col]==player)
                return +10;

            else if (b[0][col]==opponent)
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==player)
            return +10;
        else if (b[0][0]==opponent)
            return -10;
    }

    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==player)
            return +10;
        else if (b[0][2]==opponent)
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the entire board for the player
int minimax(char space[3][3], int depth, bool isMax)
{
    int score = evaluate(space);

    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;

    // If there are no more moves and no winner then
    // it is a tie
    if (isMovesLeft(space)==false)
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (space[i][j]=='_')
                {
                    // Make the move
                    space[i][j] = player;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = max( best,
                                minimax(space, depth+1, !isMax) );

                    // Undo the move
                    space[i][j] = '_';
                }
            }
        }
        return best;
    }

        // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (space[i][j]=='_')
                {
                    // Make the move
                    space[i][j] = opponent;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                               minimax(space, depth+1, !isMax));

                    // Undo the move
                    space[i][j] = '_';
                }
            }
        }
        return best;
    }
}

// This will return the best possible move for the player
Move findBestMove(char space[3][3])
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            // Check if cell is empty
            if (space[i][j]=='_')
            {
                // Make the move
                space[i][j] = player;

                // compute evaluation function for this
                // move.
                int moveVal = minimax(space, 0, false);

                // Undo the move
                space[i][j] = '_';

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    printf("The value of the best Move is : %d\n\n",
           bestVal);

    return bestMove;
}

// Driver code
int main()
{
    cout<<"Please input the value ('x', 'o', or '_' at each space) \n";

    char space1;
    printf("What was the value of space 1?: ");
    scanf("%s", &space1);
    printf("Space 1 reads: %s\n", &space1);
    (space1 != NULL);
    char space2;
    printf("What was the value of space 2?: ");
    scanf("%s", &space2);
    printf("Space 2 reads: %s\n", &space2);
    (space2 != NULL);
    char space3;
    printf("What was the value of space 3?: ");
    scanf("%s", &space3);
    printf("Space 3 reads: %s\n", &space3);
    (space3 != NULL);
    char space4;
    printf("What was the value of space 4?: ");
    scanf("%s", &space4);
    printf("Space 4 reads: %s\n", &space4);
    (space4 != NULL);
    char space5;
    printf("What was the value of space 5?: ");
    scanf("%s", &space5);
    printf("Space 5 reads: %s\n", &space5);
    (space5 != NULL);
    char space6;
    printf("What was the value of space 6?: ");
    scanf("%s", &space6);
    printf("Space 6 reads: %s\n", &space6);
    (space6 != NULL);
    char space7;
    printf("What was the value of space 7?: ");
    scanf("%s", &space7);
    printf("Space 7 reads: %s\n", &space7);
    (space7 != NULL);
    char space8;
    printf("What was the value of space 8?: ");
    scanf("%s", &space8);
    printf("Space 8 reads: %s\n", &space8);
    (space8 != NULL);
    char space9;
    printf("What was the value of space 9?: ");
    scanf("%s", &space9);
    printf("Space 9 reads: %s\n", &space9);
    (space9 != NULL);

    char space[3][3]={{space1, space2, space3},
                      {space4, space5, space6},
                      {space7, space8, space9}};

    cout<< "     |     |     \n";
    cout<< "  "<<space[0][0]<<"  |  " <<space[0][1]<<   "  |  "<<space[0][2]<<"  \n";
    cout<< "_____|_____|_____\n";
    cout<< "     |     |     \n";
    cout<< "  "<<space[1][0]<<"  |  " <<space[1][1]<<   "  |  "<<space[1][2]<<"  \n";
    cout<< "_____|_____|_____\n";
    cout<< "     |     |     \n";
    cout<< "  "<<space[2][0]<<"  |  " <<space[2][1]<<   "  |  "<<space[2][2]<<"  \n";
    cout<< "     |     |     \n";
    cout<< "                 \n";
    cout<< "                 \n";


    Move bestMove = findBestMove(space);
    printf("The Optimal Move is :\n\n");
    printf("ROW: %d COL: %d\n\n", bestMove.row,
           bestMove.col );
    return 0;
}
