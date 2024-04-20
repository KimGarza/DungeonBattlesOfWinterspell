#pragma once
#include "IPlace.h"
#include <string>
#include <memory>
#include <string>
#include <vector>

class IMap {

protected:
    ActState act;
    std::vector <std::shared_ptr<IPlace>> places_;
    std::vector<std::string> placeNames_;
    std::shared_ptr<IPlace> currentPlace_;

public:
    virtual ActState GetAct() = 0;
    virtual std::shared_ptr<IPlace> GetCurrentPlace() = 0;
    virtual std::vector<std::shared_ptr<IPlace>> GetPlaces() = 0;
    virtual std::vector<std::string> GetPlaceNames() = 0;

    virtual void SetCurrentPlace(std::shared_ptr<IPlace> inCurrentPlace) = 0;
    virtual void SetPlaceNames(std::vector<std::string> inPlaceNames) = 0;
};

