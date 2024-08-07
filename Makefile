CC = gcc
CFLAGS = -Wall -Werror -Wextra
MAIN_DIR = src
CHRCTR = src\character
INTFC = src\interface

all: DD

DD: $(MAIN_DIR)\main.c $(INTFC)\main_interface.c $(CHRCTR)\character_menu.c $(CHRCTR)\character_profile.c $(CHRCTR)\character_list.c
	$(CC) $(CFLAGS) -o DD $(MAIN_DIR)\main.c $(INTFC)\main_interface.c $(CHRCTR)\character_menu.c $(CHRCTR)\character_profile.c $(CHRCTR)\character_list.c

format:
	powershell -Command "Get-ChildItem -Recurse -Include *.c,*.h -File | ForEach-Object { clang-format -i $_.FullName }"