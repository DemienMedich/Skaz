#include <stdio.h>

#include "character.h"

int characterMenu(void) {
    int choice;

    printf("Выбор героя:\n");
    printf("1 - Выбрать готового.\n");
    printf("2 - Создать нового.\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Выберите героя\n");
        break;

    case 2:
        printf("Создаем героя.\n");
        characterList();
        break;
    
    default:
        break;
    }
    return 0;
}