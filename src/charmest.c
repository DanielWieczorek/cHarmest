/*
 */
#include "CUnit/Basic.h"
#include "equalTo.h"
#include "assert.h"
#include "not.h"
#include "memwatch.h"


void test(void)
{
	char* string1 = "foo";
	char* string2 = "bar";

	int int1 = 23;
	int int2 = 23;

	assertThat( string1, not(equalTo(string1)));
	assertThat( string1, not(equalTo(string1)));

	assertThat( string1, not(equalTo(string2)));
	assertThat( string1, equalTo(string1));
	assertThat( 11, equalTo(11));
	assertThat( 11, equalTo(13));

	assertThat( &int2, equalTo(&int1));
	assertThat( &int1, equalTo(&int1));
		assertThat( &int2, not(equalTo(&int1)));
}

int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", NULL, NULL);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if (NULL == CU_add_test(pSuite, "test()", test))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
