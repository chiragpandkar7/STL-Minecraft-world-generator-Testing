#include "pch.h"
#include "Point3D.h"



TEST(Point3DTest, DefaultConstructor) {
    Point3D point;
    EXPECT_FLOAT_EQ(point.x(), 0.0f);
    EXPECT_FLOAT_EQ(point.y(), 0.0f);
    EXPECT_FLOAT_EQ(point.z(), 0.0f);
}

TEST(Point3DTest, ParameterizedConstructor) {
    Point3D point(1.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(point.x(), 1.0f);
    EXPECT_FLOAT_EQ(point.y(), 2.0f);
    EXPECT_FLOAT_EQ(point.z(), 3.0f);
}

TEST(Point3DTest, SettersAndGetters) {
    Point3D point;
    point.setX(4.0f);
    point.setY(4.0f);
    point.setZ(4.0f);

    EXPECT_FLOAT_EQ(point.x(), 4.0f);
    EXPECT_FLOAT_EQ(point.y(), 4.0f);
    EXPECT_FLOAT_EQ(point.z(), 4.0f);
}

TEST(Point3DTest, OperatorOverloadingAddition) {
    Point3D p1(1.0, 2.0, 3.0);
    Point3D p2(4.0, 5.0, 6.0);
    Point3D result = p1 + p2;
    EXPECT_FLOAT_EQ(result.x(), 5.0f);
    EXPECT_FLOAT_EQ(result.y(), 7.0f);
    EXPECT_FLOAT_EQ(result.z(), 9.0f);
}

TEST(Point3DTest, OperatorOverloadingSubtraction) {
    Point3D p1(5.0, 7.0, 9.0);
    Point3D p2(1.0, 2.0, 3.0);
    Point3D result = p1 - p2;
    EXPECT_FLOAT_EQ(result.x(), 4.0f);
    EXPECT_FLOAT_EQ(result.y(), 5.0f);
    EXPECT_FLOAT_EQ(result.z(), 6.0f);
}

TEST(Point3DTest, OperatorOverloadingMultiplication) {
    Point3D p1(2.0, 3.0, 4.0);
    double scalar = 2.5;
    Point3D result = p1 * scalar;
    EXPECT_FLOAT_EQ(result.x(), 5.0f);
    EXPECT_FLOAT_EQ(result.y(), 7.5f);
    EXPECT_FLOAT_EQ(result.z(), 10.0f);
}

TEST(Point3DTest, OperatorOverloadingDivision) {
    Point3D p1(10.0, 15.0, 20.0);
    double scalar = 2.0;
    Point3D result = p1 / scalar;
    EXPECT_FLOAT_EQ(result.x(), 5.0f);
    EXPECT_FLOAT_EQ(result.y(), 7.5f);
    EXPECT_FLOAT_EQ(result.z(), 10.0f);
}

TEST(Point3DTest, OperatorOverloadingCrossProduct) {
    Point3D p1(2.0, 3.0, 4.0);
    Point3D p2(5.0, 6.0, 7.0);
    Point3D result = p1 ^ p2;
    EXPECT_FLOAT_EQ(result.x(), -3.0f);
    EXPECT_FLOAT_EQ(result.y(), 6.0f);
    EXPECT_FLOAT_EQ(result.z(), -3.0f);
}

TEST(Point3DTest, OperatorOverloadingDotProduct) {
    Point3D p1(2.0, 3.0, 4.0);
    Point3D p2(5.0, 6.0, 7.0);
    double result = p1 & p2;
    EXPECT_FLOAT_EQ(result, 56.0f);
}

TEST(Point3DTest, OperatorOverloadingCompoundAssignment) {
    Point3D p1(2.0, 3.0, 4.0);
    Point3D p2(1.0, 1.0, 1.0);

    // Compound addition
    p1 += p2;
    EXPECT_FLOAT_EQ(p1.x(), 3.0f);
    EXPECT_FLOAT_EQ(p1.y(), 4.0f);
    EXPECT_FLOAT_EQ(p1.z(), 5.0f);

    // Compound subtraction
    p1 -= p2;
    EXPECT_FLOAT_EQ(p1.x(), 2.0f);
    EXPECT_FLOAT_EQ(p1.y(), 3.0f);
    EXPECT_FLOAT_EQ(p1.z(), 4.0f);

    // Compound multiplication
    p1 *= 2.0;
    EXPECT_FLOAT_EQ(p1.x(), 4.0f);
    EXPECT_FLOAT_EQ(p1.y(), 6.0f);
    EXPECT_FLOAT_EQ(p1.z(), 8.0f);

    // Compound division
    p1 /= 2.0;
    EXPECT_FLOAT_EQ(p1.x(), 2.0f);
    EXPECT_FLOAT_EQ(p1.y(), 3.0f);
    EXPECT_FLOAT_EQ(p1.z(), 4.0f);
}

TEST(Point3DTest, NormalMethod) {
    Point3D p(3.0, 4.0, 0.0);
    double result = p.normal();
    EXPECT_FLOAT_EQ(result, 5.0f);
}