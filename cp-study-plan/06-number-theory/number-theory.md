# Number Theory & Mathematics

## 1. GCD và LCM

### Greatest Common Divisor (GCD)
```cpp
// Euclidean algorithm - O(log min(a,b))
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Iterative version
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Built-in C++14
int g = __gcd(a, b);
// hoặc C++17
int g = gcd(a, b);
```

### Least Common Multiple (LCM)
```cpp
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;  // Tránh overflow
}
```

### Extended Euclidean Algorithm
Tìm x, y sao cho ax + by = gcd(a, b)

```cpp
int extendedGCD(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    
    x = y1;
    y = x1 - (a / b) * y1;
    
    return gcd;
}
```

## 2. Prime Numbers

### Check Prime - O(√n)
```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}
```

### Sieve of Eratosthenes - Tìm tất cả primes ≤ n
```cpp
vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    return isPrime;
}

// Lấy list các primes
vector<int> getPrimes(int n) {
    vector<bool> isPrime = sieveOfEratosthenes(n);
    vector<int> primes;
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}
```

### Prime Factorization
```cpp
vector<pair<int, int>> primeFactorization(int n) {
    vector<pair<int, int>> factors;
    
    // Check for 2
    int count = 0;
    while (n % 2 == 0) {
        count++;
        n /= 2;
    }
    if (count > 0) {
        factors.push_back({2, count});
    }
    
    // Check for odd factors
    for (int i = 3; i * i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        if (count > 0) {
            factors.push_back({i, count});
        }
    }
    
    // If n is still > 1, then it's a prime
    if (n > 1) {
        factors.push_back({n, 1});
    }
    
    return factors;
}
```

## 3. Modular Arithmetic

### Basic Modular Operations
```cpp
const int MOD = 1e9 + 7;

// Modular addition
int addMod(int a, int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

// Modular subtraction
int subMod(int a, int b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

// Modular multiplication
long long mulMod(long long a, long long b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
```

### Modular Exponentiation - a^b mod m
```cpp
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    
    return result;
}
```

### Modular Inverse
```cpp
// Khi mod là prime, dùng Fermat's little theorem: a^(p-1) ≡ 1 (mod p)
// => a^(-1) ≡ a^(p-2) (mod p)
long long modInverse(long long a, long long mod) {
    return powerMod(a, mod - 2, mod);
}

// Modular division: (a/b) mod m = (a * b^(-1)) mod m
long long divMod(long long a, long long b, long long mod) {
    return mulMod(a, modInverse(b, mod));
}
```

## 4. Combinatorics

### Factorial với Modulo
```cpp
vector<long long> fact, invFact;

void precomputeFactorials(int n) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mulMod(fact[i-1], i);
    }
    
    invFact[n] = modInverse(fact[n], MOD);
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = mulMod(invFact[i+1], i+1);
    }
}
```

### Combination nCr
```cpp
// O(1) sau khi precompute
long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return mulMod(fact[n], mulMod(invFact[r], invFact[n-r]));
}

// O(r) không cần precompute
long long nCrSimple(int n, int r) {
    if (r > n - r) r = n - r;  // Take advantage of symmetry
    
    long long result = 1;
    for (int i = 0; i < r; i++) {
        result = mulMod(result, n - i);
        result = divMod(result, i + 1, MOD);
    }
    
    return result;
}
```

### Permutation nPr
```cpp
long long nPr(int n, int r) {
    if (r > n || r < 0) return 0;
    return mulMod(fact[n], invFact[n-r]);
}
```

## 5. Number Theory Tricks

### Count divisors của n
```cpp
int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) count++;
        }
    }
    return count;
}
```

### Sum of divisors
```cpp
long long sumOfDivisors(int n) {
    long long sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i;
        }
    }
    return sum;
}
```

### Euler's Totient Function φ(n)
Đếm số integers từ 1 đến n coprime với n.

```cpp
int eulerTotient(int n) {
    int result = n;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            // Remove multiples of i
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    
    // If n is still > 1, then it's a prime
    if (n > 1) result -= result / n;
    
    return result;
}
```

## 6. Matrix Exponentiation

Dùng để tính Fibonacci, Linear recurrence nhanh trong O(log n).

```cpp
typedef vector<vector<long long>> Matrix;

Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    
    return C;
}

Matrix matrixPower(Matrix A, long long p) {
    int n = A.size();
    Matrix result(n, vector<long long>(n, 0));
    
    // Identity matrix
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }
    
    while (p > 0) {
        if (p & 1) {
            result = multiply(result, A);
        }
        A = multiply(A, A);
        p >>= 1;
    }
    
    return result;
}

// Fibonacci bằng matrix exponentiation
long long fibonacciMatrix(long long n) {
    if (n <= 1) return n;
    
    Matrix base = {{1, 1}, {1, 0}};
    Matrix result = matrixPower(base, n - 1);
    
    return result[0][0];
}
```

## Bài tập thực hành

### Easy
1. Find GCD and LCM
2. Check if number is prime
3. Count factors of a number

### Medium
4. Sieve of Eratosthenes
5. Modular exponentiation
6. nCr with large numbers

### Hard
7. Matrix exponentiation for Fibonacci
8. Euler's totient function
9. Prime factorization

## Tips quan trọng

1. **Overflow**: Luôn chú ý overflow khi tính toán với số lớn
2. **Modulo**: Dùng modulo arithmetic cho số lớn
3. **Precompute**: Tính trước factorial, primes nếu cần nhiều query
4. **Prime check**: Dùng sieve nếu cần check nhiều số
5. **Matrix exponentiation**: Tốt cho linear recurrence với exponent lớn