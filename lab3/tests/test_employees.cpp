#include <gtest/gtest.h>
#include "employees/Picker.hpp"
#include "employees/ShiftSchedule.hpp"

using namespace wms;

TEST(EmployeesTest, PickerRecordsItems) {
    Picker p("E-01", "Alice");
    p.recordPick();
    p.recordPick();
    EXPECT_EQ(p.itemsPicked(), 2);
}
