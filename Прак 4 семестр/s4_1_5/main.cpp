

int main()
{
    int count;
    std::cin >> count;
    Holder **cnt = new Holder *[count];
    for (int i = 0; i < count; i++) {
        cnt[i] = new Holder;
    }
    for (int i = 0; i < count; i++) {
        delete cnt[i];
    }
    delete[] cnt;
    return 0;
}
