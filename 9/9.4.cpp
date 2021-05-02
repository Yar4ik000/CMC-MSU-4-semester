int main()
{
    int count;
    std::cin >> count;
    Holder *array = new Holder[count];
    for (int i = 0, j = count - 1; i < j; i++, j--) {
        array[i].swap(array[j]);
    }
    delete[] array;
}