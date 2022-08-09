/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
UrcompressorAudioProcessorEditor::UrcompressorAudioProcessorEditor (UrcompressorAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

	addAndMakeVisible(&attackSlider);
	addAndMakeVisible(&releaseSlider);
	addAndMakeVisible(&ratioSlider);
	addAndMakeVisible(&thresholdSlider);

	//Set ranges
	attackSlider.setRange(0.1f, 100.f);
	releaseSlider.setRange(10.f, 1000.f);
	ratioSlider.setRange(1.f, 10.f, 1.0f);
	thresholdSlider.setRange(-64.f, 0.f);


	//Set starting values
	attackSlider.setValue(10.f);
	releaseSlider.setValue(100.f);
	ratioSlider.setValue(4.f);
	thresholdSlider.setValue(-3.f);

	//Set textboxes
	attackSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 70, 70);
	releaseSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 70, 70);
	ratioSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 70, 70);
	thresholdSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 70, 70);

	//Attach sliders to values
	attackSlider.onValueChange = [this]() {

		audioProcessor.compressor.setAttack(attackSlider.getValue());
	};
	releaseSlider.onValueChange = [this]() {

		audioProcessor.compressor.setRelease(releaseSlider.getValue());
	};
	ratioSlider.onValueChange = [this]() {

		audioProcessor.compressor.setRatio(ratioSlider.getValue());
	};
	thresholdSlider.onValueChange = [this]() {

		audioProcessor.compressor.setTreshold(thresholdSlider.getValue());
	};

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

UrcompressorAudioProcessorEditor::~UrcompressorAudioProcessorEditor()
{
}

//==============================================================================
void UrcompressorAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void UrcompressorAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

	attackSlider.setBounds(5, 75, 70, 70);
	releaseSlider.setBounds(100, 75, 70, 70);
	ratioSlider.setBounds(200, 75, 70, 70);
	thresholdSlider.setBounds(300, 75, 70, 70);
}
