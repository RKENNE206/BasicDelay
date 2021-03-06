/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class BasicDelayAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
	
	enum Parameters
	{
		kDelayTimeParam = 0,  // 0
		kFeedbackParam, // 1
		kNumParameters // 2
	};
	
	float delayTime;  // set up to store values from slider controls
	float feedback;

	int getNumParameters();
	float getParameter(int index);
	void setParameter(int index, float newValue);
	const String getParameterName(int index);
	const String getParameterText(int index);

    BasicDelayAudioProcessor();
    ~BasicDelayAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    //==============================================================================
	AudioSampleBuffer delayBuffer;
	int delayBufferLength;
	int readIndex;
	int writeIndex;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicDelayAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
