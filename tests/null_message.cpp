#include <gtest/gtest.h>
#include <hard_assert.hpp>
#include <stddef.h>

static char expected_death_message[] = "hard_assert unrecoverable error : 'NULL message.'";

TEST(null_message, assert)
{	ha_require_user_interaction = false;
	ASSERT_DEATH(ha_assert(false, "", NULL), expected_death_message);
}

TEST(null_message, abort)
{	ha_require_user_interaction = false;
	ASSERT_DEATH(ha_abort("", NULL), expected_death_message);
}
