/*
 */
#include "CUnit/Basic.h"
#include "equalTo.h"
#include "assert.h"
#include "not.h"
#include "memwatch.h"

	char* string1 = "foo";
	char* string2 = "bar";

	char string3[] = "foo";
	char string4[] = "bar";

	int int1 = 23;
	int int2 = 23;

void testEqualToString(void) {
	assertThat(string1, equalTo(string1));
	assertThat(string1, not(equalTo(string2)))

	assertThat(string3, equalTo(string3));
	assertThat(string3, not(equalTo(string4)));
}

void testEqualToInt(void) {
	assertThat(11, equalTo(11));
	assertThat(11, not(equalTo(13)));
}

void testEqualToPointer(void) {
	assertThat( &int2, not(equalTo(&int1)));
	assertThat( &int1, equalTo(&int1));
	assertThat(int2, not(equalTo(&int1)));
}


int main() {
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
	if (NULL == CU_add_test(pSuite, "test of equalTo() with char* and char[]", testEqualToString)
			|| NULL == CU_add_test(pSuite, "test of equalTo() with integer values", testEqualToInt)
			|| NULL == CU_add_test(pSuite, "test of equalTo() with pointers", testEqualToPointer)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
