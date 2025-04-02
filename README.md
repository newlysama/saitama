# **SAITAMA PROJECT**

## __I - PURPOSE__

No purpose, at least for you ^^ This is just a simple training project. My goal is to improve my C++ skills by  
manipulating complex algorithms, structures, frameworks, etc...  

New features / optimizations / code cleaning should be added daily.  

## __II - STRUCTURE__

### This projects is structured like this :

**- Makefile :** build the project.  
**- config.mk :** configuration file for building (included in Makefile)  
**- exos/ :** src folder. Contains exercises implementations (`exercisesname/`), and benchmarks for perf testing (`main/`).  
**- utils/ :** contains all necessary utilities for `exos/` to run properly. This includes data structures implementation, utility methods, etc...  
**- tests/ :** test folder (no shit)  

## __II - BUILDING__

### 1 - This project uses `make` to build. The Makefile defines the following rules :

**- make :** Default rule, build the exercises  
**- make test :** Build tests  
**- make run :** Run all built binaries  
**- make run-benchmark :** Run exercise executable forcing certain options  

### 2 - The `config.mk` :

This files allow intelligent building. It defines sources for the Makefile to run.  
To define a source to build, simply set the according maccros on top of the file to 1.  
This will get all the needed files for building and add them to EXO_SRC, UTILS_SRC or TEST_SRC.  

SPOILER ALERT : Do not build exercises alongside tests, otherwise you'll get multiple main() definitions.  

### 3 - Build folders :

**- build/ :** Object files  
**- bin/ :** Binaries  

### 4 - Depedencises

This project requires several depedencies to build :  

**- Google Benchmark :** Used as exercises' main, allowing us to test our implementations' performance on large/complex data structures. Refs : [Github](https://github.com/google/benchmark)  
**- Google Tests :** For testing (^^). Refs : [Github](https://github.com/google/googletest)  