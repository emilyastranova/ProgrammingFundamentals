#include <stdio.h>

int main()
{
    char e[][7] = { {'E','E','E','E','E','E','E'},
                    {'E',' ',' ',' ',' ',' ',' '},                  
                    {'E',' ',' ',' ',' ',' ',' '},
                    {'E','E','E','E','E',' ',' '},
                    {'E',' ',' ',' ',' ',' ',' '},
                    {'E',' ',' ',' ',' ',' ',' '},
                    {'E','E','E','E','E','E','E'},
                  };

int i, j, b;

b = 6;

for (i = 0; i < 7; i++) {
    printf("\n\t\t\t");
    for (j = 0; j < 7; j++)
        printf("%c", e[i][j]);
    printf("\t\t");
    for (j = 0; j < 7; j++)
        printf("%c", e[j][i]);
    printf("\t\t");
    for (j = 6; j >= 0; j--)
        printf("%c", e[i][j]);
    printf("\t\t");
    for (j = 0; j < 7; j++)
        printf("%c", e[j][b]);
    b--; // Have to count backwards instead of using i
    
}

printf("\n\n\n");

}