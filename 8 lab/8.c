#include <stdio.h>
#include <string.h>
struct Person {
    char surname[50];
    char name[50];
    char patronymic[50];
    char specialty[50];
    int score;
    int ranking;
    int document_flag;
};

void addRecord() {
    FILE *file2 = fopen("persons.dat", "ab+");
    struct Person person;
    printf("Введите фамилию: ");
    scanf("%s", person.surname);
    printf("Введите имя: ");
    scanf("%s", person.name);
    printf("Введите отчество: ");
    scanf("%s", person.patronymic);
    printf("Введите специальность: ");
    fgets(person.specialty, sizeof(person.specialty), stdin);
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Введите сумму баллов: ");
    scanf("%d", &person.score);
    printf("Введите номер в рейтинге: ");
    scanf("%d", &person.ranking);
    printf("Введите признак сдачи документа (0 - не сдал, 1 - сдал): ");
    scanf("%d", &person.document_flag);
    
    fwrite(&person, sizeof(struct Person), 1, file2);
    fclose(file2);
}

void displayPersons() {
    FILE* file = fopen("persons.dat", "rb");
    struct Person person;
    printf("\n%-10s %-10s %-10s %-30s %-15s %-15s %-20s\n", "Фамилия", "Имя", "Отчество", "Специальность", "Сумма баллов", "Номер в рейтинге", "Признак сдачи документа");
    while (fread(&person, sizeof(struct Person), 1, file)) {
        printf("\n%-10s %-10s %-10s %-30s %-15d %-15d %-20s\n", person.surname, person.name, person.patronymic, person.specialty, person.score, person.ranking, (person.document_flag == 1) ? "Сдал" : "Не сдал");
    }
    printf("\n");
}

void searchRecord(FILE* file, const char* searchName) {
    struct Person person;
    int found = 0;
    rewind(file);
    while (fread(&person, sizeof(struct Person), 1, file)) {
        if (strcmp(person.name, searchName) == 0) {
            found = 1;
            printf("\n%-30s %-30s %-30s %-30s %-15s %-15s %-20s\n", "Фамилия", "Имя", "Отчество", "Специальность", "Сумма баллов", "Номер в рейтинге", "Признак сдачи документа");
            printf("\n%-10s %-10s %-10s %-30s %-15d %-15d %-20s\n", person.surname, person.name, person.patronymic, person.specialty, person.score, person.ranking, (person.document_flag == 1) ? "Сдал" : "Не сдал");
            break;
        }
    }
    if (!found) {
        printf("Запись не найдена.\n");
    }
}

void deleteRecord(FILE* file, const char* deleteName) {
    FILE* tempFile = fopen("temp.dat", "wb");
    struct Person person;
    int found = 0;
    rewind(file);
    while (fread(&person, sizeof(struct Person), 1, file)) {
        if (strcmp(person.name, deleteName) != 0) {
            fwrite(&person, sizeof(struct Person), 1, tempFile);
        } else {
            found = 1;
        }
    }
    fclose(file);
    fclose(tempFile);
    remove("persons.dat");
    rename("temp.dat", "persons.dat");
    if (!found) {
        printf("Запись не найдена.\n");
    } else {
        printf("Запись успешно удалена.\n");
    }
}


void editRecord(const char* filename) {
    FILE* file = fopen(filename, "r+b");

    if (file == NULL) {
        fprintf(stderr, "Не удалось открыть файл\n");
        return;
    }

    char search_surname[50];
    char search_name[50];
    char search_patronymic[50];

    // Получаем от пользователя данные для поиска записи
    printf("Введите фамилию: ");
    scanf("%s", search_surname);
    printf("Введите имя: ");
    scanf("%s", search_name);
    printf("Введите отчество: ");
    scanf("%s", search_patronymic);

    struct Person person;

    // Ищем запись с соответствующими данными
    while (fread(&person, sizeof(struct Person), 1, file)) {
        if (strcmp(person.surname, search_surname) == 0 && strcmp(person.name, search_name) == 0 && strcmp(person.patronymic, search_patronymic) == 0) {
            // Найдена запись, выводим её на экран
            printf("Найдена запись:\n");
            printf("Фамилия: %s\n", person.surname);
            printf("Имя: %s\n", person.name);
            printf("Отчество: %s\n", person.patronymic);
            printf("Специальность: %s\n", person.specialty);
            printf("Сумма баллов: %d\n", person.score);
            printf("Номер в рейтинге: %d\n", person.ranking);
            printf("Сдал(а) документы: %s\n", person.document_flag ? "Сдал" : "Не сдал");
            
            // Получаем от пользователя данные для редактирования
            printf("Что вы хотите отредактировать?\n");
            printf("1 - Специальность\n");
            printf("2 - Сумму баллов\n");
            printf("3 - Номер в рейтинге\n");
            printf("4 - Сдал(а) документы\n");
            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Введите новую специальность: ");
                    scanf("%s", person.specialty);
                    break;

                case 2:
                    printf("Введите новую сумму баллов: ");
                    scanf("%d", &person.score);
                    break;

                case 3:
                    printf("Введите новый номер в рейтинге: ");
                    scanf("%d", &person.ranking);
                    break;

                case 4:
                    printf("Сдал(а) документы (1 - Сдал, 0 - Не сдал): ");
                    scanf("%d", &person.document_flag);
                    break;

                default:
                    printf("Некорректный выбор\n");
                    break;
            }

            // Возвращаем указатель в файле на местоположение записи
            fseek(file, -sizeof(struct Person), SEEK_CUR);

            // Записываем измененную запись обратно в файл
            fwrite(&person, sizeof(struct Person), 1, file);

            printf("Запись успешно отредактирована\n");
            fclose(file);
            return;
        }
    }

    printf("Запись не найдена\n");
    fclose(file);
}

int add_array() {
    FILE *file = fopen("persons.dat", "ab");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 0;
    }

    struct Person persons[] = {
        {"Иванов", "Иван", "Иванович", "Информатика", 85, 1, 1},
        {"Петров", "Петр", "Петрович", "Экономика", 78, 2, 0}
    };

    int num = sizeof(persons) / sizeof(persons[0]);

    for (int i = 0; i < num; i++) {
        fwrite(&persons[i], sizeof(struct Person), 1, file); // записываем каждую запись из массива в файл
    }

    fclose(file);
    return 0;
}

int main() {
    FILE* file = fopen("persons.dat", "ab+");
    
    int choice, expression;
    char searchName[50];
    char deleteName[50];

    do {
        printf("\nМеню:\n1. Добавить запись\n2. Показать все записи\n3. Найти запись\n4. Удалить запись\n5. Редактировать запись\n6. Выход\nВведите ваш выбор: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("1. Добавить запись вручную\n2. Из заранее заготовленного массива\nВведите ваш выбор: ");
                scanf("%d", &expression);
                switch (expression)
                {
                case 1:
                    addRecord();
                    break;
                case 2:
                    add_array();
                    break;
                default:
                    break;
                }
                break;
            case 2:
                displayPersons();
                break;
            case 3:
                printf("Введите имя для поиска: ");
                scanf("%s", searchName);
                searchRecord(file, searchName);
                break;
            case 4:
                printf("Введите имя для удаления: ");
                scanf("%s", deleteName);
                deleteRecord(file, deleteName);
                break;
            case 5:
                editRecord("persons.dat");
                break;
            case 6:
                break;
            default:
                printf("Неверный выбор.\n");
        }
    } while (choice != 6);
    
    fclose(file);
    return 0;
}