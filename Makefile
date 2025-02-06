all: partie1 partie2 partie3 partie4 partie5 partie6


partie1: partie1.c commun.c commun.h
	gcc -o partie1 partie1.c commun.c

test1:
	cat test11.txt | ./partie1
	cat test12.txt | ./partie1
	cat test13.txt | ./partie1



partie2: partie2.c commun.c commun.h
	gcc -o partie2 partie2.c commun.c

test2:
	cat test21.txt | ./partie2
	cat test22.txt | ./partie2
	cat test23.txt | ./partie2
	cat test24.txt | ./partie2
	cat test25.txt | ./partie2
	cat test26.txt | ./partie2
	cat test27.txt | ./partie2
	cat test28.txt | ./partie2



partie3: partie3.c commun.c commun.h
	gcc -o partie3 partie3.c commun.c

test3:
	cat test31.txt | ./partie3
	cat test32.txt | ./partie3
	cat test33.txt | ./partie3


partie4: partie4.c commun.c commun.h
	gcc -o partie4 partie4.c commun.c

test4:
	cat test41.txt | ./partie4
	cat test42.txt | ./partie4
	cat test43.txt | ./partie4



partie5: partie5.c commun.c commun.h
	gcc -o partie5 partie5.c commun.c

test5:
	cat test51.txt | ./partie5
	cat test52.txt | ./partie5
	cat test53.txt | ./partie5
	cat test54.txt | ./partie5

partie6: partie6.c commun.c commun.h
	gcc -o partie6 partie6.c commun.c

clean:
	rm -f partie1 partie2 partie3 partie4 partie5 partie6

