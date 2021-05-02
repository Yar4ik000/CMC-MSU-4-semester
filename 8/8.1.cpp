#include <iostream>


int func(int a, int b, int c, int d) {
    return abs(a - b) + abs(c - d);
}


int main() {
    int n, m;
    std::cin >> m >> n;
    int r1, c1, r2, c2;
    while (std::cin >> r1 >> c1 >> r2 >> c2) {
        r1 += n;
        r2 += n;
        c1 += m;
        c2 += m;
        int ans1 = std::min(func(r1, r2 + m, c1, c2), func(r1, r2 + m, c1, c2 + n));
        int ans2 = std::min(func(r1, r2, c1, c2 + n), func(r1, r2 - m, c1, c2 + n));
        int ans3 = std::min(func(r1, r2 - m, c1, c2), func(r1, r2 - m, c1, c2 - n));
        int ans4 = std::min(func(r1, r2, c1, c2 - n), func(r1, r2 + m, c1, c2 - n));
        int ans = std::min(ans1, ans2);
        ans = std::min(ans3, ans);
        ans = std::min(ans4, ans);
        ans = std::min(ans, func(r1, r2, c1, c2));
        std::cout << ans << std::endl;
    }
    long long a = 10;
    std::cout << abs(a);
}
