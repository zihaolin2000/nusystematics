// Use BDT json reweighter to reweight from SuSAv2 inclusive to Valencia exclusive 2p2h.


#include "Valencia2p2hReweighter.hh"

namespace nusyst {


    Valencia2p2hReweighter::Valencia2p2hReweighter(const std::string& json_file)
        : reweighter_(json_file)  // JSON parsed once, here
    {}

    double BDTCalculator::GetWeight(
        const MyEvent& event
    ) const {
        // Exact same feature order as BDT training.
        const std::array<float, 8> x = {
            0, 0, 0, 0, 0, 0, 0, 0
        };

        return reweighter_.PredictWeight(
            x.data(),
            x.size(),
            event.original_weight
        );
    }


} // namespace nusyst
