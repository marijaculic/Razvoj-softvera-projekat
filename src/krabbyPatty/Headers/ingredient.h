#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "item.h"
#include <QObject>

class Ingredient : public Item
{
public:
    Ingredient(qreal playerWidth, QString imagePath);
    void collect() override;
    ~Ingredient();
};

#endif // INGREDIENT_H
