#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    s[strlen(s) - 1] = '\0';

    char *token = strtok(s, " ");
    char *words[100];
    int count = 0;
    while (token != NULL) {
        words[count] = token;
        count++;
        token = strtok(NULL, " ");
    }

    words[count - 1][strlen(words[count - 1]) - 1] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(words[i], words[count - 1]) != 0) {            
          int flag = 1;
          for (int j = 0; j < strlen(words[i]); j++) {
            if (words[i][j] >= '0' && words[i][j] <= '9') {
              flag = 0;
              break;
            }
          }
          if (flag) {
            printf("(%s)\n", words[i]);
          } else {
            printf("%s\n", words[i]);
          }
        }
    }

    return 0;
}

