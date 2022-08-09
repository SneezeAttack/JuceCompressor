/*
  ==============================================================================

    URCompressor.h
    Created: 25 Jun 2021 7:53:02pm
    Author:  asla_

  ==============================================================================
*/

#pragma once

#include "EnvelopeShaper.h"
#include <cmath>
#include <algorithm>

class Compressor{
 
    
    private:
    
    float m_Threshold;
    float m_Ratio;
    
    EnvelopeShaper m_EnvelopeShaper;
    
    const float BOUND_LOG = -96.f;
    const float BOUND_LIN = decibelToAmplitude(BOUND_LOG);
    
    float AmplitudeToDecibel(float amplitude);
    float decibelToAmplitude(float db);
    
    
    public:
    
	Compressor();

    void setRatio(float ratio);
    void setTreshold(float thresh);
    void setAttack(float attack);
    void setRelease(float release);

	void setSampleRate(float sampleRate);
    
    void processAudioSample(float& sample);
};