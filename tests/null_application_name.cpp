#include <gtest/gtest.h>
#include <hard_assert.hpp>
#include <stddef.h>

TEST(null_application_name, null_application_name)
{	ha_require_user_interaction = false;
	ASSERT_DEATH(ha_set_application_name(NULL), "hard_assert unrecoverable error : 'NULL application name.'");
}
