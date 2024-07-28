#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_OPTION_LENGTH 50
#define MAX_OPTIONS 10

int characterList(void) {
    FILE *file, *outputFile;
    char filename[] = "src/character/base_character_info/the_hero_template.txt";
    char outputFilename[] = "src/character/character_lib/character_new.txt"; // Файл для записи выбора пользователя
    char line[MAX_LINE_LENGTH];
    char options[MAX_OPTIONS][MAX_OPTION_LENGTH];
    int numOptions = 0;
    char choice[MAX_OPTION_LENGTH];

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

    while (fgets(line, sizeof(line), file)!= NULL) {
        // Разберем строку на варианты
        char *token = strtok(line, ":;, \n");
        printf("%s: ", token);
        token = strtok(NULL, ":;, \n");
        while (token!= NULL && numOptions < MAX_OPTIONS) {
            strcpy(options[numOptions], token);
            printf("%s, ", options[numOptions]);
            token = strtok(NULL, ":;, \n");
            numOptions++;
        }
        printf("\n");

        // Предложим пользователю выбрать один из вариантов
        printf("Выберите один из вариантов: ");
        for (int i = 0; i < numOptions; i++) {
            printf("%d - %s, ", i + 1, options[i]);
        }
        printf("\n");
        int choiceNum;
        scanf("%d", &choiceNum);
        if (choiceNum >= 1 && choiceNum <= numOptions) {
            strcpy(choice, options[choiceNum - 1]);
        } else {
            printf("Недопустимый выбор. Будет выбран первый вариант.\n");
            strcpy(choice, options[0]);
        }

        // Запишем выбор пользователя в файл
        fprintf(outputFile, "%s: %s\n", strtok(line, ":;, \n"), choice);

        // Сбросим количество вариантов и очистим массив вариантов
        numOptions = 0;
        for (int i = 0; i < MAX_OPTIONS; i++) {
            options[i][0] = '\0';
        }
    }

    fclose(file);
    fclose(outputFile);

    return 0;
}