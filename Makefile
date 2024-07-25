CC = gcc
CFLAGS = -Wall -Werror -Wextra
MAIN_DIR = src
CH = src\Character

all: DD

DD: $(MAIN_DIR)\main.c $(CH)\character_profile.c $(CH)\character_menu.c
	$(CC) $(CFLAGS) -o DD $(MAIN_DIR)\main.c $(CH)\character_profile.c $(CH)\character_menu.c

format:
	powershell -Command "Get-ChildItem -Recurse -Include *.c,*.h -File | ForEach-Object { clang-format -i $_.FullName }"