b main
run
call (int)open("/dev/pts/0", 1, 0)
call (int)dup2($1, 1)
call (int)close($1)
layout src