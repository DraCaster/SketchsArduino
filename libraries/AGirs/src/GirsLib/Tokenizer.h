#pragma once

#include <InfraredTypes.h>
#include <limits.h>

class Tokenizer {
private:
    static const int invalidIndex = -1;

    int index; // signed since invalidIndex is possible
    const String& payload;
    void trim();

public:
    Tokenizer(const String &str);
    //Tokenizer(const char *str);
    virtual ~Tokenizer();

    String getToken();
    String getRest();
    String getLine();
    long getInt();
    microseconds_t getMicroseconds();
    frequency_t getFrequency();

    static const int invalid = INT_MAX;
};
