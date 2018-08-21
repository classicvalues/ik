#include "gmock/gmock.h"
#include "ik/ik.h"

#define NAME vec3

using namespace ::testing;

const double pi = std::atan(1.0) * 4;

TEST(NAME, vec3)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 2, 3);
    EXPECT_THAT(v.x, DoubleEq(1));
    EXPECT_THAT(v.y, DoubleEq(2));
    EXPECT_THAT(v.z, DoubleEq(3));
}

TEST(NAME, copy)
{
    ik_vec3_t v1;
    ik_vec3_set(v1.f, 1, 2, 3);
    ik_vec3_t v2;
    ik_vec3_set(v2.f, 4, 5, 6);
    ik_vec3_copy(v1.f, v2.f);
    EXPECT_THAT(v1.x, DoubleEq(4));
    EXPECT_THAT(v1.y, DoubleEq(5));
    EXPECT_THAT(v1.z, DoubleEq(6));
}

TEST(NAME, set_zero)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 2, 3);
    ik_vec3_set_zero(v.f);
    EXPECT_THAT(v.x, DoubleEq(0));
    EXPECT_THAT(v.y, DoubleEq(0));
    EXPECT_THAT(v.z, DoubleEq(0));
}

TEST(NAME, add_scalar)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 2, 3);
    ik_vec3_add_scalar(v.f, 3);
    EXPECT_THAT(v.x, DoubleEq(4));
    EXPECT_THAT(v.y, DoubleEq(5));
    EXPECT_THAT(v.z, DoubleEq(6));
}

TEST(NAME, add_vec3)
{
    ik_vec3_t v1;
    ik_vec3_set(v1.f, 1, 2, 3);
    ik_vec3_t v2;
    ik_vec3_set(v2.f, 4, 5, 6);
    ik_vec3_add_vec3(v1.f, v2.f);
    EXPECT_THAT(v1.x, DoubleEq(5));
    EXPECT_THAT(v1.y, DoubleEq(7));
    EXPECT_THAT(v1.z, DoubleEq(9));
}

TEST(NAME, sub_scalar)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 2, 3);
    ik_vec3_sub_scalar(v.f, 2);
    EXPECT_THAT(v.x, DoubleEq(-1));
    EXPECT_THAT(v.y, DoubleEq(0));
    EXPECT_THAT(v.z, DoubleEq(1));
}

TEST(NAME, sub_vec3)
{
    ik_vec3_t v1;
    ik_vec3_set(v1.f, 1, 2, 3);
    ik_vec3_t v2;
    ik_vec3_set(v2.f, 4, 5, 6);
    ik_vec3_sub_vec3(v1.f, v2.f);
    EXPECT_THAT(v1.x, DoubleEq(-3));
    EXPECT_THAT(v1.y, DoubleEq(-3));
    EXPECT_THAT(v1.z, DoubleEq(-3));
}

TEST(NAME, mul_scalar)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 2, 3);
    ik_vec3_mul_scalar(v.f, 3);
    EXPECT_THAT(v.x, DoubleEq(3));
    EXPECT_THAT(v.y, DoubleEq(6));
    EXPECT_THAT(v.z, DoubleEq(9));
}

TEST(NAME, mul_vec3)
{
    ik_vec3_t v1;
    ik_vec3_set(v1.f, 1, 2, 3);
    ik_vec3_t v2;
    ik_vec3_set(v2.f, 4, 5, 6);
    ik_vec3_mul_vec3(v1.f, v2.f);
    EXPECT_THAT(v1.x, DoubleEq(4));
    EXPECT_THAT(v1.y, DoubleEq(10));
    EXPECT_THAT(v1.z, DoubleEq(18));
}

TEST(NAME, div_scalar)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 2, 3);
    ik_vec3_div_scalar(v.f, 3);
    EXPECT_THAT(v.x, DoubleEq(1.0/3));
    EXPECT_THAT(v.y, DoubleEq(2.0/3));
    EXPECT_THAT(v.z, DoubleEq(3.0/3));
}

TEST(NAME, div_vec3)
{
    ik_vec3_t v1;
    ik_vec3_set(v1.f, 1, 2, 3);
    ik_vec3_t v2;
    ik_vec3_set(v2.f, 4, 5, 6);
    ik_vec3_div_vec3(v1.f, v2.f);
    EXPECT_THAT(v1.x, DoubleEq(0.25));
    EXPECT_THAT(v1.y, DoubleEq(0.4));
    EXPECT_THAT(v1.z, DoubleEq(0.5));
}

TEST(NAME, length_squared_positive_numbers)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 2, 3);
    EXPECT_THAT(ik_vec3.length_squared(v_f), DoubleEq(14));
}

TEST(NAME, length_squared_negative_numbers)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, -1, -2, -3);
    EXPECT_THAT(ik_vec3.length_squared(v_f), DoubleEq(14));
}

TEST(NAME, length_squared_zero)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, 0, 0, 0);
    EXPECT_THAT(ik_vec3.length_squared(v_f), DoubleEq(0));
}

TEST(NAME, length_positive_numbers)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 2, 3);
    EXPECT_THAT(ik_vec3.length(v_f), DoubleEq(sqrt(14)));
}

TEST(NAME, length_negative_numbers)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, -1, -2, -3);
    EXPECT_THAT(ik_vec3.length(v_f), DoubleEq(sqrt(14)));
}

TEST(NAME, length_zero)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, 0, 0, 0);
    EXPECT_THAT(ik_vec3.length(v_f), DoubleEq(0));
}

TEST(NAME, normalize_positive_numbers)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 2, 3);
    ik_vec3_normalize(v.f);
    EXPECT_THAT(v.x, DoubleEq(1.0 / sqrt(14)));
    EXPECT_THAT(v.y, DoubleEq(2.0 / sqrt(14)));
    EXPECT_THAT(v.z, DoubleEq(3.0 / sqrt(14)));
}

TEST(NAME, normalize_negative_numbers)
{
    ik_vec3_t v;
    ik_vec3_set(v.f, -1, -2, -3);
    ik_vec3_normalize(v.f);
    EXPECT_THAT(v.x, DoubleEq(-1.0 / sqrt(14)));
    EXPECT_THAT(v.y, DoubleEq(-2.0 / sqrt(14)));
    EXPECT_THAT(v.z, DoubleEq(-3.0 / sqrt(14)));
}

TEST(NAME, normalize_zero)
{
    // Due to vectors being used as directions, make the default direction 1,0,0
    ik_vec3_t v;
    ik_vec3_set(v.f, 0, 0, 0);
    ik_vec3_normalize(v.f);
    EXPECT_THAT(v.x, DoubleEq(1));
    EXPECT_THAT(v.y, DoubleEq(0));
    EXPECT_THAT(v.z, DoubleEq(0));
}

TEST(NAME, dot)
{
    ik_vec3_t v1;
    ik_vec3_set(v1.f, 1, 2, 3);
    ik_vec3_t v2;
    ik_vec3_set(v2.f, 4, 5, 6);
    EXPECT_THAT(ik_vec3.dot(v1.f, v2_f), DoubleEq(32));
}

TEST(NAME, cross)
{
    ik_vec3_t v1;
    ik_vec3_set(v1.f, 1, 2, 3);
    ik_vec3_t v2;
    ik_vec3_set(v2.f, 4, 5, 6);
    ik_vec3_cross(v1.f, v2.f);
    EXPECT_THAT(v1.x, DoubleEq(-3));
    EXPECT_THAT(v1.y, DoubleEq(6));
    EXPECT_THAT(v1.z, DoubleEq(-3));
}

TEST(NAME, ncross)
{
    ik_vec3_t v1;
    ik_vec3_set(v1.f, 1, 2, 3);
    ik_vec3_t v2;
    ik_vec3_set(v2.f, 4, 5, 6);
    ik_vec3_ncross(v1.f, v2.f);
    EXPECT_THAT(v1.x, DoubleEq(3));
    EXPECT_THAT(v1.y, DoubleEq(-6));
    EXPECT_THAT(v1.z, DoubleEq(3));
}

TEST(NAME, rotate_vector_45_degree)
{
    ik_quat_t q;
    ik_quat_set_axis_angle(q.f, 0, 1, 0, 45.0*pi/180);

    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 0, 0);
    ik_vec3_rotate(v.f, q.f);

    EXPECT_THAT(v.x, DoubleEq(1/sqrt(2)));
    EXPECT_THAT(v.y, DoubleEq(0));
    EXPECT_THAT(v.z, DoubleEq(-1/sqrt(2)));
}

TEST(NAME, rotate_vector_120_degree_steps)
{
    ik_quat_t q;
    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 0, 0);
    ik_quat_set_axis_angle(q.f, 1, 1, 1, 120 * pi / 180);

    ik_vec3_rotate(v.f, q.f);
    EXPECT_THAT(v.x, DoubleNear(0, 1e-15));
    EXPECT_THAT(v.y, DoubleNear(1, 1e-15));
    EXPECT_THAT(v.z, DoubleNear(0, 1e-15));

    ik_vec3_rotate(v.f, q.f);
    EXPECT_THAT(v.x, DoubleNear(0, 1e-15));
    EXPECT_THAT(v.y, DoubleNear(0, 1e-15));
    EXPECT_THAT(v.z, DoubleNear(1, 1e-15));

    ik_vec3_rotate(v.f, q.f);
    EXPECT_THAT(v.x, DoubleNear(1, 1e-15));
    EXPECT_THAT(v.y, DoubleNear(0, 1e-15));
    EXPECT_THAT(v.z, DoubleNear(0, 1e-15));
}

TEST(NAME, rotate_vector_there_and_back)
{
    ik_quat_t q;
    ik_vec3_t v;
    ik_vec3_set(v.f, 3, 7, 4);
    ik_quat_set_axis_angle(q.f, 63, 9679, 34, 48.32 * pi / 180);
    ik_vec3_rotate(v.f, q.f);
    ik_quat_conj(q.f);
    ik_vec3_rotate(v.f, q.f);
    EXPECT_THAT(v.x, DoubleNear(3, 1e-15));
    EXPECT_THAT(v.y, DoubleNear(7, 1e-15));
    EXPECT_THAT(v.z, DoubleNear(4, 1e-15));
}

TEST(NAME, nrotate_vector_45_degree)
{
    ik_quat_t q;
    ik_quat_set_axis_angle(q.f, 0, 1, 0, 45.0*pi/180);

    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 0, 0);
    ik_vec3_nrotate(v.f, q.f);

    EXPECT_THAT(v.x, DoubleEq(1/sqrt(2)));
    EXPECT_THAT(v.y, DoubleEq(0));
    EXPECT_THAT(v.z, DoubleEq(1/sqrt(2)));
}

TEST(NAME, nrotate_vector_120_degree_steps)
{
    ik_quat_t q;
    ik_vec3_t v;
    ik_vec3_set(v.f, 1, 0, 0);
    ik_quat_set_axis_angle(q.f, 1, 1, 1, 120 * pi / 180);

    ik_vec3_nrotate(v.f, q.f);
    EXPECT_THAT(v.x, DoubleNear(0, 1e-15));
    EXPECT_THAT(v.y, DoubleNear(0, 1e-15));
    EXPECT_THAT(v.z, DoubleNear(1, 1e-15));

    ik_vec3_nrotate(v.f, q.f);
    EXPECT_THAT(v.x, DoubleNear(0, 1e-15));
    EXPECT_THAT(v.y, DoubleNear(1, 1e-15));
    EXPECT_THAT(v.z, DoubleNear(0, 1e-15));

    ik_vec3_nrotate(v.f, q.f);
    EXPECT_THAT(v.x, DoubleNear(1, 1e-15));
    EXPECT_THAT(v.y, DoubleNear(0, 1e-15));
    EXPECT_THAT(v.z, DoubleNear(0, 1e-15));
}

TEST(NAME, nrotate_vector_there_and_back)
{
    ik_quat_t q;
    ik_vec3_t v;
    ik_vec3_set(v.f, 3, 7, 4);
    ik_quat_set_axis_angle(q.f, 63, 9679, 34, 48.32 * pi / 180);
    ik_vec3_nrotate(v.f, q.f);
    ik_quat_conj(q.f);
    ik_vec3_nrotate(v.f, q.f);
    EXPECT_THAT(v.x, DoubleNear(3, 1e-15));
    EXPECT_THAT(v.y, DoubleNear(7, 1e-15));
    EXPECT_THAT(v.z, DoubleNear(4, 1e-15));
}


TEST(NAME, project)
{
    ik_vec3_t u;
    ik_vec3_set(u.f, 2, 2, 2);
    ik_vec3_t v;
    ik_vec3_set(v.f, 7, 0, 7);
    ik_vec3_project_from_vec3(v.f, u.f);
    EXPECT_THAT(v.x, DoubleNear(7.0 * 28 / 98, 1e-15));
}
