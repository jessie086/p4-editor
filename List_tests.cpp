#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(test_ctr) {

    List<int> l;
    ASSERT_TRUE(l.size() == 0);
    ASSERT_TRUE(l.empty());
}

TEST(test_copy_ctr) {

    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    List<int> lcopy(l);

    ASSERT_TRUE(lcopy.size() == 3);

    List<int>::Iterator it = lcopy.begin();
    ASSERT_TRUE(*it == 3);
    
    ++it;
    ASSERT_TRUE(*it == 2);
    
    ++it;
    ASSERT_TRUE(*it == 1);
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
    //should do nothing because it's assigning to itself

   List<int>::Iterator it = l2.begin();
    ASSERT_TRUE(*it == 3);
    
    ++it;
    ASSERT_TRUE(*it == 2);
    
    ++it;
    ASSERT_TRUE(*it == 1);
}

TEST(test_self_assign) {

    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    l = l;
    //should do nothing because it's assigning to itself

    List<int>::Iterator it = l.begin();
    ASSERT_TRUE(*it == 3);
    
    ++it;
    ASSERT_TRUE(*it == 2);
    
    ++it;
    ASSERT_TRUE(*it == 1);
}

TEST(test_first_back){
    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    ASSERT_EQUAL(l.front(),3);
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
    l.push_back(1);

    List<int>::Iterator i = l.begin();
    ++i;
    ++i;

    ASSERT_TRUE(i == l.end());
}

TEST(test_operator_equal){
    List<int> l;
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);

    List<int>::Iterator i = l.begin();
    ++i;
    ++i;

    ASSERT_TRUE(i == l.end());
}




TEST_MAIN()