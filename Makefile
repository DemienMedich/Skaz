CC = gcc
CFLAGS = -Wall -Werror -Wextra
MAIN_DIR = src
CH = src\character
INT = interface

all: DD

DD: $(MAIN_DIR)\main.c $(INT)\main_interface.c $(CH)\character_menu.c $(CH)\character_profile.c
	$(CC) $(CFLAGS) -o DD $(MAIN_DIR)\main.c $(INT)\main_interface.c $(CH)\character_menu.c $(CH)\character_profile.c

format:
	powershell -Command "Get-ChildItem -Recurse -Include *.c,*.h -File | ForEach-Object { clang-format -i $_.FullName }"