#include <stdio.h>
char v[10];
int len = 0;
void sum(char c[], char k[], int l)
{
    char o[10], r[10];
    int i, j, m = 0;
    for (i = l - 1; i >= 0; i--)
    {
        if (c[i] == '0' && k[i] == '0' && m == 0)
        {
            v[i] = '0';
            m = 0;
        }
        else if (((c[i] == '1' && k[i] == '0') || (c[i] == '0' && k[i] == '1')) && m == 1)
        {
            v[i] = '0';
            m = 1;
        }
        else if (((c[i] == '0' && k[i] == '1') || (c[i] == '1' && k[i] == '0')) && m == 0)
        {
            v[i] = '1';
            m = 0;
        }
        else if (c[i] == '1' && k[i] == '1' && m == 1)
        {
            v[i] = '1';
            m = 1;
        }
        else if (c[i] == '0' && k[i] == '0' && m == 1)
        {
            v[i] = '1';
            m = 0;
        }
        else if (c[i] == '1' && k[i] == '1' && m == 0)
        {
            v[i] = '0';
            m = 1;
        }
    }
    if (m == 1)
    {
        for (i = 0; i < l - 1; i++)
            o[i] = '0';
        o[i] = '1';
        i++;
        o[i] = '\0';
        sum(v, o, l);
    }
}
void main()
{
    char m[100], c[10], cs[10];
    int i, j, k, l, ln = 0;
    printf("enter your Str: ");
    scanf("%s",m);
    printf("enter len of each block: ");
    scanf("%d", &l);
    for (j = 0; m[j] != '\0'; j++)
        ln++;
    k = 0;
    for (i = 0; i < l; i++)
        v[i] = '0';
    v[i] = '\0';
    j = 0;
    while (m[j] != '\0')
    {
        for (k = 0; k < l; k++)
        {
            c[k] = m[j];
            j++;
        }
        c[k] = '\0';
        sum(c, v, l);
    }
    for (i = 0; i < l; i++)
        if (v[i] == '0')
            cs[i] = '1';
        else
            cs[i] = '0';
    cs[i] = '\0';
    printf("Checksum is %s\n", cs);
    sum(cs, v, l);
    printf("Final : %s\n", v);
}
