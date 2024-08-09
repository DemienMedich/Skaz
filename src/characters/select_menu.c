#include <stdio.h>

#include "character.h"
#include "character_utils.h"

int selectMenu(void) {
    int choice;

    printf("Выбор героя:\n");
    printf("1 - Выбрать из стандартных\n");
    printf("2 - Выбрать из пользовательских\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Выберите героя:\n");
        handleStandardCharacters();
        break;

    case 2:
        printf("Выберите героя:\n");
        handleUserCharacters();
        break;
    
    default:
        break;
    }
    return 0;
}