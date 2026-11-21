#include <gtest/gtest.h>
#include "core/SKU.hpp"
#include "core/Barcode.hpp"
#include "core/Money.hpp"
#include "core/Quantity.hpp"
#include "core/Address.hpp"
#include "core/Contact.hpp"
#include "core/Dimensions.hpp"
#include "core/Weight.hpp"
#include "core/DateRange.hpp"
#include "core/ValidationResult.hpp"
#include "exceptions/InvalidSKUException.hpp"
#include "exceptions/InvalidBarcodeException.hpp"
#include "exceptions/InvalidQuantityException.hpp"
#include "exceptions/WarehouseException.hpp"

using namespace wms;
using namespace wms::core;

TEST(SKU, ValidFormatAccepted) { EXPECT_NO_THROW(SKU("ABC-1234")); }
TEST(SKU, InvalidFormatRejected) { EXPECT_THROW(SKU("abc-1234"), InvalidSKUException); }
TEST(Barcode, ChecksumValid) { Barcode b("4006381333931"); EXPECT_TRUE(b.isValidChecksum()); }
TEST(Money, Addition) { EXPECT_EQ((Money(100) + Money(50)).cents(), 150); }
TEST(Money, SubtractionUnderflowThrows) { EXPECT_THROW(Money(50) - Money(100), InvalidQuantityException); }
TEST(Quantity, UnderflowThrows) { EXPECT_THROW(Quantity(3) - Quantity(4), InvalidQuantityException); }
TEST(Address, EmptyFieldRejected) { EXPECT_THROW(Address("", "Berlin", "10115", "DE"), WarehouseException); }
TEST(Contact, InvalidEmailRejected) { EXPECT_THROW(Contact("not-an-email", "+49123456"), WarehouseException); }
TEST(Dimensions, VolumeComputed) { EXPECT_EQ(Dimensions(10, 20, 30).volumeMm3(), 6000u); }
TEST(Weight, Addition) { EXPECT_EQ((Weight(500) + Weight(700)).grams(), 1200u); }

// THE NEW TESTS FOR DATERANGE
TEST(DateRange, ValidRange) {
    auto start = std::chrono::system_clock::now();
    auto end = start + std::chrono::hours(5);
    EXPECT_NO_THROW(DateRange(start, end));
}
TEST(DateRange, InvertedRangeThrows) {
    auto start = std::chrono::system_clock::now();
    auto end = start - std::chrono::hours(1);
    EXPECT_THROW(DateRange(start, end), InvalidQuantityException);
}
TEST(DateRange, Contains) {
    auto start = std::chrono::system_clock::now();
    DateRange r(start, start + std::chrono::hours(5));
    EXPECT_TRUE(r.contains(start + std::chrono::hours(2)));
}
TEST(DateRange, LengthInHours) {
    auto start = std::chrono::system_clock::now();
    EXPECT_EQ(DateRange(start, start + std::chrono::hours(3)).lengthInHours(), 3);
}

TEST(Weight, Multiplication) {
    Weight w(100);
    EXPECT_EQ(w.kilograms(), 0.1);
}

TEST(Money, MultiplicationAndComparison) {
    EXPECT_EQ((Money(100) * 3).cents(), 300);
    EXPECT_TRUE(Money(50) < Money(100));
}

TEST(Quantity, AdditionAndComparison) {
    EXPECT_EQ((Quantity(3) + Quantity(4)).units(), 7u);
    EXPECT_TRUE(Quantity(1) < Quantity(2));
}
