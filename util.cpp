template<typename T>
T clamp(T v, T lo, T hi)
{
    if(v < lo) return lo;
    if(v > hi) return hi;
    return v;
}

template<typename T>
T wrap(T v, T limit)
{
    T r = v;
    if(r < 0) r = limit + r;
    while(r > limit) r -= limit;
    return r;
}

template<typename T>
string to_string(T value)
{
    string buffer;
    sprintf((char*)buffer.c_str(), "%i", value);
    return buffer.c_str();
}