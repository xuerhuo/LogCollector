src = FileTools.cpp FileTools.h LogCollector.cpp LogCollector.h OutPut.cpp OutPut.h Tools.cpp Tools.h base64.cpp base64.h
LogCollector : FileTools.o LogCollector.o OutPut.o Tools.o base64.o
	g++ -o LogCollector FileTools.o LogCollector.o OutPut.o Tools.o base64.o ./lib/hiredis/libhiredis.a
FileTools.o : FileTools.cpp FileTools.h
	g++ -c FileTools.cpp -std=c++11 -I ./
LogCollector.o : LogCollector.h LogCollector.cpp
	g++ -c LogCollector.cpp -std=c++11 -I ./
OutPut.o : OutPut.cpp OutPut.h
	g++ -c OutPut.cpp ./lib/hiredis/libhiredis.a -std=c++11 -I ./
Tools.o : Tools.cpp Tools.h
	g++ -c Tools.cpp -std=c++11 -I ./
base64.o : base64.cpp base64.h
	g++ -c base64.cpp -std=c++11 -I ./
.PHONY : clean  
clean :  
	\rm *.o
