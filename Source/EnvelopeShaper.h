/*
  ==============================================================================

    EnvelopeShaper.h
    Created: 25 Jun 2021 8:01:59pm
    Author:  asla_

  ==============================================================================
*/

#pragma once
#include <cmath>

class EnvelopeShaper{

    public:
    
	EnvelopeShaper();
    void processAudioSample(float& sample);
    void setAttack(float attack);
    void setRelease(float release);
	void setSampleRate(float sampleRate);
    
    private:
    
    float m_Envelope;
    float m_SampleRate;
    float m_AttackInMilliSeconds;
    float m_ReleaseInMilliSeconds;
    float m_Attack;
    float m_Release;
    
    void update();
    float calculate(float time);

};