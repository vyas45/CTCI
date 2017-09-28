#Obfuscate all the email addresses inside a file
import re
import sys

def emailWorker(fname):
    mailReg = re.compile(r'([\w\.-]+)@([\w\.-]+)')
    with open(fname) as f:
        fread = f.read()
        print re.findall(mailReg, fread)


fname =  sys.argv[1]

emailWorker(fname)
