#if 0
#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("hello world\n");
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

