#include "DistrhoPlugin.hpp"
#include "extra/Mutex.hpp"
#include "extra/ScopedPointer.hpp"

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "ParamSmooth.hpp"
#include "MisstortionParameters.hpp"

#include "DspFilters/Dsp.h"

START_NAMESPACE_DISTRHO

class MisstortionPlugin : public Plugin
{
public:
    MisstortionPlugin()
        : Plugin(paramCount, 0, 0)    
    {
    }

protected:
    const char *getLabel() const noexcept override
    {
        return "Misstortion DPF";
    }

    const char *getDescription() const noexcept override
    {
        return "TODO";
    }

    const char *getMaker() const noexcept override
    {
        return "TODO";
    }

    const char *getHomePage() const noexcept override
    {
        return "https://github.com/pdesaulniers/misstortion-dpf";
    }

    const char *getLicense() const noexcept override
    {
        return "GPL v3+";
    }

    uint32_t getVersion() const noexcept override
    {
        return d_version(1, 3, 1);
    }

    int64_t getUniqueId() const noexcept override
    {
        return d_cconst('M', 't', 'D', 'F');
    }

    void initParameter(uint32_t index, Parameter &parameter) override
    {
        if (index >= paramCount)
            return;

        switch (index)
        {
        /* case paramPreGain:
            parameter.name = "Pre Gain";
            parameter.symbol = "pregain";
            parameter.ranges.min = 0.0f;
            parameter.ranges.max = 2.0f;
            parameter.ranges.def = 1.0f;
            parameter.hints = kParameterIsAutomatable;
            break;
        case paramWet:
            parameter.name = "Wet";
            parameter.symbol = "wet";
            parameter.ranges.min = 0.0f;
            parameter.ranges.max = 1.0f;
            parameter.ranges.def = 1.0f;
            parameter.hints = kParameterIsAutomatable;
            break;
        case paramPostGain:
            parameter.name = "Post Gain";
            parameter.symbol = "postgain";
            parameter.ranges.min = 0.0f;
            parameter.ranges.max = 1.0f;
            parameter.ranges.def = 1.0f;
            parameter.hints = kParameterIsAutomatable;
            break;
        case paramRemoveDC:
            parameter.name = "Remove DC Offset";
            parameter.symbol = "removedc";
            parameter.ranges.min = 0.0f;
            parameter.ranges.max = 1.0f;
            parameter.ranges.def = 1.0f;
            parameter.hints = kParameterIsAutomatable | kParameterIsBoolean | kParameterIsInteger;
            break;
        case paramOversample:
            //None, 2x, 4x, 8x, 16x
            parameter.name = "Oversample";
            parameter.symbol = "oversample";
            parameter.ranges.min = 0.0f;
            parameter.ranges.max = 4.0f;
            parameter.ranges.def = 0.0f;
            parameter.hints = kParameterIsAutomatable | kParameterIsInteger;
            parameter.enumValues.count = 5;
            parameter.enumValues.restrictedMode = true;
            {
                ParameterEnumerationValue* const values = new ParameterEnumerationValue[5];
                parameter.enumValues.values = values;
                values[0].label = "None";
                values[0].value = 0.f;
                values[1].label = "2x";
                values[1].value = 1.f;
                values[2].label = "4x";
                values[2].value = 2.f;
                values[3].label = "8x";
                values[3].value = 3.f;
                values[4].label = "16x";
                values[4].value = 4.f;
            }
            break;
        case paramBipolarMode:
            parameter.name = "Bipolar Mode";
            parameter.symbol = "bipolarmode";
            parameter.ranges.min = 0.0f;
            parameter.ranges.max = 1.0f;
            parameter.ranges.def = 0.0f;
            parameter.hints = kParameterIsAutomatable | kParameterIsBoolean | kParameterIsInteger;
            parameter.enumValues.count = 2;
            parameter.enumValues.restrictedMode = true;
            {
                ParameterEnumerationValue* const values = new ParameterEnumerationValue[2];
                parameter.enumValues.values = values;
                values[0].label = "Unipolar";
                values[0].value = 0.f;
                values[1].label = "Bipolar";
                values[1].value = 1.f;
            }
            break;
        case paramHorizontalWarpType:
            //None, Bend +, Bend -, Bend +/-, Skew +, Skew -, Skew +/-
            parameter.name = "H Warp Type";
            parameter.symbol = "warptype";
            parameter.ranges.min = 0.0f;
            parameter.ranges.max = 6.0f;
            parameter.ranges.def = 0.0f;
            parameter.hints = kParameterIsAutomatable | kParameterIsInteger;
            parameter.enumValues.count = 7;
            parameter.enumValues.restrictedMode = true;
            {
                ParameterEnumerationValue* const values = new ParameterEnumerationValue[7];
                parameter.enumValues.values = values;
                values[0].label = "None";
                values[0].value = 0.f;
                values[1].label = "Bend +";
                values[1].value = 1.f;
                values[2].label = "Bend -";
                values[2].value = 2.f;
                values[3].label = "Bend +/-";
                values[3].value = 3.f;
                values[4].label = "Skew +";
                values[4].value = 4.f;
                values[5].label = "Skew -";
                values[5].value = 5.f;
                values[6].label = "Skew +/-";
                values[6].value = 6.f;
            }
            break;
        case paramHorizontalWarpAmount:
            parameter.name = "H Warp Amount";
            parameter.symbol = "warpamount";
            parameter.ranges.min = 0.0f;
            parameter.ranges.max = 1.0f;
            parameter.ranges.def = 0.0f;
            parameter.hints = kParameterIsAutomatable;
            break;
        case paramVerticalWarpType:
            //None, Bend +, Bend -, Bend +/-, Skew +, Skew -, Skew +/-
            parameter.name = "V Warp Type";
            parameter.symbol = "vwarptype";
            parameter.ranges.min = 0.0f;
            parameter.ranges.max = 6.0f;
            parameter.ranges.def = 0.0f;
            parameter.hints = kParameterIsAutomatable | kParameterIsInteger;
            parameter.enumValues.count = 7;
            parameter.enumValues.restrictedMode = true;
            {
                ParameterEnumerationValue* const values = new ParameterEnumerationValue[7];
                parameter.enumValues.values = values;
                values[0].label = "None";
                values[0].value = 0.f;
                values[1].label = "Bend +";
                values[1].value = 1.f;
                values[2].label = "Bend -";
                values[2].value = 2.f;
                values[3].label = "Bend +/-";
                values[3].value = 3.f;
                values[4].label = "Skew +";
                values[4].value = 4.f;
                values[5].label = "Skew -";
                values[5].value = 5.f;
                values[6].label = "Skew +/-";
                values[6].value = 6.f;
            }
            break;
        case paramVerticalWarpAmount:
            parameter.name = "V Warp Amount";
            parameter.symbol = "vwarpamount";
            parameter.ranges.min = 0.0f;
            parameter.ranges.max = 1.0f;
            parameter.ranges.def = 0.0f;
            parameter.hints = kParameterIsAutomatable;
            break;
        case paramOut:
            parameter.name = "Out";
            parameter.symbol = "out";
            parameter.hints = kParameterIsOutput;
            parameter.ranges.def = 0.0f;
            break;*/
        }

        parameters[index] = ParamSmooth(parameter.ranges.def);
        parameters[index].calculateCoeff(20.f, getSampleRate());
    }

    float getParameterValue(uint32_t index) const override
    {
        return parameters[index].getRawValue();
    }

    void setParameterValue(uint32_t index, float value) override
    {
        parameters[index].setValue(value);
    }

    void run(const float **inputs, float **outputs, uint32_t frames) override
    {
    }

private:
    ParamSmooth parameters[paramCount];

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MisstortionPlugin)
};

Plugin *createPlugin()
{
    return new MisstortionPlugin();
}

END_NAMESPACE_DISTRHO
