all: template

%: %.cpp
	g++  --std=c++11 -g $< -o $@ -Wall -Wextra

clean: template
	rm -f $<
