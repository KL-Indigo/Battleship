CC = g++
CFLAGS = -Wall -Wextra -Werror -O2 -std=c++11
OBJ =
DEPS =
MAIN = main.o

%.o: %.cpp ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

app: ${MAIN} ${OBJ}
	${CC} -o $@ $^ ${CFLAGS}

.PHONY: clean
clean:
	rm *.o app *.out
