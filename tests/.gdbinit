b solve
run
call (int)open("/dev/pts/1", 1, 0)
call (int)dup2($1, 1)
call (int)close($1)
layout src