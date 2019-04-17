#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int     main(int argc, char **argv)
{
    int ret;
    char input[1];
    char symbol[2];
    int i;
    int j;
    int k;
    int length;

    length = 0;
    i = 0;
    while ((ret = read(0, input, 1)) && input[0] != '\n')
    {
        if (input[0] >='0' && input[0] <= '9')
            length = length *  10 + input[0] - '0';
        else
            symbol[i] = input[0];
    }
    printf("%i", length);
    /*matrix = (char**)malloc(sizeof(char*) * 8);
    j = 0;
    k = 0;
    matrix[j] = (char*)malloc(sizeof(char) * x);
    while (ret)
    {
        index_b = 0;
        while (buf2[index_b])
        {
            matrix[index_y][index_x] = buf2[index_b];
            index_x++;
            if (index_x == x )
            {
                matrix[index_y][index_x] = ‘\0’;
                index_x = 0;
                index_y++;
                matrix[index_y] = (char*)malloc(sizeof(char) * x);
            }
            index_b++;
        }
        ret = read(fd, buf2, 1);
    }
    matrix[index_y] = 0;
    return (matrix);*/
    return (0);
}