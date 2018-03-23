##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=EarthQuakeGenCpp
ConfigurationName      :=Debug
WorkspacePath          := "/home/osboxes/tango-dev/HDB++/libhdbpp-elk"
ProjectPath            := "/home/osboxes/tango-dev/EarthQuakeGen"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=root
Date                   :=22/03/18
CodeLitePath           :="/home/osboxes/.codelite"
LinkerName             :=/usr/bin/g++-4.9
SharedObjectLinkerName :=/usr/bin/g++-4.9 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="EarthQuakeGenCpp.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -L/usr/local/lib -ltango -llog4tango -L/usr/local/lib -L/usr/local/lib -lCOS4 -lomniORB4 -lomniDynamic4 -lomnithread -lzmq -ldl -lpthread -lstdc++ 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/usr/local/include $(IncludeSwitch). $(IncludeSwitch)/usr/local/include/tango 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-4.9
CC       := /usr/bin/gcc-4.9
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/ClassFactory.cpp$(ObjectSuffix) $(IntermediateDirectory)/EarthQuakeGenerator.cpp$(ObjectSuffix) $(IntermediateDirectory)/EarthQuakeGeneratorClass.cpp$(ObjectSuffix) $(IntermediateDirectory)/EarthQuakeGeneratorStateMachine.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/ClassFactory.cpp$(ObjectSuffix): ClassFactory.cpp $(IntermediateDirectory)/ClassFactory.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/osboxes/tango-dev/EarthQuakeGen/ClassFactory.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ClassFactory.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ClassFactory.cpp$(DependSuffix): ClassFactory.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ClassFactory.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ClassFactory.cpp$(DependSuffix) -MM "ClassFactory.cpp"

$(IntermediateDirectory)/ClassFactory.cpp$(PreprocessSuffix): ClassFactory.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ClassFactory.cpp$(PreprocessSuffix) "ClassFactory.cpp"

$(IntermediateDirectory)/EarthQuakeGenerator.cpp$(ObjectSuffix): EarthQuakeGenerator.cpp $(IntermediateDirectory)/EarthQuakeGenerator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/osboxes/tango-dev/EarthQuakeGen/EarthQuakeGenerator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EarthQuakeGenerator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EarthQuakeGenerator.cpp$(DependSuffix): EarthQuakeGenerator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EarthQuakeGenerator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EarthQuakeGenerator.cpp$(DependSuffix) -MM "EarthQuakeGenerator.cpp"

$(IntermediateDirectory)/EarthQuakeGenerator.cpp$(PreprocessSuffix): EarthQuakeGenerator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EarthQuakeGenerator.cpp$(PreprocessSuffix) "EarthQuakeGenerator.cpp"

$(IntermediateDirectory)/EarthQuakeGeneratorClass.cpp$(ObjectSuffix): EarthQuakeGeneratorClass.cpp $(IntermediateDirectory)/EarthQuakeGeneratorClass.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/osboxes/tango-dev/EarthQuakeGen/EarthQuakeGeneratorClass.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EarthQuakeGeneratorClass.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EarthQuakeGeneratorClass.cpp$(DependSuffix): EarthQuakeGeneratorClass.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EarthQuakeGeneratorClass.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EarthQuakeGeneratorClass.cpp$(DependSuffix) -MM "EarthQuakeGeneratorClass.cpp"

$(IntermediateDirectory)/EarthQuakeGeneratorClass.cpp$(PreprocessSuffix): EarthQuakeGeneratorClass.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EarthQuakeGeneratorClass.cpp$(PreprocessSuffix) "EarthQuakeGeneratorClass.cpp"

$(IntermediateDirectory)/EarthQuakeGeneratorStateMachine.cpp$(ObjectSuffix): EarthQuakeGeneratorStateMachine.cpp $(IntermediateDirectory)/EarthQuakeGeneratorStateMachine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/osboxes/tango-dev/EarthQuakeGen/EarthQuakeGeneratorStateMachine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EarthQuakeGeneratorStateMachine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EarthQuakeGeneratorStateMachine.cpp$(DependSuffix): EarthQuakeGeneratorStateMachine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EarthQuakeGeneratorStateMachine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EarthQuakeGeneratorStateMachine.cpp$(DependSuffix) -MM "EarthQuakeGeneratorStateMachine.cpp"

$(IntermediateDirectory)/EarthQuakeGeneratorStateMachine.cpp$(PreprocessSuffix): EarthQuakeGeneratorStateMachine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EarthQuakeGeneratorStateMachine.cpp$(PreprocessSuffix) "EarthQuakeGeneratorStateMachine.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/osboxes/tango-dev/EarthQuakeGen/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


