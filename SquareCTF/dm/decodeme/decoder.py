import base64, string, sys
from random import shuffle
import collections

def decode(f, enc):
    for chunk in enc.split('\x00'):
        uniq_num = len(dict.fromkeys(chunk))
        print(chunk)
        c = collections.Counter(chunk[uniq_num:])
        for idx in range(uniq_num):
            diff = c[chunk[idx]] + 1
            r = chunk[idx]
            print("r:" + r + "(" + str(ord(r)) + ")" + ", (diff) = " + str(diff) )
            if ord(r) > 122:
                gap = diff
            elif ord(r) > 43:
                if diff >= 143 - ord(r):
                    gap = diff
                else:
                    gap = diff + 100
            elif ord(r) > 31:
                gap = diff + 100
            else: # 9-13
                if diff < 15:
                    gap = diff + 200
                else:
                    gap = diff + 100
            ord_x = gap + ord(r) - 100
            print("x:" + chr(ord_x)+"("+ str(ord_x) +")")
                
            f.write(chr(ord_x))



if __name__ == '__main__':
    with open(sys.argv[1], 'rb') as (r):
        w = open(sys.argv[1]+'.64', 'wb')
        decode(w, r.read())