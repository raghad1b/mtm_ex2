#include "Auxiliaries.h"

std::ostream &mtm::printGameBoard(std::ostream &os, const char *begin,
                                  const char *end, unsigned int width) {
    std::string delimiter = std::string(2 * width + 1, '*');
    const char *temp = begin;
    os << delimiter << std::endl;
    while (temp != end) {
        os << "|" << (*temp);
        ++temp;
        if ((temp - begin) % width == 0)
            os << "|" << std::endl;
    }
    os << delimiter;
    return os;
}


// from previous parts
mtm::Dimensions::Dimensions(int row_t, int col_t) : row(row_t), col(col_t) {}

std::string mtm::Dimensions::toString() const {
    return "(" + std::to_string(row) + "," + std::to_string(col) + ")";
}

bool mtm::Dimensions::operator==(const Dimensions &other) const {
    return (row == other.row) and (col == other.col);
}

bool mtm::Dimensions::operator!=(const Dimensions &other) const {
    return not(*this == other);
}

int mtm::Dimensions::getRow() const {
    return row;
}

int mtm::Dimensions::getCol() const {
    return col;
}

std::string mtm::printMatrix(const int *matrix, const Dimensions &dim) {
    std::string matrix_str;
    int col_length = dim.getCol();
    for (int i = 0; i < dim.getRow(); i++) {
        for (int j = 0; j < col_length; j++) {
            matrix_str += std::to_string(*(matrix + col_length * i + j)) + " ";
        }
        matrix_str += "\n";
    }
    matrix_str += "\n";
    return matrix_str;
}