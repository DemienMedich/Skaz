#include <stdio.h>

#include "character.h"

int characterMenu(void) {
    int choice;

    printf("Выбор героя:\n");
    printf("1 - Выбрать готового\n");
    printf("2 - Создать нового\n");
    printf("3 - Выбрать случайного персонажа\n");
    printf("4 - Создать случайного персонажа\n");   
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Выберите героя:\n");
        break;

    case 2:
        printf("Создаем героя:\n");
        characterList();
        break;

    case 3:
        printf("Ваш персонаж:\n");
        break;

    case 4:
        printf("Назовите вашего персонажа::\n");
        break;
    
    default:
        break;
    }
    return 0;
}