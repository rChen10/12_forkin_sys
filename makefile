forkfile: fork.c
	gcc fork.c -o forkfile
run: forkfile
	./forkfile