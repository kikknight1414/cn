#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main() {
char ip[16], temp[16], flag = 0;
printf("Enter the IP Address : ");
scanf("%s", ip);
int n = strlen(ip);
int x = 0, y = 0;
while (ip[x] != '.') temp[y++] = ip[x++];
if (atoi(temp) > 0 && atoi(temp) < 128) {
printf("\nIP Address belongs to Class A \n");
} else if (atoi(temp) > 127 && atoi(temp) < 192) {
printf("\nIP Address belongs to Class B \n");
y = 0;
temp[y++] = ip[x++];
while (ip[x] != '.') temp[y++] = ip[x++];
} else if (atoi(temp) > 191 && atoi(temp) < 224) {
printf("\nIP Address belongs to Class C \n");
y = 0;
temp[y++] = ip[x++];
while (ip[x] != '.') temp[y++] = ip[x++];
temp[y++] = ip[x++];
while (ip[x] != '.') temp[y++] = ip[x++];
} else {
printf("\nIP Address belongs to Class D/E \n");
flag = 1;
}
temp[x++] = '\0';
if (flag == 0) {
printf("\nNetwork ID : %s\n", temp);
printf("\nHost ID : ");
while (ip[x] != '\0') printf("%c", ip[x++]);
printf("\n\n");
}
}
