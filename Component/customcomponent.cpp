#include "customcomponent.h"

CustomComponent::CustomComponent(QWidget *parent) : QWidget(parent)
{

}

bool CustomComponent::getIsEnable()
{
    return this->bIsEnable;
}

void CustomComponent::setIsEnable(bool bIsEnable)
{
    this->bIsEnable = bIsEnable;
}
