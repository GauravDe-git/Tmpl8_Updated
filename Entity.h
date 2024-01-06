#pragma once

#include <vector>

#include "Component.h"

class Entity
{
public:
    template <typename T>
    void AddComponent(T* component)
    {
        components.push_back(component);
    }

    template <typename T>
    T* GetComponent()
    {
        for (Component* component : components)
        {
            if (T* cast = dynamic_cast<T*>(component))
            {
                return cast;
            }
        }
        return nullptr;
    }

    template <typename T>
    void RemoveComponent()
    {
        for (auto it = components.begin(); it != components.end(); ++it)
        {
            if (T* cast = dynamic_cast<T*>(*it))
            {
                components.erase(it);
                delete cast;
                return;
            }
        }
    }
private:
    std::vector<Component*> components;
};
