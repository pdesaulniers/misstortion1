#ifndef MISSTORTION_UI_HPP_INCLUDED
#define MISSTORTION_UI_HPP_INCLUDED

#include "DistrhoUI.hpp"
#include "MisstortionParameters.hpp"

START_NAMESPACE_DISTRHO

class MisstortionUI : public UI
{
public:
    MisstortionUI();
    ~MisstortionUI();

    float getParameterValue(uint32_t index) const;

protected:
    void parameterChanged(uint32_t, float value) override;
    void positionWidgets(uint width, uint height, double scaleFactor);
    void onNanoDisplay() override;
    void uiIdle() override;
    void uiReshape(uint width, uint height) override;
    bool onKeyboard(const KeyboardEvent &ev) override;
    bool onMouse(const MouseEvent &ev) override;
    bool onMotion(const MotionEvent &ev) override;

private:
    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MisstortionUI)
};

END_NAMESPACE_DISTRHO

#endif
