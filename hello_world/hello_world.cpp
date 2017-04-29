#if 1
#include <stdio.h>

/* 階乗 n! を計算する */
int fact(int n)
{ 
    if (n == 0) return 1;   /* 脱出条件。0! は 1 である */
    return fact(n - 1) * n; /* n! は (n-1)! に n を乗じたもの。再帰呼出し */
}

int main(int argc, char* argv[])
{
	int a = 10;
	printf("hello world\n");
	printf("fact(%d):%d\n",a,fact(a));
	return 0;
}
#else
#include <iostream>

int main(int argc, char* argv[])
{
	std::cout << "hello world" << std::endl;
	return 0;
}
#endif

