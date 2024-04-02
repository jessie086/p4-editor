#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(test_list_default_ctor) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
}

TEST(test_traversal) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    int j = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++j) {
        ASSERT_EQUAL(*it, j);
    }
    ASSERT_EQUAL(j, list.size());
}

TEST(test_copy_ctr) {

    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }

    List<int> lcopy(list);
    ASSERT_TRUE(lcopy.size() == 5);

    List<int>::Iterator it = lcopy.begin();
    ASSERT_TRUE(*it == 0);
    
    ++it;
    ASSERT_TRUE(*it == 1);
    
    ++it;
    ASSERT_TRUE(*it == 2);
}

TEST(test_empty_list_copy_ctr) {

    List<int> l;
    List<int> lcopy(l);

    ASSERT_TRUE(lcopy.size() == 0);
}

TEST(test_assign) {

    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    List<int> l2;
    l2.push_back(4);
    l2.push_back(5);
    l2.push_back(6);

    l2 = l;

   List<int>::Iterator it = l2.begin();
    ASSERT_TRUE(*it == 3);
    
    ++it;
    ASSERT_TRUE(*it == 2);
    
    ++it;
    ASSERT_TRUE(*it == 1);
}

//edge case: lists with different sizes?

TEST(clear){
    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    l.clear();
    ASSERT_TRUE(l.empty());
}

TEST(test_front){
    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    ASSERT_EQUAL(l.front(),3);
}

TEST(test_back){
    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    ASSERT_EQUAL(l.back(),1);
}

TEST(test_clear){
    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    l.clear();
    ASSERT_TRUE(l.empty());
}


//start to test iterator
TEST(test_operator_equal){
    List<int> l;
    l.push_back(3);
    l.push_back(2);

    List<int>::Iterator i = l.begin();
    ++i;
    ++i;

    ASSERT_TRUE(i == l.end());
}

TEST(test_operator_inequal){
    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    List<int>::Iterator i = l.begin();

    ASSERT_TRUE(i != l.end());
}

TEST(test_erase){
    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    List<int>::Iterator i = l.begin();

    l.erase(i);
    ASSERT_TRUE(l.size()==2);
}

TEST(test_insert){
    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);
   
    List<int>::Iterator i = l.begin();
    int t = 9;
    l.insert(i,t);
    --i;

    ASSERT_TRUE(*i == 9);
}

TEST(test_insert_to_empty_list){
    List<int> empty_list;
    
    List<int>::Iterator i = empty_list.begin();
    int t = 9;
    empty_list.insert(i,t);
    --i;

    ASSERT_TRUE(*i == 9);
}



TEST(test_equal_operator){
    List<int>:: Iterator i1;
    List<int>:: Iterator i2;

    List<int> l; 
    l.push_back(1); 
    l.push_back(2); 
    l.push_back(3);

    i1 = l.begin();

    ASSERT_TRUE(!(i1 == i2));
    ++i1;
    ASSERT_TRUE(!(i1 == i2));
    ++i1;
    ASSERT_TRUE(!(i1 == i2));
    i1 = l.end();
    ASSERT_TRUE(!(i1 == i2));
}


TEST(test_insert_more){
    List<int>:: Iterator i1;
    List<int>:: Iterator i2;

    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);    
    i1 = l.begin();


    ASSERT_TRUE(!(i1 == i2));
    ++i1;
    ASSERT_TRUE(!(i1 == i2));
    ++i1;
    ASSERT_TRUE(!(i1 == i2));
    i1 = l.end();
    ASSERT_TRUE(!(i1 == i2));
}

TEST(test_erase_at_end){
    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);
    l.push_back(23);

    List<int>::Iterator j = l.begin();
    
    ++j;
    ++j;
    ++j;

    l.erase(j);
    cout << l.size();
    cout << *j << *(--l.end());

    ASSERT_EQUAL(j, l.end());
}

TEST(test)
{
    
    List<int> my_list;
    int value = 0;

    my_list.empty();
    my_list.size();

    my_list.push_front(42);
    my_list.push_back(42);

    my_list.front() = 73;
    my_list.back() = 73;
   
    my_list.pop_front();
    my_list.pop_back();

    List<int> list2(my_list);
    list2 = my_list;
    List<int>::Iterator iter = my_list.begin();
    my_list.insert(iter, 42);
    iter = my_list.begin();
    my_list.erase(iter);
    iter = my_list.begin();

    List<int>::Iterator iter2 = my_list.end();
    const List<int>::Iterator iter3 = iter2;

    bool b = iter == iter2;
    assert(b);
    b = iter3 == my_list.end();
    assert(b);
    b = my_list.end() == iter3;
    assert(b);
    my_list.push_front(42);
    my_list.push_back(42);
    iter = my_list.begin();
    b = iter != iter2;
    assert(b);
    b = iter3 != my_list.end();
    assert(!b);
    b = my_list.end() != iter3;
    assert(!b);
    ++iter;


    value = *iter;

    List<int>::Iterator iter_cpy(iter);
    iter_cpy = iter;

    value = *++--iter;
    value = *--++my_list.begin();

    iter = my_list.begin();
    *(iter++) = 280;
    value = *iter;
    value = *(iter--);
    value = *iter;

    my_list.insert(my_list.begin(), 3);
    my_list.erase(my_list.begin());

    List<int> list3;
    list3.push_back(3);
    value = *list3.begin();

    List<int> list4;
    list4.push_back(4);

    value = *--list4.end();

    my_list.clear();

    List<int> list5;
    list5.push_back(7);
    list5.push_front(-1);
    list5.front() = -42;
    list5.back() = 280;
    list5.insert(list5.begin(), 11);
    list5.erase(list5.begin());

    List<int>::Iterator iter5;
    iter5 = list5.begin();

    value = (*++iter5);
    value = *iter5;
    b = ++iter5 == list5.end();
    assert(b);
    value = b;
    assert(value);
}

TEST_MAIN()