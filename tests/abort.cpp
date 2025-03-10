#include <gtest/gtest.h>
#include <hard_assert.hpp>

TEST(abort, abort)
{	ha_require_user_interaction = false;
	ASSERT_DEATH(ha_abort("", ""), " unrecoverable error : ''");
}
