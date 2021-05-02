template <class T>
typename T::value_type process(const T& container) {
    typename T::value_type sum{};
    if (container.empty()) {
        return sum;
    }
    int i = 0;
    for (auto it = container.rbegin(); it != container.rend() && i < 5; ++it) {
        if (i % 2 == 0) {
            sum += *it;
            ++i;
        } else {
            ++i;
        }
    }
    return sum;
}
