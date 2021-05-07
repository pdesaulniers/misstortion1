# Misstortion

![Misstortion's UI](https://raw.githubusercontent.com/pdesaulniers/misstortion1/master/Misstortion.png "Misstortion's UI")

This is a fork of [Misstortion](https://github.com/nimbletools/misstortion) that allows building it as an LV2 on Linux.

# Build

To build the plugin as an LV2, run the following commands (you'll need the usual JUCE dependencies):

```
git submodule update --init --recursive
ARCH=x64 ./build_lv2_linux.sh
```

You can also set ARCH=x86 for a 32 bits build.

The plugin will be placed in the LV2/linux/gmake/build/ folder.

# License

Misstortion is (like the [JUCE](https://juce.com/) library) licensed under the GPL v3.
