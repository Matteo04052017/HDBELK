##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=AmicaGen
ConfigurationName      :=Debug
WorkspacePath          := "/home/osboxes/tango-dev/HDB++/libhdbpp-elk"
ProjectPath            := "/home/osboxes/tango-dev/AmicaGen"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=root
Date                   :=28/02/18
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
ObjectsFileList        :="AmicaGen.txt"
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
Objects0=$(IntermediateDirectory)/ClassFactory.cpp$(ObjectSuffix) $(IntermediateDirectory)/AmicaLogger.cpp$(ObjectSuffix) $(IntermediateDirectory)/AmicaLoggerClass.cpp$(ObjectSuffix) $(IntermediateDirectory)/AmicaLoggerStateMachine.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/osboxes/tango-dev/AmicaGen/ClassFactory.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ClassFactory.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ClassFactory.cpp$(DependSuffix): ClassFactory.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ClassFactory.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ClassFactory.cpp$(DependSuffix) -MM "ClassFactory.cpp"

$(IntermediateDirectory)/ClassFactory.cpp$(PreprocessSuffix): ClassFactory.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ClassFactory.cpp$(PreprocessSuffix) "ClassFactory.cpp"

$(IntermediateDirectory)/AmicaLogger.cpp$(ObjectSuffix): AmicaLogger.cpp $(IntermediateDirectory)/AmicaLogger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/osboxes/tango-dev/AmicaGen/AmicaLogger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AmicaLogger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AmicaLogger.cpp$(DependSuffix): AmicaLogger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AmicaLogger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AmicaLogger.cpp$(DependSuffix) -MM "AmicaLogger.cpp"

$(IntermediateDirectory)/AmicaLogger.cpp$(PreprocessSuffix): AmicaLogger.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AmicaLogger.cpp$(PreprocessSuffix) "AmicaLogger.cpp"

$(IntermediateDirectory)/AmicaLoggerClass.cpp$(ObjectSuffix): AmicaLoggerClass.cpp $(IntermediateDirectory)/AmicaLoggerClass.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/osboxes/tango-dev/AmicaGen/AmicaLoggerClass.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AmicaLoggerClass.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AmicaLoggerClass.cpp$(DependSuffix): AmicaLoggerClass.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AmicaLoggerClass.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AmicaLoggerClass.cpp$(DependSuffix) -MM "AmicaLoggerClass.cpp"

$(IntermediateDirectory)/AmicaLoggerClass.cpp$(PreprocessSuffix): AmicaLoggerClass.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AmicaLoggerClass.cpp$(PreprocessSuffix) "AmicaLoggerClass.cpp"

$(IntermediateDirectory)/AmicaLoggerStateMachine.cpp$(ObjectSuffix): AmicaLoggerStateMachine.cpp $(IntermediateDirectory)/AmicaLoggerStateMachine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/osboxes/tango-dev/AmicaGen/AmicaLoggerStateMachine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AmicaLoggerStateMachine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AmicaLoggerStateMachine.cpp$(DependSuffix): AmicaLoggerStateMachine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AmicaLoggerStateMachine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AmicaLoggerStateMachine.cpp$(DependSuffix) -MM "AmicaLoggerStateMachine.cpp"

$(IntermediateDirectory)/AmicaLoggerStateMachine.cpp$(PreprocessSuffix): AmicaLoggerStateMachine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AmicaLoggerStateMachine.cpp$(PreprocessSuffix) "AmicaLoggerStateMachine.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/osboxes/tango-dev/AmicaGen/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
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


