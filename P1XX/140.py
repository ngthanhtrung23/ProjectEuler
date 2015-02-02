import math

cnt = 0
k = 0
sum = 0
result = []
while cnt < 14:
    k += 1
    d = (k+1) * (k+1) + 4*k*(k+3)
    x = round(math.sqrt(d))
    if x*x == d:
        cnt += 1
        sum += k
        result.append(k)
        print "{}: k = {}, sum = {}".format(cnt, k, sum)

f = [0 for i in xrange(0, 30)]
sum = 0
for i in xrange(0, 30):
    if i < 4:
        f[i] = result[i]
    else:
        f[i] = f[i-2] * 7 - f[i-4] + 7

    sum += f[i]

print sum
