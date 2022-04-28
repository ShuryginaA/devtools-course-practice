// Copyright 2022 Shurygina A

#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "include/point_in_triangle_app.h"

PointInTriangleApplication::PointInTriangleApplication() { printf("%s\n", ""); }

std::string PointInTriangleApplication::getHelp(const std::string& appname) {
    return  "Application started!" \
            "This is a service which help you to find out\n"
            "wheather the point is in triangle or not.";
}

std::string PointInTriangleApplication::
operator()(int argc, const char** argv) {
    bool result;
    if (argc == 1)
        return getHelp(argv[0]);

    try {
        if (argc > 8) {
            std::string error_msg = "Error occured: Should be less arguments."+ argc;
            throw std::runtime_error(error_msg);
        }
        if (argc < 8) {
            std::string error_msg = "Error occured: Should be more arguments."+ argc;
            throw std::runtime_error(error_msg);
        }
        Point a(parseArgument(argv[1]), parseArgument(argv[2]));
        Point b(parseArgument(argv[3]), parseArgument(argv[4]));
        Point c(parseArgument(argv[5]), parseArgument(argv[6]));
        Point x(parseArgument(argv[7]), parseArgument(argv[8]));
        Triangle tr(a, b, c);
        result = tr.IsPointInTriangle(tr, x);
    }
    catch (std::exception& exp) {
        return exp.what();
    }
    if (result)
        return "True";
    else
        return "False";
}

int PointInTriangleApplication::parseArgument(const char* arg) {
    if (!checkArgument(arg))
        throw std::runtime_error("Error occured: Wrong argument type.");
    return std::stoi(arg);
}

bool PointInTriangleApplication::checkArgument(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

