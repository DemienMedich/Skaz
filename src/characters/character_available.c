#include <stdio.h>
#include "character_utils.h"

#define CHARACTER_USER_LIB_DIR "src/characters/characters_user_lib/"

void handleUserCharacters() {
    Character characters[MAX_CHARACTERS];
    int characterCount = 0;

    printf("Список пользовательских персонажей:\n");

    // Чтение пользовательских персонажей
    readCharactersFromDirectory(CHARACTER_USER_LIB_DIR, characters, &characterCount);

    // Вывод персонажей с нумерацией
    for (int i = 0; i < characterCount; i++) {
        printCharacterInfo(&characters[i], i);
    }

    // Выбор персонажа
    int selectedCharacter = 0;
    printf("Выберите персонажа по номеру: ");
    if (scanf("%d", &selectedCharacter) != 1 || selectedCharacter < 1 || selectedCharacter > characterCount) {
        printf("Неверный выбор!\n");
        return;
    }

    printf("Вы выбрали: %s - %s (%s, %s)\n",
           characters[selectedCharacter - 1].name,
           characters[selectedCharacter - 1].level,
           characters[selectedCharacter - 1].race,
           characters[selectedCharacter - 1].classType);
}