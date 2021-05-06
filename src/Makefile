CC=g++
CFLAGS=-std=c++17 -Wall -Wextra
EXEC=./tp3
TMPOUT=tp3.testresult

$(EXEC): TipoNo.cpp TipoPalavra.cpp arvoreBinariaDeCriptografia.cpp main.cpp
	$(CC) $(CFLAGS) TipoNo.cpp TipoPalavra.cpp arvoreBinariaDeCriptografia.cpp main.cpp -o $(EXEC)

clean:
	rm tp3
