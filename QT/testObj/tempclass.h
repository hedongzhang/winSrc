#ifndef TEMPCLASS_H
#define TEMPCLASS_H

class tempclass
{
public:
    tempclass();
    tempclass(int value);
    tempclass(tempclass& value);

    void printt();

    operator int();

private:
    int value;

};

#endif // TEMPCLASS_H
