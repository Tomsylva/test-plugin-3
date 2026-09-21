#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor &p)
    : AudioProcessorEditor(&p), processorRef(p), freqSliderAttachment(processorRef.getState(), "freqHz", frequencySlider), playButtonAttachment(processorRef.getState(), "play", playButton)
{
    juce::ignoreUnused(processorRef);

    frequencySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    frequencySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);

    addAndMakeVisible(frequencySlider);

    playButton.setButtonText("Playing");
    playButton.setToggleState(true, juce::NotificationType::dontSendNotification);
    playButton.setClickingTogglesState(true);
    playButton.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::green);
    playButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::red);

    playButton.onClick = [this]()
    {
        const bool isPlaying = playButton.getToggleState();
        playButton.setButtonText(isPlaying ? "Playing" : "Bypassed");
    };

    addAndMakeVisible(playButton);

    frequencyLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(frequencyLabel);

    setSize(400, 400);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint(juce::Graphics &g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void AudioPluginAudioProcessorEditor::resized()
{
    frequencySlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 100, 100, 200);
    playButton.setBounds(getWidth() / 2 - 50, getHeight() / 2 + 120, 100, 20);
    frequencyLabel.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 120, 100, 20);
}
