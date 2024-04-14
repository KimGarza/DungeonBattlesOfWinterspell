#pragma once
#include "IPlace.h"
#include <string>
#include <memory>
#include <vector>

class IMap {

private:
    std::string name_;
    std::vector <std::shared_ptr<IPlace>> places_;
    std::shared_ptr<IPlace> currentPlace_;

public:
    virtual std::string GetName() = 0;
    virtual std::shared_ptr<IPlace> GetCurrentPlace() = 0;
    virtual std::vector<std::shared_ptr<IPlace>> GetPlaces() = 0;

    virtual void SetCurrentPlace() = 0;
};

