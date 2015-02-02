tu = 2
mau = 5
for b in xrange(3, 1000 * 1000 + 1):
    l = 1
    r = b - 1
    res = 1
    while l <= r:
        mid = (l + r) >> 1
        if 7*mid < 3*b:
            res = mid
            l = mid + 1
        else:
            r = mid - 1
    if tu*b < mau*res:
        tu = res
        mau = b

print "{}/{}".format(tu, mau)

