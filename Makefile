# Variabili
CC = g++
CFLAGS = -Wall -Wextra -g
LDFLAGS =

# Nomi dei file
TARGET = execute
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

# Regola di default
all: $(TARGET)

# Compilazione del file eseguibile
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Regola per compilare i file .c in file .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia dei file generati
clean:
	rm -f $(OBJ) $(TARGET)

# Regola per la ricostruzione del programma
rebuild: clean all

# Regola per eseguire il programma
run: $(TARGET)
	./$(TARGET)

# Help message
help:
	@echo "Makefile options:"
	@echo "  make          - Build the executable"
	@echo "  make clean    - Remove object files and executable"
	@echo "  make run      - Run the executable"
	@echo "  make install  - Install the executable"
