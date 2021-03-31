#pragma once
template <typename T>
class HasFriend
{
private:
    T item;
    static int ct;
public:
    HasFriend(const T& i) : item(i) { ct++; }
    ~HasFriend() { ct--; }
    friend void counts();
    friend void reports(HasFriend<T>&); // template parameter
};

// each specialization has its own static data member
template <typename T>
int HasFriend<T>::ct = 0;


