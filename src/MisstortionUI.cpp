#include "DistrhoUI.hpp"

#include "Window.hpp"
#include "MisstortionUI.hpp"

#include <string>

START_NAMESPACE_DISTRHO

MisstortionUI::MisstortionUI()
    : UI(DISTRHO_UI_DEFAULT_WIDTH, DISTRHO_UI_DEFAULT_HEIGHT)
{
    loadSharedResources();

    const uint minWidth = 611;
    const uint minHeight = 438;

    const float width = getWidth();
    const float height = getHeight();

    const double scaleFactor = getScaleFactor();

    setGeometryConstraints(minWidth * scaleFactor, minHeight * scaleFactor, false, false);

    if (scaleFactor != 1.0)
    {
        setSize(DISTRHO_UI_DEFAULT_WIDTH * scaleFactor, DISTRHO_UI_DEFAULT_HEIGHT * scaleFactor);
    }

    positionWidgets(width, height, scaleFactor);
}

MisstortionUI::~MisstortionUI()
{
}

void MisstortionUI::positionWidgets(uint width, uint height, double scaleFactor)
{

}

void MisstortionUI::parameterChanged(uint32_t index, float value)
{
    /* switch (index)
    {
    case paramPreGain:
        fKnobPreGain->setValue(value);
        break;
    case paramWet:
        fKnobWet->setValue(value);
        break;
    case paramPostGain:
        fKnobPostGain->setValue(value);
        break;
    case paramRemoveDC:
        fSwitchRemoveDC->setDown(value >= 0.50f);
        break;
    case paramOversample:
        fWheelOversample->setValue(value);
        break;
    case paramBipolarMode: {
        const bool down = value >= 0.50f;

        fSwitchBipolarMode->setDown(down);
        fLabelsBoxBipolarMode->setSelectedIndex(down ? 1 : 0);
        break;
    }
    case paramHorizontalWarpType: {
        const int warpType = std::round(value);

        fGraphWidget->setHorizontalWarpType((wolf::WarpType)warpType);
        fLabelListHorizontalWarpType->setSelectedIndex(warpType);

        break;
    }
    case paramHorizontalWarpAmount:
        fKnobHorizontalWarp->setValue(value);
        fGraphWidget->setHorizontalWarpAmount(value);
        break;
    case paramVerticalWarpType: {
        const int warpType = std::round(value);

        fGraphWidget->setVerticalWarpType((wolf::WarpType)warpType);
        fLabelListVerticalWarpType->setSelectedIndex(warpType);

        break;
    }
    case paramVerticalWarpAmount:
        fKnobVerticalWarp->setValue(value);
        fGraphWidget->setVerticalWarpAmount(value);
        break;
    case paramOut:
        fGraphWidget->updateInput(value);
        break;
    default:
        break;
    } */
}

void MisstortionUI::onNanoDisplay()
{
}

void MisstortionUI::uiIdle()
{
}

bool MisstortionUI::onMouse(const MouseEvent &ev)
{
    return UI::onMouse(ev);
}

bool MisstortionUI::onMotion(const MotionEvent &ev)
{
    return UI::onMotion(ev);
}

void MisstortionUI::uiReshape(uint width, uint height)
{
    UI::uiReshape(width, height);
    positionWidgets(width, height, getScaleFactor());
}

bool MisstortionUI::onKeyboard(const KeyboardEvent &)
{
    return true;
}

UI *createUI()
{
    return new MisstortionUI();
}

END_NAMESPACE_DISTRHO
