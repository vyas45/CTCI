#Obfuscate all the email addresses inside a file
import re
import sys


def obfs_email(fname):
    regmail = re.compile(r'[\w\.-]+@[\w\.-]+')
    with open(fname) as qfile:
        mails = re.findall(regmail, qfile.read())
    print mails

if __name__ == '__main__':
    fname = sys.argv[1]
    obfs_email(fname)
