#include <gtest/gtest.h>
#include <hard_assert.hpp>
#include <stddef.h>

TEST(null_module_name, assert)
{	ha_require_user_interaction = false;
	ASSERT_DEATH(ha_assert(true, NULL, ""), "hard_assert unrecoverable error : 'NULL module name.'");
}

TEST(null_module_name, abort)
{	ha_require_user_interaction = false;
	ASSERT_DEATH(ha_abort(NULL, ""), "hard_assert unrecoverable error : 'NULL module name.'");
}
