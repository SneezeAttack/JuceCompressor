/*
  ==============================================================================

    URCompressor.cpp
    Created: 25 Jun 2021 7:53:02pm
    Author:  asla_

  ==============================================================================
*/

#include "URCompressor.h"

Compressor::Compressor(){

    m_Threshold = 0.f;
    m_Ratio = 1.f;

}

void Compressor::processAudioSample(float& sample){

    float detectionSignal = sample;
    
    detectionSignal = fabs(detectionSignal);
    
    m_EnvelopeShaper.processAudioSample(detectionSignal);
    
    detectionSignal = AmplitudeToDecibel(detectionSignal);
    
    if(detectionSignal > m_Threshold){
     
        float scale = 1.f-(1.f/m_Ratio);
        float gain = scale * (m_Threshold - detectionSignal);
        
        gain = decibelToAmplitude(gain);
        
        sample *= gain;
    }

}

float Compressor::decibelToAmplitude(float db) {

    return pow(10.f, db / 20.f);

}


float Compressor::AmplitudeToDecibel(float amplitude) {

    amplitude = std::max(amplitude,BOUND_LIN);
    return 20.f*log10(amplitude);

}

void Compressor::setTreshold(float thresh) {

    m_Threshold = thresh;
}

void Compressor::setRatio(float ratio){

    m_Ratio = ratio;

}

void Compressor::setAttack(float attack){

    m_EnvelopeShaper.setAttack(attack);

}


void Compressor::setRelease(float release){

    m_EnvelopeShaper.setRelease(release);

}

void Compressor::setSampleRate(float sampleRate) {

	m_EnvelopeShaper.setSampleRate(sampleRate);
}