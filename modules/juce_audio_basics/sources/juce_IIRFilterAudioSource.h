/*
  ==============================================================================

   This file is part of the JUCE library.
   Copyright (c) 2013 - Raw Material Software Ltd.

   Permission is granted to use this software under the terms of either:
   a) the GPL v2 (or any later version)
   b) the Affero GPL v3

   Details of these licenses can be found at: www.gnu.org/licenses

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

   ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.juce.com for more information.

  ==============================================================================
*/

#ifndef __JUCE_IIRFILTERAUDIOSOURCE_JUCEHEADER__
#define __JUCE_IIRFILTERAUDIOSOURCE_JUCEHEADER__

#include "juce_AudioSource.h"
#include "../effects/juce_IIRFilter.h"


//==============================================================================
/**
    An AudioSource that performs an IIR filter on another source.
*/
class JUCE_API  IIRFilterAudioSource  : public AudioSource
{
public:
    //==============================================================================
    /** Creates a IIRFilterAudioSource for a given input source.

        @param inputSource              the input source to read from - this must not be null
        @param deleteInputWhenDeleted   if true, the input source will be deleted when
                                        this object is deleted
    */
    IIRFilterAudioSource (AudioSource* inputSource,
                          bool deleteInputWhenDeleted);

    /** Destructor. */
    ~IIRFilterAudioSource();

    //==============================================================================
    /** Changes the filter to use the same parameters as the one being passed in. */
    void setFilterParameters (const IIRFilter& newSettings);

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate);
    void releaseResources();
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill);

private:
    //==============================================================================
    OptionalScopedPointer<AudioSource> input;
    OwnedArray <IIRFilter> iirFilters;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (IIRFilterAudioSource)
};


#endif   // __JUCE_IIRFILTERAUDIOSOURCE_JUCEHEADER__
