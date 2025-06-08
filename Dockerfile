
#--------------------------------------#
# Build submodules                     #
#--------------------------------------#
FROM ubuntu:22.04 AS submodules

ENV DEBIAN_FRONTEND=noninteractive

ARG HOST_UID=1000
ARG HOST_GID=1000

RUN groupadd -g ${HOST_GID} hostgroup \
 && useradd -l -u ${HOST_UID} -g ${HOST_GID} -m hostuser

# Submodules versions
ARG GTEST_VERSION=v1.17.0
ARG BENCH_VERSION=v1.9.4

RUN apt-get update && apt-get install -y --no-install-recommends \
        bash build-essential clang llvm cmake make git && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Build
CMD ["bash"]

#--------------------------------------#
# Build project                        #
#--------------------------------------#
FROM ubuntu:22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

ARG HOST_UID=1000
ARG HOST_GID=1000

RUN groupadd -g ${HOST_GID} hostgroup \
 && useradd -l -u ${HOST_UID} -g ${HOST_GID} -m hostuser

# Installer outils de build et dépendances système de votre projet
RUN apt-get update && apt-get install -y --no-install-recommends \
      build-essential clang llvm make && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

CMD ["bash"]