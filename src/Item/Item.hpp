#ifndef ITEM_HPP
#define ITEM_HPP

class Pokemon;

class Item {
public:
    Item() = default;
    virtual ~Item() = default;

    virtual bool usar(Pokemon& alvo) = 0;
};

#endif