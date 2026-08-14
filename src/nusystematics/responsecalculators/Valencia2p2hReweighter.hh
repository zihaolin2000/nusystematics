// BDTCalculator.hh
#pragma once

#include "BDTReweighter_json.hh"

#include <array>
#include <string>

class Valencia2p2hReweighter {
public:
    explicit Valencia2p2hReweighter(const std::string& json_file);

    double GetWeight(const std::array& nFeatures) const;

private:
    BDTReweight::JSONReweighter reweighter_;
};
