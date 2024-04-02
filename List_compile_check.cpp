#include "List.hpp"
#include "List.hpp" // check for proper include guards

// THIS TEST CASE WILL ONLY TELL YOU IF YOUR CODE COMPILES.
// YOU NEED TO WRITE YOUR OWN COMPREHENSIVE TEST CASES IN List_tests.cpp

struct A {
    int x;
};

static int test()
{
    cout << "list";
    
    List<int> my_list;
    int value = 0;

    cout << 'a';

    my_list.empty();
    my_list.size();

    cout << 'b';

    my_list.push_front(42);

    cout << "front" << endl;

    // my_list.push_back(42);

    // cout << 'c';

    // my_list.front() = 73;
    // my_list.back() = 73;

    // cout << 'd';

    // my_list.pop_front();
    // my_list.pop_back();

    // cout << 'e';

    // List<int> list2(my_list);
    // list2 = my_list;

    // cout << 'f';

    // List<int>::Iterator iter = my_list.begin();
    // my_list.insert(iter, 42);
    // iter = my_list.begin();
    // my_list.erase(iter);
    // iter = my_list.begin();

    // cout << 'g';

    // List<int>::Iterator iter2 = my_list.end();
    // const List<int>::Iterator iter3 = iter2;

    // cout << 'h';

    // bool b = iter == iter2;
    // b = iter3 == my_list.end();
    // b = my_list.end() == iter3;
    // my_list.push_front(42);
    // my_list.push_back(42);
    // iter = my_list.begin();
    // b = iter != iter2;
    // b = iter3 != my_list.end();
    // b = my_list.end() != iter3;
    // ++iter;

    // cout << 'i';


    // value = *iter;

    // List<int>::Iterator iter_cpy(iter);
    // iter_cpy = iter;

    // cout << 'j';

    // value = *++--iter;
    // value = *--++my_list.begin();

    // cout << 'k';

    // iter = my_list.begin();
    // *(iter++) = 280;
    // value = *iter;
    // value = *(iter--);
    // value = *iter;

    // cout << 'l';

    // my_list.insert(my_list.begin(), 3);
    // my_list.erase(my_list.begin());

    // cout << 'm';

    // List<int> list3;
    // list3.push_back(3);
    // value = *list3.begin();

    // cout << 'n';

    // List<int> list4;
    // list4.push_back(4);
    // list4.size();
    // value = *--list4.end();

    // cout << 'o';

    // my_list.clear();

    // cout << 'p';

    // List<A> list5;
    // list5.push_back(A{7});
    // list5.push_front(A{-1});
    // list5.front() = A{-42};
    // list5.back() = A{280};
    // list5.insert(list5.begin(), A{11});
    // list5.erase(list5.begin());

    // cout << 'q';

    // List<A>::Iterator iter5;
    // iter5 = list5.begin();
    // value = (*++iter5).x;
    // value = iter5->x;
    // b = ++iter5 == list5.end();
    // value = b;


    return value;
}

int main()
{
    cout << "Hello " << endl;
    test();
}
