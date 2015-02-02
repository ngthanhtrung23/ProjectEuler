import math

D = 661
for y in xrange(1, 1000111000):
    x = round(math.sqrt(D*y*y + 1), 0)
    if x*x == D*y*y+1:
        print x
        break
