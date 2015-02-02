res = 0
for i in xrange(1, 10):
    for j in xrange(22):
        t = i ** j
        if len(str(t)) == j:
            res += 1

print res
