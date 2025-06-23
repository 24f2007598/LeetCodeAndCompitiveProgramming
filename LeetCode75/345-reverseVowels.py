#27ms, beats 14.05%
class Solution:
    def reverseVowels1(self, s: str) -> str:
        V = []
        l = len(s)
        for i in range(l):
            if s[i].lower() in ['a', 'e', 'i', 'o', 'u']:
                V.append(s[i])
        c = -1
        ns = ''
        for i in range(l):
            if s[i].lower() in ['a', 'e', 'i', 'o', 'u']:
                ns += V[c]
                c -= 1
            else:
                ns += s[i]
        return ns

#incomplete trial 2
def reverseVowels(s: str) -> str:
    L = list(s)
    l = len(s)
    a = 0
    b = -1
    v = 'aeiouAEIOU'
    # a < l // 2 or b >= -(l // 2)
    while a < l // 2 or b >= -(l // 2):
        while a < l//2:
            if L[a] in v:
                break
            a += 1
        while b >= -(l//2):
            if L[b] in v:
                break
            b -= 1

        if L[a] in v and L[b] in v:
            L[a], L[b] = L[b], L[a]
        if a == l+b:
            break
        a += 1
        b -= 1

    ns = ''.join(L)
    return ns

#incmplete trial 1
def reverseVowels2(s: str) -> str:
    L = list(s)
    l = len(s)
    a = 0
    b = -1
    while True:
        try:
            print("what: ", a, b, L)
            while a < l//2:
                if L[a] in 'aeiouAEIOU':
                    print("vovA", a)
                    break
                a += 1
            while b >= -(l//2):
                if L[b] in 'aeiouAEIOU':
                    print("vovB", b)
                    break
                b -= 1
            L[a], L[b] = L[b], L[a]
            # print(L)
            a += 1
            b -= 1
        except:
            break
        print("\n")
    L = L[::-1]
    ns = ''.join(L)
    return ns

