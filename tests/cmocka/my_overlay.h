#ifndef MY_MACRO_OVERLAY
# define MY_MACRO_OVERLAY

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <setjmp.h>
# include "cmocka.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# ifndef HOW_MANY_TESTS
#  define HOW_MANY_TESTS 500
# endif

# define TEST_ARR tests

struct CMUnitTest	TEST_ARR[HOW_MANY_TESTS];
size_t				g_test_index = 0;

//This didn't work (sad) can't forward declare functions within functions
// the forward declared function gets promoted to 'static' and 
// defining static function whithin function is not allowed. 
// couldn't figure out a way to make the forward declaration work
//# define T(x) \
//			void x(void* *);\
//			TEST_ARR[g_test_index++] = (struct CMUnitTest)cmocka_unit_test(x);\
//			void x(void* *state){

# define T(test_name, test_code) \
	void	test_name(void* *state) {\
		test_code\
	};TEST_ARR[g_test_index++] = (struct CMUnitTest)cmocka_unit_test(test_name);

# define T_D(test_name, tear_down, test_code) \
	void	test_name(void* *state) {\
		test_code\
	};TEST_ARR[g_test_index++] = (struct CMUnitTest)cmocka_unit_test_teardown(test_name, tear_down);



static int		search_test_arr_by_name(const char *t_name)
{
	size_t	i;

	i = 0;
	while (i < g_test_index)
	{
		if (!strcmp(t_name, TEST_ARR[i].name))
			return (i);
		i++;
	}
	return (0);
}

static int		search_test_arr(const char *search_for)
{
	int		ret;

	if ((ret = search_test_arr_by_name(search_for)))
		return (ret);
	else
		return ((ret = atoi(search_for)) < g_test_index ? ret : 0);
}

static int
	run_test_arr(
		int test_count, char *test_ids[])
{
	char	** const test_lim = test_ids + test_count;
	int 	ret_val = 0;

	if (!test_count)
		ret_val = _cmocka_run_group_tests(
				"TEST_ARR", TEST_ARR,
				g_test_index, 0, 0);
	else
		do {
			ret_val += _cmocka_run_group_tests(
				*test_ids,
				&TEST_ARR[search_test_arr(*test_ids)],
				1, 0, 0);
		} while (++test_ids < test_lim);
	return (ret_val);
}

//main may be defined (see compiler invocation)
#undef main
//tests are declared in .test.c files
int	declare_tests_and_run(int, char *[]);
# define AV_UTEST_DIR 1
# define AV_TESTS 2
int		main(int ac, char **av)
{
	int		ret;

	if (!(ret = chdir(av[AV_UTEST_DIR])))
		ret = declare_tests_and_run(
			ac - AV_TESTS,
			&av[AV_TESTS]);
	return (ret);
}
	
#endif
