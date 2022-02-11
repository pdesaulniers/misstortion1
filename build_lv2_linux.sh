#!/usr/bin/env bash

set -e

ARCH=${ARCH:-x64}

# Make sure DISTRHO-juce has been cloned
if [ ! -n "$(ls -A ./Libraries/DISTRHO-juce)" ]; then
	echo "The DISTRHO-juce folder seems empty." \
		 "Please run \"git submodule update --init --recursive\" to clone the missing submodule, then retry running this script."
	exit 1
fi

make -C ./Libraries/DISTRHO-juce/extras/Projucer/Builds/LinuxMakefile/

# Generate JuceLibraryCode
./Libraries/DISTRHO-juce/extras/Projucer/Builds/LinuxMakefile/build/Projucer --resave Misstortion.jucer

# Build the plugin

if [ $ARCH = "x64" ]; then
	echo "Building plugin for x64 ARCH..."
	make -C ./LV2/
elif [ $ARCH = "x86" ]; then
	echo "Building plugin for x86 ARCH..."
	make build32 -C ./LV2/
elif [ $ARCH = "ARM" ]; then
	echo "Building plugin for ARM ARCH..."
	make buildARM -C ./LV2/
else
	echo "Unsupported platform: $ARCH"
	exit 1
fi
