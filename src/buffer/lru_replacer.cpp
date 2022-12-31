//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// lru_replacer.cpp
//
// Identification: src/buffer/lru_replacer.cpp
//
// Copyright (c) 2015-2019, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "buffer/lru_replacer.h"
#include <algorithm>

namespace bustub {

LRUReplacer::LRUReplacer(size_t num_pages) {}

LRUReplacer::~LRUReplacer() = default;

bool LRUReplacer::Victim(frame_id_t *frame_id) { 
    if (Size() == 0) {
        *frame_id = INVALID_PAGE_ID;
        return false;
    }
    *frame_id = lru_list_.back();
    lru_list_.pop_back();
    return true;
}

void LRUReplacer::Pin(frame_id_t frame_id) {
    auto it = std::find(lru_list_.begin(), lru_list_.end(), frame_id);
    if (it != lru_list_.end()) {
        lru_list_.erase(it);
    }
}

void LRUReplacer::Unpin(frame_id_t frame_id) {
    auto it = std::find(lru_list_.begin(), lru_list_.end(), frame_id);
    if (it == lru_list_.end()) {
        lru_list_.push_front(frame_id);
    }
}

size_t LRUReplacer::Size() { 
    return lru_list_.size();
}

}  // namespace bustub
