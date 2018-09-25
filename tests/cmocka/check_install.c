#define HOW_MANY_TESTS 10
#include "my_overlay.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(nop,
		assert_true(1);
	)
	return (run_test_arr(all_of, these));
}
