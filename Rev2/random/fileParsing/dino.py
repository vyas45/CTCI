import math
from  operator import itemgetter

dino = {}
sortedDino = []
g = 9.8

with open('d2.csv','r') as d2:
    for line in d2:
        if "bipedal" in line:
            dline = line
            name = dline.split(",")[0]
            sl = dline.split(",")[1]
            dino[name] = float(sl)


#Open the second file and loop over to see if a dino
#is a bipdeal and compute the speed by formula

with open('d1.csv', 'r') as d1:
    for line in d1:
        lsplit = line.split(",")
        name = lsplit[0]
        legl = lsplit[1]
        #if the dino is a bipdeal then do something
        if name in dino:
            speed = float(((float(dino[name])/float(legl)) - 1) * math.sqrt(float(legl) * g))
            dino[name] = float(speed)


print " BReak "

print dino
print [k for (k, v) in sorted(dino.iteritems(), key = itemgetter(1))]

