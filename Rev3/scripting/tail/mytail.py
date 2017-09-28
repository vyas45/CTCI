import sys
import os


def tail_file(fname, nlines):
    if nlines < 1:
        return
    with open(fname) as qfile:
        position = qfile.seek(-1, os.SEEK_END)
        lines = 0
        position = qfile.tell()
        while lines <= nlines and position > 0:
            c = qfile.read(1)
            if c == '\n':
                lines += 1
                if(lines == nlines):
                    break
            position -= 2
            qfile.seek(position)
        sys.stdout.write(qfile.read())

if __name__ == '__main__':
    filename = sys.argv[1]
    nlines = int(sys.argv[2])
    tail_file(filename, nlines)
