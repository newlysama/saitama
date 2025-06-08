#!bin/env bash

set -euo pipefail

#------------------------------------------------------------------------------#
#                               ──  Colors  ──                                 #
#------------------------------------------------------------------------------#

RESET=$'\e[0m'
RED=$'\e[31m'; GREEN=$'\e[32m'; YELLOW=$'\e[33m'; BLUE=$'\e[34m'

log() {
  local level="$1"; shift
  local color
  case "$level" in
    INFO)  color="$BLUE" ;; 
    WARN)  color="$YELLOW" ;; 
    ERROR) color="$RED" ;; 
    OK)    color="$GREEN" ;; 
    *)     color="$RESET" ;; 
  esac
  printf "%b[%s] %s%b\n" "$color" "$level" "$*" "$RESET"
}

#------------------------------------------------------------------------------#
#                               ──  Build  ──                                  #
#------------------------------------------------------------------------------#

GTEST_VERSION=v1.17.0
BENCH_VERSION=v1.9.4
TBB_VERSION=v2022.1.0

# Build Google Test
build_gtest() {
  log INFO "Building GoogleTest $GTEST_VERSION..."

  cd /app/submodules/gtest
  git checkout "$GTEST_VERSION"

  mkdir -p build && cd build
  cmake .. \
    -DCMAKE_INSTALL_PREFIX=/app/external \
    -DCMAKE_BUILD_TYPE=Release
  make -j"$(nproc)"
  make install

  log OK "GoogleTest built."

  cd /app/submodules
}

# Build Google Benchmark
build_benchmark() {
  log INFO "Building GoogleBenchmark $BENCH_VERSION..."

  cd /app/submodules/benchmark
  git checkout $BENCH_VERSION

  mkdir -p build && cd build
  cmake .. \
    -DCMAKE_INSTALL_PREFIX=/app/external \
    -DCMAKE_BUILD_TYPE=Release \
    -DBENCHMARK_DOWNLOAD_DEPENDENCIES=OFF \
    -DBENCHMARK_ENABLE_GTEST_TESTS=OFF
  make -j"$(nproc)"
  make install

  log OK "Google Benchmark built."

  cd /app/submodules
}

build_tbb() {
  log INFO "Building oneTBB $TBB_VERSION…"

  # enter the oneTBB submodule
  cd /app/submodules/oneTBB
  git checkout $TBB_VERSION

  mkdir -p build && cd build
  cmake .. \
    -DCMAKE_INSTALL_PREFIX=/app/external \
    -DCMAKE_BUILD_TYPE=Release
  make -j"$(nproc)"
  make install

  log OK "oneTBB built and installed."

  cd /app/submodules
}

log INFO "Building submodules..."
build_gtest
build_benchmark
build_tbb
log OK "Submodules built and installed to ./external"