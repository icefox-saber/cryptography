# chap04

[陈永俊] [522031910203]

## 4.1

> 完成对**3-DES**的**Merkle-Hellman**攻击：令$A=0$，再对$K1$的所有$2^{56}$个取值，找出令$A=0$的明文。补全该算法，以描述或伪代码方式。

```cpp
//P-C denote 2^{56} pairs of plaintext and Ciphertext using the genuine triple DES key
Merkle-Hellman-Attack(P-C)
Choose a 64-bit value A//A can be anything

for every DES key L
    compute plaintext PL = DL(A)//DL() denotes the Decryption function for DES with key L
    search matched Ciphertext CL in P-C
    compute BL = DL(CL)
    stored {BL,L} in Hash table H

for every DES key M
    compute BM = EM(A)//since CL = EL(DM(A))
    if serach BM in H//O(1)
        return {L , M}//{L,M} = {K1,K2}
```
