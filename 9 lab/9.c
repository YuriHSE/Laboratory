// 25 вариант
// Выбором
// Вставками
// *Пузырьком*
// *Шейкер*
// Слиянием
// Быстрая
// *Пирамидальная*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    scanf("%s", person.specialty);
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
    FILE *file = fopen("persons.dat", "rb");
    struct Person person;
    printf("\n%-10s %-10s %-10s %-30s %-15s %-15s %-20s\n", "Фамилия", "Имя", "Отчество", "Специальность", "Сумма баллов", "Номер в рейтинге", "Признак сдачи документа");
    while (fread(&person, sizeof(struct Person), 1, file)) {
        printf("\n%-10s %-10s %-10s %-30s %-15d %-15d %-20s\n", person.surname, person.name, person.patronymic, person.specialty, person.score, person.ranking, (person.document_flag == 1) ? "Сдал" : "Не сдал");
    }
    fclose(file);
    printf("\n");
}

void searchRecord(FILE *file, const char *searchName) {
    struct Person person;
    int found = 0;
    rewind(file);
    while (fread(&person, sizeof(struct Person), 1, file)) {
        if (strcmp(person.name, searchName) == 0) {
            found = 1;
            printf("\n%-10s %-10s %-10s %-30s %-15s %-15s %-20s\n", "Фамилия", "Имя", "Отчество", "Специальность", "Сумма баллов", "Номер в рейтинге", "Признак сдачи документа");
            printf("\n%-10s %-10s %-10s %-30s %-15d %-15d %-20s\n", person.surname, person.name, person.patronymic, person.specialty, person.score, person.ranking, (person.document_flag == 1) ? "Сдал" : "Не сдал");
            break;
        }
    }
    if (!found) {
        printf("Запись не найдена.\n");
    }
}

void deleteRecord(FILE *file, const char *deleteName) {
    FILE *tempFile = fopen("temp.dat", "wb");
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

void editRecord(const char *filename) {
    FILE *file = fopen(filename, "r+b");
    if (file == NULL) {
        fprintf(stderr, "Не удалось открыть файл\n");
        return;
    }

    char search_surname[50];
    char search_name[50];
    char search_patronymic[50];

    printf("Введите фамилию: ");
    scanf("%s", search_surname);
    printf("Введите имя: ");
    scanf("%s", search_name);
    printf("Введите отчество: ");
    scanf("%s", search_patronymic);

    struct Person person;
    while (fread(&person, sizeof(struct Person), 1, file)) {
        if (strcmp(person.surname, search_surname) == 0 && strcmp(person.name, search_name) == 0 && strcmp(person.patronymic, search_patronymic) == 0) {
            printf("Найдена запись:\n");
            printf("Фамилия: %s\n", person.surname);
            printf("Имя: %s\n", person.name);
            printf("Отчество: %s\n", person.patronymic);
            printf("Специальность: %s\n", person.specialty);
            printf("Сумма баллов: %d\n", person.score);
            printf("Номер в рейтинге: %d\n", person.ranking);
            printf("Сдал(а) документы: %s\n", person.document_flag ? "Сдал" : "Не сдал");

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

            fseek(file, -sizeof(struct Person), SEEK_CUR);
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
        fwrite(&persons[i], sizeof(struct Person), 1, file);
    }

    fclose(file);
    return 0;
}

void bubbleSort(struct Person arr[], int n, int dir) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((dir && arr[j].score > arr[j + 1].score) || (!dir && arr[j].score < arr[j + 1].score)) {
                struct Person temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void shakerSort(struct Person arr[], int n, int dir) {
    int left = 0, right = n - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if ((dir && arr[i].score > arr[i + 1].score) || (!dir && arr[i].score < arr[i + 1].score)) {
                struct Person temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if ((dir && arr[i].score < arr[i - 1].score) || (!dir && arr[i].score > arr[i - 1].score)) {
                struct Person temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
        left++;
    }
}

void heapify(struct Person arr[], int n, int i, int dir) {
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Если левый дочерний элемент больше корня
    if (left < n && ((dir && arr[left].score > arr[largest].score) || (!dir && arr[left].score < arr[largest].score))) {
        largest = left;
    }

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (right < n && ((dir && arr[right].score > arr[largest].score) || (!dir && arr[right].score < arr[largest].score))) {
        largest = right;
    }

    // Если самый большой элемент не корень
    if (largest != i) {
        struct Person temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest, dir);
    }
}

void heapSort(struct Person arr[], int n, int dir) {
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, dir);
    }

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        struct Person temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0, dir);
    }
}


int readData(struct Person arr[]) {
    FILE *file = fopen("persons.dat", "rb");
    int count = 0;
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 0;
    }
    while (fread(&arr[count], sizeof(struct Person), 1, file)) {
        count++;
    }
    fclose(file);
    return count;
}

void writeData(struct Person arr[], int count) {
    FILE *file = fopen("persons.dat", "wb");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }
    for (int i = 0; i < count; i++) {
        fwrite(&arr[i], sizeof(struct Person), 1, file);
    }
    fclose(file);
}


void measureSortTime(void (*sortFunc)(struct Person[], int, int), struct Person arr[], int n, int dir, const char *sortName) {
    struct Person *tempArr = malloc(n * sizeof(struct Person));
    memcpy(tempArr, arr, n * sizeof(struct Person));
    clock_t start = clock();
    sortFunc(tempArr, n, dir);
    clock_t end = clock();
    free(tempArr);
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s сортировка для %d элементов заняла %f секунд\n", sortName, n, time_spent);
}


int main() {
    FILE *file = fopen("persons.dat", "ab+");
    if (file == NULL) {
        perror("Ошибка открытия файла persons.dat");
        return 1;
    }

    int choice, expression, sortChoice, sortOrder;
    char searchName[50];
    char deleteName[50];
    struct Person persons[100];
    int count = 0;

    do {
        printf("\nМеню:\n1. Добавить запись\n2. Показать все записи\n3. Найти запись\n4. Удалить запись\n5. Редактировать запись\n6. Сравнить время сортировок\n7. Сортировка\n8. Выход\nВведите ваш выбор: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("1. Добавить запись вручную\n2. Из заранее заготовленного массива\nВведите ваш выбор: ");
                scanf("%d", &expression);
                switch (expression) {
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
                {      
                    int sizes[] = {100, 1000, 5000, 10000, 20000, 50000, 100000};
                    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
                    clock_t start, end;
                    double cpu_time_used;

                    for (int i = 0; i < num_sizes; i++) {
                        int size = sizes[i];
                        struct Person persons[size];

                        // Считываем записи из файла persons.dat
                        rewind(file);
                        fread(persons, sizeof(struct Person), size, file);

                        // Измеряем время сортировки пузырьком
                        start = clock();
                        bubbleSort(persons, size, 1); // Сортировка по неубыванию
                        end = clock();
                        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                        printf("Время сортировки пузырьком для %d записей: %.6f секунд\n", size, cpu_time_used);

                        // Измеряем время сортировки шейкером
                        start = clock();
                        shakerSort(persons, size, 1); // Сортировка по неубыванию
                        end = clock();
                        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                        printf("Время сортировки шейкером для %d записей: %.6f секунд\n", size, cpu_time_used);

                        // Измеряем время сортировки пузырьком
                        start = clock();
                        heapSort(persons, size, 1); // Сортировка по неубыванию
                        end = clock();
                        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                        printf("Время сортировки пирамидальная для %d записей: %.6f секунд\n", size, cpu_time_used);
                    }
                }
                break;

            case 7:
                count = readData(persons);
                if (count == 0) {
                    printf("Нет записей для сортировки.\n");
                    break;
                }
                printf("Выберите метод сортировки:\n1. Пузырьком\n2. Шейкерная\n3. Пирамидальная\nВведите ваш выбор: ");
                scanf("%d", &sortChoice);
                printf("Выберите порядок сортировки:\n1. По неубыванию\n2. По невозрастанию\nВведите ваш выбор: ");
                scanf("%d", &sortOrder);
                int dir = (sortOrder == 1);

                switch (sortChoice) {
                    case 1:
                        bubbleSort(persons, count, dir);
                        break;
                    case 2:
                        shakerSort(persons, count, dir);
                        break;
                    case 3:
                        heapSort(persons, count, dir);
                        break;
                    default:
                        printf("Некорректный выбор\n");
                        break;
                }
                writeData(persons, count);
                printf("Сортировка выполнена.\n");
                break;
            case 8:
                break;
            default:
                printf("Неверный выбор.\n");
        }
    } while (choice != 8);

    fclose(file);
    return 0;
}
