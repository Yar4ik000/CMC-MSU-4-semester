template <class T, class P>
T myfilter(T container, P predicat) {
    T copy;
    auto it1 = copy.end();
    for (auto it : container) {
        if (predicat(it)) {
            copy.insert(it1, it);
            it1 = copy.end();
        }
    }
    return copy;
}
