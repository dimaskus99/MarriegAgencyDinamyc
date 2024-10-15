CXX = g++
CXXFLAGS = -Wall -std=c++11 -fPIC
LDFLAGS = -shared
TARGET = bin/agency
LIBNAME = libagency.so

INCDIR = include
LIBDIR = lib
SRCDIR = src

OBJS = $(SRCDIR)/main.o -L$(LIBDIR) -lagency

all: $(TARGET)

$(LIBDIR)/$(LIBNAME): $(SRCDIR)/Client.o $(SRCDIR)/Database.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(LIBDIR)/$(LIBNAME) $(SRCDIR)/Client.o $(SRCDIR)/Database.o

$(TARGET): $(SRCDIR)/main.o $(LIBDIR)/$(LIBNAME)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCDIR)/main.o -L$(LIBDIR) -lagency

$(SRCDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/Client.h $(INCDIR)/Database.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.cpp -I$(INCDIR) -o $(SRCDIR)/main.o

$(SRCDIR)/Client.o: $(SRCDIR)/Client.cpp $(INCDIR)/Client.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Client.cpp -I$(INCDIR) -o $(SRCDIR)/Client.o

$(SRCDIR)/Database.o: $(SRCDIR)/Database.cpp $(INCDIR)/Database.h $(INCDIR)/Client.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Database.cpp -I$(INCDIR) -o $(SRCDIR)/Database.o

clean:
	rm -f $(SRCDIR)/*.o $(TARGET) $(LIBDIR)/$(LIBNAME)
