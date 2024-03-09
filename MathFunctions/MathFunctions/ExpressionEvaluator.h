#pragma once

#ifdef EXPRESSIONEVALUATOR_EXPORTS
#define EXPRESSIONEVALUATOR_API __declspec(dllexport)
#else
#define EXPRESSIONEVALUATOR_API __declspec(dllimport)
#endif

#include <string> // Include <string> for string usage

extern "C" {
    EXPRESSIONEVALUATOR_API double evaluateExpression(const std::string& expression); // Use std::string instead of const char*
}
