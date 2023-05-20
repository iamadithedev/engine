#pragma once

class File
{
public:
    template<typename  type>
    static std::vector<type> read(const std::string& file)
    {
        int32_t flag = std::ios::ate;

        if constexpr (std::is_same_v<type, std::byte>)
        {
            flag |= std::ios::binary;
        }

        std::ifstream stream(file, flag);
        assert(stream.is_open());

        auto   size = stream.tellg();
        assert(size > 0);

        std::vector<type> content(size); // TODO maybe this will work faster with reserve?

        stream.seekg(0, std::ios::beg);
        stream.read(reinterpret_cast<char*>(content.data()), size);

        return content;
    }
};
