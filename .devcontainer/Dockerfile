FROM mcr.microsoft.com/devcontainers/cpp:debian-12

# Install additional packages
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    build-essential \
    cmake \
    clang \
    clangd \
    clang-format \
    clang-tidy \
    gdb \
    ninja-build \
    pkg-config \
    git \
    libboost-all-dev \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    build-essential \
    cmake \
    g++-13 \
    libstdc++-13-dev \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Set default GCC version
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 100

# Set the default shell to bash
ENV SHELL /bin/bash