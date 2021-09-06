/**
 * @file pharma_test.c
 * @author Karthik S (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "unity.h"
#include "pharma_operations.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_add_medicine(void) {
  number new_medicine = {"Add_1", "mname", "1234", "1234", "cname", "12-12-1234", "12-12-1234"};
  TEST_ASSERT_EQUAL(0, add_medicine(&new_medicine));
}

void test_delete_medicine(void) {
  number new_medicine = {"Delete_1", "mname", "1234", "1234", "cname", "12-12-1234", "12-12-1234"};
  TEST_ASSERT_EQUAL(0, add_medicine(&new_medicine));
  TEST_ASSERT_EQUAL(0, delete_medicine(new_medicine.name));
}

void test_modify_medicine(void) {
  number new_medicine = {"Modify_1", "mname", "1234", "1234", "cname", "12-12-1234", "12-12-1234"};
  number new_medicine1 = {"Modified_id", "mname1", "123", "123", "cname1", "11-11-1235", "11-10-1235"};
  TEST_ASSERT_EQUAL(0, add_medicine(&new_medicine));
  TEST_ASSERT_EQUAL(0, modify_medicine(new_medicine.name, &new_medicine1));
  TEST_ASSERT_EQUAL(0, delete_medicine(new_medicine1.name));
}
void test_search_medicine(void) {
  number new_medicine = {"Search_1", "mname", "1234", "1234", "cname", "12-12-1234", "12-12-1234"};
  TEST_ASSERT_EQUAL(0, add_medicine(&new_medicine));
  TEST_ASSERT_EQUAL(0 , search_medicine(new_medicine.name));
  TEST_ASSERT_EQUAL(0 , delete_medicine(new_medicine.name));
}
void test_display_medicine(void) 
{ 
  TEST_ASSERT_EQUAL(1, display_medicine()>0);
}

int main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_add_medicine);
  RUN_TEST(test_delete_medicine);
  RUN_TEST(test_modify_medicine);
  RUN_TEST(test_search_medicine);
  RUN_TEST(test_display_medicine);

  /* Close the Unity Test Framework */
  return UNITY_END();
}
