import math
from  operator import itemgetter

dino = {}
g = 9.8

with open("d2.csv", "r") as d1:
    for line in d1:
        if "bipedal" in line:
            bidino = line.split(",")
            name = bidino[0]
            sl = float(bidino[1])
            dino[name] = sl

print dino

with open("d1.csv", "r") as d1:
    for line in d1:
        dint  = line.split(",")
        name = dint[0]
        legl = dint[1]
        if name in dino:
            speed = float(((float(dino[name])/float(legl)) - 1) * math.sqrt(float(legl) * g))
            dino[name] = speed

print dino

print [k for (k,v) in sorted(dino.iteritems(), key = itemgetter(1))]

