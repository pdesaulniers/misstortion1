# Misstortion

This is a fork of [Misstortion](https://github.com/nimbletools/misstortion) that allows building it as an LV2 on Linux.

Linux LV2 and VST builds are available in the releases tab.

# Build

To build the plugin as an LV2, run the following commands (you'll need the usual JUCE dependencies):

```
git submodule update --init --recursive
./build_lv2_linux.sh
```

The plugin will be placed in the LV2/linux/gmake/build/ folder.

# License

Misstortion is (like the [JUCE](https://juce.com/) library) licensed under the GPL v3.
