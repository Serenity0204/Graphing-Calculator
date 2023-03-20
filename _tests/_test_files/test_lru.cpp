#include "gtest/gtest.h"
#include <bits/stdc++.h>

//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/lru/lru.h"
//------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------
//Helper Functions
const int CAPACITY = 5;



//------------------------------------------------------------------------------
//@TODO: add more test functions here:


bool test_lru1(bool debug=false)
{
    
    LRU<int,int> lru(CAPACITY);
    lru.put(1, 1);
    lru.put(2, 2);
    lru.put(3, 3);
    lru.put(4, 4);
    lru.put(5, 5);

    cout << lru << endl;
    lru.put(3, 3);
    cout << lru << endl;
    lru.put(1, 10);
    cout << lru << endl;
    lru.get(3);
    cout << lru << endl;
    lru.put(6, 6);
    cout << lru << endl;
    return true;
}



//------------------------------------------------------------------------------


// Lord help me! 
const bool debug = false;



//------------------------------------------------------------------------------
//@TODO: add more test sets to call test functions here:

TEST(TEST_LRU, TestLru1)
{
    bool success = test_lru1(debug);
    EXPECT_EQ(success, true);
}

//------------------------------------------------------------------------------


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}
