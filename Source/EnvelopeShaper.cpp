/*
  ==============================================================================

    EnvelopeShaper.cpp
    Created: 25 Jun 2021 8:01:59pm
    Author:  asla_

  ==============================================================================
*/

#include "EnvelopeShaper.h"

EnvelopeShaper::EnvelopeShaper(){

    m_Envelope = 0.f;
	m_SampleRate = 44100.f;
	m_AttackInMilliSeconds = 10.f;
	m_ReleaseInMilliSeconds = 100.f;
    m_Attack = 0.f;
    m_Release = 0.f;
}

void EnvelopeShaper::processAudioSample(float& sample){

    if(sample > m_Envelope){
    
        m_Envelope += m_Attack * (sample - m_Envelope);
    }
    else if(sample < m_Envelope){
    
        m_Envelope += m_Release * (sample - m_Envelope);
    }
    sample = m_Envelope;

}

void EnvelopeShaper::setAttack(float attack){

    m_AttackInMilliSeconds = attack;
    update();

}


void EnvelopeShaper::setRelease(float release){

    m_ReleaseInMilliSeconds = release;
    update();

}


void EnvelopeShaper::update(){

    m_Attack = calculate(m_AttackInMilliSeconds);
    m_Release = calculate(m_ReleaseInMilliSeconds);
    
}

float EnvelopeShaper::calculate(float time){

    if(time <= 0.f||m_SampleRate <= 0.f){
        return 1;
    }
    return 1-exp(-1.f/(time*0.001f*m_SampleRate));


}

void EnvelopeShaper::setSampleRate(float sampleRate) {

	m_SampleRate = sampleRate;
}