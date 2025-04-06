# **SAITAMA PROJECT**

## ▶️ PURPOSE

No purpose, at least for you ^^ This is just a simple training project. My goal is to improve my C++ skills by  manipulating complex algorithms, structures, frameworks, etc... This project is meant to be quant trading oriented, so I mean to use quant trading specific features.   

New features / optimizations / code cleaning should be added daily.   

## ▶️ STRUCTURE

### This projects is structured ass followed :

**- Makefile :** build the project.   
**- config.mk :** configuration file for building (included in `Makefile`).   
**- exos/ :** src folder. Contains exercises implementations and main files (`mains/`).   
**- benchmark/ :** benchmark folder. Contains all the necessaries to benchmark our algorithms implemented in `exos/`.   
**- utils/ :** contains various utility data structures and algorithms implementations.   
**- tests/ :** test folder.   

## ▶️ BUILDING AND RUNNING

### 🚩 The `config.mk` :

This file allows intelligent building. It defines sources for the Makefile to run.   
To define a source to build, simply set the according maccros to 1.  
This will get all the needed files for building and add them to EXO_SRC, UTILS_SRC, BENCHARK_SRC or TEST_SRC maccros.  
Building modes maccros in config.mk/Makefile are set depending on the make rule called.   

### 🚩 The `Makefile` :

**- make :** Default rule, build the exercises (set EXO_ON to 1)   
**- make test :** Build tests (set TEST_ON to 1)   
**- make benchmark :** Build benchmarks (set BENCHMARK_ON to 1)   
**- make run :** Run all built binaries   
**- make run-benchmark :** Run benchmark executable forcing certain options   

### 🚩 The `Dockerfile` :

A Dockerfile is also provided. Just build and run the image, all the depedencies will be installed, and   
you should be able to run everything properly.

**[SPOILER ALERT]** It only works in interactive mode (use -it when running the container).   

### 🚩 Build folders :

**- build/ :** Object files   
**- bin/ :** Binaries   

### 🚩 Dependencises :

This project requires several depedencies to build and run :   
**- Google Benchmark :** Used to test our implementations' performance on large/complex data structures. Refs : [Github](https://github.com/google/benchmark)   
**- Google Tests :** For testing (^^). Refs : [Github](https://github.com/google/googletest)   
