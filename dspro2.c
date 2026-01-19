#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[100], pat[100], rep[100], ans[200];
    int i, j, k, c, m, flag = 0;

    printf("enter the string \n");
    gets(str);

    printf("enter the pattern string\n");
    gets(pat);

    printf("enter the rep string\n");
    gets(rep);

    i = m = c = j = 0;

    while (str[c] != '\0') {
        if (str[m] == pat[i]) {
            i++;
            m++;
            if (pat[i] == '\0') {
                flag = 1;
                for (k = 0; rep[k] != '\0'; k++, j++) {
                    ans[j] = rep[k];
                }
                i = 0;
                c = m;
            }
        } else {
            ans[j++] = str[c++];
            m = c;
            i = 0;
        }
    }

    ans[j] = '\0';

    if (flag == 0)
        printf("pattern not found");
    else
        printf("resultant string %s", ans);

    return 0;
}
