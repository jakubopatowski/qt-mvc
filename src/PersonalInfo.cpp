#include "PersonalInfo.hpp"

std::vector< PersonalInfo > PersonalInfo::getSomePersonalInfo() {
    std::vector< PersonalInfo > result{ { 1, "Jakub", "Opatowski", 39 },
                                        { 2, "Natalia", "Opatowska", 39 },
                                        { 3, "Zofia", "Opatowska", 8 },
                                        { 4, "Hanna", "Opatowska", 6 } };
    return result;
}