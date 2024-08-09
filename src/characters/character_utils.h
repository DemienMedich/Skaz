#ifndef CHARACTER_UTILS_H
#define CHARACTER_UTILS_H

#include <dirent.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILENAME_LENGTH 256
#define MAX_CHARACTERS 100

void handleStandardCharacters();
void handleUserCharacters();

typedef struct {
    char name[MAX_LINE_LENGTH];
    char level[MAX_LINE_LENGTH];
    char race[MAX_LINE_LENGTH];
    char classType[MAX_LINE_LENGTH];
} Character;

void printCharacterInfo(Character *character, int index);
void readCharactersFromDirectory(const char *directory, Character characters[], int *count);

#endif