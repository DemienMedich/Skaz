#include <stdio.h>

#include "character.h"

int characterMenu(void) {
    int choice;

    printf("Выбор героя:\n");
    printf("1 - Создать нового.\n");
    printf("2 - Выбрать готового.\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Создаем героя.\n");
        break;

    case 2:
        printf("Выберите героя\n");
        characterList();
        break;
    
    default:
        break;
    }
    return 0;
}