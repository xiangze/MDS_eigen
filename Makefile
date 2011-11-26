phony:all

bin=mds

$(bin):test.cpp $(bin).hpp 
	g++ -std=c++0x $^ -o $@ 

$(bin)_d:test.cpp $(bin).hpp 
	g++ -g $^ -o $@ 

$(bin)_red:test.cpp $(bin).hpp 
	g++ -std=c++0x $^ -o $@ -D_MDS_WITH_REDSVD

clean:
	rm $(bin)

all:$(bin) $(bin)_red

test:
	./$(bin) $(bin)_red