#include "pch.h"
#include "Triangle.h"

TEST(TriangleTest, DefaultConstructor) {
    Triangle triangle;
    EXPECT_EQ(triangle.p1(), Point3D(0, 0, 0));
    EXPECT_EQ(triangle.p2(), Point3D(0, 0, 0));
    EXPECT_EQ(triangle.p3(), Point3D(0, 0, 0));
    EXPECT_EQ(triangle.normal(), Point3D(0, 0, 0));
}

TEST(TriangleTest, ParameterizedConstructorPoints) {
    Point3D p1(1, 2, 3);
    Point3D p2(4, 5, 6);
    Point3D p3(7, 8, 9);
    Triangle triangle(p1, p2, p3);
    EXPECT_EQ(triangle.p1(), p1);
    EXPECT_EQ(triangle.p2(), p2);
    EXPECT_EQ(triangle.p3(), p3);
    EXPECT_EQ(triangle.normal(), Point3D(0, 0, 0));
}

TEST(TriangleTest, ParameterizedConstructorNormalPoints) {
    Point3D normal(1, 0, 0);
    Point3D p1(1, 2, 3);
    Point3D p2(4, 5, 6);
    Point3D p3(7, 8, 9);
    Triangle triangle(normal, p1, p2, p3);
    EXPECT_EQ(triangle.p1(), p1);
    EXPECT_EQ(triangle.p2(), p2);
    EXPECT_EQ(triangle.p3(), p3);
    EXPECT_EQ(triangle.normal(), normal);
}

TEST(TriangleTest, SettersAndGetters) {
    Triangle triangle;
    Point3D p1(1, 2, 3);
    Point3D p2(4, 5, 6);
    Point3D p3(7, 8, 9);
    Point3D normal(1, 0, 0);

    triangle.setNormal(normal);
    EXPECT_EQ(triangle.normal(), normal);

    triangle.setNormal(Point3D(0, 0, 0));
    EXPECT_EQ(triangle.normal(), Point3D(0, 0, 0));

    triangle.setNormal(Point3D(2, 3, 4));
    EXPECT_EQ(triangle.normal(), Point3D(2, 3, 4));
}


