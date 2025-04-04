FROM ubuntu:24.04

# =======================
#        ENV
# =======================
ENV DEBIAN_FRONTEND=noninteractive

# =======================
#     INSTALL TOOLS
# =======================
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    libbenchmark-dev \
    libgtest-dev \
    sudo \
    vim \
    nano \
    && rm -rf /var/lib/apt/lists/*

# =======================
#   COMPILE GTEST
# =======================
RUN cd /usr/src/googletest && \
    cmake . && \
    make && \
    cp -r lib/*.a /usr/lib && \
    cp -r googletest/include/gtest /usr/include/

# =======================
#     ADD NON-ROOT USER
# =======================
RUN useradd -ms /bin/bash app && \
    usermod -aG sudo app

USER app
WORKDIR /home/app

# =======================
#    COPY PROJECT FILES
# =======================
COPY --chown=app:app . .

# =======================
#        BUILD
# =======================
# (optionnel si tu veux builder automatiquement)
# RUN make test

# =======================
#       DEFAULT CMD
# =======================
CMD ["bash"]
