
#include "Set.h"
#include <gtest/gtest.h>

// 1. Test an empty set
TEST(SetTests, EmptySet)
{
    Set A;
    EXPECT_TRUE(A.empty());
    EXPECT_EQ(A.size(), 0);
}

// 2. Test adding elements and preventing duplicates
TEST(SetTests, AddAndContains)
{
    Set A;
    A.add("a");
    A.add("b");
    A.add("a");

    EXPECT_EQ(A.size(), 2);
    EXPECT_TRUE(A.contains("a"));
    EXPECT_TRUE(A["b"]);
    EXPECT_FALSE(A.contains("c"));
}

// 3. Test removing elements
TEST(SetTests, RemoveElements)
{
    Set A;
    A.add("a");
    A.add("b");

    A.remove("a");
    EXPECT_FALSE(A.contains("a"));
    EXPECT_EQ(A.size(), 1);

    A.remove("missing");
    EXPECT_EQ(A.size(), 1);
}

// 4. Test union
TEST(SetTests, Union)
{
    Set B = Set::fromString("{a, b}");
    Set C = Set::fromString("{b, c}");

    Set result = B + C;

    EXPECT_EQ(result.size(), 3);
    EXPECT_TRUE(result.contains("a"));
    EXPECT_TRUE(result.contains("b"));
    EXPECT_TRUE(result.contains("c"));
}

// 5. Test intersection
TEST(SetTests, Intersection)
{
    Set B = Set::fromString("{a, b}");
    Set C = Set::fromString("{b, c}");

    Set result = B * C;

    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(result.contains("b"));
}

// 6. Test difference
TEST(SetTests, Difference)
{
    Set B = Set::fromString("{a, b}");
    Set C = Set::fromString("{b, c}");

    Set result = B - C;

    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(result.contains("a"));
}

// 7. Test compound assignment operators
TEST(SetTests, CompoundAssignment)
{
    Set B = Set::fromString("{a, b}");
    Set C = Set::fromString("{b, c}");
    Set D = B;

    D += C;
    EXPECT_EQ(D.size(), 3);

    D = B;
    D *= C;
    EXPECT_EQ(D.size(), 1);
    EXPECT_TRUE(D.contains("b"));

    D = B;
    D -= C;
    EXPECT_EQ(D.size(), 1);
    EXPECT_TRUE(D.contains("a"));
}

// 8. Test copy constructor
TEST(SetTests, CopyConstructor)
{
    Set B = Set::fromString("{a, b}");
    Set copied(B);

    EXPECT_TRUE(copied == B);
}

// 9. Test assignment operator
TEST(SetTests, AssignmentOperator)
{
    Set C = Set::fromString("{b, c}");
    Set assigned;
    assigned = C;

    EXPECT_TRUE(assigned == C);
}

// 10. Test equality and inequality
TEST(SetTests, EqualityAndInequality)
{
    Set B = Set::fromString("{a, b}");
    Set same = Set::fromString("{b, a}");
    Set C = Set::fromString("{b, c}");

    EXPECT_TRUE(B == same);
    EXPECT_TRUE(B != C);
}

// 11. Test conversion from and to text
TEST(SetTests, TextConversion)
{
    Set parsed = Set::fromString("{x, y}");

    EXPECT_EQ(parsed.size(), 2);
    EXPECT_EQ(parsed.toString(), "{x, y}");
}

// 12. Test power set
TEST(SetTests, PowerSet)
{
    Set B = Set::fromString("{a, b}");
    Set power = B.powerSet();

    EXPECT_EQ(power.size(), 4);
}

// 13. Test nested-set uniqueness
TEST(SetTests, NestedSetUniqueness)
{
    Set nested = Set::fromString("{{a, b}, {b, a}}");

    EXPECT_EQ(nested.size(), 1);
}


 // 14. Test adding an empty string
TEST(SetTests, AddEmptyString)
{
    Set A;
    A.add("");
    EXPECT_EQ(A.size(), 1);
    EXPECT_TRUE(A.contains(""));
}

// 15. Test equality with different sizes
TEST(SetTests, EqualityDifferentSizes)
{
    Set A = Set::fromString("{a}");
    Set B = Set::fromString("{a, b}");

    EXPECT_FALSE(A == B);
    EXPECT_TRUE(A != B);
}

// 16. Test assigning a set to itself
TEST(SetTests, SelfAssignment)
{
    Set A = Set::fromString("{a, b}");

    A = A;

    EXPECT_EQ(A.size(), 2);
    EXPECT_TRUE(A.contains("a"));
    EXPECT_TRUE(A.contains("b"));
}

// 17. Test empty set text conversion
TEST(SetTests, EmptySetTextConversion)
{
    Set A = Set::fromString("{}");

    EXPECT_TRUE(A.empty());
    EXPECT_EQ(A.toString(), "{}");
}

// 18. Test parsing nested elements
TEST(SetTests, NestedParsing)
{
    Set A = Set::fromString("{a, {b, c}}");

    EXPECT_EQ(A.size(), 2);
    EXPECT_TRUE(A.contains("a"));
    EXPECT_TRUE(A.contains("{b,c}"));
}

// 19. Test parsing spaces and duplicate elements
TEST(SetTests, SpacesAndDuplicates)
{
    Set A = Set::fromString("{a, a, b}");

    EXPECT_EQ(A.size(), 2);
    EXPECT_TRUE(A.contains("a"));
    EXPECT_TRUE(A.contains("b"));
}

// 20. Test power set of an empty set
TEST(SetTests, EmptyPowerSet)
{
    Set A;
    Set result = A.powerSet();

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result.toString(), "{{}}");
}

// 21. Test power set of a single element
TEST(SetTests, SingleElementPowerSet)
{
    Set A = Set::fromString("{a}");
    Set result = A.powerSet();

    EXPECT_EQ(result.size(), 2);
}

// 22. Test removing the only element
TEST(SetTests, RemoveLastElement)
{
    Set A;
    A.add("a");
    A.remove("a");

    EXPECT_TRUE(A.empty());
    EXPECT_EQ(A.size(), 0);
}