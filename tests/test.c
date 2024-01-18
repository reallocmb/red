#include"eenheid/eenheid.h"
#include<red/r_file.c>

__EENHEID_INIT__

SUITE(r_file_c)
{
    TEST(red_file_copy())
    {
        eenheid_assert_str("matthis", "matthis");
    } TEST_END
}

__EENHEID_END__
