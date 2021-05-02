class C
{
public:
    int q;
    C(double a) : q{0} {}
    C() : q{0} {}
    C(double a, double b) : q{0} {}
    int operator~ () const{
        return 0;
    }
    friend int operator+ (int v2, const C &v1){
        return 0;
    }
    C operator++ () {
        return *this;
    }
    int operator* (C* w) {
        return 0;
    };
    C(const C*) : q{0} {}
};