FROM ubuntu:24.04

# =======================
#        ENV
# =======================
ENV DEBIAN_FRONTEND=noninteractive

# =======================
#     INSTALL TOOLS
# =======================
RUN apt update && apt install -y \
    sudo \
    vim \
    nano \
    build-essential \
    make \
    llvm \
    clang \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /home/app

# =======================
#    COPY PROJECT FILES
# =======================
COPY --chown=app:app . .

# =======================
#       DEFAULT CMD
# =======================
CMD ["bash"]
