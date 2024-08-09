#include <stdio.h>
#include "character/character.h"
#include "interface/interface.h"

int main(void) {
    mainInterface();
    characterMenu();
    characterProfile();
    printf("\tVersion 0.0.3\n");
    return 0;
}