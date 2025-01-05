# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -O2

# Каталоги
BIN_DIR = bin
OBJ_DIR = $(BIN_DIR)/obj

# Исходные файлы и заголовки
SRC = testcmp.cpp mycomplex.cpp
HEADERS = mycomplex.h

# Объектные файлы
OBJ = $(OBJ_DIR)/testcmp.o $(OBJ_DIR)/mycomplex.o

# Итоговый исполняемый файл
TARGET = $(BIN_DIR)/program.exe

# Сборка всех целей
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Сборка объектных файлов
$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	del /q $(OBJ_DIR)\*.o $(TARGET)
