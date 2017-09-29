#Count the number of words in the file and sort them based on occurances
import sys
from  operator import itemgetter

words = {}

def countAndSort(fname):
    with open(fname) as qfile:
        readLines = qfile.read()
        word_list = readLines.split()
        for word in word_list:
            if word in words:
                words[word] = int(words[word]) + 1
            else:
                words[word] = 1
    print words
    print [k for (k,v) in sorted(words.iteritems(), key=itemgetter(1), reverse=True)]


if __name__ == '__main__':
    fname = sys.argv[1]
    countAndSort(fname)
