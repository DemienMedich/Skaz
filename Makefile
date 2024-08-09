CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Директории
MAIN_DIR = src
CHRCTR_DIR = $(MAIN_DIR)/characters
INTFC_DIR = $(MAIN_DIR)/interface

# Файлы
SRCS = $(MAIN_DIR)/main.c \
       $(INTFC_DIR)/main_interface.c \
       $(CHRCTR_DIR)/character_menu.c \
       $(CHRCTR_DIR)/select_menu.c \
       $(CHRCTR_DIR)/character_profile.c \
       $(CHRCTR_DIR)/character_new.c \
       $(CHRCTR_DIR)/character_ready.c \
       $(CHRCTR_DIR)/character_utils.c \
       $(CHRCTR_DIR)/character_available.c

OBJS = $(SRCS:.c=.o)

# Цель по умолчанию
all: DD

# Правило сборки
DD: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Правило компиляции объектных файлов
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для форматирования кода
format:
	powershell -Command "Get-ChildItem -Recurse -Include *.c,*.h -File | ForEach-Object { clang-format -i $_FullName }"

# Чистка объектных файлов
clean:
	del /Q src\main.o \
          src\interface\main_interface.o \
          src\characters\character_menu.o \
          src\characters\select_menu.o \
          src\characters\character_profile.o \
          src\characters\character_new.o \
          src\characters\character_ready.o \
          src\characters\character_utils.o \
          src\characters\character_available.o