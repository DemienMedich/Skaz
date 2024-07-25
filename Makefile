CC = gcc
CFLAGS = -Wall -Werror -Wextra
MAIN_DIR = src

all: DD

DD: $(MAIN_DIR)\main.c $(MAIN_DIR)\Character\character_profile.c
	$(CC) $(CFLAGS) -o DD $(MAIN_DIR)\main.c $(MAIN_DIR)\Character\character_profile.c

format:
	powershell -Command "Get-ChildItem -Recurse -Include *.c,*.h -File | ForEach-Object { clang-format -i $_.FullName }"