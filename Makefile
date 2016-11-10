
BINARIES= hof01 hof02 hof03 hof04 hof05

all: ${BINARIES}

CXXFLAGS= -std=c++0x

hof01: hof01.c
	${CC} ${CFLAGS} $< -o $@

hof02: hof02.cpp
	${CXX} ${CXXFLAGS} $< -o $@

hof03: hof03.cpp
	${CXX} ${CXXFLAGS} $< -o $@

hof04: hof04.cpp
	${CXX} ${CXXFLAGS} $< -o $@


hof05: hof05.cpp
	${CXX} ${CXXFLAGS} $< -o $@

clean:
	- /bin/rm -f ${BINARIES}