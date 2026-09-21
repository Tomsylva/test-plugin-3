#pragma once

#include "PluginProcessor.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor &);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics &) override;
    void resized() override;

private:
    juce::Slider frequencySlider;
    juce::TextButton playButton;
    juce::Label frequencyLabel{"FrequencyLabel", "Frequency"};

    AudioPluginAudioProcessor &processorRef;

    juce::AudioProcessorValueTreeState::SliderAttachment freqSliderAttachment;
    juce::AudioProcessorValueTreeState::ButtonAttachment playButtonAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessorEditor)
};
