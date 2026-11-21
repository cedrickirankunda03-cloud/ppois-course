#include "core/DateRange.hpp"
#include "exceptions/InvalidQuantityException.hpp"
namespace wms { namespace core {
using Clock = std::chrono::system_clock;
DateRange::DateRange(Clock::time_point start, Clock::time_point end) : start_(start), end_(end) {
    if (end_ <= start_) throw InvalidQuantityException("date range end must be after start");
}
bool DateRange::contains(Clock::time_point tp) const noexcept { return tp >= start_ && tp < end_; }
long long DateRange::lengthInHours() const noexcept {
    return static_cast<long long>(std::chrono::duration_cast<std::chrono::minutes>(end_ - start_).count() / 60);
}
}}
