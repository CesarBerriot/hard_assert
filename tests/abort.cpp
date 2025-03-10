#include <gtest/gtest.h>
#include <hard_assert.hpp>

TEST(abort, abort)
{	ha_require_user_interaction = false;
	ha_set_application_name("");
	ASSERT_DEATH(ha_abort(""), " unrecoverable error : ''");
}
