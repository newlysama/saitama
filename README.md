# **SAITAMA PROJECT**

## ▶️ PURPOSE

No purpose, at least for you ^^ This is just a simple training project. My goal is to improve my C++ skills by manipulating complex algorithms, structures, frameworks, etc... This project is meant to be quant trading oriented, so I mean to use quant trading specific features.<br>

New features / optimizations / code cleaning should be added daily.

## ▶️ STRUCTURE

### This projects is structured as followed :

**- Makefile :** build the project.<br>
**- config.mk :** configuration file for building (included in `Makefile`).<br>
**- src/exos/ :** src folder. Contains exercises implementations and main files (`mains/`).<br>
**- src/benchmark/ :** benchmark folder. Contains all the necessaries to benchmark our algorithms implemented in `exos/`.<br>
**- src/utils/ :** contains various utility data structures and algorithms implementations.<br>
**- src/tests/ :** test folder.<br>

## ▶️ BUILDING AND RUNNING

### 🚩 The `config.mk` :

This file allows intelligent building. It defines sources for the Makefile to run.<br>
To define a source to build, simply set the according maccros to 1.<br>
This will get all the needed files for building and add them to EXO_SRC, UTILS_SRC, BENCHARK_SRC or TEST_SRC maccros.<br>
Building modes maccros in config.mk/Makefile are set depending on the make rule called.<br>

### 🚩 The `Makefile` :

**- make :** Default rule, build the exercises (set EXO_ON to 1)<br>
**- make test :** Build tests (set TEST_ON to 1)<br>
**- make benchmark :** Build benchmarks (set BENCHMARK_ON to 1)<br>
**- make run :** Run all built binaries<br>
**- make run-benchmark :** Run benchmark executable forcing certain options<br>

### 🚩 Docker building :

A docker structure (Dockerfile + docker-compose.yaml) is provided to build both submodules and the project.<br>

**- ./scripts/build.sh --submodules:** init, updates et compile submodules (required to build the project)<br>
**- ./scripts/build.sh --all:** Build the project with `make all`<br>
**- ./scripts/build.sh --test:** Build the project with `make test`<br>
**- ./scripts/build.sh --benchmark:** Build the project with `make benchmark`<br>

### 🚩 Build folders :

**- build/ :** Object files<br>
**- bin/ :** Binaries<br>

### 🚩 Dependencises :

This project requires several depedencies to build and run :<br>
**- Google Benchmark :** [Github](https://github.com/google/benchmark)<br>
**- Google Tests :** [Github](https://github.com/google/googletest)<br>
**- Intel oneTBB :** [Github](https://github.com/uxlfoundation/oneTBB)<br>
