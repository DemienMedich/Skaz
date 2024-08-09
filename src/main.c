#include <stdio.h>
#include "characters/character.h"
#include "interface/interface.h"

int main(void) {
    mainInterface();
    characterMenu();
    characterProfile();
    printf("\tVersion 0.0.4\n");
    return 0;
}