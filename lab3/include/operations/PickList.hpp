#pragma once
#include <vector>
#include "PickTask.hpp"
namespace wms {
class PickList {
    std::vector<PickTask> tasks_;
public:
    void addTask(const PickTask& task) { tasks_.push_back(task); }
    size_t taskCount() const noexcept { return tasks_.size(); }
};
}
