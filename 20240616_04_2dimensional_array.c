#include <stdio.h>

// tic-tac-toe
int main(int argc, char const *argv[])
{
    /**
     * 二维数组初始化，列数是必须给出的，行数可以由编译器来数
     * 每行一个{}, 逗号分隔
     * 最后的逗号可以存在，有古老传统
     * 如果省略，表示补0
     * 也可以用定位(* C99 only)
     */
    int a[][5] = {
        {
            0,
            1,
            2,
            3,
            4,
        },
        {
            2,
            3,
            4,
            5,
            6,
        },
    };

    const int size = 3;
    int board[size][size];
    int i, j;
    int num_of_x, num_of_o;
    int result = -1; // -1 平局, 1:X赢, 0:O赢

    // 读入矩阵
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; i++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    // 检查行
    for (i = 0; i < size && result == -1; i++)
    {
        num_of_x = num_of_o = 0;
        for (j = 0; j < size; j++)
        {
            if (board[i][j] == 1)
            {
                num_of_x++;
            } else {
                num_of_o++;
            }
        }
        if (num_of_o == size)
        {
            result = 0;
        } else if (num_of_x == size) {
            result = 1;
        }
    }

    // 检查列
    if (result == -1)
    {
        for (j = 0; j < size && result == -1; j++)
        {
            num_of_x = num_of_o = 0;
            for (i = 0; i < size; i++)
            {
                if (board[i][j] == 1)
                {
                    num_of_x++;
                } else {
                    num_of_o++;
                }
            }
            if (num_of_o == size)
            {
                result = 0;
            } else if (num_of_x == size) {
                result = 1;
            }
        }
    }

    // 检查正对角线
    if (result == -1)
    {
        num_of_x = num_of_o = 0;
        for (i = 0; i < size; i++)
        {
            if (board[i][i] == 1)
            {
                num_of_x++;
            } else {
                num_of_o++;
            }
        }
        if (num_of_o == size)
        {
            result = 0;
        } else if (num_of_x == size) {
            result = 1;
        }
    }

    // 检查反对角线
    if (result == -1)
    {
        num_of_x = num_of_o = 0;
        for (i = 0; i < size; i++)
        {
            if (board[i][size - i - 1] == 1)
            {
                num_of_x++;
            } else {
                num_of_o++;
            }
        }
        if (num_of_o == size)
        {
            result = 0;
        } else if (num_of_x == size) {
            result = 1;
        }
    }

    /* code */
    return 0;
}
