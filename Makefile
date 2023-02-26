DEBUG_BUILDPATH = build/debug
RELEASE_BUILDPATH = build/release
DEBUG_FLAG = -g
RELEASE_FLAG = -s -static -O3


all: debug release
debug:	$(DEBUG_BUILDPATH)/debug.exe
release: $(RELEASE_BUILDPATH)/release.exe


$(DEBUG_BUILDPATH)/debug.exe: src/main.cpp include/event.h
	g++ $(DEBUG_FLAG) src/main.cpp -I include -o $(DEBUG_BUILDPATH)/debug.exe

$(RELEASE_BUILDPATH)/release.exe: src/main.cpp include/event.h
	g++ $(RELEASE_FLAG) src/main.cpp -I include -o $(RELEASE_BUILDPATH)/release.exe