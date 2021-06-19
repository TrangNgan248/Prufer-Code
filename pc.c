#include <stdio.h>
int main()
{
    FILE *f;
    int i, j, h, k, m, e, v;
    int a[100][100];
    int deg[100];
    for (i = 0; i < 100; i++)
        deg[i] = 0;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            a[i][j] = 0;
    f = fopen("prufer.txt", "r");
    fscanf(f, "%d\n", &e);
    printf("e = %d\n", e);
    v = e + 1; // vertex = edge + 1
    for (i = 0; i < e; i++)
    {
        fscanf(f, "%d%d\n", &h, &k);
        a[h][k] = 1;
        a[k][h] = 1;
        deg[h]++;
        deg[k]++;
    }
    fclose(f);
    int count = 0;
     do
    {
        for (i = 0; i < e+1; i++)
        {
            if (deg[i] == 1)
            {
                for (j = 0; j < e+1; j++)
                {
                    if (a[i][j] == 1)
                    {
                        printf("%4d", j);
                        count++;
                        deg[i]--;
                        deg[j]--;
                        a[i][j] = 0;
                        a[j][i] = 0;
                      goto TEST;
                    }
              
                }
             
            }
         
        }
        TEST : k = 0;
    } while (count != e -1);
}