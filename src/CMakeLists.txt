dpf_add_plugin(misstortion-dpf
	TARGETS jack lv2 vst2 dssi vst3 clap
	FILES_DSP
		Utils/src/Mathf.cpp
		Structures/src/Graph.cpp 
		Structures/src/ParamSmooth.cpp 
		../libs/DSPFilters/source/Butterworth.cpp
		../libs/DSPFilters/source/Biquad.cpp
		../libs/DSPFilters/source/Cascade.cpp
		../libs/DSPFilters/source/Filter.cpp
		../libs/DSPFilters/source/Param.cpp
		../libs/DSPFilters/source/Butterworth.cpp
		../libs/DSPFilters/source/PoleFilter.cpp
		../libs/DSPFilters/source/RBJ.cpp
		../libs/DSPFilters/source/Bessel.cpp
		../libs/DSPFilters/source/RootFinder.cpp
		MisstortionPlugin.cpp
	FILES_UI
		MisstortionUI.cpp
)

target_include_directories(misstortion-dpf PUBLIC
	"."
	"../dpf/distrho"
	"../dpf/dgl"
	"./Structures"
	"./Widgets"
	"./Utils"
	"./Resources"
	"../libs/DSPFilters/include"
)

target_link_libraries(misstortion-dpf PUBLIC Threads::Threads)
