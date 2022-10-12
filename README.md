# testing-intel-qs

I am doing two things at the same time: testing IQS (Intel QS), and how to integrate it with Java.

One option (preferably) is using GraalVM. For it I need first to now how to compile and integrate it in Java with Quarkus or Spring Native.

The second option will be generating wrappers/proxies to IQS library. This is interesting as I can write the circuits in Java directly.

The third option is somehow run the executable and get the output. Not very fond of this solution, as it is very naïve.

## How to compile (nooby I am)

Checkout and compile [intel-qs](https://github.com/intel/intel-qs). Also make sure both this project and intel-qs are in the same folder.

Then run:
´´´
$ g++ qengine.cpp -liqs -o qengine
´´´

## GraalVM

With it I can compile and run everything in one single place. I don't need to learn how to write a REST api in C++ and I don't need to struggle to find a Quantum Simulator written in Java.

But the problem is making it working. First I need to compile the c++ code into bytecode, what I'm been failing so far.

## Intel-QS

Before exploring this simulator, I need to make sure it can be compiled using GraalVM. After that, I will try to reproduce more complex circuits.

## How to build JNI

´´´
$ swig -c++ -java -package com.github.brunopacheco1.qengine qengine.i
$ g++ -c -fpic qengine.cpp qengine_wrap.cxx -liqs -I/home/bruno/dev/graalvm-ce-java17-22.2.0/include/linux -I/home/bruno/dev/graalvm-ce-java17-22.2.0/include
$ g++ -shared -liqs qengine.o qengine_wrap.o -o libqengine.so
$ sudo cp libqengine.so /usr/lib/libqengine.so
´´´

## Next Steps

I'll be trying to compile using GraalVM.

If for any reason I get frustrated, I will try to create proxies to IQS. It looks like there are tools to support this wrapping, namingly [SWIG](https://www.swig.org/).

Breaking through this barrier, the following step will be writting a quantum circuit that reflex a very simple rules matrix.

After that, a very simple microservice will be created to expose it. I may use [Quarkus](https://quarkus.io/), to compile to native.

I need to benchmark it against a similar matrix implementation, but using [Kogito](https://kogito.kie.org/), also compiled to native.

The idea is to compare memory consumption and throughput.