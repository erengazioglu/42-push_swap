b solver_sort.c:69
run
call (int)open("/dev/pts/5", 1, 0)
call (int)dup2($1, 1)
call (int)close($1)
p ps(state, 0)
layout src