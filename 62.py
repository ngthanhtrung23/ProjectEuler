x = dict()
for i in xrange(1, 100111):
    cur = str(i ** 3)
    cur = ''.join(sorted(cur))
    tmp = x.get(cur, [])
    tmp.append(i ** 3)
    x[cur] = tmp
    if len(x[cur]) == 5:
        print x[cur]
        break

