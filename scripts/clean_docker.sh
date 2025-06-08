#!/bin/bash

docker rm submodules-build
docker rm saitama-build
docker container prune -f
docker rmi submodules-build
docker rmi saitama-build
docker image prune -f