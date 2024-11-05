RemoveKthElement: RemoveKthElement.o
	g++ -g -o RemoveKthElement.exe RemoveKthElement.o -pthread    

RemoveKthElement.o: RemoveKthElement/RemoveKthElement.cpp
	g++ -g  -c -pthread RemoveKthElement/RemoveKthElement.cpp
