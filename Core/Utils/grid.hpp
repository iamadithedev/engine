#pragma once

template <typename type, int32_t _rows, int32_t _columns>
class Grid
{
public:
    type& item_at(int32_t row, int32_t column)
    {
        assert(row    < _rows);
        assert(column < _columns);

        return _data[row][column];
    }

    [[nodiscard]] int32_t rows()    const
    {
        return _rows;
    }
    [[nodiscard]] int32_t columns() const
    {
        return _columns;
    }

private:
    type _data[_rows][_columns];
};