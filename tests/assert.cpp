#include <gtest/gtest.h>
#include <hard_assert.hpp>

TEST(assert, false)
{	ha_require_user_interaction = false;
	ha_set_application_name("");
	ASSERT_DEATH(ha_assert(false, ""), " unrecoverable error : ''");
}

TEST(assert, true)
{	ha_require_user_interaction = false;
	ha_set_application_name("");
	ha_assert(true, "");
}
