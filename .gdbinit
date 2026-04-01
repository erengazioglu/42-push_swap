b main
python
with open("/dev/tty", "r") as tty:
    import sys
    sys.stdout.write("Enter TTY number: ")
    sys.stdout.flush()
    ttyno = tty.readline().strip()
tty_path = "/dev/pts/" + ttyno
gdb.execute("set inferior-tty " + tty_path)
gdb.execute("break main")
gdb.execute("layout src")
gdb.execute("run")
gdb.execute('call (int)open("' + tty_path + '", 1, 0)')
gdb.execute('call (int)dup2($1, 1)')
gdb.execute('call (int)close($1)')
end
layout src