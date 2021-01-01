#pragma once

uint32_t align(uint32_t offset, uint32_t alignment);

uint64_t align64(uint64_t offset, uint64_t alignment);

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}