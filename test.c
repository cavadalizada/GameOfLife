#include "mylib/board.c"
#include <stdio.h>
#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUnit.h>

void c_test_arena(void)
{
    struct arena *ar = initialize(5, 5);
    ar->board[0][0] = 1;
    ar->board[0][4] = 1;
    CU_ASSERT_EQUAL(checkNeighbourCircular(ar, 1, 0), 2);
    CU_ASSERT_EQUAL(checkNeighbourClipped(ar, 1, 0), 0);
    CU_ASSERT_NOT_EQUAL(isEmpty(ar), 1);
    CU_ASSERT_EQUAL(isEmpty(ar), 0);
}

int main(int argc, char const *argv[])
{
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite pSuite1 = CU_add_suite("Testing of checkNeighbour", NULL, NULL);
    CU_ADD_TEST(pSuite1, c_test_arena);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    return CU_get_number_of_failures();
}
