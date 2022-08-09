/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class UrcompressorAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    UrcompressorAudioProcessorEditor (UrcompressorAudioProcessor&);
    ~UrcompressorAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

	juce::Slider attackSlider, releaseSlider, thresholdSlider, ratioSlider;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    UrcompressorAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UrcompressorAudioProcessorEditor)
};
