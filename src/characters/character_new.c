#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_OPTION_LENGTH 50
#define MAX_OPTIONS 10
#define CHARACTER_DIR "src/characters/characters_user_lib/"

int getNextCharacterNumber() {
    DIR *dir;
    struct dirent *entry;
    int maxNumber = 0;

    dir = opendir(CHARACTER_DIR);
    if (dir == NULL) {
        perror("Не удалось открыть директорию");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            int num;
            if (sscanf(entry->d_name, "%d.txt", &num) == 1) {
                if (num > maxNumber) {
                    maxNumber = num;
                }
            }
        }
    }

    closedir(dir);
    return maxNumber + 1;
}

int isNumeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

int characterNew(void) {
    FILE *file, *outputFile;
    char filename[] = "src/characters/base_characters_info/the_hero_template.txt"; // Файл опций
    char outputFilename[MAX_LINE_LENGTH]; // Файл для записи выбора пользователя
    char characterName[MAX_OPTION_LENGTH];
    int characterNumber = getNextCharacterNumber();
    char line[MAX_LINE_LENGTH];
    char options[MAX_OPTIONS][MAX_OPTION_LENGTH];
    int numOptions = 0;
    char choice[MAX_OPTION_LENGTH];

    // Создание имени файла на основе номера персонажа
    snprintf(outputFilename, sizeof(outputFilename), "src/characters/characters_user_lib/%d.txt", characterNumber);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Не удалось открыть файл");
        return 1;
    }

    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        perror("Не удалось открыть файл для записи");
        fclose(file);
        return 1;
    }

    printf("Введите имя персонажа [ENG]: ");
    scanf("%s", characterName);

    // Запись имени персонажа в начало файла
    fprintf(outputFile, "Имя персонажа: %s\n", characterName);

    // Добавляем уровень персонажа на новой строке
    fprintf(outputFile, "Уровень: 1\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, ":;, \n");
        char key[MAX_OPTION_LENGTH];
        if (token != NULL) {
            strcpy(key, token);
            printf("%s: ", key);
        }
        token = strtok(NULL, ":;, \n");
        while (token != NULL && numOptions < MAX_OPTIONS) {
            strcpy(options[numOptions], token);
            printf("%s, ", options[numOptions]);
            token = strtok(NULL, ":;, \n");
            numOptions++;
        }
        printf("\n");

        int choiceNum;
        while (1) {
            printf("Выберите один из вариантов:\n");
            for (int i = 0; i < numOptions; i++) {
                printf("%d - %s\n", i + 1, options[i]);
            }
            printf("\n");

            char input[MAX_OPTION_LENGTH];
            scanf("%s", input);

            if (isNumeric(input)) {
                choiceNum = atoi(input);
                if (choiceNum >= 1 && choiceNum <= numOptions) {
                    strcpy(choice, options[choiceNum - 1]);
                    break;
                } else {
                    printf("Недопустимый выбор. Пожалуйста, выберите число от 1 до %d.\n", numOptions);
                }
            } else {
                printf("Ошибка: ввод должен быть числом. Пожалуйста, попробуйте снова.\n");
            }
        }

        fprintf(outputFile, "%s: %s\n", key, choice);

        numOptions = 0;
        for (int i = 0; i < MAX_OPTIONS; i++) {
            options[i][0] = '\0';
        }
    }

    fclose(file);
    fclose(outputFile);

    return 0;
}