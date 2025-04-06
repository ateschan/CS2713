bin: main.o logic.o ncurses_helper.o
	gcc *.o -o out -ltinfo -lncurses

main: main.o
	gcc -march=native -Wall -Wextra-c -g main.c -ltinfo -lncurses

logic: logic.o
	gcc -march=native -Wall -Wextra-c -g logic.c 

ncurses: ncurses_helper.o
	gcc -march=native -Wall -Wextra -c -g ncurses_helper.c -ltinfo -lncurses

clean: 
	rm -f *.o
