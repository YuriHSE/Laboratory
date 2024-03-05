#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char input[100];
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);
    
    // Заменяем точку на пробел для разделения слов
    int input_length = strlen(input);
    for (int i = 0; i < input_length; i++) {
        if (input[i] == '.') {
            input[i] = ' ';
        }
    }
    
    char *words[30]; // Объявляем массив указателей на строки
    int count = 0;

    char *token = strtok(input, " "); // Находим первое слово в строке
    while (token != NULL) {
        // Проверяем, содержит ли слово только буквы и цифры
        int valid = 1;
        int token_length = strlen(token);
        for (int j = 0; j < token_length; j++) {
            if (isspace(token[j])) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            words[count] = token; // Сохраняем слово в массив
            count++;
        }
        
        token = strtok(NULL, " "); // Находим следующее слово в строке
    }

    // Выводим слова из массива
    printf("Введённые слова: ");
    for (int i = 0; i < count; i++) {
        printf("%s ", words[i]);
    }
    printf("\nAnswer: ");
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
            printf("(%s) ", words[i]);
          } else {
            printf("%s ", words[i]);
          }
        }
    }

    return 0;
}

