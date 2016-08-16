IDIR = /usr/X11R6/include
LDIR = /usr/X11R6/lib
CC=g++
CFLAGS=-I$(IDIR) -L$(LDIR) -O3 #-Wall -pedantic

ODIR=
LDIR =

LIBS=-lpthread -lX11 -lm -lopencv_objdetect -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_ml -lopencv_video -lopencv_videoio
	
all: libDLibShapePredictorJNI.dylib

libDLibShapePredictorJNI.dylib: $(OBJ)
	g++ -dynamiclib -fpic -o libDLibShapePredictorJNI.dylib src/DLibShapePredictor/DLibShapePredictor.cpp src/DLibShapePredictorBridge/DLibShapePredictorBridge.cpp src/DLibShapePredictorJNI/DLibShapePredictorJNI.cpp /usr/local/include/dlib/all/source.cpp -DUSE_SSE2_INSTRUCTIONS=ON -DUSE_SSE4_INSTRUCTIONS=ON -DUSE_AVX_INSTRUCTIONS=ON -I/Users/benross/Downloads/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/swift-migrator/sdks/MacOSX.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers -Isrc/DLibShapePredictorBridge -Isrc/DLibShapePredictor -Isrc/DLibShapePredictorJNI -I/usr/X11R6/include -L/usr/X11R6/lib -lpthread -lX11 -lopencv_objdetect -lm -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_ml -lopencv_video -lopencv_videoio

.PHONY: clean

clean:
	rm -f *.o *~ core $(INCDIR)/*~