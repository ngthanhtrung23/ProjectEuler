import math

fibo = [0 for x in xrange(50)]
fibo[1] = 1
fibo[2] = 2
for i in xrange(3, 50):
    fibo[i] = fibo[i-1] + fibo[i-2]

cnt = 0
while cnt < 15:
    k = fibo[2*cnt+1] * fibo[2*cnt+2]
    cnt += 1
    print '{}: k = {}'.format(cnt, k)
