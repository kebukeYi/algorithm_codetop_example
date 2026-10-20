#include <cstdio>
#include <cstdlib>

int main() {
    int* p = (int*)malloc(sizeof(int));  // 强制类型转换
    *p = 100;
    free(p);
    *p = 200;  // use-after-free，ASAN捕获
    printf("%d\n", *p);
    return 0;
}

// 查看内存泄露
// g++ -fsanitize=address -g use_after_free.cpp -o test && ./test
