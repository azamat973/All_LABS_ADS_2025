b_tape = input().strip()
n = int(input())

s_tapes  = [input().strip() for i in range(n)]

L = len(b_tape)

dp = [False] * (L +1)
dp[0] = True

for i in range (L):
    if dp[i] :
        for word in s_tapes :
            length  = len(word)
            if i + length  <= L:
                
                if b_tape [i:i + length] == word:
                    dp[i + length] = True

if dp[L]:
    print("YES")
else:
    print("NO")
