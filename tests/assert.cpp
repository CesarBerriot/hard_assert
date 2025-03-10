#include <gtest/gtest.h>
#include <hard_assert.hpp>

TEST(assert, false)
{	ha_require_user_interaction = false;
	ASSERT_DEATH(ha_assert(false, "", ""), " unrecoverable error : ''");
}

TEST(assert, true)
{	ha_require_user_interaction = false;
	ha_assert(true, "", "");
}
