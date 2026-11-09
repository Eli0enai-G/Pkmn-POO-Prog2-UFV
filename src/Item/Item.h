#ifndef ITEM_H
#define ITEM_H

class Pokemon;

class Item {
public:
    Item() = default;
    virtual ~Item() = default;

    virtual bool usar(Pokemon& alvo) = 0;
};

#endif