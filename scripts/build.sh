#!/usr/bin/env bash

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
#                              ──  Functions  ──                               #
#------------------------------------------------------------------------------#

SCRIPT_DIR=$(dirname "${BASH_SOURCE[0]}")

usage() {
  echo "Usage: $0 [--submodules | --benchmark | --test | --all]"
  exit 1
}

build_submodules() {
  log INFO "Starting submodules build..."

  cd $SCRIPT_DIR/..
  mkdir -p external
  mkdir -p submodules
  git submodule update --init --recursive
 
  docker compose up --build submodules
}

build_all() {
  log INFO "Starting saitama all build..."

  export MAKE_TARGET=all
  docker compose up --build saitama
}

build_test() {
  log INFO "Starting saitama test build..."

  export MAKE_TARGET=test
  docker compose up --build saitama
}

build_benchmark() {
  log INFO "Starting saitama benchmark build..."

  export MAKE_TARGET=benchmark
  docker compose up --build saitama
}

#------------------------------------------------------------------------------#
#                                ──  Main  ──                                  #
#------------------------------------------------------------------------------#

if [[ $# -ne 1 ]]; then
  usage
fi

case "$1" in
  --submodules)
      build_submodules
      ;;

  --benchmark)
      build_benchmark
      ;;

  --test)
      build_test
      ;;

  --all)
      log INFO "Starting full build..."
      build_all
      ;;

  *)
    usage
      ;;
esac 
