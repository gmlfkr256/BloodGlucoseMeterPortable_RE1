#ifndef GLOBALCLASS_H
#define GLOBALCLASS_H


class GlobalClass
{
public:
    static GlobalClass& instance();

    GlobalClass(const GlobalClass&) = delete;
    GlobalClass& operator = (const GlobalClass&) = delete;

private:
    GlobalClass() = default;
    ~GlobalClass() = default;
};

#endif // GLOBALCLASS_H
