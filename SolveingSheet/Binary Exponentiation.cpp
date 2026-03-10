//   a - > number   , b - > power

int power(int a, int b) 
{
    if (b == 0) return 1;
    int tmp = power(a, b / 2);
    int result = tmp * tmp;
    if (b % 2 == 1) result *= a;
    return result;
}