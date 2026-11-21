#pragma once
#include <chrono>
namespace wms { namespace core {
class DateRange {
    std::chrono::system_clock::time_point start_, end_;
public:
    DateRange(std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end);
    const std::chrono::system_clock::time_point& start() const noexcept { return start_; }
    const std::chrono::system_clock::time_point& end() const noexcept { return end_; }
    bool contains(std::chrono::system_clock::time_point tp) const noexcept;
    long long lengthInHours() const noexcept;
};
}}
