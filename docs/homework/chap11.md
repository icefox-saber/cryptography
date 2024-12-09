# chap11

[陈永俊] [522031910203]

## 验证 DSS（数字签名标准）算法的有效性

### 2. **DSS 有效性证明**

签名验证有效性的核心在于证明 $v = r$：

$$
v = ((g^{u_1} \cdot y^{u_2}) \mod p) \mod q
$$

展开 $u_1$ 和 $u_2$：
$$
u_1 = H(m) \cdot w \mod q, \quad u_2 = r \cdot w \mod q
$$
其中 $w = s^{-1} \mod q$，而 $s = k^{-1}(H(m) + xr) \mod q$。

将 $s$ 和 $w$ 代入：
$$
u_1 = H(m) \cdot k \mod q, \quad u_2 = r \cdot k \mod q
$$

根据 $g^{u_1} \cdot y^{u_2}$ 的展开：
$$
g^{u_1} \cdot y^{u_2} = g^{H(m) \cdot k} \cdot (g^x)^{r \cdot k} \mod p = g^{k(H(m) + xr)} \mod p
$$

由于 $r = (g^k \mod p) \mod q$，可以验证 $v = r$。

### 2. **SM2 有效性证明**

验证核心在于证明 $R = (e + x_2) \mod n$：

1. **展开验证计算**  
   令 $(x_2, y_2) = sG + tP$，代入 $s$ 和 $t$：
   $$
   sG + tP = (k^{-1}(1 + d \cdot R))G + (R + s)P
   $$

2. **简化公式**  
   代入 $P = dG$：
   $$
   sG + tP = (k^{-1}(1 + d \cdot R))G + (R + s)dG
   $$
   化简后验证 $x_2$ 的结果最终满足 $R = (e + x_2) \mod n$。
