#include<stdio.h>
#define flag '$'
#define esc '@'

void main()
{
    char in[100],out[100];
    int i=0,j=0;
    printf("Enter the Input String : ");
    scanf("%s",in);
    
    out[j++]=flag;//starting of string
    
    while(in[i]!='\0')
    {
        if(in[i]==flag || in[i]==esc)
        {
            out[j++]=flag;
        }

        out[j++]=in[i++];
    }

    out[j++]=flag;//for end of the string

    printf("After Character Stuffing : %s\n",out);
}
