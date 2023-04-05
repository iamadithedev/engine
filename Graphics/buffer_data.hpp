#pragma once

class BufferData
{
public:
    BufferData(const void* ptr, uint32_t size);

    [[nodiscard]] const void* ptr() const;
    [[nodiscard]] uint32_t   size() const;

    template<typename type_t>
    static BufferData make_data_of_type(const std::vector<type_t>& buffer)
    {
        return { buffer.data(), static_cast<uint32_t>(buffer.size() * sizeof(type_t)) };
    }

private:
    const void* _ptr;
    uint32_t   _size;
};