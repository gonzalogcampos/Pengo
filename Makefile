#Compiler
CXX = g++
#CXX = clang++

#GETTING ALL .CPP
SOURCES := $(subst src/,,$(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp src/*/*/*/*.cpp src/*/*/*/*/*.cpp))

#ALL .H
HEADERS := $(subst .cpp,.h,$(SOURCES))

#ALL .O
OBJECTS := $(subst .cpp,.o,$(subst src/,bin/,$(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp src/*/*/*/*.cpp)))


#ALL DIRS
#GETTING ALL DIRS
DIRS := $(subst src,bin,$(wildcard src/. src/*/. src/*/*/.))



#EXTERNAL HOMES
SMFHeaders := -I/usr/include/SFML
SFMLLibraries := -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio



#INCLUDES && LIBRAIES
INCLUDES := $(addprefix -I,$(wildcard src/. src/*/. src/*/*/.))
LIBRAIES := $(SFMLLibraries)


default:
	@mkdir -p $(DIRS)
	$(MAKE)  Pengo

#Linker
Pengo: $(OBJECTS)
	@echo Linkando
	@$(CXX) -o $@ $^ $(LIBRAIES)
	@echo Proceso terminado


#REGlA Compiler
define REGLA
$(1): $(2)
	@echo Compilando: $(basename $(notdir $(1)))
	@$(CXX) -o3 -g -Wall -o $(1) -c $(2) $(INCLUDES)

endef
$(foreach O,$(OBJECTS),$(eval $(call REGLA,$(O),$(subst bin/,src/,$(O:.o=.cpp)))))


info:
	$(info $(OBJECTS))

all:
	$(MAKE) clear
	$(MAKE) 

clear:
	@rm -f $(OBJECTS)