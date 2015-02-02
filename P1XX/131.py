sieve = [0 for i in xrange(1, 1000111)]

for i in xrange(2, 1001):
    if sieve[i] == 0:
        j = i*i
        while j <= 1000 * 1000:
            sieve[j] = i
            j += i

for i in xrange(1, 10):
    print i, sieve[i]

cnt = 0
for n3 in xrange(1, 1000111000111):
    n = n3 * n3 * n3
    x = n + n3 * n3
    t = x*x*x - n*n*n
    if t % (n*n) == 0:
        if t/n/n > 1000 * 1000:
            break
        if sieve[t/n/n] == 0:
            print t/n/n
            cnt += 1

print "cnt = {}".format(cnt)

