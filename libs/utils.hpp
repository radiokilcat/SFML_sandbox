#pragma once

class Uuid
{
public:
    static unsigned int generate()
    {
        static unsigned int value;
        return value++;
    }
};
