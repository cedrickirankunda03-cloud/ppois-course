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

TEST(SKU, ValidFormatAccepted) {
    EXPECT_NO_THROW(SKU("ABC-1234"));
    EXPECT_NO_THROW(SKU("XYZ-999999"));
}

TEST(SKU, InvalidFormatRejected) {
    EXPECT_THROW(SKU("abc-1234"), InvalidSKUException);
    EXPECT_THROW(SKU("AB-1234"), InvalidSKUException);
    EXPECT_THROW(SKU("ABC-12"), InvalidSKUException);
    EXPECT_THROW(SKU(""), InvalidSKUException);
}

TEST(SKU, Equality) {
    SKU a("ABC-1234"), b("ABC-1234"), c("XYZ-5678");
    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
    EXPECT_TRUE(a < c);
}

TEST(Barcode, ValidLengthAccepted) { EXPECT_NO_THROW(Barcode("1234567890123")); }

TEST(Barcode, WrongLengthRejected) {
    EXPECT_THROW(Barcode("123"), InvalidBarcodeException);
    EXPECT_THROW(Barcode("12345678901234"), InvalidBarcodeException);
}

TEST(Barcode, NonDigitsRejected) { EXPECT_THROW(Barcode("12345678901a3"), InvalidBarcodeException); }

TEST(Barcode, ChecksumValid) {
    Barcode b("4006381333931");
    EXPECT_TRUE(b.isValidChecksum());
}

TEST(Money, ConstructionRejectsNegative) {
    EXPECT_THROW(Money(-1), InvalidQuantityException);
    EXPECT_NO_THROW(Money(0));
}

TEST(Money, Addition) { EXPECT_EQ((Money(100) + Money(50)).cents(), 150); }

TEST(Money, SubtractionUnderflowThrows) {
    EXPECT_THROW(Money(50) - Money(100), InvalidQuantityException);
    EXPECT_EQ((Money(100) - Money(50)).cents(), 50);
}

TEST(Money, Multiplication) {
    EXPECT_EQ((Money(100) * 3).cents(), 300);
    EXPECT_THROW(Money(100) * -1, InvalidQuantityException);
}

TEST(Money, Comparisons) {
    EXPECT_TRUE(Money(50) < Money(100));
    EXPECT_TRUE(Money(100) > Money(50));
    EXPECT_TRUE(Money(100) == Money(100));
}

TEST(Quantity, Addition) { EXPECT_EQ((Quantity(3) + Quantity(4)).units(), 7u); }

TEST(Quantity, UnderflowThrows) {
    EXPECT_THROW(Quantity(3) - Quantity(4), InvalidQuantityException);
    EXPECT_EQ((Quantity(4) - Quantity(3)).units(), 1u);
}

TEST(Quantity, Comparisons) {
    EXPECT_TRUE(Quantity(1) < Quantity(2));
    EXPECT_TRUE(Quantity(2) >= Quantity(2));
    EXPECT_TRUE(Quantity(0).isZero());
}

TEST(Address, ValidConstruction) {
    Address a("Main St 1", "Berlin", "10115", "Germany");
    EXPECT_EQ(a.city(), "Berlin");
    EXPECT_NE(a.format().find("Berlin"), std::string::npos);
}

TEST(Address, EmptyFieldRejected) {
    EXPECT_THROW(Address("", "Berlin", "10115", "DE"), WarehouseException);
    EXPECT_THROW(Address("Main", "", "10115", "DE"), WarehouseException);
    EXPECT_THROW(Address("Main", "Berlin", "", "DE"), WarehouseException);
    EXPECT_THROW(Address("Main", "Berlin", "10115", ""), WarehouseException);
}

TEST(Contact, ValidAccepted) { EXPECT_NO_THROW(Contact("user@example.com", "+49123456")); }

TEST(Contact, InvalidEmailRejected) {
    EXPECT_THROW(Contact("not-an-email", "+49123456"), WarehouseException);
    EXPECT_THROW(Contact("", "+49123456"), WarehouseException);
}

TEST(Contact, EmptyPhoneRejected) { EXPECT_THROW(Contact("user@example.com", ""), WarehouseException); }

TEST(Dimensions, VolumeComputed) { EXPECT_EQ(Dimensions(10, 20, 30).volumeMm3(), 6000u); }

TEST(Dimensions, ZeroRejected) {
    EXPECT_THROW(Dimensions(0, 20, 30), InvalidQuantityException);
    EXPECT_THROW(Dimensions(10, 0, 30), InvalidQuantityException);
    EXPECT_THROW(Dimensions(10, 20, 0), InvalidQuantityException);
}

TEST(Dimensions, FitsInside) {
    Dimensions small(10, 10, 10), big(20, 20, 20);
    EXPECT_TRUE(small.fitsInside(big));
    EXPECT_FALSE(big.fitsInside(small));
}

TEST(Weight, Addition) { EXPECT_EQ((Weight(500) + Weight(700)).grams(), 1200u); }
TEST(Weight, Kilograms) { EXPECT_DOUBLE_EQ(Weight(1500).kilograms(), 1.5); }

// --- THE NEW TESTS FOR DATERANGE ---
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
    EXPECT_FALSE(r.contains(start + std::chrono::hours(5)));
}

TEST(DateRange, LengthInHours) {
    auto start = std::chrono::system_clock::now();
    EXPECT_EQ(DateRange(start, start + std::chrono::hours(3)).lengthInHours(), 3);
}

TEST(ValidationResult, SuccessAndFailure) {
    auto ok = ValidationResult::success();
    auto bad = ValidationResult::failure("oops");
    EXPECT_TRUE(ok.ok());
    EXPECT_FALSE(bad.ok());
    EXPECT_EQ(bad.message(), "oops");
    EXPECT_TRUE(static_cast<bool>(ok));
    EXPECT_FALSE(static_cast<bool>(bad));
}

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
    EXPECT_FALSE(r.contains(start + std::chrono::hours(5)));
}

TEST(DateRange, LengthInHours) {
    auto start = std::chrono::system_clock::now();
    EXPECT_EQ(DateRange(start, start + std::chrono::hours(3)).lengthInHours(), 3);
}