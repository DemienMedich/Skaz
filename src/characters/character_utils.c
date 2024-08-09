#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character_utils.h"

void printCharacterInfo(Character *character, int index) {
    printf("%d. %s - %s (%s, %s)\n", index + 1, character->name, character->level, character->race, character->classType);
}

void readCharactersFromDirectory(const char *directory, Character characters[], int *count) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(directory);
    if (dir == NULL) {
        perror("Не удалось открыть директорию");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG && *count < MAX_CHARACTERS) {
            char filePath[MAX_FILENAME_LENGTH];
            snprintf(filePath, sizeof(filePath), "%s%s", directory, entry->d_name);

            FILE *file = fopen(filePath, "r");
            if (file == NULL) {
                perror("Не удалось открыть файл");
                continue;
            }

            Character character = {0};
            char line[MAX_LINE_LENGTH];

            while (fgets(line, sizeof(line), file)) {
                if (strncmp(line, "Имя персонажа:", 14) == 0) {
                    sscanf(line, "Имя персонажа: %[^\n]", character.name);
                } else if (strncmp(line, "Уровень:", 8) == 0) {
                    sscanf(line, "Уровень: %[^\n]", character.level);
                } else if (strncmp(line, "Раса:", 5) == 0) {
                    sscanf(line, "Раса: %[^\n]", character.race);
                } else if (strncmp(line, "Класс:", 6) == 0) {
                    sscanf(line, "Класс: %[^\n]", character.classType);
                }
            }

            fclose(file);

            if (character.name[0] != '\0' && character.level[0] != '\0' && character.race[0] != '\0' && character.classType[0] != '\0') {
                characters[*count] = character;
                (*count)++;
            }
        }
    }

    closedir(dir);
}